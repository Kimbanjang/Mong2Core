#include "ScriptPCH.h"
#include "Lyn_han.h"
#include "Sweet_TeleportNPC.h"
#include "InstanceSaveMgr.h"


#define GoBack C_WHT"[�ڷ�]"

// Teleport NPC GossipHello
class Sweet_TeleportNPC : public CreatureScript
{
public:
	Sweet_TeleportNPC() : CreatureScript("Sweet_TeleportNPC") {}
	
	bool OnGossipHello(Player * pPlayer, Creature * pCreature)
	{
		if (pPlayer->isInCombat() || pPlayer->HasInvisibilityAura() || pPlayer->HasStealthAura())
		{
			SEND_NOTIFICATION(C_YLW"����� ���� ���Դϴ�.");
			GOSSIP_CLOSE();
			return true;
		}
		
		
		//GOSSIP_ITEM(MI_WNG, C_BRW"[�̵� �ϱ�]",		SEND_MAIN, PG_TRAVEL);
		//GOSSIP_ITEM(MI_WNG, C_DGR"[���� �ޱ�]",		SEND_MAIN, PG_BUFF);
		GOSSIP_ITEM(MI_WL1, C_PNK"[���� �ޱ�]",		SEND_MAIN, PG_SUPPORT);
		GOSSIP_ITEM(MI_WNG, C_BRW"[��ų ����]",		SEND_MAIN, PG_SKILL);
		  

		GOSSIP_MENU(700000, pCreature->GetGUID());
		return true;
	}

	// Teleport NPC GossipSelect
	bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 iSender, uint32 iAction)
	{
		if (pPlayer->isInCombat() || pPlayer->HasInvisibilityAura() || pPlayer->HasStealthAura())
		{
			SEND_NOTIFICATION(C_YLW"����� ���� ���Դϴ�.");
			GOSSIP_CLOSE();
			return true;
		}

		// Pages accessed via Main Menu
		if (iSender == SEND_MAIN)
		{
			GOSSIP_CLEAR();
			if (iAction != PG_MAIN)
				GOSSIP_ITEM(MI_CHT, GoBack,	SEND_MAIN, PG_MAIN);

			if (iAction == PG_MAIN)			// Return to Main Page
				return OnGossipHello(pPlayer, pCreature);

			if (iAction == PG_TRAVEL)		// Travel Page
			{
				GOSSIP_ITEM(MI_WNG, C_BRW"[�뵵��]",			SEND_TRAVEL, PG_CITY_T);
				GOSSIP_ITEM(MI_WNG, C_DGR"[����]",			SEND_TRAVEL, PG_TOWN_T);
				//GOSSIP_ITEM(MI_WNG, C_RED"[PVP & ������ ����Ʈ ����]",	SEND_TRAVEL, PG_PVP_T);
				GOSSIP_ITEM(MI_WNG, C_PRL"[�δ� & ���ݴ�]",		SEND_TRAVEL, PG_D_AND_R);
			}

			if (iAction == PG_BUFF)		// Buff Page
			{
 		               GOSSIP_ITEM(MI_BOK, C_BLU"[���� 6��(10+) - 10 ���]",	SEND_BUFF, 0);
					  /* if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
 						GOSSIP_ITEM(MI_BOK, C_PRL"[GM ���� 6��(60+) - 60 ���]",	SEND_BUFF, 1);*/
			}

			if (iAction == PG_SUPPORT)		// Support Page
			{
				GOSSIP_ITEM(MI_WL1, C_GRN"[Ư�� �ʱ�ȭ - ����!]",			SEND_SUPPORT, 0);
				GOSSIP_ITEM(MI_WNG, C_PRL"[���� Ž�� - 100 ���]",	SEND_SUPPORT, 1);
				GOSSIP_ITEM(MI_WNG, C_ORG"[��Ȱ ������ ���� - 10 ���]",	SEND_SUPPORT, 2);
			}
			if (iAction == PG_SKILL)		//skil Page
			{
				GOSSIP_ITEM(MI_WNG, "[���� - 600 ���]",	SEND_SKILL, 164);				
				GOSSIP_ITEM(MI_WNG, "[���� - 600 ���]",	SEND_SKILL, 165);
				GOSSIP_ITEM(MI_WNG, "[���� - 600 ���]",	SEND_SKILL, 171);
				GOSSIP_ITEM(MI_WNG, "[���� - 600 ���]",	SEND_SKILL, 182);
				GOSSIP_ITEM(MI_WNG, "[ä�� - 600 ���]",	SEND_SKILL, 186);
				GOSSIP_ITEM(MI_WNG, "[��� - 600 ���]",	SEND_SKILL, 197);
				GOSSIP_ITEM(MI_WNG, "[��� - 600 ���]",	SEND_SKILL, 202);
				GOSSIP_ITEM(MI_WNG, "[���� - 600 ���]",	SEND_SKILL, 333);
				GOSSIP_ITEM(MI_WNG, "[���� - 600 ���]",	SEND_SKILL, 393);
				GOSSIP_ITEM(MI_WNG, "[���� - 600 ���]",	SEND_SKILL, 755);
				GOSSIP_ITEM(MI_WNG, "[�ְ� - 600 ���]",	SEND_SKILL, 773);

			}
			
			GOSSIP_MENU(700000, pCreature->GetGUID());
		}

		/*
		Teleport
		=================================================================================================================================================================
		=================================================================================================================================================================
		=================================================================================================================================================================
		*/

		// City Teleport
		if (iSender == SEND_TE_CITY)
		{
			GOSSIP_CLOSE();

			TELEPORT_TO(travelCity[iAction].map, travelCity[iAction].posx, travelCity[iAction].posy, travelCity[iAction].posz, travelCity[iAction].poso);
		}

		// Azeroth Towns Teleport
		if (iSender == SEND_TE_T_AZ)
		{
			GOSSIP_CLOSE();
			
			TELEPORT_TO(townAZ[iAction].map, townAZ[iAction].posx, townAZ[iAction].posy, townAZ[iAction].posz, townAZ[iAction].poso);
		}

		// Outland Towns Teleport
		if (iSender == SEND_TE_T_OL)
		{
			GOSSIP_CLOSE();
			
			TELEPORT_TO(townOL[iAction].map, townOL[iAction].posx, townOL[iAction].posy, townOL[iAction].posz, townOL[iAction].poso);
		}

		// Northrend Towns Teleport
		if (iSender == SEND_TE_T_NR)
		{
			GOSSIP_CLOSE();
			
			TELEPORT_TO(townNR[iAction].map, townNR[iAction].posx, townNR[iAction].posy, townNR[iAction].posz, townNR[iAction].poso);
		}

		// Azeroth Dungeons Teleport
		if (iSender == SEND_TE_D_AZ)
		{
			GOSSIP_CLOSE();
			
			TELEPORT_TO(dungAZ[iAction].map, dungAZ[iAction].posx, dungAZ[iAction].posy, dungAZ[iAction].posz, dungAZ[iAction].poso);
		}

		// Outland Dungeons Teleport
		if (iSender == SEND_TE_D_OL)
		{
			GOSSIP_CLOSE();
			
			TELEPORT_TO(dungOL[iAction].map, dungOL[iAction].posx, dungOL[iAction].posy, dungOL[iAction].posz, dungOL[iAction].poso);
		}

		// Northrend Dungeons Teleport
		if (iSender == SEND_TE_D_NR)
		{
			GOSSIP_CLOSE();
			
			TELEPORT_TO(dungNR[iAction].map, dungNR[iAction].posx, dungNR[iAction].posy, dungNR[iAction].posz, dungNR[iAction].poso);
		}

		// PvP Teleport
		if (iSender == SEND_TE_PVP)
		{
			GOSSIP_CLOSE();
			
			TELEPORT_TO(travelPVP[iAction].map, travelPVP[iAction].posx, travelPVP[iAction].posy, travelPVP[iAction].posz, travelPVP[iAction].poso);
		}
		//Skill Set
		if (iSender == SEND_SKILL)
		{
			
			if (pPlayer->GetSkillValue(iAction))
			{
				//uint32 money = pPlayer->GetMoney();
				//if (money < 6000000)
				//{
				//	SEND_NOTIFICATION(C_RED"��尡 �����մϴ�.");
				//}
				//else
				//{
				//	pPlayer->SetMoney(money - 6000000);
					pPlayer->SetSkill(iAction,pPlayer->GetSkillStep(iAction), 400, 450);
				}
			}
			else
			{
				SEND_NOTIFICATION(C_RED"���� ����� ���� ��ų�Դϴ�.");
			}
		}
		// Buff
		if (iSender == SEND_BUFF)
		{
			switch (iAction)
			{
			case 0:		// ����
				{
					if ( pPlayer->getLevel() >= 10 )
					{
						uint32 money = pPlayer->GetMoney();
						if (money < 100000)
						{
							SEND_NOTIFICATION(C_RED"��尡 �����մϴ�.");
						}
						else
						{
							pPlayer->SetMoney(money - 100000);

							pCreature->CastSpell(pPlayer, 16612, true);
							pCreature->CastSpell(pPlayer, 17013, true);
							pCreature->CastSpell(pPlayer, 10767, true);
							pCreature->CastSpell(pPlayer, 48161, true);
							pCreature->CastSpell(pPlayer, 42995, true);
							pCreature->CastSpell(pPlayer, 48469, true);
							pCreature->CastSpell(pPlayer, 57940, true);
							
							SEND_NOTIFICATION(C_YLW"������ �Ϸ�Ǿ����ϴ�.");
						}
					}
					else
						SEND_NOTIFICATION(C_RED"������ �����ϴ�.");
				}
				break;
            		case 1:		// GM ����
				{
					if ( pPlayer->getLevel() >= 60 )
					{
						uint32 money = pPlayer->GetMoney();
						if (money < 600000)
						{
							SEND_NOTIFICATION(C_RED"��尡 �����մϴ�.");
						}
						else
						{
							pPlayer->SetMoney(money - 600000);

							pCreature->CastSpell(pPlayer, 15366, true);
							//pCreature->CastSpell(pPlayer, 16609, true);
							pCreature->CastSpell(pPlayer, 24425, true);
							pCreature->CastSpell(pPlayer, 22888, true);
							//pCreature->CastSpell(pPlayer, 34410, true);
							//pCreature->CastSpell(pPlayer, 29235, true);
							
							SEND_NOTIFICATION(C_YLW"������ �Ϸ�Ǿ����ϴ�.");
						}
					}
					else
						SEND_NOTIFICATION(C_RED"������ �����ϴ�.");
				}
				break;

			}

			GOSSIP_CLOSE(); // sweet
			return true;
		}

		// Support
		if (iSender == SEND_SUPPORT)
		{
			switch (iAction)
			{
			case 0:		// Repair Items //Ư���ʱ�ȭ
				{			
					pPlayer->resetTalents(true);
					pPlayer->SendTalentsInfoData(false);
					SEND_NOTIFICATION(C_YLW"Ư���� �ʱ�ȭ �Ǿ����ϴ�.");
				}
				break;

			case 1:		// Explore World
				{
					uint32 money = pPlayer->GetMoney();
					if (money < 1000000)
					{
						SEND_NOTIFICATION(C_RED"��尡 �����մϴ�.");
					}
					else
					{
						pPlayer->SetMoney(money - 1000000);

						for (uint8 i = 0; i < 128; i++)
							pPlayer->SetFlag(PLAYER_EXPLORED_ZONES_1+i, 0xFFFFFFFF);

						SEND_NOTIFICATION(C_YLW"��� ������ ���Ƚ��ϴ�.");
					}
				}
				break;

			case 2:		// ��Ȱ ������ ����
				{
					uint32 money = pPlayer->GetMoney();
					if (money < 100000)
					{
						SEND_NOTIFICATION(C_RED"��尡 �����մϴ�.");
					}
					else
					{
						pPlayer->SetMoney(money - 100000);
						pPlayer->learnSpell(DEATHSICK, false);
						pPlayer->removeSpell(DEATHSICK);
						SEND_NOTIFICATION(C_YLW"��Ȱ �������� ���ŵǾ����ϴ�.");
					}
				}
				break;
			}

			GOSSIP_CLOSE(); // sweet
//			return OnGossipHello(pPlayer, pCreature);
			return true;
		}

		/*
		Travel
		=================================================================================================================================================================
		=================================================================================================================================================================
		=================================================================================================================================================================
		*/

		if (iSender == SEND_TRAVEL)
		{
			// Pages accessed via Travel Menu
			if (iAction == PG_CITY_T || iAction == PG_TOWN_T || iAction == PG_PVP_T || iAction == PG_D_AND_R)
			{
				GOSSIP_CLEAR();
				GOSSIP_ITEM(MI_CHT, GoBack,	SEND_MAIN, PG_TRAVEL);

				switch (iAction)
				{
				case PG_CITY_T:			// City Travel Menu
					{
						if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
						{
							GOSSIP_ITEM(MI_WNG, C_ORG"[���׸���]",	SEND_TE_CITY, 0);
							GOSSIP_ITEM(MI_WNG, C_ORG"[�����Ƽ]",	SEND_TE_CITY, 1);
							GOSSIP_ITEM(MI_WNG, C_ORG"[��� ����]",	SEND_TE_CITY, 2);
							GOSSIP_ITEM(MI_WNG, C_ORG"[�ǹ���]",	SEND_TE_CITY, 3);
						}
						if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
						{
							GOSSIP_ITEM(MI_WNG, C_ORG"[��������]",	SEND_TE_CITY, 4);
							GOSSIP_ITEM(MI_WNG, C_ORG"[���̾�����]",	SEND_TE_CITY, 5);
							GOSSIP_ITEM(MI_WNG, C_ORG"[�ٸ�������]",	SEND_TE_CITY, 6);
							GOSSIP_ITEM(MI_WNG, C_ORG"[���Ҵٸ�]",	SEND_TE_CITY, 7);
						}

						GOSSIP_ITEM(MI_WNG, C_YLW"[��Ʈ��]",		SEND_TE_CITY, 8);
						GOSSIP_ITEM(MI_WNG, C_BLU"[�޶��]",		SEND_TE_CITY, 9);
					}
					break;
		
				case PG_TOWN_T:			// Town Travel Menu
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[�����ν�]",		SEND_TRAVEL, PG_AZ_T);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�ƿ�����]",		SEND_TRAVEL, PG_OL_T);
						GOSSIP_ITEM(MI_WNG, C_BLU"[�뽺����]",		SEND_TRAVEL, PG_NR_T);
					}
					break;

				case PG_PVP_T:			// PvP Travel Menu
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[����ٽ� ������]",SEND_TE_PVP, PLAYER_TEAM() == HORDE ? 0 : 9);
						GOSSIP_ITEM(MI_WNG, C_ORG"[������ ����]",SEND_TE_PVP, PLAYER_TEAM() == HORDE ? 1 : 10);

						if (PLAYER_TEAM() == HORDE)
						{
							GOSSIP_ITEM(MI_WNG, C_ORG"[�������� ħ��]",	SEND_TE_PVP, 2);
							GOSSIP_ITEM(MI_WNG, C_ORG"[���̾����� ħ��]",		SEND_TE_PVP, 3);
							GOSSIP_ITEM(MI_WNG, C_ORG"[�ٸ������� ħ��]",		SEND_TE_PVP, 4);
							GOSSIP_ITEM(MI_WNG, C_ORG"[���Ҵٸ� ħ��]",		SEND_TE_PVP, 5);
						}
						if (PLAYER_TEAM() == ALLIANCE)
						{
							GOSSIP_ITEM(MI_WNG, C_ORG"[���׸��� ħ��]",		SEND_TE_PVP, 11);
							GOSSIP_ITEM(MI_WNG, C_ORG"[�����Ƽ ħ��]",		SEND_TE_PVP, 12);
							GOSSIP_ITEM(MI_WNG, C_ORG"[��� ���� ħ��]",	SEND_TE_PVP, 13);
							GOSSIP_ITEM(MI_WNG, C_ORG"[�ǹ��� ħ��]",	SEND_TE_PVP, 14);
						}
						
						GOSSIP_ITEM(MI_WNG, C_DGR"[���׶���: ���� ������ 65+]",	SEND_TE_PVP, PLAYER_TEAM() == HORDE ? 6 : 15);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�ٵ��: ����� ������ 75+]",	SEND_TE_PVP, PLAYER_TEAM() == HORDE ? 7 : 16);
						GOSSIP_ITEM(MI_WNG, C_BLU"[�ܿ�վƱ� ȣ��]",	SEND_TE_PVP, PLAYER_TEAM() == HORDE ? 8 : 17);
					}
					break;

				case PG_D_AND_R:		// Dungeons And Raids Menu
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[�����ν� �δ�]",	SEND_TRAVEL, PG_AZ_D_P1);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�����ν� ���ݴ�]",	SEND_TRAVEL, PG_AZ_R);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�ƿ����� �δ�]",	SEND_TRAVEL, PG_OL_D_P1);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�ƿ����� ���ݴ�]",	SEND_TRAVEL, PG_OL_R);
						GOSSIP_ITEM(MI_WNG, C_BLU"[�뽺���� �δ�]",	SEND_TRAVEL, PG_NR_D_P1);
						GOSSIP_ITEM(MI_WNG, C_BLU"[�뽺���� ���ݴ�]",	SEND_TRAVEL, PG_NR_R);
					}
					break;
				}
			}

			// Pages accessed via Town Travel Menu
			if (iAction == PG_AZ_T || iAction == PG_OL_T || iAction == PG_NR_T)
			{
				GOSSIP_CLEAR();
				GOSSIP_ITEM(MI_CHT, GoBack,	SEND_TRAVEL, PG_TOWN_T);

				if (iAction == PG_AZ_T)
				{
					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_ORG"[ȣ�� ����]",	SEND_TRAVEL, PG_AZ_F_P1);
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_ORG"[����̾� ����]",SEND_TRAVEL, PG_AZ_F_P1);

					GOSSIP_ITEM(MI_WNG, C_ORG"[�߸� ����]",		SEND_TRAVEL, PG_AZ_N);
				}

				if (iAction == PG_OL_T)
				{
					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_DGR"[ȣ�� ����]",	SEND_TRAVEL, PG_OL_F);
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_DGR"[����̾� ����]",SEND_TRAVEL, PG_OL_F);

					GOSSIP_ITEM(MI_WNG, C_DGR"[�߸� ����]",		SEND_TRAVEL, PG_OL_N);
				}

				if (iAction == PG_NR_T)
				{
					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_BLU"[ȣ�� ����]",	SEND_TRAVEL, PG_NR_F_P1);
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_BLU"[����̾� ����]",SEND_TRAVEL, PG_NR_F_P1);

					GOSSIP_ITEM(MI_WNG, C_BLU"[�߸� ����]",		SEND_TRAVEL, PG_NR_N_P1);
				}
			}

			// Pages accessed via Azeroth Town Travel Menu
			if (iAction == PG_AZ_F_P1 || iAction == PG_AZ_F_P2 || iAction == PG_AZ_N)
			{
				GOSSIP_CLEAR();
				GOSSIP_ITEM(MI_CHT, GoBack,	SEND_TRAVEL, PG_AZ_T);

				if (iAction == PG_AZ_F_P1)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"[���� ������] -->",		SEND_TRAVEL, PG_AZ_F_P2);

					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[�Ǹۿ� �ʼ�]",			SEND_TE_T_AZ, 0);
						GOSSIP_ITEM(MI_WNG, C_ORG"[������ ����]",			SEND_TE_T_AZ, 1);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�����: ������ �߿���]",		SEND_TE_T_AZ, 2);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�Ҹ��� ��: Ÿ����� �߿���]",		SEND_TE_T_AZ, 3);
						GOSSIP_ITEM(MI_WNG, C_ORG"[ȭ�� ����]",				SEND_TE_T_AZ, 4);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�������� ���츮: �����ٶ� ���츮]",	SEND_TE_T_AZ, 5);
						GOSSIP_ITEM(MI_WNG, C_ORG"[���ô��� ��¥��: �׷Ұ� �ֵ���]",	SEND_TE_T_AZ, 6);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�ƶ�� ���: �ظ���]",			SEND_TE_T_AZ, 7);
						GOSSIP_ITEM(MI_WNG, C_ORG"[Ȳ���� ��: ī������]",			SEND_TE_T_AZ, 8);
						GOSSIP_ITEM(MI_WNG, C_ORG"[���� ������: �����ͽ�ũ ����]",		SEND_TE_T_AZ, 9);
						GOSSIP_ITEM(MI_WNG, C_ORG"[������ ��: �״ü��� ����]",		SEND_TE_T_AZ, 10);
						GOSSIP_ITEM(MI_WNG, C_ORG"[��� ��¥��: �丷���� �ֵ���]",		SEND_TE_T_AZ, 11);
						GOSSIP_ITEM(MI_WNG, C_ORG"[������ ��: ���䳪��]",			SEND_TE_T_AZ, 12);
					}
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[���γ�����: �ͱ��� ���츮]",		SEND_TE_T_AZ, 20);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�����¥��: �ƽ�Ʈ�󳪸�]",		SEND_TE_T_AZ, 21);
						GOSSIP_ITEM(MI_WNG, C_ORG"[����� �ؾ�: �ƿ������]",		SEND_TE_T_AZ, 22);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�ͺ��Ȱ� ��: �ͺ� �����ʼ�]",		SEND_TE_T_AZ, 23);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�����ٶ� �߿���]",			SEND_TE_T_AZ, 24);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�״� ��: ��ũ���̾�]",			SEND_TE_T_AZ, 25);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�����: ����� ���]",		SEND_TE_T_AZ, 26);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�������� ���: ����ũ���̾�]",		SEND_TE_T_AZ, 27);
						GOSSIP_ITEM(MI_WNG, C_ORG"[������: �޳׽� �ױ�]",			SEND_TE_T_AZ, 28);
						GOSSIP_ITEM(MI_WNG, C_ORG"[���ֹ��� ��: �״����� ���]",			SEND_TE_T_AZ, 29);
						GOSSIP_ITEM(MI_WNG, C_ORG"[������ ��: �������� �߿���]",		SEND_TE_T_AZ, 30);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�ݶ��� �߿���]",			SEND_TE_T_AZ, 31);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�ӽ� �ֵ���]",			SEND_TE_T_AZ, 32);
					}
				}

				if (iAction == PG_AZ_F_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [���� ������]",		SEND_TRAVEL, PG_AZ_F_P1);

					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[������ ���: �ع��� �߿���]",		SEND_TE_T_AZ, 13);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�����귡�� ������: Ÿ�� �г���]",	SEND_TE_T_AZ, 14);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�Ҹ��� ��: ũ�ν��ε�]",		SEND_TE_T_AZ, 15);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�����ҳ��� ��: ��������]",		SEND_TE_T_AZ, 16);
						GOSSIP_ITEM(MI_WNG, C_ORG"[������ ��: Ʈ��������]",		SEND_TE_T_AZ, 17);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�������: �߷θ���ũ]",			SEND_TE_T_AZ, 18);
						GOSSIP_ITEM(MI_WNG, C_ORG"[��� ��¥��: �������� ���ʱ���]",	SEND_TE_T_AZ, 19);
					}
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[���� ��������: ������ ���]",		SEND_TE_T_AZ, 33);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�����귡�� ������: ��콺���]",		SEND_TE_T_AZ, 34);
						GOSSIP_ITEM(MI_WNG, C_ORG"[������ ���: ������ ���츮]",		SEND_TE_T_AZ, 35);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�������� ��]",			SEND_TE_T_AZ, 36);
						GOSSIP_ITEM(MI_WNG, C_ORG"[Ż���帮�� �ʼ�]",			SEND_TE_T_AZ, 37);
						GOSSIP_ITEM(MI_WNG, C_ORG"[Ż�󳪸�]",				SEND_TE_T_AZ, 38);
						GOSSIP_ITEM(MI_WNG, C_ORG"[��� ȣ��: �ڻ縶]",			SEND_TE_T_AZ, 39);
						GOSSIP_ITEM(MI_WNG, C_ORG"[�������� ������: �׶��� ��]",		SEND_TE_T_AZ, 40);
					}
				}

				if (iAction == PG_AZ_N)
				{
					GOSSIP_ITEM(MI_WNG, C_ORG"[���ô��� ��¥��: ������]",			SEND_TE_T_AZ, 41);
					GOSSIP_ITEM(MI_WNG, C_ORG"[�Ǹ�����: �������� ���]",			SEND_TE_T_AZ, 42);
					GOSSIP_ITEM(MI_WNG, C_ORG"[���޶��� ����]",				SEND_TE_T_AZ, 43);
					GOSSIP_ITEM(MI_WNG, C_ORG"[������ ����: ������ ����]",			SEND_TE_T_AZ, 44);
					GOSSIP_ITEM(MI_WNG, C_ORG"[Ÿ������: ������]",				SEND_TE_T_AZ, 45);
					GOSSIP_ITEM(MI_WNG, C_ORG"[���ٳ��� ��]",				SEND_TE_T_AZ, 46);
					GOSSIP_ITEM(MI_WNG, C_ORG"[���� ��������: ����� �� �����]",		SEND_TE_T_AZ, 47);
					GOSSIP_ITEM(MI_WNG, C_ORG"[������ �߿���]",				SEND_TE_T_AZ, 48);
					GOSSIP_ITEM(MI_WNG, C_ORG"[���� ��]",					SEND_TE_T_AZ, 49);
					GOSSIP_ITEM(MI_WNG, C_ORG"[������� ����]",				SEND_TE_T_AZ, 50);
					GOSSIP_ITEM(MI_WNG, C_ORG"[�Ҹ��� ��: �����]",				SEND_TE_T_AZ, 51);
					GOSSIP_ITEM(MI_WNG, C_ORG"[��� ���� ����]",				SEND_TE_T_AZ, 52);
				}
			}

			// Pages accessed via Outland Town Travel Menu
			if (iAction == PG_OL_F || iAction == PG_OL_N)
			{
				GOSSIP_CLEAR();
				GOSSIP_ITEM(MI_CHT, GoBack,	SEND_TRAVEL, PG_OL_T);

				if (iAction == PG_OL_F)
				{
					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_DGR"[������ �ݵ�: ���� ����ž]",		SEND_TE_T_OL, 0);
						GOSSIP_ITEM(MI_WNG, C_DGR"[���׶���: ����ٸ�]",			SEND_TE_T_OL, 1);
						GOSSIP_ITEM(MI_WNG, C_DGR"[Į�� ���: ��ũ��Ż ����]",		SEND_TE_T_OL, 2);
						GOSSIP_ITEM(MI_WNG, C_DGR"[��Ҵ� ��¥��: ��Ҵ� ����]",		SEND_TE_T_OL, 3);
						GOSSIP_ITEM(MI_WNG, C_DGR"[������ �ݵ�: �ذ��ġ �ʼ�]",		SEND_TE_T_OL, 4);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�׷�ī�� ��: ����ġ ���]",		SEND_TE_T_OL, 5);	
						GOSSIP_ITEM(MI_WNG, C_DGR"[�尡�� ������: ���� �����ʼ�]",		SEND_TE_T_OL, 6);
						GOSSIP_ITEM(MI_WNG, C_DGR"[������ �ݵ�: ������]",			SEND_TE_T_OL, 7);
						GOSSIP_ITEM(MI_WNG, C_DGR"[Į�� ���: õ�ձ��� ���]",		SEND_TE_T_OL, 8);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�尡�� ������: �ں����]",		SEND_TE_T_OL, 9);
					}
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_DGR"[�˷����� ��ä]",			SEND_TE_T_OL, 10);
						GOSSIP_ITEM(MI_WNG, C_DGR"[���� ���]",			SEND_TE_T_OL, 11);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�������� �ǳ�ó]",			SEND_TE_T_OL, 12);
						GOSSIP_ITEM(MI_WNG, C_DGR"[¡�˴ٸ� ����]",			SEND_TE_T_OL, 13);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�ǹٳ���]",				SEND_TE_T_OL, 14);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�ڶ�Ƹ�]",				SEND_TE_T_OL, 15);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�ڷ�����]",				SEND_TE_T_OL, 16);
						GOSSIP_ITEM(MI_WNG, C_DGR"[���ϸ�Ʈ ���]",			SEND_TE_T_OL, 17);
						GOSSIP_ITEM(MI_WNG, C_DGR"[�佯���� ��������]",			SEND_TE_T_OL, 18);
						GOSSIP_ITEM(MI_WNG, C_DGR"[���ϵ��ظ� ��ä]",			SEND_TE_T_OL, 19);
					}
				}

				if (iAction == PG_OL_N)
				{
					GOSSIP_ITEM(MI_WNG, C_DGR"[��Ÿ�� ����]",				SEND_TE_T_OL, 20);
					GOSSIP_ITEM(MI_WNG, C_DGR"[52 ����]",					SEND_TE_T_OL, 21);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�����ٶ� �������]",				SEND_TE_T_OL, 22);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�������� �߿���]",				SEND_TE_T_OL, 23);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�ڽ���ġ]",					SEND_TE_T_OL, 24);
					GOSSIP_ITEM(MI_WNG, C_DGR"[������ ��]",					SEND_TE_T_OL, 25);
					GOSSIP_ITEM(MI_WNG, C_DGR"[���׸���]",					SEND_TE_T_OL, 26);
					GOSSIP_ITEM(MI_WNG, C_DGR"[���� ����]",					SEND_TE_T_OL, 27);
					GOSSIP_ITEM(MI_WNG, C_DGR"[��ǳ ÷ž]",					SEND_TE_T_OL, 28);
					GOSSIP_ITEM(MI_WNG, C_DGR"[����� ���]",				SEND_TE_T_OL, 29);
				}
			}

			// Pages accessed via Northrend Town Travel Menu
			if (iAction == PG_NR_F_P1 || iAction == PG_NR_F_P2 || iAction == PG_NR_N_P1 || iAction == PG_NR_N_P2)
			{
				GOSSIP_CLEAR();
				GOSSIP_ITEM(MI_CHT, GoBack,	SEND_TRAVEL, PG_NR_T);

				if (iAction == PG_NR_F_P1)
				{
					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_CHD, C_BLK"[���� ������] -->",	SEND_TRAVEL, PG_NR_F_P2);

						GOSSIP_ITEM(MI_WNG, C_BLU"[���¢�� ����: ���ݼ��� �߿���(Lv69~71)]",	SEND_TE_T_NR, 1);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���¢�� ����: �ܿ�߱� �߿���(Lv69~71)]",	SEND_TE_T_NR, 5);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���¢�� ����: �� �ư�����(Lv69~71)]",		SEND_TE_T_NR, 10);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���¢�� ����: ������ �����(Lv69~71)]",		SEND_TE_T_NR, 13);
						GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ��: �������ũ ���ʱ���(Lv69~72)]",	SEND_TE_T_NR, 2);
						GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ��: Ÿ��ī�� ����(Lv69~72)]",		SEND_TE_T_NR, 12);
						GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ��: ����뷡���� ���(Lv69~72)]",		SEND_TE_T_NR, 15);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���� �Ƚ�ó: �Ʊ׸����� ��ġ(Lv72~75)]",		SEND_TE_T_NR, 0);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���� �Ƚ�ó: �ڸ�ũ�� ��������(Lv72~75)]",	SEND_TE_T_NR, 9);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���� �Ƚ�ó: ������ �ʼ�(Lv72~75)]",		SEND_TE_T_NR, 14);
						GOSSIP_ITEM(MI_WNG, C_BLU"[ȸ�� ������: ��ũ�� �߿���(Lv73~75)]",		SEND_TE_T_NR, 3);
						GOSSIP_ITEM(MI_WNG, C_BLU"[ȸ�� ������: ������ ���(Lv73~75)]",		SEND_TE_T_NR, 6);
						GOSSIP_ITEM(MI_WNG, C_BLU"[�ٵ��: �κ����(Lv74~77)]",			SEND_TE_T_NR, 7);
					}
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_BLU"[���¢�� ����: �����ٸ� ���(Lv69~71)]",		SEND_TE_T_NR, 19);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���¢�� ����: �߰���(Lv69~71)]",		SEND_TE_T_NR, 22);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���¢�� ����: ���ΰ��� ��ä(Lv69~71)]",	SEND_TE_T_NR, 25);
						GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ��: ����ũ��ũ ������(Lv69~72)]",		SEND_TE_T_NR, 17);
						GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ��: ����� ��ä(Lv69~72)]",		SEND_TE_T_NR, 23);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���� �Ƚ�ó: ������ ���(Lv72~75)]",		SEND_TE_T_NR, 18);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���� �Ƚ�ó: ���� ����(Lv72~75)]",		SEND_TE_T_NR, 21);
						GOSSIP_ITEM(MI_WNG, C_BLU"[���� �Ƚ�ó: ���Ͱ��� ��ä(Lv72~75)]",		SEND_TE_T_NR, 27);
						GOSSIP_ITEM(MI_WNG, C_BLU"[ȸ�� ������: ȣ�ں��ҳ��� ���θ�(Lv73~75)]",	SEND_TE_T_NR, 16);
						GOSSIP_ITEM(MI_WNG, C_BLU"[ȸ�� ������: ���� �������� ���� �߿���(Lv73~75)]",	SEND_TE_T_NR, 24);
						GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ���츮: �������(Lv78~80)]",		SEND_TE_T_NR, 20);
						GOSSIP_ITEM(MI_WNG, C_BLU"[�����뷡 ��: ���巯�� ������]",			SEND_TE_T_NR, 26);
					}
				}

				if (iAction == PG_NR_F_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [���� ������]",		SEND_TRAVEL, PG_NR_F_P1);

					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ���츮: �׷Ҿƽ� �߶� ����(Lv78~80)]",	SEND_TE_T_NR, 8);
						GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ���츮: ��ī�� �߿���(Lv78~80)]",		SEND_TE_T_NR, 4);
						GOSSIP_ITEM(MI_WNG, C_BLU"[�����뷡 ��: ������ �����ʼ�]",			SEND_TE_T_NR, 11);
					}
					if (PLAYER_TEAM() == ALLIANCE)
					{
					}
				}

				if (iAction == PG_NR_N_P1)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"[���� ������] -->",		SEND_TRAVEL, PG_NR_N_P2);

					GOSSIP_ITEM(MI_WNG, C_BLU"[���¢�� ����: ī������(Lv69~71)]",			SEND_TE_T_NR, 36);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ��: ȣ�ڼ� ����(Lv69~72)]",			SEND_TE_T_NR, 28);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ��: ������ ��ȣ��(Lv69~72)]",			SEND_TE_T_NR, 44);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ��: �촩��(Lv69~72)]",				SEND_TE_T_NR, 45);
					GOSSIP_ITEM(MI_WNG, C_BLU"[���� �Ƚ�ó: ���Ű �ױ�(Lv72~75)]",			SEND_TE_T_NR, 39);
					GOSSIP_ITEM(MI_WNG, C_BLU"[���� �Ƚ�ó: ��潰�� ���(Lv72~75)]",			SEND_TE_T_NR, 46);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�ٵ��: ���� ƴ(Lv74~77)]",				SEND_TE_T_NR, 38);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�ٵ��: ĥ���� �����ʼ�(Lv74~77)]",			SEND_TE_T_NR, 34);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�ٵ��: �������ڱ� ������(Lv74~77)]",			SEND_TE_T_NR, 41);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�ٵ��: ���丣��(Lv74~77)]",				SEND_TE_T_NR, 47);
					GOSSIP_ITEM(MI_WNG, C_BLU"[����ڸ� ����: ȣ���� ������(Lv75~78)]",			SEND_TE_T_NR, 37);
					GOSSIP_ITEM(MI_WNG, C_BLU"[����ڸ� ����: �׽̿��� �ֵ���(Lv75~78)]",		SEND_TE_T_NR, 40);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ���츮: �� ���緽(Lv78~80)]",			SEND_TE_T_NR, 33);
				}

				if (iAction == PG_NR_N_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [���� ������]",		SEND_TRAVEL, PG_NR_N_P1);

					GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ���츮: K3(Lv78~80)]",				SEND_TE_T_NR, 35);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��ǳ�� ���츮: �ٿ��ũ���� ����ó(Lv78~80)]",		SEND_TE_T_NR, 30);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����հ�: �������ڱ� ��������(Lv78~80)]",		SEND_TE_T_NR, 42);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����հ�: ����� �����(Lv78~80)]",			SEND_TE_T_NR, 43);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����հ�: �������ڱ� ������� ����(Lv78~80)]",		SEND_TE_T_NR, 29);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����հ�: ���ڱ� ���츮(Lv78~80)]",			SEND_TE_T_NR, 31);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����հ�: ������ ����(Lv78~80)]",			SEND_TE_T_NR, 32);
				}
			}

			// Pages accessed via Dungeons And Raids Menu
			if (iAction == PG_AZ_D_P1 || iAction == PG_AZ_D_P2 || iAction == PG_AZ_R ||
				iAction == PG_OL_D_P1 || iAction == PG_OL_D_P2 || iAction == PG_OL_R ||
				iAction == PG_NR_D_P1 || iAction == PG_NR_D_P2 || iAction == PG_NR_R)
			{
				GOSSIP_CLEAR();
				GOSSIP_ITEM(MI_CHT, GoBack,	SEND_TRAVEL, PG_D_AND_R);

				if (iAction == PG_AZ_D_P1)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"[���� ������] -->",		SEND_TRAVEL, PG_AZ_D_P2);

					GOSSIP_ITEM(MI_WNG, C_ORG"[������ ��(Lv15~28)]",		SEND_TE_D_AZ, 13);
					GOSSIP_ITEM(MI_WNG, C_ORG"[����� ����(Lv15~28)]",		SEND_TE_D_AZ, 15);
					GOSSIP_ITEM(MI_WNG, C_ORG"[�׸��ڼ۰��� ��ä(Lv18~32)]",		SEND_TE_D_AZ, 10);
					GOSSIP_ITEM(MI_WNG, C_ORG"[�����ɿ��� ����(Lv20~35)]",		SEND_TE_D_AZ, 0);
					GOSSIP_ITEM(MI_WNG, C_ORG"[���õ��� �츮(Lv24~40)]",		SEND_TE_D_AZ, 7);	
					GOSSIP_ITEM(MI_WNG, C_ORG"[�𸮰�(Lv24~40)]",			SEND_TE_D_AZ, 4);
					GOSSIP_ITEM(MI_WNG, C_ORG"[�������ڱ� ������(Lv29~45)]",		SEND_TE_D_AZ, 8);
					GOSSIP_ITEM(MI_WNG, C_ORG"[��ٸ�(Lv32~52)]",			SEND_TE_D_AZ, 14);
					GOSSIP_ITEM(MI_WNG, C_ORG"[���õ��� ����(Lv33~47)]",		SEND_TE_D_AZ, 6);  
					GOSSIP_ITEM(MI_WNG, C_ORG"[����쵷(Lv40~58)]",			SEND_TE_D_AZ, 5);
					GOSSIP_ITEM(MI_WNG, C_ORG"[���Ķ�(Lv43~54)]",			SEND_TE_D_AZ, 16);
					GOSSIP_ITEM(MI_WNG, C_ORG"[��Ż��ī�� ����(Lv50~55)]",		SEND_TE_D_AZ, 12);
					GOSSIP_ITEM(MI_WNG, C_ORG"[��Ʈ��ָ�(Lv56~61)]",		SEND_TE_D_AZ, 11);
				}

				if (iAction == PG_AZ_D_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [���� ������]",		SEND_TRAVEL, PG_AZ_D_P1);

					GOSSIP_ITEM(MI_WNG, C_ORG"[�������� ÷ž����(Lv58~60)]",		SEND_TE_D_AZ, 1);
					GOSSIP_ITEM(MI_WNG, C_ORG"[�������� ÷ž����(Lv59~62)]",		SEND_TE_D_AZ, 2);
					GOSSIP_ITEM(MI_WNG, C_ORG"[������ ����(Lv54~61)]",		SEND_TE_D_AZ, 3);
					GOSSIP_ITEM(MI_WNG, C_ORG"[��Į�θǽ�(Lv56~61)]",		SEND_TE_D_AZ, 9);
				}

				if (iAction == PG_AZ_R)
				{
					GOSSIP_ITEM(MI_WNG, C_ORG"[�������� ����(40��)]",			SEND_TE_D_AZ, 17);
					GOSSIP_ITEM(MI_WNG, C_ORG"[ȭ������(40��)]",			SEND_TE_D_AZ, 18);
					GOSSIP_ITEM(MI_WNG, C_ORG"[�������� ����(20��)]",			SEND_TE_D_AZ, 19);
					GOSSIP_ITEM(MI_WNG, C_ORG"[�������� ���(40��)]",			SEND_TE_D_AZ, 20);
					GOSSIP_ITEM(MI_WNG, C_ORG"[�ٱ���(20��)]",			SEND_TE_D_AZ, 21);
				}

				if (iAction == PG_OL_D_P1)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"[���� ������] -->",		SEND_TRAVEL, PG_OL_D_P2);

					GOSSIP_ITEM(MI_WNG, C_DGR"[������ ��ä: ������ ����(Lv60~62)]",		SEND_TE_D_OL, 9);
					GOSSIP_ITEM(MI_WNG, C_DGR"[������ ��ä: ���� �뱤��(Lv61~63)]",		SEND_TE_D_OL, 10);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�����۰��� ������: ���� �뿪��(Lv62~64)]",	SEND_TE_D_OL, 6);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�����۰��� ������: ���ϼ���(Lv63~65)]",		SEND_TE_D_OL, 8);
					GOSSIP_ITEM(MI_WNG, C_DGR"[��Ų��: ���� ����(Lv64~66)]",			SEND_TE_D_OL, 1);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�ð��� ����: �� �����귡�� ������(Lv65~68)]",	SEND_TE_D_OL, 4);
					GOSSIP_ITEM(MI_WNG, C_DGR"[��Ų��: ��Ű���� �����(Lv65~67)]",		SEND_TE_D_OL, 0);
					GOSSIP_ITEM(MI_WNG, C_DGR"[��Ų��: ����ũ ����(Lv67~69)]",			SEND_TE_D_OL, 2);
					GOSSIP_ITEM(MI_WNG, C_DGR"[��Ų��: ����� �̱�(Lv70+)]",			SEND_TE_D_OL, 3);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�ð��� ����: ���� ��(Lv70+)]",			SEND_TE_D_OL, 5);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�����۰��� ������: ���� �����(Lv70+)]",		SEND_TE_D_OL, 7);
					GOSSIP_ITEM(MI_WNG, C_DGR"[������ ��ä: �������� ���� ����(Lv70+)]",	SEND_TE_D_OL, 11);
					GOSSIP_ITEM(MI_WNG, C_DGR"[���������� ����(Lv70+)]",			SEND_TE_D_OL, 12);
				}

				if (iAction == PG_OL_D_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [���� ������]",		SEND_TRAVEL, PG_OL_D_P1);

					GOSSIP_ITEM(MI_WNG, C_DGR"[��ǳ�� ���: ��īƮ����(Lv70+)]",	SEND_TE_D_OL, 13);
					GOSSIP_ITEM(MI_WNG, C_DGR"[��ǳ�� ���: �ŷ��� ����(Lv70+)]",	SEND_TE_D_OL, 14);
					GOSSIP_ITEM(MI_WNG, C_DGR"[��ǳ�� ���: ��ī����(Lv70+)]",		SEND_TE_D_OL, 15);
				}

				if (iAction == PG_OL_R)
				{	
					GOSSIP_ITEM(MI_WNG, C_DGR"[ī����]",				SEND_TE_D_OL, 20);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�پƸ�]",				SEND_TE_D_OL, 24);
					GOSSIP_ITEM(MI_WNG, C_DGR"[������ ��ä: �����׸����� ����]",	SEND_TE_D_OL, 19);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�׷��� ����]",			SEND_TE_D_OL, 18);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�ҹ� ����]",				SEND_TE_D_OL, 21);
					GOSSIP_ITEM(MI_WNG, C_DGR"[��ǳ�� ���: ��ǳ�� ���]",		SEND_TE_D_OL, 23);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�ð��� ����: ������ ���� ����]",		SEND_TE_D_OL, 17);
					GOSSIP_ITEM(MI_WNG, C_DGR"[���� ���]",				SEND_TE_D_OL, 16);
					GOSSIP_ITEM(MI_WNG, C_DGR"[�¾�� ���]",			SEND_TE_D_OL, 22);
				}
				
				if (iAction == PG_NR_D_P1)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"[���� ������] -->",		SEND_TRAVEL, PG_NR_D_P2);

					GOSSIP_ITEM(MI_WNG, C_BLU"[������ ž: ������ ž(Lv70~72)]",		SEND_TE_D_NR, 8);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��Ʈ���� ��ä: ��Ʈ���� ��ä(Lv70~72)]",		SEND_TE_D_NR, 14);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����׷�: �����׷�(Lv72~74)]",			SEND_TE_D_NR, 1);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��ī��Ʈ: ��� �ձ�(Lv74~76)]",			SEND_TE_D_NR, 0);
					GOSSIP_ITEM(MI_WNG, C_BLU"[���Ÿ�� ��ä(Lv74~76)]",			SEND_TE_D_NR, 3);
					GOSSIP_ITEM(MI_WNG, C_BLU"[������ ���(Lv75~77)]",			SEND_TE_D_NR, 10);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����(Lv76~78)]",				SEND_TE_D_NR, 4);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��ξƸ�: ���� ����(Lv77~79)]",			SEND_TE_D_NR, 13);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��Ʈ���� ��ä: ��Ʈ���� ÷ž(Lv80+)]",		SEND_TE_D_NR, 15);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�ð��� ����: �� ��Ʈ��ָ�(Lv80+)]",		SEND_TE_D_NR, 2);
					GOSSIP_ITEM(MI_WNG, C_BLU"[������ ž: ������ ��(Lv80+)]",			SEND_TE_D_NR, 9);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��ξƸ�: ������ ����(Lv80+)]",			SEND_TE_D_NR, 12);
					GOSSIP_ITEM(MI_WNG, C_BLU"[����� ������(Lv80+)]",			SEND_TE_D_NR, 11);
				}

				if (iAction == PG_NR_D_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [���� ������]",		SEND_TRAVEL, PG_NR_D_P1);

					GOSSIP_ITEM(MI_WNG, C_BLU"[�����հ� ��ä: ������ ����(Lv80+)]",		SEND_TE_D_NR, 5);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����հ� ��ä: ����� ������(Lv80+)]",		SEND_TE_D_NR, 6);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����հ� ��ä: ��ȥ�� ���ü�(Lv80+)]",		SEND_TE_D_NR, 7);
				}

				if (iAction == PG_NR_R)
				{
					GOSSIP_ITEM(MI_WNG, C_BLU"[��ī�� ����]",				SEND_TE_D_NR, 24);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��伮 ����]",				SEND_TE_D_NR, 20);
					GOSSIP_ITEM(MI_WNG, C_BLU"[������ ��]",					SEND_TE_D_NR, 19);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����󸶽�]",					SEND_TE_D_NR, 17);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��ξƸ�]",					SEND_TE_D_NR, 23);
					GOSSIP_ITEM(MI_WNG, C_BLU"[���ڱ��� ������]",				SEND_TE_D_NR, 22);
					GOSSIP_ITEM(MI_WNG, C_BLU"[���нþ��� ����]",				SEND_TE_D_NR, 18);
					GOSSIP_ITEM(MI_WNG, C_BLU"[�����հ� ��ä]",				SEND_TE_D_NR, 16);
					GOSSIP_ITEM(MI_WNG, C_BLU"[��� ����]",					SEND_TE_D_NR, 21);
				}
			}

			GOSSIP_MENU(700000, pCreature->GetGUID());
		}
		return true;
	}
};

// Register Script
void AddSC_Sweet_TeleportNPC()
{
	new Sweet_TeleportNPC();
}

