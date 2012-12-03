-- 스카디 업적
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7595;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(7595, 11, 0, 0, 'achievement_skadi_all_the_time'),
(7595, 12, 1, 0, '');

-- 레버 활성화
DELETE FROM `disables` WHERE `sourceType` = 4 AND `entry` = 7595;

-- 플래그 및 모드 재세팅
UPDATE `creature_template` SET `modelid1` = 11686, `modelid2` = 0 WHERE `entry` IN (27339, 30808);
UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14 WHERE `entry` IN (27339, 30808, 27386, 30756);
UPDATE `creature_template` SET `modelid1` = 11686, `modelid3` = 0 WHERE `entry` = 26688;

-- 성채 전용 명역체계
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` IN (26683, 30772, 26684, 30803, 26685, 30790, 26686, 30770, 26687 ,30774 ,26693, 30807, 26861, 30788 ,29281, 30809, 26668, 30810);
UPDATE `creature_template` SET `flags_extra` = 1 WHERE `entry` IN (30770, 30772, 30790, 30803);

-- 누락된 전문기술 제조법 추가
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 1 AND `SourceGroup` IN (26861, 30788) AND `SourceEntry` = 41797;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorTextId, ScriptName, Comment) VALUES
(1, 26861, 41797, 0, 0, 7, 0, 755, 1, 0, 0, 0, '', ''),
(1, 30788, 41797, 0, 0, 7, 0, 755, 1, 0, 0, 0, '', '');
