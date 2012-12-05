#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "Lyn_han.h"

/* ScriptData
SDName: Guild object
SDAuthor: Lyn
SD%Complete: 95%
SDComment: 오류나 조금만 손보면 됨.  
스폰 시간이없는 고정형 오브젝트의 경우는 수정해야됨 
고정형 오브젝트에 경우도 스폰타입을 입력할경우  어떻게 될지 확인요망
SDCategory: Custom
EndScriptData */

#define SPAWNTIME	5000

class guild_object : public ItemScript
{
public:

	guild_object()
		: ItemScript("mong_guild_object")
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


			 QueryResult result = WorldDatabase.PQuery("SELECT guildid FROM guild_houses WHERE area = '%d'", me->GetAreaId());
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
			}
				
		}
		return true;
	}
};
void AddSC_mong_guild_object()
{
    new guild_object();
}
/*
테이블 설계
테이블 명 : guild_houses
칼럼 : 
guid -> 아이템 번호
object_id -> 오브젝트 번호
comment -> 설명
*/
