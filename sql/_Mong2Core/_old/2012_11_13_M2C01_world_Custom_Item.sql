## 재료관련 커스텀템
-- 아제로스 재료상자:채광/채집/무두/옷감 : 100~150개 2종 회득(총 200~300개 획득 가능)
-- 아웃랜드 재료상자:채광/채집/무두/옷감 : 80~120개 1종 회득
-- 노스랜드 재료상자:채광/채집/무두/옷감 : 50~90개 1종 회득 (서리연꽃 5~10 / 엉겅퀴풀 10~20 / 티타늄 광석 20~40 / 극지가죽 5~10)
-- 아제로스 재료상자:마부 : 가루 50~100 / 상급정수 10~30 / 결정 5~10 / 마력의 결정체 1~5 / 랜덤하게 4종 획득
-- 아웃랜드 재료상자:마부 : 가루 30~80 / 상급정수 8~25 / 결정 3~8 / 공허의 수정 1~3 / 랜덤하게 3종 획득
-- 노스랜드 재료상자:마부 : 가루 15~40 / 상급정수 4~15 / 결정 1~4 / 심연의 수정 1~2 / 랜덤하게 2종 획득
-- 전 차원 원소결계 : 아제로스 20~40개 / 아웃랜드 15~30개 / 노스랜드 10~20개 / 각 차원 1종씩 총 3종 획득
-- 에픽보석 상자 : 각 에픽 보석 1~3개 2종 획득(총 2~6개 획득 가능)

-- 재판매 버그방지를 위한 초기설정
-- 에픽보석
DELETE FROM `npc_vendor` WHERE `item` IN (36919,36931,36922,36925,36928,36934); 
UPDATE `item_template` SET `SellPrice`=10000 WHERE `entry` IN (36919,36931,36922,36925,36928,36934);
-- 주요원소
DELETE FROM `npc_vendor` WHERE `item` IN (36860,35622,35623,35624,35627,35625);
UPDATE `item_template` SET `SellPrice`=100 WHERE `entry` IN (36860,35622,35623,35624,35627);
UPDATE `item_template` SET `SellPrice`=100 WHERE `entry` IN (35625); -- 영원의 생명
-- 약초
DELETE FROM `npc_vendor` WHERE `item` IN (765,2447,2449,785,2450,2453,3355,3356,3369,3357,3818,3358,3819,3820,3821,4625,8831,8836,8838,8839,8845,8846,13464,13463,13465,13466,13467,13468,22785,22786,22787,22788,22789,22790,22791,22792,22793,37921,36901,36904,36907,36905,36906,36903,36908,2452,22794);
UPDATE `item_template` SET `SellPrice`=1 WHERE `entry` IN (765,2447,2449,785,2450,2453,3355,3356,3369,3357,3818,3358,3819,3820,3821,4625,8831,8836,8838,8839,8845,8846,13464,13463,13465,13466,13467,13468,2452);
UPDATE `item_template` SET `SellPrice`=5 WHERE `entry` IN (22785,22786,22787,22788,22789,22790,22791,22792,22793);
UPDATE `item_template` SET `SellPrice`=10 WHERE `entry` IN (37921,36901,36904,36907,22794);
UPDATE `item_template` SET `SellPrice`=50 WHERE `entry` IN (36905,36906,36903);
UPDATE `item_template` SET `SellPrice`=100 WHERE `entry` IN (36908);
-- 광석
DELETE FROM `npc_vendor` WHERE `item` IN (2770,2771,2772,3858,10620,2775,2776,7911,23424,23425,23426,36909,36912,36910);
UPDATE `item_template` SET `SellPrice`=1 WHERE `entry` IN (2770,2771,2772,3858,10620,2775,2776,7911);
UPDATE `item_template` SET `SellPrice`=5 WHERE `entry` IN (23424,23425);
UPDATE `item_template` SET `SellPrice`=10 WHERE `entry` IN (23426,36909);
UPDATE `item_template` SET `SellPrice`=50 WHERE `entry` IN (36912);
UPDATE `item_template` SET `SellPrice`=100 WHERE `entry` IN (36910);
-- 옷감
DELETE FROM `npc_vendor` WHERE `item` IN (2589,2592,4306,4338,14047,21877,33407);
UPDATE `item_template` SET `SellPrice`=1 WHERE `entry` IN (2589,2592,4306,4338,14047);
UPDATE `item_template` SET `SellPrice`=5 WHERE `entry` IN (21877);
UPDATE `item_template` SET `SellPrice`=10 WHERE `entry` IN (33407);
-- 가죽
DELETE FROM `npc_vendor` WHERE `item` IN (783,2318,2319,4232,4234,4235,4304,8154,8165,8169,8170,15412,15415,15416,21887,25649,25699,25700,25707,25708,29539,29547,29548,33567,33567,33568,38557,38558,38561,44128);
UPDATE `item_template` SET `SellPrice`=1 WHERE `entry` IN (783,2318,2319,4232,4234,4235,4304,8154,8165,8169,8170,15412,15415,15416);
UPDATE `item_template` SET `SellPrice`=5 WHERE `entry` IN (21887,25649,25699,25700,25707,25708,29539,29547,29548);
UPDATE `item_template` SET `SellPrice`=10 WHERE `entry` IN (33567,33568,38557,38558,38561);
UPDATE `item_template` SET `SellPrice`=100 WHERE `entry` IN (44128);

-- 커스텀 아이템 및 색상 변경
DELETE FROM `item_template` WHERE `entry` IN (32543,32544,32545,32546,32547,22124,22125,22126,22127,22129,21969,21970,21971,21972,21973,34156,34548);
INSERT INTO `item_template` (`entry`, `class`, `subclass`, `SoundOverrideSubclass`, `name`, `displayid`, `Quality`, `Flags`, `FlagsExtra`, `BuyCount`, `BuyPrice`, `SellPrice`, `InventoryType`, `AllowableClass`, `AllowableRace`, `ItemLevel`, `RequiredLevel`, `RequiredSkill`, `RequiredSkillRank`, `requiredspell`, `requiredhonorrank`, `RequiredCityRank`, `RequiredReputationFaction`, `RequiredReputationRank`, `maxcount`, `stackable`, `ContainerSlots`, `StatsCount`, `stat_type1`, `stat_value1`, `stat_type2`, `stat_value2`, `stat_type3`, `stat_value3`, `stat_type4`, `stat_value4`, `stat_type5`, `stat_value5`, `stat_type6`, `stat_value6`, `stat_type7`, `stat_value7`, `stat_type8`, `stat_value8`, `stat_type9`, `stat_value9`, `stat_type10`, `stat_value10`, `ScalingStatDistribution`, `ScalingStatValue`, `dmg_min1`, `dmg_max1`, `dmg_type1`, `dmg_min2`, `dmg_max2`, `dmg_type2`, `armor`, `holy_res`, `fire_res`, `nature_res`, `frost_res`, `shadow_res`, `arcane_res`, `delay`, `ammo_type`, `RangedModRange`, `spellid_1`, `spelltrigger_1`, `spellcharges_1`, `spellppmRate_1`, `spellcooldown_1`, `spellcategory_1`, `spellcategorycooldown_1`, `spellid_2`, `spelltrigger_2`, `spellcharges_2`, `spellppmRate_2`, `spellcooldown_2`, `spellcategory_2`, `spellcategorycooldown_2`, `spellid_3`, `spelltrigger_3`, `spellcharges_3`, `spellppmRate_3`, `spellcooldown_3`, `spellcategory_3`, `spellcategorycooldown_3`, `spellid_4`, `spelltrigger_4`, `spellcharges_4`, `spellppmRate_4`, `spellcooldown_4`, `spellcategory_4`, `spellcategorycooldown_4`, `spellid_5`, `spelltrigger_5`, `spellcharges_5`, `spellppmRate_5`, `spellcooldown_5`, `spellcategory_5`, `spellcategorycooldown_5`, `bonding`, `description`, `PageText`, `LanguageID`, `PageMaterial`, `startquest`, `lockid`, `Material`, `sheath`, `RandomProperty`, `RandomSuffix`, `block`, `itemset`, `MaxDurability`, `area`, `Map`, `BagFamily`, `TotemCategory`, `socketColor_1`, `socketContent_1`, `socketColor_2`, `socketContent_2`, `socketColor_3`, `socketContent_3`, `socketBonus`, `GemProperties`, `RequiredDisenchantSkill`, `ArmorDamageModifier`, `Duration`, `ItemLimitCategory`, `HolidayId`, `ScriptName`, `DisenchantID`, `FoodType`, `minMoneyLoot`, `maxMoneyLoot`, `WDBVerified`) VALUES 
(32543, 15, 0, -1, '#아제로스 재료상자 : 채집', 12333, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(32544, 15, 0, -1, '#아제로스 재료상자 : 채광', 12333, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(32545, 15, 0, -1, '#아제로스 재료상자 : 옷감', 12333, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(32546, 15, 0, -1, '#아제로스 재료상자 : 무두', 12333, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(32547, 15, 0, -1, '#아제로스 재료상자 : 마력결정', 12333, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(22124, 15, 0, -1, '#아웃랜드 재료상자 : 채집', 15589, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(22125, 15, 0, -1, '#아웃랜드 재료상자 : 채광', 15589, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(22126, 15, 0, -1, '#아웃랜드 재료상자 : 옷감', 15589, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(22127, 15, 0, -1, '#아웃랜드 재료상자 : 무두', 15589, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(22129, 15, 0, -1, '#아웃랜드 재료상자 : 마력결정', 15589, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(21969, 15, 0, -1, '#노스랜드 재료상자 : 채집', 34490, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(21970, 15, 0, -1, '#노스랜드 재료상자 : 채광', 34490, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(21971, 15, 0, -1, '#노스랜드 재료상자 : 옷감', 34490, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(21972, 15, 0, -1, '#노스랜드 재료상자 : 무두', 34490, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(21973, 15, 0, -1, '#노스랜드 재료상자 : 마력결정', 34490, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(34156, 15, 0, -1, '#전 차원 원소 결계 주머니', 47512, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340),
(34548, 15, 0, -1, '#틑어진 보석 주머니', 12644, 5, 4, 0, 1, 0, 0, 0, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, '실수로 창을 닫으면 상자가 사라집니다.', 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, '', 0, 0, 0, 0, 12340);
UPDATE `item_template` SET `Quality`=5 WHERE `entry` IN (32543,32544,32545,32546,32547,22124,22125,22126,22127,22129,21969,21970,21971,21972,21973,34156,34548);

-- 커스텀 상자 세팅
DELETE FROM `item_loot_template` WHERE `entry` IN (32543,32544,32545,32546,32547,22124,22125,22126,22127,22129,21969,21970,21971,21972,21973,34156,34548);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 에픽보석 주머니
(34548,1,100,1,0,-90007,2),
-- 아제로스 상자
(32543,1,100,1,0,-90008,2),(32544,1,100,1,0,-90009,2),(32545,1,100,1,0,-90010,2),(32546,1,100,1,0,-90011,2),(32547,1,100,1,0,-90025,4),
-- 아웃랜드 상자
(22124,1,100,1,0,-90012,1),(22125,1,100,1,0,-90013,1),(22126,1,100,1,0,-90014,1),(22127,1,100,1,0,-90015,1),(22129,1,100,1,0,-90026,3),
-- 노스랜드 상자
(21969,1,100,1,0,-90016,1),(21970,1,100,1,0,-90018,1),(21971,1,100,1,0,-90020,1),(21972,1,100,1,0,-90021,1),(21973,1,100,1,0,-90027,2),
-- 전 차원 원소결계
(34156,1,100,1,0,-90022,1),(34156,2,100,1,0,-90023,1),(34156,3,100,1,0,-90024,1);

-- 룻테이블 세팅
DELETE FROM `reference_loot_template` WHERE `entry` IN (90001,90002,90003,90004,90005,90006,90007,90008,90009,90010,90011,90012,90013,90014,90015,90016,90017,90018,90019,90020,90021,90022,90023,90024,90025,90026,90027);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
-- 승전문장 판매템 (공통)
(90001,47667,0,1,1,1,1),(90001,47666,0,1,1,1,1),(90001,47665,0,1,1,1,1),(90001,47673,0,1,1,1,1),(90001,47672,0,1,1,1,1),(90001,47662,0,1,1,1,1),(90001,47661,0,1,1,1,1),(90001,47664,0,1,1,1,1),(90001,47668,0,1,1,1,1),(90001,47671,0,1,1,1,1),(90001,47659,0,1,1,1,1),(90001,47658,0,1,1,1,1),(90001,47660,0,1,1,1,1),(90001,47733,0,1,1,1,1),(90001,47730,0,1,1,1,1),(90001,47731,0,1,1,1,1),(90001,47729,0,1,1,1,1),(90001,47732,0,1,1,1,1),(90001,48724,0,1,1,1,1),(90001,48722,0,1,1,1,1),(90001,47734,0,1,1,1,1),(90001,47735,0,1,1,1,1),
-- 승전문장 판매템 (진영구분 있는 것)
(90002,47712,0,1,1,1,1),(90002,47698,0,1,1,1,1),(90002,47702,0,1,1,1,1),(90002,47697,0,1,1,1,1),(90002,47715,0,1,1,1,1),(90002,47707,0,1,1,1,1),(90002,47713,0,1,1,1,1),(90002,47704,0,1,1,1,1),(90002,47708,0,1,1,1,1),(90002,47689,0,1,1,1,1),(90002,47693,0,1,1,1,1),(90002,47685,0,1,1,1,1),(90002,47686,0,1,1,1,1),(90002,47674,0,1,1,1,1),(90002,47694,0,1,1,1,1),(90002,47690,0,1,1,1,1),(90002,47681,0,1,1,1,1),(90002,47677,0,1,1,1,1),(90002,47706,0,1,2,1,1),(90002,47701,0,1,2,1,1),(90002,47696,0,1,2,1,1),(90002,47699,0,1,2,1,1),(90002,47705,0,1,2,1,1),(90002,47714,0,1,2,1,1),(90002,47716,0,1,2,1,1),(90002,47710,0,1,2,1,1),(90002,47709,0,1,2,1,1),(90002,47688,0,1,2,1,1),(90002,47691,0,1,2,1,1),(90002,47692,0,1,2,1,1),(90002,47695,0,1,2,1,1),(90002,47682,0,1,2,1,1),(90002,47678,0,1,2,1,1),(90002,47687,0,1,2,1,1),(90002,47675,0,1,2,1,1),(90002,47684,0,1,2,1,1),
-- 냉혹1차무기 + 보조장비
(90003,42329,0,1,1,1,1),(90003,49189,0,1,1,1,1),(90003,42354,0,1,1,1,1),(90003,42386,0,1,1,1,1),(90003,42334,0,1,1,1,1),(90003,42229,0,1,1,1,1),(90003,42287,0,1,1,1,1),(90003,42234,0,1,1,1,1),(90003,42250,0,1,1,1,1),(90003,42521,0,1,1,1,1),(90003,42483,0,1,1,1,1),(90003,42504,0,1,1,1,1),(90003,42498,0,1,1,1,1),(90003,42272,0,1,1,1,1),(90003,42210,0,1,1,1,1),(90003,42244,0,1,1,1,1),(90003,42262,0,1,1,1,1),(90003,42324,0,1,1,1,1),(90003,42292,0,1,1,1,1),(90003,42267,0,1,1,1,1),(90003,42348,0,1,1,1,1),(90003,44424,0,1,1,1,1),(90003,42319,0,1,1,1,1),(90003,42366,0,1,1,1,1),(90003,42515,0,1,1,1,1),(90003,42257,0,1,1,1,1),(90003,42282,0,1,1,1,1),(90003,42487,0,1,1,1,1),(90003,44423,0,1,1,1,1),(90003,42277,0,1,1,1,1),(90003,49185,0,1,1,1,1),(90003,42492,0,1,1,1,1),(90003,42392,0,1,1,1,1),(90003,42566,0,1,1,1,1),(90003,42539,0,1,1,1,1),(90003,49187,0,1,1,1,1),(90003,42533,0,1,1,1,1),(90003,42616,0,1,1,1,1),(90003,42527,0,1,1,1,1),(90003,42580,0,1,1,1,1),(90003,42609,0,1,1,1,1),(90003,42572,0,1,1,1,1),(90003,42854,0,1,1,1,1),(90003,42561,0,1,1,1,1),(90003,42599,0,1,1,1,1),(90003,42604,0,1,1,1,1),(90003,42585,0,1,1,1,1),(90003,42591,0,1,1,1,1),(90003,42622,0,1,1,1,1),
-- 냉혹 2차무기
(90004,48523,0,1,1,1,1),(90004,49191,0,1,1,1,1),(90004,48406,0,1,1,1,1),(90004,48507,0,1,1,1,1),(90004,48440,0,1,1,1,1),(90004,48519,0,1,1,1,1),(90004,48521,0,1,1,1,1),(90004,48412,0,1,1,1,1),(90004,48404,0,1,1,1,1),(90004,48420,0,1,1,1,1),(90004,48408,0,1,1,1,1),(90004,48402,0,1,1,1,1),(90004,48509,0,1,1,1,1),(90004,48442,0,1,1,1,1),(90004,48517,0,1,1,1,1),(90004,48428,0,1,1,1,1),(90004,48424,0,1,1,1,1),(90004,48410,0,1,1,1,1),(90004,48414,0,1,1,1,1),(90004,48426,0,1,1,1,1),(90004,48515,0,1,1,1,1),(90004,48444,0,1,1,1,1),(90004,48432,0,1,1,1,1),(90004,48435,0,1,1,1,1),(90004,48513,0,1,1,1,1),(90004,48422,0,1,1,1,1),(90004,48438,0,1,1,1,1),(90004,48511,0,1,1,1,1),
-- 드랍용 탈것/팻
(90005,11026,0,1,1,1,1),(90005,11027,0,1,1,1,1),(90005,48126,0,1,1,1,1),(90005,48118,0,1,1,1,1),(90005,48112,0,1,1,1,1),(90005,48124,0,1,1,1,1),(90005,48122,0,1,1,1,1),(90005,48114,0,1,1,1,1),(90005,48116,0,1,1,1,1),(90005,33993,0,1,1,1,1),(90005,31760,0,1,1,1,1),(90005,11110,0,1,1,1,1),(90005,12264,0,1,1,1,1),(90005,12529,0,1,1,1,1),(90005,27445,0,1,1,1,1),(90005,43698,0,1,1,1,1),(90005,44983,0,1,1,1,1),(90005,33816,0,1,1,1,1),(90005,35350,0,1,1,1,1),(90005,35349,0,1,1,1,1),(90005,33818,0,1,1,1,1),(90005,33976,0,1,1,1,1),(90005,21218,0,1,1,1,1),(90005,21323,0,1,1,1,1),(90005,21324,0,1,1,1,1),(90005,43962,0,1,1,1,1),(90005,43951,0,1,1,1,1),(90005,33977,0,1,1,1,1),(90005,33809,0,1,1,1,1),(90005,21321,0,1,1,1,1),(90005,37012,0,1,1,1,1),(90005,46109,0,1,1,1,1),(90005,49283,0,1,1,1,1),(90005,49285,0,1,1,1,1),
-- 3등급 탈것/팻
(90006,39973,0,1,1,1,1),(90006,44721,0,1,1,1,1),(90006,39898,0,1,1,1,1),(90006,39899,0,1,1,1,1),(90006,39896,0,1,1,1,1),(90006,10398,0,1,1,1,1),(90006,11474,0,1,1,1,1),(90006,8492,0,1,1,1,1),(90006,8494,0,1,1,1,1),(90006,8498,0,1,1,1,1),(90006,8499,0,1,1,1,1),(90006,10822,0,1,1,1,1),(90006,34535,0,1,1,1,1),(90006,20769,0,1,1,1,1),(90006,29960,0,1,1,1,1),(90006,44738,0,1,1,1,1),(90006,46544,0,1,1,1,1),(90006,46545,0,1,1,1,1),(90006,50446,0,1,1,1,1),(90006,22235,0,1,1,1,1),(90006,23002,0,1,1,1,1),(90006,23015,0,1,1,1,1),(90006,23007,0,1,1,1,1),(90006,32616,0,1,1,1,1),(90006,32617,0,1,1,1,1),(90006,32622,0,1,1,1,1),(90006,19450,0,1,1,1,1),(90006,23083,0,1,1,1,1),(90006,34955,0,1,1,1,1),(90006,32233,0,1,1,1,1),(90006,46707,0,1,1,1,1),(90006,33154,0,1,1,1,1),(90006,21301,0,1,1,1,1),(90006,21305,0,1,1,1,1),(90006,21308,0,1,1,1,1),(90006,21309,0,1,1,1,1),(90006,44794,0,1,1,1,1),(90006,44810,0,1,1,1,1),(90006,37719,0,1,1,1,1),(90006,44707,0,1,1,1,1),(90006,44151,0,1,1,1,1),(90006,43953,0,1,1,1,1),(90006,43952,0,1,1,1,1),(90006,44168,0,1,1,1,1),(90006,44160,0,1,1,1,1),(90006,19902,0,1,1,1,1),(90006,19872,0,1,1,1,1),(90006,30480,0,1,1,1,1),(90006,23720,0,1,1,1,1),(90006,49282,0,1,1,1,1),(90006,43986,0,1,1,1,1),(90006,43954,0,1,1,1,1),(90006,13335,0,1,1,1,1),(90006,32768,0,1,1,1,1),(90006,35513,0,1,1,1,1),(90006,37828,0,1,1,1,1),
-- 에픽보석
(90007,36919,0,1,1,1,3),(90007,36931,0,1,1,1,3),(90007,36922,0,1,1,1,3),(90007,36925,0,1,1,1,3),(90007,36928,0,1,1,1,3),(90007,36934,0,1,1,1,3),(90007,43102,0,1,1,1,3),
-- 아제로스 약초
(90008,765,0,1,1,100,150),(90008,2447,0,1,1,100,150),(90008,2449,0,1,1,100,150),(90008,785,0,1,1,100,150),(90008,2450,0,1,1,100,150),(90008,2453,0,1,1,100,150),(90008,3355,0,1,1,100,150),(90008,3356,0,1,1,100,150),(90008,3369,0,1,1,100,150),(90008,3357,0,1,1,100,150),(90008,3818,0,1,1,100,150),(90008,3358,0,1,1,100,150),(90008,3819,0,1,1,100,150),(90008,3820,0,1,1,100,150),(90008,3821,0,1,1,100,150),(90008,4625,0,1,1,100,150),(90008,8831,0,1,1,100,150),(90008,8836,0,1,1,100,150),(90008,8838,0,1,1,100,150),(90008,8839,0,1,1,100,150),(90008,8845,0,1,1,100,150),(90008,8846,0,1,1,100,150),(90008,13464,0,1,1,100,150),(90008,13463,0,1,1,100,150),(90008,13465,0,1,1,100,150),(90008,13466,0,1,1,100,150),(90008,13467,0,1,1,100,150),(90008,13468,0,1,1,100,150),
-- 아제로스 광물
(90009,2770,0,1,1,100,150),(90009,2771,0,1,1,100,150),(90009,2772,0,1,1,100,150),(90009,3858,0,1,1,100,150),(90009,10620,0,1,1,100,150),(90009,2775,0,1,1,100,150),(90009,2776,0,1,1,100,150),(90009,7911,0,1,1,100,150),
-- 아제로스 옷감
(90010,2589,0,1,1,100,150),(90010,2592,0,1,1,100,150),(90010,4306,0,1,1,100,150),(90010,4338,0,1,1,100,150),(90010,14047,0,1,1,100,150),
-- 아제로스 가죽
(90011,783,0,1,1,100,150),(90011,2318,0,1,1,100,150),(90011,2319,0,1,1,100,150),(90011,4232,0,1,1,100,150),(90011,4234,0,1,1,100,150),(90011,4235,0,1,1,100,150),(90011,4304,0,1,1,100,150),(90011,8154,0,1,1,100,150),(90011,8165,0,1,1,100,150),(90011,8169,0,1,1,100,150),(90011,8170,0,1,1,100,150),(90011,15412,0,1,1,100,150),(90011,15415,0,1,1,100,150),(90011,15416,0,1,1,100,150),
-- 아웃랜드 약초
(90012,22785,0,1,1,80,120),(90012,22786,0,1,1,80,120),(90012,22787,0,1,1,80,120),(90012,22788,0,1,1,80,120),(90012,22789,0,1,1,80,120),(90012,22790,0,1,1,80,120),(90012,22791,0,1,1,80,120),(90012,22792,0,1,1,80,120),(90012,22793,0,1,1,80,120),
-- 아웃랜드 광물
(90013,23424,0,1,1,80,120),(90013,23425,0,1,1,80,120),(90013,23426,0,1,1,80,120),
-- 아웃랜드 옷감
(90014,21877,0,1,1,80,120),
-- 아웃랜드 가죽
(90015,21887,0,1,1,80,120),(90015,25649,0,1,1,80,120),(90015,25699,0,1,1,80,120),(90015,25700,0,1,1,80,120),(90015,25707,0,1,1,80,120),(90015,25708,0,1,1,80,120),(90015,29539,0,1,1,80,120),(90015,29547,0,1,1,80,120),(90015,29548,0,1,1,80,120),
-- 노스랜드 약초
(90016,37921,0,1,1,60,90),(90016,36901,0,1,1,60,90),(90016,36904,0,1,1,60,90),(90016,36907,0,1,1,60,90),(90016,22794,0,1,1,60,90),(90016,36905,0,1,1,60,90),(90016,36906,0,1,1,60,90),(90016,36903,0,1,1,60,90),(90016,36908,0,1,1,5,10),(90016,2452,0,1,1,10,20),
-- 노스랜드 광물
(90018,36909,0,1,1,60,90),(90018,36912,0,1,1,60,90),(90018,36910,0,1,1,20,40),
-- 노스랜드 옷감
(90020,33470,0,1,1,60,90),
-- 노스랜드 가죽
(90021,33567,0,1,1,60,90),(90021,33568,0,1,1,60,90),(90021,38557,0,1,1,60,90),(90021,38558,0,1,1,60,90),(90021,38561,0,1,1,60,90),(90021,44128,0,1,1,5,10),
-- 아제로스 원소
(90022,7076,0,1,1,20,40),(90022,7078,0,1,1,20,40),(90022,7080,0,1,1,20,40),(90022,7082,0,1,1,20,40),
-- 아웃랜드 원소
(90023,22572,0,1,1,15,30),(90023,22573,0,1,1,15,30),(90023,22574,0,1,1,15,30),(90023,22575,0,1,1,15,30),(90023,22576,0,1,1,15,30),(90023,22577,0,1,1,15,30),(90023,22578,0,1,1,15,30),
-- 노스랜드 원소
(90024,36860,0,1,1,10,20),(90024,35622,0,1,1,10,20),(90024,35623,0,1,1,10,20),(90024,35624,0,1,1,10,20),(90024,35627,0,1,1,10,20),(90024,35625,0,1,1,10,20),
-- 아제로스 마법결정
(90025,10940,0,1,1,50,100),(90025,11083,0,1,1,50,100),(90025,11137,0,1,1,50,100),(90025,11176,0,1,1,50,100),(90025,16204,0,1,1,50,100),(90025,10939,0,1,1,10,30),(90025,11082,0,1,1,10,30),(90025,11135,0,1,1,10,30),(90025,11175,0,1,1,10,30),(90025,16203,0,1,1,10,30),(90025,10978,0,1,1,5,10),(90025,11138,0,1,1,5,10),(90025,11177,0,1,1,5,10),(90025,14343,0,1,1,5,10),(90025,11084,0,1,1,5,10),(90025,11139,0,1,1,5,10),(90025,11178,0,1,1,5,10),(90025,14344,0,1,1,5,10),(90025,20725,0,1,1,1,5),
-- 아웃랜드 마법결정
(90026,22446,0,1,1,30,80),(90026,22445,0,1,1,8,25),(90026,22448,0,1,1,12,24),(90026,22449,0,1,1,3,8),(90026,22450,0,1,1,1,3),
-- 노스랜드 마법결정
(90027,34055,0,1,1,15,40),(90027,34054,0,1,1,4,15),(90027,34053,0,1,1,3,12),(90027,34052,0,1,1,1,4),(90027,34057,0,1,1,1,2);