-- 교수 비행선 아이템 드랍 (100%-1 / 75%-2 / 100%-1 / 75%-2)
DELETE FROM `creature_loot_template` WHERE `mincountOrRef` IN (-91002,-91003,-91004,-91005);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(36678,2,100,1,0,-91002,1),(38431,2,75,1,0,-91003,2),(38585,3,100,1,0,-91004,1),(38586,2,75,1,0,-91005,2);

-- 싸울팽 비행선 아이템 드랍 (75%-1 / 50%-2 / 75%-1 / 50%-2)
DELETE FROM `gameobject_loot_template` WHERE `mincountOrRef` IN (-91002,-91003,-91004,-91005);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(28046,2,75,1,0,-91002,1),(28074,3,50,1,0,-91003,2),(28058,3,75,1,0,-91004,1),(28088,3,50,1,0,-91005,2);
