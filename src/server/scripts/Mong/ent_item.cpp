#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "Lyn_han.h"


class ent_item : public ItemScript
{
public:

	ent_item()
		: ItemScript("ent_item")
	{
	}
	bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& scTargets)
	{
		
		
		
		if (pPlayer->HasItemCount(pItem->GetEntry(), 1))
			pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);
		
	
		
		int item_entry = pItem->GetEntry();
		QueryResult result = WorldDatabase.PQuery("select A.slot AS slot,A.level AS level,B.spell AS spell,B.caption AS caption from (ent_item A join ent_spell B on((A.level = B.level))) where (A.entry = '%d') order by rand() limit 1", item_entry);
			
		uint32 item_slot;
		uint32 item_spell_level;
		uint32 ent_spell; 
		uint32 spell_rand = (rand()%50); //(rand()%10);
		
		Field *fields = result->Fetch();
		item_slot = fields[0].GetUInt32() ;
        item_spell_level = fields[1].GetUInt32()+6;
        ent_spell = fields[2].GetUInt32();
		const char* caption = fields[3].GetCString();

		uint32 ent_suc = 17 - item_spell_level;
		
		if(pPlayer->GetItemByPos(INVENTORY_SLOT_BAG_0,item_slot) == NULL)
		{
			SEND_NOTIFICATION(C_YLW"장비가 없습니다. 주문서가 빛나며 사라집니다.");
			return true;
		}

		
		Item* itemTarget = pPlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, item_slot);
		pPlayer->ApplyEnchantment(itemTarget, EnchantmentSlot(item_spell_level), false);  // 이전 마법부여를 지운다
		char msg[500];
		if(spell_rand < 2 && item_spell_level == 7)
			item_spell_level += 1;


		//확률 계산
		////if(spell_rand < ent_suc)
		//{
			sprintf(msg,"|cffffff00 주문서가 빛을 내며 사라집니다.  %s  마법이 부여되었습니다.",caption);
			itemTarget->SetEnchantment(EnchantmentSlot(item_spell_level), ent_spell, 0, 0);
			pPlayer->ApplyEnchantment(itemTarget, EnchantmentSlot(item_spell_level), true);   // 새로운 마법부여
			SEND_NOTIFICATION(msg);
		//}
		//else if(spell_rand < (ent_suc + 2))
		//{
		//	SEND_NOTIFICATION(C_YLW"주문서가 지글거리며 타오릅니다. 주문서 사용에 실패 햇습니다.");
		//	itemTarget->ClearEnchantment(EnchantmentSlot(item_spell_level));
		//}
		//else 
		//{
		//	itemTarget->IsBroken();
		//	//pPlayer->DestroyItem(INVENTORY_SLOT_BAG_0, item_slot, true);
		//	SEND_NOTIFICATION(C_YLW"무리한 주문을 취급하면서 장비가 손상되었습니다.");
		//}
	return true;	
	}
};

void AddSC_ent_item()
{
	new ent_item();
}
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
//
//-- 검색식
//
//select A.entry AS entry,A.slot AS slot,A.level AS level,B.spell AS spell 
//from (M1_R_C.ent_item A join M1_R_C.ent_spell B on((A.level = B.level))) 
//where (A.entry = '%d') 
//order by rand() 
//limit 1
//
//
//
//-- ----------------------------
//-- Table structure for ent_item 테이블 
//-- ----------------------------
//CREATE TABLE ent_item (
//  entry int(11) NOT NULL DEFAULT '0',
//  slot int(2) DEFAULT NULL,
//  level int(2) DEFAULT NULL,
//  PRIMARY KEY (entry)
//) DEFAULT CHARSET=utf8;
//
//-- ----------------------------
//-- Table structure for ent_spell 테이블
//-- ----------------------------
//CREATE TABLE ent_spell (
//  spell int(7) NOT NULL DEFAULT '0',
//  level int(2) DEFAULT NULL,
//  PRIMARY KEY (spell)
//) DEFAULT CHARSET=utf8;
