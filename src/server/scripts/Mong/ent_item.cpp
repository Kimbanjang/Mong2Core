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
		uint32 spell_rand = (rand()%10);
		
		Field *fields = result->Fetch();
		item_slot = fields[0].GetUInt32() ;
        item_spell_level = fields[1].GetUInt32()+6;
        ent_spell = fields[2].GetUInt32();
		const char* caption = fields[3].GetCString();

		uint32 ent_suc = 17 - item_spell_level;
		
		if(pPlayer->GetItemByPos(INVENTORY_SLOT_BAG_0,item_slot) == NULL)
		{
			SEND_NOTIFICATION(C_YLW"��� �����ϴ�. �ֹ����� ������ ������ϴ�.");
			return true;
		}
		//   // remove old enchanting before applying new if equipped
        //item_owner->ApplyEnchantment(itemTarget,PERM_ENCHANTMENT_SLOT,false);

        //itemTarget->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchant_id, 0, 0);

        //// add new enchanting if equipped
        //item_owner->ApplyEnchantment(itemTarget,PERM_ENCHANTMENT_SLOT,true);

        //itemTarget->SetSoulboundTradeable(NULL, item_owner, false);
		
		Item* itemTarget = pPlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, item_slot);
		pPlayer->ApplyEnchantment(itemTarget, EnchantmentSlot(item_spell_level), false);  // ���� �����ο��� �����
		char msg[500];
		//Ȯ�� ���
		if(spell_rand < ent_suc)
		{
			sprintf(msg,"|cffffff00 �ֹ����� ���� ���� ������ϴ�.  %s  ������ �ο��Ǿ����ϴ�.",caption);
			itemTarget->SetEnchantment(EnchantmentSlot(item_spell_level), ent_spell, 0, 0);
			pPlayer->ApplyEnchantment(itemTarget, EnchantmentSlot(item_spell_level), true);   // ���ο� �����ο�
			SEND_NOTIFICATION(msg);
		}
		else if(spell_rand < (ent_suc + 2))
		{
			SEND_NOTIFICATION(C_YLW"�ֹ����� ���۰Ÿ��� Ÿ�����ϴ�. �ֹ��� ��뿡 ���� �޽��ϴ�.");
			itemTarget->ClearEnchantment(EnchantmentSlot(item_spell_level));
		}
		else 
		{
			itemTarget->IsBroken();
			//pPlayer->DestroyItem(INVENTORY_SLOT_BAG_0, item_slot, true);
			SEND_NOTIFICATION(C_YLW"������ �ֹ��� ����ϸ鼭 ��� �ջ�Ǿ����ϴ�.");
		}
	return true;	
	}
};

void AddSC_ent_item()
{
	new ent_item();
}
/*
#define  	PROP_ENCHANTMENT_SLOT_0          7                  	// +1  ��þƮ ����
#define     PROP_ENCHANTMENT_SLOT_1          8                  	// +2
#define     PROP_ENCHANTMENT_SLOT_2          9                  	// +3
#define     PROP_ENCHANTMENT_SLOT_3          10                 	// +4
#define     PROP_ENCHANTMENT_SLOT_4          11						// +5
*/
/*
enum EquipmentSlots                                         // 19 slots
{
    EQUIPMENT_SLOT_HEAD         = 0,	�Ӹ�
    EQUIPMENT_SLOT_NECK         = 1,	�����
    EQUIPMENT_SLOT_SHOULDERS    = 2,	���
    EQUIPMENT_SLOT_BODY         = 3,	����  �ް���
    EQUIPMENT_SLOT_CHEST        = 4,  	�ӿ�  �ް��� �̰� ����������??
    EQUIPMENT_SLOT_WAIST        = 5, 	�㸮
    EQUIPMENT_SLOT_LEGS         = 6,	�ٸ�
    EQUIPMENT_SLOT_FEET         = 7,	��
    EQUIPMENT_SLOT_WRISTS       = 8,	�ո�
    EQUIPMENT_SLOT_HANDS        = 9,	�尩
    EQUIPMENT_SLOT_FINGER1      = 10,	�հ���
    EQUIPMENT_SLOT_FINGER2      = 11,	�հ���
    EQUIPMENT_SLOT_TRINKET1     = 12,	��ű�1
    EQUIPMENT_SLOT_TRINKET2     = 13,	��ű�2
    EQUIPMENT_SLOT_BACK         = 14,	��
    EQUIPMENT_SLOT_MAINHAND     = 15,	�ֹ���
    EQUIPMENT_SLOT_OFFHAND      = 16,	��������
    EQUIPMENT_SLOT_RANGED       = 17,	���Ÿ�
    EQUIPMENT_SLOT_TABARD       = 18,	�ѿ�
    EQUIPMENT_SLOT_END          = 19
};
*/
//
//-- �˻���
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
//-- Table structure for ent_item ���̺� 
//-- ----------------------------
//CREATE TABLE ent_item (
//  entry int(11) NOT NULL DEFAULT '0',
//  slot int(2) DEFAULT NULL,
//  level int(2) DEFAULT NULL,
//  PRIMARY KEY (entry)
//) DEFAULT CHARSET=utf8;
//
//-- ----------------------------
//-- Table structure for ent_spell ���̺�
//-- ----------------------------
//CREATE TABLE ent_spell (
//  spell int(7) NOT NULL DEFAULT '0',
//  level int(2) DEFAULT NULL,
//  PRIMARY KEY (spell)
//) DEFAULT CHARSET=utf8;
