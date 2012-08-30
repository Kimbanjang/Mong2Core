#ifndef Lyn_han_
#define Lyn_han_



//Han_gul Functions
#define SAY(message)	_Creature->MonsterSay( message, LANG_UNIVERSAL,NULL)
#define GOSSIP_ITEM(icon, message, iSender, iAction)	pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem( -1,icon, message, iSender, iAction, "", 0)
#define ADD_GOSSIP_ITEM(a, b, c, d)   PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, a, b, c, d, "", 0)
#define SEND_NOTIFICATION(text)				pPlayer->GetSession()->SendNotification(text)
#define GOSSIP_ITEX(icon, message, iSender, iAction, text, cost)	pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, icon, message, iSender, iAction, text, cost)

// Defined Functions
//#define GOSSIP_ITEM(icon, message, iSender, iAction)	pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(icon, message, iSender, iAction, "", 0)
//#define GOSSIP_ITEX(icon, message, iSender, iAction, text, cost)	pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(icon, message, iSender, iAction, text, cost)
#define GOSSIP_MENU(textID, objectGUID)			pPlayer->PlayerTalkClass->SendGossipMenu(textID, objectGUID)
#define GOSSIP_CLOSE()					pPlayer->PlayerTalkClass->SendCloseGossip()
#define GOSSIP_CLEAR()					pPlayer->PlayerTalkClass->ClearMenus()
#define TELEPORT_TO(mapID, posX, posY, posZ, posO) 	pPlayer->TeleportTo(mapID, posX, posY, posZ, posO)
#define PLAYER_TEAM()					pPlayer->GetTeam()

#define C_BLK "|cff000000" // Black
#define C_WHT "|cffffffff" // White
#define C_BLU "|cff00ccff" // Blue
#define C_GRN "|cff00ff00" // Green
#define C_DGR "|cff00aa00" // Dark Green
#define C_RED "|cffff0000" // Red
#define C_BRW "|cffffcc44" // Brown
#define C_YLW "|cffffff00" // Yellow
#define C_ORG "|cffff6400" // Orange
#define C_PNK "|cffff00ff" // Pink
#define C_PRL "|cff7700ff" // Purple

#endif