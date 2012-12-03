-- 위안 발동효과 재수정
DELETE FROM `spell_proc_event` WHERE `entry` IN (67752,67698);
INSERT INTO `spell_proc_event` VALUES(67752, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0), (67698, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0);
