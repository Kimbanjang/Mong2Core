##### 면역체계 #####
-- 완전 무결한 보스
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (10184,36538); -- 오닉시아
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (34564,34566,35615,35616); -- 십자군 아눕아락
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (34796,35438,35439,35440); -- 십자군 고르목
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (35144,35511,35512,35513); -- 십자군 산성아귀
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (34799,35514,35515,35516); -- 십자군 공포비늘
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (34797,35447,35448,35449); -- 십자군 얼음울음
-- 차단만 가능한 보스
UPDATE `creature_template` SET `mechanic_immune_mask`='617299967' WHERE `entry` IN (34496,35347,35348,35349); -- 십자군 다크베인
UPDATE `creature_template` SET `mechanic_immune_mask`='617299967' WHERE `entry` IN (34497,35350,35351,35352); -- 십자군 라이트베인
UPDATE `creature_template` SET `mechanic_immune_mask`='617299967' WHERE `entry` IN (34780,35216,35268,35269); -- 십자군 자락서스
-- 매즈가 가능한 보스
-- TBC 보스
UPDATE `creature_template` SET `flags_extra` = 0 WHERE `entry` IN (19893,19895,19894,20267,20268,20266,18436,18433,18434,20690,20706,23035,20738,20568,20597,21551,21558,21581,21559,25562,25573,25560,24857,18621,18601,18607,20169,20168,20183,20184,20636,20637,20653,20657,20629,20630,20633,21533,21536,21537,21626,21590,21624,21601,20318,20306);
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967, `flags_extra` = 0 WHERE `entry` IN (20738, 20737,20993,21582);
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967, `flags_extra` = 256 WHERE `entry` IN (20745,20596);
-- The Nexus
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (30510, 30529, 30532, 30540, 30398, 30397);
-- Utgarde Keep
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (30748, 31679, 31656, 31673, 31674);
-- Utgarde Pinnacle
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (30810, 30774, 30807, 30788);
-- Stratholme Past
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (31211, 31212, 31215, 31217);
-- Halls of Stone
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (31384, 31381, 31386);
-- Halls of Lightning
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (31533, 31536, 31537, 31538);
-- Drak'Tharon Keep
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (31362, 31350, 31349, 31360);
-- Gundrak
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (31370, 31365, 30530, 31368, 29932);
-- Azjol-Nerub
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (31612, 31611, 31610);
-- The Violet Hold
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (31507, 31510, 31508, 31511, 31509, 31512, 31506);
-- Update Frozen Halls Immunities
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (
-- Halls of Reflection (38112 - Falric, 38599 - Falric (1), 38113 - Marwyn, 38603 - Marwyn (1), 37226 - Wrath of the Lich King)
38112,38599,38113,38603,37226,
-- Pit of Saron (36494 - Forgemaster Garfrost, 37613 - Forgemaster Garfrost (1) ,36476 - Ick ,37627 - Ick (1) ,36477 - Krick ,37629 - Krick (1) ,36658 - Scourgelord Tyrannus ,36938 - Scourgelord Tyrannus (1))
36494,37613,36476,37627,36477,37629,36658,36938,
-- The Forge of Souls (36497 - Bronjahm, 36498 - Bronjahm (1), 36502 - Devourer of Souls, 37677 - Devourer of Souls (1))
36497,36498,36502,37677);


################################
########## [비레이드] ##########
################################

##### 검은바위 첨탑 상층 #####
-- 입구 문 오브젝 삭제
DELETE FROM `gameobject` WHERE `guid` IN (87839,87842,87841,87845,87844);
-- 백업
-- INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES ('87839', '175244', '229', '1', '1', '216.443', '-286.135', '76.9406', '3.14159', '0', '0', '0', '0', '120', '0', '1'),('87842', '175705', '229', '1', '1', '175.127', '-258.945', '91.5603', '0', '0', '0', '0', '0', '120', '0', '1'),('87841', '175153', '229', '1', '1', '113.751', '-258.945', '91.5603', '0', '0', '0', '0', '0', '120', '0', '1'),('87845', '164726', '229', '1', '1', '108.036', '-420.331', '110.954', '3.14159', '0', '0', '0', '0', '120', '0', '1'),('87844', '175186', '229', '1', '1', '92.9595', '-435.59', '110.954', '-1.5708', '0', '0', '0', '0', '120', '0', '1');

/*
##### 용사의 시험장(TOC5) #####
-- 용사의 시합장 승전문장 드랍
DELETE FROM `gameobject_loot_template` WHERE `entry`=27321 and `item`=47241;
DELETE FROM `gameobject_loot_template` WHERE `entry`=27325 and `item`=47241;
DELETE FROM `gameobject_loot_template` WHERE `entry`=27327 and `item`=47241;
DELETE FROM `gameobject_loot_template` WHERE `entry`=27414 and `item`=47241;
DELETE FROM `gameobject_loot_template` WHERE `entry`=27416 and `item`=47241;
DELETE FROM `gameobject_loot_template` WHERE `entry`=27417 and `item`=47241;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(27321,47241,100,1,0,1,2), -- 1넴 일반
(27325,47241,100,1,0,1,2), -- 2넴 에드릭 일반
(27327,47241,100,1,0,1,2), -- 2넴 파레트레스 일반
(27414,47241,100,1,0,2,2), -- 1넴 하드
(27416,47241,100,1,0,2,2), -- 2넴 에드릭 하드
(27417,47241,100,1,0,2,2); -- 2넴 파레트레스 하드
DELETE FROM `creature_loot_template` WHERE `entry`=35451 and `item`=47241;
DELETE FROM `creature_loot_template` WHERE `entry`=35490 and `item`=47241;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 3넴 흑기사 일반
(35451,47241,100,1,0,4,8),(35451,36919,20,1,0,1,3),(35451,36931,20,1,0,1,3),(35451,36922,20,1,0,1,3),(35451,36925,20,1,0,1,3),(35451,36928,20,1,0,1,3),(35451,36934,20,1,0,1,3),
-- 3넴 흑기사 하드
(35490,47241,100,1,0,6,6),(35490,2,30,1,0,-34212,2);

-- 용사의 시합장 네임드 10% 버프 (73818)
DELETE FROM `creature_template_addon` WHERE `entry` IN (35307,35309,35451,34657);
INSERT INTO `creature_template_addon` VALUES
-- 일반
(34657,0,0,0,0,0,73818), -- 1넴 시작
(34701,0,0,0,0,0,73818),
(34702,0,0,0,0,0,73818),
(34703,0,0,0,0,0,73818),
(34705,0,0,0,0,0,73818),
(35569,0,0,0,0,0,73818),
(35570,0,0,0,0,0,73818),
(35571,0,0,0,0,0,73818),
(35572,0,0,0,0,0,73818),
(35617,0,0,0,0,0,73818), -- 1넴 끝
(35305,0,0,0,0,0,73818), -- 2넴 졸 시작
(35307,0,0,0,1,0,73818),
(35309,0,0,0,1,0,73818), -- 2넴 졸 끝
(35119,0,0,0,0,0,73818), -- 2넴 에드릭
(34928,0,0,0,0,0,73818), -- 2넴 파레트레스
(35564,0,0,0,0,0,73818), -- 3넴 졸 시작
(35590,0,0,0,0,0,73818),
(35545,0,0,0,0,0,73818), -- 3넴 졸 끝
(35451,0,0,0,1,0,73818), -- 3넴 흑기사1
-- 하드
(36086,0,0,0,0,0,73818), -- 1넴 시작
(36083,0,0,0,0,0,73818),
(36082,0,0,0,0,0,73818),
(36087,0,0,0,0,0,73818),
(36088,0,0,0,0,0,73818),
(36085,0,0,0,0,0,73818),
(36091,0,0,0,0,0,73818),
(36090,0,0,0,0,0,73818),
(36089,0,0,0,0,0,73818),
(36084,0,0,0,0,0,73818), -- 1넴 끝
(35306,0,0,0,0,0,73818), -- 2넴 졸 시작
(35308,0,0,0,0,0,73818),
(35310,0,0,0,0,0,73818), -- 2넴 졸 끝
(35518,0,0,0,0,0,73818), -- 2넴 에드릭
(35517,0,0,0,0,0,73818), -- 2넴 파레트레스
(35717,0,0,0,0,0,73818), -- 3넴 졸 시작
(35546,0,0,0,0,0,73818),
(35568,0,0,0,0,0,73818), -- 3넴 졸 끝 
(35490,0,0,0,0,0,73818); -- 3넴 흑기사1

##### 얼왕 5인던젼 #####
-- 인던 연결
DELETE FROM `areatrigger_teleport` WHERE `id` IN (5635,5642,5688,5636,5646,5637,5643,5683);
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(5635, 'Forge of Souls (Entrance)', 632, 4922.86, 2175.63, 638.734, 2.00355),
(5642, 'Forge of Souls (Exit)', 571, 5667.72, 2007.19, 798.042, 2.31535),
(5688, 'Forge of Souls (Exit)', 658, 435.743, 212.413, 528.709, 6.25646),
(5637, 'Pit of Saron (Entrance)', 632, 4922.86, 2175.63, 638.734, 2.00355),
(5643, 'Pit of Saron (Exit)', 571, 5595.92, 2013.02, 798.041, 0.648728),
(5683, 'Pit of Saron (Exit)', 668, 5239.01, 1932.64, 707.695, 0.800565),
(5636, 'Halls of Reflection (Entrance)', 632, 4922.86, 2175.63, 638.734, 2.00355),
(5646, 'Halls of Reflection (Exit)', 571, 5630.59, 1997.55, 798.049, 1.44042);

-- 마지막 추가 보상
DELETE FROM `gameobject_loot_template` WHERE `entry`=27985 and `item`=47241;
DELETE FROM `gameobject_loot_template` WHERE `entry`=27993 and `item`=47241;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 투영 상자 일반
(27985,47241,100,1,0,15,20),(27985,1,20,1,0,-34212,1),(27985,36919,40,1,0,1,2),(27985,36931,40,1,0,1,2),(27985,36922,40,1,0,1,2),(27985,36925,40,1,0,1,2),(27985,36928,40,1,0,1,2),(27985,36934,40,1,0,1,2),
-- 투영 상자 하드
(27993,47241,100,1,0,20,20),(27993,1,20,1,0,-34213,2);
*/

##############################
########## [레이드] ##########
##############################

##### 줄구룹 #####
-- 혈군주 만도키르 이벤트발생X 공격가능
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=11382;


##### 낙스마라스 #####
-- 낙스, 프웜 날개짓 수정
DELETE FROM areatrigger_scripts WHERE `entry`=4156;
INSERT INTO areatrigger_scripts VALUES (4156,'at_naxxramas_frostwyrm_wing');

-- 낙스, 글루스 수정
DELETE FROM spell_script_names WHERE spell_id IN (28374, 54426);
INSERT INTO spell_script_names VALUES (28374, "spell_gluth_decimate"),(54426, "spell_gluth_decimate");


##### 오닉시아 #####
-- 오닉시아 둥지에서 전멸시 유령 스타팅 포인트 정상적으로 수정 (얼라이언스, 호드 공통)
DELETE FROM `game_graveyard_zone` WHERE `ghost_zone`='2159';
INSERT INTO `game_graveyard_zone` VALUES (1265,2159,0);


##### 아카본 #####
-- 아카본의 콜라론 업적
DELETE FROM achievement_criteria_data WHERE criteria_id IN (11478, 11479);
INSERT INTO achievement_criteria_data VALUES (11478, 12, 0, 0, ""), (11479, 12, 1, 0, "");

-- 아카본 진입 조정 (얼라이언스만 1733 / 호드만 1735 / 둘다 0)
UPDATE `gameobject_template` SET `faction`=0 WHERE `entry`=190763;

-- 승전문장 판매템 룻테이블 작성 (90001 공통 / 90002 얼라-호드 구분 있는것)
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(90001,47667,0,1,1,1,1),(90001,47666,0,1,1,1,1),(90001,47665,0,1,1,1,1),(90001,47673,0,1,1,1,1),(90001,47672,0,1,1,1,1),(90001,47662,0,1,1,1,1),(90001,47661,0,1,1,1,1),(90001,47664,0,1,1,1,1),(90001,47668,0,1,1,1,1),(90001,47671,0,1,1,1,1),(90001,47659,0,1,1,1,1),(90001,47658,0,1,1,1,1),(90001,47660,0,1,1,1,1),(90001,47733,0,1,1,1,1),(90001,47730,0,1,1,1,1),(90001,47731,0,1,1,1,1),(90001,47729,0,1,1,1,1),(90001,47732,0,1,1,1,1),(90001,48724,0,1,1,1,1),(90001,48722,0,1,1,1,1),(90001,47734,0,1,1,1,1),(90001,47735,0,1,1,1,1);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(90002,47712,0,1,1,1,1),(90002,47698,0,1,1,1,1),(90002,47702,0,1,1,1,1),(90002,47697,0,1,1,1,1),(90002,47715,0,1,1,1,1),(90002,47707,0,1,1,1,1),(90002,47713,0,1,1,1,1),(90002,47704,0,1,1,1,1),(90002,47708,0,1,1,1,1),(90002,47689,0,1,1,1,1),(90002,47693,0,1,1,1,1),(90002,47685,0,1,1,1,1),(90002,47686,0,1,1,1,1),(90002,47674,0,1,1,1,1),(90002,47694,0,1,1,1,1),(90002,47690,0,1,1,1,1),(90002,47681,0,1,1,1,1),(90002,47677,0,1,1,1,1),(90002,47706,0,1,2,1,1),(90002,47701,0,1,2,1,1),(90002,47696,0,1,2,1,1),(90002,47699,0,1,2,1,1),(90002,47705,0,1,2,1,1),(90002,47714,0,1,2,1,1),(90002,47716,0,1,2,1,1),(90002,47710,0,1,2,1,1),(90002,47709,0,1,2,1,1),(90002,47688,0,1,2,1,1),(90002,47691,0,1,2,1,1),(90002,47692,0,1,2,1,1),(90002,47695,0,1,2,1,1),(90002,47682,0,1,2,1,1),(90002,47678,0,1,2,1,1),(90002,47687,0,1,2,1,1),(90002,47675,0,1,2,1,1),(90002,47684,0,1,2,1,1);

-- 코랄론25 드랍테이블 변경 (냉혹X - 신규 드랍테이블 추가)
DELETE FROM `creature_loot_template` WHERE `entry`=35360;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(35360,1,100,1,0,-34205,2),
(35360,2,80,1,0,-90001,1),
(35360,3,80,1,0,-90002,1),
(35360,4,1,1,0,-34203,1),
(35360,47241,100,1,0,2,2);

-- 토라본 10/25 드랍테이블 : 코랄론과 동일
DELETE FROM `creature_loot_template` WHERE `entry` IN (38433,38462);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(38433,1,100,1,0,-34212,1), -- 토라본 10
(38433,2,100,1,0,-34204,1),
(38433,3,1,1,0,-34203,1),
(38433,47241,100,1,0,2,2),
(38462,1,100,1,0,-34205,2), -- 토라본 25
(38462,2,80,1,0,-90001,1),
(38462,3,80,1,0,-90002,1),
(38462,4,1,1,0,-34203,1),
(38462,47241,100,1,0,2,2);


##### 울두아르 #####


##### 마상 시합장(TOC) #####
-- 노스랜드 야수들 잡을시 던젼 귀속
UPDATE `creature_template` SET `flags_extra`='1' WHERE `entry` IN (35514,35515,35516,35511,35512,35513);

-- 자락서스 추가 구현
-- DELETE FROM `spell_script_names` WHERE `spell_id` IN (66316,67100,67101,67102) AND `ScriptName`='spell_spinning_pain_strike';
-- INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (66316, 'spell_spinning_pain_strike'),(67100, 'spell_spinning_pain_strike'),(67101, 'spell_spinning_pain_strike'),(67102, 'spell_spinning_pain_strike');

-- 십자군 바닥 HP
UPDATE `gameobject_template` SET `data0`=10000000 WHERE `entry`=195527;

-- 십자군 레이드 아이템 드랍수 변경 (item=1 얼라이언스 / item=2 호드)
-- 10N
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34797 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34797 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34780 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34780 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34497 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34497 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34564 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34564 AND `item`=2;
-- 25N
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35447 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35447 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35216 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35216 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35350 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35350 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=34566 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=34566 AND `item`=2;
-- 10H
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35448 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35448 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35268 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35268 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35351 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35351 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35615 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35615 AND `item`=2;
-- 25H
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35449 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35449 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35269 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35269 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35352 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35352 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35616 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35616 AND `item`=2;


##### 얼왕성채 #####
-- 얼왕성채 버프 삭제
DELETE FROM `spell_area` WHERE `spell` IN (73822,73828);

-- 얼왕 착귀템 획귀템 변경
UPDATE `item_template` SET `bonding`=1 WHERE `entry` IN (49967,49994,50001,50015,50020,50038,50069,50175,50182,50472,50444,50447,50449,50450,50451,50452,50453);

-- 얼왕평판 수치 변경
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` ='0' WHERE `RewOnKillRepFaction1` = '1156';
REPLACE INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES
(36612, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36855, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(37813, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36627, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36626, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36678, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(37970, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(37955, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36853, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36597, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36597, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(37957, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38106, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38402, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38390, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(37504, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38431, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38401, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38434, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38265, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(39166, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(37958, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38296, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38582, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38549, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(37505, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38585, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38784, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38435, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(38266, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(39167, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(37959, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38297, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38583, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38550, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(37506, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(38586, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(38785, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(38436, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(38267, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(39168, 1156, 1156, 6, 0, 150, 7, 0, 100, 0);

-- 얼왕 착귀 룻테이블 삭제 및 재생성 (신규 착귀템 테이블 91001)
DELETE FROM `reference_loot_template` WHERE `entry`=35068;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(35068,38,0,1,1,1,1),(35068,39,0,1,1,1,1),(35068,40,0,1,1,1,1),(35068,43,0,1,1,1,1),(35068,44,0,1,1,1,1),(35068,45,0,1,1,1,1),(35068,47,0,1,1,1,1),(35068,48,0,1,1,1,1),(35068,49,0,1,1,1,1),(35068,51,0,1,1,1,1),(35068,52,0,1,1,1,1),(35068,53,0,1,1,1,1),(35068,55,0,1,1,1,1),(35068,56,0,1,1,1,1),(35068,57,0,1,1,1,1),(35068,59,0,1,1,1,1),
(91001,50444,0,1,1,1,1),(91001,50447,0,1,1,1,1),(91001,50449,0,1,1,1,1),(91001,50450,0,1,1,1,1),(91001,50451,0,1,1,1,1),(91001,50452,0,1,1,1,1),(91001,50453,0,1,1,1,1);

-- 얼왕 착귀템 25인일반/10인하드 라나텔, 신드라고사, 리치왕 25% 드랍
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(39166,3,25,1,0,-91001,1),(39167,3,25,1,0,-91001,1),(38434,3,25,1,0,-91001,1),(38435,3,25,1,0,-91001,1),(38265,3,25,1,0,-91001,1),(38266,3,25,1,0,-91001,1);

-- 얼왕 일퀘 착귀템 드랍제거
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=49967;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=49994;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50001;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50015;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50020;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50038;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50069;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50175;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50182;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50444;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50447;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50449;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50450;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50451;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50452;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50453;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50472;

-- 비행선 룻테이블
DELETE FROM `reference_loot_template` WHERE `entry` IN (91002,91003,91004,91005);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
-- 10인 일반
(91002, 50340, 0, 1, 1, 1, 1),(91002, 50787, 0, 1, 1, 1, 1),(91002, 50788, 0, 1, 1, 1, 1),(91002, 50789, 0, 1, 1, 1, 1),(91002, 50790, 0, 1, 1, 1, 1),(91002, 50791, 0, 1, 1, 1, 1),(91002, 50792, 0, 1, 1, 1, 1),(91002, 50793, 0, 1, 1, 1, 1),(91002, 50794, 0, 1, 1, 1, 1),(91002, 50795, 0, 1, 1, 1, 1),(91002, 50796, 0, 1, 1, 1, 1),(91002, 50797, 0, 1, 1, 1, 1),
-- 25인 일반
(91003, 49998, 0, 1, 1, 1, 1),(91003, 49999, 0, 1, 1, 1, 1),(91003, 50000, 0, 1, 1, 1, 1),(91003, 50001, 0, 1, 1, 1, 1),(91003, 50002, 0, 1, 1, 1, 1),(91003, 50003, 0, 1, 1, 1, 1),(91003, 50005, 0, 1, 1, 1, 1),(91003, 50006, 0, 1, 1, 1, 1),(91003, 50008, 0, 1, 1, 1, 1),(91003, 50009, 0, 1, 1, 1, 1),(91003, 50010, 0, 1, 1, 1, 1),(91003, 50011, 0, 1, 1, 1, 1),(91003, 50352, 0, 1, 1, 1, 1),(91003, 50359, 0, 1, 1, 1, 1),(91003, 50411, 0, 1, 1, 1, 1),
-- 10인 하드
(91004, 50345, 0, 1, 1, 1, 1),(91004, 51906, 0, 1, 1, 1, 1),(91004, 51907, 0, 1, 1, 1, 1),(91004, 51908, 0, 1, 1, 1, 1),(91004, 51909, 0, 1, 1, 1, 1),(91004, 51910, 0, 1, 1, 1, 1),(91004, 51911, 0, 1, 1, 1, 1),(91004, 51912, 0, 1, 1, 1, 1),(91004, 51913, 0, 1, 1, 1, 1),(91004, 51914, 0, 1, 1, 1, 1),(91004, 51915, 0, 1, 1, 1, 1),(91004, 51916, 0, 1, 1, 1, 1),
-- 25인 하드
(91005, 50349, 0, 1, 1, 1, 1),(91005, 50366, 0, 1, 1, 1, 1),(91005, 50653, 0, 1, 1, 1, 1),(91005, 50654, 0, 1, 1, 1, 1),(91005, 50655, 0, 1, 1, 1, 1),(91005, 50656, 0, 1, 1, 1, 1),(91005, 50657, 0, 1, 1, 1, 1),(91005, 50658, 0, 1, 1, 1, 1),(91005, 50659, 0, 1, 1, 1, 1),(91005, 50660, 0, 1, 1, 1, 1),(91005, 50661, 0, 1, 1, 1, 1),(91005, 50663, 0, 1, 1, 1, 1),(91005, 50664, 0, 1, 1, 1, 1),(91005, 50665, 0, 1, 1, 1, 1),(91005, 50667, 0, 1, 1, 1, 1);

-- 교수 비행선 아이템 추가드랍
DELETE FROM `creature_loot_template` WHERE `mincountOrRef` IN (-91002,-91003,-91004,-91005);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(36678,2,40,1,0,-91002,2),(38431,2,40,1,0,-91003,3),(38585,3,40,1,0,-91004,2),(38586,2,40,1,0,-91005,3);

-- 신드라고사 / 리치왕 종족 타입변경
UPDATE `creature_template` SET `type` ='7' WHERE `entry` IN (36597,39166,39167,39168);
UPDATE `creature_template` SET `type` ='2' WHERE `entry` IN (36853,38265,38266,38267);
