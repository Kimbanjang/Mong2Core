#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "Lyn_han.h"
#include "Group.h"

/* ScriptData
SDName: MASTER_BOOK
SDAuthor: Lyn
SD%Complete: 65%
SDComment: 오류나 조금만 손보면 됨.  
스폰 시간이없는 고정형 오브젝트의 경우는 수정해야됨 
고정형 오브젝트에 경우도 스폰타입을 입력할경우  어떻게 될지 확인요망
SDCategory: Custom
EndScriptData */

#define SPAWNTIME	5000
//오브젝트 소환
class guild_object : public ItemScript
{
public:

	guild_object()
		: ItemScript("guild_object")
	{
	}
	bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& scTargets)
	{
		if (pPlayer->HasItemCount(pItem->GetEntry(), 1))
			pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);
			 uint32 object_id;
			 QueryResult result_ob = WorldDatabase.PQuery("SELECT object_id FROM guild_object WHERE guid = '%d'", pItem->GetEntry());
			 Field *fields = result_ob->Fetch();
			 object_id =  fields[0].GetUInt32();


			 QueryResult result = WorldDatabase.PQuery("SELECT guildid FROM guild_houses WHERE area = '%d'", pPlayer->GetMapId());
            if (result)
            {

					uint32 spawntm = SPAWNTIME;
				
					float x = pPlayer->GetPositionX();
					float y = pPlayer->GetPositionY();
					float z = pPlayer->GetPositionZ();
					float ang = pPlayer->GetOrientation();
				
					float rot2 = std::sin(ang/2);
					float rot3 = std::cos(ang/2);
				
					pPlayer->SummonGameObject(object_id, x, y, z, ang, 0, 0, rot2, rot3, spawntm);
					pPlayer->Say("심고 심고 가꾸고 심고!",LANG_UNIVERSAL);
			}
			else 
				pPlayer->Say("실패!",LANG_UNIVERSAL);
		return true;			
	}
};

//그룹소환
class group_summon : public ItemScript
{
public:

	group_summon()
		: ItemScript("group_summon")
	{
	}
	bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& scTargets)
	{
			
			if (pPlayer->HasItemCount(pItem->GetEntry(), 1))
			pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);

			MapEntry const* map = sMapStore.LookupEntry(pPlayer->GetMapId());
			if (!map || map->IsBattlegroundOrArena())
			{return true;}


			Group* grp = pPlayer->GetGroup();
			if (!grp){return true;}

			for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
			{
				Player* group_player = itr->getSource();

				if (!group_player || !group_player->GetSession())
					continue;

				// 비행중일경우 비행을 멈추어야함
				if (group_player->isInFlight())
				{
					group_player->GetMotionMaster()->MovementExpired();
					group_player->CleanupAfterTaxiFlight();
				}
				else
					group_player->SaveRecallPosition();

					float x = group_player->GetPositionX();
					float y = group_player->GetPositionY();
					float z = group_player->GetPositionZ();
					float ang = group_player->GetOrientation();
					//유저를 텔포 시킴
					group_player->TeleportTo(group_player->GetMapId(), x, y, z, ang);
			}
		pPlayer->Say("공간을 지배하는 자!",LANG_UNIVERSAL);
		return true;
	}
};



class instance_unbind : public ItemScript
{
public:

	instance_unbind()
		: ItemScript("instance_unbind")
	{
	}
	bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& scTargets)
	{
			
			if (pPlayer->HasItemCount(pItem->GetEntry(), 1))
			pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);

			for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
			{
				Player::BoundInstancesMap &binds = pPlayer->GetBoundInstances(Difficulty(i));
				for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
				{
					InstanceSave* save = itr->second.save;
					if (itr->first != pPlayer->GetMapId())
					{
						pPlayer->UnbindInstance(itr, Difficulty(i));
					}
					else
						++itr;
				}
			}
			pPlayer->Say("시간을 지배하는 자!",LANG_UNIVERSAL);
		return true;
	}
};

void AddSC_Mong2_Master_Book()//AddSC_Mong2_Master_Book
{
    new guild_object();
	new group_summon();
	new instance_unbind();
}
/*
테이블 설계
테이블 명 : guild_object
칼럼 : 
guid -> 아이템 번호
object_id -> 오브젝트 번호
comment -> 설명
*/
