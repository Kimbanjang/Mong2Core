#include "ScriptPCH.h"
#include "ScriptMgr.h"

#define	CHANGE	3707

class Lyn_change : public ItemScript
{
    public:

        Lyn_change()
            : ItemScript("Lyn_change")
        {
        }
bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& scTargets)
{
    uint32 pmodel;
	if (pPlayer->HasItemCount(pItem->GetEntry(), 1))
		pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);
	if(pItem->GetEntry()==CHANGE)
	{
		
		switch(rand()%40)
		{
			case 0:
				pmodel=28227;
				break;
			case 1:
				pmodel=28213;
				break;
			case 2:
				pmodel=28127;
				break;
			case 3:
				pmodel=20681;
				break;
			case 4:
				pmodel=23459;
				break;
			case 5:
				pmodel=8769;
				break;
			case 6:
				pmodel=31093;//22340;
				break;
			case 7:
				pmodel=2043;
				break;
			case 8:
				pmodel=80;
				break;
			case 9:
				pmodel=79;
				break;
			case 10:
				pmodel=31788;
				break;
			case 11:
				pmodel=30865;
				break;
			case 12:
				pmodel=30415;
				break;
			case 13:
				pmodel=30583;//28942;
				break;
			case 14:
				pmodel=28672;
				break;
			case 15:
				pmodel=28547;
				break;
			case 16:
				pmodel=37035;//28104;
				break;
			case 17:
				pmodel=22956;
				break;
			case 18:
				pmodel=22975;
				break;
			case 19:
				pmodel=22799;
				break;
			case 20:
				pmodel=22847;
				break;
			case 21:
				pmodel=22906;
				break;
			case 22:
				pmodel=22979;
				break;
			case 23:
				pmodel=23035;
				break;
			case 24:
				pmodel=23041;
				break;
			case 25:
				pmodel=23197;
				break;
			case 26:
				pmodel=30616;//23259;
				break;
			case 27:
				pmodel=23472;
				break;
			case 28:
				pmodel=23768;
				break;
			case 29:
				pmodel=23777;
				break;
			case 30:
				pmodel=23930;
				break;
			case 31:
				pmodel=27359;
				break;
			case 32:
				pmodel=27545;
				break;
			case 33:
				pmodel=27917;
				break;
			case 34:
				pmodel=27921;
				break;
			case 35:
				pmodel=4162;
				break;
			case 36:
				pmodel=20918;
				break;
			case 37:
				pmodel=20514;
				break;
			case 38:
				pmodel=19780;
				break;
			case 39:
				pmodel=16582;
				break;


		}		
		pPlayer->SetDisplayId(pmodel);
	
}
	return true;
}
};
void AddSC_Lyn_change()
{
    new Lyn_change();
}