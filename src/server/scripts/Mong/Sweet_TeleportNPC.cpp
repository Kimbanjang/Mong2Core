#include "ScriptPCH.h"
#include "Lyn_han.h"
#include "Sweet_TeleportNPC.h"
#include "InstanceSaveMgr.h"


#define GoBack C_WHT"[뒤로]"

// Teleport NPC GossipHello
class Sweet_TeleportNPC : public CreatureScript
{
public:
	Sweet_TeleportNPC() : CreatureScript("Sweet_TeleportNPC") {}
	
	bool OnGossipHello(Player * pPlayer, Creature * pCreature)
	{
		if (pPlayer->isInCombat() || pPlayer->HasInvisibilityAura() || pPlayer->HasStealthAura())
		{
			SEND_NOTIFICATION(C_YLW"당신은 전투 중입니다.");
			GOSSIP_CLOSE();
			return true;
		}
		
		
		//GOSSIP_ITEM(MI_WNG, C_BRW"[이동 하기]",		SEND_MAIN, PG_TRAVEL);
		//GOSSIP_ITEM(MI_WNG, C_DGR"[버프 받기]",		SEND_MAIN, PG_BUFF);
		GOSSIP_ITEM(MI_WL1, C_PNK"[지원 받기]",		SEND_MAIN, PG_SUPPORT);
		GOSSIP_ITEM(MI_WNG, C_BRW"[스킬 숙련]",		SEND_MAIN, PG_SKILL);
		  

		GOSSIP_MENU(700000, pCreature->GetGUID());
		return true;
	}

	// Teleport NPC GossipSelect
	bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 iSender, uint32 iAction)
	{
		if (pPlayer->isInCombat() || pPlayer->HasInvisibilityAura() || pPlayer->HasStealthAura())
		{
			SEND_NOTIFICATION(C_YLW"당신은 전투 중입니다.");
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
				GOSSIP_ITEM(MI_WNG, C_BRW"[대도시]",			SEND_TRAVEL, PG_CITY_T);
				GOSSIP_ITEM(MI_WNG, C_DGR"[마을]",			SEND_TRAVEL, PG_TOWN_T);
				//GOSSIP_ITEM(MI_WNG, C_RED"[PVP & 투기장 퀘스트 지역]",	SEND_TRAVEL, PG_PVP_T);
				GOSSIP_ITEM(MI_WNG, C_PRL"[인던 & 공격대]",		SEND_TRAVEL, PG_D_AND_R);
			}

			if (iAction == PG_BUFF)		// Buff Page
			{
 		               GOSSIP_ITEM(MI_BOK, C_BLU"[버프 6종(10+) - 10 골드]",	SEND_BUFF, 0);
					  /* if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
 						GOSSIP_ITEM(MI_BOK, C_PRL"[GM 버프 6종(60+) - 60 골드]",	SEND_BUFF, 1);*/
			}

			if (iAction == PG_SUPPORT)		// Support Page
			{
				GOSSIP_ITEM(MI_WL1, C_GRN"[특성 초기화 - 무료!]",			SEND_SUPPORT, 0);
				GOSSIP_ITEM(MI_WNG, C_PRL"[세계 탐험 - 100 골드]",	SEND_SUPPORT, 1);
				GOSSIP_ITEM(MI_WNG, C_ORG"[부활 후유증 제거 - 10 골드]",	SEND_SUPPORT, 2);
			}
			if (iAction == PG_SKILL)		//skil Page
			{
				GOSSIP_ITEM(MI_WNG, "[대장 - 600 골드]",	SEND_SKILL, 164);				
				GOSSIP_ITEM(MI_WNG, "[가세 - 600 골드]",	SEND_SKILL, 165);
				GOSSIP_ITEM(MI_WNG, "[연금 - 600 골드]",	SEND_SKILL, 171);
				GOSSIP_ITEM(MI_WNG, "[약초 - 600 골드]",	SEND_SKILL, 182);
				GOSSIP_ITEM(MI_WNG, "[채광 - 600 골드]",	SEND_SKILL, 186);
				GOSSIP_ITEM(MI_WNG, "[재봉 - 600 골드]",	SEND_SKILL, 197);
				GOSSIP_ITEM(MI_WNG, "[기계 - 600 골드]",	SEND_SKILL, 202);
				GOSSIP_ITEM(MI_WNG, "[마부 - 600 골드]",	SEND_SKILL, 333);
				GOSSIP_ITEM(MI_WNG, "[무두 - 600 골드]",	SEND_SKILL, 393);
				GOSSIP_ITEM(MI_WNG, "[보세 - 600 골드]",	SEND_SKILL, 755);
				GOSSIP_ITEM(MI_WNG, "[주각 - 600 골드]",	SEND_SKILL, 773);

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
				//	SEND_NOTIFICATION(C_RED"골드가 부족합니다.");
				//}
				//else
				//{
				//	pPlayer->SetMoney(money - 6000000);
					pPlayer->SetSkill(iAction,pPlayer->GetSkillStep(iAction), 400, 450);
				//}
			}
			else
			{
				SEND_NOTIFICATION(C_RED"아직 배우지 못한 스킬입니다.");
			}
		}
		// Buff
		if (iSender == SEND_BUFF)
		{
			switch (iAction)
			{
			case 0:		// 버프
				{
					if ( pPlayer->getLevel() >= 10 )
					{
						uint32 money = pPlayer->GetMoney();
						if (money < 100000)
						{
							SEND_NOTIFICATION(C_RED"골드가 부족합니다.");
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
							
							SEND_NOTIFICATION(C_YLW"버프가 완료되었습니다.");
						}
					}
					else
						SEND_NOTIFICATION(C_RED"레벨이 낮습니다.");
				}
				break;
            		case 1:		// GM 버프
				{
					if ( pPlayer->getLevel() >= 60 )
					{
						uint32 money = pPlayer->GetMoney();
						if (money < 600000)
						{
							SEND_NOTIFICATION(C_RED"골드가 부족합니다.");
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
							
							SEND_NOTIFICATION(C_YLW"버프가 완료되었습니다.");
						}
					}
					else
						SEND_NOTIFICATION(C_RED"레벨이 낮습니다.");
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
			case 0:		// Repair Items //특성초기화
				{			
					pPlayer->resetTalents(true);
					pPlayer->SendTalentsInfoData(false);
					SEND_NOTIFICATION(C_YLW"특성이 초기화 되었습니다.");
				}
				break;

			case 1:		// Explore World
				{
					uint32 money = pPlayer->GetMoney();
					if (money < 1000000)
					{
						SEND_NOTIFICATION(C_RED"골드가 부족합니다.");
					}
					else
					{
						pPlayer->SetMoney(money - 1000000);

						for (uint8 i = 0; i < 128; i++)
							pPlayer->SetFlag(PLAYER_EXPLORED_ZONES_1+i, 0xFFFFFFFF);

						SEND_NOTIFICATION(C_YLW"모든 지도가 열렸습니다.");
					}
				}
				break;

			case 2:		// 부활 후유증 제거
				{
					uint32 money = pPlayer->GetMoney();
					if (money < 100000)
					{
						SEND_NOTIFICATION(C_RED"골드가 부족합니다.");
					}
					else
					{
						pPlayer->SetMoney(money - 100000);
						pPlayer->learnSpell(DEATHSICK, false);
						pPlayer->removeSpell(DEATHSICK);
						SEND_NOTIFICATION(C_YLW"부활 후유증이 제거되었습니다.");
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
							GOSSIP_ITEM(MI_WNG, C_ORG"[오그리마]",	SEND_TE_CITY, 0);
							GOSSIP_ITEM(MI_WNG, C_ORG"[언더시티]",	SEND_TE_CITY, 1);
							GOSSIP_ITEM(MI_WNG, C_ORG"[썬더 블러프]",	SEND_TE_CITY, 2);
							GOSSIP_ITEM(MI_WNG, C_ORG"[실버문]",	SEND_TE_CITY, 3);
						}
						if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
						{
							GOSSIP_ITEM(MI_WNG, C_ORG"[스톰윈드]",	SEND_TE_CITY, 4);
							GOSSIP_ITEM(MI_WNG, C_ORG"[아이언포지]",	SEND_TE_CITY, 5);
							GOSSIP_ITEM(MI_WNG, C_ORG"[다르나서스]",	SEND_TE_CITY, 6);
							GOSSIP_ITEM(MI_WNG, C_ORG"[엑소다르]",	SEND_TE_CITY, 7);
						}

						GOSSIP_ITEM(MI_WNG, C_YLW"[샤트라스]",		SEND_TE_CITY, 8);
						GOSSIP_ITEM(MI_WNG, C_BLU"[달라란]",		SEND_TE_CITY, 9);
					}
					break;
		
				case PG_TOWN_T:			// Town Travel Menu
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[아제로스]",		SEND_TRAVEL, PG_AZ_T);
						GOSSIP_ITEM(MI_WNG, C_DGR"[아웃랜드]",		SEND_TRAVEL, PG_OL_T);
						GOSSIP_ITEM(MI_WNG, C_BLU"[노스렌드]",		SEND_TRAVEL, PG_NR_T);
					}
					break;

				case PG_PVP_T:			// PvP Travel Menu
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[구루바시 투기장]",SEND_TE_PVP, PLAYER_TEAM() == HORDE ? 0 : 9);
						GOSSIP_ITEM(MI_WNG, C_ORG"[혈투의 전장]",SEND_TE_PVP, PLAYER_TEAM() == HORDE ? 1 : 10);

						if (PLAYER_TEAM() == HORDE)
						{
							GOSSIP_ITEM(MI_WNG, C_ORG"[스톰윈드 침공]",	SEND_TE_PVP, 2);
							GOSSIP_ITEM(MI_WNG, C_ORG"[아이언포지 침공]",		SEND_TE_PVP, 3);
							GOSSIP_ITEM(MI_WNG, C_ORG"[다르나서스 침공]",		SEND_TE_PVP, 4);
							GOSSIP_ITEM(MI_WNG, C_ORG"[엑소다르 침공]",		SEND_TE_PVP, 5);
						}
						if (PLAYER_TEAM() == ALLIANCE)
						{
							GOSSIP_ITEM(MI_WNG, C_ORG"[오그리마 침공]",		SEND_TE_PVP, 11);
							GOSSIP_ITEM(MI_WNG, C_ORG"[언더시티 침공]",		SEND_TE_PVP, 12);
							GOSSIP_ITEM(MI_WNG, C_ORG"[썬더 블러프 침공]",	SEND_TE_PVP, 13);
							GOSSIP_ITEM(MI_WNG, C_ORG"[실버문 침공]",	SEND_TE_PVP, 14);
						}
						
						GOSSIP_ITEM(MI_WNG, C_DGR"[나그란드: 피의 투기장 65+]",	SEND_TE_PVP, PLAYER_TEAM() == HORDE ? 6 : 15);
						GOSSIP_ITEM(MI_WNG, C_DGR"[줄드락: 고뇌의 투기장 75+]",	SEND_TE_PVP, PLAYER_TEAM() == HORDE ? 7 : 16);
						GOSSIP_ITEM(MI_WNG, C_BLU"[겨울손아귀 호수]",	SEND_TE_PVP, PLAYER_TEAM() == HORDE ? 8 : 17);
					}
					break;

				case PG_D_AND_R:		// Dungeons And Raids Menu
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[아제로스 인던]",	SEND_TRAVEL, PG_AZ_D_P1);
						GOSSIP_ITEM(MI_WNG, C_ORG"[아제로스 공격대]",	SEND_TRAVEL, PG_AZ_R);
						GOSSIP_ITEM(MI_WNG, C_DGR"[아웃랜드 인던]",	SEND_TRAVEL, PG_OL_D_P1);
						GOSSIP_ITEM(MI_WNG, C_DGR"[아웃랜드 공격대]",	SEND_TRAVEL, PG_OL_R);
						GOSSIP_ITEM(MI_WNG, C_BLU"[노스렌드 인던]",	SEND_TRAVEL, PG_NR_D_P1);
						GOSSIP_ITEM(MI_WNG, C_BLU"[노스렌드 공격대]",	SEND_TRAVEL, PG_NR_R);
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
						GOSSIP_ITEM(MI_WNG, C_ORG"[호드 마을]",	SEND_TRAVEL, PG_AZ_F_P1);
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_ORG"[얼라이언스 마을]",SEND_TRAVEL, PG_AZ_F_P1);

					GOSSIP_ITEM(MI_WNG, C_ORG"[중립 마을]",		SEND_TRAVEL, PG_AZ_N);
				}

				if (iAction == PG_OL_T)
				{
					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_DGR"[호드 마을]",	SEND_TRAVEL, PG_OL_F);
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_DGR"[얼라이언스 마을]",SEND_TRAVEL, PG_OL_F);

					GOSSIP_ITEM(MI_WNG, C_DGR"[중립 마을]",		SEND_TRAVEL, PG_OL_N);
				}

				if (iAction == PG_NR_T)
				{
					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_BLU"[호드 마을]",	SEND_TRAVEL, PG_NR_F_P1);
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
						GOSSIP_ITEM(MI_WNG, C_BLU"[얼라이언스 마을]",SEND_TRAVEL, PG_NR_F_P1);

					GOSSIP_ITEM(MI_WNG, C_BLU"[중립 마을]",		SEND_TRAVEL, PG_NR_N_P1);
				}
			}

			// Pages accessed via Azeroth Town Travel Menu
			if (iAction == PG_AZ_F_P1 || iAction == PG_AZ_F_P2 || iAction == PG_AZ_N)
			{
				GOSSIP_CLEAR();
				GOSSIP_ITEM(MI_CHT, GoBack,	SEND_TRAVEL, PG_AZ_T);

				if (iAction == PG_AZ_F_P1)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"[다음 페이지] -->",		SEND_TRAVEL, PG_AZ_F_P2);

					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[피멍울 초소]",			SEND_TE_T_AZ, 0);
						GOSSIP_ITEM(MI_WNG, C_ORG"[담쟁이 마을]",			SEND_TE_T_AZ, 1);
						GOSSIP_ITEM(MI_WNG, C_ORG"[페랄라스: 모자케 야영지]",		SEND_TE_T_AZ, 2);
						GOSSIP_ITEM(MI_WNG, C_ORG"[불모의 땅: 타우라조 야영지]",		SEND_TE_T_AZ, 3);
						GOSSIP_ITEM(MI_WNG, C_ORG"[화염 마루]",				SEND_TE_T_AZ, 4);
						GOSSIP_ITEM(MI_WNG, C_ORG"[버섯구름 봉우리: 높새바람 봉우리]",	SEND_TE_T_AZ, 5);
						GOSSIP_ITEM(MI_WNG, C_ORG"[가시덤불 골짜기: 그롬골 주둔지]",	SEND_TE_T_AZ, 6);
						GOSSIP_ITEM(MI_WNG, C_ORG"[아라시 고원: 해머폴]",			SEND_TE_T_AZ, 7);
						GOSSIP_ITEM(MI_WNG, C_ORG"[황야의 땅: 카르가스]",			SEND_TE_T_AZ, 8);
						GOSSIP_ITEM(MI_WNG, C_ORG"[동부 내륙지: 레반터스크 마을]",		SEND_TE_T_AZ, 9);
						GOSSIP_ITEM(MI_WNG, C_ORG"[잊혀진 땅: 그늘수렵 마을]",		SEND_TE_T_AZ, 10);
						GOSSIP_ITEM(MI_WNG, C_ORG"[잿빛 골짜기: 토막나무 주둔지]",		SEND_TE_T_AZ, 11);
						GOSSIP_ITEM(MI_WNG, C_ORG"[슬픔의 늪: 스토나드]",			SEND_TE_T_AZ, 12);
					}
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[동부내륙지: 맹금의 봉우리]",		SEND_TE_T_AZ, 20);
						GOSSIP_ITEM(MI_WNG, C_ORG"[잿빛골짜기: 아스트라나르]",		SEND_TE_T_AZ, 21);
						GOSSIP_ITEM(MI_WNG, C_ORG"[어둠의 해안: 아우버다인]",		SEND_TE_T_AZ, 22);
						GOSSIP_ITEM(MI_WNG, C_ORG"[핏빛안개 섬: 핏빛 감시초소]",		SEND_TE_T_AZ, 23);
						GOSSIP_ITEM(MI_WNG, C_ORG"[서리바람 야영지]",			SEND_TE_T_AZ, 24);
						GOSSIP_ITEM(MI_WNG, C_ORG"[그늘 숲: 다크샤이어]",			SEND_TE_T_AZ, 25);
						GOSSIP_ITEM(MI_WNG, C_ORG"[페랄라스: 페더문 요새]",		SEND_TE_T_AZ, 26);
						GOSSIP_ITEM(MI_WNG, C_ORG"[붉은마루 산맥: 레이크샤이어]",		SEND_TE_T_AZ, 27);
						GOSSIP_ITEM(MI_WNG, C_ORG"[저습지: 메네실 항구]",			SEND_TE_T_AZ, 28);
						GOSSIP_ITEM(MI_WNG, C_ORG"[저주받은 땅: 네더가드 요새]",			SEND_TE_T_AZ, 29);
						GOSSIP_ITEM(MI_WNG, C_ORG"[잊혀진 땅: 나이젤의 야영지]",		SEND_TE_T_AZ, 30);
						GOSSIP_ITEM(MI_WNG, C_ORG"[반란군 야영지]",			SEND_TE_T_AZ, 31);
						GOSSIP_ITEM(MI_WNG, C_ORG"[임시 주둔지]",			SEND_TE_T_AZ, 32);
					}
				}

				if (iAction == PG_AZ_F_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [이전 페이지]",		SEND_TRAVEL, PG_AZ_F_P1);

					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[돌발톱 산맥: 해바위 야영지]",		SEND_TE_T_AZ, 13);
						GOSSIP_ITEM(MI_WNG, C_ORG"[힐스브래드 구릉지: 타렌 밀농장]",	SEND_TE_T_AZ, 14);
						GOSSIP_ITEM(MI_WNG, C_ORG"[불모의 땅: 크로스로드]",		SEND_TE_T_AZ, 15);
						GOSSIP_ITEM(MI_WNG, C_ORG"[은빛소나무 숲: 공동묘지]",		SEND_TE_T_AZ, 16);
						GOSSIP_ITEM(MI_WNG, C_ORG"[유령의 땅: 트랜퀼리엔]",		SEND_TE_T_AZ, 17);
						GOSSIP_ITEM(MI_WNG, C_ORG"[아즈샤라: 발로르모크]",			SEND_TE_T_AZ, 18);
						GOSSIP_ITEM(MI_WNG, C_ORG"[잿빛 골짜기: 조람가르 전초기지]",	SEND_TE_T_AZ, 19);
					}
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_ORG"[서부 몰락지대: 감시의 언덕]",		SEND_TE_T_AZ, 33);
						GOSSIP_ITEM(MI_WNG, C_ORG"[힐스브래드 구릉지: 사우스쇼어]",		SEND_TE_T_AZ, 34);
						GOSSIP_ITEM(MI_WNG, C_ORG"[돌발톱 산맥: 돌발톱 봉우리]",		SEND_TE_T_AZ, 35);
						GOSSIP_ITEM(MI_WNG, C_ORG"[갈퀴가지 숲]",			SEND_TE_T_AZ, 36);
						GOSSIP_ITEM(MI_WNG, C_ORG"[탈렌드리스 초소]",			SEND_TE_T_AZ, 37);
						GOSSIP_ITEM(MI_WNG, C_ORG"[탈라나르]",				SEND_TE_T_AZ, 38);
						GOSSIP_ITEM(MI_WNG, C_ORG"[모단 호수: 텔사마]",			SEND_TE_T_AZ, 39);
						GOSSIP_ITEM(MI_WNG, C_ORG"[먼지진흙 습지대: 테라모아 섬]",		SEND_TE_T_AZ, 40);
					}
				}

				if (iAction == PG_AZ_N)
				{
					GOSSIP_ITEM(MI_WNG, C_ORG"[가시덤불 골짜기: 무법항]",			SEND_TE_T_AZ, 41);
					GOSSIP_ITEM(MI_WNG, C_ORG"[실리더스: 세나리온 요새]",			SEND_TE_T_AZ, 42);
					GOSSIP_ITEM(MI_WNG, C_ORG"[에메랄드 성소]",				SEND_TE_T_AZ, 43);
					GOSSIP_ITEM(MI_WNG, C_ORG"[여명의 설원: 눈망루 마을]",			SEND_TE_T_AZ, 44);
					GOSSIP_ITEM(MI_WNG, C_ORG"[타나리스: 가젯잔]",				SEND_TE_T_AZ, 45);
					GOSSIP_ITEM(MI_WNG, C_ORG"[쿠엘다나스 섬]",				SEND_TE_T_AZ, 46);
					GOSSIP_ITEM(MI_WNG, C_ORG"[동부 역병지대: 희망의 빛 예배당]",		SEND_TE_T_AZ, 47);
					GOSSIP_ITEM(MI_WNG, C_ORG"[마샬의 야영지]",				SEND_TE_T_AZ, 48);
					GOSSIP_ITEM(MI_WNG, C_ORG"[달의 숲]",					SEND_TE_T_AZ, 49);
					GOSSIP_ITEM(MI_WNG, C_ORG"[진흙톱니 거점]",				SEND_TE_T_AZ, 50);
					GOSSIP_ITEM(MI_WNG, C_ORG"[불모의 땅: 톱니항]",				SEND_TE_T_AZ, 51);
					GOSSIP_ITEM(MI_WNG, C_ORG"[토륨 조합 거점]",				SEND_TE_T_AZ, 52);
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
						GOSSIP_ITEM(MI_WNG, C_DGR"[지옥불 반도: 매의 감시탑]",		SEND_TE_T_OL, 0);
						GOSSIP_ITEM(MI_WNG, C_DGR"[나그란드: 가라다르]",			SEND_TE_T_OL, 1);
						GOSSIP_ITEM(MI_WNG, C_DGR"[칼날 산맥: 모크나탈 마을]",		SEND_TE_T_OL, 2);
						GOSSIP_ITEM(MI_WNG, C_DGR"[어둠달 골짜기: 어둠달 마을]",		SEND_TE_T_OL, 3);
						GOSSIP_ITEM(MI_WNG, C_DGR"[지옥불 반도: 해골망치 초소]",		SEND_TE_T_OL, 4);
						GOSSIP_ITEM(MI_WNG, C_DGR"[테로카르 숲: 돌망치 요새]",		SEND_TE_T_OL, 5);	
						GOSSIP_ITEM(MI_WNG, C_DGR"[장가르 습지대: 늪쥐 감시초소]",		SEND_TE_T_OL, 6);
						GOSSIP_ITEM(MI_WNG, C_DGR"[지옥불 반도: 스랄마]",			SEND_TE_T_OL, 7);
						GOSSIP_ITEM(MI_WNG, C_DGR"[칼날 산맥: 천둥군주 요새]",		SEND_TE_T_OL, 8);
						GOSSIP_ITEM(MI_WNG, C_DGR"[장가르 습지대: 자브라진]",		SEND_TE_T_OL, 9);
					}
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_DGR"[알레리아 성채]",			SEND_TE_T_OL, 10);
						GOSSIP_ITEM(MI_WNG, C_DGR"[명예의 요새]",			SEND_TE_T_OL, 11);
						GOSSIP_ITEM(MI_WNG, C_DGR"[오레보르 피난처]",			SEND_TE_T_OL, 12);
						GOSSIP_ITEM(MI_WNG, C_DGR"[징검다리 거점]",			SEND_TE_T_OL, 13);
						GOSSIP_ITEM(MI_WNG, C_DGR"[실바나르]",				SEND_TE_T_OL, 14);
						GOSSIP_ITEM(MI_WNG, C_DGR"[텔라아르]",				SEND_TE_T_OL, 15);
						GOSSIP_ITEM(MI_WNG, C_DGR"[텔레도르]",				SEND_TE_T_OL, 16);
						GOSSIP_ITEM(MI_WNG, C_DGR"[텔하마트 사원]",			SEND_TE_T_OL, 17);
						GOSSIP_ITEM(MI_WNG, C_DGR"[토쉴리의 연구기지]",			SEND_TE_T_OL, 18);
						GOSSIP_ITEM(MI_WNG, C_DGR"[와일드해머 성채]",			SEND_TE_T_OL, 19);
					}
				}

				if (iAction == PG_OL_N)
				{
					GOSSIP_ITEM(MI_WNG, C_DGR"[샤타르 제단]",				SEND_TE_T_OL, 20);
					GOSSIP_ITEM(MI_WNG, C_DGR"[52 구역]",					SEND_TE_T_OL, 21);
					GOSSIP_ITEM(MI_WNG, C_DGR"[검은바람 비행기지]",				SEND_TE_T_OL, 22);
					GOSSIP_ITEM(MI_WNG, C_DGR"[세나리온 야영지]",				SEND_TE_T_OL, 23);
					GOSSIP_ITEM(MI_WNG, C_DGR"[코스모렌치]",					SEND_TE_T_OL, 24);
					GOSSIP_ITEM(MI_WNG, C_DGR"[영원의 숲]",					SEND_TE_T_OL, 25);
					GOSSIP_ITEM(MI_WNG, C_DGR"[오그릴라]",					SEND_TE_T_OL, 26);
					GOSSIP_ITEM(MI_WNG, C_DGR"[별의 성소]",					SEND_TE_T_OL, 27);
					GOSSIP_ITEM(MI_WNG, C_DGR"[폭풍 첨탑]",					SEND_TE_T_OL, 28);
					GOSSIP_ITEM(MI_WNG, C_DGR"[운명의 계단]",				SEND_TE_T_OL, 29);
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
						GOSSIP_ITEM(MI_CHD, C_BLK"[다음 페이지] -->",	SEND_TRAVEL, PG_NR_F_P2);

						GOSSIP_ITEM(MI_WNG, C_BLU"[울부짖는 협만: 연금술사 야영지(Lv69~71)]",	SEND_TE_T_NR, 1);
						GOSSIP_ITEM(MI_WNG, C_BLU"[울부짖는 협만: 겨울발굽 야영지(Lv69~71)]",	SEND_TE_T_NR, 5);
						GOSSIP_ITEM(MI_WNG, C_BLU"[울부짖는 협만: 신 아가만드(Lv69~71)]",		SEND_TE_T_NR, 10);
						GOSSIP_ITEM(MI_WNG, C_BLU"[울부짖는 협만: 복수의 상륙지(Lv69~71)]",		SEND_TE_T_NR, 13);
						GOSSIP_ITEM(MI_WNG, C_BLU"[북풍의 땅: 보르고로크 전초기지(Lv69~72)]",	SEND_TE_T_NR, 2);
						GOSSIP_ITEM(MI_WNG, C_BLU"[북풍의 땅: 타운카르 마을(Lv69~72)]",		SEND_TE_T_NR, 12);
						GOSSIP_ITEM(MI_WNG, C_BLU"[북풍의 땅: 전쟁노래부족 요새(Lv69~72)]",		SEND_TE_T_NR, 15);
						GOSSIP_ITEM(MI_WNG, C_BLU"[용의 안식처: 아그마르의 망치(Lv72~75)]",		SEND_TE_T_NR, 0);
						GOSSIP_ITEM(MI_WNG, C_BLU"[용의 안식처: 코르크론 선봉기지(Lv72~75)]",	SEND_TE_T_NR, 9);
						GOSSIP_ITEM(MI_WNG, C_BLU"[용의 안식처: 원한의 초소(Lv72~75)]",		SEND_TE_T_NR, 14);
						GOSSIP_ITEM(MI_WNG, C_BLU"[회색 구릉지: 원크와 야영지(Lv73~75)]",		SEND_TE_T_NR, 3);
						GOSSIP_ITEM(MI_WNG, C_BLU"[회색 구릉지: 정복의 요새(Lv73~75)]",		SEND_TE_T_NR, 6);
						GOSSIP_ITEM(MI_WNG, C_BLU"[줄드락: 두브라진(Lv74~77)]",			SEND_TE_T_NR, 7);
					}
					if (PLAYER_TEAM() == ALLIANCE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_BLU"[울부짖는 협만: 빌더바르 요새(Lv69~71)]",		SEND_TE_T_NR, 19);
						GOSSIP_ITEM(MI_WNG, C_BLU"[울부짖는 협만: 발가드(Lv69~71)]",		SEND_TE_T_NR, 22);
						GOSSIP_ITEM(MI_WNG, C_BLU"[울부짖는 협만: 서부경비대 성채(Lv69~71)]",	SEND_TE_T_NR, 25);
						GOSSIP_ITEM(MI_WNG, C_BLU"[북풍의 땅: 피즈크랭크 비행장(Lv69~72)]",		SEND_TE_T_NR, 17);
						GOSSIP_ITEM(MI_WNG, C_BLU"[북풍의 땅: 용맹의 성채(Lv69~72)]",		SEND_TE_T_NR, 23);
						GOSSIP_ITEM(MI_WNG, C_BLU"[용의 안식처: 폴드라곤 요새(Lv72~75)]",		SEND_TE_T_NR, 18);
						GOSSIP_ITEM(MI_WNG, C_BLU"[용의 안식처: 별의 쉼터(Lv72~75)]",		SEND_TE_T_NR, 21);
						GOSSIP_ITEM(MI_WNG, C_BLU"[용의 안식처: 윈터가드 성채(Lv72~75)]",		SEND_TE_T_NR, 27);
						GOSSIP_ITEM(MI_WNG, C_BLU"[회색 구릉지: 호박빛소나무 오두막(Lv73~75)]",	SEND_TE_T_NR, 16);
						GOSSIP_ITEM(MI_WNG, C_BLU"[회색 구릉지: 서부 몰락지대 여단 야영지(Lv73~75)]",	SEND_TE_T_NR, 24);
						GOSSIP_ITEM(MI_WNG, C_BLU"[퐁풍우 봉우리: 서리요새(Lv78~80)]",		SEND_TE_T_NR, 20);
						GOSSIP_ITEM(MI_WNG, C_BLU"[수정노래 숲: 윈드러너 전망대]",			SEND_TE_T_NR, 26);
					}
				}

				if (iAction == PG_NR_F_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [이전 페이지]",		SEND_TRAVEL, PG_NR_F_P1);

					if (PLAYER_TEAM() == HORDE || pPlayer->isGameMaster() )
					{
						GOSSIP_ITEM(MI_WNG, C_BLU"[폭풍우 봉우리: 그롬아쉬 추락 지점(Lv78~80)]",	SEND_TE_T_NR, 8);
						GOSSIP_ITEM(MI_WNG, C_BLU"[폭풍우 봉우리: 툰카로 야영지(Lv78~80)]",		SEND_TE_T_NR, 4);
						GOSSIP_ITEM(MI_WNG, C_BLU"[수정노래 숲: 선리버 지휘초소]",			SEND_TE_T_NR, 11);
					}
					if (PLAYER_TEAM() == ALLIANCE)
					{
					}
				}

				if (iAction == PG_NR_N_P1)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"[다음 페이지] -->",		SEND_TRAVEL, PG_NR_N_P2);

					GOSSIP_ITEM(MI_WNG, C_BLU"[울부짖는 협만: 카마구아(Lv69~71)]",			SEND_TE_T_NR, 36);
					GOSSIP_ITEM(MI_WNG, C_BLU"[북풍의 땅: 호박석 절벽(Lv69~72)]",			SEND_TE_T_NR, 28);
					GOSSIP_ITEM(MI_WNG, C_BLU"[북풍의 땅: 변위의 보호막(Lv69~72)]",			SEND_TE_T_NR, 44);
					GOSSIP_ITEM(MI_WNG, C_BLU"[북풍의 땅: 우누페(Lv69~72)]",				SEND_TE_T_NR, 45);
					GOSSIP_ITEM(MI_WNG, C_BLU"[용의 안식처: 모아키 항구(Lv72~75)]",			SEND_TE_T_NR, 39);
					GOSSIP_ITEM(MI_WNG, C_BLU"[용의 안식처: 고룡쉼터 사원(Lv72~75)]",			SEND_TE_T_NR, 46);
					GOSSIP_ITEM(MI_WNG, C_BLU"[줄드락: 빛의 틈(Lv74~77)]",				SEND_TE_T_NR, 38);
					GOSSIP_ITEM(MI_WNG, C_BLU"[줄드락: 칠흑의 감시초소(Lv74~77)]",			SEND_TE_T_NR, 34);
					GOSSIP_ITEM(MI_WNG, C_BLU"[줄드락: 은빛십자군 격전지(Lv74~77)]",			SEND_TE_T_NR, 41);
					GOSSIP_ITEM(MI_WNG, C_BLU"[줄드락: 짐토르가(Lv74~77)]",				SEND_TE_T_NR, 47);
					GOSSIP_ITEM(MI_WNG, C_BLU"[숄라자르 분지: 호반의 착륙장(Lv75~78)]",			SEND_TE_T_NR, 37);
					GOSSIP_ITEM(MI_WNG, C_BLU"[숄라자르 분지: 네싱워리 주둔지(Lv75~78)]",		SEND_TE_T_NR, 40);
					GOSSIP_ITEM(MI_WNG, C_BLU"[폭풍우 봉우리: 던 니펠렘(Lv78~80)]",			SEND_TE_T_NR, 33);
				}

				if (iAction == PG_NR_N_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [이전 페이지]",		SEND_TRAVEL, PG_NR_N_P1);

					GOSSIP_ITEM(MI_WNG, C_BLU"[폭풍우 봉우리: K3(Lv78~80)]",				SEND_TE_T_NR, 35);
					GOSSIP_ITEM(MI_WNG, C_BLU"[폭풍우 봉우리: 바울더크랙의 은거처(Lv78~80)]",		SEND_TE_T_NR, 30);
					GOSSIP_ITEM(MI_WNG, C_BLU"[얼음왕관: 은빛십자군 선봉기지(Lv78~80)]",		SEND_TE_T_NR, 42);
					GOSSIP_ITEM(MI_WNG, C_BLU"[얼음왕관: 어둠의 무기고(Lv78~80)]",			SEND_TE_T_NR, 43);
					GOSSIP_ITEM(MI_WNG, C_BLU"[얼음왕관: 은빛십자군 마상시합 광장(Lv78~80)]",		SEND_TE_T_NR, 29);
					GOSSIP_ITEM(MI_WNG, C_BLU"[얼음왕관: 십자군 봉우리(Lv78~80)]",			SEND_TE_T_NR, 31);
					GOSSIP_ITEM(MI_WNG, C_BLU"[얼음왕관: 죽음의 마루(Lv78~80)]",			SEND_TE_T_NR, 32);
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
					GOSSIP_ITEM(MI_CHD, C_BLK"[다음 페이지] -->",		SEND_TRAVEL, PG_AZ_D_P2);

					GOSSIP_ITEM(MI_WNG, C_ORG"[죽음의 폐광(Lv15~28)]",		SEND_TE_D_AZ, 13);
					GOSSIP_ITEM(MI_WNG, C_ORG"[통곡의 동굴(Lv15~28)]",		SEND_TE_D_AZ, 15);
					GOSSIP_ITEM(MI_WNG, C_ORG"[그림자송곳니 성채(Lv18~32)]",		SEND_TE_D_AZ, 10);
					GOSSIP_ITEM(MI_WNG, C_ORG"[검은심연의 나락(Lv20~35)]",		SEND_TE_D_AZ, 0);
					GOSSIP_ITEM(MI_WNG, C_ORG"[가시덩굴 우리(Lv24~40)]",		SEND_TE_D_AZ, 7);	
					GOSSIP_ITEM(MI_WNG, C_ORG"[놈리건(Lv24~40)]",			SEND_TE_D_AZ, 4);
					GOSSIP_ITEM(MI_WNG, C_ORG"[붉은십자군 수도원(Lv29~45)]",		SEND_TE_D_AZ, 8);
					GOSSIP_ITEM(MI_WNG, C_ORG"[울다만(Lv32~52)]",			SEND_TE_D_AZ, 14);
					GOSSIP_ITEM(MI_WNG, C_ORG"[가시덩굴 구릉(Lv33~47)]",		SEND_TE_D_AZ, 6);  
					GOSSIP_ITEM(MI_WNG, C_ORG"[마라우돈(Lv40~58)]",			SEND_TE_D_AZ, 5);
					GOSSIP_ITEM(MI_WNG, C_ORG"[줄파락(Lv43~54)]",			SEND_TE_D_AZ, 16);
					GOSSIP_ITEM(MI_WNG, C_ORG"[아탈학카르 신전(Lv50~55)]",		SEND_TE_D_AZ, 12);
					GOSSIP_ITEM(MI_WNG, C_ORG"[스트라솔름(Lv56~61)]",		SEND_TE_D_AZ, 11);
				}

				if (iAction == PG_AZ_D_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [이전 페이지]",		SEND_TRAVEL, PG_AZ_D_P1);

					GOSSIP_ITEM(MI_WNG, C_ORG"[검은바위 첨탑하층(Lv58~60)]",		SEND_TE_D_AZ, 1);
					GOSSIP_ITEM(MI_WNG, C_ORG"[검은바위 첨탑상층(Lv59~62)]",		SEND_TE_D_AZ, 2);
					GOSSIP_ITEM(MI_WNG, C_ORG"[혈투의 전장(Lv54~61)]",		SEND_TE_D_AZ, 3);
					GOSSIP_ITEM(MI_WNG, C_ORG"[스칼로맨스(Lv56~61)]",		SEND_TE_D_AZ, 9);
				}

				if (iAction == PG_AZ_R)
				{
					GOSSIP_ITEM(MI_WNG, C_ORG"[검은날개 둥지(40인)]",			SEND_TE_D_AZ, 17);
					GOSSIP_ITEM(MI_WNG, C_ORG"[화산심장부(40인)]",			SEND_TE_D_AZ, 18);
					GOSSIP_ITEM(MI_WNG, C_ORG"[안퀴라즈 폐허(20인)]",			SEND_TE_D_AZ, 19);
					GOSSIP_ITEM(MI_WNG, C_ORG"[안퀴라즈 사원(40인)]",			SEND_TE_D_AZ, 20);
					GOSSIP_ITEM(MI_WNG, C_ORG"[줄구룹(20인)]",			SEND_TE_D_AZ, 21);
				}

				if (iAction == PG_OL_D_P1)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"[다음 페이지] -->",		SEND_TRAVEL, PG_OL_D_P2);

					GOSSIP_ITEM(MI_WNG, C_DGR"[지옥불 성채: 지옥불 성루(Lv60~62)]",		SEND_TE_D_OL, 9);
					GOSSIP_ITEM(MI_WNG, C_DGR"[지옥불 성채: 피의 용광로(Lv61~63)]",		SEND_TE_D_OL, 10);
					GOSSIP_ITEM(MI_WNG, C_DGR"[갈퀴송곳니 저수지: 강제 노역소(Lv62~64)]",	SEND_TE_D_OL, 6);
					GOSSIP_ITEM(MI_WNG, C_DGR"[갈퀴송곳니 저수지: 지하수렁(Lv63~65)]",		SEND_TE_D_OL, 8);
					GOSSIP_ITEM(MI_WNG, C_DGR"[아킨돈: 마나 무덤(Lv64~66)]",			SEND_TE_D_OL, 1);
					GOSSIP_ITEM(MI_WNG, C_DGR"[시간의 동굴: 옛 힐스브래드 구릉지(Lv65~68)]",	SEND_TE_D_OL, 4);
					GOSSIP_ITEM(MI_WNG, C_DGR"[아킨돈: 아키나이 납골당(Lv65~67)]",		SEND_TE_D_OL, 0);
					GOSSIP_ITEM(MI_WNG, C_DGR"[아킨돈: 세테크 전당(Lv67~69)]",			SEND_TE_D_OL, 2);
					GOSSIP_ITEM(MI_WNG, C_DGR"[아킨돈: 어둠의 미궁(Lv70+)]",			SEND_TE_D_OL, 3);
					GOSSIP_ITEM(MI_WNG, C_DGR"[시간의 동굴: 검은 늪(Lv70+)]",			SEND_TE_D_OL, 5);
					GOSSIP_ITEM(MI_WNG, C_DGR"[갈퀴송곳니 저수지: 증기 저장고(Lv70+)]",		SEND_TE_D_OL, 7);
					GOSSIP_ITEM(MI_WNG, C_DGR"[지옥불 성채: 으스러진 손의 전당(Lv70+)]",	SEND_TE_D_OL, 11);
					GOSSIP_ITEM(MI_WNG, C_DGR"[마법학자의 정원(Lv70+)]",			SEND_TE_D_OL, 12);
				}

				if (iAction == PG_OL_D_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [이전 페이지]",		SEND_TRAVEL, PG_OL_D_P1);

					GOSSIP_ITEM(MI_WNG, C_DGR"[폭풍우 요새: 알카트라즈(Lv70+)]",	SEND_TE_D_OL, 13);
					GOSSIP_ITEM(MI_WNG, C_DGR"[폭풍우 요새: 신록의 정원(Lv70+)]",	SEND_TE_D_OL, 14);
					GOSSIP_ITEM(MI_WNG, C_DGR"[폭풍우 요새: 메카나르(Lv70+)]",		SEND_TE_D_OL, 15);
				}

				if (iAction == PG_OL_R)
				{	
					GOSSIP_ITEM(MI_WNG, C_DGR"[카라잔]",				SEND_TE_D_OL, 20);
					GOSSIP_ITEM(MI_WNG, C_DGR"[줄아만]",				SEND_TE_D_OL, 24);
					GOSSIP_ITEM(MI_WNG, C_DGR"[지옥불 성채: 마그테리돈의 둥지]",	SEND_TE_D_OL, 19);
					GOSSIP_ITEM(MI_WNG, C_DGR"[그룰의 둥지]",			SEND_TE_D_OL, 18);
					GOSSIP_ITEM(MI_WNG, C_DGR"[불뱀 제단]",				SEND_TE_D_OL, 21);
					GOSSIP_ITEM(MI_WNG, C_DGR"[폭풍우 요새: 폭풍우 요새]",		SEND_TE_D_OL, 23);
					GOSSIP_ITEM(MI_WNG, C_DGR"[시간의 동굴: 하이잘 산의 전투]",		SEND_TE_D_OL, 17);
					GOSSIP_ITEM(MI_WNG, C_DGR"[검은 사원]",				SEND_TE_D_OL, 16);
					GOSSIP_ITEM(MI_WNG, C_DGR"[태양샘 고원]",			SEND_TE_D_OL, 22);
				}
				
				if (iAction == PG_NR_D_P1)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"[다음 페이지] -->",		SEND_TRAVEL, PG_NR_D_P2);

					GOSSIP_ITEM(MI_WNG, C_BLU"[마력의 탑: 마력의 탑(Lv70~72)]",		SEND_TE_D_NR, 8);
					GOSSIP_ITEM(MI_WNG, C_BLU"[우트가드 성채: 우트가드 성채(Lv70~72)]",		SEND_TE_D_NR, 14);
					GOSSIP_ITEM(MI_WNG, C_BLU"[아졸네룹: 아졸네룹(Lv72~74)]",			SEND_TE_D_NR, 1);
					GOSSIP_ITEM(MI_WNG, C_BLU"[안카헤트: 고대 왕국(Lv74~76)]",			SEND_TE_D_NR, 0);
					GOSSIP_ITEM(MI_WNG, C_BLU"[드락타론 성채(Lv74~76)]",			SEND_TE_D_NR, 3);
					GOSSIP_ITEM(MI_WNG, C_BLU"[보랏빛 요새(Lv75~77)]",			SEND_TE_D_NR, 10);
					GOSSIP_ITEM(MI_WNG, C_BLU"[군드락(Lv76~78)]",				SEND_TE_D_NR, 4);
					GOSSIP_ITEM(MI_WNG, C_BLU"[울두아르: 돌의 전당(Lv77~79)]",			SEND_TE_D_NR, 13);
					GOSSIP_ITEM(MI_WNG, C_BLU"[우트가드 성채: 우트가드 첨탑(Lv80+)]",		SEND_TE_D_NR, 15);
					GOSSIP_ITEM(MI_WNG, C_BLU"[시간의 동굴: 옛 스트라솔름(Lv80+)]",		SEND_TE_D_NR, 2);
					GOSSIP_ITEM(MI_WNG, C_BLU"[마력의 탑: 마력의 눈(Lv80+)]",			SEND_TE_D_NR, 9);
					GOSSIP_ITEM(MI_WNG, C_BLU"[울두아르: 번개의 전당(Lv80+)]",			SEND_TE_D_NR, 12);
					GOSSIP_ITEM(MI_WNG, C_BLU"[용사의 시험장(Lv80+)]",			SEND_TE_D_NR, 11);
				}

				if (iAction == PG_NR_D_P2)
				{
					GOSSIP_ITEM(MI_CHD, C_BLK"<-- [이전 페이지]",		SEND_TRAVEL, PG_NR_D_P1);

					GOSSIP_ITEM(MI_WNG, C_BLU"[얼음왕관 성채: 투영의 전당(Lv80+)]",		SEND_TE_D_NR, 5);
					GOSSIP_ITEM(MI_WNG, C_BLU"[얼음왕관 성채: 사론의 구덩이(Lv80+)]",		SEND_TE_D_NR, 6);
					GOSSIP_ITEM(MI_WNG, C_BLU"[얼음왕관 성채: 영혼의 제련소(Lv80+)]",		SEND_TE_D_NR, 7);
				}

				if (iAction == PG_NR_R)
				{
					GOSSIP_ITEM(MI_WNG, C_BLU"[아카본 석실]",				SEND_TE_D_NR, 24);
					GOSSIP_ITEM(MI_WNG, C_BLU"[흑요석 성소]",				SEND_TE_D_NR, 20);
					GOSSIP_ITEM(MI_WNG, C_BLU"[영원의 눈]",					SEND_TE_D_NR, 19);
					GOSSIP_ITEM(MI_WNG, C_BLU"[낙스라마스]",					SEND_TE_D_NR, 17);
					GOSSIP_ITEM(MI_WNG, C_BLU"[울두아르]",					SEND_TE_D_NR, 23);
					GOSSIP_ITEM(MI_WNG, C_BLU"[십자군의 시험장]",				SEND_TE_D_NR, 22);
					GOSSIP_ITEM(MI_WNG, C_BLU"[오닉시아의 둥지]",				SEND_TE_D_NR, 18);
					GOSSIP_ITEM(MI_WNG, C_BLU"[얼음왕관 성채]",				SEND_TE_D_NR, 16);
					GOSSIP_ITEM(MI_WNG, C_BLU"[루비 성소]",					SEND_TE_D_NR, 21);
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

