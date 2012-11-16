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
SDName: Mong2 Postman
SDAuthor: Lyn & Kimbanjang
SD%Complete: 90%
SDComment: 귀찮아서 미배송 명단 출력이 아닌, 카운터로 대체함... 시간 나면 명단출력으로 바꾸고 100% 명기 할것 by Kimbanjang
SDCategory: Custom
EndScriptData */

#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

class npc_Postman : public CreatureScript
{
	public:
	    npc_Postman() : CreatureScript("npc_Postman") { }

		bool OnGossipHello(Player* player, Creature* creature)
		{
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "도대체 택배가 얼만큼 밀려있는거에요?!", GOSSIP_SENDER_MAIN, 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "내 택배 안왔단 말이에요! 빨리 보내주세요!", GOSSIP_SENDER_MAIN, 2);
	
	        player->PlayerTalkClass->SendGossipMenu(907, creature->GetGUID());

	        return true;
		}

	    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	    {
			if(action == 1)
			{
				QueryResult result = CharacterDatabase.PQuery("SELECT SUM(IF(`flag`='1',0,1)) FROM `kc_item_mail`;");
				Field *fields = result->Fetch();
				uint32 notSendMailCount = fields[0].GetUInt32();

				if(notSendMailCount < 1)
					creature->MonsterWhisper("현재 대기중인 택배가 없습니다.", player->GetGUID());
				else
				{
					char checkMSG[50];
					snprintf(checkMSG, 50, "배송 대기중 택배수 : %u", notSendMailCount);
					creature->MonsterWhisper(checkMSG, player->GetGUID());
				}
			}
			else
			{
				QueryResult result = CharacterDatabase.PQuery("SELECT idx,cguid,item_entry,item_stack FROM kc_item_mail WHERE flag = '0' LIMIT 1;");

				if(result)
				{
					Field *fields = result->Fetch();
					uint32 m_idx=fields[0].GetUInt32();
					uint32 m_guid=fields[1].GetUInt32();
					uint32 m_item_entry=fields[2].GetUInt32();
					uint32 m_item_stack=fields[3].GetUInt32();

					MailSender sender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM);  // 보내는 사람이 GM으로 등록
					Player *pPlayer = sObjectMgr->GetPlayerByLowGUID(m_guid); //guid 값을 넣으면 케릭터를 찾을수있다.
					SQLTransaction trans = CharacterDatabase.BeginTransaction();   //메일관련 SQL을 등록
					MailDraft draft("몽이 포인트샵","포인트샵에서 구입한 물품이 도착 했습니다.");
				    
					if (Item* item = Item::CreateItem(m_item_entry,m_item_stack,pPlayer))
					{
						item->SaveToDB(trans);                               // save for prevent lost at next mail load, if send fail then item will deleted
						draft.AddItem(item);
					}         
					draft.SendMailTo(trans, MailReceiver(pPlayer, GUID_LOPART(m_guid)),sender);
					CharacterDatabase.CommitTransaction(trans);
					CharacterDatabase.PQuery("UPDATE kc_item_mail SET flag = '1' WHERE idx= '%d' ",m_idx);
				}

				creature->MonsterWhisper("다음 배송예정 택배를 강제 배송 했습니다.", player->GetGUID());
			}
		
			player->CLOSE_GOSSIP_MENU();

			return true;
		}

		CreatureAI* GetAI(Creature* pCreature) const
	    {
	        return new npc_PostmanAI (pCreature);
	    }

	    struct npc_PostmanAI : public ScriptedAI
	    {
	        npc_PostmanAI(Creature* pCreature) : ScriptedAI(pCreature) 
	        {
	            SendTimer = 500000;
	        }
	        
	        uint32 SendTimer;
	
	        void UpdateAI(const uint32 diff)
	        {                    

				if (SendTimer <= diff)
	            {
						QueryResult result = CharacterDatabase.PQuery("SELECT idx,cguid,item_entry,item_stack FROM kc_item_mail WHERE flag = '0' LIMIT 1;");

						if(result)
						{
							Field *fields = result->Fetch();
							uint32 m_idx=fields[0].GetUInt32();
							uint32 m_guid=fields[1].GetUInt32();
							uint32 m_item_entry=fields[2].GetUInt32();
							uint32 m_item_stack=fields[3].GetUInt32();
	
							MailSender sender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM);  // 보내는 사람이 GM으로 등록
							Player *pPlayer = sObjectMgr->GetPlayerByLowGUID(m_guid); //guid 값을 넣으면 케릭터를 찾을수있다.
							SQLTransaction trans = CharacterDatabase.BeginTransaction();   //메일관련 SQL을 등록
							MailDraft draft("몽이 포인트샵","포인트샵에서 구입한 물품이 도착 했습니다.");
			        
							if (Item* item = Item::CreateItem(m_item_entry,m_item_stack,pPlayer))
							{
								item->SaveToDB(trans);                               // save for prevent lost at next mail load, if send fail then item will deleted
								draft.AddItem(item);
							}         
							draft.SendMailTo(trans, MailReceiver(pPlayer, GUID_LOPART(m_guid)),sender);
							CharacterDatabase.CommitTransaction(trans);
							CharacterDatabase.PQuery("UPDATE kc_item_mail SET flag = '1' WHERE idx= '%d' ",m_idx);
						}
				
	                SendTimer = 500000;
		        }
	            else SendTimer -= diff;            
	        }
		};
};

void AddSC_Mong2_Postman()
{
	new npc_Postman();
}
