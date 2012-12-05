-- 투명화 다시 시도
DELETE FROM `spell_linked_spell` WHERE `spell_effect`='54661' AND `spell_trigger` IN (32612,5215,1784,1856);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES ('32612', '54661', '0', 'Invisibility Sanctuary Effect'),('5215', '54661', '0', 'Prowl Sanctuary Effect'),('1784', '54661', '0', 'Stealth Sanctuary Effect'),('1856', '54661', '0', 'Stealth Sanctuary Effect');

-- 마법사 투명화 어그로 리셋 (핵이므로 차후 수정시 되돌려야 함) : 이것 안됨. 이거 때문에 눈속이랑 속거도 안되는거 같음
-- UPDATE `spell_dbc` SET `AttributesEx3` = `AttributesEx3` | 131072 WHERE `id` = 35009;
