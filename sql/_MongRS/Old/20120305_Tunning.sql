-- 얼라이언스 가방 4개
UPDATE `playercreateinfo_item` SET `amount`=4 WHERE `race`=1 and `itemid`=23162;
UPDATE `playercreateinfo_item` SET `amount`=4 WHERE `race`=3 and `itemid`=23162;
UPDATE `playercreateinfo_item` SET `amount`=4 WHERE `race`=4 and `itemid`=23162;
UPDATE `playercreateinfo_item` SET `amount`=4 WHERE `race`=7 and `itemid`=23162;
UPDATE `playercreateinfo_item` SET `amount`=4 WHERE `race`=11 and `itemid`=23162;

-- 얼라이언스 옷감
-- INSERT INTO `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) VALUES
-- (1, 1, 2592, 300),(1, 2, 2592, 300),(1, 4, 2592, 300),(1, 5, 2592, 300),(1, 8, 2592, 300),(1, 9, 2592, 300),(3, 1, 2592, 300),(3, 2, 2592, 300),(3, 3, 2592, 300),(3, 4, 2592, 300),(3, 5, 2592, 300),(4, 1, 2592, 300),(4, 3, 2592, 300),(4, 4, 2592, 300),(4, 5, 2592, 300),(4, 11, 2592, 300),(7, 1, 2592, 300),(7, 9, 2592, 300),(7, 8, 2592, 300),(7, 4, 2592, 300),(11, 1, 2592, 300),(11, 2, 2592, 300),(11, 3, 2592, 300),(11, 5, 2592, 300),(11, 7, 2592, 300),(11, 8, 2592, 300),(1, 6, 2592, 300),(3, 6, 2592, 300),(4, 6, 2592, 300),(7, 6, 2592, 300),(11, 6, 2592, 300),
-- (1, 1, 4306, 300),(1, 2, 4306, 300),(1, 4, 4306, 300),(1, 5, 4306, 300),(1, 8, 4306, 300),(1, 9, 4306, 300),(3, 1, 4306, 300),(3, 2, 4306, 300),(3, 3, 4306, 300),(3, 4, 4306, 300),(3, 5, 4306, 300),(4, 1, 4306, 300),(4, 3, 4306, 300),(4, 4, 4306, 300),(4, 5, 4306, 300),(4, 11, 4306, 300),(7, 1, 4306, 300),(7, 9, 4306, 300),(7, 8, 4306, 300),(7, 4, 4306, 300),(11, 1, 4306, 300),(11, 2, 4306, 300),(11, 3, 4306, 300),(11, 5, 4306, 300),(11, 7, 4306, 300),(11, 8, 4306, 300),(1, 6, 4306, 300),(3, 6, 4306, 300),(4, 6, 4306, 300),(7, 6, 4306, 300),(11, 6, 4306, 300),
-- (1, 1, 4338, 300),(1, 2, 4338, 300),(1, 4, 4338, 300),(1, 5, 4338, 300),(1, 8, 4338, 300),(1, 9, 4338, 300),(3, 1, 4338, 300),(3, 2, 4338, 300),(3, 3, 4338, 300),(3, 4, 4338, 300),(3, 5, 4338, 300),(4, 1, 4338, 300),(4, 3, 4338, 300),(4, 4, 4338, 300),(4, 5, 4338, 300),(4, 11, 4338, 300),(7, 1, 4338, 300),(7, 9, 4338, 300),(7, 8, 4338, 300),(7, 4, 4338, 300),(11, 1, 4338, 300),(11, 2, 4338, 300),(11, 3, 4338, 300),(11, 5, 4338, 300),(11, 7, 4338, 300),(11, 8, 4338, 300),(1, 6, 4338, 300),(3, 6, 4338, 300),(4, 6, 4338, 300),(7, 6, 4338, 300),(11, 6, 4338, 300),
-- (1, 1, 14047, 300),(1, 2, 14047, 300),(1, 4, 14047, 300),(1, 5, 14047, 300),(1, 8, 14047, 300),(1, 9, 14047, 300),(3, 1, 14047, 300),(3, 2, 14047, 300),(3, 3, 14047, 300),(3, 4, 14047, 300),(3, 5, 14047, 300),(4, 1, 14047, 300),(4, 3, 14047, 300),(4, 4, 14047, 300),(4, 5, 14047, 300),(4, 11, 14047, 300),(7, 1, 14047, 300),(7, 9, 14047, 300),(7, 8, 14047, 300),(7, 4, 14047, 300),(11, 1, 14047, 300),(11, 2, 14047, 300),(11, 3, 14047, 300),(11, 5, 14047, 300),(11, 7, 14047, 300),(11, 8, 14047, 300),(1, 6, 14047, 300),(3, 6, 14047, 300),(4, 6, 14047, 300),(7, 6, 14047, 300),(11, 6, 14047, 300);

-- 아카본 얼라이언스만 진입
-- UPDATE `gameobject_template` SET `faction`=1733 WHERE `entry`=190763;

-- 십자군 레이드 아이템 드랍수 변경 (item=1 얼라이언스 / item=2 호드)
-- 10N
UPDATE `creature_loot_template` SET `maxcount`=5 WHERE `entry`=34797 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34797 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=5 WHERE `entry`=34780 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34780 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=5 WHERE `entry`=34497 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34497 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=5 WHERE `entry`=34564 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34564 AND `item`=2;
-- 25N
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35447 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35447 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=5 WHERE `entry`=35216 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35216 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=35350 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35350 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=4 WHERE `entry`=34566 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=34566 AND `item`=2;
-- 10H
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35448 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35448 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35268 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35268 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35351 AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35351 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry`=35615 AND `item`=1;
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
