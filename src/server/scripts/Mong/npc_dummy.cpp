#include "ScriptPCH.h"
#include "ScriptMgr.h"

class Lyn_dps_mobAI : public CreatureScript
{
public:

     Lyn_dps_mobAI() : CreatureScript("Lyn_dps_mobAI") { }
	 
	 CreatureAI* GetAI(Creature* pCreature) const
	 {
		return new Lyn_dps_mob_AI (pCreature);
	 }


	struct Lyn_dps_mob_AI : public Scripted_NoMovementAI
	{
	    Lyn_dps_mob_AI(Creature *c) : Scripted_NoMovementAI(c){}

	    uint32 ReSet_Timer;
	    uint32 SayCount;
	    uint32 totdamage;
	    uint32 Custom_Timer;
		uint32 Check_Timer;

	    char message[200];
	    void Reset()
	    {
	       ReSet_Timer = 60000;
	       Custom_Timer = 60000;
		   Check_Timer = 0;
	       totdamage = 0;

	       SayCount = 0;

	       me->SetHealth(500000);              
	       me->SetMaxHealth(500000);
	       me->MonsterSay("Start!", 0, NULL);
	       me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
	       me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
	    }

	    void EnterCombat(Unit *who)
	    {
	    }

	    void JustDied(Unit* Killer)
	    {        
			sprintf(message, "|cffffff00%u sec |cffffffff%u|cffffff00 Damege, DPS : |cffffffff%u|cffffff00.", Check_Timer/1000, totdamage, totdamage/(Check_Timer/1000));
	        me->MonsterSay(message, 0, NULL);
			me->RemoveCorpse();
	    }

	    void DamageTaken(Unit *done_by, uint32 &damage)
	    {
	        totdamage += damage;
	    }

	    void UpdateAI(const uint32 diff)
	    {
	        if (!UpdateVictim())
	            return;

	        Check_Timer += diff;
			if (ReSet_Timer <= diff)
	        {            
	            me->SetHealth(1);
	        }
	        else
	        {
	            ReSet_Timer -= diff;
	            
	            if(SayCount == 0 && ReSet_Timer < 30000)
	            {
	                SayCount++;
	                me->MonsterSay("Reset 30sec", 0, NULL);
	            }

	            else if(SayCount == 1 && ReSet_Timer < 10000)
	            {
	                SayCount++;
	                me->MonsterSay("Reset 10sec", 0, NULL);
	            }

	        }

	        //DoMeleeAttackIfReady();
	    }
	};
};

#define MONGDUMMY 999998
#define DUMMYITEM 1044
class npc_dummy : public ItemScript
{
public:

	npc_dummy()
		: ItemScript("npc_dummy")
	{
	}
	bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& scTargets)
	{
		if (pPlayer->HasItemCount(pItem->GetEntry(), 1))
			pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);
		if(pItem->GetEntry()==DUMMYITEM && pPlayer->GetMapId() == 1 || pPlayer->GetMapId() == 0)
		{
			Creature* dummy = pPlayer->SummonCreature(MONGDUMMY,pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,1200000);
		}
		return true;
	}
};

void AddSC_npc_dummy()
{
	new npc_dummy();
	new Lyn_dps_mobAI();
}