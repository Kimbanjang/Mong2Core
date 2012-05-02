##### 퀘스트 #####

-- 주술사 물의 부름 퀘스트 수정
DELETE FROM `gameobject` WHERE `id` = '202275';
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`animprogress`,`state`) VALUE ('202275','530','1','1','-2184.36','-12343.3','56.2689','3.05885','300','0','1');

-- 단어의 힘 수정
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`IN(26073,26076);

-- Wanton Warlord 수정
DELETE FROM `event_scripts` WHERE `id`=17767;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES (17767,0,10,27002,300000,0,2789.774,382.7825,76.8793,2.597488);

-- Fix Unlocking Zuluhed's Chains
UPDATE `quest_template` SET `RequiredNpcOrGo1` = -185156 WHERE `Id` = 10866;

-- 주간레이드 퀘스트 보상 조정
UPDATE `quest_template` SET `RewardItemCount1`=2, `RewardItemCount2`=8 WHERE `Id` IN (24579,24582,24583,24584,24590,24580,24581,24587,24585,24588,24586,24589);

-- 서리조각 퀘스트 임시조정 (요구아이템 : 서리문장 1000개 / 보상아이템 : 녹슨단검)
UPDATE `quest_template` SET `RequiredItemId1`='49426' , RequiredItemCount1='1000'  WHERE `Id`='24548';

-- 성기사구원 스킬 획득
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES ('16681', '7328', '0', '0', '0', '20');
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES ('928', '7328', '0', '0', '0', '20');

-- 라벤홀트 평판용 보관함 반납퀘스트 도적직업제한 해제
UPDATE `quest_template` SET `ZoneOrSort`='-1' WHERE (`Id`='8249');

-- 흑기사의 명령서 퀘스트 1번조건 흑기사의 그리핀 팩션 우호에서 적대로 조정
UPDATE `creature_template` SET `faction_A`='1885', `faction_H`='1885' WHERE (`entry`='33519');

-- 진은광물 채광시 퀘템으로 잘못 설정된 부분 진은광물 드랍으로 변경
UPDATE `gameobject_loot_template` SET `item`='7911' WHERE (`entry`='5045') AND (`item`='12906');

-- 죽기 퀘스트 [하늘로부터의 죽음] 버그 임시 픽스
UPDATE `quest_template` SET `RequiredNpcOrGo1`='0', `RequiredNpcOrGo2`='0', `RequiredNpcOrGo3`='0', `RequiredNpcOrGo4`='0' WHERE (`Id`='12641');
UPDATE `quest_template` SET `RequiredNpcOrGoCount1`='0', `RequiredNpcOrGoCount2`='0', `RequiredNpcOrGoCount3`='0', `RequiredNpcOrGoCount4`='0' WHERE (`Id`='12641');
UPDATE `quest_template` SET `RequiredSpellCast1`='0', `RequiredSpellCast2`='0', `RequiredSpellCast3`='0', `RequiredSpellCast4`='0' WHERE (`Id`='12641');
/* 복구용
UPDATE `quest_template` SET `RequiredNpcOrGo1`='28525', `RequiredNpcOrGo2`='28543', `RequiredNpcOrGo3`='28542', `RequiredNpcOrGo4`='28544' WHERE (`Id`='12641');
UPDATE `quest_template` SET `RequiredNpcOrGoCount1`='1', `RequiredNpcOrGoCount2`='1', `RequiredNpcOrGoCount3`='1', `RequiredNpcOrGoCount4`='1' WHERE (`Id`='12641');
UPDATE `quest_template` SET `RequiredSpellCast1`='51858', `RequiredSpellCast2`='51858', `RequiredSpellCast3`='51858', `RequiredSpellCast4`='51858' WHERE (`Id`='12641');
*/

-- 마상퀘 [흑기사의 종자에겐 뭔가 특별한 것이 있다] 대상 NPC 말로릭 배치 오류로 삭제후 재배치
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES ('11957861', '33498', '571', '1', '1', '0', '1855', '5424.45', '401.527', '167.945', '0.152293', '300', '0', '0', '11770', '3809', '0', '0', '0', '0');

-- 사제 지팡이 퀘스트 에리스 헤븐파이어 배치누락으로 추가
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES ('11959760', '14494', '0', '1', '1', '0', '0', '3327.39', '-3018.04', '171.75', '2.67837', '300', '0', '0', '3052', '0', '0', '0', '0', '0');

-- 얼왕 평판반지 퀘
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `Id` IN
-- Paths
(24827,24834,24835,24823,24828,24829,25239,25240,25242,24826,24832,24833,24825,24830,24831,
-- A Change of Heart
24819,24820,24821,24822,24836,24837,24838,24839,24840,24841,24842,24843,24844,24845,24846,24847,25246,25247,25248,25249);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN
-- Paths
(24827,24834,24835,24823,24828,24829,25239,25240,25242,24826,24832,24833,24825,24830,24831,
-- A Change of Heart
24819,24820,24821,24822,24836,24837,24838,24839,24840,24841,24842,24843,24844,24845,24846,24847,25246,25247,25248,25249);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Path of Courage
(19,0,24827,0,0,2,50375,1,0,0,0,0,'Path of Courage 1'),
(19,0,24834,0,0,2,50388,1,0,0,0,0,'Path of Courage 2'),
(19,0,24835,0,0,2,50403,1,0,0,0,0,'Path of Courage 3'),
-- Path of Destruction
(19,0,24823,0,0,2,50384,1,0,0,0,0,'Path of Destruction 1'),
(19,0,24828,0,0,2,50377,1,0,0,0,0,'Path of Destruction 2'),
(19,0,24829,0,0,2,50397,1,0,0,0,0,'Path of Destruction 3'),
-- Path of Might
(19,0,25239,0,0,2,52569,1,0,0,0,0,'Path of Might 1'),
(19,0,25240,0,0,2,52570,1,0,0,0,0,'Path of Might 2'),
(19,0,25242,0,0,2,52571,1,0,0,0,0,'Path of Might 3'),
-- Path of Vengeance
(19,0,24826,0,0,2,50376,1,0,0,0,0,'Path of Vengeance 1'),
(19,0,24832,0,0,2,50387,1,0,0,0,0,'Path of Vengeance 2'),
(19,0,24833,0,0,2,50401,1,0,0,0,0,'Path of Vengeance 3'),
-- Path of Wisdom
(19,0,24825,0,0,2,50378,1,0,0,0,0,'Path of Wisdom 1'),
(19,0,24830,0,0,2,50386,1,0,0,0,0,'Path of Wisdom 2'),
(19,0,24831,0,0,2,50399,1,0,0,0,0,'Path of Wisdom 3'),
-- A Change of Heart
(19,0,24819,0,0,2,50377,1,0,0,0,0,'A Change of Heart'),
(19,0,24820,0,0,2,50376,1,0,0,0,0,'A Change of Heart'),
(19,0,24821,0,0,2,50375,1,0,0,0,0,'A Change of Heart'),
(19,0,24822,0,0,2,50378,1,0,0,0,0,'A Change of Heart'),
(19,0,24836,0,0,2,50384,1,0,0,0,0,'A Change of Heart'),
(19,0,24837,0,0,2,50386,1,0,0,0,0,'A Change of Heart'),
(19,0,24838,0,0,2,50387,1,0,0,0,0,'A Change of Heart'),
(19,0,24839,0,0,2,50388,1,0,0,0,0,'A Change of Heart'),
(19,0,24840,0,0,2,50397,1,0,0,0,0,'A Change of Heart'),
(19,0,24841,0,0,2,50399,1,0,0,0,0,'A Change of Heart'),
(19,0,24842,0,0,2,50401,1,0,0,0,0,'A Change of Heart'),
(19,0,24843,0,0,2,50403,1,0,0,0,0,'A Change of Heart'),
(19,0,24844,0,0,2,50398,1,0,0,0,0,'A Change of Heart'),
(19,0,24845,0,0,2,50400,1,0,0,0,0,'A Change of Heart'),
(19,0,24846,0,0,2,50402,1,0,0,0,0,'A Change of Heart'),
(19,0,24847,0,0,2,50404,1,0,0,0,0,'A Change of Heart'),
(19,0,25246,0,0,2,52572,1,0,0,0,0,'A Change of Heart'),
(19,0,25247,0,0,2,52569,1,0,0,0,0,'A Change of Heart'),
(19,0,25248,0,0,2,52570,1,0,0,0,0,'A Change of Heart'),
(19,0,25249,0,0,2,52571,1,0,0,0,0,'A Change of Heart');


##### 기타 #####

-- 힐다나 데스스틸러 펙션 수정
UPDATE `creature_template` SET `faction_H`=22, `faction_A`=22 WHERE `entry`=32495;

-- 호드 무용문장상인 누락건 선리버성소 배치
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES ('11956420', '31582', '571', '1', '1', '0', '917', '5941.03', '511.184', '650.178', '2.77698', '300', '0', '0', '10080', '8814', '0', '0', '0', '0');
