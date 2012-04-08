DELETE FROM `creature_template` WHERE `entry` IN (210001,210002);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(210001, 0, 0, 0, 0, 0, 27985, 27985, 0, 0, '샤론고', '몽이교단 현장요원', 'vehichleCursor', 0, 80, 80, 0, 35, 35, 1, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 147.371, 147.371, 147.371, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_helper_5raid1', 12340),
(210002, 0, 0, 0, 0, 0, 27985, 27985, 0, 0, '투영고', '몽이교단 현장요원', 'vehichleCursor', 0, 80, 80, 0, 35, 35, 1, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 147.371, 147.371, 147.371, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_helper_5raid2', 12340);
-- 5인 레이드 부활지점 영혼의 치유사 젠
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(10660043, 6491, 571, 1, 1, 0, 0, 6450.52, 2058.5, 564.834, 2.47872, 300, 0, 0, 4120, 0, 0, 0, 0, 0);

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(69845, 'spell_sindragosa_collision_filter'),
(70117, 'spell_sindragosa_collision_filter'),
(70127, 'spell_sindragosa_collision_filter'),
(71053, 'spell_sindragosa_collision_filter'),
(71054, 'spell_sindragosa_collision_filter'),
(71055, 'spell_sindragosa_collision_filter'),
(72528, 'spell_sindragosa_collision_filter'),
(72529, 'spell_sindragosa_collision_filter'),
(72530, 'spell_sindragosa_collision_filter');

-- 토라본 10/25 드랍테이블 : 코랄론과 동일
DELETE FROM `creature_loot_template` WHERE `entry`=38433;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(38433, 1, 100, 1, 0, -34212, 1),
(38433, 2, 100, 1, 0, -34204, 1),
(38433, 3, 1, 1, 0, -34203, 1),
(38433, 47241, 100, 1, 0, 2, 2);

DELETE FROM `creature_loot_template` WHERE `entry`=38462;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(38462,1,100,1,0,-34205,2),
(38462,2,80,1,0,-90001,1),
(38462,3,80,1,0,-90002,1),
(38462,4,1,1,0,-34203,1),
(38462,47241,100,1,0,2,2);

-- 투영 상자에 기존 추가템 삭제
DELETE FROM `gameobject_loot_template` WHERE `entry`=27985 and `item` IN (47241,36919,36931,36922,36925,36928,36934);
DELETE FROM `gameobject_loot_template` WHERE `entry`=27993 and `item`=47241;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 투영 상자 일반
(27985,47241,100,1,0,4,4),
-- 투영 상자 하드
(27993,47241,100,1,0,4,4);

-- 마윈 5인레이드 보상 추가
DELETE FROM `creature_loot_template` WHERE `entry`=38113 and `item`=47241;
DELETE FROM `creature_loot_template` WHERE `entry`=38603 and `item`=47241;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 마윈 일반
(38113,47241,100,1,0,12,17),(38113,36919,40,1,0,1,2),(38113,36931,40,1,0,1,2),(38113,36922,40,1,0,1,2),(38113,36925,40,1,0,1,2),(38113,36928,40,1,0,1,2),(38113,36934,40,1,0,1,2),
-- 마윈 하드
(38603,47241,100,1,0,17,17);

-- 냉혹1차무기 + 보조장비 룻테이블 작성
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(90003,42329,0,1,1,1,1),(90003,49189,0,1,1,1,1),(90003,42354,0,1,1,1,1),(90003,42386,0,1,1,1,1),(90003,42334,0,1,1,1,1),(90003,42229,0,1,1,1,1),(90003,42287,0,1,1,1,1),(90003,42234,0,1,1,1,1),(90003,42250,0,1,1,1,1),(90003,42521,0,1,1,1,1),(90003,42483,0,1,1,1,1),(90003,42504,0,1,1,1,1),(90003,42498,0,1,1,1,1),(90003,42272,0,1,1,1,1),(90003,42210,0,1,1,1,1),(90003,42244,0,1,1,1,1),(90003,42262,0,1,1,1,1),(90003,42324,0,1,1,1,1),(90003,42292,0,1,1,1,1),(90003,42267,0,1,1,1,1),(90003,42348,0,1,1,1,1),(90003,44424,0,1,1,1,1),(90003,42319,0,1,1,1,1),(90003,42366,0,1,1,1,1),(90003,42515,0,1,1,1,1),(90003,42257,0,1,1,1,1),(90003,42282,0,1,1,1,1),(90003,42487,0,1,1,1,1),(90003,44423,0,1,1,1,1),(90003,42277,0,1,1,1,1),(90003,49185,0,1,1,1,1),(90003,42492,0,1,1,1,1),(90003,42392,0,1,1,1,1),(90003,42566,0,1,1,1,1),(90003,42539,0,1,1,1,1),(90003,49187,0,1,1,1,1),(90003,42533,0,1,1,1,1),(90003,42616,0,1,1,1,1),(90003,42527,0,1,1,1,1),(90003,42580,0,1,1,1,1),(90003,42609,0,1,1,1,1),(90003,42572,0,1,1,1,1),(90003,42854,0,1,1,1,1),(90003,42561,0,1,1,1,1),(90003,42599,0,1,1,1,1),(90003,42604,0,1,1,1,1),(90003,42585,0,1,1,1,1),(90003,42591,0,1,1,1,1),(90003,42622,0,1,1,1,1);

-- 냉혹 2차무기 룻테이블 작성
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(90004,48523,0,1,1,1,1),(90004,49191,0,1,1,1,1),(90004,48406,0,1,1,1,1),(90004,48507,0,1,1,1,1),(90004,48440,0,1,1,1,1),(90004,48519,0,1,1,1,1),(90004,48521,0,1,1,1,1),(90004,48412,0,1,1,1,1),(90004,48404,0,1,1,1,1),(90004,48420,0,1,1,1,1),(90004,48408,0,1,1,1,1),(90004,48402,0,1,1,1,1),(90004,48509,0,1,1,1,1),(90004,48442,0,1,1,1,1),(90004,48517,0,1,1,1,1),(90004,48428,0,1,1,1,1),(90004,48424,0,1,1,1,1),(90004,48410,0,1,1,1,1),(90004,48414,0,1,1,1,1),(90004,48426,0,1,1,1,1),(90004,48515,0,1,1,1,1),(90004,48444,0,1,1,1,1),(90004,48432,0,1,1,1,1),(90004,48435,0,1,1,1,1),(90004,48513,0,1,1,1,1),(90004,48422,0,1,1,1,1),(90004,48438,0,1,1,1,1),(90004,48511,0,1,1,1,1);

-- 드랍 탈것/팻 룻테이블 작성
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(90005,11026,0,1,1,1,1),(90005,11027,0,1,1,1,1),(90005,48126,0,1,1,1,1),(90005,48118,0,1,1,1,1),(90005,48112,0,1,1,1,1),(90005,48124,0,1,1,1,1),(90005,48122,0,1,1,1,1),(90005,48114,0,1,1,1,1),(90005,48116,0,1,1,1,1),(90005,33993,0,1,1,1,1),(90005,31760,0,1,1,1,1),(90005,11110,0,1,1,1,1),(90005,12264,0,1,1,1,1),(90005,12529,0,1,1,1,1),(90005,27445,0,1,1,1,1),(90005,43698,0,1,1,1,1),(90005,44983,0,1,1,1,1),(90005,33816,0,1,1,1,1),(90005,35350,0,1,1,1,1),(90005,35349,0,1,1,1,1),(90005,33818,0,1,1,1,1),(90005,33976,0,1,1,1,1),(90005,21218,0,1,1,1,1),(90005,21323,0,1,1,1,1),(90005,21324,0,1,1,1,1),(90005,43962,0,1,1,1,1),(90005,43951,0,1,1,1,1),(90005,33977,0,1,1,1,1),(90005,33809,0,1,1,1,1),(90005,21321,0,1,1,1,1),(90005,37012,0,1,1,1,1),(90005,46109,0,1,1,1,1),(90005,49283,0,1,1,1,1),(90005,49285,0,1,1,1,1);

-- 비행선 10인 일반 룻테이블 작성
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(91002, 50340, 0, 1, 1, 1, 1),(91002, 50787, 0, 1, 1, 1, 1),(91002, 50788, 0, 1, 1, 1, 1),(91002, 50789, 0, 1, 2, 1, 1),(91002, 50790, 0, 1, 2, 1, 1),(91002, 50791, 0, 1, 1, 1, 1),(91002, 50792, 0, 1, 2, 1, 1),(91002, 50793, 0, 1, 1, 1, 1),(91002, 50794, 0, 1, 1, 1, 1),(91002, 50795, 0, 1, 2, 1, 1),(91002, 50796, 0, 1, 2, 1, 1),(91002, 50797, 0, 1, 2, 1, 1);

-- 비행선 25인 일반 룻테이블 작성
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(91003, 49998, 0, 1, 1, 1, 1),(91003, 49999, 0, 1, 2, 1, 1),(91003, 50000, 0, 1, 2, 1, 1),(91003, 50001, 0, 1, 3, 1, 1),(91003, 50002, 0, 1, 2, 1, 1),(91003, 50003, 0, 1, 3, 1, 1),(91003, 50005, 0, 1, 1, 1, 1),(91003, 50006, 0, 1, 3, 1, 1),(91003, 50008, 0, 1, 1, 1, 1),(91003, 50009, 0, 1, 3, 1, 1),(91003, 50010, 0, 1, 2, 1, 1),(91003, 50011, 0, 1, 1, 1, 1),(91003, 50352, 0, 1, 1, 1, 1),(91003, 50359, 0, 1, 2, 1, 1),(91003, 50411, 0, 1, 3, 1, 1);

-- 비행선 10인 하드 룻테이블 작성
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(91004, 50345, 0, 1, 2, 1, 1),(91004, 51906, 0, 1, 1, 1, 1),(91004, 51907, 0, 1, 1, 1, 1),(91004, 51908, 0, 1, 1, 1, 1),(91004, 51909, 0, 1, 2, 1, 1),(91004, 51910, 0, 1, 2, 1, 1),(91004, 51911, 0, 1, 2, 1, 1),(91004, 51912, 0, 1, 2, 1, 1),(91004, 51913, 0, 1, 1, 1, 1),(91004, 51914, 0, 1, 2, 1, 1),(91004, 51915, 0, 1, 1, 1, 1),(91004, 51916, 0, 1, 1, 1, 1);

-- 비행선 25인 하드 룻테이블 작성
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(91005, 50349, 0, 1, 2, 1, 1),(91005, 50366, 0, 1, 1, 1, 1),(91005, 50653, 0, 1, 3, 1, 1),(91005, 50654, 0, 1, 3, 1, 1),(91005, 50655, 0, 1, 3, 1, 1),(91005, 50656, 0, 1, 2, 1, 1),(91005, 50657, 0, 1, 3, 1, 1),(91005, 50658, 0, 1, 1, 1, 1),(91005, 50659, 0, 1, 2, 1, 1),(91005, 50660, 0, 1, 1, 1, 1),(91005, 50661, 0, 1, 1, 1, 1),(91005, 50663, 0, 1, 2, 1, 1),(91005, 50664, 0, 1, 2, 1, 1),(91005, 50665, 0, 1, 1, 1, 1),(91005, 50667, 0, 1, 3, 1, 1);

-- 교수 비행선 아이템 추가드랍
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(36678,2,40,1,0,-91002,2),(38431,2,40,1,0,-91003,3),(38585,3,40,1,0,-91004,2),(38586,2,40,1,0,-91005,3);

-- 냉혹무기들 추가드랍
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 3넴 흑기사 일반 (+격노 룻테이블)
(35451,2,5,1,0,-34212,1),(35451,3,4,1,0,-90003,1),(35451,4,2,1,0,-90004,1),
-- 3넴 흑기사 하드
(35490,3,6,1,0,-90003,2),(35490,4,4,1,0,-90004,1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 투영 상자 일반
(27985,2,4,1,0,-90003,2),(27985,3,3,1,0,-90004,1),
-- 투영 상자 하드
(27993,2,6,1,0,-90004,1);

-- 팻/탈것 추가드랍
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(35451,5,2.5,1,0,-90005,1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 투영 상자 일반
(27985,4,2.5,1,0,-90005,1);
