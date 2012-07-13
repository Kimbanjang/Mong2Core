-- 열세진영 지원 "?"
DELETE FROM `item_template` WHERE `entry` IN (60001);
INSERT INTO `item_template` (`entry`, `class`, `subclass`, `unk0`, `name`, `displayid`, `Quality`, `Flags`, `FlagsExtra`, `BuyCount`, `BuyPrice`, `SellPrice`, `InventoryType`, `AllowableClass`, `AllowableRace`, `ItemLevel`, `RequiredLevel`, `RequiredSkill`, `RequiredSkillRank`, `requiredspell`, `requiredhonorrank`, `RequiredCityRank`, `RequiredReputationFaction`, `RequiredReputationRank`, `maxcount`, `stackable`, `ContainerSlots`, `StatsCount`, `stat_type1`, `stat_value1`, `stat_type2`, `stat_value2`, `stat_type3`, `stat_value3`, `stat_type4`, `stat_value4`, `stat_type5`, `stat_value5`, `stat_type6`, `stat_value6`, `stat_type7`, `stat_value7`, `stat_type8`, `stat_value8`, `stat_type9`, `stat_value9`, `stat_type10`, `stat_value10`, `ScalingStatDistribution`, `ScalingStatValue`, `dmg_min1`, `dmg_max1`, `dmg_type1`, `dmg_min2`, `dmg_max2`, `dmg_type2`, `armor`, `holy_res`, `fire_res`, `nature_res`, `frost_res`, `shadow_res`, `arcane_res`, `delay`, `ammo_type`, `RangedModRange`, `spellid_1`, `spelltrigger_1`, `spellcharges_1`, `spellppmRate_1`, `spellcooldown_1`, `spellcategory_1`, `spellcategorycooldown_1`, `spellid_2`, `spelltrigger_2`, `spellcharges_2`, `spellppmRate_2`, `spellcooldown_2`, `spellcategory_2`, `spellcategorycooldown_2`, `spellid_3`, `spelltrigger_3`, `spellcharges_3`, `spellppmRate_3`, `spellcooldown_3`, `spellcategory_3`, `spellcategorycooldown_3`, `spellid_4`, `spelltrigger_4`, `spellcharges_4`, `spellppmRate_4`, `spellcooldown_4`, `spellcategory_4`, `spellcategorycooldown_4`, `spellid_5`, `spelltrigger_5`, `spellcharges_5`, `spellppmRate_5`, `spellcooldown_5`, `spellcategory_5`, `spellcategorycooldown_5`, `bonding`, `description`, `PageText`, `LanguageID`, `PageMaterial`, `startquest`, `lockid`, `Material`, `sheath`, `RandomProperty`, `RandomSuffix`, `block`, `itemset`, `MaxDurability`, `area`, `Map`, `BagFamily`, `TotemCategory`, `socketColor_1`, `socketContent_1`, `socketColor_2`, `socketContent_2`, `socketColor_3`, `socketContent_3`, `socketBonus`, `GemProperties`, `RequiredDisenchantSkill`, `ArmorDamageModifier`, `Duration`, `ItemLimitCategory`, `HolidayId`, `ScriptName`, `DisenchantID`, `FoodType`, `minMoneyLoot`, `maxMoneyLoot`, `WDBVerified`) VALUES 
(60001, 0, 0, -1, '열세진영 지원 "?"', 15589, 6, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 지원품이 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340);
DELETE FROM `item_loot_template` WHERE `entry` IN (60001);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 옷감 240개
(60001, 2592, 100, 1, 0, 240, 240),(60001, 4306, 100, 1, 0, 240, 240),(60001, 4338, 100, 1, 0, 240, 240),(60001, 14047, 100, 1, 0, 240, 240),
-- 무법항 퀘템 가시덤불 골짜기의 푸른 언덕 "완전판"
(60001, 2725, 100, 1, 0, 1, 1),(60001, 2728, 100, 1, 0, 1, 1),(60001, 2730, 100, 1, 0, 1, 1),(60001, 2732, 100, 1, 0, 1, 1),(60001, 2734, 100, 1, 0, 1, 1),(60001, 2735, 100, 1, 0, 1, 1),(60001, 2738, 100, 1, 0, 1, 1),(60001, 2740, 100, 1, 0, 1, 1),(60001, 2742, 100, 1, 0, 1, 1),(60001, 2744, 100, 1, 0, 1, 1),(60001, 2745, 100, 1, 0, 1, 1),(60001, 2748, 100, 1, 0, 1, 1),(60001, 2749, 100, 1, 0, 1, 1),(60001, 2750, 100, 1, 0, 1, 1),(60001, 2751, 100, 1, 0, 1, 1),
-- 타나리스의 줄파락산 트롤경화제 1박스, 자동탐사 막대 1개
(60001, 9523, 100, 1, 0, 20, 20),(60001, 8548, 100, 1, 0, 1, 1),
-- 강함을 추구하는 자를 위한 영약 4종 세트
(60001, 22854, 100, 1, 0, 5, 5),
(60001, 22861, 100, 1, 0, 5, 5),
(60001, 22866, 100, 1, 0, 5, 5),
(60001, 22851, 100, 1, 0, 5, 5);
-- 배급
DELETE FROM `playercreateinfo_item` WHERE `itemid` IN (60001);
INSERT INTO `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) VALUES
-- 얼라
(1, 1, 60001, 1),(1, 2, 60001, 1),(1, 4, 60001, 1),(1, 5, 60001, 1),(1, 6, 60001, 1),(1, 8, 60001, 1),(1, 9, 60001, 1),
(3, 1, 60001, 1),(3, 2, 60001, 1),(3, 3, 60001, 1),(3, 4, 60001, 1),(3, 5, 60001, 1),(3, 6, 60001, 1),
(4, 1, 60001, 1),(4, 3, 60001, 1),(4, 4, 60001, 1),(4, 5, 60001, 1),(4, 6, 60001, 1),(4, 11, 60001, 1),
(7, 1, 60001, 1),(7, 4, 60001, 1),(7, 6, 60001, 1),(7, 8, 60001, 1),(7, 9, 60001, 1),
(11, 1, 60001, 1),(11, 2, 60001, 1),(11, 3, 60001, 1),(11, 5, 60001, 1),(11, 6, 60001, 1),(11, 7, 60001, 1),(11, 8, 60001, 1);
-- 호드
-- (2, 1, 60001, 1),(2, 3, 60001, 1),(2, 4, 60001, 1),(2, 6, 60001, 1),(2, 7, 60001, 1),(2, 9, 60001, 1),
-- (5, 1, 60001, 1),(5, 4, 60001, 1),(5, 5, 60001, 1),(5, 6, 60001, 1),(5, 8, 60001, 1),(5, 9, 60001, 1),
-- (6, 1, 60001, 1),(6, 3, 60001, 1),(6, 6, 60001, 1),(6, 7, 60001, 1),(6, 11, 60001, 1),
-- (8, 1, 60001, 1),(8, 3, 60001, 1),(8, 4, 60001, 1),(8, 5, 60001, 1),(8, 6, 60001, 1),(8, 7, 60001, 1),(8, 8, 60001, 1),
-- (10, 2, 60001, 1),(10, 3, 60001, 1),(10, 4, 60001, 1),(10, 5, 60001, 1),(10, 6, 60001, 1),(10, 8, 60001, 1),(10, 9, 60001, 1);

-- 문장팟 버프
DELETE FROM `spell_area` WHERE `spell`=16609 and `area`=4723;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_start_active`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`) VALUES
-- 얼라
(16609, 4723, 0, 0, 0, 0, 690, 2, 1);
-- 호드
-- (16609, 4723, 0, 0, 0, 0, 1101, 2, 1);
