-- 신드라고사 / 리치왕 종족 타입변경 (7/2 - 언데드 관련 스킬로 바보 만들기 픽스 했던것. 사용해보고 적용할 것)
UPDATE `creature_template` SET `type` ='6' WHERE `entry` IN (36597,39166,39167,39168);
UPDATE `creature_template` SET `type` ='6' WHERE `entry` IN (36853,38265,38266,38267);

-- 마법사 투명화 어그로 리셋 (핵이므로 차후 수정시 되돌려야 함)
UPDATE `spell_dbc` SET `AttributesEx3` = `AttributesEx3` | 131072 WHERE `id` = 35009;
