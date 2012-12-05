-- 보석주머니에서 얼보 제거
DELETE FROM `reference_loot_template` WHERE `entry`=90007 AND `item`=43102;

-- 샤론/영제 에서 얼보 드랍 50%
DELETE FROM `creature_loot_template` WHERE `entry`=36658 AND `item`=43102;
DELETE FROM `creature_loot_template` WHERE `entry`=36502 AND `item`=43102;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(36658,43102,50,1,0,1,1),(36502,43102,50,1,0,1,1);

-- 보석주머니/원소결계/겨손상인템 잔진이 판매
DELETE FROM `npc_vendor` WHERE `entry` IN (60242);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
(60242,0,44075,0,0,2549),(60242,0,44069,0,0,2549),(60242,0,44067,0,0,2546),(60242,0,44068,0,0,2546),(60242,0,44115,0,0,2546), -- 겨손템
(60242,0,32543,0,0,2723),(60242,0,32544,0,0,2723),(60242,0,32545,0,0,2723),(60242,0,32546,0,0,2723),(60242,0,32547,0,0,2723),(60242,0,22124,0,0,2723),(60242,0,22125,0,0,2723),(60242,0,22126,0,0,2723),(60242,0,22127,0,0,2723),(60242,0,22129,0,0,2723),(60242,0,21969,0,0,2723),(60242,0,21970,0,0,2723),(60242,0,21971,0,0,2723),(60242,0,21972,0,0,2723),(60242,0,21973,0,0,2723),(60242,0,34156,0,0,2723),(60242,0,34548,0,0,2723);

-- 실수로 지운 오그리마/스톰윈드 탈것 NPC
DELETE FROM `npc_vendor` WHERE `entry` IN (12796,12783);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
(12783, 0, 29465, 0, 0, 423),(12783, 0, 29467, 0, 0, 423),(12783, 0, 29468, 0, 0, 423),(12783, 0, 29471, 0, 0, 423),(12783, 0, 35906, 0, 0, 423),(12796, 0, 29466, 0, 0, 423),(12796, 0, 29469, 0, 0, 423),(12796, 0, 29470, 0, 0, 423),(12796, 0, 29472, 0, 0, 423),(12796, 0, 34129, 0, 0, 423);

-- 커스텀 상자 강화
DELETE FROM `item_loot_template` WHERE `entry` IN (34548,34156);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 에픽보석 주머니
(34548,1,100,1,0,-90007,3),
-- 전 차원 원소결계
(34156,1,100,1,0,-90022,2),(34156,2,100,1,0,-90023,2),(34156,3,100,1,0,-90024,2);
