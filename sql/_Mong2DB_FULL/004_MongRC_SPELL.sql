# 도적 
-- 눈속/속거 버그 수정
DELETE FROM `spell_proc_event` WHERE `entry` IN (34477,57934);
INSERT INTO `spell_proc_event` (`entry`,`procflags`,`CustomChance`) VALUES
(34477,0x211154,100), -- Misdirection
(57934,0x000154,100); -- ToT

# 드루이드
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
/*
-- T8 방어 4피스 보너스 효과 구현
DELETE FROM `spell_dbc` WHERE `Id`='64934';
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`, `Comment`) VALUES ('64934', '1', '0', '384', '0', '0', '0', '0', '131080', '0', '0', '0', '1', '0', '0', '101', '0', '0', '80', '80', '1', '1', '0', '-1', '0', '0', '6', '0', '0', '1', '0', '1', '0', '0', '0', '-21', '0', '-11', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '87', '0', '0', '0', '0', '0', '0', '0', '0', '126', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '16777829', '0', '0', '0', '15', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '32', 'Item - Warrior T8 Protection 4P Bonus');
*/

# 주술사 
-- 격노의 토템 크리버프 구현
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (57658,57660,57662,57663);
INSERT INTO `spell_linked_spell` VALUES ('57658', '30708', '0', 'Totem of Wrath crit (rank1)'),('57660', '30708', '0', 'Totem of Wrath crit (rank2)'),('57662', '30708', '0', 'Totem of Wrath crit (rank3)'),('57663', '30708', '0', 'Totem of Wrath crit (rank4)');
-- 힐토템 수정
DELETE FROM `spell_bonus_data` WHERE `entry` IN (52042,5672);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`,`ap_bonus`, `ap_dot_bonus`, `comments`) VALUES ('5672','0.0827','-1','-1','-1','Shaman - Healing Stream Totem Rank 1');

# 죽음의 기사
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

# 성기사 

# 흑마법사
-- 임프 마나
UPDATE `pet_levelstats` SET `mana`='65000' WHERE `creature_entry`='416' and `level`='80';
