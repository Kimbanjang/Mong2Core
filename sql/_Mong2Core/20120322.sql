DELETE FROM `creature_loot_template` WHERE `mincountOrRef` IN (-91002,-91003,-91004,-91005);
-- 교수 비행선 아이템 추가드랍
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(36678,2,40,1,0,-91002,2),(38431,2,40,1,0,-91003,3),(38585,3,40,1,0,-91004,2),(38586,2,40,1,0,-91005,3);

-- 열세진영정책 회수
UPDATE `playercreateinfo_item` SET `amount`=2 WHERE `race`=1 and `itemid`=23162;
UPDATE `playercreateinfo_item` SET `amount`=2 WHERE `race`=3 and `itemid`=23162;
UPDATE `playercreateinfo_item` SET `amount`=2 WHERE `race`=4 and `itemid`=23162;
UPDATE `playercreateinfo_item` SET `amount`=2 WHERE `race`=7 and `itemid`=23162;
UPDATE `playercreateinfo_item` SET `amount`=2 WHERE `race`=11 and `itemid`=23162;
DELETE FROM `playercreateinfo_item` WHERE `itemid` IN (60001);
DELETE FROM `spell_area` WHERE `spell`=16609 and `area`=4723;
DELETE FROM `spell_area` WHERE `spell`=16609 and `area`=4809;
DELETE FROM `spell_area` WHERE `spell`=16609 and `area`=4904; 
DELETE FROM `spell_area` WHERE `spell`=16609 and `area`=4820;
-- 10N
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34797 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34797 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34780 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34780 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34497 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34497 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34564 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34564 AND `item`=2;
-- 25N
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35447 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35447 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35216 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35216 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35350 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35350 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=34566 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=34566 AND `item`=2;
-- 10H
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35448 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35448 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35268 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35268 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35351 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35351 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35615 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35615 AND `item`=2;
-- 25H
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35449 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35449 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35269 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35269 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35352 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35352 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35616 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35616 AND `item`=2;
