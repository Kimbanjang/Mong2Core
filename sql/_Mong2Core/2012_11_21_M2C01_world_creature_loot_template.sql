-- 교수 비행선 아이템 드랍확률 100%
DELETE FROM `creature_loot_template` WHERE `mincountOrRef` IN (-91002,-91003,-91004,-91005);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(36678,2,100,1,0,-91002,1),(38431,2,100,1,0,-91003,2),(38585,3,100,1,0,-91004,1),(38586,2,100,1,0,-91005,2);
