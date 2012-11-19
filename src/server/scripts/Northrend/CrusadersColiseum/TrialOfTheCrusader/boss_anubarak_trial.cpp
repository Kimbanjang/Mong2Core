/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// Known bugs:
// Anubarak - underground phase partially not worked
//          - tele after impale hit a permafrost doesn't work (the entire tele spell should be better)
// Scarab   - Kill credit isn't crediting?

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "trial_of_the_crusader.h"
#include <limits>

enum Yells
{
    SAY_INTRO               = 0,
    SAY_AGGRO               = 1,
    EMOTE_SUBMERGE          = 2,
    EMOTE_BURROWER          = 3,
    SAY_EMERGE              = 4,
    SAY_LEECHING_SWARM      = 5,
    EMOTE_LEECHING_SWARM    = 6,
    SAY_KILL_PLAYER         = 7,
    SAY_DEATH               = 8,

    EMOTE_SPIKE             = 0
};

enum Summons
{
    NPC_FROST_SPHERE     = 34606,
    NPC_BURROW           = 34862,
    NPC_BURROWER         = 34607,
    NPC_SCARAB           = 34605,
    NPC_SPIKE            = 34660
};

enum BossSpells
{
    SPELL_FREEZE_SLASH      = 66012,
    SPELL_PENETRATING_COLD  = 66013,
    SPELL_LEECHING_SWARM    = 66118,
    SPELL_LEECHING_HEAL     = 66125,
    SPELL_LEECHING_DAMAGE   = 66240,
    SPELL_MARK              = 67574,
    SPELL_SPIKE_CALL        = 66169,
    SPELL_SUBMERGE_ANUBARAK = 65981,
    SPELL_CLEAR_ALL_DEBUFFS = 34098,
    SPELL_EMERGE_ANUBARAK   = 65982,
    SPELL_SUMMON_BEATLES    = 66339,
    SPELL_SUMMON_BURROWER   = 66332,

    // Burrow
    SPELL_CHURNING_GROUND   = 66969,

    // Scarab
    SPELL_DETERMINATION     = 66092,
    SPELL_TRIGGERED_ACID_MANDIBLE_0 = 65775,
    SPELL_TRIGGERED_ACID_MANDIBLE_1 = 67861,
    SPELL_TRIGGERED_ACID_MANDIBLE_2 = 67862,
    SPELL_TRIGGERED_ACID_MANDIBLE_3 = 67863,

    // Burrower
    SPELL_SPIDER_FRENZY     = 66129,
    SPELL_EXPOSE_WEAKNESS   = 67720, //Passive - Triggered
    SPELL_SHADOW_STRIKE     = 66134,
<<<<<<< HEAD
    SPELL_SUBMERGE_EFFECT   = 53421,
    SPELL_EMERGE_EFFECT     = 66947,
=======
    SPELL_SUBMERGE_EFFECT   = 68394,
    SPELL_AWAKENED          = 66311,
    SPELL_EMERGE_EFFECT     = 65982,

    SPELL_PERSISTENT_DIRT   = 68048,
>>>>>>> TC/master

    SUMMON_SCARAB           = NPC_SCARAB,
    SUMMON_FROSTSPHERE      = NPC_FROST_SPHERE,
    SPELL_BERSERK           = 26662,

    //Frost Sphere
    SPELL_FROST_SPHERE      = 67539,
    SPELL_PERMAFROST_VISUAL = 65882,

    //Spike
    SPELL_SUMMON_SPIKE      = 66169,
    SPELL_SPIKE_SPEED1      = 65920,
    SPELL_SPIKE_TRAIL       = 65921,
    SPELL_SPIKE_SPEED2      = 65922,
    SPELL_SPIKE_SPEED3      = 65923,
    SPELL_SPIKE_FAIL        = 66181,
    SPELL_SPIKE_TELE        = 66170
};

#define SPELL_PERMAFROST    RAID_MODE(66193, 67855, 67856, 67857)
#define SPELL_IMPALE        RAID_MODE(65919, 67858, 67859, 67860)

enum SummonActions
{
<<<<<<< HEAD
    ACTION_SHADOW_STRIKE,
=======
    ACTION_SHADOW_STRIKE    = 0,
    ACTION_SCARAB_SUBMERGE  = 1
>>>>>>> TC/master
};

const Position SphereSpawn[6] =
{
    { 776.8380f, 125.6795f, 155.6701f, 0 },
    { 786.4426f, 145.5566f, 155.6701f, 0 },
    { 759.1386f, 163.9654f, 155.6701f, 0 },
    { 744.3701f, 119.5211f, 155.6701f, 0 },
    { 710.0211f, 120.8152f, 155.6701f, 0 },
    { 706.6383f, 161.5266f, 155.6701f, 0 },
};

enum MovementPoints
{
    POINT_FALL_GROUND           = 1
};

enum PursuingSpikesPhases
{
    PHASE_NO_MOVEMENT       = 0,
    PHASE_IMPALE_NORMAL     = 1,
    PHASE_IMPALE_MIDDLE     = 2,
    PHASE_IMPALE_FAST       = 3
};

enum Events
{
    // Anub'arak
    EVENT_FREEZE_SLASH              = 1,
    EVENT_PENETRATING_COLD          = 2,
    EVENT_SUMMON_NERUBIAN           = 3,
    EVENT_NERUBIAN_SHADOW_STRIKE    = 4,
    EVENT_SUBMERGE                  = 5,
    EVENT_EMERGE                    = 6,
    EVENT_PURSUING_SPIKE            = 7,
    EVENT_SUMMON_SCARAB             = 8,
    EVENT_SUMMON_FROST_SPHERE       = 9,
    EVENT_BERSERK                   = 10
};

enum Phases
{
    // Anub'arak
    PHASE_MELEE                 = 1,
    PHASE_SUBMERGED             = 2,

<<<<<<< HEAD
        InstanceScript* instance;

        SummonList Summons;

        uint32 m_uiFreezeSlashTimer;
        uint32 m_uiPenetratingColdTimer;
        uint32 m_uiSummonNerubianTimer;
        uint32 m_uiNerubianShadowStrikeTimer;
        uint32 m_uiSubmergeTimer;
        float m_posPursuingSpikePositionX;
        float m_posPursuingSpikePositionY;
        float m_posPursuingSpikePositionZ;
        uint32 m_uiPursuingSpikeTimer;
        uint32 m_uiSummonScarabTimer;
        uint32 m_uiSummonFrostSphereTimer;
        uint32 m_uiBerserkTimer;

        uint8  m_uiStage;
        bool   m_bIntro;
        bool   m_bReachedPhase3;
        uint64 m_uiTargetGUID;

        void Reset()
        {
            m_uiFreezeSlashTimer = 15*IN_MILLISECONDS;
            m_uiPenetratingColdTimer = 20*IN_MILLISECONDS;
            m_uiNerubianShadowStrikeTimer = 30*IN_MILLISECONDS;
            m_uiSummonNerubianTimer = 10*IN_MILLISECONDS;
            m_uiSubmergeTimer = 80*IN_MILLISECONDS;

            m_posPursuingSpikePositionX = 0.0f;
            m_posPursuingSpikePositionY = 0.0f;
            m_posPursuingSpikePositionZ = 0.0f;
            m_uiPursuingSpikeTimer = 2*IN_MILLISECONDS;

            m_uiSummonFrostSphereTimer = urand(20, 30)*1000;

            m_uiBerserkTimer = 10*MINUTE*IN_MILLISECONDS;
            m_uiStage = 0;
            m_bIntro = true;
            m_bReachedPhase3 = false;
            m_uiTargetGUID = 0;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_PERMAFROST, true);
            Summons.DespawnAll();
        }
=======
    PHASE_MASK_MELEE            = 1 << PHASE_MELEE
};
>>>>>>> TC/master

class boss_anubarak_trial : public CreatureScript
{
    public:
        boss_anubarak_trial() : CreatureScript("boss_anubarak_trial") { }

        struct boss_anubarak_trialAI : public BossAI
        {
            boss_anubarak_trialAI(Creature* creature) : BossAI(creature, BOSS_ANUBARAK)
            {
<<<<<<< HEAD
                Talk(SAY_KILL_PLAYER);
                if (instance)
                    instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELIGIBLE, 0);
=======
>>>>>>> TC/master
            }

            void Reset()
            {
                _Reset();
                events.SetPhase(PHASE_MELEE);
                events.ScheduleEvent(EVENT_FREEZE_SLASH, 15*IN_MILLISECONDS, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_PENETRATING_COLD, 20*IN_MILLISECONDS, PHASE_MELEE);
                events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 10*IN_MILLISECONDS, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_SUBMERGE, 80*IN_MILLISECONDS, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_BERSERK, 10*MINUTE*IN_MILLISECONDS);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_NERUBIAN_SHADOW_STRIKE, 30*IN_MILLISECONDS, 0, PHASE_MELEE);

                if (!IsHeroic())
                    events.ScheduleEvent(EVENT_SUMMON_FROST_SPHERE, 20*IN_MILLISECONDS);

                _intro = true;
                _reachedPhase3 = false;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                // clean up spawned Frost Spheres
                std::list<Creature*> FrostSphereList;
                me->GetCreatureListWithEntryInGrid(FrostSphereList, NPC_FROST_SPHERE, 150.0f);
                if (!FrostSphereList.empty())
                    for (std::list<Creature*>::iterator itr = FrostSphereList.begin(); itr != FrostSphereList.end(); itr++)
                        (*itr)->DespawnOrUnsummon();

                _burrowGUID.clear();
            }

<<<<<<< HEAD
        void JustReachedHome()
        {
            if (instance)
                instance->SetData(TYPE_ANUBARAK, FAIL);
        }

        void JustDied(Unit* /*killer*/)
        {
            Summons.DespawnAll();
            Talk(SAY_DEATH);
            if (instance)
                instance->SetData(TYPE_ANUBARAK, DONE);
        }

        void JustSummoned(Creature* summoned)
        {
            switch (summoned->GetEntry())
            {
                case NPC_BURROW:
                    summoned->SetReactState(REACT_PASSIVE);
                    summoned->CastSpell(summoned, SPELL_CHURNING_GROUND, false);
                    break;
                case NPC_SPIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    {
                        summoned->AI()->AttackStart(target);
                        Talk(EMOTE_SPIKE, target->GetGUID());
                    }
                    else
                        m_uiPursuingSpikeTimer = 2000;
                    break;
                case NPC_BURROWER:
                case NPC_SCARAB:
                    summoned->setFaction(14);
                    DoZoneInCombat(summoned);
                    break;
            }
            Summons.Summon(summoned);
        }
=======
            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_KILL_PLAYER);
                    if (instance)
                        instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE, 0);
                }
            }
>>>>>>> TC/master

            void MoveInLineOfSight(Unit* /*who*/)
            {
<<<<<<< HEAD
                case NPC_SPIKE:
                    m_posPursuingSpikePositionX = summoned->GetPositionX();
                    m_posPursuingSpikePositionY = summoned->GetPositionY();
                    m_posPursuingSpikePositionZ = summoned->GetPositionZ();
                    m_uiPursuingSpikeTimer = 2*IN_MILLISECONDS;
                    break;
            }

            Summons.Despawn(summoned);
        }

        uint32 GetPlayerCountInFrostSphereZones()
        {
            uint32 counter = 0;
            Map* map = me->GetMap();

            if (map && map->IsDungeon())
            {
                Map::PlayerList const &PlayerList = map->GetPlayers();

                if (PlayerList.isEmpty())
                    return 0;

                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (i->getSource())
                    {
                        if (i->getSource()->isAlive())
                        {
                            if (i->getSource()->HasAura(SPELL_PERMAFROST))
                                counter++;
                        }
                    }
               }
            }

            return counter;
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            DoZoneInCombat();
            if (instance)
                instance->SetData(TYPE_ANUBARAK, IN_PROGRESS);

            //Spawn Frost Spheres
            for (int i=0; i < 6; i++)
                me->SummonCreature(NPC_FROST_SPHERE, SphereSpawn[i]);
        }
=======
                if (!_intro)
                {
                    Talk(SAY_INTRO);
                    _intro = false;
                }
            }
>>>>>>> TC/master

            void JustReachedHome()
            {
                if (instance)
                    instance->SetBossState(BOSS_ANUBARAK, FAIL);
                //Summon Scarab Swarms neutral at random places
                for (int i = 0; i < 10; i++)
                    if (Creature* temp = me->SummonCreature(NPC_SCARAB, AnubarakLoc[1].GetPositionX()+urand(0, 50)-25, AnubarakLoc[1].GetPositionY()+urand(0, 50)-25, AnubarakLoc[1].GetPositionZ()))
                    {
                        temp->setFaction(31);
                        temp->GetMotionMaster()->MoveRandom(10);
                    }
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);

                // despawn frostspheres and Burrowers on death
                std::list<Creature*> AddList;
                me->GetCreatureListWithEntryInGrid(AddList, NPC_FROST_SPHERE, 150.0f);
                me->GetCreatureListWithEntryInGrid(AddList, NPC_BURROWER, 150.0f);
                if (!AddList.empty())
                    for (std::list<Creature*>::iterator itr = AddList.begin(); itr != AddList.end(); itr++)
                        (*itr)->DespawnOrUnsummon();
            }

            void JustSummoned(Creature* summoned)
            {
<<<<<<< HEAD
                case 0:
                    if (m_uiFreezeSlashTimer <= uiDiff)
                    {
                        DoCastVictim(SPELL_FREEZE_SLASH);
                        m_uiFreezeSlashTimer = urand(8*1000, 10*1000);
                    } else m_uiFreezeSlashTimer -= uiDiff;

                    if (m_uiPenetratingColdTimer <= uiDiff)
                    {
                        me->CastCustomSpell(SPELL_PENETRATING_COLD, SPELLVALUE_MAX_TARGETS, RAID_MODE(2, 5, 2, 5));
                        m_uiPenetratingColdTimer = 18000;
                    } else m_uiPenetratingColdTimer -= uiDiff;

                    if (IsHeroic() || !m_bReachedPhase3)
                    {
                        if (m_uiSummonNerubianTimer <= uiDiff)
                        {
                            uint8 maxSpawns = RAID_MODE(1, 2, 2, 4);

                            for (uint8 i = 0; i < maxSpawns; i++)
                                me->SummonCreature(NPC_BURROWER, AnubarakLoc[i+2], TEMPSUMMON_CORPSE_DESPAWN);

                            m_uiSummonNerubianTimer = 40000;
                        } else m_uiSummonNerubianTimer -= uiDiff;
                    }

                    if (IsHeroic())
                    {
                        if (m_uiNerubianShadowStrikeTimer <= uiDiff)
                        {
                            EntryCheckPredicate pred(NPC_BURROWER);
                            Summons.DoAction(ACTION_SHADOW_STRIKE, pred);
                            m_uiNerubianShadowStrikeTimer = urand(20*1000, 30*1000);
                        } else m_uiNerubianShadowStrikeTimer -= uiDiff;
                    }

                    if (!m_bReachedPhase3 && !me->HasAura(SPELL_BERSERK))
                    {
                        if (m_uiSubmergeTimer <= uiDiff)
                        {
                            m_uiStage = 1;
                            m_uiSubmergeTimer = 60*1000;
                        } else m_uiSubmergeTimer -= uiDiff;
                    }
                    break;
                case 1:
                    DoCast(me, SPELL_SUBMERGE_ANUBARAK);
                    DoCast(me, SPELL_CLEAR_ALL_DEBUFFS);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    Talk(EMOTE_BURROWER);
                    m_uiPursuingSpikeTimer = 2000;
                    m_uiSummonScarabTimer = 4*IN_MILLISECONDS;
                    m_uiStage = 2;
                    break;
                case 2:
                    if (m_uiPursuingSpikeTimer <= uiDiff)
                    {
                        // replace spell with manual spawning so we can restart the spike where it left off.
                        //DoCast(SPELL_SPIKE_CALL);
                        if (m_posPursuingSpikePositionX == 0.0f || m_posPursuingSpikePositionY == 0.0f || m_posPursuingSpikePositionZ == 0.0f)
                            me->SummonCreature(NPC_SPIKE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                        else
                            me->SummonCreature(NPC_SPIKE, m_posPursuingSpikePositionX, m_posPursuingSpikePositionY, m_posPursuingSpikePositionZ);
                        // Just to make sure it won't happen again in this phase
                        m_uiPursuingSpikeTimer = 90*IN_MILLISECONDS;
                    } else m_uiPursuingSpikeTimer -= uiDiff;

                    if (m_uiSummonScarabTimer <= uiDiff)
                    {
                        uint32 playersInFrostSphere = GetPlayerCountInFrostSphereZones();

                        if (playersInFrostSphere > 0)
                        {
                            uint8 location = 2;
                            for (uint8 i = 0; i < playersInFrostSphere * RAID_MODE(1, 2, 2, 3); i++)
                            {
                                location++;

                                if (location >= 6)
                                    location = 2;

                                me->SummonCreature(NPC_SCARAB, AnubarakLoc[location], TEMPSUMMON_CORPSE_DESPAWN);
                            }
                        }
                        else
                        {
                            if (!me->GetMap())
                                return;

                            if (!me->GetMap()->IsDungeon())
                                return;

                            uint32 count = 0;

                            switch (me->GetMap()->GetDifficulty())
                            {
                                case RAID_DIFFICULTY_10MAN_NORMAL:
                                    count = urand(1, 2);
                                    break;
                                case RAID_DIFFICULTY_25MAN_NORMAL:
                                    count = 2;
                                    break;
                                case RAID_DIFFICULTY_10MAN_HEROIC:
                                    count = 2;
                                    break;
                                case RAID_DIFFICULTY_25MAN_HEROIC:
                                    count = urand(2, 3);
                                    break;
                            }

                            for (uint8 i = 0; i < count; i++)
                                me->SummonCreature(NPC_SCARAB, AnubarakLoc[i+2], TEMPSUMMON_CORPSE_DESPAWN);
                        }

                        m_uiSummonScarabTimer = 10000;
                    } else m_uiSummonScarabTimer -= uiDiff;

                    if (m_uiSubmergeTimer <= uiDiff)
                    {
                        m_uiStage = 3;
                        m_uiSubmergeTimer = 80*IN_MILLISECONDS;
                    } else m_uiSubmergeTimer -= uiDiff;
                    break;
                case 3:
                    m_uiStage = 0;
                    Summons.DespawnEntry(NPC_SPIKE);
                    m_posPursuingSpikePositionX = 0.0f;
                    m_posPursuingSpikePositionY = 0.0f;
                    m_posPursuingSpikePositionZ = 0.0f;
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE_ANUBARAK);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    DoCast(me, SPELL_EMERGE_ANUBARAK);
                    me->GetMotionMaster()->MoveChase(me->getVictim());
                    m_uiSummonNerubianTimer = 10*1000;
                    m_uiNerubianShadowStrikeTimer = urand(20*1000, 30*1000);
                    break;
            }

            if (!IsHeroic())
            {
                if (m_uiSummonFrostSphereTimer <= uiDiff)
                {
                    uint8 frostSpheresWithAuraCount = 0;
                    for(std::list<uint64>::const_iterator itr = Summons.begin(); itr != Summons.end(); ++itr)
                    {
                        if (Creature* temp = Unit::GetCreature(*me,* itr))
                        {
                            if (temp)
                            {
                                if (temp->GetEntry() == NPC_FROST_SPHERE)
                                {
                                    if (temp->HasAura(SPELL_FROST_SPHERE))
                                    {
                                        frostSpheresWithAuraCount++;
                                    }
                                }
=======
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                switch (summoned->GetEntry())
                {
                    case NPC_BURROW:
                        _burrowGUID.push_back(summoned->GetGUID());
                        summoned->SetReactState(REACT_PASSIVE);
                        summoned->CastSpell(summoned, SPELL_CHURNING_GROUND, false);
                        summoned->SetDisplayId(summoned->GetCreatureTemplate()->Modelid2);
                        break;
                    case NPC_SPIKE:
                        summoned->CombatStart(target);
                        summoned->SetDisplayId(summoned->GetCreatureTemplate()->Modelid1);
                        Talk(EMOTE_SPIKE, target->GetGUID());
                        break;
                    default:
                        break;
                }
                summons.Summon(summoned);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                // Despawn Scarab Swarms neutral
                EntryCheckPredicate pred(NPC_SCARAB);
                summons.DoAction(ACTION_SCARAB_SUBMERGE, pred);

                // Spawn Burrow
                for (int i = 0; i < 4; i++)
                    me->SummonCreature(NPC_BURROW, AnubarakLoc[i + 2]);

                // Spawn 6 Frost Spheres at start
                for (int i = 0; i < 6; i++)
                    if (Unit* summoned = me->SummonCreature(NPC_FROST_SPHERE, SphereSpawn[i]))
                        _sphereGUID[i] = summoned->GetGUID();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FREEZE_SLASH:
                            DoCastVictim(SPELL_FREEZE_SLASH);
                            events.ScheduleEvent(EVENT_FREEZE_SLASH, 15*IN_MILLISECONDS, 0, PHASE_MELEE);
                            return;
                        case EVENT_PENETRATING_COLD:
                            me->CastCustomSpell(SPELL_PENETRATING_COLD, SPELLVALUE_MAX_TARGETS, RAID_MODE(2, 5, 2, 5));
                            events.ScheduleEvent(EVENT_PENETRATING_COLD, 20*IN_MILLISECONDS, 0, PHASE_MELEE);
                            return;
                        case EVENT_SUMMON_NERUBIAN:
                            if (IsHeroic() || !_reachedPhase3)
                                me->CastCustomSpell(SPELL_SUMMON_BURROWER, SPELLVALUE_MAX_TARGETS, RAID_MODE(1, 2, 2, 4));
                            events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 45*IN_MILLISECONDS, 0, PHASE_MELEE);
                            return;
                        case EVENT_NERUBIAN_SHADOW_STRIKE:
                        {
                            EntryCheckPredicate pred(NPC_BURROWER);
                            summons.DoAction(ACTION_SHADOW_STRIKE, pred);
                            events.ScheduleEvent(EVENT_NERUBIAN_SHADOW_STRIKE, 30*IN_MILLISECONDS, 0, PHASE_MELEE);
                            break;
                        }
                        case EVENT_SUBMERGE:
                            if (!_reachedPhase3 && !me->HasAura(SPELL_BERSERK))
                            {
                                DoCast(me, SPELL_SUBMERGE_ANUBARAK);
                                DoCast(me, SPELL_CLEAR_ALL_DEBUFFS);
                                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                Talk(EMOTE_BURROWER);
                                events.SetPhase(PHASE_SUBMERGED);
                                events.ScheduleEvent(EVENT_PURSUING_SPIKE, 2*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
                                events.ScheduleEvent(EVENT_SUMMON_SCARAB, 4*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
                                events.ScheduleEvent(EVENT_EMERGE, 1*MINUTE*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
>>>>>>> TC/master
                            }
                            break;
                        case EVENT_PURSUING_SPIKE:
                            DoCast(SPELL_SPIKE_CALL);
                            break;
                        case EVENT_SUMMON_SCARAB:
                        {
                            /* WORKAROUND
                            * - The correct implementation is more likely the comment below but it needs spell knowledge
                            */
                            std::list<uint64>::iterator i = _burrowGUID.begin();
                            uint32 at = urand(0, _burrowGUID.size()-1);
                            for (uint32 k = 0; k < at; k++)
                                ++i;
                            if (Creature* pBurrow = Unit::GetCreature(*me, *i))
                                pBurrow->CastSpell(pBurrow, 66340, false);

                            events.ScheduleEvent(EVENT_SUMMON_SCARAB, 4*IN_MILLISECONDS, 0, PHASE_SUBMERGED);

                            /*It seems that this spell have something more that needs to be taken into account
                            //Need more sniff info
                            DoCast(SPELL_SUMMON_BEATLES);
                            // Just to make sure it won't happen again in this phase
                            m_uiSummonScarabTimer = 90*IN_MILLISECONDS;*/
                            break;
                        }
<<<<<<< HEAD
                    }

                    for(uint8 i = 0; i < 6 - frostSpheresWithAuraCount; i++)
                        me->SummonCreature(NPC_FROST_SPHERE, SphereSpawn[urand(0, 5)]);

                    m_uiSummonFrostSphereTimer = urand(20, 30)*1000;
                } else m_uiSummonFrostSphereTimer -= uiDiff;
            }

            if (HealthBelowPct(30) && m_uiStage == 0 && !m_bReachedPhase3)
            {
                m_bReachedPhase3 = true;
                DoCastAOE(SPELL_LEECHING_SWARM, true);
                Talk(EMOTE_LEECHING_SWARM);
                Talk(SAY_LEECHING_SWARM);
            }
=======
                        case EVENT_EMERGE:
                            events.ScheduleEvent(EVENT_SUBMERGE, 80*IN_MILLISECONDS, 0, PHASE_MELEE);
                            DoCast(SPELL_SPIKE_TELE);
                            summons.DespawnEntry(NPC_SPIKE);
                            me->RemoveAurasDueToSpell(SPELL_SUBMERGE_ANUBARAK);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_EMERGE_ANUBARAK);
                            events.SetPhase(PHASE_MELEE);
                            events.ScheduleEvent(EVENT_FREEZE_SLASH, 15*IN_MILLISECONDS, 0, PHASE_MELEE);
                            events.ScheduleEvent(EVENT_PENETRATING_COLD, 20*IN_MILLISECONDS, PHASE_MELEE);
                            events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 10*IN_MILLISECONDS, 0, PHASE_MELEE);
                            events.ScheduleEvent(EVENT_SUBMERGE, 80*IN_MILLISECONDS, 0, PHASE_MELEE);
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_NERUBIAN_SHADOW_STRIKE, 30*IN_MILLISECONDS, 0, PHASE_MELEE);
                            return;
                        case EVENT_SUMMON_FROST_SPHERE:
                        {
                            uint8 startAt = urand(0, 5);
                            uint8 i = startAt;
                            do
                            {
                                if (Unit* pSphere = Unit::GetCreature(*me, _sphereGUID[i]))
                                {
                                    if (!pSphere->HasAura(SPELL_FROST_SPHERE))
                                    {
                                        if (Creature* summon = me->SummonCreature(NPC_FROST_SPHERE, SphereSpawn[i]))
                                            _sphereGUID[i] = summon->GetGUID();
                                        break;
                                    }
                                }
                                i = (i + 1) % 6;
                            }
                            while
                                (i != startAt);
                            events.ScheduleEvent(EVENT_SUMMON_FROST_SPHERE, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            break;
                        }
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                        default:
                            break;
                    }

                }
>>>>>>> TC/master

                if (HealthBelowPct(30) && events.GetPhaseMask() & PHASE_MASK_MELEE && !_reachedPhase3)
                {
                    _reachedPhase3 = true;
                    DoCastAOE(SPELL_LEECHING_SWARM);
                    Talk(EMOTE_LEECHING_SWARM);
                    Talk(SAY_LEECHING_SWARM);
                }

                if (events.GetPhaseMask() & PHASE_MASK_MELEE)
                    DoMeleeAttackIfReady();
            }

            private:
                std::list<uint64> _burrowGUID;
                uint64 _sphereGUID[6];
                bool _intro;
                bool _reachedPhase3;
                uint32 _frostSphereTimer;
                uint32 _berserkTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_anubarak_trialAI(creature);
        };
};

class mob_swarm_scarab : public CreatureScript
{
<<<<<<< HEAD
public:
    mob_swarm_scarab() : CreatureScript("mob_swarm_scarab") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_swarm_scarabAI(creature);
    };

    struct mob_swarm_scarabAI : public ScriptedAI
    {
        mob_swarm_scarabAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 m_uiDeterminationTimer;
        uint32 m_uiAcidMandibleTimer;
=======
    public:
        mob_swarm_scarab() : CreatureScript("mob_swarm_scarab") { }
>>>>>>> TC/master

        struct mob_swarm_scarabAI : public ScriptedAI
        {
<<<<<<< HEAD
            me->SetCorpseDelay(0);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_PERMAFROST, true);
            m_uiDeterminationTimer = urand(5*1000, 60*1000);
            m_uiAcidMandibleTimer = 3500;
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                me->AddThreat(target, 20000.0f);
        }
=======
            mob_swarm_scarabAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                me->SetCorpseDelay(0);
                _determinationTimer = urand(5*IN_MILLISECONDS, 60*IN_MILLISECONDS);
                DoCast(me, SPELL_ACID_MANDIBLE);
                me->SetInCombatWithZone();
                if (me->isInCombat())
                    if (Creature* Anubarak = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_ANUBARAK)))
                        Anubarak->AI()->JustSummoned(me);
            }
>>>>>>> TC/master

            void DoAction(const int32 actionId)
            {
                switch (actionId)
                {
                    case ACTION_SCARAB_SUBMERGE:
                        DoCast(SPELL_SUBMERGE_EFFECT);
                        me->DespawnOrUnsummon(1*IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* killer)
            {
                DoCast(killer, RAID_MODE(SPELL_TRAITOR_KING_10, SPELL_TRAITOR_KING_25));
            }

            void UpdateAI(const uint32 diff)
            {
                if (_instance && _instance->GetBossState(BOSS_ANUBARAK) != IN_PROGRESS)
                    me->DisappearAndDie();

<<<<<<< HEAD
            if (m_uiAcidMandibleTimer <= uiDiff)
            {
                m_uiAcidMandibleTimer = 3500;

                if (!me->getVictim() || !instance)
                    return;

                //If we are within range melee the target
                if (me->IsWithinMeleeRange(me->getVictim()))
                {
                    if (me->getVictim()->HasAura(RAID_MODE(SPELL_TRIGGERED_ACID_MANDIBLE_0, SPELL_TRIGGERED_ACID_MANDIBLE_1, SPELL_TRIGGERED_ACID_MANDIBLE_2, SPELL_TRIGGERED_ACID_MANDIBLE_3)))
                    {
                        if (Aura* aur = me->getVictim()->GetAura(RAID_MODE(SPELL_TRIGGERED_ACID_MANDIBLE_0, SPELL_TRIGGERED_ACID_MANDIBLE_1, SPELL_TRIGGERED_ACID_MANDIBLE_2, SPELL_TRIGGERED_ACID_MANDIBLE_3)))
                        {
                            if (aur->GetStackAmount() < 40)
                                aur->SetStackAmount(aur->GetStackAmount() + 1);

                            if (aur->GetStackAmount() == 40)
                                aur->SetStackAmount(40);
                        }
                    }
                    else
                    {
                        if (Creature* anubarak = Unit::GetCreature(*me, instance->GetData64(NPC_ANUBARAK)))
                            me->CastSpell(me->getVictim(), RAID_MODE(SPELL_TRIGGERED_ACID_MANDIBLE_0, SPELL_TRIGGERED_ACID_MANDIBLE_1, SPELL_TRIGGERED_ACID_MANDIBLE_2, SPELL_TRIGGERED_ACID_MANDIBLE_3), true, 0, 0, instance->GetData64(NPC_ANUBARAK));
                    }
                }
            } else m_uiAcidMandibleTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
=======
                if (!UpdateVictim())
                    return;
>>>>>>> TC/master

                /* Bosskillers don't recognize */
                if (_determinationTimer <= diff)
                {
                    DoCast(me, SPELL_DETERMINATION);
                    _determinationTimer = urand(10*IN_MILLISECONDS, 60*IN_MILLISECONDS);
                }
                else
                    _determinationTimer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* _instance;
                uint32 _determinationTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_swarm_scarabAI(creature);
        };
};

<<<<<<< HEAD
        void Reset()
        {
            me->SetCorpseDelay(0);
            m_uiSpiderFrenzyTimer = 2000;
            m_uiSubmergeTimer = 30*1000;
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_PERMAFROST, true);
            DoCast(me, SPELL_EXPOSE_WEAKNESS);
        }
=======
class mob_nerubian_burrower : public CreatureScript
{
    public:
        mob_nerubian_burrower() : CreatureScript("mob_nerubian_burrower") { }
>>>>>>> TC/master

        struct mob_nerubian_burrowerAI : public ScriptedAI
        {
            mob_nerubian_burrowerAI(Creature* creature) : ScriptedAI(creature)
            {
<<<<<<< HEAD
                case ACTION_SHADOW_STRIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SHADOW_STRIKE);
                    break;
=======
                _instance = creature->GetInstanceScript();
>>>>>>> TC/master
            }

<<<<<<< HEAD
            if (m_uiSubmergeTimer <= uiDiff)
=======
            void Reset()
            {
                me->SetCorpseDelay(10);
                _submergeTimer = 30*IN_MILLISECONDS;
                DoCast(me, SPELL_EXPOSE_WEAKNESS);
                DoCast(me, SPELL_SPIDER_FRENZY);
                DoCast(me, SPELL_AWAKENED);
                me->SetInCombatWithZone();
                if (me->isInCombat())
                    if (Creature* Anubarak = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_ANUBARAK)))
                        Anubarak->AI()->JustSummoned(me);
            }

            void DoAction(const int32 actionId)
>>>>>>> TC/master
            {
                switch (actionId)
                {
<<<<<<< HEAD
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE_EFFECT);
                    DoCast(me, SPELL_EMERGE_EFFECT);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
=======
                    case ACTION_SHADOW_STRIKE:
                        if (!me->HasAura(SPELL_AWAKENED))
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_SHADOW_STRIKE);
                        break;
                    default:
                        break;
>>>>>>> TC/master
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (_instance && _instance->GetBossState(BOSS_ANUBARAK) != IN_PROGRESS)
                    me->DisappearAndDie();

                if (!UpdateVictim() && !me->HasAura(SPELL_SUBMERGE_EFFECT))
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if ((_submergeTimer <= diff) && HealthBelowPct(80))
                {
<<<<<<< HEAD
                    // Just for security purposes, sometimes they get stuck unattackable, this one should solve the problem
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);

                    if (HealthBelowPct(80))
                    {
                        std::list<Creature*> sphereList;
                        me->GetCreatureListWithEntryInGrid(sphereList, NPC_FROST_SPHERE, 6.0f);

                        bool readyToSubmerge = true;

                        if (!sphereList.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = sphereList.begin(); itr != sphereList.end(); ++itr)
                            {
                                if (Creature* creature = (*itr))
                                {
                                    if (creature->GetDynObject(SPELL_PERMAFROST))
                                    {
                                        readyToSubmerge = false;
                                    }
                                }
                            }
                        }

                        if (readyToSubmerge)
                        {
                            uint32 setHealthVal = 0;

                            uint32 percentageAddVal = (uint32)(me->GetMaxHealth() * 0.4);
                            uint32 currentHealthVal = me->GetHealth();

                            setHealthVal = percentageAddVal + currentHealthVal;

                            if (setHealthVal > me->GetMaxHealth())
                                setHealthVal = me->GetMaxHealth();

                            me->SetHealth(setHealthVal);

                            DoCast(me, SPELL_SUBMERGE_EFFECT);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
=======
                    if (me->HasAura(SPELL_SUBMERGE_EFFECT))
                    {
                        me->RemoveAurasDueToSpell(SPELL_SUBMERGE_EFFECT);
                        DoCast(me, SPELL_EMERGE_EFFECT);
                        DoCast(me, SPELL_AWAKENED);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                    else
                    {
                        if (!me->HasAura(SPELL_PERMAFROST_HELPER))
                        {
                            DoCast(me, SPELL_SUBMERGE_EFFECT);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_PERSISTENT_DIRT, true);
>>>>>>> TC/master
                        }
                    }
                    _submergeTimer = 20*IN_MILLISECONDS;
                }
<<<<<<< HEAD
                m_uiSubmergeTimer = 20*1000;
            } else m_uiSubmergeTimer -= uiDiff;

            if (m_uiSpiderFrenzyTimer <= uiDiff)
            {
                std::list<Creature*> burrowerCreatureList;
                me->GetCreatureListWithEntryInGrid(burrowerCreatureList, me->GetEntry(), 12.0f);

                bool doCastFrenzy = false;

                if (!burrowerCreatureList.empty())
                {
                    for (std::list<Creature*>::const_iterator itr = burrowerCreatureList.begin(); itr != burrowerCreatureList.end(); ++itr)
                    {
                        if (Creature* creature = (*itr))
                        {
                            if (creature->GetGUID() != me->GetGUID())
                            {
                                if (!creature->HasAura(SPELL_SUBMERGE_EFFECT))
                                {
                                    doCastFrenzy = true;
                                    break;
                                }
                            }
                        }
                    }
                }

                if (doCastFrenzy)
                    me->AddAura(SPELL_SPIDER_FRENZY, me);

                m_uiSpiderFrenzyTimer = 2000;
            } else m_uiSpiderFrenzyTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
=======
                else
                    _submergeTimer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                uint32 _submergeTimer;
                Phases _phase;
                EventMap _events;
                InstanceScript* _instance;
        };
>>>>>>> TC/master

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_nerubian_burrowerAI(creature);
        };
};

class mob_frost_sphere : public CreatureScript
{
    public:
        mob_frost_sphere() : CreatureScript("mob_frost_sphere") { }

        struct mob_frost_sphereAI : public ScriptedAI
        {
            mob_frost_sphereAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _isFalling = false;
                me->SetReactState(REACT_PASSIVE);
                //! Confirmed sniff 3.3.5.a
                me->SetDisableGravity(true);
                me->SetByteValue(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                //! end
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                me->SetSpeed(MOVE_FLIGHT, 0.5f, false);
                me->GetMotionMaster()->MoveRandom(20.0f);
                DoCast(SPELL_FROST_SPHERE);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                if (me->GetHealth() <= damage)
                {
                    damage = 0;
                    if (!_isFalling)
                    {
                        _isFalling = true;
                        me->GetMotionMaster()->MoveIdle();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        //At hit the ground
                        me->HandleEmoteCommand(EMOTE_ONESHOT_FLYDEATH);

                        // In this case MoveFall might fail, but we are close to ground, so create permafrost now
                        float tz = me->GetMap()->GetHeight(me->GetPhaseMask(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), true, MAX_FALL_DISTANCE);
                        if (tz > INVALID_HEIGHT)
                        {
                            if (fabs(me->GetPositionZ() - tz) < 0.1f)
                            {
                                DoTeleportTo(me->GetPositionX(), me->GetPositionY(), tz);
                                me->StopMoving();
                                me->GetMotionMaster()->Clear();
                                me->GetMotionMaster()->MoveIdle();
                                me->RemoveAurasDueToSpell(SPELL_FROST_SPHERE);
                                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                                DoCast(SPELL_PERMAFROST_VISUAL);
                                DoCast(SPELL_PERMAFROST);
                                me->SetObjectScale(2.0f);
                                return;
                            }
                        }

                        me->GetMotionMaster()->MoveFall(POINT_FALL_GROUND);
                    }
                }
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != EFFECT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case POINT_FALL_GROUND:
                        me->RemoveAurasDueToSpell(SPELL_FROST_SPHERE);
                        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                        DoCast(SPELL_PERMAFROST_VISUAL);
                        DoCast(SPELL_PERMAFROST);
                        me->SetObjectScale(2.0f);
                        break;
                    default:
                        break;
                }
            }

            // Empty EnterEvadeMode and UpdateAI, so it will not reset if victim died, will be despawned by Anub'Arak anyways
            void EnterEvadeMode()
            {
            }

            void UpdateAI(const uint32 /*diff*/)
            {
            }

        private:
            bool _isFalling;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_frost_sphereAI(creature);
        };
};

class mob_anubarak_spike : public CreatureScript
{
    public:
        mob_anubarak_spike() : CreatureScript("mob_anubarak_spike") { }

        struct mob_anubarak_spikeAI : public ScriptedAI
        {
            mob_anubarak_spikeAI(Creature* creature) : ScriptedAI(creature)
            {
            }

<<<<<<< HEAD
        void Reset()
        {
            m_uiTargetGUID = 0;
        }
=======
            void Reset()
            {
                _phase = PHASE_NO_MOVEMENT;
                _phaseSwitchTimer = 1;
                // make sure the spike has everyone on threat list
                me->SetInCombatWithZone();
            }
>>>>>>> TC/master

            bool CanAIAttack(Unit const* victim) const
            {
                return victim->GetTypeId() == TYPEID_PLAYER;
            }

<<<<<<< HEAD
        void AttackStart(Unit* who)
        {
            if (!who)
                return;

            me->AddThreat(who, 5000000.0f);
            m_uiTargetGUID = who->GetGUID();
            DoCast(me, SPELL_SPIKE_TRAIL, true);
            Talk(EMOTE_SPIKE, who->GetGUID());
            me->SetSpeed(MOVE_RUN, 0.5f);
            m_uiSpeed = 0;
            m_uiIncreaseSpeedTimer = 1*1000;
            UnitAI::AttackStart(who);
        }
=======
            void EnterCombat(Unit* who)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                {
                    StartChase(target);
                    Talk(EMOTE_SPIKE, who->GetGUID());
                }
            }
>>>>>>> TC/master

            void DamageTaken(Unit* /*who*/, uint32& uiDamage)
            {
                uiDamage = 0;
            }

<<<<<<< HEAD
        void UpdateAI(const uint32 uiDiff)
        {
            std::list<Creature*> sphereList;
            me->GetCreatureListWithEntryInGrid(sphereList, NPC_FROST_SPHERE, 6.0f);

            if (!sphereList.empty())
            {
                for (std::list<Creature*>::const_iterator itr = sphereList.begin(); itr != sphereList.end(); ++itr)
                {
                    if (Creature* creature = (*itr))
                    {
                        if (creature->GetDynObject(SPELL_PERMAFROST))
                        {
                            creature->DisappearAndDie();
                            me->DisappearAndDie();
                            break;
                        }
                    }
                }
            }

            if (m_uiTargetGUID)
            {
                Unit* target = Unit::GetUnit((*me), m_uiTargetGUID);

                if (!target || !target->isAlive())
=======
            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
>>>>>>> TC/master
                {
                    me->DisappearAndDie();
                    return;
                }

<<<<<<< HEAD
                if (target)
                {
                    if (!target->HasAura(SPELL_MARK))
                    {
                        DoCast(target, SPELL_MARK, true);
                    }

                    if (!me->getVictim())
                    {
                        AttackStart(target);
                        me->AddThreat(target, 5000000.0f);
                    }
=======
                if (_phaseSwitchTimer)
                {
                    if (_phaseSwitchTimer <= diff)
                    {
                        switch (_phase)
                        {
                            case PHASE_NO_MOVEMENT:
                                DoCast(me, SPELL_SPIKE_SPEED1);
                                DoCast(me, SPELL_SPIKE_TRAIL);
                                _phase = PHASE_IMPALE_NORMAL;
                                if (Unit* target2 = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                {
                                    StartChase(target2);
                                    Talk(EMOTE_SPIKE, target2->GetGUID());
                                }
                                _phaseSwitchTimer = 7*IN_MILLISECONDS;
                                return;
                            case PHASE_IMPALE_NORMAL:
                                DoCast(me, SPELL_SPIKE_SPEED2);
                                _phase = PHASE_IMPALE_MIDDLE;
                                _phaseSwitchTimer = 7*IN_MILLISECONDS;
                                return;
                            case PHASE_IMPALE_MIDDLE:
                                DoCast(me, SPELL_SPIKE_SPEED3);
                                _phase = PHASE_IMPALE_FAST;
                                _phaseSwitchTimer = 0;
                                return;
                            default:
                                return;
                        }
                    }
                    else
                        _phaseSwitchTimer -= diff;
>>>>>>> TC/master
                }
            }

            void MoveInLineOfSight(Unit* pWho)
            {
                if (!pWho)
                    return;

                if (pWho->GetEntry() != NPC_FROST_SPHERE)
                    return;

                if (_phase == PHASE_NO_MOVEMENT)
                    return;

                if (me->IsWithinDist(pWho, 7.0f))
                {
                    switch (_phase)
                    {
<<<<<<< HEAD
                        case 0:
                            DoCast(me, SPELL_SPIKE_SPEED1, true);
                            m_uiSpeed = 1;
                            m_uiIncreaseSpeedTimer = 7*IN_MILLISECONDS;
                            break;
                        case 1:
                            DoCast(me, SPELL_SPIKE_SPEED2, true);
                            m_uiSpeed = 2;
                            m_uiIncreaseSpeedTimer = 7*IN_MILLISECONDS;
                            break;
                        case 2:
                            DoCast(me, SPELL_SPIKE_SPEED3, true);
                            m_uiIncreaseSpeedTimer = 0;
=======
                        case PHASE_IMPALE_NORMAL:
                            me->RemoveAurasDueToSpell(SPELL_SPIKE_SPEED1);
                            break;
                        case PHASE_IMPALE_MIDDLE:
                            me->RemoveAurasDueToSpell(SPELL_SPIKE_SPEED2);
                            break;
                        case PHASE_IMPALE_FAST:
                            me->RemoveAurasDueToSpell(SPELL_SPIKE_SPEED3);
                            break;
                        default:
>>>>>>> TC/master
                            break;
                    }

                    me->CastSpell(me, SPELL_SPIKE_FAIL, true);

                    pWho->ToCreature()->DespawnOrUnsummon(3*IN_MILLISECONDS);

                    // After the spikes hit the icy surface they can't move for about ~5 seconds
                    _phase = PHASE_NO_MOVEMENT;
                    _phaseSwitchTimer = 5*IN_MILLISECONDS;
                    SetCombatMovement(false);
                    me->GetMotionMaster()->MoveIdle();
                    me->GetMotionMaster()->Clear();
                }
            }

            void StartChase(Unit* who)
            {
                DoCast(who, SPELL_MARK);
                me->SetSpeed(MOVE_RUN, 0.5f);
                // make sure the Spine will really follow the one he should
                me->getThreatManager().clearReferences();
                me->SetInCombatWithZone();
                me->getThreatManager().addThreat(who, std::numeric_limits<float>::max());
                me->GetMotionMaster()->Clear(true);
                me->GetMotionMaster()->MoveChase(who);
                me->TauntApply(who);
            }

            private:
                uint32 _phaseSwitchTimer;
                PursuingSpikesPhases _phase;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_anubarak_spikeAI(creature);
        };
};

class spell_impale : public SpellScriptLoader
{
    public:
        spell_impale() : SpellScriptLoader("spell_impale") { }

        class spell_impale_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_impale_SpellScript);

            void HandleDamageCalc(SpellEffIndex /*effIndex*/)
            {
                Unit* target = GetHitUnit();
                uint32 permafrost = sSpellMgr->GetSpellIdForDifficulty(SPELL_PERMAFROST, target);

                // make sure Impale doesnt do damage if we are standing on permafrost
                if (target && target->HasAura(permafrost))
                    SetHitDamage(0);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_impale_SpellScript::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_impale_SpellScript();
        }
};

void AddSC_boss_anubarak_trial()
{
    new boss_anubarak_trial();
    new mob_swarm_scarab();
    new mob_nerubian_burrower();
    new mob_anubarak_spike();
    new mob_frost_sphere();

    new spell_impale();
}
