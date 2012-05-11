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
--UPDATE `gameobject_loot_template` SET `item`='7911' WHERE (`entry`='5045') AND (`item`='12906');

-- 죽기 퀘스트 [하늘로부터의 죽음] 버그 픽스
UPDATE `creature_template` SET `ScriptName` = 'npc_eye_of_acherus' WHERE `entry` = '28511';
/*
-- 죽기 퀘스트 [하늘로부터의 죽음] 버그 임시 픽스
UPDATE `quest_template` SET `RequiredNpcOrGo1`='0', `RequiredNpcOrGo2`='0', `RequiredNpcOrGo3`='0', `RequiredNpcOrGo4`='0' WHERE (`Id`='12641');
UPDATE `quest_template` SET `RequiredNpcOrGoCount1`='0', `RequiredNpcOrGoCount2`='0', `RequiredNpcOrGoCount3`='0', `RequiredNpcOrGoCount4`='0' WHERE (`Id`='12641');
UPDATE `quest_template` SET `RequiredSpellCast1`='0', `RequiredSpellCast2`='0', `RequiredSpellCast3`='0', `RequiredSpellCast4`='0' WHERE (`Id`='12641');
-- 복구용
UPDATE `quest_template` SET `RequiredNpcOrGo1`='28525', `RequiredNpcOrGo2`='28543', `RequiredNpcOrGo3`='28542', `RequiredNpcOrGo4`='28544' WHERE (`Id`='12641');
UPDATE `quest_template` SET `RequiredNpcOrGoCount1`='1', `RequiredNpcOrGoCount2`='1', `RequiredNpcOrGoCount3`='1', `RequiredNpcOrGoCount4`='1' WHERE (`Id`='12641');
UPDATE `quest_template` SET `RequiredSpellCast1`='51858', `RequiredSpellCast2`='51858', `RequiredSpellCast3`='51858', `RequiredSpellCast4`='51858' WHERE (`Id`='12641');
*/

-- 마상퀘 [흑기사의 종자에겐 뭔가 특별한 것이 있다] 대상 NPC 말로릭 배치 오류로 삭제후 재배치
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES ('11957861', '33498', '571', '1', '1', '0', '1855', '5424.45', '401.527', '167.945', '0.152293', '300', '0', '0', '11770', '3809', '0', '0', '0', '0');

-- 사제 지팡이 퀘스트 에리스 헤븐파이어 배치누락으로 추가
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES ('11959760', '14494', '0', '1', '1', '0', '0', '3327.39', '-3018.04', '171.75', '2.67837', '300', '0', '0', '3052', '0', '0', '0', '0', '0');

-- 아웃랜드 첫 와이본/그리폰 작동안함 수정
-- Vlagga Freyfeather NPC(18930)
SET @NPC=18930;
SET @GOSSIP=7938;
DELETE FROM  `gossip_menu_option` WHERE  `menu_id` =@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,0,2,'Show me where I can fly.',4,8192,0,0,0,0,''),
(@GOSSIP,1,2,'Send me to Thrallmar!',4,8192,0,0,0,0,'');

DELETE FROM `creature_ai_scripts` WHERE `creature_id` =@NPC;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry` =@NPC;
DELETE FROM  `smart_scripts` WHERE  `entryorguid` =@NPC;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,0,62,0,100,0,@GOSSIP,1,0,0,11,34924,2,0,0,0,0,7,0,0,0,0,0,0,0,'Vlagga Freyfeather - On gossip option 1 select - Cast Stair of Destiny to Thrallmar'),
(@NPC,0,1,0,4,0,100,0,0,0,0,0,12,9297,4,30000,0,0,0,1,0,0,0,0,0,0,0,'Vlagga Freyfeather - Summon Enraged Wyverns on Aggro'),
(@NPC,0,2,0,4,0,100,0,0,0,0,0,12,9297,4,30000,0,0,0,1,0,0,0,0,0,0,0,'Vlagga Freyfeather - Summon Enraged Wyverns on Aggro'),
(@NPC,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vlagga Freyfeather - Say text on Aggro');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,0,0,0, 8,0,10289,0,0,0,0,'','Show gossip option 0 if player has rewarded quest 10289 "Journey to Thrallmar"'),
(15,@GOSSIP,1,0,0,28,0,10289,0,0,0,0,'','Show gossip option 1 if player has complete quest 10289 "Journey to Thrallmar"');

-- Amish Wildhammer NPC(18931)
SET @NPC=18931;
SET @GOSSIP=7939;
DELETE FROM  `gossip_menu` WHERE  `entry` =@GOSSIP;
DELETE FROM  `npc_text` WHERE  `ID` IN (9935,9991);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP,10052);

DELETE FROM  `gossip_menu_option` WHERE  `menu_id` =@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,0,2,'Show me where I can fly.',4,8192,0,0,0,0,''),
(@GOSSIP,1,2,'Send me to Honor Hold!',4,8192,0,0,0,0,'');

DELETE FROM `creature_ai_scripts` WHERE `creature_id` =@NPC;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry` =@NPC;
DELETE FROM  `smart_scripts` WHERE  `entryorguid` =@NPC;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,0,62,0,100,0,@GOSSIP,1,0,0,11,34907,2,0,0,0,0,7,0,0,0,0,0,0,0,'Amish Wildhammer - On gossip option 1 select - Cast Stair of Destiny to Honor Hold'),
(@NPC,0,1,0,4,0,100,0,0,0,0,0,12,9526,4,30000,0,0,0,1,0,0,0,0,0,0,0,'Amish Wildhammer - Summon Enraged Gryphon on Aggro'),
(@NPC,0,2,0,4,0,100,0,0,0,0,0,12,9526,4,30000,0,0,0,1,0,0,0,0,0,0,0,'Amish Wildhammer - Summon Enraged Gryphon on Aggro'),
(@NPC,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Amish Wildhammer - Say text on Aggro');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,0,0,0, 8,0,10140,0,0,0,0,'','Show gossip option 0 if player has rewarded quest 10140 "Journey to Honor Hold"'),
(15,@GOSSIP,1,0,0,28,0,10140,0,0,0,0,'','Show gossip option 1 if player has complete quest 10140 "Journey to Honor Hold"');

-- 흑마 보이드워커퀘 수정
UPDATE `creature_template` SET `faction_a`=29, `faction_h`=29 WHERE `entry`=36213;


##### 기타 #####

-- 힐다나 데스스틸러 펙션 수정
UPDATE `creature_template` SET `faction_H`=22, `faction_A`=22 WHERE `entry`=32495;

-- 노스랜드 팩션 안맞는 크리쳐 수정
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry` IN 
(32357,32361, 32358,32481,32471,32501,32398,32377,32438,32475,32386,32400);

-- 호드 무용문장상인 누락건 선리버성소 배치
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES ('11956420', '31582', '571', '1', '1', '0', '917', '5941.03', '511.184', '650.178', '2.77698', '300', '0', '0', '10080', '8814', '0', '0', '0', '0');
