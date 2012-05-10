-- 고유가방 드랍X
DELETE FROM `creature_loot_template` WHERE `entry` IN (50317,50316,49295);
DELETE FROM `reference_loot_template` WHERE `entry` IN (50317,50316,49295);

-- 쿨다운 없는 장신구 내부 쿨다운 구현
UPDATE `spell_proc_event` SET `Cooldown`='55' WHERE `entry`='33648'; -- 진실의 거울
DELETE FROM `spell_proc_event` WHERE `entry` IN (33953,60063,63251,67712); -- 필멸의 정수 알, 추방자의 해시계, 창기사의 격노, 생통 상/하급
INSERT INTO `spell_proc_event` VALUES (33953,0,0,0,0,0,278528,0,0,0,55),(60063,0,0,0,0,0,65536,0,0,0,60),(63251,127,0,0,0,0,0,0,0,0,55),(67712,0,0,0,0,0,69632,2,0,0,2);
DELETE FROM `spell_proc_event` WHERE `entry`='64955'; -- 성스러운 보호막의 성서
INSERT INTO `spell_proc_event` VALUES (64955,0,10,0,64,0,0,0,0,100,10);

-- 승천문장 성서, 토템, 우상, 인장 발동률 구현(무한발동 -> 본섭구현)
UPDATE `spell_proc_event` SET `CustomChance`='70',`Cooldown`='8' WHERE `entry`='67353'; -- 절단의 우상
UPDATE `spell_proc_event` SET `CustomChance`='70',`Cooldown`='5' WHERE `entry`='67356'; -- 불타는 성장의 우상
UPDATE `spell_proc_event` SET `CustomChance`='70',`Cooldown`='6' WHERE `entry`='67361'; -- 달빛 격노의 우상
UPDATE `spell_proc_event` SET `CustomChance`='70',`Cooldown`='8' WHERE `entry`='67363'; -- 진실의 성서
UPDATE `spell_proc_event` SET `CustomChance`='70',`Cooldown`='8' WHERE `entry`='67365'; -- 용기의 성서
UPDATE `spell_proc_event` SET `CustomChance`='80',`Cooldown`='9' WHERE `entry`='67379'; -- 도전의 성서
UPDATE `spell_proc_event` SET `CustomChance`='80',`Cooldown`='10' WHERE `entry`='67381'; -- 오만의 인장
UPDATE `spell_proc_event` SET `SpellFamilyMask1`='134348816',`procFlags`='16',`CustomChance`='70',`Cooldown`='10' WHERE `entry`='67384'; -- 발병력의 인장
UPDATE `spell_proc_event` SET `procFlags`='0',`CustomChance`='70',`Cooldown`='6' WHERE `entry`='67386'; -- 짜릿한 바람의 토템
UPDATE `spell_proc_event` SET `procFlags`='0',`CustomChance`='70',`Cooldown`='8' WHERE `entry`='67389'; -- 고요한 파도의 토템
UPDATE `spell_proc_event` SET `procFlags`='0',`CustomChance`='80',`Cooldown`='9' WHERE `entry`='67392'; -- 전률하는 대지의 토템

-- 버그 템/마부 수정
DELETE FROM `spell_proc_event` WHERE `entry`='36070'; -- 태양왕의 홀(무한발동 -> 분당 1회 발동)
INSERT INTO `spell_proc_event` VALUES (36070,0,0,0,0,0,0,0,1,0,0); 
UPDATE `spell_proc_event` SET `Cooldown` = '30' WHERE `entry` = 64440; -- 검 수호 마부식 글로벌 쿨타임 수정
UPDATE `spell_enchant_proc_data` SET `PPMChance` = '1' WHERE `entry` = 803; -- 불타는 무기 분당 1회 발동
UPDATE `spell_enchant_proc_data` SET `PPMChance` = '0.5' WHERE `entry` = 1894; -- 빙결 분당 0.5회 발동
UPDATE `spell_enchant_proc_data` SET `PPMChance` = '1' WHERE `entry` = 1898; -- 생명력 흡수 분당 1회 발동
UPDATE `spell_enchant_proc_data` SET `PPMChance` = '0.5' WHERE `entry` = 3273; -- 혹한 분당 0.5회 발동
UPDATE `spell_enchant_proc_data` SET `PPMChance` = '1.5' WHERE `entry` = 3239; -- 쇄빙 분당 1.5회 발동

-- 이상한 알 게임 플레이시간으로 부화되던 것 실시간으로 부화되게 수정
UPDATE `item_template` SET `Duration` = '-590400' WHERE `entry` IN ('39878', '44717');

-- 비정상이던 달라란표 무기 데미지 수정
UPDATE `item_template` SET `dmg_min1` = FLOOR((`dmg_min1` + `dmg_max1`) / 2), `dmg_max1` = `dmg_min1` WHERE `entry` IN (44635, 44636, 44637, 44638, 44639, 44640, 44641, 44642, 44643, 44644, 44645, 44652, 44654, 44655);

-- 누락된 냉혹템
DELETE FROM `npc_vendor` WHERE `entry` IN (34060, 34078) AND `item` IN (42133, 42134, 42135, 42136, 42137);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
-- Battlemaster HORDE
(34060, 0, 42137, 0, 0, 2718),(34060, 0, 42136, 0, 0, 2718),(34060, 0, 42134, 0, 0, 2718),(34060, 0, 42135, 0, 0, 2718),(34060, 0, 42133, 0, 0, 2718),
-- Battlemaster ALLY
(34078, 0, 42137, 0, 0, 2718),(34078, 0, 42136, 0, 0, 2718),(34078, 0, 42134, 0, 0, 2718),(34078, 0, 42135, 0, 0, 2718),(34078, 0, 42133, 0, 0, 2718);
-- Relentless shields
DELETE FROM `npc_vendor` WHERE `entry` = 33927 AND `item` IN (42561, 42566, 42572);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
(33927, 0, 42561, 0, 0, 2701),(33927, 0, 42566, 0, 0, 2701),(33927, 0, 42572, 0, 0, 2701);

-- 버그퀘템 사용제한
UPDATE `item_template` SET `RequiredLevel`='81' WHERE `entry`=50709; -- 토비 어쩌고 연설문
UPDATE `item_template` SET `RequiredLevel`='81' WHERE `entry`=30259; -- 보렌살의 헌신

-- 자유의지의 물약 쿨타임 30분으로 너프
UPDATE `item_template` SET `spellcategorycooldown_1`=1800000 WHERE `entry`=5634;

-- 위안 발동효과 수정
DELETE FROM `spell_proc_event` WHERE `entry` IN (67752,67698);
INSERT INTO `spell_proc_event` VALUES(67752, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 30), (67698, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 30);

-- 정신충격 발동효과 수정
DELETE FROM `spell_proc_event` WHERE `entry` IN (71865,71868);
INSERT INTO `spell_proc_event` VALUES(71865, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 30), (71865, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 30);

-- 알소르의 연산장치 발동효과 수정
DELETE FROM `spell_proc_event` WHERE `entry` IN (71611,71642);
INSERT INTO `spell_proc_event` VALUES(71611, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 45), (71642, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 45);

-- 투기 투척무기 수정
UPDATE `item_template` SET `Flags`=4231168,`RangedModRange`=100,`MaxDurability`=0 WHERE `entry` IN (42449,42444);

/*
-- 포장지 템삭제
DELETE FROM `item_template` WHERE `entry` IN (5042,5043,5044,5048,17302,17303,17304,17305,17307,17308,21830);
DELETE FROM `npc_vendor` WHERE `item` IN (5042,5043,5044,5048,17302,17303,17304,17305,17307,17308,21830);
DELETE FROM `item_loot_template` WHERE `item` IN (5042,5043,5044,5048,17302,17303,17304,17305,17307,17308,21830);
DELETE FROM `reference_loot_template` WHERE `item` IN (5042,5043,5044,5048,17302,17303,17304,17305,17307,17308,21830);
DELETE FROM `creature_loot_template` WHERE `item` IN (5042,5043,5044,5048,17302,17303,17304,17305,17307,17308,21830);
*/

-- 어둠서리 조각 삭제
DELETE FROM `item_template` WHERE `entry`=50274;
DELETE FROM `item_loot_template` WHERE `item`=50274;
DELETE FROM `creature_loot_template` WHERE `item`=50274;
DELETE FROM `gameobject_loot_template` WHERE `item`=50274;
DELETE FROM `reference_loot_template` WHERE `item`=50274;