/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Mong2 In To The Matrix
SDAuthor: Kimbanjang
SD%Complete: 0%
SDComment: 20121115 : 시작
SDCategory: Custom
EndScriptData */

#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

enum eEnums
{
    _redDrug,
	_blueDrug,
	_orangeDrug
};

// 모피어스
class npc_Morpheus : public CreatureScript
{
	public:
	    npc_Morpheus() : CreatureScript("npc_Morpheus") { }

		bool OnGossipHello(Player* player, Creature* creature)
		{
			QueryResult result = CharacterDatabase.PQuery("SELECT `matrix` FROM `characters` WHERE `guid`='%u';", player->GetGUID());
			Field *fields = result->Fetch();
			uint32 chk_matrix = fields[0].GetUInt32();

			if(chk_matrix < 1)
			{
				// 솰라솰라솰라 DB 연결
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "빨간약을 먹는다.", GOSSIP_SENDER_MAIN, _redDrug);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "파란약을 먹는다.", GOSSIP_SENDER_MAIN, _blueDrug);
	
		        player->PlayerTalkClass->SendGossipMenu(907, creature->GetGUID());
			}
			else
			{
				player->CLOSE_GOSSIP_MENU();
			}

	        return true;
		}

	    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	    {
			switch(action) // switch(action) @START@
			{
				case _redDrug:
					CharacterDatabase.PQuery("UPDATE `characters` SET `matrix`='1' WHERE `guid`='%u';", player->GetGUID());
					player->GiveLevel(80); // Player->ApplyLevelInfo(Info, 80); 둘중에서 한개...

					break; // case _redDrug

				case _blueDrug:
					CharacterDatabase.PQuery("UPDATE `characters` SET `matrix`='2' WHERE `guid`='%u';", player->GetGUID());
					player->GiveLevel(70);
					player->GetReputationMgr().ModifyReputation(sFactionStore.LookupEntry(78), 20);

					break; // case _blueDrug

				default:
					break;
			} // switch (action) #END#
	
			player->CLOSE_GOSSIP_MENU();

			return true;
		}

		CreatureAI* GetAI(Creature* pCreature) const
	    {
	        return new npc_Morpheus (pCreature);
	    }

};

// 트리니티
class npc_Trinity : public CreatureScript
{
	public:
	    npc_Trinity() : CreatureScript("npc_Trinity") { }

		bool OnGossipHello(Player* player, Creature* creature)
		{
			QueryResult result = CharacterDatabase.PQuery("SELECT `matrix` FROM `characters` WHERE `guid`='%u';", player->GetGUID());
			Field *fields = result->Fetch();
			uint32 chk_matrix = fields[0].GetUInt32();

			if(chk_matrix > 1)
			{
				// 솰라솰라솰라 DB 연결
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "빨간약을 먹는다.", GOSSIP_SENDER_MAIN, _redDrug);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "파란약을 먹는다.", GOSSIP_SENDER_MAIN, _blueDrug);
	
		        player->PlayerTalkClass->SendGossipMenu(907, creature->GetGUID());
			}
			else
			{
				player->CLOSE_GOSSIP_MENU();
			}

	        return true;
		}

	    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	    {
			switch(action) // switch(action) @START@
			{
				case _redDrug:
					CharacterDatabase.PQuery("UPDATE `characters` SET `matrix`='1' WHERE `guid`='%u';", player->GetGUID());
					player->GiveLevel(80); // Player->ApplyLevelInfo(Info, 80); 둘중에서 한개...

					break; // case _redDrug

				case _blueDrug:
					CharacterDatabase.PQuery("UPDATE `characters` SET `matrix`='2' WHERE `guid`='%u';", player->GetGUID());
					player->GiveLevel(70);
					player->GetReputationMgr().ModifyReputation(sFactionStore.LookupEntry(78), 20);

					break; // case _blueDrug

				default:
					break;
			} // switch (action) #END#
	
			player->CLOSE_GOSSIP_MENU();
		}

		CreatureAI* GetAI(Creature* pCreature) const
	    {
	        return new npc_Morpheus (pCreature);
	    }

};

// 니오
class npc_NIO : public CreatureScript
{
	public:
	    npc_NIO() : CreatureScript("npc_NIO") { }

		bool OnGossipHello(Player* player, Creature* creature)
		{
			QueryResult chk_matrix = CharacterDatabase.PQuery("SELECT `matrix` FROM `characters` WHERE `guid`='%u';", player->GetGUID());

			if(chk_matrix<1)
			{
				// 솰라솰라솰라 DB 연결
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "빨간약을 먹는다.", GOSSIP_SENDER_MAIN, _redDrug);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "파란약을 먹는다.", GOSSIP_SENDER_MAIN, _blueDrug);
	
		        player->PlayerTalkClass->SendGossipMenu(907, creature->GetGUID());
			}
			else
			{
				player->CLOSE_GOSSIP_MENU();
			}

	        return true;
		}

	    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	    {
			switch(action) // switch(action) @START@
			{
				case _redDrug:
					CharacterDatabase.PQuery("UPDATE `characters` SET `matrix`='1' WHERE `guid`='%u';", player->GetGUID());
					player->GiveLevel(80); // Player->ApplyLevelInfo(Info, 80); 둘중에서 한개...

					break; // case _redDrug

				case _blueDrug:
					CharacterDatabase.PQuery("UPDATE `characters` SET `matrix`='2' WHERE `guid`='%u';", player->GetGUID());
					player->GiveLevel(70);
					player->GetReputationMgr().ModifyReputation(sFactionStore.LookupEntry(78), 20);

					break; // case _blueDrug

				default:
					break;
			} // switch (action) #END#
	
			player->CLOSE_GOSSIP_MENU();
		}

		CreatureAI* GetAI(Creature* pCreature) const
	    {
	        return new npc_Morpheus (pCreature);
	    }

};

void AddSC_Mong2_INTmatrix()
{
	new npc_Morpheus();
	new npc_Trinity();
	new npc_NIO();
}
