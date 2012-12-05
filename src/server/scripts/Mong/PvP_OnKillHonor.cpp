#include "ScriptPCH.h"

class PvP_OnKillHonor : public PlayerScript
{
        public:
                PvP_OnKillHonor() : PlayerScript("PvP_OnKillHonor") {}
        
                void OnPvPKill(Player *pKiller, Player *pVictim) {
                        uint64 KillerGUID = pKiller->GetGUID();
                        uint64 VictimGUID = pVictim->GetGUID();
                        
                        if(KillerGUID == VictimGUID) {return;}
                        
						//명예점수
						int32 Victim_honor = pVictim->GetHonorPoints() * 0.1;
						if(Victim_honor < 10){return;}
						pKiller->ModifyHonorPoints(Victim_honor);
						Victim_honor  = ~Victim_honor;
						pVictim->ModifyHonorPoints(Victim_honor);
						
						////투기 점수
						//int32 Victim_arena = pVictim->GetArenaPoints() * 0.1;
						//if(Victim_arena < 1){return;} 
						//pKiller->ModifyArenaPoints(Victim_arena); 
						//Victim_arena  = ~Victim_arena;
						//pKiller->ModifyArenaPoints(Victim_arena); 
				
                    //    char msg[250];
                        sprintf(msg, "[ %s ] 님이  [ %s ] 를 처치햇습니다.", pKiller->GetName(), pKiller->GetName());
						sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
                }
};

void AddSC_PvP_OnKillHonor()
{
        new PvP_OnKillHonor;
}