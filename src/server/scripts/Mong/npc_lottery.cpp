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
SDName: BloodyWars Lottery & mong2 mail sender
SDAuthor: PrinceCreed & Lyn
SD%Complete: 100%
SDComment: //
SDCategory: Custom
EndScriptData */

#include "ScriptPCH.h"
#include "Lyn_han.h"
/*######
## npc_lotto
######*/

#define GOSSIP_BUY_TICKET          "로또를 구입합니다.! 500골드"
#define TICKET_COST                 5000000
#define EVENT_BLOODYLOTTO           132

class npc_lotto : public CreatureScript
{
public:
    npc_lotto() : CreatureScript("npc_lotto") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer && !pPlayer->isGameMaster())
        {
            QueryResult result = WorldDatabase.PQuery("SELECT id FROM lotto_tickets WHERE guid=%u", pPlayer->GetGUIDLow());
            if (result)
            {
                pPlayer->SEND_GOSSIP_MENU(100001, pCreature->GetGUID());
                return false;
            }

            pPlayer->PrepareGossipMenu(pCreature);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BUY_TICKET, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            pPlayer->SEND_GOSSIP_MENU(100000, pCreature->GetGUID());
        }
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        
        if (!pPlayer->HasEnoughMoney(TICKET_COST))
            return false;
        
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF:
                pPlayer->ModifyMoney(-TICKET_COST);
                QueryResult result = WorldDatabase.Query("SELECT MAX(id) FROM lotto_tickets");
                uint32 id = result->Fetch()->GetUInt32();
                WorldDatabase.PExecute("INSERT INTO lotto_tickets (id,name,guid) VALUES (%u,'%s',%u);", id+1, pPlayer->GetName(), pPlayer->GetGUIDLow());
                char msg[500];
                sprintf(msg, "행운을 빌겟습니다, $N. 당신의 로또 구입번호는 %i 입니다.", id+1);
                pCreature->MonsterWhisper(msg, pPlayer->GetGUID());
                break;
        }
        pPlayer->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lottoAI (pCreature);
    }

    struct npc_lottoAI : public ScriptedAI
    {
        npc_lottoAI(Creature* pCreature) : ScriptedAI(pCreature) 
        {
            SayTimer = 1800*IN_MILLISECONDS;
        }
        
        uint32 SayTimer;

        void UpdateAI(const uint32 diff)
        {
            if (IsEventActive(EVENT_BLOODYLOTTO))
            {
                if (me->IsVisible())
                {
                    me->SetVisible(false);
                    QueryResult result = WorldDatabase.Query("SELECT MAX(id) FROM lotto_tickets");
                    uint32 maxTickets = result->Fetch()->GetUInt32();
                    if (!maxTickets)
                        return;

                    result = WorldDatabase.Query("SELECT name, guid FROM `lotto_tickets` ORDER BY RAND() LIMIT 1;");
                    uint32 position = 0;

                    do
                    {
                        ++position;

                        Field *fields = result->Fetch();

                        const char* name = fields[0].GetCString();
                        uint32 guid = fields[1].GetUInt32();
                        uint32 reward = TICKET_COST / (1 << position) * maxTickets;

                        WorldDatabase.PExecute("INSERT INTO `lotto_extractions` (winner,guid,position,reward) VALUES ('%s',%u,%u,%u);",name,guid,position,reward);

                        // Send reward by mail
                        Player *pPlayer = sObjectMgr->GetPlayerByLowGUID(guid);
                        SQLTransaction trans = CharacterDatabase.BeginTransaction();
						MailDraft("Lotto","당첨을 축하드립니다")
                            .AddMoney(reward)
                            .SendMailTo(trans, MailReceiver(pPlayer, GUID_LOPART(guid)), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
                        CharacterDatabase.CommitTransaction(trans);

                        // Event Message
                        sWorld->SendWorldText(LANG_EVENTMESSAGE, name);
                    }
                    while (result->NextRow());

                    // Delete tickets after extraction
                    WorldDatabase.PExecute("DELETE FROM lotto_tickets;");
                }
            }
            else
            {
                if (!me->IsVisible())
                    me->SetVisible(true);
                    
                if (SayTimer <= diff)
                {
                    me->MonsterSay("Lotto! 가 여기왔습니다.", 0, NULL);
                    SayTimer = 1800*IN_MILLISECONDS;
                }
                else SayTimer -= diff;
            }
        }
    };

};

class npc_Mailsender : public CreatureScript
{
public:
    npc_Mailsender() : CreatureScript("npc_Mailsender") { }

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

						MailSender sender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM);  // 보내는 사람이 GM으로 등록
						Player *pPlayer = sObjectMgr->GetPlayerByLowGUID(m_guid); //guid 값을 넣으면 케릭터를 찾을수있다.
						SQLTransaction trans = CharacterDatabase.BeginTransaction();   //메일관련 SQL을 등록
						MailDraft draft("몽섭이벤트","당첨을 축하드립니다");
	                     
						 //Item* Item::CreateItem(uint32 item, uint32 count, Player const* player)   
				        
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
void AddSC_npc_lottery()
{
    new npc_lotto();
	new npc_Mailsender();
}