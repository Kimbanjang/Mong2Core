#ifndef Teleport_Book_h__
#define Teleport_Book_h__

#define DEATHSICK 15007

// Gossip Menu Icons
enum MenuIcon
{
	MI_CHT,	// White Chat Bubble
	MI_BAG,	// Brown Bag
	MI_WNG,	// Flight Wing 1
	MI_BOK,	// Book
	MI_WL1,	// Interaction Wheel 1
	MI_WL2,	// Interaction Wheel 2
	MI_CBG,	// Brown Bag With Yellow Dot
	MI_CHD,	// White Chat Bubble With Black Dots
	MI_TBD,	// Tabard
	MI_PVP,	// Two Swords
	MI_YDT,	// Flight Wing 2
};

// Page Senders
enum PageSender
{
//  ================================================================================
	SEND_MAIN,		// Pages accessed via Main Menu
//  ================================================================================
	SEND_TRAVEL,	// Travel Pages
//  ================================================================================
	SEND_TE_CITY,	// City Teleport
	SEND_TE_T_AZ,	// Azeroth Town Teleport
	SEND_TE_T_OL,	// Outland Town Teleport
	SEND_TE_T_NR,	// Northrend Town Teleport
	SEND_TE_D_AZ,	// Azeroth Dungeons Teleport
	SEND_TE_D_OL,	// Outland Dungeons Teleport
	SEND_TE_D_NR,	// Northrend Dungeons Teleport
	SEND_TE_PVP,	// PvP Teleport
	SEND_TE_VEND,	// Vendors Teleport
//  ================================================================================
	SEND_TRAIN,		// Trainers
//  ================================================================================
	SEND_SUPPORT,	// Character Support
//  ================================================================================
	SEND_BUFF,	// Buff Support
//  ================================================================================
	SEND_SKILL,  //SKILL SET
};

// Menu Pages
enum MenuPage
{
//  ================================================================================
	PG_MAIN,		// Main Page
//  ================================================================================
	PG_TRAVEL,		// Travel Page
	PG_CITY_T,		// City Travel
//  ================================================================================
	PG_TOWN_T,		// Town Travel
	PG_AZ_T,		// Azeroth Town Travel
	PG_AZ_F_P1,		// Azeroth Faction Towns Page 1
	PG_AZ_F_P2,
	PG_AZ_N,		// Azeroth Neutral Towns
	PG_OL_T,		// Outland Town Travel
	PG_OL_F,		// Outland Faction Towns Page
	PG_OL_N,		// Outland Neutral Towns Page
	PG_NR_T,		// Northrend Town Travel
	PG_NR_F_P1,		// Northrend Faction Towns Page 1
	PG_NR_F_P2,
	PG_NR_N_P1,		// Northrend Neutral Towns Page 1
	PG_NR_N_P2,
//  ================================================================================
	PG_PVP_T,		// PvP Travel
//  ================================================================================
	PG_D_AND_R,		// Dungeons And Raids
	PG_AZ_D_P1,		// Azeroth Dungeons Page 1
	PG_AZ_D_P2,
	PG_AZ_R,		// Azeroth Raids
	PG_OL_D_P1,		// Outland Dungeons Page 1
	PG_OL_D_P2,
	PG_OL_R,		// Outland Raids
	PG_NR_D_P1,		// Northrend Dungeons Page 1
	PG_NR_D_P2,
	PG_NR_R,		// Northrend Raids
//  ================================================================================
	PG_TRAIN,		// Trainers Page
//  ================================================================================	
	PG_SUPPORT,		// Support Page
//  ================================================================================
	PG_BUFF,		// Buff Page
//  ================================================================================
	PG_SKILL,		//skill Page
};

uint32 spellsMageTeleH[12] =
{
	3567,	// Teleport: Orgrimmar
	3563,	// Teleport: Undercity
	3566,	// Teleport: Thunder Bluff
	32272,	// Teleport: Silvermoon
	35715,	// Teleport: Shattrath
	49358,	// Teleport: Stonard
	11417,	// Portal: Orgrimmar
	11419,	// Portal: Undercity
	11420,	// Portal: Thunder Bluff
	32267,	// Portal: Silvermoon
	35717,	// Portal: Shattrath
	49361,	// Portal: Stonard
};

uint32 spellsMageTeleA[12] =
{
	3561,	// Teleport: Stormwind
	3562,	// Teleport: Ironforge
	3565,	// Teleport: Darnassus
	32271,	// Teleport: Exodar
	33690,	// Teleport: Shattrath
	49359,	// Teleport: Theramore
	10059,	// Portal: Stormwind
	11416,	// Portal: Ironforge
	11419,	// Portal: Darnassus
	32266,	// Portal: Exodar
	33691,	// Portal: Shattrath
	49360,	// Portal: Theramore
};

// Teleport Location Structure
struct TeleportLocation
{
	uint32 map; // Map ID
	float posx; // Position X
	float posy; // Position Y
	float posz; // Position Z
	float poso; // Orientation
};

// Location Coords
TeleportLocation travelCity[10] =
{	// Horde Cities
	{1, 1632.662231f, -4413.200684f, 17.030209f, 3.120389f},		// 0 -> Orgrimmar
	{0, 1585.783447f, 240.439087f, -52.150272f, 0.007850f},			// 1 -> Undercity
	{1, -1264.661865f, 73.349838f, 127.677025f, 0.329856f},			// 2 -> Thunder Bluff
	{530, 9508.231445f, -7345.596680f, 14.360150f, 1.551162f},		// 3 -> Silvermoon City

	// Alliance Cities
	{0, -8814.460938f, 626.122681f, 94.114937f, 3.894350f},			// 4 -> Stormwind City
	{0, -4804.738770f, -1100.723877f, 498.807159f, 5.406187f},		// 5 -> Ironforge
	{1, 9950.087891f, 2347.237549f, 1330.758057f, 1.584090f},		// 6 -> Darnassus
	{530, -3946.729980f, -11621.686523f, -138.633072f, 2.183399f},	// 7 -> Exodar

	// Neutral Cities
	{530, -1854.133179f, 5410.975586f, -12.427743f, 2.041195f},		// 8 -> Shattrath
	{571, 5804.227539f, 639.307373f, 647.772644f, 0.901726f},		// 9 -> Dalaran
};

TeleportLocation townAZ[53] =
{
	// Horde Azeroth Towns Page 1
	{1, 5115.787598f, -322.434601f, 360.003876f, 4.220192f},		// 0 -> Bloodvenom Post [H]
	{1, -3117.037842f, -2851.928223f, 34.803963f, 4.234085f},		// 1 -> Brackenwall Village [H]
	{1, -4397.621582f, 231.320084f, 25.413435f, 4.917230f},			// 2 -> Camp Mojache [H]
	{1, -2345.170898f, -1943.232178f, 95.794983f, 2.180264f},		// 3 -> Camp Taurajo [H]
	{0, -7494.805664f, -2179.294678f, 165.574097f, 4.033412f},		// 4 -> Flame Crest [H]
	{1, -5437.656738f, -2442.284424f, 89.791351f, 2.282196f},		// 5 -> Freewind Post [H]
	{0, -12387.884766f, 165.770477f, 2.638800f, 0.991557f},			// 6 -> Grom'gol Base Camp [H]
	{0, -973.954041f, -3502.033203f, 56.072098f, 3.870734f},		// 7 -> Hammerfall [H]
	{0, -6672.360840f, -2179.734619f, 244.030624f, 0.958919f},		// 8 -> Kargath [H]
	{0, -562.174072f, -4570.381348f, 9.480235f, 4.292376f},			// 9 -> Revantusk Village [H]
	{1, -1660.034546f, 3099.331787f, 30.501087f, 6.165372f},		// 10 -> Shadowprey Village [H]
	{1, 2317.618652f, -2537.828857f, 100.350426f, 0.192421f},		// 11 -> Splintertree Post [H]
	{0, -10435.561523f, -3261.821777f, 20.178511f, 3.675270f},		// 12 -> Stonard [H]

	// Horde Azeroth Towns Page 2
	{1, 937.948547f, 913.984253f, 104.303925f, 3.216220f},			// 13 -> Sun Rock Retreat [H]
	{0, -33.283699f, -925.621216f, 54.479855f, 5.893157f},			// 14 -> Tarren Mill [H]
	{1, -454.829498f, -2649.234131f, 95.458107f, 1.045365f},		// 15 -> The Crossroads [H]
	{0, 494.366394f, 1588.068237f, 125.807602f, 0.019155f},			// 16 -> The Sepulcher [H]
	{530, 7580.661621f, -6824.590332f, 86.497955f, 3.929347f},		// 17 -> Tranquillien [H]
	{1, 3607.778076f, -4413.986328f, 113.193169f, 0.032453f},		// 18 -> Valormok [H]
	{1, 3362.253662f, 1005.475891f, 4.037580f, 3.173028f},			// 19 -> Zoram'gar Outpost [H]

	// Alliance Azeroth Towns Page 1
	{0, 271.798920f, -2023.874634f, 183.717545f, 0.852342f},		// 20 -> Aerie Peak [A]
	{1, 2719.501709f, -382.812653f, 107.093414f, 0.816828f},		// 21 -> Astranaar [A]
	{1, 6436.053711f, 487.692902f, 7.103769f, 3.061721f},			// 22 -> Auberdine [A]
	{530, -1935.006958f, -11879.564453f, 47.243168f, 3.173790f},	// 23 -> Blood Watch [A]
	{0, 962.139526f, -1422.584839f, 65.701469f, 4.024701f},			// 24 -> Chillwind Camp [A]
	{0, -10559.495117f, -1187.759155f, 28.076004f, 0.077349f},		// 25 -> Darkshire [A]
	{1, -4434.876465f, 3276.780762f, 11.768742f, 6.226482f},		// 26 -> Feathermoon Stronghold [A]
	{0, -9270.224609f, -2185.923584f, 64.089615f, 4.697079f},		// 27 -> Lakeshire [A]
	{0, -3771.432373f, -738.995850f, 8.043953f, 5.284135f},			// 28 -> Menethil Harbor [A]
	{0, -10999.792969f, -3382.262939f, 62.229103f, 4.803109f},		// 29 -> Nethergarde Keep [A]
	{1, 109.832245f, 1230.028198f, 161.944870f, 0.251321f},			// 30 -> Nijel's Point [A]
	{0, -11300.810547f, -203.065659f, 75.751396f, 2.944065f},		// 31 -> Rebel Camp [A]
	{0, -1252.380615f, -2522.547363f, 20.454514f, 2.044679f},		// 32 -> Refuge Point [A]

	// Alliance Azeroth Towns Page 2
	{0, -10628.781250f, 1125.899414f, 33.771633f, 1.838210f},		// 33 -> Sentinel Hill [A]
	{0, -858.021484f, -532.966858f, 9.418888f, 0.510019f},			// 34 -> Southshore [A]
	{1, 2670.812012f, 1476.801392f, 231.392807f, 0.695094f},		// 35 -> Stonetalon Peak [A]
	{1, 6155.673340f, -1925.045044f, 571.808105f, 5.095133f},		// 36 -> Talonbranch Glade [A]
	{1, 2703.418457f, -3864.342285f, 104.250511f, 5.456950f},		// 37 -> Talrendis Point [A]
	{1, -4499.418945f, -787.039490f, -41.953720f, 1.693160f},		// 38 -> Thalanaar [A]
	{0, -5350.871094f, -2960.459961f, 323.738434f, 1.815788f},		// 39 -> Thelsamar [A]
	{1, -3669.153320f, -4412.997070f, 10.739157f, 3.160446f},		// 40 -> Theramore Isle [A]
	
	// Neutral Azeroth Towns Page
	{0, -14429.058594f, 452.362396f, 15.400412f, 3.756942f},		// 41 -> Booty Bay
	{1, -6810.153320f, 804.515259f, 51.437672f, 1.935840f},			// 42 -> Cenarion Hold
	{1, 3984.009766f, -1292.649414f, 248.879318f, 0.045786f},		// 43 -> Emerald Sanctuary
	{1, 6722.945801f, -4651.246094f, 720.887695f, 5.045636f},		// 44 -> Everlook
	{1, -7156.736328f, -3824.199219f, 8.549184f, 6.074884f},		// 45 -> Gadgetzan
	{530, 12751.221680f, -6925.507324f, 12.237798f, 2.324980f},		// 46 -> Isle Of Quel'Danas
	{0, 2279.451904f, -5283.249023f, 82.509171f, 4.678797f},		// 47 -> Light's Hope Chapel
	{1, -6170.298828f, -1095.421509f, -211.411240f, 0.200110f},		// 48 -> Marshal's Refuge
	{1, 7963.570313f, -2492.025879f, 487.822876f, 3.261999f},		// 49 -> Moonglade
	{1, -4584.047363f, -3174.054443f, 34.161263f, 3.093698f},		// 50 -> Mudsprocket
	{1, -956.662292f, -3755.033447f, 5.335715f, 1.032013f},			// 51 -> Ratchet
	{0, -6499.305664f, -1138.711182f, 306.968018f, 3.396796f},		// 52 -> Thorium Point
};

TeleportLocation townOL[30] =
{
	// Horde Outland Towns Page
	{530, -617.505859f, 4089.817139f,  91.500542f, 0.989180f},		// 0 -> Falcon Watch [H]
	{530, -1317.980835f, 7212.696289f,  33.870823f, 2.460215f},		// 1 -> Garadar [H]
	{530, 2189.993652f, 4766.689941f,  155.749741f, 5.380417f},		// 2 -> Mok'Nathal Village [H]
	{530, -3004.976563f, 2568.329590f,  76.956612f, 0.911352f},		// 3 -> Shadowmoon Village [H]
	{530, -1325.462402f, 2365.636719f, 88.954033f, 1.105421f},		// 4 -> Spinebreaker Post [H]
	{530, -2619.541504f, 4391.600098f,  34.068291f, 2.718553f},		// 5 -> Stonebreaker Hold [H]
	{530, 94.802635f, 5196.393555f,  20.951540f, 0.173930f},		// 6 -> Swamprat Post [H]
	{530, 143.267487f, 2673.445557f, 85.670822f, 5.852374f},		// 7 -> Thrallmar [H]
	{530, 2290.301514f, 6038.186035f,  142.401627f, 5.778629f},		// 8 -> Thunderlord Stronghold [H]
	{530, 248.813843f, 7856.596680f,  24.263754f, 0.013702f},		// 9 -> Zabra'jin [H]

	// Alliance Outland Towns Page
	{530, -2942.166748f, 3966.378174f,  -0.598505f, 1.593858f},		// 10 -> Allerian Stronghold [A]
	{530, -718.752991f, 2675.316406f, 95.209076f, 5.495013f},		// 11 -> Honor Hold [A]
	{530, 1009.664063f, 7368.451172f,  36.306358f, 2.609444f},		// 12 -> Orebor Harborage [A]
	{530, 263.657654f, 1472.287842f, -17.175808f, 5.805249f},		// 13 -> Shatter Point [A]
	{530, 2061.958740f, 6851.607910f,  172.588699f, 4.732471f},		// 14 -> Sylvanaar [A]
	{530, -2558.829346f, 7297.593262f,  14.139544f, 4.311391f},		// 15 -> Telaar [A]
	{530, 290.537689f, 6070.129395f,  130.265793f, 4.134689f},		// 16 -> Telredor [A]
	{530, 143.646118f, 4332.554199f,  106.336487f, 0.019208f},		// 17 -> Temple Of Telhamat [A]
	{530, 1912.115479f, 5566.871582f,  262.747223f, 5.143607f},		// 18 -> Toshley's Station [A]
	{530, -3969.906494f, 2192.205322f,  101.744431f, 3.687734f},	// 19 -> Wildhammer Stronghold [A]

	// Neutral Outland Towns Page
	{530, -3050.631592f, 824.821289f,  -10.513947f, 5.695379f},		// 20 -> Altar Of Sha'tar
	{530, 3056.253906f, 3669.949219f,  142.394669f, 3.164400f},		// 21 -> Area 52
	{530, -3386.980957f, 3595.523682f,  275.959381f, 1.485478f},	// 22 -> Blackwind Landing
	{530, -225.646637f, 5477.283203f,  21.680319f, 1.546806f},		// 23 -> Cenarion Refuge
	{530, 2963.659180f, 1787.588379f,  139.120956f, 0.662909f},		// 24 -> Cosmowrench
	{530, 2990.534180f, 5480.605469f,  143.698044f, 5.337229f},		// 25 -> Evergrove
	{530, 2296.692383f, 7281.697754f,  365.852570f, 0.562009f},		// 26 -> Ogri'la
	{530, -4086.411377f, 1112.296753f,  41.480618f, 1.945098f},		// 27 -> Sanctum Of The Stars
	{530, 4122.599121f, 2976.634521f,  351.270477f, 5.241774f},		// 28 -> Stormspire
	{530, -248.712006f, 956.944824f, 84.357864f, 1.599432f},		// 29 -> The Stair Of Destiny
};

TeleportLocation townNR[48] =
{
	// Horde Northrend Towns Page 1
	{571, 3841.800781f, 1544.532471f, 89.724785f, 4.724355f},		// 0 -> Agmar's Hammer [H]
	{571, 2114.129639f, -2980.377197f, 148.551147f, 0.072746f},		// 1 -> Apothecary Camp [H]
	{571, 4481.708496f, 5738.009277f, 79.290619f, 5.835969f},		// 2 -> Bor'gorok Outpost [H]
	{571, 3853.823975f, -4517.291504f, 209.401154f, 4.395287f},		// 3 -> Camp Oneqwah [H]
	{571, 7790.713379f, -2831.383301f, 1218.397095f, 2.225008f},	// 4 -> Camp Taunka'lo [H]
	{571, 2693.925537f, -4356.290527f, 279.361816f, 2.695976f},		// 5 -> Camp Winterhoof [H]
	{571, 3249.944092f, -2269.770020f, 114.240486f, 4.714098f},		// 6 -> Conquest Hold [H]
	{571, 6902.164551f, -4108.562500f, 467.353973f, 5.798779f},		// 7 -> Dubra'Jin [H]
	{571, 7867.363770f, -742.431641f, 1176.560181f, 3.638720f},		// 8 -> Grom'arsh Crash-Site [H]
	{571, 4944.132813f, 1222.468506f, 225.258179f, 1.769688f},		// 9 -> Kor'kron Vanguard [H]
	{571, 410.871796f, -4573.613770f, 244.506866f, 0.811793f},		// 10 -> New Agamand [H]
	{571, 5606.213867f, -697.194458f, 206.625351f, 2.136462f},		// 11 -> Sunreaver's Command [H]
	{571, 3441.392822f, 4104.409668f, 15.990473f, 0.873810f},		// 12 -> Taunka'le Village [H]

	// Horde Northrend Towns Page 2
	{571, 1943.239624f, -6166.621582f, 23.735603f, 2.358242f},		// 13 -> Vengeance Landing [H]
	{571, 3240.108398f, -692.830872f, 166.898804f, 4.725160f},		// 14 -> Venomspite [H]
	{571, 2827.234863f, 6176.347656f, 121.981499f, 0.751180f},		// 15 -> Warsong Hold [H]

	// Alliance Northrend Towns Page 1
	{571, 3448.321777f, -2760.153809f, 199.368820f, 4.700748f},		// 16 -> Amberpine Lodge [A]
	{571, 4137.858887f, 5269.710449f, 24.728651f, 0.948434f},		// 17 -> Fizzcrank Airstrip [A]
	{571, 4586.966309f, 1439.437744f, 189.228745f, 4.738503f},		// 18 -> Fordragon Hold [A]
	{571, 2427.430908f, -5123.509766f, 276.350525f, 0.398682f},		// 19 -> Fort Wildervar [A]
	{571, 6675.778809f, -231.200317f, 945.471741f, 5.613211f},		// 20 -> Frosthold [A]
	{571, 3513.436768f, 2006.026611f, 65.182350f, 3.682129f},		// 21 -> Stars' Rest [A]
	{571, 618.158752f, -4988.689941f, 3.964351f, 4.675948f},		// 22 -> Valguarde [A]
	{571, 2257.555908f, 5201.790527f, 11.315316f, 5.945026f},		// 23 -> Valiance Keep [A]
	{571, 4537.835938f, -4210.440430f, 170.801392f, 4.759708f},		// 24 -> Westfall Brigade Encampment [A]
	{571, 1392.368408f, -3256.562988f, 161.525650f, 0.489005f},		// 25 -> Westguard Keep [A]
	{571, 5063.699219f, -578.600403f, 219.971176f, 1.589828f},		// 26 -> Windrunner's Overlook [A]
	{571, 3684.132080f, -724.333130f, 212.719788f, 1.167303f},		// 27 -> Wintergarde Keep [A]

	// Neutral Northrend Towns Page 1
	{571, 3612.910889f, 5971.108887f, 136.214813f, 3.477412f},		// 28 -> Amber Ledge
	{571, 8651.575195f, 792.033936f, 547.693176f, 3.178035f},		// 29 -> Argent Tournament Grounds
	{571, 8457.391602f, -320.950043f, 906.719971f, 3.993721f},		// 30 -> Bouldercrag's Refuge
	{571, 6417.428223f, 445.478729f, 511.282104f, 3.363219f},		// 31 -> Crusaders' Pinnacle
	{571, 7448.230957f, 4187.925781f, 314.092834f, 3.198284f},		// 32 -> Death's Rise
	{571, 7287.883789f, -2650.123291f, 814.924988f, 4.743750f},		// 33 -> Din Niffelem
	{571, 5222.459473f, -1322.732544f, 242.022476f, 2.441990f},		// 34 -> Ebon Watch
	{571, 6122.322754f, -1060.918701f, 402.580872f, 4.744549f},		// 35 -> K3
	{571, 771.004944f, -2938.717773f, 7.328056f, 1.577557f},		// 36 -> Kamagua
	{571, 5483.040527f, 4746.956543f, -196.739868f, 6.243582f},		// 37 -> Lakeside Landing
	{571, 5165.309082f, -2201.917969f, 236.538437f, 6.264513f},		// 38 -> Light's Breach
	{571, 2774.332764f, 872.073730f, 5.154878f, 2.017494f},			// 39 -> Moa'ki Harbor
	{571, 5555.523438f, 5751.262695f, -77.180382f, 6.062961f},		// 40 -> Nesingwary Base Camp
  
	// Neutral Northrend Towns Page 2
	{571, 5450.289063f, -2629.246582f, 306.253296f, 1.579617f},		// 41 -> The Argent Strand
	{571, 6191.019043f, 42.912907f, 380.097595f, 4.722127f},		// 42 -> The Argent Vanguard
	{571, 8453.691406f, 2695.318359f, 656.586548f, 2.747474f},		// 43 -> The Shadow Vault
	{571, 3584.850342f, 6664.337402f, 195.239182f, 3.998149f},		// 44 -> Transitus Shield
	{571, 2923.657959f, 4063.423584f, 1.449907f, 4.459840f},		// 45 -> Unu'pe
	{571, 3545.090332f, 292.714203f, 45.648422f, 4.813128f},		// 46 -> Wyrmrest Temple
	{571, 5784.288086f, -3570.130859f, 386.494934f, 3.178689f},		// 47 -> Zim'Torga
};

TeleportLocation dungAZ[22] =
{
	// Azeroth Dungeons Page 1
	{1, 4246.175293f, 736.848511f, -26.228987f, 1.277788f},			// 0 -> Blackfathom Deeps
	{0, -7180.362793f, -917.782837f, 165.490616f, 4.945970f},		// 1 -> Blackrock Depths
	{0, -7527.285156f, -1225.060181f, 285.731995f, 5.249139f},		// 2 -> Blackrock Spire
	{1, -3544.522949f, 1124.450806f, 161.027359f, 0.023531f},		// 3 -> Dire Maul
	{0, -5163.263184f, 922.161804f, 257.177948f, 1.507965f},		// 4 -> Gnomeregan
	{1, -1464.774658f, 2616.750732f, 76.913940f, 3.130310f},		// 5 -> Maraudon
	{1, -4657.692871f, -2524.980957f, 81.322029f, 4.222143f},		// 6 -> Razorfen Downs
	{1, -4465.589844f, -1667.068481f, 81.891060f, 0.895985f},		// 7 -> Razorfen Kraul
	{0, 2892.416260f, -810.978027f, 160.332932f, 5.094393f},		// 8 -> Scarlet Monastery
	{0, 1267.309937f, -2556.878662f, 94.126869f, 0.498888f},		// 9 -> Scholomance
	{0, -235.255478f, 1561.217896f, 76.892097f, 1.197113f},			// 10 -> Shadowfang Keep
	{0, 3359.748291f, -3379.437988f, 144.781509f, 6.279408f},		// 11 -> Stratholme
	{0, -10184.213867f, -3993.077637f, -109.194939f, 6.032234f},	// 12 -> Sunken Temple

	// Azeroth Dungeons Page 2
	{0, -11208.371094f, 1671.760376f, 24.676750f, 1.569575f},		// 13 -> The Deadmines
	{0, -6071.292480f, -2955.544922f, 209.780411f, 0.074613f},		// 14 -> Uldaman
	{1, -738.908813f, -2219.407715f, 16.909426f, 2.588510f},		// 15 -> Wailing Caverns
	{1, -6800.479004f, -2890.937500f, 8.882550f, 0.023800f},		// 16 -> Zul'Farrak

	// Azeroth Raids
	{469, -7665.430664f, -1102.359619f, 399.679260f, 0.620886f},	// 17 -> Blackwing Lair
	{0, -7509.605957f, -1037.547241f, 180.911942f, 2.252842f},		// 18 -> Molten Core
	{1, -8412.381836f, 1502.331787f, 29.518759f, 2.702592f},		// 19 -> Ruins Of Ahn'Qiraj
	{1, -8239.101563f, 1991.822754f, 129.071838f, 0.955076f},		// 20 -> Temple Of Ahn'Qiraj
	{0, -11916.207031f, -1207.825684f, 92.288231f, 4.711202f},		// 21 -> Zul'Gurub
};

TeleportLocation dungOL[25] =
{
	// Outland Dungeons Page 1
	{530, -3362.021973f, 5211.709961f, -101.048912f, 1.583664f},	// 0 -> Auchindoun: Auchenai Crypts
	{530, -3087.771484f, 4943.162598f, -101.047478f, 0.000299f},	// 1 -> Auchindoun: Mana Tombs
	{530, -3361.980957f, 4675.402832f, -101.049065f, 4.717567f},	// 2 -> Auchindoun: Sethekk Halls
	{530, -3629.630859f, 4942.966309f, -101.048233f, 3.145816f},	// 3 -> Auchindoun: Shadow Labyrinth
	{1, -8361.020508f, -4057.474365f, -208.198288f, 0.142076f},		// 4 -> Caverns Of Time: Old Hillsbrad Foothills
	{1, -8743.524414f, -4212.994629f, -209.502350f, 2.079652f},		// 5 -> Caverns Of Time: The Black Morass
	{530, 726.399109f, 7012.219238f, -71.653625f, 0.243469f},		// 6 -> Coilfang Reservoir: The Slave Pens
	{530, 818.363037f, 6936.934082f, -80.563950f, 1.566548f},		// 7 -> Coilfang Reservoir: The Steamvault
	{530, 781.700317f, 6758.209473f, -72.538559f, 4.819668f},		// 8 -> Coilfang Reservoir: The Underbog
	{530, -361.422882f, 3070.912109f, -15.100495f, 1.831057f},		// 9 -> Hellfire Citadel: Hellfire Ramparts
	{530, -289.900055f, 3143.812012f, 31.559465f, 2.156997f},		// 10 -> Hellfire Citadel: The Blood Furnace
	{530, -305.500092f, 3057.982666f, -2.563048f, 1.803568f},		// 11 -> Hellfire Citadel: The Shattered Halls
	{530, 12887.865234f, -7327.206055f, 65.489189f, 4.414161f},		// 12 -> Magisters' Terrace
  
	// Outland Dungeons Page 2
	{530, 3308.408203f, 1341.109985f, 505.560150f, 5.088820f},		// 13 -> Tempest Keep: The Arcatraz
	{530, 3406.238770f, 1488.858521f, 182.836716f, 5.638611f},		// 14 -> Tempest Keep: The Botanica
	{530, 2871.128418f, 1553.697510f, 252.159409f, 3.880885f},		// 15 -> Tempest Keep: The Mechanar

	// Outland Raids
	{530, -3630.067139f, 316.651123f, 37.886879f, 3.256560f},		// 16 -> Black Temple
	{1, -8174.394043f, -4175.435059f, -166.111435f, 1.039002f},		// 17 -> Caverns Of Time: Hyjal Summit
	{530, 3523.040771f, 5156.423340f, -1.361456f, 4.897941f},		// 18 -> Gruul's Lair
	{530, -315.569214f, 3091.555908f, -116.450279f, 5.204344f},		// 19 -> Hellfire Citadel: Magtheridon's Lair
	{0, -11120.469727f, -2012.200928f, 47.092010f, 0.691536f},		// 20 -> Karazhan
	{530, 792.329529f, 6865.801758f, -64.877464f, 0.009099f},		// 21 -> Coilfang Reservoir: Serpentshrine Cavern
	{530, 12571.379883f, -6774.881348f, 15.090665f, 3.122185f},		// 22 -> Sunwell Plateau
	{530, 3088.703369f, 1387.535034f, 185.047989f, 4.631672f},		// 23 -> Tempest Keep: The Eye
	{530, 6851.236328f, -7946.058105f, 170.099228f, 4.721519f},		// 24 -> Zul'Aman
};

TeleportLocation dungNR[25] =
{
	// Northrend Dungeons Page 1
	{571, 3646.768555f, 2045.060547f, 1.788014f, 4.325577f},		// 0 -> Azjol-Nerub: Ahn'kahet: The Old Kingdom
	{571, 3677.125977f, 2168.078125f, 35.871422f, 2.462090f},		// 1 -> Azjol-Nerub: Azjol-Nerub
	{1, -8755.368164f, -4452.229980f, -199.898544f, 4.577219f},		// 2 -> Caverns Of Time: The Culling Of Stratholme
	{571, 4774.416016f, -2029.638794f, 229.377426f, 1.574463f},		// 3 -> Drak'Tharon Keep
	{571, 6952.257324f, -4420.084473f, 450.078491f, 0.710164f},		// 4 -> Gundrak
	{571, 5631.060059f, 2000.651245f, 798.053406f, 4.632284f},		// 5 -> Icecrown Citadel: Halls Of Reflection
	{571, 5604.095215f, 2020.264282f, 798.041565f, 3.854735f},		// 6 -> Icecrown Citadel: Pit Of Saron
	{571, 5660.829590f, 2015.391846f, 798.041565f, 5.421601f},		// 7 -> Icecrown Citadel: The Forge Of Souls
	{571, 3895.210693f, 6985.370117f, 69.488205f, 0.027609f},		// 8 -> The Nexus: The Nexus
	{571, 3861.390381f, 6983.841797f, 106.320709f, 0.046456f},		// 9 -> The Nexus: The Oculus
	{571, 5693.519531f, 503.024994f, 652.672668f, 4.051174f},		// 10 -> The Violet Hold
	{571, 8576.594727f, 792.178955f, 558.234314f, 3.177016f},		// 11 -> Crusaders' Coliseum: Trial Of The Champion
	
	// Northrend Dungeons Page 2
	{571, 9183.517578f, -1385.273193f, 1110.216553f, 5.553724f},	// 12 -> Ulduar: Halls Of Lighting
	{571, 8922.086914f, -979.697876f, 1039.286865f, 1.599244f},		// 13 -> Ulduar: Halls Of Stone
	{571, 1223.049683f, -4864.201172f, 41.247898f, 0.313228f},		// 14 -> Utgarde Keep: Utgarde Keep
	{571, 1242.868408f, -4857.460938f, 217.697083f, 3.463465f},		// 15 -> Utgarde Keep: Utgarde Pinnacle

	// Northrend Raids
	{571, 5855.583496f, 2101.985596f, 635.984558f, 3.579838f},		// 16 -> Icecrown Citadel
	{571, 3664.203613f, -1264.700439f, 243.886444f, 2.394701f},		// 17 -> Naxxramas
	{1, -4691.370117f, -3715.655762f, 49.115166f, 3.802153f},		// 18 -> Onyxia's Lair
	{571, 3878.891113f, 6979.814941f, 152.041946f, 2.678330f},		// 19 -> The Nexus: The Eye Of Eternity
	{571, 3471.989746f, 264.767578f, -120.144058f, 3.305161f},		// 20 -> The Obsidian Sanctum
	{571, 3590.016357f, 210.837860f, -120.056282f, 5.374678f},		// 21 -> The Ruby Sanctum
	{571, 8515.464844f, 727.112427f, 558.247864f, 1.592124f},		// 22 -> Crusaders' Coliseum: Trial Of The Crusader
	{571, 9331.112305f, -1114.685547f, 1245.146484f, 6.279322f},	// 23 -> Ulduar
	{571, 5476.769531f, 2840.317627f, 418.674683f, 6.276591f},		// 24 -> Vault Of Archavon
};

TeleportLocation travelPVP[18] =
{
	// PvP Travel Horde
	{0, -13539.644531f, 85.802834f, 28.728601f, 0.017654f},			// 0 -> Gurubashi [H]
	{1, -3644.058350f, 1092.957275f, 172.040924f, 3.134361f},		// 1 -> Dire Maul Arena [H]
	{0, -9298.084961f, 508.720795f, 80.465569f, 5.231081f},			// 2 -> Stormwind City Raid [H]
	{0, -5162.809082f, -872.166809f, 507.178802f, 0.872077f},		// 3 -> Ironforge Raid [H]
	{1, 9924.938477f, 2046.368774f, 1336.274414f, 1.091635f},		// 4 -> Darnassus Raid [H]
	{530, -3873.686035f, -11836.560547f, 5.010812f, 3.896366f},		// 5 -> The Exodar Raid [H]
	{530, -730.999329f, 7929.365234f, 58.172394f, 4.786565f},		// 6 -> Circle Of Blood [H]
	{571, 5789.297363f, -3031.679932f, 286.285767f, 2.019441f},		// 7 -> The Ring Of Trials [H]
	{571, 5026.607422f, 3675.916016f, 362.643372f, 4.260478f},		// 8 -> Wintergrasp [H]
  
	// PvP Travel Alliance
	{0, -13248.459961f, -82.886223f, 19.811010f, 1.553115f},		// 9 -> Gurubashi [A]
	{1, -3858.127930f, 1094.487183f, 172.038940f, 6.279881f},		// 10 -> Dire Maul Arena [A]
	{1, 1262.646851f, -4111.083008f, 27.059034f, 4.932321f},		// 11 -> Ogrimmar Raid [A]
	{0, 1804.898193f, 194.912460f, 70.399727f, 1.570292f},			// 12 -> Undercity Raid [A]
	{1, -1452.919434f, 242.737000f, -0.669047f, 5.403522f},			// 13 -> Thunder Bluff Raid [A]
	{530, 9324.250000f, -7481.621094f, 28.800985f, 1.311335f},		// 14 -> Silvermoon City Raid [A]
	{530, -730.999329f, 7929.365234f, 58.172394f, 4.786565f},		// 15 -> Circle Of Blood [A]
	{571, 5789.297363f, -3031.679932f, 286.285767f, 2.019441f},		// 16 -> The Ring Of Trials [A]
	{571, 5096.616211f, 2180.867432f, 365.603516f, 0.873054f},		// 17 -> Wintergrasp [A]
};

bool OnGossipHello(Player * pPlayer, Creature * pCreature);
bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 iSender, uint32 iAction);

#endif
