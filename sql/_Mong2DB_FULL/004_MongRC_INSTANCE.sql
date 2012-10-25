################################
########## [비레이드] ##########
################################

##### 용사의 시험장(TOC5) #####
/*
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
(35451,47241,100,1,0,4,8), -- 3넴 흑기사 일반
(35490,47241,100,1,0,6,6); -- 3넴 흑기사 하드
*/

##### 얼왕5인 추가 세팅 #####
-- 영제/샤론/투영 토큰 드랍(23961,23964,23967)
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(36658,2,2,1,0,-90005,1),(36938,2,2,1,0,-90005,1),(36502,2,4,1,0,-90005,1),(37677,2,4,1,0,-90005,1), -- 팻/탈것
(36658,23961,10,1,0,5,5),(36938,23961,10,1,0,5,5),(36502,23964,100,1,0,5,5),(37677,23964,100,1,0,5,5);   -- 토큰
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(27993,2,4,1,0,-90005,1),(27985,2,8,1,0,-90005,1),  -- 팻/탈것
(27993,23967,20,1,0,5,5),(27985,23967,100,1,0,5,5); -- 토큰

-- 보석 드랍 샘플
-- INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- (27985,36919,40,1,0,1,2),(27985,36931,40,1,0,1,2),(27985,36922,40,1,0,1,2),(27985,36925,40,1,0,1,2),(27985,36928,40,1,0,1,2),(27985,36934,40,1,0,1,2);


##############################
########## [레이드] ##########
##############################

##### 아제로스 레이드 보스 젠시간 #####
UPDATE `creature` SET `spawntimesecs`='604800' WHERE `id` IN (12118,11982,12259,12057,12264,12056,11988,12098,12435,13020,12017,11983,14601,11981,14020,11583,15263,15516,15510,15509,15276,15275,15727,15543,15544,15511,15299,15517);
UPDATE `creature` SET `spawntimesecs`='259200' WHERE `id` IN (15348,15341,15340,15370,15369,15339,14517,14507,14510,14509,14515,14834,11382,11380);

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

-- 토라본 10/25 드랍테이블 : 코랄론과 동일
DELETE FROM `creature_loot_template` WHERE `entry` IN (38433,38462);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(38433, 1, 100, 1, 0, -34212, 1),(38433, 2, 100, 1, 0, -34204, 1),(38433, 3, 1, 1, 0, -34203, 1),(38433, 4, 20, 1, 0, -90003, 1),(38433, 47241, 100, 1, 0, 2, 2),(38462, 1, 100, 1, 0, -34213, 2),(38462, 2, 100, 1, 0, -34205, 2),(38462, 3, 1, 1, 0, -34203, 1),(38462, 4, 20, 1, 0, -90004, 1),(38462, 47241, 100, 1, 0, 2, 2);


##### 울두아르 #####


##### 마상 시합장(TOC) #####
-- 자락서스 추가 구현
-- DELETE FROM `spell_script_names` WHERE `spell_id` IN (66316,67100,67101,67102) AND `ScriptName`='spell_spinning_pain_strike';
-- INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (66316, 'spell_spinning_pain_strike'),(67100, 'spell_spinning_pain_strike'),(67101, 'spell_spinning_pain_strike'),(67102, 'spell_spinning_pain_strike');

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

##### 루비 성소 #####
-- 보스 젠시간 조정
-- UPDATE `creature` SET `spawntimesecs`='604800' WHERE `id` IN (15348,15341,15340,15370,15369,15339,14517,14507,14510,14509,14515,14834,11382,11380);

