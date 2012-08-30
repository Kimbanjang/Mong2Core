/*########################################################
#                      Mini Bosses                       #
#              Case di Gilda - BloodyWars                #
#             <https://www.bloodywars.net/>              #
#  <https://github.com/A-Metaphysical-Drama/BloodyCore>  #
########################################################*/

/* ScriptData
SDName: BloodyWars Mini Bosses
SDAuthor: PrinceCreed
SDComment: Likantropo, Lava Boost, Quel'Nagas, Might of Sylvanas, Trollzilla, Perotharn e Uznam
SDCategory: Mini-Boss Case di Gilda
EndScriptData */

#include "ScriptPCH.h"
#include "Lyn_han.h"
enum LikantropoSpells
{
    ENRAGE                                                  = 48138,
    FRENZY                                                  = 48142,
    MORTAL_WOUND                                            = 59265,
    WORGEN_BITE                                             = 55266,
    WORGEN_CALL                                             = 53095,
    DECREPIT_FEVER                                          = 54098,
    SUMMON_WORGEN                                           = 27020
};

// Likantropo yells
#define SAY_LIKANTROPO_AGGRO    "나의 노예가 되려하느냐"
#define SAY_LIKANTROPO_SLAY     "분노를 느껴보아라!"
#define SAY_LIKANTROPO_DEATH    " 안돼!!  나의 성으로....."
#define SAY_LIKANTROPO_MORPH    "넌 후회하게될꺼야!"

enum LavaBoostSpells
{
    HEALING_WAVE                                            = 51586,
    LIGHTNING_BOLT                                          = 59024,
    BLOODLUST                                               = 41185,
    LIGHTNING_SHIELD                                        = 59025,
    SUMMON_AIR_ELEMENTAL                                    = 30418,
    LAVA_BURST                                              = 59519,
    CHAIN_LIGHTNING                                         = 54531,
    FLAME_SHOCK                                             = 43303,
    EARTH_SHOCK                                             = 43305,
    LIGHTNING_RING                                          = 59848
};

// Lava Boost yells
#define SAY_LAVA_AGGRO          "어떻게 넌 정령의 분노가 무섭지않나?!"
#define SAY_LAVA_SLAY           "충격파!"
#define SAY_LAVA_DEATH          "자연이시여 왜 날 버리시나이까."
#define SAY_LAVA_BLOOD          "Bloodlust!"

enum QuelNagasSpells
{
    SPELL_MAGIC_BARRIER                                     = 38112,
    SPELL_TOXIC_SPORES                                      = 38575,
    TOXIC_SPORES_TRIGGER                                    = 22207,
    SUMMONED_MURLOC                                         = 27649,
    SPELL_POISON_BOLT_VOLLEY                                = 54098,
    SPELL_ENTANGLE                                          = 38316,
    SPELL_WRATH                                             = 20698
};

// Quel'Nagas yells
#define SAY_NAGAS_AGGRO         "심연의 공포를 보여주마!"
#define SAY_NAGAS_SLAY          "나에게 저항하려는것이냐!"
#define SAY_NAGAS_DEATH         "믿을수 없다. 어떻게..."
#define SAY_NAGAS_SUMMON        "멀록!"

enum SylvanasSpells
{
    SPELL_MULTISHOT                                         = 40872,
    SPELL_VOLLEY                                            = 38633,
    SUMMONED_SNAKE                                          = 29444,
    SPELL_BOLT_VOLLEY                                       = 34780,
    SPELL_BEWITCHING_AURA                                   = 29486,
    SPELL_REJUVENATION                                      = 71142,
    SPELL_ICE_TRAP                                          = 71249,
    SPELL_AURA_ROT                                          = 25818
};

// Might of Sylvanas yells
#define SAY_SYLVANAS_AGGRO      "I quel'dorei mai periranno!"
#define SAY_SYLVANAS_SLAY       "Shorel'aran!"
#define SAY_SYLVANAS_DEATH      "Tutta la mia essenza per la signora della morte..."
#define SAY_SYLVANAS_ICE        "Come la mettiamo adesso?"

enum TrollzillaSpells
{
    SPELL_FRENZY                                            = 28131,
    SPELL_CLEAVE                                            = 33480,
    SPELL_FIRE_SHIELD                                       = 30513,
    SPELL_WAR_STOMP                                         = 56427,
    SUMMON_FIRE_ELEMENTAL                                   = 30416
};

// Trollzilla yells
#define SAY_TROLLZILLA_AGGRO    "Io... Distruggo... Voi..."
#define SAY_TROLLZILLA_SLAY     "Hakkar... Per te..."
#define SAY_TROLLZILLA_DEATH    "Hakkar ar...rrii...vo."
#define SAY_TROLLZILLA_FRENZY   "Io... MOLTO... ARRABBIATO!"

enum PerotharnSpells
{
    STORM_OF_GRIEF                                          = 59772,
    SHADOW_BURST                                            = 34436,
    PIERCING_SHADOW                                         = 36698,
    SHADOW_FLAME                                            = 22539,
    HARVEST_SOUL                                            = 28679,
    SHADOW_BOLT                                             = 41957
};

// Perotharn yells
#define SAY_PEROTHARN_AGGRO     "세바인님에게 드릴 선물이 하나 늘엇군"
#define SAY_PEROTHARN_SLAY      "곧 우린 하나가 될것이다."
#define SAY_PEROTHARN_DEATH     "죄송합니다 스승님.."
#define SAY_PEROTHARN_SOUL      "스승님! 여기 영혼이 있습니다."

enum UznamSpells
{
    EARTHQUAKE                                              = 62325,//46240,
    WHIRLWIND                                               = 37640,//52027,
    SHOCK_OF_SORROW                                         = 50760,
    ENTROPIC_AURA                                           = 36784,
    AURAL_SHOCK                                             = 14538,
	DEATH_GRAP												= 55718,
	DOYEK													= 64942
};

// Uznam yells
#define SAY_UZNAM_AGGRO         "날 지금 건든건가?"
#define SAY_UZNAM_SLAY          "이런일이 정말 가치가 있다고 생각하나?."
#define SAY_UZNAM_DEATH         "난 또다시 일어나니라..또...다.."
#define SAY_UZNAM_SPECIAL       "아~ 피곤하게 하는구만!."
#define EMOTE_WHIRL             "begins to cast Whirlwind!"


/*#########
# Likantropo
#########*/

class npc_likantropo : public CreatureScript
{
public:
    npc_likantropo() : CreatureScript("npc_likantropo") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_likantropoAI (pCreature);
    }

    struct npc_likantropoAI : public ScriptedAI
    {
        npc_likantropoAI(Creature *pCreature) : ScriptedAI(pCreature){}

        uint32 EnrageTimer;
        uint32 WoundTimer;
        uint32 BiteTimer;
        uint32 FeverTimer;
        bool Enraged;
        bool Worgen;

        void Reset()
        {
            me->RestoreDisplayId();
            EnrageTimer = 15000;
            WoundTimer = 5000;
            BiteTimer = 45000;
            FeverTimer = 12000;
            Enraged = false;
            Worgen = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_LIKANTROPO_AGGRO, LANG_UNIVERSAL, 0);
        }

        void KilledUnit(Unit* victim)
        {
            me->MonsterYell(SAY_LIKANTROPO_SLAY, LANG_UNIVERSAL, 0);
            // In caso di morte di un pg, evoca un worgen dal suo corpo <3 ale
            if (victim->GetTypeId() == TYPEID_PLAYER)
                victim->SummonCreature(SUMMON_WORGEN, victim->GetPositionX(), victim->GetPositionY(), victim->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_LIKANTROPO_DEATH, LANG_UNIVERSAL, 0);
            me->RestoreDisplayId();
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            // Piccoli Enrage (durata 8 secondi) che raddoppiano il danno ogni 20 sec circa
            if (EnrageTimer <= uiDiff)
            {
                DoCast(me, ENRAGE);
                EnrageTimer = urand(20000,25000);
            } else EnrageTimer -= uiDiff;

            // Ogni 5 sec applica uno stack di wound che riduce del 5% le cure (max 15 stack)
            if (WoundTimer <= uiDiff)
            {
                DoCast(me->getVictim(), MORTAL_WOUND);
                WoundTimer = 5000;
            } else WoundTimer -= uiDiff;

            // Ogni 20 sec applica un disease che riduce del 50% gli hp e fa 3k ogni 3 sec per 21 sec
            if (FeverTimer <= uiDiff)
            {
                DoCastAOE(DECREPIT_FEVER);
                FeverTimer = 20000;
            } else FeverTimer -= uiDiff;

            // Ogni 45 secondi Whirlwind che colpisce ad area facendo il danno normale
            // e contemporaneamente trasforma un target a caso in Worgen, disattivandogli le spell
            if (BiteTimer <= uiDiff)
            {
                DoCast(me, WORGEN_BITE);
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,1))
                    me->AddAura(WORGEN_CALL, pTarget);
                BiteTimer = 45000;
            } else BiteTimer -= uiDiff;

            // Ad 80% hp si trasforma in Worgen
            if (HealthBelowPct(80) && !Worgen)
            {
                me->SetDisplayId(26787);
                me->MonsterYell(SAY_LIKANTROPO_MORPH, LANG_UNIVERSAL, 0);
                DoCast(me, ENRAGE);
                EnrageTimer = urand(25000,35000);
                Worgen = true;
            }

            // Enrage a 15% di vita (aumenta 50% attack speed e 50% damage)
            if (HealthBelowPct(15) && !Enraged)
            {
                DoCast(me, FRENZY);
                Enraged = true;
            }

            DoMeleeAttackIfReady();
        }
    };

};


/*#########
# Lava Boost
#########*/

class npc_lava_boost : public CreatureScript
{
public:
    npc_lava_boost() : CreatureScript("npc_lava_boost") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lava_boostAI (pCreature);
    }

    struct npc_lava_boostAI : public ScriptedAI
    {
        npc_lava_boostAI(Creature *pCreature) : ScriptedAI(pCreature){}

        uint32 ChainTimer;
        uint32 LavaTimer;
        uint32 FlameTimer;
        uint32 ShockTimer;
        bool Haste;
        bool Healed;

        void Reset()
        {
            ChainTimer = 8000;
            LavaTimer = 15000;
            FlameTimer = 4000;
            ShockTimer = 20000;
            Haste = false;
            Healed = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_LAVA_AGGRO, LANG_UNIVERSAL, 0);
        }

        void KilledUnit(Unit* victim)
        {
            me->MonsterYell(SAY_LAVA_SLAY, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_LAVA_DEATH, LANG_UNIVERSAL, 0);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            // Chain Lightning ogni 10/15 sec
            if (ChainTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(me->getVictim(), CHAIN_LIGHTNING);
                ChainTimer = urand(10000,15000);
            } else ChainTimer -= uiDiff;

            // Ogni 15 sec casta Lava Burst su un target random da 8/10k
            if (LavaTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(false);
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,1))
                    DoCast(pTarget, LAVA_BURST);
                DoCast(me, LIGHTNING_SHIELD);
                LavaTimer = 15000;
            } else LavaTimer -= uiDiff;

            // Ogni 20 sec casta Earth Shock su un target random
            if (ShockTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(false);
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,1))
                    DoCast(pTarget, EARTH_SHOCK);
                DoCast(me, LIGHTNING_RING);
                ShockTimer = 10000;
            } else ShockTimer -= uiDiff;

            // Ogni 12 sec applica Flame Shock sul tank
            if (FlameTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(me->getVictim(), FLAME_SHOCK);
                FlameTimer = 12000;
            } else FlameTimer -= uiDiff;

            // A 25% hp si cura con Healing Wave (solo una volta)
            if (HealthBelowPct(25) && !Healed)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(me, HEALING_WAVE);
                ChainTimer = 8000;
                LavaTimer = 10000;
                FlameTimer = 4000;
                ShockTimer = 15000;
                Healed = true;
            }

            // Bloodlust a 50% di vita e Summon Air Elemental
            if (HealthBelowPct(50) && !Haste)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(me, BLOODLUST);
                me->MonsterYell(SAY_LAVA_BLOOD, LANG_UNIVERSAL, 0);
                for(int i = 0; i< 4 ; i++)
				{
					me->SummonCreature(SUMMON_AIR_ELEMENTAL, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
				}
                Haste = true;
            }

            DoSpellAttackIfReady(LIGHTNING_BOLT);
        }
    };

};


/*#########
# Quel'Nagas
#########*/

class npc_quel_nagas : public CreatureScript
{
public:
    npc_quel_nagas() : CreatureScript("npc_quel_nagas") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_quel_nagasAI (pCreature);
    }

    struct npc_quel_nagasAI : public ScriptedAI
    {
        npc_quel_nagasAI(Creature *pCreature) : ScriptedAI(pCreature){}

        uint32 Phase2Timer;
        uint32 Phase1Timer;
        uint32 SporeTimer;
        uint32 PoisonTimer;
        uint32 RootTimer;
        bool Phase1;

        void Reset()
        {
            Phase2Timer = 60000;
            Phase1Timer = 90000;
            SporeTimer = 6000;
            PoisonTimer = 15000;
            RootTimer = 25000;
            Phase1 = true;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_NAGAS_AGGRO, LANG_UNIVERSAL, 0);
        }

        void KilledUnit(Unit* victim)
        {
            me->MonsterYell(SAY_NAGAS_SLAY, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_NAGAS_DEATH, LANG_UNIVERSAL, 0);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            // Summon Phase
            if (Phase2Timer <= uiDiff)
            {
                Phase1 = false;
                me->InterruptNonMeleeSpells(false);
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                me->RemoveAllAuras();
                // In Fase 2 evoca 3 Murloc
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                    for (uint8 i = 1; i <= 10; i++)
                    {
                        me->SummonCreature(SUMMONED_MURLOC, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    }
                me->AddAura(SPELL_MAGIC_BARRIER, me);
                me->MonsterYell(SAY_NAGAS_SUMMON, LANG_UNIVERSAL, 0);
                Phase2Timer = 90000;
            } else Phase2Timer -= uiDiff;

            // Normal Phase
            if (Phase1Timer <= uiDiff)
            {
                Phase1 = true;
                me->InterruptNonMeleeSpells(false);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAurasDueToSpell(SPELL_MAGIC_BARRIER);
                DoZoneInCombat();
                if (me->getThreatManager().isThreatListEmpty())
                    EnterEvadeMode();
                Phase1Timer = 90000;
            } else Phase1Timer -= uiDiff;

            if (Phase1)
            {
                // Ogni 15 sec lancia una spora velenosa ai piedi di un player random
                if (SporeTimer <= uiDiff)
                {
                    me->InterruptNonMeleeSpells(false);
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        Creature* trig = me->SummonCreature(TOXIC_SPORES_TRIGGER, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 30000);
                        if (trig)
                        {
                            trig->setFaction(14);
                            trig->CastSpell(trig, SPELL_TOXIC_SPORES,true);
                        }
                    }                
                    SporeTimer = 10000;
                } else SporeTimer -= uiDiff;

                // Poison ad area ogni 10 sec
                if (PoisonTimer <= uiDiff)
                {
                    me->InterruptNonMeleeSpells(false);
                    DoCastAOE(SPELL_POISON_BOLT_VOLLEY);
                    PoisonTimer = 10000;
                } else PoisonTimer -= uiDiff;

                // Radici su un target random ogni 25 sec
                if (RootTimer <= uiDiff)
                {
                    me->InterruptNonMeleeSpells(false);
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_ENTANGLE);
                    RootTimer = 25000;
                } else RootTimer -= uiDiff;
            }

            DoSpellAttackIfReady(SPELL_WRATH);
        }
    };

};


/*#########
# Might of Sylvanas
#########*/

class npc_might_of_sylvanas : public CreatureScript
{
public:
    npc_might_of_sylvanas() : CreatureScript("npc_might_of_sylvanas") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_might_of_sylvanasAI (pCreature);
    }

    struct npc_might_of_sylvanasAI : public ScriptedAI
    {
        npc_might_of_sylvanasAI(Creature *pCreature) : ScriptedAI(pCreature){}

        uint32 MultiTimer;
        uint32 VolleyTimer;
        uint32 SnakeTimer;
        uint32 PoisonTimer;
        uint32 TrapTimer;
        uint32 HealTimer;
        bool Haste;
        bool Healed;

        void Reset()
        {
            MultiTimer = 2000;
            VolleyTimer = 15000;
            SnakeTimer = 5000;
            PoisonTimer = 12000;
            TrapTimer = 20000;
            HealTimer = 25000;
            Haste = false;
            Healed = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_SYLVANAS_AGGRO, LANG_UNIVERSAL, 0);
            me->AddAura(SPELL_BEWITCHING_AURA, me);
            me->AddAura(SPELL_AURA_ROT, me);
        }

        void KilledUnit(Unit* victim)
        {
            me->MonsterYell(SAY_SYLVANAS_SLAY, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_SYLVANAS_DEATH, LANG_UNIVERSAL, 0);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            // Multishot ogni 2 sec
            if (MultiTimer <= uiDiff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_MULTISHOT);
                MultiTimer = 4000;
            } else MultiTimer -= uiDiff;

            // Ogni 10 sec casta Volley su un target random
            if (VolleyTimer <= uiDiff)
            {
                DoCastAOE(SPELL_VOLLEY);
                VolleyTimer = 15000;
            } else VolleyTimer -= uiDiff;

            // Ogni 5 sec casta Snake Trap su un target random
            if (SnakeTimer <= uiDiff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                    for (uint8 i = 1; i <= 3; i++)
                    {
                        me->SummonCreature(SUMMONED_SNAKE, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    }
                SnakeTimer = 5000;
            } else SnakeTimer -= uiDiff;

            // Poison ad area ogni 10 sec
            if (PoisonTimer <= uiDiff)
            {
                DoCastAOE(SPELL_BOLT_VOLLEY);
                PoisonTimer = 12000;
            } else PoisonTimer -= uiDiff;

            // Ogni 20 sec casta Frost Trap sul tank
            if (TrapTimer <= uiDiff)
            {
                me->MonsterYell(SAY_SYLVANAS_ICE, LANG_UNIVERSAL, 0);
                DoCast(me->getVictim(), SPELL_ICE_TRAP);
                TrapTimer = 20000;
            } else TrapTimer -= uiDiff;

            // Ogni 25 sec casta Rejuvenation
            if (HealTimer <= uiDiff)
            {
                DoCast(me, SPELL_REJUVENATION);
                HealTimer = 25000;
            } else HealTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};


/*#########
# Trollzilla
#########*/

class npc_trollzilla : public CreatureScript
{
public:
    npc_trollzilla() : CreatureScript("npc_trollzilla") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_trollzillaAI (pCreature);
    }

    struct npc_trollzillaAI : public ScriptedAI
    {
        npc_trollzillaAI(Creature *pCreature) : ScriptedAI(pCreature){}

        uint32 CleaveTimer;
        uint32 StompTimer;
        uint32 FireTimer;
        bool Enraged;

        void Reset()
        {
            CleaveTimer = 5000;
            StompTimer = 20000;
            FireTimer = 30000;
            Enraged = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_TROLLZILLA_AGGRO, LANG_UNIVERSAL, 0);
            me->AddAura(SPELL_FIRE_SHIELD, me);
        }

        void KilledUnit(Unit* victim)
        {
            me->MonsterYell(SAY_TROLLZILLA_SLAY, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_TROLLZILLA_DEATH, LANG_UNIVERSAL, 0);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            // Ogni 5 sec fa Cleave
            if (CleaveTimer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                CleaveTimer = 5000;
            } else CleaveTimer -= uiDiff;

            // Ogni 20 sec fa un War Stomp che stunna ad area
            if (StompTimer <= uiDiff)
            {
                DoCastAOE(SPELL_WAR_STOMP);
                StompTimer = 20000;
            } else StompTimer -= uiDiff;

            // Summon Fire Elemental ogni 30 sec
            if (FireTimer <= uiDiff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                    me->SummonCreature(SUMMON_FIRE_ELEMENTAL, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
                FireTimer = 30000;
            } else FireTimer -= uiDiff;

            // Enrage a 25% di vita (aumenta 40% attack speed e 25% damage)
            if (HealthBelowPct(25) && !Enraged)
            {
                me->MonsterYell(SAY_TROLLZILLA_FRENZY, LANG_UNIVERSAL, 0);
                DoCast(me, SPELL_FRENZY);
                Enraged = true;
            }

            DoMeleeAttackIfReady();
        }
    };

};


/*#########
# Perotharn
#########*/

class npc_perotharn : public CreatureScript
{
public:
    npc_perotharn() : CreatureScript("npc_perotharn") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_perotharnAI (pCreature);
    }

    struct npc_perotharnAI : public ScriptedAI
    {
        npc_perotharnAI(Creature *pCreature) : ScriptedAI(pCreature){}

        uint32 BurstTimer;
        uint32 GriefTimer;
        uint32 FlameTimer;
        uint32 PiercingTimer;
        uint32 HarvestTimer;

        void Reset()
        {
            BurstTimer = 30000;
            GriefTimer = 20000;
            FlameTimer = 15000;
            PiercingTimer = 10000;
            HarvestTimer = 45000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_PEROTHARN_AGGRO, LANG_UNIVERSAL, 0);
        }

        void KilledUnit(Unit* victim)
        {
            me->MonsterYell(SAY_PEROTHARN_SLAY, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_PEROTHARN_DEATH, LANG_UNIVERSAL, 0);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            // Shadow Burst ad area e reset threat
            if (BurstTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(false);
                me->DeleteThreatList();
                DoCast(me->getVictim(), SHADOW_BURST);
                BurstTimer = urand(25000,35000);
            } else BurstTimer -= uiDiff;

            // Storm of Grief ogni 20 sec colpisce ad area
            if (GriefTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(false);
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                    DoCast(pTarget, STORM_OF_GRIEF);
                GriefTimer = 20000;
            } else GriefTimer -= uiDiff;

            // Ogni 10 sec casta Piercing Shadow sul target a maggior aggro dopo il tank
            if (PiercingTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(false);
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO,0))
                    DoCast(pTarget, PIERCING_SHADOW);
                PiercingTimer = 10000;
            } else PiercingTimer -= uiDiff;

            // Ogni 15 sec casta Shadow Flame che fa danno a cono
            if (FlameTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(false);
                DoCastAOE(SHADOW_FLAME);
                FlameTimer = 15000;
            } else FlameTimer -= uiDiff;

            // Ogni 45 sec casta Harvest Soul su tutto il raid
            if (HarvestTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(false);
                me->MonsterYell(SAY_PEROTHARN_SOUL, LANG_UNIVERSAL, 0);
                DoCastAOE(HARVEST_SOUL);
                HarvestTimer = 45000;
            } else HarvestTimer -= uiDiff;

            DoSpellAttackIfReady(SHADOW_BOLT);
        }
    };

};


/*#########
# Uznam the Watcher
#########*/

class npc_uznam_the_watcher : public CreatureScript
{
public:
    npc_uznam_the_watcher() : CreatureScript("npc_uznam_the_watcher") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_uznam_the_watcherAI (pCreature);
    }

    struct npc_uznam_the_watcherAI : public ScriptedAI
    {
        npc_uznam_the_watcherAI(Creature *pCreature) : ScriptedAI(pCreature){}

        uint32 EarthquakeTimer;
        uint32 WhirlwindTimer;
        uint32 ShockTimer;
        uint32 AuralShockTimer;

        void Reset()
        {
            EarthquakeTimer = 8000;
            WhirlwindTimer = 20000;
            ShockTimer = 30000;
            AuralShockTimer = 50000;
			DoCast(me,41634);
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_UZNAM_AGGRO, LANG_UNIVERSAL, 0);
            DoCast(me, ENTROPIC_AURA);
        }

        void KilledUnit(Unit* victim)
        {
            me->MonsterYell(SAY_UZNAM_SLAY, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_UZNAM_DEATH, LANG_UNIVERSAL, 0);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            // Earthquake Ogni 20 secondi.
            if (EarthquakeTimer <= uiDiff)
            {
                DoCast(EARTHQUAKE);
                EarthquakeTimer = 20000;
            } else EarthquakeTimer -= uiDiff;

            // Whirlwind Ogni 30 sec
            if (WhirlwindTimer <= uiDiff)
            {
                me->MonsterYell(SAY_UZNAM_SPECIAL, LANG_UNIVERSAL, 0);
                me->MonsterTextEmote(EMOTE_WHIRL, 0, true);
				DoCast(DEATH_GRAP);
                DoCast(me, WHIRLWIND);
                WhirlwindTimer = 30000;
            } else WhirlwindTimer -= uiDiff;

            // Shock of sorrow Ogni 40 sec.
            if (ShockTimer <= uiDiff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
				{   
					DoCast(pTarget, SHOCK_OF_SORROW);
					DoCast(pTarget,DOYEK);
				}
				ShockTimer = 40000;
            } else ShockTimer -= uiDiff;
            
            // Aural Shock Ogni minuto
            if (AuralShockTimer <= uiDiff)
            {
                DoCast(AURAL_SHOCK);
                AuralShockTimer = 60000;
            } else AuralShockTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};

#define SAY_WAR         "경보 발령!!   침입자 발생!! 제거!!"
class npc_lyn_def : public CreatureScript
{
public:
    npc_lyn_def() : CreatureScript("npc_lyn_def") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lyn_defAI (pCreature);
    }

	struct npc_lyn_defAI : public Scripted_NoMovementAI
	{
	    npc_lyn_defAI(Creature *c) : Scripted_NoMovementAI(c){}

        uint32 ChainTimer;

        void Reset()
        {
            ChainTimer = 2000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_WAR, LANG_UNIVERSAL, 0);
        }

        void KilledUnit(Unit* victim)
        {
            
        }

        void JustDied(Unit* /*killer*/)
        {
            
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;
            if (ChainTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(me->getVictim(), 57432);
                ChainTimer = urand(5000,10000);
            } else ChainTimer -= uiDiff;
        }
    };

};
	

#define	SAY_AGGRO				"하찮은 것들이 자꾸 귀찮게 하는구나! 죽을 준비나 해라!"		//Your intervention has been a nuisance long enough! Prepare to perish...
#define	SAY_KILL				"너무 약하군... 검은용군단은 영원하다!"		//Weak.. The twilight dragonflight is infinite!
#define	SAY_DIE					"주인님..당신이.. 옳았습니다....모든 것은 ... 절...걱정....."		//The master was right... To be concerned... He will unleash devestation upon.. you.. all..
#define	SAY_BERSERK				"충분히 느껴봐라! 무한한 힘을. 그리고 끝없는 공포를!"		// Enough.. The infinite dragonflight is unboundary in power! FEEL MY EXERTION!
#define	SAY_CORRUPTINGBLIGHT	"너에게 주어진 시간이 끝나간다."     //Watch as your own timeline becomes deteriorated!
#define EMOTE_FROSTBOMB			"경보! 파스크란이 얼음폭탄을 시전합니다."

enum
{
	REFLECTION				= 22067,		//PHASE 2    every 27 sec?
	DRAINMANA				= 46453,		//ALL PHASES, every 50 sec
	SHROUDOFSARROW			= 72981,		//Start spell
	TAILSMASH				= 71077,		// Every 40 Sec , phase 1
	SHADOWBREATH			= 59126,		// Every 30 Sec , phase 1 & 3
	STRONGCLEAVE			= 19983,		//Every 45 Sec, phase 1 & 3
	BLISTERINGCOLD		 	= 70123,		//phase 3 , 58 sec
	FROSTBOMB				= 71053,		//phase 2 , end of it		
	SHADOWBOLT				= 64698,		// phase 2, every 15 sec, random target
	CORRUPTINGBLIGHT		= 60588,        // PHASE 1 & 3 , every 25 Sec, on tank
	SPELL_BERSERK			= 62555,		// berserk 1.5%
	
	TENEBRONID				= 17842,//30452,
	SHADRONID				= 17767,//30451,
	VESPERONID				= 25038,//30449,

};
class npc_lyn_darkbone : public CreatureScript
{
public:
    npc_lyn_darkbone() : CreatureScript("npc_lyn_darkbone") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lyn_darkboneAI (pCreature);
    }
	struct npc_lyn_darkboneAI : public ScriptedAI
	{
	    npc_lyn_darkboneAI(Creature *c) : ScriptedAI(c){}

    bool berserk;
	uint32 PHASE;
	uint32 flyTimer;
	
	bool tenebron;
	bool shadron;
	bool vesperon;
	uint32 boss_Timer;
	uint32 Reflection_Timer;
	uint32 Drainmana_Timer;
	uint32 Tailsmash_Timer;
	uint32 Shadowbreath_Timer;
	uint32 Strongcleave_Timer;
	uint32 Blisteringcold_Timer;
	uint32 Shadowbolt_Timer;
	uint32 Corruptingblight_Timer;




	void Reset()
	{
		PHASE			= 1;
		berserk			= false;



		Reflection_Timer = 10000; 
		Drainmana_Timer		= 33000;
		Tailsmash_Timer		= urand(48000, 49000);
		Shadowbreath_Timer	= 30000;
		Strongcleave_Timer	= 45000;
		Blisteringcold_Timer = urand(56000, 58000);
		Shadowbolt_Timer	= urand(13000, 14000);
		Corruptingblight_Timer	= 25500;
		
		flyTimer			= 6000;
		tenebron = false;
		shadron = false;
		vesperon = false;
		boss_Timer = 70000;

	}


        void EnterCombat(Unit* /*who*/)
        {
            //me->MonsterYell(SAY_WAR, LANG_UNIVERSAL, 0);
			me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, 0);
			DoCast(me, SHROUDOFSARROW);
        }

        void KilledUnit(Unit* victim)
        {
           me->MonsterYell(SAY_KILL, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit* /*killer*/)
        {
           me->MonsterYell(SAY_DIE, LANG_UNIVERSAL , 0);  
        }
		
		void JustSummoned(Creature *pSummoned)
    	{
        	if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
           		pSummoned->AI()->AttackStart(pTarget);
		}
        void UpdateAI(const uint32 uiDiff)
		{
		if (!UpdateVictim())
            	return;

			if (PHASE == 1)
			{
				if(Drainmana_Timer < uiDiff)
				{
					DoCast(me->getVictim(), DRAINMANA);
					Drainmana_Timer		= 38500;
				}
				else
					Drainmana_Timer -= uiDiff;
				
				if(Tailsmash_Timer < uiDiff)
				{
					DoCast(me, TAILSMASH);
					Tailsmash_Timer		= urand(38000, 39000);
				}
				else
					Tailsmash_Timer -= uiDiff;

				if(Shadowbreath_Timer < uiDiff)
				{
					DoCast(me->getVictim(), SHADOWBREATH);
					Shadowbreath_Timer	= 20000;
				}
				else
					Shadowbreath_Timer -= uiDiff;

				if(Strongcleave_Timer < uiDiff)
				{
					DoCast(me->getVictim(), STRONGCLEAVE);
					Strongcleave_Timer	= 25000;
				}
				else
					Strongcleave_Timer -= uiDiff;
				
				if(Corruptingblight_Timer < uiDiff)
				{
					DoCast(me->getVictim(), CORRUPTINGBLIGHT);
					Corruptingblight_Timer	= 15500;
					me->MonsterYell(SAY_CORRUPTINGBLIGHT, LANG_UNIVERSAL, 0);
				}
				else
					Corruptingblight_Timer -= uiDiff;

				if (HealthBelowPct(65))
				{
					
					PHASE = 2;
								me->SetReactState(REACT_PASSIVE);
								me->AttackStop();
								me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(),me->GetPositionZ()+30.0f);
								me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
								//me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
								me->SendMovementFlagUpdate();
					
					//SetCombatMovement(false);
					//me->InterruptNonMeleeSpells(false);
		//            		me->GetMotionMaster()->Clear(false);
		//            		me->GetMotionMaster()->MoveIdle();
		//            		DoCastSpellIfCan(me,57764);
							//me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(),me->GetPositionZ()+30.0f);	
               	 		//me->SetHover(true);
				}


			}

			if(PHASE == 2)
			{

				if(flyTimer < uiDiff)
				{	
					switch(urand(1, 4))
					{	
						case 1:
						me->GetMotionMaster()->MovePoint(0, me->GetPositionX()+30.0f, me->GetPositionY(),me->GetPositionZ());	
						break;
						case 2:
						me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY()+30.0f,me->GetPositionZ());	
						break;
						case 3:
						me->GetMotionMaster()->MovePoint(0, me->GetPositionX()-30.0f, me->GetPositionY(),me->GetPositionZ());	
						break;
						case 4:
						me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY()-30.0f,me->GetPositionZ());	
						break;
					}
					flyTimer = 10000;
				}
				else 
					flyTimer -= uiDiff;			
		
				if(!tenebron)
				{
					me->SummonCreature(TENEBRONID, me->GetPositionX(), me->GetPositionY()-20.0f,me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000);
					tenebron = true;
				}

				if(boss_Timer < uiDiff && tenebron && !shadron)
				{
					me->SummonCreature(SHADRONID, me->GetPositionX()+20, me->GetPositionY(),me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000);
					shadron = true;
					boss_Timer = 70000;
				}
				else
				{	if(tenebron && !shadron)
					boss_Timer -= uiDiff;
				}

				if(boss_Timer < uiDiff && shadron && tenebron && !vesperon)
				{
					me->SummonCreature(VESPERONID, me->GetPositionX(), me->GetPositionY()+20.0f,me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000);
					vesperon = true;
					boss_Timer = 70000;
				}
				else
				{
					if(shadron && tenebron && !vesperon)
					boss_Timer -= uiDiff;
				}			

				if(Reflection_Timer < uiDiff)
				{
					DoCast(me,REFLECTION);
					Reflection_Timer = 10000; 
				}
				else
					Reflection_Timer -= uiDiff;

				if(Drainmana_Timer < uiDiff)
				{
					DoCast(me->getVictim(), DRAINMANA);
					Drainmana_Timer		= 53000;
				}
				else
					Drainmana_Timer -= uiDiff;

				if(Shadowbolt_Timer < uiDiff)
				{
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                    			DoCast(pTarget,SHADOWBOLT);

					Shadowbolt_Timer	= urand(13000, 14000);
				}
				else
					Shadowbolt_Timer -= uiDiff;

				if(boss_Timer < uiDiff && shadron && tenebron && vesperon)
				{
					PHASE = 3;
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                    //me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->SendMovementFlagUpdate();
        			me->GetMotionMaster()->MoveChase(me->getVictim());
					me->MonsterTextEmote(EMOTE_FROSTBOMB, 0, true);
					DoCast(me->getVictim(),FROSTBOMB);
				}
				else
				{
					if(shadron && tenebron && vesperon)
					boss_Timer -= uiDiff;
				}
			}

			if(PHASE == 3)
			{
				if (me->HasAura(57764))
                		me->RemoveAurasDueToSpell(57764);
					
				if(Drainmana_Timer < uiDiff)
				{
					DoCast(me->getVictim(), DRAINMANA);
					Drainmana_Timer		= 26500;
				}
				else
					Drainmana_Timer -= uiDiff;
				
				if(Shadowbreath_Timer < uiDiff)
				{
					DoCast(me->getVictim(), SHADOWBREATH);
					Shadowbreath_Timer	= 20000;
				}
				else
					Shadowbreath_Timer -= uiDiff;

				if(Strongcleave_Timer < uiDiff)
				{
					DoCast(me->getVictim(), STRONGCLEAVE);
					Strongcleave_Timer	= 35000;
				}
				else
					Strongcleave_Timer -= uiDiff;

				if(Blisteringcold_Timer < uiDiff)
				{
					DoCast(me->getVictim(), BLISTERINGCOLD);
					Blisteringcold_Timer = urand(46000, 48000);
				}
				else
					Blisteringcold_Timer -= uiDiff;

				if(Corruptingblight_Timer < uiDiff)
				{
					DoCast(me->getVictim(), CORRUPTINGBLIGHT);
					Corruptingblight_Timer	= 15500;
					me->MonsterYell(SAY_CORRUPTINGBLIGHT, LANG_UNIVERSAL, 0);
				}
				else
					Corruptingblight_Timer -= uiDiff;

				if(HealthBelowPct(15)&& !berserk)
				{
		   			berserk = true;
					me->MonsterYell(SAY_BERSERK, LANG_UNIVERSAL, 0);
					DoCast(me,SPELL_BERSERK);
				}	
						
			}


			if (PHASE!=2)
				DoMeleeAttackIfReady();


		}

	};
};


#define SAY_anna_AGGRO			"초면에 이건 너무 하는거 아니야?"
#define SAY_anna_SLAY			"미안..실수로 죽여버렷네?"
#define SAY_anna_DEATH			"이것이 끝이라고 생각지는 마라."
#define SAY_anna_SPECIAL		"포격준비!! "
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
					me->MonsterYell("넌 나와 함께 가는거다!", LANG_UNIVERSAL, 0);

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
					me->MonsterYell("니녀석이 가장 약하구나! 주것!", LANG_UNIVERSAL, 0);
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_BOTTOMAGGRO,0))  
						DoCast(pTarget, DEATHS);
					death_timer = 37000;
				} else death_timer -= uiDiff;
			}
			
			if (HealthBelowPct(35) && !phase)
			{
				phase=true;
				me->MonsterYell("포격 준비!", LANG_UNIVERSAL, 0);
			}

            DoMeleeAttackIfReady();
        }
		 private:
			 uint64 mirroredSoulTarget;

    };

};
// 충격파 - 57728
// 화염폭풍 - 66044
// 광휘의 오라 - 71953 HP 회복 3%씩
// 별똥별 - 53195
// 야성의 돌진- 45334
// 신의 격노  - 57466

// 어둠의 형상 - 29406 
// 음에너지 - 46009
// 어둠 붕괴 63722
// 어둠의 오라 - 69491 주변에 데미지

#define SAY_reona_AGGRO			"언제나 찬란한 빛의 힘을!"
#define SAY_reona_SLAY			"빛이 함께 하기를."
#define SAY_reona_DEATH			"마....마스터..."
#define SAY_reona_SPECIAL		"난...이미  죽어버린 사람이였군요..."

#define SHOCK_WAVE			57728
#define FIRE_STOM			66044
#define HOLY_AURA			71953
#define STAR_POLL			64638
#define GOD_FURY			57466
#define DARKNISS			29406
#define NEGATIVE_AURA		46284
#define DARK_BOOM			63722
#define DARK_AURA			69491


class npc_lyn_reona : public CreatureScript
{
public:
    npc_lyn_reona() : CreatureScript("npc_lyn_reona") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lyn_reonaAI (pCreature);
    }

    struct npc_lyn_reonaAI : public ScriptedAI
    {
        npc_lyn_reonaAI(Creature *pCreature) : ScriptedAI(pCreature){}

        uint32 shock_wave_timer;
        uint32 fire_stom_timer;
        uint32 god_fury_timer;
        uint32 star_poll_timer;
		uint32 dark_boom_timer;
		Vehicle* vehicle;

		uint32 phase;

		uint32 Ex_timer;
		uint16 Ex_number;

        void Reset()
        {
            shock_wave_timer = 8000;
            fire_stom_timer = 20000;
            god_fury_timer = 30000;
            star_poll_timer= 50000;
			dark_boom_timer = 30000;
			Ex_timer = 15000;
			Ex_number = 0;
			//일단 여기까지
			phase = 0;
			DoCast(HOLY_AURA);
			DoCastAOE(NEGATIVE_AURA, false);
			DoCastAOE(DARK_AURA, false);
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_reona_AGGRO, LANG_UNIVERSAL, 0);
			DoCast(HOLY_AURA);
        }

        void KilledUnit(Unit* victim)
        {
            me->MonsterYell(SAY_reona_SLAY, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_reona_DEATH, LANG_UNIVERSAL, 0);
        }

		void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_FARTHEST,0))
                {
                    int32 mirrorDamage = (uiDamage * 5)/100;
                    me->CastCustomSpell(pTarget, 69034, &mirrorDamage, 0, 0, true);
                }
            }
        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;


            if (shock_wave_timer <= uiDiff)
            {
				if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST,0))  
					DoCast(pTarget,SHOCK_WAVE);

                shock_wave_timer = 30700;
            } else shock_wave_timer -= uiDiff;
            
			if (fire_stom_timer <= uiDiff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO,0)) 
					DoCast(pTarget,FIRE_STOM);
                fire_stom_timer = 45070;
            } else fire_stom_timer -= uiDiff;            			
			if(phase == 1) // 여기까지
			{
				if (god_fury_timer <= uiDiff)
				{
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO,0))
					{	
						DoCast(pTarget,GOD_FURY);
					}
					me->MonsterYell("제게로 모이세요", LANG_UNIVERSAL, 0);
					god_fury_timer = 37000;
				} else god_fury_timer -= uiDiff;
				
				if (star_poll_timer<= uiDiff)
				{
					DoCast(STAR_POLL);
					star_poll_timer= 47000;
					me->MonsterYell("새벽이 밝았습니다", LANG_UNIVERSAL, 0);
				} else star_poll_timer-= uiDiff;
			}
			else if(phase == 2)
			{
				if(Ex_number == 5)
				{
					Ex_number = 0;
					Ex_timer = 20000;
					me->MonsterYell(SAY_reona_SPECIAL, LANG_UNIVERSAL, 0);
				}else Ex_timer -= uiDiff;

				if (dark_boom_timer <= uiDiff && Ex_number < 5)
				{
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
						me->CastSpell(pTarget, DARK_BOOM, true);
					dark_boom_timer = 1000;
					Ex_number+=1;
				} else dark_boom_timer -= uiDiff;
			}
			
			if (HealthBelowPct(90) && phase < 1)
			{
				phase = 1;
				me->MonsterYell("다음번에는...흠집이라도 내보시죠!", LANG_UNIVERSAL, 0);
			}
			else if (HealthBelowPct(30) && phase < 2)
			{
				phase = 2;
				me->MonsterYell("이클립스!", LANG_UNIVERSAL, 0);
				DoCastAOE(DARKNISS, true);
				DoCastAOE(NEGATIVE_AURA, true);
				DoCastAOE(DARK_AURA, true);
			}
            DoMeleeAttackIfReady();
        }

    };

};


void AddSC_npcs_mini_boss()
{
    new npc_likantropo();
    new npc_lava_boost();
    new npc_quel_nagas();
    new npc_might_of_sylvanas();
    new npc_trollzilla();
    new npc_perotharn();
    new npc_uznam_the_watcher();
	new npc_lyn_def();
	new npc_lyn_darkbone();
	new npc_lyn_anna();
	new npc_lyn_reona();
}	

