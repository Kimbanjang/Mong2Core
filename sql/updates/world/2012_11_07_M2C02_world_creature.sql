-- 샤론의 구덩이 동굴이벤트 롤백
DELETE FROM `creature` WHERE `id`=36847;

-- 아눕아락 서리문장 재조정
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(34564,49426,25,1,0,2,5),(34566,49426,50,1,0,4,7),(35615,49426,50,1,0,4,7),(35616,49426,75,1,0,5,10);