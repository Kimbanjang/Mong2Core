# 도적 
-- 눈속/속거 버그 수정
DELETE FROM `spell_proc_event` WHERE `entry` IN (34477,57934);
INSERT INTO `spell_proc_event` (`entry`,`procflags`,`CustomChance`) VALUES
(34477,0x211154,100), -- Misdirection
(57934,0x000154,100); -- ToT

# 드루이드
-- 나무껍질 제대로 구현
DELETE FROM `spell_proc_event` WHERE `entry`='22812';
INSERT INTO `spell_proc_event` VALUES (22812,0,0,0,0,0,0,3,0,0,0);
-- 암습피해 전투력 보정 수정
DELETE FROM `spell_bonus_data` WHERE `entry`='9007';
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES ('9007','0','0','0','0.03','Druid - Pounce ($AP*0.18 / number of ticks)');
-- 광폭 구현
DELETE FROM `spell_script_names` WHERE `spell_id`='50334';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (50334, 'spell_dru_berserk');
/*
-- 별똥별 주문력 보정 수정
DELETE FROM `spell_bonus_data` WHERE `comments` LIKE "Druid - Starfall%";
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES ('50294','0.13','0','0','0','Druid - Starfall AOE rank 1'),('53188','0.13','0','0','0','Druid - Starfall AOE rank 2'),('53189','0.13','0','0','0','Druid - Starfall AOE rank 3'),('53190','0.13','0','0','0','Druid - Starfall AOE rank 4'),('50288','0.3','0','0','0','Druid - Starfall rank 1'),('53191','0.3','0','0','0','Druid - Starfall rank 2'),('53194','0.3','0','0','0','Druid - Starfall rank 3'),('53195','0.3','0','0','0','Druid - Starfall rank 4');
-- 휘둘려 치기 수정 (주문력으로 보정 들어가던것 전투력으로 수정)
UPDATE spell_bonus_data SET direct_bonus = 0, dot_bonus = 0, ap_bonus = 0.063, ap_dot_bonus = 0 WHERE entry = 779;
*/

# 마법사
/*
-- 화살탄막 제대로 구현
UPDATE `spell_proc_event` SET `Cooldown`='5' WHERE `entry` IN (44404,54486,54488,54489,54490);
UPDATE `spell_proc_event` SET `CustomChance`='40' WHERE `entry` IN (44404,54486,54488,54489,54490);
-- 투명화 제대로 구현
DELETE FROM `spell_linked_spell` WHERE `spell_effect`='54661' AND `spell_trigger` IN (32612,5215,1784,1856);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES ('32612', '54661', '0', 'Invisibility Sanctuary Effect'),('5215', '54661', '0', 'Prowl Sanctuary Effect'),('1784', '54661', '0', 'Stealth Sanctuary Effect'),('1856', '54661', '0', 'Stealth Sanctuary Effect');
*/

# 전사
-- 복수 보너스 데미지 바르게 수정(0.21 -> 0.31 버프)
DELETE FROM `spell_bonus_data` WHERE `entry`='6572';
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES (6572, -1, -1, 0.31, -1, 'Warrior - Revenge');
-- 피의 맛 분쇄로만 발동
UPDATE `spell_proc_event` SET `procEx`=0x40000 WHERE entry IN (56636, 56637, 56638);
/*
-- T8 방어 4피스 보너스 효과 구현
DELETE FROM `spell_dbc` WHERE `Id`='64934';
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`, `Comment`) VALUES ('64934', '1', '0', '384', '0', '0', '0', '0', '131080', '0', '0', '0', '1', '0', '0', '101', '0', '0', '80', '80', '1', '1', '0', '-1', '0', '0', '6', '0', '0', '1', '0', '1', '0', '0', '0', '-21', '0', '-11', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '87', '0', '0', '0', '0', '0', '0', '0', '0', '126', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '16777829', '0', '0', '0', '15', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '32', 'Item - Warrior T8 Protection 4P Bonus');
*/

# 주술사 
-- 전기 보호막 데미지 바르게 수정(0.33 -> 0.267 너프)
DELETE FROM `spell_bonus_data` WHERE `entry`='26364';
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES (26364, 0.267, -1, -1, -1, 'Shaman - Lightning Shield Proc');
-- 대지의 보호막(974-소폭 너프), 치유의 토템(52042-2배 버프), 성난해일(61295-소폭 버프) 수정
DELETE FROM `spell_bonus_data` WHERE `entry` IN ('974','52042','61295');
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES (61295, 0.402, 0.188, -1, -1, 'Shaman - Riptide'),(974, 0.538, -1, -1, -1, 'Shaman - Earth Shield'),(52042, 0.08272, -1, -1, -1, 'Shaman - Healing Stream Totem Triggered Heal');
-- 정기의 집중 힐링웨이브 류에는 발동하지 않게 수정
UPDATE `spell_proc_event` SET `SpellFamilyMask0`=0x90100003 WHERE `entry`='16164';
-- 야수정령의 오라, 정령의 걸음 디스펠 되지 않게 수정
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`='58875';
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUE ('58875', '58876', '2', 'Spirit Walk - Immunity');
-- 격노의 토템 크리버프 구현
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (57658,57660,57662,57663);
INSERT INTO `spell_linked_spell` VALUES ('57658', '30708', '0', 'Totem of Wrath crit (rank1)'),('57660', '30708', '0', 'Totem of Wrath crit (rank2)'),('57662', '30708', '0', 'Totem of Wrath crit (rank3)'),('57663', '30708', '0', 'Totem of Wrath crit (rank4)');
-- 힐토템 수정
DELETE FROM `spell_bonus_data` WHERE `entry` IN (52042,5672);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`,`ap_bonus`, `ap_dot_bonus`, `comments`) VALUES ('5672','0.0827','-1','-1','-1','Shaman - Healing Stream Totem Rank 1');

# 죽음의 기사
-- 피 묻은 칼날 수정(무한발동 -> 본섭구현)
DELETE FROM `spell_proc_event` WHERE `entry`='49219';
INSERT INTO `spell_proc_event` VALUES (49219,0,15,0,0,0,4,0,0,10,0);
-- 도살기 수정(무한발동 -> 본섭구현)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51123,51127,51128,51129,51130);
INSERT INTO `spell_proc_event` VALUES (51123,0,15,0,0,0,20,0,0,15,0),(51127,0,15,0,0,0,20,0,0,20,0),(51128,0,15,0,0,0,20,0,0,25,0),(51129,0,15,0,0,0,20,0,0,30,0),(51130,0,15,0,0,0,20,0,0,35,0);
-- 작열하는 분노 전투력 보정 수정 (0.1 -> 0.2 버프)
DELETE FROM `spell_bonus_data` WHERE `entry`='49184';
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES ('49184','-1','-1','0.2','-1','Death Knight - Howling Blast');
-- 잿더미 빙하 툴팁의 스킬에만 발동하도록 
UPDATE `spell_proc_event` SET `SpellFamilyName`='15', `SpellFamilyMask0`=0x42002, `SpellFamilyMask1`=0x6, `SpellFamilyMask2`=0x80 WHERE `entry`='53386';
-- 구울 가고일 이뮨설정 바르게 수정
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|0x00000010 WHERE `entry` IN (27829,26125);
/*
-- 황폐화 구현
DELETE FROM `spell_proc_event` WHERE `entry` IN (66799,66814,66815,66816);
INSERT INTO `spell_proc_event` VALUES (66799,5,15,4194304,0,0,0,0,0,100,0),(66814,5,15,4194304,0,0,0,0,0,100,0),(66815,5,15,4194304,0,0,0,0,0,100,0),(66816,5,15,4194304,0,0,0,0,0,100,0);
-- 시체 되살리기 스킬 픽스
DELETE FROM `spell_script_names` WHERE `spell_id`='46584';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (46584, 'spell_dk_raise_dead');
-- 뼈보호막 수정
DELETE FROM `spell_dbc` WHERE `Id`='250000';
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`, `Comment`) VALUES (250000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 1, 0, -1, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 'Bone Shield Charges Cooldown');
DELETE FROM `spell_proc_event` WHERE `entry`='49222';
INSERT INTO `spell_proc_event` VALUES (49222,0,0,0,0,0,1048576,0,0,0,3);
-- 괴사 수정
DELETE FROM `spell_proc_event` WHERE `entry` IN (51459,51462,51463,51464,51465);
INSERT INTO `spell_proc_event` VALUES (51459,0,15,0,0,0,4,0,0,100,0),(51462,0,15,0,0,0,4,0,0,100,0),(51463,0,15,0,0,0,4,0,0,100,0),(51464,0,15,0,0,0,4,0,0,100,0),(51465,0,15,0,0,0,4,0,0,100,0);
*/

# 사냥꾼

# 사제 
-- 불행 툴팁의 스킬에만 적용 되도록 수정
DELETE FROM `spell_proc_event` WHERE `entry` IN (33191,33192,33193);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES ('33191','0','6', 0x808000, 0x400, 0x40,'0','0','0','0','0'),('33192','0','6', 0x808000, 0x400, 0x40,'0','0','0','0','0'),('33193','0','6', 0x808000, 0x400, 0x40,'0','0','0','0','0');

# 성기사 
-- 정신집중 연마 오라 수정
DELETE FROM `spell_linked_spell` WHERE `spell_effect` IN (-63510,63510);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES ('465', '63510', '2', 'Improved Concentration Aura linked spell'),('643', '63510', '2', 'Improved Concentration Aura linked spell'),('1032', '63510', '2', 'Improved Concentration Aura linked spell'),('7294', '63510', '2', 'Improved Concentration Aura linked spell'),('10290', '63510', '2', 'Improved Concentration Aura linked spell'),('10291', '63510', '2', 'Improved Concentration Aura linked spell'),('10292', '63510', '2', 'Improved Concentration Aura linked spell'),('10293', '63510', '2', 'Improved Concentration Aura linked spell'),('10298', '63510', '2', 'Improved Concentration Aura linked spell'),('10299', '63510', '2', 'Improved Concentration Aura linked spell'),('10300', '63510', '2', 'Improved Concentration Aura linked spell'),('10301', '63510', '2', 'Improved Concentration Aura linked spell'),('19746', '63510', '2', 'Improved Concentration Aura linked spell'),('19876', '63510', '2', 'Improved Concentration Aura linked spell'),('19888', '63510', '2', 'Improved Concentration Aura linked spell'),('19891', '63510', '2', 'Improved Concentration Aura linked spell'),('19895', '63510', '2', 'Improved Concentration Aura linked spell'),('19896', '63510', '2', 'Improved Concentration Aura linked spell'),('19897', '63510', '2', 'Improved Concentration Aura linked spell'),('19898', '63510', '2', 'Improved Concentration Aura linked spell'),('19899', '63510', '2', 'Improved Concentration Aura linked spell'),('19900', '63510', '2', 'Improved Concentration Aura linked spell'),('27149', '63510', '2', 'Improved Concentration Aura linked spell'),('27150', '63510', '2', 'Improved Concentration Aura linked spell'),('27151', '63510', '2', 'Improved Concentration Aura linked spell'),('27152', '63510', '2', 'Improved Concentration Aura linked spell'),('27153', '63510', '2', 'Improved Concentration Aura linked spell'),('32223', '63510', '2', 'Improved Concentration Aura linked spell'),('48941', '63510', '2', 'Improved Concentration Aura linked spell'),('48942', '63510', '2', 'Improved Concentration Aura linked spell'),('48943', '63510', '2', 'Improved Concentration Aura linked spell'),('48945', '63510', '2', 'Improved Concentration Aura linked spell'),('48947', '63510', '2', 'Improved Concentration Aura linked spell'),('54043', '63510', '2', 'Improved Concentration Aura linked spell');
-- 빛의 문장 발동 너프 (20PPM 에서 15Chance 로 수정)
UPDATE `spell_proc_event` SET `ppmRate`='0',`CustomChance`='15' WHERE `entry`='20165';
-- 정방 수정
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_righteous_defense';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (31789,'spell_pal_righteous_defense');
-- 성축 수정
DELETE FROM `spell_dbc` WHERE `id`='20912';
INSERT INTO `spell_dbc` (`Id`,`CastingTimeIndex`,`DurationIndex`,`RangeIndex`,`Effect1`,`EffectBasePoints1`,`EffectImplicitTargetA1`,`EffectApplyAuraName1`,`EffectMiscValue1`,`SpellFamilyName`,`Comment`) VALUES (20912,1,21,1,6,-3,1,87,127,10,'Blessing of Sanctuary Helper (SERVERSIDE)');
-- 성축 중복적용 수정
UPDATE `spell_group` SET `spell_id`='68066' WHERE `id`='1091' and `spell_id`='47930';
UPDATE `spell_group` SET `spell_id`='20912' WHERE `id`='1092' and `spell_id`='20911';
-- 성전사의 심장 구현
UPDATE `spell_proc_event` SET `procFlags`='272', `CustomChance`='100' WHERE `entry` IN (53695,53696,20335,20336,20337);
/*
-- T8 신성 2셋 보너스 효과 구현
DELETE FROM `spell_bonus_data` WHERE `entry`='64891';
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES ('64891','0','0','0','0','Paladin T8 Holy 2P Bonus');
*/

# 흑마법사
-- 임프 마나
UPDATE `pet_levelstats` SET `mana`='65000' WHERE `creature_entry`='416' and `level`='80';
