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
SDComment: �����Ƽ� �̹�� ��� ����� �ƴ�, ī���ͷ� ��ü��... �ð� ���� ���������� �ٲٰ� 100% ��� �Ұ� by Kimbanjang
SDCategory: Custom
EndScriptData */

#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

enum eEnums
{
    _mailCheck,
    _mailQuickSend
};

class npc_Postman : public CreatureScript
{
	public:
	    npc_Postman() : CreatureScript("npc_Postman") { }

		bool OnGossipHello(Player* player, Creature* creature)
		{
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "����ü �ù谡 ��ŭ �з��ִ°ſ���?!", GOSSIP_SENDER_MAIN, _mailCheck);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "�� �ù� �ȿԴ� ���̿���! �� �����ϱ� ���� �����ּ���!", GOSSIP_SENDER_MAIN, _mailQuickSend);
	
	        player->PlayerTalkClass->SendGossipMenu(907, creature->GetGUID());

	        return true;
		}

	    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	    {
			switch(action) // switch(action) @START@
			{
				case _mailCheck:
					QueryResult notSendMailCount = CharacterDatabase.PQuery("SELECT SUM(IF(`flag`='1',0,1)) FROM `kc_item_mail`;");
					// uint32 notSendMailCountV = notSendMailCount; Ȥ�� ���������� ���ڿ��� �νĽ� �־����

					if(notSendMailCount < 1)
						player->MonsterWhisper("���� ������� �ù谡 �����ϴ�.", player->GetGUID());
					else
					{
						char checkMSG[100];
						snprintf(checkMSG, 100, "��� ����� �ù�� : %u", notSendMailCount);
						player->MonsterWhisper(checkMSG, player->GetGUID());
					}

					break; // case _mailCheck

				case _mailQuickSend:
					QueryResult result = CharacterDatabase.PQuery("SELECT idx,cguid,item_entry,item_stack FROM kc_item_mail WHERE flag = '0' LIMIT 1;");

					if(result)
					{
						Field *fields = result->Fetch();
						uint32 m_idx=fields[0].GetUInt32();
						uint32 m_guid=fields[1].GetUInt32();
						uint32 m_item_entry=fields[2].GetUInt32();
						uint32 m_item_stack=fields[3].GetUInt32();

						MailSender sender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM);  // ������ ����� GM���� ���
						Player *pPlayer = sObjectMgr->GetPlayerByLowGUID(m_guid); //guid ���� ������ �ɸ��͸� ã�����ִ�.
						SQLTransaction trans = CharacterDatabase.BeginTransaction();   //���ϰ��� SQL�� ���
						MailDraft draft("�ð��� ���̶�, ģ��","����Ʈ������ ������ ��ǰ�� ���� �߽��ϴ�.");
					    
						if (Item* item = Item::CreateItem(m_item_entry,m_item_stack,pPlayer))
						{
							item->SaveToDB(trans);                               // save for prevent lost at next mail load, if send fail then item will deleted
							draft.AddItem(item);
						}         
						draft.SendMailTo(trans, MailReceiver(pPlayer, GUID_LOPART(m_guid)),sender);
						CharacterDatabase.CommitTransaction(trans);
						CharacterDatabase.PQuery("UPDATE kc_item_mail SET flag = '1' WHERE idx= '%d' ",m_idx);
					}

					player->MonsterWhisper("���� ��ۿ��� �ù踦 ���� ��� �߽��ϴ�.", player->GetGUID());

					break; // _mailQuickSend

				default:
					break;
			} // switch (action) #END#
	
			player->CLOSE_GOSSIP_MENU();
		}

		CreatureAI* GetAI(Creature* pCreature) const
	    {
	        return new npc_MailsenderAI (pCreature);
	    }

	    struct npc_MailsenderAI : public ScriptedAI
	    {
	        npc_MailsenderAI(Creature* pCreature) : ScriptedAI(pCreature) 
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
	
							MailSender sender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM);  // ������ ����� GM���� ���
							Player *pPlayer = sObjectMgr->GetPlayerByLowGUID(m_guid); //guid ���� ������ �ɸ��͸� ã�����ִ�.
							SQLTransaction trans = CharacterDatabase.BeginTransaction();   //���ϰ��� SQL�� ���
							MailDraft draft("�ð��� ���̶�, ģ��","����Ʈ������ ������ ��ǰ�� ���� �߽��ϴ�.");
			        
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

void AddSC_npc_Postman()
{
	new npc_Postman();
}
