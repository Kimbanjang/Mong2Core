
/* ScriptData
SDName: Boss_Vaelastrasz
SD%Complete: 75
SDComment: Burning Adrenaline not correctly implemented in core
SDCategory: Blackwing Lair
EndScriptData */

#include "ScriptPCH.h"
#include "Lyn_han.h"

#define SAY_LINE1           -1469026
#define SAY_LINE2           -1469027
#define SAY_LINE3           -1469028
#define SAY_HALFLIFE        -1469029
#define SAY_KILLTARGET      -1469030

#define GOSSIP_ITEM_S         "Start Event <Needs Gossip Text>"

#define SPELL_ESSENCEOFTHERED       23513
#define SPELL_FLAMEBREATH           58956
#define SPELL_FIRENOVA              62680
#define SPELL_TAILSWIPE             71077
#define SPELL_BURNINGADRENALINE     23620
#define SPELL_CLEAVE                20684                   //Chain cleave is most likely named something different and contains a dummy effect

class boss_lyn_vaelastrasz : public CreatureScript
{
public:
    boss_lyn_vaelastrasz() : CreatureScript("boss_lyn_vaelastrasz") { }

    void SendDefaultMenu(Player* pPlayer, Creature* pCreature, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)               //Fight time
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            CAST_AI(boss_lyn_vaelastrasz::boss_vaelAI, pCreature->AI())->BeginSpeech(pPlayer);
        }
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiSender == GOSSIP_SENDER_MAIN)
            SendDefaultMenu(pPlayer, pCreature, uiAction);

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_S, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_vaelAI (pCreature);
    }

    struct boss_vaelAI : public ScriptedAI
    {
        boss_vaelAI(Creature *c) : ScriptedAI(c)
        {
            c->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            c->setFaction(35);
            c->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        uint64 PlayerGUID;
        uint32 SpeechTimer;
        uint32 SpeechNum;
        uint32 Cleave_Timer;
        uint32 FlameBreath_Timer;
        uint32 FireNova_Timer;
        uint32 BurningAdrenalineCaster_Timer;
        uint32 BurningAdrenalineTank_Timer;
        uint32 TailSwipe_Timer;
        bool HasYelled;
        bool DoingSpeech;

        void Reset()
        {
            PlayerGUID = 0;
            SpeechTimer = 0;
            SpeechNum = 0;
            Cleave_Timer = 8000;                                //These times are probably wrong
            FlameBreath_Timer = 11000;
            BurningAdrenalineCaster_Timer = 15000;
            BurningAdrenalineTank_Timer = 45000;
            FireNova_Timer = 5000;
            TailSwipe_Timer = 20000;
            HasYelled = false;
            DoingSpeech = false;
        }

        void BeginSpeech(Unit *pTarget)
        {
            //Stand up and begin speach
            PlayerGUID = pTarget->GetGUID();

            //10 seconds
            DoScriptText(SAY_LINE1, me);

            SpeechTimer = 10000;
            SpeechNum = 0;
            DoingSpeech = true;

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void KilledUnit(Unit * victim)
        {
            if (rand()%5)
                return;

            DoScriptText(SAY_KILLTARGET, me, victim);
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoCast(me, SPELL_ESSENCEOFTHERED);
            DoZoneInCombat();
            me->SetHealth(me->CountPctFromMaxHealth(30));
        }

        void UpdateAI(const uint32 diff)
        {
            //Speech
            if (DoingSpeech)
            {
                if (SpeechTimer <= diff)
                {
                    switch (SpeechNum)
                    {
                        case 0:
                            //16 seconds till next line
                            DoScriptText(SAY_LINE2, me);
                            SpeechTimer = 16000;
                            ++SpeechNum;
                            break;
                        case 1:
                            //This one is actually 16 seconds but we only go to 10 seconds because he starts attacking after he says "I must fight this!"
                            DoScriptText(SAY_LINE3, me);
                            SpeechTimer = 10000;
                            ++SpeechNum;
                            break;
                        case 2:
                            me->setFaction(103);
                            if (PlayerGUID && Unit::GetUnit((*me),PlayerGUID))
                            {
                                AttackStart(Unit::GetUnit((*me),PlayerGUID));
                                DoCast(me, SPELL_ESSENCEOFTHERED);
                            }
                            SpeechTimer = 0;
                            DoingSpeech = false;
                            break;
                    }
                } else SpeechTimer -= diff;
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            // Yell if hp lower than 15%
            if (HealthBelowPct(15) && !HasYelled)
            {
                DoScriptText(SAY_HALFLIFE, me);
                HasYelled = true;
            }

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = 15000;
            } else Cleave_Timer -= diff;

            //FlameBreath_Timer
            if (FlameBreath_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FLAMEBREATH);
                FlameBreath_Timer = urand(4000,8000);
            } else FlameBreath_Timer -= diff;

            //BurningAdrenalineCaster_Timer
            if (BurningAdrenalineCaster_Timer <= diff)
            {
                Unit *pTarget = NULL;

                uint8 i = 0;
                while (i < 3)                                   // max 3 tries to get a random target with power_mana
                {
                    ++i;
                    pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true); //not aggro leader
                    if (pTarget && pTarget->getPowerType() == POWER_MANA)
                            i = 3;
                }
                if (pTarget)                                     // cast on self (see below)
                    pTarget->CastSpell(pTarget,SPELL_BURNINGADRENALINE,1);

                BurningAdrenalineCaster_Timer = 15000;
            } else BurningAdrenalineCaster_Timer -= diff;

            //BurningAdrenalineTank_Timer
            if (BurningAdrenalineTank_Timer <= diff)
            {
                // have the victim cast the spell on himself otherwise the third effect aura will be applied
                // to Vael instead of the player
                me->getVictim()->CastSpell(me->getVictim(),SPELL_BURNINGADRENALINE,1);

                BurningAdrenalineTank_Timer = 45000;
            } else BurningAdrenalineTank_Timer -= diff;

            //FireNova_Timer
            if (FireNova_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FIRENOVA);
                FireNova_Timer = 5000;
            } else FireNova_Timer -= diff;

            //TailSwipe_Timer
            if (TailSwipe_Timer <= diff)
            {
                DoCast(me, SPELL_TAILSWIPE);
                TailSwipe_Timer = 20000;
            } else TailSwipe_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

#define SAY_anna_AGGRO			Con2U8("초면에 이건 너무 하는거 아니야?")
#define SAY_anna_SLAY			Con2U8("미안..실수로 죽여버렷네?")
#define SAY_anna_DEATH			Con2U8("이것이 끝이라고 생각지는 마라.")
#define SAY_anna_SPECIAL		Con2U8("포격준비!! ")
#define BLOODY				59682
#define EVEA				46989
#define EVEB				4086
#define POSION				64638
#define DEATHS				41080
#define CHAMING				71289
#define SHOT				71251
#define MIRRED				69051
#define SPELL_ROCKET_STRIKE 63036

class npc_lyn_anna : public CreatureScript
{
public:
    npc_lyn_anna() : CreatureScript("npc_lyn_anna") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lyn_annaAI (pCreature);
    }

    struct npc_lyn_annaAI : public ScriptedAI
    {
        npc_lyn_annaAI(Creature *pCreature) : ScriptedAI(pCreature){}

        uint32 bloody_timer;
        uint32 eve_timer;
        uint32 posion_timer;
        uint32 death_timer;
		uint32 chaming_timer;
		uint32 shot_timer;
		uint32 mirred_timer;
		Vehicle* vehicle;

		bool phase;

		uint32 Ex_timer;
		uint16 Ex_number;

        void Reset()
        {
            bloody_timer = 8000;
            eve_timer = 20000;
            posion_timer = 30000;
            death_timer= 50000;
			chaming_timer = 10000;
			Ex_timer = 15000;
			mirred_timer = 30000;
			shot_timer = 10000;
			Ex_number = 0;
			mirroredSoulTarget=0;
			phase=false;
			DoCast(EVEB);
			DoCast(57978);
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_anna_AGGRO, LANG_UNIVERSAL, 0);
			DoCast(EVEB);
			DoCast(57978);
        }

        void KilledUnit(Unit* victim)
        {
            me->MonsterYell(SAY_anna_SLAY, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_anna_DEATH, LANG_UNIVERSAL, 0);
        }

		void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage)
            {
                if (mirroredSoulTarget && me->HasAura(MIRRED))
                {
                    if (Player* player = Unit::GetPlayer(*me, mirroredSoulTarget))
                    {
                        if (player->GetAura(MIRRED))
                        {
                            int32 mirrorDamage = (uiDamage * 60)/100;
                            me->CastCustomSpell(player, 69034, &mirrorDamage, 0, 0, true);
                        }
                        else
                            mirroredSoulTarget = 0;
                    }
                }
            }
        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;


            if (bloody_timer <= uiDiff)
            {
				if (Unit *pTarget = SelectTarget(SELECT_TARGET_FARTHEST,0))  
					DoCast(BLOODY);

                bloody_timer = 30700;
            } else bloody_timer -= uiDiff;
            
			if (eve_timer <= uiDiff)
            {
                DoCast(EVEA);
                eve_timer = 45070;
            } else eve_timer -= uiDiff;
            
			if (posion_timer <= uiDiff)
            {
				if (Unit *pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO,0))  
					DoCast(pTarget, POSION);
                posion_timer = 4700;
            } else posion_timer -= uiDiff;
			
			if(!phase)
			{
				if (mirred_timer <= uiDiff)
				{
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_FARTHEST,0))
					{	
						mirroredSoulTarget = pTarget->GetGUID();
						DoCast(pTarget, MIRRED);
					}
					me->MonsterYell(Con2U8("넌 나와 함께 가는거다!"), LANG_UNIVERSAL, 0);

					mirred_timer = 37000;
				} else mirred_timer -= uiDiff;
				
				if (shot_timer<= uiDiff)
				{
					DoCast(SHOT);
					shot_timer= 47000;
				} else shot_timer-= uiDiff;
			}
			else if(phase)
			{
				if(Ex_timer <= uiDiff && Ex_number == 5)
				{
					Ex_number = 0;
					Ex_timer = 20000;
					me->MonsterYell(SAY_anna_SPECIAL, LANG_UNIVERSAL, 0);
				}else Ex_timer -= uiDiff;

				if (posion_timer <= uiDiff && Ex_number < 5)
				{
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
						me->CastSpell(pTarget, SPELL_ROCKET_STRIKE, true);
					posion_timer = 1000;
				} else posion_timer -= uiDiff;

				if (death_timer <= uiDiff)
				{
					me->MonsterYell(Con2U8("니녀석이 가장 약하구나! 주것!"), LANG_UNIVERSAL, 0);
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_BOTTOMAGGRO,0))  
						DoCast(pTarget, DEATHS);
					death_timer = 37000;
				} else death_timer -= uiDiff;
			}
			
			if (HealthBelowPct(35) && !phase)
			{
				phase=true;
				me->MonsterYell(Con2U8("포격 준비!"), LANG_UNIVERSAL, 0);
			}

            DoMeleeAttackIfReady();
        }
		 private:
			 uint64 mirroredSoulTarget;

    };

};

void AddSC_lyn_boss()
{
    new boss_lyn_vaelastrasz();
	new npc_lyn_anna();
}
