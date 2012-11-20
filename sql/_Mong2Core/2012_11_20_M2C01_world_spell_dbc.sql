-- 마법사 투명화 어그로 리셋 (핵이므로 차후 수정시 되돌려야 함)
UPDATE `spell_dbc` SET `AttributesEx3` = `AttributesEx3` | 131072 WHERE `id` = 35009;
