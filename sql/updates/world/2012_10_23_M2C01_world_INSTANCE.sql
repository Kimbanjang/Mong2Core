##### 면역체계 #####
-- 완전 무결한 보스
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (10184,36538); -- 오닉시아
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (34564,34566,35615,35616); -- 십자군 아눕아락
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (34796,35438,35439,35440); -- 십자군 고르목
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (35144,35511,35512,35513); -- 십자군 산성아귀
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (34799,35514,35515,35516); -- 십자군 공포비늘
UPDATE `creature_template` SET `mechanic_immune_mask`='650854271' WHERE `entry` IN (34797,35447,35448,35449); -- 십자군 얼음울음
-- 차단만 가능한 보스
UPDATE `creature_template` SET `mechanic_immune_mask`='617299967' WHERE `entry` IN (34496,35347,35348,35349); -- 십자군 다크베인
UPDATE `creature_template` SET `mechanic_immune_mask`='617299967' WHERE `entry` IN (34497,35350,35351,35352); -- 십자군 라이트베인
UPDATE `creature_template` SET `mechanic_immune_mask`='617299967' WHERE `entry` IN (34780,35216,35268,35269); -- 십자군 자락서스
-- 매즈가 가능한 보스

-- 얼왕 보스
/* Boss - Lord Marrowgar */
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='36612');
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='37957');
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='37958');
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='37959');
 
/* Boss - Lady Deathwhisper */
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='36855');
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='38106');
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='38296');
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='38297');
 
/* Boss - Deathbringer Saurfang */
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38583');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='37813');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38402');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38582');
 
/* Boss - Festergut */
/* ALL IS OK */
 
/* Boss - Rotface */
/* ALL IS OK */
 
/* Boss - Professor Putricide */
/* ALL IS OK */
 
/* Boss - Prince Valanar */
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='37970');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38401');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38784');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38785');
 
/* Boss - Prince Keleseth */
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='37972');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38399');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38769');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38770');
 
/* Boss - Prince Taldaram */
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='37973');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38400');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38771');
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE (`entry`='38772');
 
/* Boss - Blood-Queen Lana'thel */
UPDATE `creature_template` SET `mechanic_immune_mask`='801849343' WHERE (`entry`='37955');
UPDATE `creature_template` SET `mechanic_immune_mask`='801849343' WHERE (`entry`='38434');
UPDATE `creature_template` SET `mechanic_immune_mask`='801849343' WHERE (`entry`='38435');
UPDATE `creature_template` SET `mechanic_immune_mask`='801849343' WHERE (`entry`='38436');
 
/* Boss - Sindragosa */
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='36853');
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='38265');
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='38266');
UPDATE `creature_template` SET `mechanic_immune_mask`='667893759' WHERE (`entry`='38267');

-- Volatile Ooze and Gas Cloud
UPDATE creature_template SET mechanic_immune_mask='650854399' WHERE entry IN (37697, 38758, 38759, 38604, 37562, 38760, 38761, 38602);
-- Little and Big Ooze
UPDATE creature_template SET mechanic_immune_mask='650853375' WHERE entry IN (36899, 38123, 36897, 38138);
-- Little Ooze taunt
UPDATE creature_template SET flags_extra='256' WHERE entry IN (36897, 38138);

-- 리분 5인 던젼
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|4|8|16|64|128|256|512|1024|4096|65536|131072|524288|67108864|536870912 WHERE `entry` IN (
-- Halls of stone:
27975,-- Maiden of Grief
31384,-- Maiden of Grief (1)
27977,-- Krystallus
31381,-- Krysyallus (1)
27978,-- Sjonnir the Ironshaper
31386,-- Sjonnir the Ironshaper (1)
-- Halls of Lightning:
28586,-- General Bjarngrim
31533,-- General Bjarngrim (1)
28587,-- Volkhan
31536,-- Volkhan (1)
28546,-- Ionar
31537,-- Ionar (1)
28923,-- Loken
31538,-- Loken (1)
-- The Nexus:
26731,-- Grand Magus Telestra
26930,-- Grand Magus Telestra (Blue - Frost)
26929,-- Grand Magus Telestra (Purple)
26928,-- Grand Magus Telestra (Red - Fire)
30510,-- Grand Magus Telestra (1)
30513,-- Grand Magus Telestra (Blue - Frost (1))
30512,-- Grand Magus Telestra (Purple (1))
30511,-- Grand Magus Telestra (Red - Fire (1))
26763,-- Anomalus
30529,-- Anomalus (1)
26974,-- Ormorok the Tree-Shaper
26723,-- Keristrasza
30540,-- Keristrasza (1)
26796,-- Commander Stoutbeard
30398,-- Commander Stoutbeard (1)
26798,-- Commander Kolurg
30397,-- Commander Kolurg (1)
-- The Oculus:
27654,-- Drakos the Interrogator
31558,-- Drakos the Interrogator (1)
27447,-- Varos Cloudstrider
31559,-- Varos Cloudstrider (1)
27655,-- Mage-Lord Urom
31560,-- Mage-Lord Urom (1)
27656,-- Ley-Guardian Eregos
31561,-- Ley-Guardian Eregos (1)
-- Azjol-Nerub:
28684,-- Krik'thir the Gatewatcher
31612,-- Krik'thir the Gatewatcher (1)
28921,-- Hadronox
31611,-- Hadronox (1)
29120,-- Anub'arak
31610,-- Anub'arak (1)
-- Ahn'kahet: The Old Kingdom:
29309,-- Elder Nadox
31456,-- Elder Nadox (1)
29308,-- Prince Taldaram
31469,-- Prince Taldaram (1)
29310,-- Jedoga Shadowseeker
31465,-- Jedoga Shadowseeker (1)
29311,-- Herald Volazj
31464,-- Herald Volazj (1)
30258,-- Amanitar
31463,-- Amanitar (1)
-- Utgarde Pinnacle:
26668,-- Svala Sorrowgrave
31810,-- Svala Sorrowgrave (1)
26687,-- Gortok Palehoof
30774,-- Gortok Palehoof (1)
26693,-- Skadi the Ruthless
30807,-- Skadi the Ruthless (1)
26861,-- King Ymiron
30788,-- King Ymiron (1)
-- Gundrak:
29304,-- Slad'ran
31370,-- Slad'ran (1)
29305,-- Moorabi
30530,-- Moorabi (1)
29307,-- Drakkari Colossus
31365,-- Drakkari Colossus (1)
29537,-- Drakkari Elemental
29306,-- Gal'darah
31368,-- Gal'darah (1)
29932,-- Eck the Ferocious
-- Halls of Reflection:
38112,-- Falric
38599,-- Falric (1)
38113,-- Marwyn
38603,-- Marwyn (1)
37226,-- Wrath of the Lich King
-- Pit of Saron:
36494,-- Forgemaster Garfrost
37613,-- Forgemaster Garfrost (1) 
36476,-- Ick
37627,-- Ick (1)
36477,-- Krick
37629,-- Krick (1)
36658,-- Scourgelord Tyrannus
36938,-- Scourgelord Tyrannus (1)
-- The Forge of Souls:
36497,-- Bronjahm
36498,-- Bronjahm (1)
36502,-- Devourer of Souls
37677);-- Devourer of Souls (1)

-- TBC 보스
UPDATE `creature_template` SET `flags_extra` = 0 WHERE `entry` IN (19893,19895,19894,20267,20268,20266,18436,18433,18434,20690,20706,23035,20738,20568,20597,21551,21558,21581,21559,25562,25573,25560,24857,18621,18601,18607,20169,20168,20183,20184,20636,20637,20653,20657,20629,20630,20633,21533,21536,21537,21626,21590,21624,21601,20318,20306);
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967, `flags_extra` = 0 WHERE `entry` IN (20738, 20737,20993,21582);
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967, `flags_extra` = 256 WHERE `entry` IN (20745,20596);


################################
########## [비레이드] ##########
################################

##### 검은바위 첨탑 상층 #####
-- 입구 문 오브젝 삭제
DELETE FROM `gameobject` WHERE `guid` IN (87839,87842,87841,87845,87844);
-- 백업
-- INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES ('87839', '175244', '229', '1', '1', '216.443', '-286.135', '76.9406', '3.14159', '0', '0', '0', '0', '120', '0', '1'),('87842', '175705', '229', '1', '1', '175.127', '-258.945', '91.5603', '0', '0', '0', '0', '0', '120', '0', '1'),('87841', '175153', '229', '1', '1', '113.751', '-258.945', '91.5603', '0', '0', '0', '0', '0', '120', '0', '1'),('87845', '164726', '229', '1', '1', '108.036', '-420.331', '110.954', '3.14159', '0', '0', '0', '0', '120', '0', '1'),('87844', '175186', '229', '1', '1', '92.9595', '-435.59', '110.954', '-1.5708', '0', '0', '0', '0', '120', '0', '1');

##### 영혼의 제련소 #####
-- 장비세팅
UPDATE `creature_template` SET `equipment_id`=2367 WHERE `entry`=37569; -- Soulguard Watchman
UPDATE `creature_template` SET `equipment_id`=2331 WHERE `entry`=37568; -- Soulguard Reaper
UPDATE `creature_template` SET `equipment_id`=2335 WHERE `entry`=37566; -- Soulguard Adept
UPDATE `creature_template` SET `equipment_id`=2326 WHERE `entry`=36498; -- Bronjahm

##### 샤론의 구덩이 #####
-- 팩션조정
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `unit_flags`=32832 WHERE `entry`=37643; -- Ymirjar Skycaller
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry` IN (36830,37638); -- Wrathbone Laborer

-- 장비세팅
UPDATE `creature_template` SET `equipment_id`=2438 WHERE `entry`=37639; -- Ymirjar Skycaller
UPDATE `creature_template` SET `equipment_id`=104 WHERE `entry`=37638;  -- Wrathbone Laborer
UPDATE `creature_template` SET `equipment_id`=122 WHERE `entry`=37639;  -- Wrathbone Siegesmith
UPDATE `creature_template` SET `equipment_id`=2443 WHERE `entry`=37612; -- Fallen Warrior
UPDATE `creature_template` SET `equipment_id`=2325 WHERE `entry`=37613; -- Forgemaster Garfrost
UPDATE `creature_template` SET `equipment_id`=2365 WHERE `entry`=37609; -- Deathwhisper Necrolyte
UPDATE `creature_template` SET `equipment_id`=2365 WHERE `entry`=38025; -- Deathwhisper Shadowcaster

-- 동굴 이벤트 구현
DELETE FROM `creature_template` WHERE (`entry`=36847);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (36847, 0, 0, 0, 0, 0, 28470, 1126, 0, 0, 'Collapsing Icicle', '', '', 0, 80, 80, 2, 35, 35, 0, 1, 1.14286, 1, 0, 420, 630, 0, 157, 1, 2000, 2000, 1, 33587200, 8, 0, 0, 0, 0, 0, 336, 504, 126, 4, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 128, 'npc_tyrannus_icicle', 12340);
 
DELETE FROM `creature` WHERE `id`=36847;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(139286, 36847, 658, 3, 1, 0, 0, 1074.55, 19.4549, 633.102, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139287, 36847, 658, 3, 1, 0, 0, 1083.67, 6.56424, 633.7, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139288, 36847, 658, 3, 1, 0, 0, 1010.18, -141.198, 621.042, 2.49582, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139289, 36847, 658, 3, 1, 0, 0, 1074.55, 19.4549, 633.102, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139290, 36847, 658, 3, 1, 0, 0, 1069.24, -10.6545, 633.781, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139291, 36847, 658, 3, 1, 0, 0, 1021.05, -122.354, 624.375, 2.84489, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139292, 36847, 658, 3, 1, 0, 0, 1058.88, -51.0677, 633.797, 4.60767, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139293, 36847, 658, 3, 1, 0, 0, 1048.24, -75.2014, 633.003, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139294, 36847, 658, 3, 1, 0, 0, 1021.05, -122.354, 624.375, 2.84489, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139295, 36847, 658, 3, 1, 0, 0, 1038.08, -106.852, 628.901, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139296, 36847, 658, 3, 1, 0, 0, 1056.59, -109.167, 630.891, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139297, 36847, 658, 3, 1, 0, 0, 1059.43, -39.0729, 633.943, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139298, 36847, 658, 3, 1, 0, 0, 981.66, -134.417, 607.866, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139299, 36847, 658, 3, 1, 0, 0, 951.469, -96.0486, 595.238, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139300, 36847, 658, 3, 1, 0, 0, 1072.91, -40.8993, 633.59, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139301, 36847, 658, 3, 1, 0, 0, 985.663, -128.326, 608.254, 0.15708, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139302, 36847, 658, 3, 1, 0, 0, 1000.3, -126.005, 615.862, 2.07694, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139303, 36847, 658, 3, 1, 0, 0, 1058.25, -53.5122, 633.705, 3.75246, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139304, 36847, 658, 3, 1, 0, 0, 948.851, -111.17, 595.13, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139305, 36847, 658, 3, 1, 0, 0, 1074.6, 71.1458, 631.068, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139306, 36847, 658, 3, 1, 0, 0, 1068.62, 52.066, 631.293, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139307, 36847, 658, 3, 1, 0, 0, 1080.09, 43.467, 630, 0.506145, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139308, 36847, 658, 3, 1, 0, 0, 1008.45, -127.712, 620.498, 2.49582, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139309, 36847, 658, 3, 1, 0, 0, 1072.91, -40.8993, 633.59, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139310, 36847, 658, 3, 1, 0, 0, 1049.65, -74.033, 633.078, 4.36332, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139311, 36847, 658, 3, 1, 0, 0, 1069.24, -10.6545, 633.781, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139312, 36847, 658, 3, 1, 0, 0, 1056.59, -109.167, 630.891, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139313, 36847, 658, 3, 1, 0, 0, 1068.64, 27.0972, 631.282, 4.08407, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139314, 36847, 658, 3, 1, 0, 0, 1018.17, -130.429, 623.537, 0.15708, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139315, 36847, 658, 3, 1, 0, 0, 948.851, -111.17, 595.13, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139316, 36847, 658, 3, 1, 0, 0, 1058.25, -53.5122, 633.705, 3.75246, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139317, 36847, 658, 3, 1, 0, 0, 957.536, -110.778, 595.604, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139318, 36847, 658, 3, 1, 0, 0, 948.851, -111.17, 595.13, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139319, 36847, 658, 3, 1, 0, 0, 1083.67, 6.56424, 633.7, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139320, 36847, 658, 3, 1, 0, 0, 1074.55, 19.4549, 633.102, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139321, 36847, 658, 3, 1, 0, 0, 1018.17, -130.429, 623.537, 0.15708, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139322, 36847, 658, 3, 1, 0, 0, 946.724, -105.462, 594.994, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139323, 36847, 658, 3, 1, 0, 0, 1060.56, -77.3542, 633.758, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139324, 36847, 658, 3, 1, 0, 0, 951.465, -102.632, 594.968, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139325, 36847, 658, 3, 1, 0, 0, 1071.78, -19.1458, 633.174, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139326, 36847, 658, 3, 1, 0, 0, 1048.24, -75.2014, 633.003, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139327, 36847, 658, 3, 1, 0, 0, 1062.55, -23.7222, 634.076, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139328, 36847, 658, 3, 1, 0, 0, 980.286, -118.993, 601.536, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139329, 36847, 658, 3, 1, 0, 0, 1068.78, -70.4063, 633.396, 3.66519, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139330, 36847, 658, 3, 1, 0, 0, 1071.78, -19.1458, 633.174, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139331, 36847, 658, 3, 1, 0, 0, 1029.76, -114.705, 626.664, 2.94961, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139332, 36847, 658, 3, 1, 0, 0, 1068.78, -70.4063, 633.396, 3.66519, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139333, 36847, 658, 3, 1, 0, 0, 1048.78, -115.236, 629.419, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139334, 36847, 658, 3, 1, 0, 0, 1065.23, 116.997, 628.366, 4.93928, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139335, 36847, 658, 3, 1, 0, 0, 1071.78, -19.1458, 633.174, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139336, 36847, 658, 3, 1, 0, 0, 1059.43, -39.0729, 633.943, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139337, 36847, 658, 3, 1, 0, 0, 990.997, -124.531, 609.625, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139338, 36847, 658, 3, 1, 0, 0, 1058.25, -53.5122, 633.705, 3.75246, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139339, 36847, 658, 3, 1, 0, 0, 1048.24, -75.2014, 633.003, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139340, 36847, 658, 3, 1, 0, 0, 1082.01, 29.5747, 630.368, 4.08407, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139341, 36847, 658, 3, 1, 0, 0, 1067.68, -13.2049, 633.712, 4.53786, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139342, 36847, 658, 3, 1, 0, 0, 1079.75, 38.0608, 629.712, 4.60767, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139343, 36847, 658, 3, 1, 0, 0, 1074.6, 71.1458, 631.068, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139344, 36847, 658, 3, 1, 0, 0, 946.724, -105.462, 594.994, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139345, 36847, 658, 3, 1, 0, 0, 1073.01, 58.1354, 631.722, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139346, 36847, 658, 3, 1, 0, 0, 980.286, -118.993, 601.536, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139347, 36847, 658, 3, 1, 0, 0, 951.465, -102.632, 594.968, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139348, 36847, 658, 3, 1, 0, 0, 1021.05, -122.354, 624.375, 2.84489, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139349, 36847, 658, 3, 1, 0, 0, 1071.71, -55.4722, 633.578, 3.75246, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139350, 36847, 658, 3, 1, 0, 0, 1039.86, -115.92, 628.833, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139351, 36847, 658, 3, 1, 0, 0, 1029.76, -114.705, 626.664, 2.94961, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139352, 36847, 658, 3, 1, 0, 0, 1068.64, 27.0972, 631.282, 4.08407, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139353, 36847, 658, 3, 1, 0, 0, 947.764, -97.849, 595.385, 5.74213, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139354, 36847, 658, 3, 1, 0, 0, 958.288, -120.444, 596.854, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139355, 36847, 658, 3, 1, 0, 0, 1038.08, -106.852, 628.901, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139356, 36847, 658, 3, 1, 0, 0, 1071.71, -55.4722, 633.578, 3.75246, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139357, 36847, 658, 3, 1, 0, 0, 1048.78, -115.236, 629.419, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139358, 36847, 658, 3, 1, 0, 0, 1069.24, -10.6545, 633.781, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139359, 36847, 658, 3, 1, 0, 0, 1076.03, -25.5486, 633.157, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139360, 36847, 658, 3, 1, 0, 0, 1041.26, -98.5243, 630.805, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139361, 36847, 658, 3, 1, 0, 0, 1076.67, -16.7396, 632.985, 4.45059, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139362, 36847, 658, 3, 1, 0, 0, 1068.78, -70.4063, 633.396, 3.66519, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139363, 36847, 658, 3, 1, 0, 0, 1076.03, -25.5486, 633.157, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139364, 36847, 658, 3, 1, 0, 0, 1018.17, -130.429, 623.537, 0.15708, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139365, 36847, 658, 3, 1, 0, 0, 970.95, -128.878, 601.532, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139366, 36847, 658, 3, 1, 0, 0, 1048.78, -115.236, 629.419, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139367, 36847, 658, 3, 1, 0, 0, 1071.78, -19.1458, 633.174, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139368, 36847, 658, 3, 1, 0, 0, 1018.17, -130.429, 623.537, 0.15708, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139369, 36847, 658, 3, 1, 0, 0, 1039.86, -115.92, 628.833, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139370, 36847, 658, 3, 1, 0, 0, 1068.78, -70.4063, 633.396, 3.66519, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139371, 36847, 658, 3, 1, 0, 0, 1082.01, 29.5747, 630.368, 4.08407, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139372, 36847, 658, 3, 1, 0, 0, 1056.59, -109.167, 630.891, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139373, 36847, 658, 3, 1, 0, 0, 1073.6, 89.8524, 631.606, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139374, 36847, 658, 3, 1, 0, 0, 1048.78, -115.236, 629.419, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139375, 36847, 658, 3, 1, 0, 0, 1068.78, -70.4063, 633.396, 3.66519, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139376, 36847, 658, 3, 1, 0, 0, 1070.19, 8.39063, 635.596, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139377, 36847, 658, 3, 1, 0, 0, 1070.62, -84.4514, 633.036, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139378, 36847, 658, 3, 1, 0, 0, 948.851, -111.17, 595.13, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139379, 36847, 658, 3, 1, 0, 0, 1070.62, -84.4514, 633.036, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139380, 36847, 658, 3, 1, 0, 0, 981.66, -134.417, 607.866, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139381, 36847, 658, 3, 1, 0, 0, 1050.19, 109.042, 628.479, 5.5676, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139382, 36847, 658, 3, 1, 0, 0, 1074.6, 71.1458, 631.068, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139383, 36847, 658, 3, 1, 0, 0, 1027.41, -134.373, 624.973, 2.84489, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139384, 36847, 658, 3, 1, 0, 0, 1068.64, 27.0972, 631.282, 4.08407, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139385, 36847, 658, 3, 1, 0, 0, 1059.43, -39.0729, 633.943, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139386, 36847, 658, 3, 1, 0, 0, 1015.34, -122.51, 622.795, 3.7001, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139387, 36847, 658, 3, 1, 0, 0, 1041.45, -125.929, 627.413, 3.59538, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139388, 36847, 658, 3, 1, 0, 0, 990.997, -124.531, 609.625, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139389, 36847, 658, 3, 1, 0, 0, 1059.53, 59.9618, 631.987, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139390, 36847, 658, 3, 1, 0, 0, 1037.52, -125.868, 627.045, 2.94961, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139391, 36847, 658, 3, 1, 0, 0, 951.469, -96.0486, 595.238, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139392, 36847, 658, 3, 1, 0, 0, 1069.24, -10.6545, 633.781, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139393, 36847, 658, 3, 1, 0, 0, 1048.78, -115.236, 629.419, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139394, 36847, 658, 3, 1, 0, 0, 1066.98, 43.559, 630.154, 0.506145, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139395, 36847, 658, 3, 1, 0, 0, 1069.6, 38.2292, 629.868, 4.95674, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139396, 36847, 658, 3, 1, 0, 0, 996.191, -138.967, 615.289, 2.07694, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139397, 36847, 658, 3, 1, 0, 0, 1069.48, -85.151, 633.061, 4.2237, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139398, 36847, 658, 3, 1, 0, 0, 1056.59, -109.167, 630.891, 0.10472, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139399, 36847, 658, 3, 1, 0, 0, 1010.18, -141.198, 621.042, 2.49582, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139400, 36847, 658, 3, 1, 0, 0, 1000.3, -126.005, 615.862, 2.07694, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139401, 36847, 658, 3, 1, 0, 0, 1029.76, -114.705, 626.664, 2.94961, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139402, 36847, 658, 3, 1, 0, 0, 1010.18, -141.198, 621.042, 2.49582, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139403, 36847, 658, 3, 1, 0, 0, 1008.45, -127.712, 620.498, 2.49582, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139404, 36847, 658, 3, 1, 0, 0, 958.288, -120.444, 596.854, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139405, 36847, 658, 3, 1, 0, 0, 1083.67, 6.56424, 633.7, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139406, 36847, 658, 3, 1, 0, 0, 947.764, -97.849, 595.385, 5.74213, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139407, 36847, 658, 3, 1, 0, 0, 958.288, -120.444, 596.854, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139408, 36847, 658, 3, 1, 0, 0, 1068.78, -70.4063, 633.396, 3.66519, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139409, 36847, 658, 3, 1, 0, 0, 1000.3, -126.005, 615.862, 2.07694, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139410, 36847, 658, 3, 1, 0, 0, 1076.03, -25.5486, 633.157, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139411, 36847, 658, 3, 1, 0, 0, 966.177, -115.295, 597.076, 5.74213, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139412, 36847, 658, 3, 1, 0, 0, 1070.19, 8.39063, 635.596, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139413, 36847, 658, 3, 1, 0, 0, 1027.41, -134.373, 624.973, 2.84489, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139414, 36847, 658, 3, 1, 0, 0, 1069.37, -52.0087, 633.837, 4.5204, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139415, 36847, 658, 3, 1, 0, 0, 1060.12, 88.0052, 630.991, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139416, 36847, 658, 3, 1, 0, 0, 990.997, -124.531, 609.625, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139417, 36847, 658, 3, 1, 0, 0, 1064.83, -44.6389, 634.187, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139418, 36847, 658, 3, 1, 0, 0, 1039.86, -115.92, 628.833, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139419, 36847, 658, 3, 1, 0, 0, 1060.12, 88.0052, 630.991, 0.890118, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139420, 36847, 658, 3, 1, 0, 0, 980.286, -118.993, 601.536, 1.64061, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139421, 36847, 658, 3, 1, 0, 0, 1037.52, -125.868, 627.045, 2.94961, 604800, 0, 0, 42, 0, 0, 0, 0, 0),
(139422, 36847, 658, 3, 1, 0, 0, 1062.55, -23.7222, 634.076, 0.628319, 604800, 0, 0, 42, 0, 0, 0, 0, 0);


##############################
########## [레이드] ##########
##############################

##### 아제로스 레이드 보스 젠시간 #####
UPDATE `creature` SET `spawntimesecs`='604800' WHERE `id` IN (12118,11982,12259,12057,12264,12056,11988,12098,12435,13020,12017,11983,14601,11981,14020,11583,15263,15516,15510,15509,15276,15275,15727,15543,15544,15511,15299,15517);
UPDATE `creature` SET `spawntimesecs`='259200' WHERE `id` IN (15348,15341,15340,15370,15369,15339,14517,14507,14510,14509,14515,14834,11382,11380);

##### 줄구룹 #####
-- 혈군주 만도키르 이벤트발생X 공격가능
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=11382;

##### 낙스마라스 #####
-- 낙스, 프웜 날개짓 수정
DELETE FROM areatrigger_scripts WHERE `entry`=4156;
INSERT INTO areatrigger_scripts VALUES (4156,'at_naxxramas_frostwyrm_wing');

-- 낙스, 글루스 수정
DELETE FROM spell_script_names WHERE spell_id IN (28374, 54426);
INSERT INTO spell_script_names VALUES (28374, "spell_gluth_decimate"),(54426, "spell_gluth_decimate");

##### 오닉시아 #####
-- 오닉시아 둥지에서 전멸시 유령 스타팅 포인트 정상적으로 수정 (얼라이언스, 호드 공통)
DELETE FROM `game_graveyard_zone` WHERE `ghost_zone`='2159';
INSERT INTO `game_graveyard_zone` VALUES (1265,2159,0);

##### 아카본 #####
-- 아카본의 콜라론 업적
DELETE FROM achievement_criteria_data WHERE criteria_id IN (11478, 11479);
INSERT INTO achievement_criteria_data VALUES (11478, 12, 0, 0, ""), (11479, 12, 1, 0, "");

-- 아카본 진입 조정 (얼라이언스만 1733 / 호드만 1735 / 둘다 0)
UPDATE `gameobject_template` SET `faction`=0 WHERE `entry`=190763;

-- 토라본 10/25 드랍테이블 : 코랄론과 동일
DELETE FROM `creature_loot_template` WHERE `entry` IN (38433,38462);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(38433, 1, 100, 1, 0, -34212, 1),(38433, 2, 100, 1, 0, -34204, 1),(38433, 3, 1, 1, 0, -34203, 1),(38433, 4, 20, 1, 0, -90003, 1),(38433, 47241, 100, 1, 0, 2, 2),(38462, 1, 100, 1, 0, -34213, 2),(38462, 2, 100, 1, 0, -34205, 2),(38462, 3, 1, 1, 0, -34203, 1),(38462, 4, 20, 1, 0, -90004, 1),(38462, 47241, 100, 1, 0, 2, 2);


##### 울두아르 #####


##### 마상 시합장(TOC) #####
-- 노스랜드 야수들 잡을시 던젼 귀속
UPDATE `creature_template` SET `flags_extra`='1' WHERE `entry` IN (35514,35515,35516,35511,35512,35513);

-- 십자군 바닥 HP
UPDATE `gameobject_template` SET `data0`=10000000 WHERE `entry`=195527;

-- 아눕아락 서리문장 드랍
DELETE FROM `reference_loot_template` WHERE `entry`=34564 AND `item`=47241;
DELETE FROM `reference_loot_template` WHERE `entry`=34566 AND `item`=47241; 
DELETE FROM `reference_loot_template` WHERE `entry`=35615 AND `item`=47241; 
DELETE FROM `reference_loot_template` WHERE `entry`=35616 AND `item`=47241;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(34564,49426,25,1,0,5,10),(34566,49426,50,1,0,5,10),(35615,49426,50,1,0,5,10),(35616,49426,75,1,0,5,10);


##### 얼왕성채 #####
-- 얼왕성채 버프 삭제
DELETE FROM `spell_area` WHERE `spell` IN (73822,73828);

-- 얼왕 착귀템 획귀템 변경
-- UPDATE `item_template` SET `bonding`=1 WHERE `entry` IN (49967,49994,50001,50015,50020,50038,50069,50175,50182,50472,50444,50447,50449,50450,50451,50452,50453);

-- 얼왕평판 수치 변경
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` ='0' WHERE `RewOnKillRepFaction1` = '1156';
REPLACE INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES
(36612, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36855, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(37813, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36627, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36626, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36678, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(37970, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(37955, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36853, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36597, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(36597, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(37957, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38106, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38402, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38390, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(37504, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38431, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38401, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38434, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38265, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(39166, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(37958, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38296, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38582, 1156, 1156, 4, 0, 300, 5, 0, 200, 0),(38549, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(37505, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38585, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38784, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38435, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(38266, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(39167, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(37959, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38297, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38583, 1156, 1156, 5, 0, 200, 6, 0, 150, 0),(38550, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(37506, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(38586, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(38785, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(38436, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(38267, 1156, 1156, 6, 0, 150, 7, 0, 100, 0),(39168, 1156, 1156, 6, 0, 150, 7, 0, 100, 0);

-- 얼왕 착귀 룻테이블 삭제 및 재생성 (신규 착귀템 테이블 91001)
DELETE FROM `reference_loot_template` WHERE `entry`=35068;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(35068,38,0,1,1,1,1),(35068,39,0,1,1,1,1),(35068,40,0,1,1,1,1),(35068,43,0,1,1,1,1),(35068,44,0,1,1,1,1),(35068,45,0,1,1,1,1),(35068,47,0,1,1,1,1),(35068,48,0,1,1,1,1),(35068,49,0,1,1,1,1),(35068,51,0,1,1,1,1),(35068,52,0,1,1,1,1),(35068,53,0,1,1,1,1),(35068,55,0,1,1,1,1),(35068,56,0,1,1,1,1),(35068,57,0,1,1,1,1),(35068,59,0,1,1,1,1),
(91001,50444,0,1,1,1,1),(91001,50447,0,1,1,1,1),(91001,50449,0,1,1,1,1),(91001,50450,0,1,1,1,1),(91001,50451,0,1,1,1,1),(91001,50452,0,1,1,1,1),(91001,50453,0,1,1,1,1);

-- 얼왕 착귀템 25인일반/10인하드 라나텔, 신드라고사, 리치왕 25% 드랍
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(39166,3,25,1,0,-91001,1),(39167,3,25,1,0,-91001,1),(38434,3,25,1,0,-91001,1),(38435,3,25,1,0,-91001,1),(38265,3,25,1,0,-91001,1),(38266,3,25,1,0,-91001,1);

-- 얼왕 일퀘 착귀템 드랍제거
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=49967;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=49994;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50001;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50015;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50020;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50038;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50069;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50175;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50182;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50444;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50447;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50449;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50450;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50451;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50452;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50453;
DELETE FROM `item_loot_template` WHERE `entry`=52006 and `item`=50472;

-- 비행선 룻테이블
DELETE FROM `reference_loot_template` WHERE `entry` IN (91002,91003,91004,91005);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
-- 10인 일반
(91002, 50340, 0, 1, 1, 1, 1),(91002, 50787, 0, 1, 1, 1, 1),(91002, 50788, 0, 1, 1, 1, 1),(91002, 50789, 0, 1, 1, 1, 1),(91002, 50790, 0, 1, 1, 1, 1),(91002, 50791, 0, 1, 1, 1, 1),(91002, 50792, 0, 1, 1, 1, 1),(91002, 50793, 0, 1, 1, 1, 1),(91002, 50794, 0, 1, 1, 1, 1),(91002, 50795, 0, 1, 1, 1, 1),(91002, 50796, 0, 1, 1, 1, 1),(91002, 50797, 0, 1, 1, 1, 1),
-- 25인 일반
(91003, 49998, 0, 1, 1, 1, 1),(91003, 49999, 0, 1, 1, 1, 1),(91003, 50000, 0, 1, 1, 1, 1),(91003, 50001, 0, 1, 1, 1, 1),(91003, 50002, 0, 1, 1, 1, 1),(91003, 50003, 0, 1, 1, 1, 1),(91003, 50005, 0, 1, 1, 1, 1),(91003, 50006, 0, 1, 1, 1, 1),(91003, 50008, 0, 1, 1, 1, 1),(91003, 50009, 0, 1, 1, 1, 1),(91003, 50010, 0, 1, 1, 1, 1),(91003, 50011, 0, 1, 1, 1, 1),(91003, 50352, 0, 1, 1, 1, 1),(91003, 50359, 0, 1, 1, 1, 1),(91003, 50411, 0, 1, 1, 1, 1),
-- 10인 하드
(91004, 50345, 0, 1, 1, 1, 1),(91004, 51906, 0, 1, 1, 1, 1),(91004, 51907, 0, 1, 1, 1, 1),(91004, 51908, 0, 1, 1, 1, 1),(91004, 51909, 0, 1, 1, 1, 1),(91004, 51910, 0, 1, 1, 1, 1),(91004, 51911, 0, 1, 1, 1, 1),(91004, 51912, 0, 1, 1, 1, 1),(91004, 51913, 0, 1, 1, 1, 1),(91004, 51914, 0, 1, 1, 1, 1),(91004, 51915, 0, 1, 1, 1, 1),(91004, 51916, 0, 1, 1, 1, 1),
-- 25인 하드
(91005, 50349, 0, 1, 1, 1, 1),(91005, 50366, 0, 1, 1, 1, 1),(91005, 50653, 0, 1, 1, 1, 1),(91005, 50654, 0, 1, 1, 1, 1),(91005, 50655, 0, 1, 1, 1, 1),(91005, 50656, 0, 1, 1, 1, 1),(91005, 50657, 0, 1, 1, 1, 1),(91005, 50658, 0, 1, 1, 1, 1),(91005, 50659, 0, 1, 1, 1, 1),(91005, 50660, 0, 1, 1, 1, 1),(91005, 50661, 0, 1, 1, 1, 1),(91005, 50663, 0, 1, 1, 1, 1),(91005, 50664, 0, 1, 1, 1, 1),(91005, 50665, 0, 1, 1, 1, 1),(91005, 50667, 0, 1, 1, 1, 1);

-- 교수 비행선 아이템 추가드랍
DELETE FROM `creature_loot_template` WHERE `mincountOrRef` IN (-91002,-91003,-91004,-91005);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(36678,2,40,1,0,-91002,1),(38431,2,40,1,0,-91003,2),(38585,3,40,1,0,-91004,1),(38586,2,40,1,0,-91005,2);

-- 신드라고사 / 리치왕 종족 타입변경
UPDATE `creature_template` SET `type` ='7' WHERE `entry` IN (36597,39166,39167,39168);
UPDATE `creature_template` SET `type` ='2' WHERE `entry` IN (36853,38265,38266,38267);

-- 구린속/썩은얼굴 바닥구현
DELETE FROM `spell_linked_spell` WHERE `spell_effect` IN (72144,72145);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(69291, 72144, 1, 'Festergut: Apply Orange Blight Residue'),
(72101, 72144, 1, 'Festergut: Apply Orange Blight Residue'),
(72102, 72144, 1, 'Festergut: Apply Orange Blight Residue'),
(72103, 72144, 1, 'Festergut: Apply Orange Blight Residue'),
(69507, 72145, 1, 'Rotface: Apply Green Blight Residue'),
(71213, 72145, 1, 'Rotface: Apply Green Blight Residue'),
(73189, 72145, 1, 'Rotface: Apply Green Blight Residue'),
(73190, 72145, 1, 'Rotface: Apply Green Blight Residue');

-- 보스 잘못된 데미지 계산표 수정
-- Lord Marrowgar
UPDATE `creature_template` SET `dmg_multiplier`=55 WHERE `entry`=36612;
UPDATE `creature_template` SET `dmg_multiplier`=85 WHERE `entry`=37957;
UPDATE `creature_template` SET `dmg_multiplier`=75 WHERE `entry`=37958;
UPDATE `creature_template` SET `dmg_multiplier`=100 WHERE `entry`=37959;

-- Lady Deathwhisper
UPDATE `creature_template` SET `dmg_multiplier`=45 WHERE `entry`=36855;
UPDATE `creature_template` SET `dmg_multiplier`=70 WHERE `entry`=38106;
UPDATE `creature_template` SET `dmg_multiplier`=80 WHERE `entry`=38296;
UPDATE `creature_template` SET `dmg_multiplier`=100 WHERE `entry`=38297;

-- Deathbringer Saurfang
UPDATE `creature_template` SET `dmg_multiplier`=60 WHERE `entry`=37813;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38402;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38582;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38583;

-- Festergut
UPDATE `creature_template` SET `dmg_multiplier`=75 WHERE `entry`=36626;
UPDATE `creature_template` SET `dmg_multiplier`=115 WHERE `entry`=37504;
UPDATE `creature_template` SET `dmg_multiplier`=115 WHERE `entry`=37505;
UPDATE `creature_template` SET `dmg_multiplier`=150 WHERE `entry`=37506;

-- Rotface
UPDATE `creature_template` SET `dmg_multiplier`=70 WHERE `entry`=36627;
UPDATE `creature_template` SET `dmg_multiplier`=100 WHERE `entry`=38390;
UPDATE `creature_template` SET `dmg_multiplier`=100 WHERE `entry`=38549;
UPDATE `creature_template` SET `dmg_multiplier`=140 WHERE `entry`=38550;

-- Professor Putricide
UPDATE `creature_template` SET `dmg_multiplier`=60 WHERE `entry`=36678;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38431;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38585;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38586;

-- Blood Prince Council
UPDATE `creature_template` SET `dmg_multiplier`=65 WHERE `entry` IN (37970, 37973, 37972);
UPDATE `creature_template` SET `dmg_multiplier`=95 WHERE `entry` IN (38401, 38400, 38399);
UPDATE `creature_template` SET `dmg_multiplier`=95 WHERE `entry` IN (38784, 38771, 38769);
UPDATE `creature_template` SET `dmg_multiplier`=130 WHERE `entry` IN (38785, 38772, 38770);

-- Blood Queen Lana'thel
UPDATE `creature_template` SET `dmg_multiplier`=60 WHERE `entry`=37955;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38434;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38435;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38436;

-- Sindragosa
UPDATE `creature_template` SET `dmg_multiplier`=60 WHERE `entry`=36853;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38265;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38266;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38267;

-- 신드라고사 10인 잘못된 데미지 수정
UPDATE `creature_template` SET `mindmg`=509, `maxdmg`=683, `attackpower`=805 WHERE `entry`=36853;
