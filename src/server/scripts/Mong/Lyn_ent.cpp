/*
*
*       mong2 - costom data
*		make & edit by Lyn
*/
#include "Lyn_han.h"
#include "ScriptPCH.h"
#include "World.h"

#define		HIENT		900004  //상위 인첸트되는몹
#define		ITEMID		999999
#define		SUCC		1
#define		FAIL		2
#define		BREAKN		3
#define		ENTCOUNT		(1+(sEnt_index-1)*(sEnt_index+2)/2)

/*
#define  	PROP_ENCHANTMENT_SLOT_0          7                  	// +1  인첸트 슬롯
#define     PROP_ENCHANTMENT_SLOT_1          8                  	// +2
#define     PROP_ENCHANTMENT_SLOT_2          9                  	// +3
#define     PROP_ENCHANTMENT_SLOT_3          10                 	// +4
#define     PROP_ENCHANTMENT_SLOT_4          11						// +5
*/
/*
enum EquipmentSlots                                         // 19 slots
{
    EQUIPMENT_SLOT_HEAD         = 0,	머리
    EQUIPMENT_SLOT_NECK         = 1,	목걸이
    EQUIPMENT_SLOT_SHOULDERS    = 2,	어깨
    EQUIPMENT_SLOT_BODY         = 3,	가슴  햇갈림
    EQUIPMENT_SLOT_CHEST        = 4,  	속옷  햇갈림 이게 가슴같은데??
    EQUIPMENT_SLOT_WAIST        = 5, 	허리
    EQUIPMENT_SLOT_LEGS         = 6,	다리
    EQUIPMENT_SLOT_FEET         = 7,	발
    EQUIPMENT_SLOT_WRISTS       = 8,	손목
    EQUIPMENT_SLOT_HANDS        = 9,	장갑
    EQUIPMENT_SLOT_FINGER1      = 10,	손가락
    EQUIPMENT_SLOT_FINGER2      = 11,	손가락
    EQUIPMENT_SLOT_TRINKET1     = 12,	장신구1
    EQUIPMENT_SLOT_TRINKET2     = 13,	장신구2
    EQUIPMENT_SLOT_BACK         = 14,	등
    EQUIPMENT_SLOT_MAINHAND     = 15,	주무기
    EQUIPMENT_SLOT_OFFHAND      = 16,	보조무기
    EQUIPMENT_SLOT_RANGED       = 17,	원거리
    EQUIPMENT_SLOT_TABARD       = 18,	겉옷
    EQUIPMENT_SLOT_END          = 19
};
*/
	EnchantmentSlot Ent_index;
	EquipmentSlots Ent_slot;
	int Ent_count=0;

	uint32 Entinfo[5][17]={
	{3395,3414,3420,1596,3440,2282,2051,3418,2130,928, 3394,1073,1950,2248,1075,3273,1894},
	{3395,3414,3420,1596,3440,2282,2051,3418,2130,928, 3394,1073,1950,2248,1075,3273,1894},
	{3395,3414,3420,1596,3440,2282,2051,3418,2130,928, 3394,1073,1950,2248,1075,3273,1894},
	{3395,3414,3420,1596,3440,2282,2051,3418,2130,928, 3394,1073,1950,2248,1075,3273,1894},
	{3395,3414,3420,1596,3440,2282,2051,3418,2130,928, 3394,1073,1950,2248,1075,3273,1894},
	};
/*
			1 "[패치워크]의 영혼 -(전투력 +12 / 체력 +9)",  + 501);
			2 "[그라불루스]의 영혼 -(주문력 +7 / 치명타 +6)",  + 502);
			3 "[글루스]의 영혼 -(숙련 +6 / 적중도 +6)",  + 503);
			4 "[타디우스]의 영혼 -(전투력 +30)",  + 504);
			5 "[아눕레칸]의 영혼 -(적중도 +6 /마나 회복량 +2)",  + 505);
			6 "[펠리나]의 영혼 -(자연 주문 공격력 +20)",  + 506);
			7 "[맥스나]의 영혼 -(원거리 전투력 +29)",  + 507);
			8 "[라주비어드]의 영혼 -(회피 숙련도 +6 / 방어 숙련도 +6)",  + 508);
			9 "[고딕]의 영혼 -(암흑 주문 공격력 +20)",  + 509);
		   10 "[4인기사단]의 영혼 -(모든 능력치 +3)",  + 510);
		   11 "[노스]의 영혼 -(주문력 +7 / 체력 +9)",  + 511);
		   12 "[헤이건]의 영혼 -(체력 +20)",  + 512);
		   13 "[로데브]의 영혼 -(방어 숙련도 +15)",  + 513);
		   14 "[사피론]의 영혼 -(냉기 주문 공격력 +26)",  + 514);
		   15 "[사피론]의 영혼 -(체력 +22)",  + 515);
		   16 "[켈투자드]의 영혼 -(혹한)",  + 516);
		   17 "[켈투자드]의 영혼 -(빙결의무기)",  + 517);
*/
class Lyn_enchant : public CreatureScript
{
	 public:

	      Lyn_enchant()
	          : CreatureScript("Lyn_enchant"){}

void ent(Player *pPlayer, Creature *_Creature, uint32 action ,EnchantmentSlot Ent_index ,EquipmentSlots Ent_slot , int Ent_count)
{
	int sEnt_index = Ent_count;	// 제련수
	int Ent_succ;
	int Ent_rand;
	char buff[2048];
	int spell_rand;

			//아이템 여부 검사
			if((pPlayer->HasItemCount(ITEMID, ENTCOUNT*100)))
			{
				if (pPlayer->GetMoney() >= abs(3000000 * ENTCOUNT))
				{
					if (pPlayer->GetHonorPoints() >= abs(5000 * ENTCOUNT))
					{
						pPlayer->ModifyMoney(-1*(3000000 * ENTCOUNT));
						pPlayer->ModifyHonorPoints(-int32(5000 * ENTCOUNT));
						pPlayer->DestroyItemCount(ITEMID, ENTCOUNT*100, true);
						Item* itemTarget = pPlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, Ent_slot);
						pPlayer->ApplyEnchantment(itemTarget, Ent_index, false);  // 이전 마법부여를 지운다

						Ent_rand=(rand()%10) + 1; //랜덤 확률
						spell_rand=(rand()%sizeof(Entinfo[sEnt_index]));
						switch(Ent_index)
						{
							case PROP_ENCHANTMENT_SLOT_0:
								Ent_succ = SUCC;
								break;
							case PROP_ENCHANTMENT_SLOT_1:
								if(Ent_rand < 8) Ent_succ = SUCC;
								else Ent_succ = FAIL;
								break;
							case PROP_ENCHANTMENT_SLOT_2:
								if(Ent_rand < 6) Ent_succ = SUCC;
								else if(Ent_rand >= 6 && Ent_rand < 10) Ent_succ = FAIL;
								else Ent_succ = BREAKN;
								break;
							case PROP_ENCHANTMENT_SLOT_3:
								if(Ent_rand < 4) Ent_succ = SUCC;
								else if(Ent_rand >= 4 && Ent_rand < 8) Ent_succ = FAIL;
								else Ent_succ = BREAKN;
								break;
							case PROP_ENCHANTMENT_SLOT_4:
								if(Ent_rand < 3) Ent_succ = SUCC;
								else if(Ent_rand >= 3 && Ent_rand < 7) Ent_succ = FAIL;
								else Ent_succ = BREAKN;
								break;
						}

						switch(Ent_succ)
						{
							case SUCC:
								itemTarget->SetEnchantment(Ent_index, Entinfo[sEnt_index][spell_rand], 0, 0);
								pPlayer->ApplyEnchantment(itemTarget, Ent_index, true);   // 새로운 마법부여
								SAY("이런 성공해버렸군! 역시 난 대단해!");
								sprintf(buff, "[ |cffffff00%s ]  |cffffffff+%u Success!!!  ",pPlayer->GetName(),sEnt_index);
								break;
							case FAIL:
								SAY("하하!! 그래 그래 실수를 할수도 있는법 아닌가?  그렇지?  다음엔 꼭 성공할걸세! ");
								sprintf(buff, "[ |cffffff00%s ] : |cffffffff+%u  Fail!!! ",pPlayer->GetName(),sEnt_index);
								break;
							case BREAKN:
								pPlayer->DestroyItem(INVENTORY_SLOT_BAG_0, Ent_slot, true);
								SAY("이런이런 이런 약한 장비를 가져오다니.  노려보지말게!! 장비가 약한것일뿐이야!  이몸이 잘못한게 아니란 말일세!");
								sprintf(buff, "[ |cffffff00%s ] :  |cffffffff+%u ITEM BROCKEN!!!",pPlayer->GetName(),sEnt_index);
								break;
						}
						sWorld->SendServerMessage(SERVER_MSG_STRING, buff);
					}
					else SEND_NOTIFICATION("명예점수가 부족합니다.");
				}
				else  SEND_NOTIFICATION("골드가 부족합니다.");
			}
			else SEND_NOTIFICATION("재료 아이템이 부족합니다.");

			pPlayer->CLOSE_GOSSIP_MENU();
}

void SendDefaultMenu_Lyn_Buffer(Player *pPlayer, Creature *_Creature, uint32 action)
{
	if (action == GOSSIP_ACTION_INFO_DEF)
	{
		GOSSIP_ITEM(0, "[ + 1 ]을 제련합니다.(300G	5000H	100개)" , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		GOSSIP_ITEM(0, "[ + 2 ]을 제련합니다.(900G	15000H	300개)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
		GOSSIP_ITEM(0, "[ + 3 ]을 제련합니다.(1800G 30000H	600개)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
		GOSSIP_ITEM(0, "[ + 4 ]을 제련합니다.(3000G 50000H	1000개)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
		GOSSIP_ITEM(0, "[ + 5 ]을 제련합니다.(4500G 75000H	1500개)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
	}
	else if (action < GOSSIP_ACTION_INFO_DEF + 10)
	{
		Ent_count = action - GOSSIP_ACTION_INFO_DEF	;
		switch(action - GOSSIP_ACTION_INFO_DEF)
		{
		case 1:
			Ent_index=PROP_ENCHANTMENT_SLOT_0;
			break;
		case 2:
			Ent_index=PROP_ENCHANTMENT_SLOT_1;
			break;
		case 3:
			Ent_index=PROP_ENCHANTMENT_SLOT_2;
			break;
		case 4:
			Ent_index=PROP_ENCHANTMENT_SLOT_3;
			break;
		case 5:
			Ent_index=PROP_ENCHANTMENT_SLOT_4;
			break;
		}

		GOSSIP_ITEM(0, "[ 주무기 ]에 영혼을 부여", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 51);
		//GOSSIP_ITEM(0, "[ 방패 ]에 영혼을 부여", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 52);
		//GOSSIP_ITEM(0, "[속옷] 에서 발견한 영혼", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 53);
		//GOSSIP_ITEM(0, "[휘장] 에서 발견한 영혼", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 54);
		//GOSSIP_ITEM(0, "[목걸이] 에서 발견한 영혼", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 55);
		//GOSSIP_ITEM(0, "[반지] 에서 발견한 영혼", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 55);
		//GOSSIP_ITEM(0, "[반지] 에서 발견한 영혼", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 55);
		//GOSSIP_ITEM(0, "[반지] 에서 발견한 영혼", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 55);
		//GOSSIP_ITEM(0, "[반지] 에서 발견한 영혼", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 55);

		GOSSIP_ITEM(7, "<-[뒤로]", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
	}
	else if (action > GOSSIP_ACTION_INFO_DEF + 50 && action < GOSSIP_ACTION_INFO_DEF + 100)
	{
		switch(action - GOSSIP_ACTION_INFO_DEF)
		{
		case 51:  //주무기
			Ent_slot=EQUIPMENT_SLOT_MAINHAND;
			break;
		case 52:  //보조무기,방패
			Ent_slot=EQUIPMENT_SLOT_OFFHAND;
			break;
		case 53:  //속옷
			Ent_slot=EQUIPMENT_SLOT_CHEST;
			break;
		case 54:  //휘장
			Ent_slot=EQUIPMENT_SLOT_TABARD;
			break;
		case 55:  //목걸이
			Ent_slot=EQUIPMENT_SLOT_NECK;

			break;
		}
		GOSSIP_ITEM(7, "<-[뒤로]", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
	}
	else ent(pPlayer, _Creature, action - GOSSIP_ACTION_INFO_DEF, Ent_index, Ent_slot , Ent_count);
}

bool OnGossipHello(Player *pPlayer, Creature *_Creature)
{
	SendDefaultMenu_Lyn_Buffer(pPlayer, _Creature, GOSSIP_ACTION_INFO_DEF);
    return true;
}

bool OnGossipSelect(Player *pPlayer, Creature *_Creature, uint32 sender, uint32 action )
{
    if (sender == GOSSIP_SENDER_MAIN) SendDefaultMenu_Lyn_Buffer(pPlayer, _Creature, action);
    return true;
}
};
void AddSC_Lyn_Etc()
{
	new Lyn_enchant;
}