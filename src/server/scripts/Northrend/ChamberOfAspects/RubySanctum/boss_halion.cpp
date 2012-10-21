<<<<<<< HEAD
﻿/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
=======
/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
>>>>>>> TC/master
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

<<<<<<< HEAD
#include "ScriptPCH.h"
=======
#include "ScriptMgr.h"
>>>>>>> TC/master
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "Vehicle.h"
#include "MapManager.h"
<<<<<<< HEAD
#include "ruby_sanctum.h"

/*
TODO:
- Look over how threat should be treaten (apparently there's a creature (entry 40151) that keeps 200 threat on both Halion's)
- See if corporeality code can be improved
- Script adds and surrounding trash
- Update Texts
*/

enum Texts
{
    SAY_INTRO                        = 0, // Meddlesome insects! You are too late. The Ruby Sanctum is lost!
    SAY_AGGRO                        = 1, // Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!
    SAY_METEOR_STRIKE                = 2, // The heavens burn!
    SAY_PHASE_TWO                    = 3, // You will find only suffering within the realm of twilight! Enter if you dare!
    SAY_DEATH                        = 4, // Relish this victory, mortals, for it will be your last! This world will burn with the master's return!
    SAY_KILL                         = 5, // Another "hero" falls.
    SAY_BERSERK                      = 6, // Not good enough.

    SAY_SPHERE_PULSE                 = 0, // Beware the shadow!
    SAY_PHASE_THREE                  = 1, // I am the light and the darkness! Cower, mortals, before the herald of Deathwing!

    EMOTE_TWILIGHT_OUT_TWILIGHT      = 0, // Your companion's efforts have forced Halion further out of the Twilight realm!
    EMOTE_TWILIGHT_IN_TWILIGHT       = 1, // Your efforts have forced Halion further into the Twilight realm!
    EMOTE_PHYSICAL_OUT_PHYSICAL      = 2, // Your companion's efforts have forced Halion further out of the Physical realm!
    EMOTE_PHYSICAL_IN_PHYSICAL       = 3, // Your efforts have forced Halion further into the Physical realm!
    EMOTE_REGENERATE                 = 4, // Without pressure in both realms, Halion begins to regenerate.

    EMOTE_WARN_LASER                 = 0, // The orbiting spheres pulse with dark energy!
=======
#include "GameObjectAI.h"
#include "ScriptedCreature.h"
#include "ruby_sanctum.h"

/* ScriptData
SDName: ruby_sanctum
SDAuthors: Kaelima, Warpten
SD%Complete: 90%
SDComment: Based on Kaelima's initial work (nearly half of it). Corporeality handling is a pure guess, we lack info.
SDCategory: Chamber of Aspects
EndScriptData */

enum Texts
{
    // Shared
    SAY_REGENERATE                     = 0, // Without pressure in both realms, %s begins to regenerate.

    // Halion
    SAY_INTRO                          = 1, // Meddlesome insects! You are too late. The Ruby Sanctum is lost!
    SAY_AGGRO                          = 2, // Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!
    SAY_METEOR_STRIKE                  = 3, // The heavens burn!
    SAY_PHASE_TWO                      = 4, // You will find only suffering within the realm of twilight! Enter if you dare!
    SAY_DEATH                          = 5, // Relish this victory, mortals, for it will be your last! This world will burn with the master's return!
    SAY_KILL                           = 6, // Another "hero" falls.
    SAY_BERSERK                        = 7, // Not good enough.
    EMOTE_CORPOREALITY_POT             = 8, // Your efforts force %s further out of the physical realm!
    EMOTE_CORPOREALITY_PIP             = 9, // Your companions' efforts force %s further into the physical realm!

    // Twilight Halion
    SAY_SPHERE_PULSE                   = 1, // Beware the shadow!
    SAY_PHASE_THREE                    = 2, // I am the light and the darkness! Cower, mortals, before the herald of Deathwing!
    EMOTE_CORPOREALITY_TIT             = 3, // Your companions' efforts force %s further into the twilight realm!
    EMOTE_CORPOREALITY_TOT             = 4, // Your efforts force %s further out of the twilight realm!

    EMOTE_WARN_LASER                   = 0, // The orbiting spheres pulse with dark energy!
>>>>>>> TC/master
};

enum Spells
{
    // Halion
    SPELL_FLAME_BREATH                  = 74525,
    SPELL_CLEAVE                        = 74524,
    SPELL_METEOR_STRIKE                 = 74637,
    SPELL_TAIL_LASH                     = 74531,

    SPELL_FIERY_COMBUSTION              = 74562,
    SPELL_MARK_OF_COMBUSTION            = 74567,
    SPELL_FIERY_COMBUSTION_EXPLOSION    = 74607,
    SPELL_FIERY_COMBUSTION_SUMMON       = 74610,

    // Combustion & Consumption
    SPELL_SCALE_AURA                    = 70507, // Aura created in spell_dbc.
    SPELL_COMBUSTION_DAMAGE_AURA        = 74629,
    SPELL_CONSUMPTION_DAMAGE_AURA       = 74803,

    // Twilight Halion
    SPELL_DARK_BREATH                   = 74806,

    SPELL_MARK_OF_CONSUMPTION           = 74795,
    SPELL_SOUL_CONSUMPTION              = 74792,
    SPELL_SOUL_CONSUMPTION_EXPLOSION    = 74799,
    SPELL_SOUL_CONSUMPTION_SUMMON       = 74800,

    // Living Inferno
    SPELL_BLAZING_AURA                  = 75885,

    // Halion Controller
    SPELL_COSMETIC_FIRE_PILLAR          = 76006,
    SPELL_FIERY_EXPLOSION               = 76010,
    SPELL_CLEAR_DEBUFFS                 = 75396,

    // Meteor Strike
    SPELL_METEOR_STRIKE_COUNTDOWN       = 74641,
    SPELL_METEOR_STRIKE_AOE_DAMAGE      = 74648,
    SPELL_METEOR_STRIKE_FIRE_AURA_1     = 74713,
    SPELL_METEOR_STRIKE_FIRE_AURA_2     = 74718,
    SPELL_BIRTH_NO_VISUAL               = 40031,

    // Shadow Orb
    SPELL_TWILIGHT_CUTTER               = 74768, // Unknown dummy effect (EFFECT_0)
    SPELL_TWILIGHT_CUTTER_TRIGGERED     = 74769,
    SPELL_TWILIGHT_PULSE_PERIODIC       = 78861,
    SPELL_TRACK_ROTATION                = 74758,

    // Misc
    SPELL_TWILIGHT_DIVISION             = 75063, // Phase spell from phase 2 to phase 3
    SPELL_LEAVE_TWILIGHT_REALM          = 74812,
    SPELL_TWILIGHT_PHASING              = 74808, // Phase spell from phase 1 to phase 2
    SPELL_SUMMON_TWILIGHT_PORTAL        = 74809, // Summons go 202794
<<<<<<< HEAD
    SPELL_TWILIGHT_MENDING              = 75509,
    SPELL_TWILIGHT_REALM                = 74807,

    SPELL_COPY_DAMAGE                   = 74810, // Not in DBCs but found in sniffs. Not cast.
=======
    SPELL_SUMMON_EXIT_PORTALS           = 74805, // Custom spell created in spell_dbc.
    SPELL_TWILIGHT_MENDING              = 75509,
    SPELL_TWILIGHT_REALM                = 74807,
    SPELL_COPY_DAMAGE                   = 74810  // Aura not found in DBCs.
>>>>>>> TC/master
};

enum Events
{
    // Halion
    EVENT_ACTIVATE_FIREWALL     = 1,
<<<<<<< HEAD
    EVENT_CLEAVE                = 2, // Used by Twilight Halion too
=======
    EVENT_CLEAVE                = 2,
>>>>>>> TC/master
    EVENT_FLAME_BREATH          = 3,
    EVENT_METEOR_STRIKE         = 4,
    EVENT_FIERY_COMBUSTION      = 5,
    EVENT_TAIL_LASH             = 6,

<<<<<<< HEAD
    // Halion Controller
    EVENT_START_INTRO           = 7,
    EVENT_INTRO_PROGRESS_1      = 8,
    EVENT_INTRO_PROGRESS_2      = 9,
    EVENT_INTRO_PROGRESS_3      = 10,
    EVENT_CHECK_CORPOREALITY    = 11,
    EVENT_SHADOW_PULSARS_SHOOT  = 12,
    EVENT_BERSERK               = 13,

    // Meteor Strike
    EVENT_SPAWN_METEOR_FLAME    = 14,

    // Twilight Halion
    EVENT_DARK_BREATH           = 15,
    EVENT_SOUL_CONSUMPTION      = 16,

    // Living Ember
    EVENT_EMBER_ENRAGE          = 17,

    // Misc
    EVENT_CHECK_THREAT          = 18,
    // This is all shitty for now. Halion, Twilight Halion, and Halion Controller will check their threat list
    // every two seconds and if they find out that either one of the NPCs lost aggro on any player, that would
    // mean that the encounter has to reset. Not yet implemented, this comment block is rather some way for me
    // to brain a bit about this fubarish stuff.
=======
    // Twilight Halion
    EVENT_DARK_BREATH           = 7,
    EVENT_SOUL_CONSUMPTION      = 8,

    // Meteor Strike
    EVENT_SPAWN_METEOR_FLAME    = 9,

    // Halion Controller
    EVENT_START_INTRO           = 10,
    EVENT_INTRO_PROGRESS_1      = 11,
    EVENT_INTRO_PROGRESS_2      = 12,
    EVENT_INTRO_PROGRESS_3      = 13,
    EVENT_CHECK_CORPOREALITY    = 14,
    EVENT_SHADOW_PULSARS_SHOOT  = 15,
    EVENT_TRIGGER_BERSERK       = 16,
    EVENT_TWILIGHT_MENDING      = 17
>>>>>>> TC/master
};

enum Actions
{
    // Meteor Strike
    ACTION_METEOR_STRIKE_BURN   = 1,
    ACTION_METEOR_STRIKE_AOE    = 2,

<<<<<<< HEAD
    // Halion
    ACTION_BERSERK              = 3,

    // Halion Controller
    ACTION_PHASE_TWO            = 4,
    ACTION_PHASE_THREE          = 5,
    ACTION_CLEANUP              = 6,

    // Orb Carrier
    ACTION_SHOOT                = 7,
=======
    // Halion Controller
    ACTION_PHASE_TWO            = 3,
    ACTION_PHASE_THREE          = 4,
    ACTION_CLEANUP              = 5,

    // Orb Carrier
    ACTION_SHOOT                = 6
>>>>>>> TC/master
};

enum Phases
{
    PHASE_ALL           = 0,
<<<<<<< HEAD
    PHASE_ONE           = 1,
    PHASE_TWO           = 2,
    PHASE_THREE         = 3,

    PHASE_ONE_MASK      = 1 << PHASE_ONE,
    PHASE_TWO_MASK      = 1 << PHASE_TWO,
    PHASE_THREE_MASK    = 1 << PHASE_THREE,
=======
    PHASE_INTRO         = 1,
    PHASE_ONE           = 2,
    PHASE_TWO           = 3,
    PHASE_THREE         = 4,

    PHASE_INTRO_MASK    = 1 << PHASE_INTRO,
    PHASE_ONE_MASK      = 1 << PHASE_ONE,
    PHASE_TWO_MASK      = 1 << PHASE_TWO,
    PHASE_THREE_MASK    = 1 << PHASE_THREE
>>>>>>> TC/master
};

enum Misc
{
    DATA_TWILIGHT_DAMAGE_TAKEN   = 1,
    DATA_MATERIAL_DAMAGE_TAKEN   = 2,
    DATA_STACKS_DISPELLED        = 3,
    DATA_FIGHT_PHASE             = 4,
<<<<<<< HEAD
=======
    DATA_EVADE_METHOD            = 5
>>>>>>> TC/master
};

enum OrbCarrierSeats
{
    SEAT_NORTH            = 0,
    SEAT_SOUTH            = 1,
    SEAT_EAST             = 2,
<<<<<<< HEAD
    SEAT_WEST             = 3,
=======
    SEAT_WEST             = 3
};

enum CorporealityEvent
{
    CORPOREALITY_NONE               = 0,
    CORPOREALITY_TWILIGHT_MENDING   = 1,
    CORPOREALITY_INCREASE           = 2,
    CORPOREALITY_DECREASE           = 3
>>>>>>> TC/master
};

Position const HalionSpawnPos = {3156.67f, 533.8108f, 72.98822f, 3.159046f};

<<<<<<< HEAD
struct CorporealityData
{
    uint8 materialPercentage;
=======
uint8 const MAX_CORPOREALITY_STATE = 11;

struct CorporealityEntry
{
>>>>>>> TC/master
    uint32 materialRealmSpell;
    uint32 twilightRealmSpell;
};

<<<<<<< HEAD
uint8 const MAX_CORPOREALITY_STATE = 11;

CorporealityData const corporealityReference[MAX_CORPOREALITY_STATE] =
{
    {  0, 74836, 74831},
    { 10, 74835, 74830},
    { 20, 74834, 74829},
    { 30, 74833, 74828},
    { 40, 74832, 74827},
    { 50, 74826, 74826},
    { 60, 74827, 74832},
    { 70, 74828, 74833},
    { 80, 74829, 74834},
    { 90, 74830, 74835},
    {100, 74831, 74836},
=======
CorporealityEntry const _corporealityReference[MAX_CORPOREALITY_STATE] = {
    {74836, 74831},
    {74835, 74830},
    {74834, 74829},
    {74833, 74828},
    {74832, 74827},
    {74826, 74826},
    {74827, 74832},
    {74828, 74833},
    {74829, 74834},
    {74830, 74835},
    {74831, 74836}
};

struct generic_halionAI : public BossAI
{
    generic_halionAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId), _canEvade(false) { }

    void EnterCombat(Unit* /*who*/)
    {
        Talk(SAY_AGGRO);
        _EnterCombat();
        _canEvade = false;
        events.Reset();
        events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
    }

    void EnterEvadeMode()
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _EnterEvadeMode();
    }

    void ExecuteEvent(uint32 const eventId)
    {
        switch (eventId)
        {
            case EVENT_CLEAVE:
                DoCastVictim(SPELL_CLEAVE);
                events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                break;
        }
    }

    void UpdateAI(uint32 const diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
            ExecuteEvent(eventId);

        DoMeleeAttackIfReady();
    }

    void SetData(uint32 index, uint32 dataValue)
    {
        switch (index)
        {
            case DATA_EVADE_METHOD:
                _canEvade = (dataValue == 1);
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* /*who*/, SpellInfo const* spellInfo)
    {
        if (spellInfo->Id == SPELL_TWILIGHT_MENDING)
            Talk(SAY_REGENERATE);
    }

protected:
    bool _canEvade;
>>>>>>> TC/master
};

class boss_halion : public CreatureScript
{
    public:
        boss_halion() : CreatureScript("boss_halion") { }

<<<<<<< HEAD
        struct boss_halionAI : public BossAI
        {
            boss_halionAI(Creature* creature) : BossAI(creature, DATA_HALION) { }

            void Reset()
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _Reset();
=======
        struct boss_halionAI : public generic_halionAI
        {
            boss_halionAI(Creature* creature) : generic_halionAI(creature, DATA_HALION) { }

            void Reset()
            {
                generic_halionAI::Reset();
                me->SetReactState(REACT_DEFENSIVE);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                me->RemoveAurasDueToSpell(SPELL_TWILIGHT_PHASING);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void EnterEvadeMode()
            {
                // Phase 1: We always can evade. Phase 2 & 3: We can evade if and only if the controller tells us to.
                // Controller has absolute priority over the phasemask.
                if ((events.GetPhaseMask() & PHASE_ONE_MASK) || _canEvade)
                    generic_halionAI::EnterEvadeMode();
>>>>>>> TC/master
            }

            void EnterCombat(Unit* who)
            {
<<<<<<< HEAD
                _EnterCombat();
                Talk(SAY_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

                events.Reset();
                events.SetPhase(PHASE_ONE);
                // Schedule events without taking care of phases, since EventMap will not be updated under phase 2.
                events.ScheduleEvent(EVENT_ACTIVATE_FIREWALL, 10000);
                events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
=======
                generic_halionAI::EnterCombat(who);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                instance->SetBossState(DATA_HALION, IN_PROGRESS);

                events.SetPhase(PHASE_ONE);
                events.ScheduleEvent(EVENT_ACTIVATE_FIREWALL, 10000);
>>>>>>> TC/master
                events.ScheduleEvent(EVENT_FLAME_BREATH, urand(10000, 12000));
                events.ScheduleEvent(EVENT_METEOR_STRIKE, urand(20000, 25000));
                events.ScheduleEvent(EVENT_FIERY_COMBUSTION, urand(15000, 18000));
                events.ScheduleEvent(EVENT_TAIL_LASH, 10000);

<<<<<<< HEAD
                // Due to Halion's EventMap not being updated under phase two, Berserk will be triggered by the Controller
                // so that the timer still ticks in phase two.
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->EnterCombat(who);
=======
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->SetData(DATA_FIGHT_PHASE, PHASE_ONE);
>>>>>>> TC/master
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
<<<<<<< HEAD
                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->Reset();

                // This block shouldn't be needed anymore after spell 74810 is working.
                if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_TWILIGHT_HALION)))
                    if (twilightHalion->isAlive())
                        twilightHalion->Kill(twilightHalion);
            }

            void JustReachedHome()
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                me->RemoveAurasDueToSpell(SPELL_TWILIGHT_PHASING);

                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->Reset();

                _JustReachedHome();
=======

                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    me->Kill(controller);
>>>>>>> TC/master
            }

            Position const* GetMeteorStrikePosition() const { return &_meteorStrikePos; }

<<<<<<< HEAD
            void DamageTaken(Unit* /*attacker*/, uint32& damage, SpellInfo const* spellInfo)
=======
            void DamageTaken(Unit* attacker, uint32& damage)
>>>>>>> TC/master
            {
                if (me->HealthBelowPctDamaged(75, damage) && (events.GetPhaseMask() & PHASE_ONE_MASK))
                {
                    events.SetPhase(PHASE_TWO);
<<<<<<< HEAD
                    events.DelayEvents(2600); // 2.5 sec + 0.1 sec lag

                    me->CastStop();
                    me->AttackStop();

                    Talk(SAY_PHASE_TWO);
                    DoCast(me, SPELL_TWILIGHT_PHASING);
                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->DoAction(ACTION_PHASE_TWO);

                    return;
                }

                if (spellInfo && spellInfo->Id != SPELL_COPY_DAMAGE)
                {
                    if ((me->GetHealth() - damage) > 0 && (events.GetPhaseMask() & (PHASE_ONE_MASK | PHASE_THREE_MASK)))
                    {
                        if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_TWILIGHT_HALION)))
                        {
                            SpellNonMeleeDamage damageInfo(me, twilightHalion, SPELL_COPY_DAMAGE, spellInfo->SchoolMask);
                            damageInfo.damage = damage;
                            me->SendSpellNonMeleeDamageLog(&damageInfo);
                            me->DealSpellDamage(&damageInfo, false);
                        }
                    }

                    if ((events.GetPhaseMask() & PHASE_THREE_MASK))
                        if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                            controller->AI()->SetData(DATA_MATERIAL_DAMAGE_TAKEN, damage);
                }
            }

            bool CanAIAttack(Unit const* victim) { return !victim->HasAura(SPELL_TWILIGHT_REALM); }

            void UpdateAI(uint32 const diff)
            {
                if ((!UpdateVictim() && (events.GetPhaseMask() & (PHASE_ONE_MASK | PHASE_THREE_MASK))) || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                // Events won't be updated under phase two.
                if (!(events.GetPhaseMask() & PHASE_TWO_MASK))
                    events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ACTIVATE_FIREWALL:
                        {
                            // Firewall is activated 10 seconds after starting encounter, DOOR_TYPE_ROOM is only instant.
                            if (GameObject* firewall = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_FLAME_RING)))
                                instance->HandleGameObject(instance->GetData64(DATA_FLAME_RING), false, firewall);
                            if (GameObject* firewall = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_TWILIGHT_FLAME_RING)))
                                instance->HandleGameObject(instance->GetData64(DATA_TWILIGHT_FLAME_RING), false, firewall);
                            break;
                        }
                        case EVENT_FLAME_BREATH:
                            DoCast(me, SPELL_FLAME_BREATH);
                            events.ScheduleEvent(EVENT_FLAME_BREATH, 25000);
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                            break;
                        case EVENT_TAIL_LASH:
                            DoCastAOE(SPELL_TAIL_LASH);
                            events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
                            break;
                        case EVENT_METEOR_STRIKE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_TWILIGHT_REALM))
                            {
                                target->GetPosition(&_meteorStrikePos);
                                me->CastSpell(_meteorStrikePos.GetPositionX(), _meteorStrikePos.GetPositionY(), _meteorStrikePos.GetPositionZ(), SPELL_METEOR_STRIKE, true, NULL, NULL, me->GetGUID());
                                Talk(SAY_METEOR_STRIKE);
                            }
                            events.ScheduleEvent(EVENT_METEOR_STRIKE, 40000);
                            break;
                        }
                        case EVENT_FIERY_COMBUSTION:
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_TWILIGHT_REALM);
                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_TWILIGHT_REALM);
                            if (target)
                                DoCast(target, SPELL_FIERY_COMBUSTION);
                            events.ScheduleEvent(EVENT_FIERY_COMBUSTION, 25000);
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
=======
                    Talk(SAY_PHASE_TWO);
                    
                    me->CastStop();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    DoCast(me, SPELL_TWILIGHT_PHASING);

                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->SetData(DATA_FIGHT_PHASE, PHASE_TWO);
                    return;
                }

                if (events.GetPhaseMask() & PHASE_THREE_MASK)
                {
                    // Don't consider copied damage.
                    if (!me->InSamePhase(attacker))
                        return;

                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->SetData(DATA_MATERIAL_DAMAGE_TAKEN, damage);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (events.GetPhaseMask() & PHASE_TWO_MASK)
                    return;

                generic_halionAI::UpdateAI(diff);
            }

            void ExecuteEvent(uint32 const eventId)
            {
                switch (eventId)
                {
                    case EVENT_ACTIVATE_FIREWALL:
                    {
                        // Flame ring is activated 10 seconds after starting encounter, DOOR_TYPE_ROOM is only instant.
                        for (uint8 i = DATA_FLAME_RING; i <= DATA_TWILIGHT_FLAME_RING; ++i)
                            if (GameObject* flameRing = ObjectAccessor::GetGameObject(*me, instance->GetData64(i)))
                                instance->HandleGameObject(instance->GetData64(DATA_FLAME_RING), false, flameRing);
                        break;
                    }
                    case EVENT_FLAME_BREATH:
                        DoCast(me, SPELL_FLAME_BREATH);
                        events.ScheduleEvent(EVENT_FLAME_BREATH, 25000);
                        break;
                    case EVENT_TAIL_LASH:
                        DoCastAOE(SPELL_TAIL_LASH);
                        events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
                        break;
                    case EVENT_METEOR_STRIKE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_TWILIGHT_REALM))
                        {
                            target->GetPosition(&_meteorStrikePos);
                            me->CastSpell(_meteorStrikePos.GetPositionX(), _meteorStrikePos.GetPositionY(), _meteorStrikePos.GetPositionZ(), SPELL_METEOR_STRIKE, true, NULL, NULL, me->GetGUID());
                            Talk(SAY_METEOR_STRIKE);
                        }
                        events.ScheduleEvent(EVENT_METEOR_STRIKE, 40000);
                        break;
                    }
                    case EVENT_FIERY_COMBUSTION:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_TWILIGHT_REALM))
                            DoCast(target, SPELL_FIERY_COMBUSTION);
                        events.ScheduleEvent(EVENT_FIERY_COMBUSTION, 25000);
                        break;
                    }
                    default:
                        generic_halionAI::ExecuteEvent(eventId);
                        break;
                }
>>>>>>> TC/master
            }

            void SetData(uint32 index, uint32 value)
            {
<<<<<<< HEAD
                if (index == DATA_FIGHT_PHASE)
                    events.SetPhase(value);
            }

            uint32 GetData(uint32 index)
            {
                if (index == DATA_FIGHT_PHASE)
                    return events.GetPhaseMask();

                return 0;
            }

            void DoAction(int32 const action)
            {
                if (action != ACTION_BERSERK)
                    return;

                Talk(SAY_BERSERK);
                DoCast(me, SPELL_BERSERK);
=======
                switch (index)
                {
                    case DATA_FIGHT_PHASE:
                        events.SetPhase(value);
                        break;
                    default:
                        generic_halionAI::SetData(index, value);
                }
>>>>>>> TC/master
            }

        private:
            Position _meteorStrikePos;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<boss_halionAI>(creature);
        }
};

typedef boss_halion::boss_halionAI HalionAI;

class boss_twilight_halion : public CreatureScript
{
    public:
        boss_twilight_halion() : CreatureScript("boss_twilight_halion") { }

<<<<<<< HEAD
        struct boss_twilight_halionAI : public ScriptedAI
        {
            boss_twilight_halionAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {
                me->SetPhaseMask(0x20, true); // Should not be visible with phasemask 0x21, so only 0x20
                events.SetPhase(PHASE_ONE);
            }

            void EnterCombat(Unit* who)
            {
                if (Creature* whoCreature = who->ToCreature())
                    if (whoCreature->GetEntry() == NPC_COMBAT_STALKER)
                        return;

                _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
                events.Reset();
                events.SetPhase(PHASE_TWO);
                //! All of Twilight Halion's abilities are not phase dependant as he is never on Phase One.
                //! However, phasemasks are "needed" so that we know on which phase we are when Halion takes
                //! damage, causing corporeality not to tick in phase two.
                events.ScheduleEvent(EVENT_DARK_BREATH, urand(10000, 15000));
                events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, 20000);
                events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
            }

=======
        struct boss_twilight_halionAI : public generic_halionAI
        {
            boss_twilight_halionAI(Creature* creature) : generic_halionAI(creature, DATA_TWILIGHT_HALION)
            {
                Creature* halion = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION));
                if (!halion)
                    return;

                // We use explicit targeting here to avoid conditions + SPELL_ATTR6_CANT_TARGET_SELF.
                // Using AddAura because no spell cast packet in sniffs.
                halion->AddAura(SPELL_COPY_DAMAGE, me);
                me->AddAura(SPELL_COPY_DAMAGE, halion);

                me->SetHealth(halion->GetHealth());
                me->SetPhaseMask(0x20, true);
                me->SetReactState(REACT_AGGRESSIVE);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);

                events.Reset();
                events.SetPhase(PHASE_TWO);
                events.ScheduleEvent(EVENT_DARK_BREATH, urand(10000, 15000));
                events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, 20000);
                events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
            }

            void EnterEvadeMode()
            {
                // We don't care about evading, we will be despawned.
            }

>>>>>>> TC/master
            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);

                // Victims should not be in the Twilight Realm
                me->CastSpell(victim, SPELL_LEAVE_TWILIGHT_REALM, true);
            }

            void JustDied(Unit* killer)
            {
<<<<<<< HEAD
                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
=======
                if (Creature* halion = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION)))
>>>>>>> TC/master
                {
                    // Ensure looting
                    if (me->IsDamageEnoughForLootingAndReward())
                        halion->LowerPlayerDamageReq(halion->GetMaxHealth());

                    if (halion->isAlive())
                        killer->Kill(halion);
                }

<<<<<<< HEAD
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->CastSpell(controller, SPELL_CLEAR_DEBUFFS);
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void JustReachedHome()
            {
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->CastSpell(controller, SPELL_CLEAR_DEBUFFS);
                ScriptedAI::JustReachedHome();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage, SpellInfo const* spellInfo)
=======
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->Kill(controller);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
>>>>>>> TC/master
            {
                if (me->HealthBelowPctDamaged(50, damage) && (events.GetPhaseMask() & PHASE_TWO_MASK))
                {
                    events.SetPhase(PHASE_THREE);
<<<<<<< HEAD
                    events.DelayEvents(2600); // 2.5 sec + 0.1sec lag

=======
>>>>>>> TC/master
                    me->CastStop();
                    DoCast(me, SPELL_TWILIGHT_DIVISION);
                    Talk(SAY_PHASE_THREE);
                    return;
                }

<<<<<<< HEAD
                if (spellInfo && spellInfo->Id != SPELL_COPY_DAMAGE)
                {
                    if ((me->GetHealth() - damage) > 0 && !(events.GetPhaseMask() & PHASE_ONE_MASK))
                    {
                        if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_TWILIGHT_HALION)))
                        {
                            SpellNonMeleeDamage damageInfo(me, halion, SPELL_COPY_DAMAGE, spellInfo->SchoolMask);
                            damageInfo.damage = damage;
                            me->SendSpellNonMeleeDamageLog(&damageInfo);
                            me->DealSpellDamage(&damageInfo, false);
                        }
                    }

                    if ((events.GetPhaseMask() & PHASE_THREE_MASK))
                        if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                            controller->AI()->SetData(DATA_TWILIGHT_DAMAGE_TAKEN, damage);
                }
            }

            void SpellHitTarget(Unit* /*who*/, SpellInfo const* spell)
            {
                if (spell->Id != SPELL_TWILIGHT_DIVISION)
                    return;

                DoCast(me, corporealityReference[5].twilightRealmSpell);
                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                {
                    halion->CastSpell(halion, corporealityReference[5].materialRealmSpell, false);
                    halion->RemoveAurasDueToSpell(SPELL_TWILIGHT_PHASING);
                    halion->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    halion->AI()->SetData(DATA_FIGHT_PHASE, PHASE_THREE);
                }

                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->DoAction(ACTION_PHASE_THREE);
            }

            bool CanAIAttack(Unit const* victim)
            {
                return victim->HasAura(SPELL_TWILIGHT_REALM);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_BERSERK)
                    DoCast(me, SPELL_BERSERK);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DARK_BREATH:
                        {
                            DoCast(me, SPELL_DARK_BREATH);
                            events.ScheduleEvent(EVENT_DARK_BREATH, urand(10000, 15000));
                            break;
                        }
                        case EVENT_SOUL_CONSUMPTION:
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, SPELL_TWILIGHT_REALM);
                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, SPELL_TWILIGHT_REALM);
                            if (target)
                                DoCast(target, SPELL_SOUL_CONSUMPTION);
                            events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, 20000);
                            break;
                        }
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                            break;
                        case EVENT_TAIL_LASH:
                            DoCastAOE(SPELL_TAIL_LASH);
                            events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
=======
                if (events.GetPhaseMask() & PHASE_THREE_MASK)
                {
                    // Don't consider copied damage.
                    if (!me->InSamePhase(attacker))
                        return;

                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->SetData(DATA_TWILIGHT_DAMAGE_TAKEN, damage);
                }
            }

            void SpellHit(Unit* who, SpellInfo const* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_TWILIGHT_DIVISION:
                        if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                            controller->AI()->SetData(DATA_FIGHT_PHASE, PHASE_THREE);
                        break;
                    default:
                        generic_halionAI::SpellHit(who, spell);
                        break;
                }
            }

            void ExecuteEvent(uint32 const eventId)
            {
                switch (eventId)
                {
                    case EVENT_DARK_BREATH:
                        DoCast(me, SPELL_DARK_BREATH);
                        events.ScheduleEvent(EVENT_DARK_BREATH, urand(10000, 15000));
                        break;
                    case EVENT_SOUL_CONSUMPTION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, SPELL_TWILIGHT_REALM))
                            DoCast(target, SPELL_SOUL_CONSUMPTION);
                        events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, 20000);
                        break;
                    case EVENT_TAIL_LASH:
                        DoCastAOE(SPELL_TAIL_LASH);
                        events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
                        break;
                    default:
                        generic_halionAI::ExecuteEvent(eventId);
                        break;
                }
            }

        private:
>>>>>>> TC/master
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<boss_twilight_halionAI>(creature);
        }
};

<<<<<<< HEAD
typedef boss_twilight_halion::boss_twilight_halionAI twilightHalionAI;

=======
>>>>>>> TC/master
class npc_halion_controller : public CreatureScript
{
    public:
        npc_halion_controller() : CreatureScript("npc_halion_controller") { }

        struct npc_halion_controllerAI : public ScriptedAI
        {
            npc_halion_controllerAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript()), _summons(me)
            {
                me->SetPhaseMask(me->GetPhaseMask() | 0x20, true);
<<<<<<< HEAD
=======
                _events.SetPhase(PHASE_INTRO);
>>>>>>> TC/master
            }

            void Reset()
            {
<<<<<<< HEAD
                me->SetReactState(REACT_PASSIVE);
                _summons.DespawnAll();
                _events.Reset();
=======
                _summons.DespawnAll();
                _events.Reset();
                _materialCorporealityValue = 5;

>>>>>>> TC/master
                DoCast(me, SPELL_CLEAR_DEBUFFS);
            }

            void JustSummoned(Creature* who)
            {
                _summons.Summon(who);
            }

<<<<<<< HEAD
            void EnterCombat(Unit* who)
            {
                if (Creature* combatStalker = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_COMBAT_STALKER)))
                    combatStalker->AI()->EnterCombat(who);

                _events.ScheduleEvent(EVENT_BERSERK, 8 * MINUTE * IN_MILLISECONDS);
=======
            void JustDied(Unit* /*killer*/)
            {
                _events.Reset();
                _summons.DespawnAll();

                DoCast(me, SPELL_CLEAR_DEBUFFS);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _twilightDamageTaken = 0;
                _materialDamageTaken = 0;

                _events.ScheduleEvent(EVENT_TRIGGER_BERSERK, 8 * MINUTE * IN_MILLISECONDS);
            }

            void JustReachedHome()
            {
                if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_TWILIGHT_HALION)))
                    twilightHalion->DespawnOrUnsummon();

                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                {
                    halion->AI()->SetData(DATA_EVADE_METHOD, 1);
                    halion->AI()->EnterEvadeMode();
                }

                _instance->SetBossState(DATA_HALION, FAIL);
>>>>>>> TC/master
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_INTRO_HALION:
<<<<<<< HEAD
                    {
                        _events.Reset();
                        _events.ScheduleEvent(EVENT_START_INTRO, 2000);
                        _events.ScheduleEvent(EVENT_INTRO_PROGRESS_1, 6000);
                        _events.ScheduleEvent(EVENT_INTRO_PROGRESS_2, 10000);
                        _events.ScheduleEvent(EVENT_INTRO_PROGRESS_3, 14000);
                        break;
                    }
                    case ACTION_PHASE_TWO:
                    {
                        _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, 10000); // Fix the timer
                        break;
                    }
                    case ACTION_PHASE_THREE:
                    {
                        _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 20000);
                        TwilightDamageTaken = 0;
                        MaterialDamageTaken = 0;
                        materialCorporealityValue = 50;
                        _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TOGGLE, 1);
                        _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_MATERIAL, 50);
                        _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TWILIGHT, 50);
                        break;
                    }
=======
                        _events.Reset();
                        _events.SetPhase(PHASE_INTRO);
                        _events.ScheduleEvent(EVENT_START_INTRO, 2000);
                        break;
                    default:
                        break;
>>>>>>> TC/master
                }
            }

            void UpdateAI(uint32 const diff)
            {
<<<<<<< HEAD
=======
                // The isInCombat() check is needed because that check should be false when Halion is
                // not engaged, while it would return true without as UpdateVictim() checks for
                // combat state.
                if (!(_events.GetPhaseMask() & PHASE_INTRO_MASK) && me->isInCombat() && !UpdateVictim())
                {
                    EnterEvadeMode();
                    return;
                }

>>>>>>> TC/master
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_INTRO:
                            DoCast(me, SPELL_COSMETIC_FIRE_PILLAR, true);
<<<<<<< HEAD
=======
                            _events.ScheduleEvent(EVENT_INTRO_PROGRESS_1, 4000);
>>>>>>> TC/master
                            break;
                        case EVENT_INTRO_PROGRESS_1:
                            for (uint8 i = DATA_BURNING_TREE_3; i <= DATA_BURNING_TREE_4; ++i)
                                if (GameObject* tree = ObjectAccessor::GetGameObject(*me, _instance->GetData64(i)))
                                    _instance->HandleGameObject(_instance->GetData64(i), true, tree);
<<<<<<< HEAD
=======
                            _events.ScheduleEvent(EVENT_INTRO_PROGRESS_2, 4000);
>>>>>>> TC/master
                            break;
                        case EVENT_INTRO_PROGRESS_2:
                            for (uint8 i = DATA_BURNING_TREE_1; i <= DATA_BURNING_TREE_2; ++i)
                                if (GameObject* tree = ObjectAccessor::GetGameObject(*me, _instance->GetData64(i)))
                                    _instance->HandleGameObject(_instance->GetData64(i), true, tree);
<<<<<<< HEAD
=======
                            _events.ScheduleEvent(EVENT_INTRO_PROGRESS_3, 4000);
>>>>>>> TC/master
                            break;
                        case EVENT_INTRO_PROGRESS_3:
                            DoCast(me, SPELL_FIERY_EXPLOSION);
                            if (Creature* halion = me->GetMap()->SummonCreature(NPC_HALION, HalionSpawnPos))
                                halion->AI()->Talk(SAY_INTRO);
<<<<<<< HEAD
                            me->GetMap()->SummonCreature(NPC_TWILIGHT_HALION, HalionSpawnPos);
                            break;
                        case EVENT_SHADOW_PULSARS_SHOOT:
                        {
=======
                            break;
                        case EVENT_TWILIGHT_MENDING:
                            if (ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION))) // Just check if physical Halion is spawned
                                if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_TWILIGHT_HALION)))
                                    twilightHalion->CastSpell((Unit*)NULL, SPELL_TWILIGHT_MENDING, true);
                            break;
                        case EVENT_TRIGGER_BERSERK:
                            for (uint8 i = DATA_HALION; i <= DATA_TWILIGHT_HALION; i++)
                                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(i)))
                                    halion->CastSpell(halion, SPELL_BERSERK, true);
                            break;
                        case EVENT_SHADOW_PULSARS_SHOOT:
>>>>>>> TC/master
                            if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_TWILIGHT_HALION)))
                                twilightHalion->AI()->Talk(SAY_SPHERE_PULSE);

                            if (Creature* orbCarrier = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORB_CARRIER)))
                                orbCarrier->AI()->DoAction(ACTION_SHOOT);

<<<<<<< HEAD
                            _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, 29000);   // 9 sec channel duration, every 20th second
                            break;
                        }
                        case EVENT_CHECK_CORPOREALITY:
                        {
                            bool canUpdate = false;
                            if (MaterialDamageTaken != 0 && TwilightDamageTaken != 0)
                            {
                                // Guessed scaling
                                if (MaterialDamageTaken >= 1.02f * TwilightDamageTaken)
                                {
                                    TwilightDamageTaken = 0;
                                    MaterialDamageTaken = 0;
                                    canUpdate = (materialCorporealityValue != 0);
                                    if (canUpdate)
                                        materialCorporealityValue -= 10;
                                }
                                else if (TwilightDamageTaken >= 1.02f * MaterialDamageTaken)
                                {
                                    TwilightDamageTaken = 0;
                                    MaterialDamageTaken = 0;
                                    canUpdate = (materialCorporealityValue != 100);
                                    if (canUpdate)
                                        materialCorporealityValue += 10;
                                }
                            }
                            else
                            {
                                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                                {
                                    if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_TWILIGHT_HALION)))
                                    {
                                        twilightHalion->CastSpell(halion, SPELL_TWILIGHT_MENDING);

                                        // TODO: I bet this is wrong
                                        Map::PlayerList const &PlList = me->GetMap()->GetPlayers();
                                        for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                                            if (Player* player = i->getSource())
                                                Talk(EMOTE_REGENERATE, player->GetGUID());
                                    }
                                }
                                _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 15000);
                                break;
                            }

                            if (canUpdate)
                            {
                                for (uint8 i = 0; i < MAX_CORPOREALITY_STATE; i++)
                                {
                                    if (corporealityReference[i].materialPercentage == materialCorporealityValue)
                                    {
                                        for (uint8 j = DATA_HALION; j <= DATA_TWILIGHT_HALION; j++)
                                        {
                                            if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(j)))
                                            {
                                                RemoveCorporeality(halion);
                                                halion->CastSpell(halion, (j == DATA_HALION ? corporealityReference[i].materialRealmSpell : corporealityReference[i].twilightRealmSpell), true);
                                            }
                                        }
                                        break; // No need to iterate more
                                    }
                                }

                                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_MATERIAL, materialCorporealityValue);
                                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TWILIGHT, (100 - materialCorporealityValue));

                                Map::PlayerList const &playersList = me->GetMap()->GetPlayers();
                                for (Map::PlayerList::const_iterator i = playersList.begin(); i != playersList.end(); ++i)
                                {
                                    if (Player* player = i->getSource())
                                    {
                                        if (materialCorporealityValue > 50) // Range is 0 ... 100
                                        {
                                            if (player->HasAura(SPELL_TWILIGHT_REALM))
                                                Talk(EMOTE_TWILIGHT_OUT_TWILIGHT, player->GetGUID());
                                            else
                                                Talk(EMOTE_PHYSICAL_IN_PHYSICAL, player->GetGUID());
                                        }
                                        else
                                        {
                                            if (player->HasAura(SPELL_TWILIGHT_REALM))
                                                Talk(EMOTE_TWILIGHT_IN_TWILIGHT, player->GetGUID());
                                            else
                                                Talk(EMOTE_PHYSICAL_OUT_PHYSICAL, player->GetGUID());
                                        }
                                    }
                                }
                            }
                            _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 15000);
                            break;
                        }
                        case EVENT_BERSERK:
                        {
                            for (uint8 i = DATA_HALION; i <= DATA_TWILIGHT_HALION; i++)
                                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(i)))
                                    halion->AI()->DoAction(ACTION_BERSERK);
                            break;
                        }
=======
                            _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, 29000);
                            break;
                        case EVENT_CHECK_CORPOREALITY:
                            UpdateCorporeality();
                            _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 5000);
                            break;
>>>>>>> TC/master
                        default:
                            break;
                    }
                }
            }

            void SetData(uint32 id, uint32 value)
            {
                switch (id)
                {
                    case DATA_MATERIAL_DAMAGE_TAKEN:
<<<<<<< HEAD
                        MaterialDamageTaken += value;
                        break;
                    case DATA_TWILIGHT_DAMAGE_TAKEN:
                        TwilightDamageTaken += value;
                        break;
                }
            }

        private:

            void RemoveCorporeality(Creature* who)
            {
                for (uint8 i = 0; i < MAX_CORPOREALITY_STATE; i++)
                {
                    if (who->HasAura(corporealityReference[i].materialRealmSpell))
                    {
                        who->RemoveAurasDueToSpell(corporealityReference[i].materialRealmSpell);
                        break;
                    }
                    if (who->HasAura(corporealityReference[i].twilightRealmSpell))
                    {
                        who->RemoveAurasDueToSpell(corporealityReference[i].twilightRealmSpell);
=======
                        _materialDamageTaken += value;
                        break;
                    case DATA_TWILIGHT_DAMAGE_TAKEN:
                        _twilightDamageTaken += value;
                        break;
                    case DATA_FIGHT_PHASE:
                        _events.SetPhase(value);
                        switch (value)
                        {
                            case PHASE_ONE:
                                DoZoneInCombat();
                                break;
                            case PHASE_TWO:
                                // Timer taken from a 4.3.4 solo video and confirmed by TankSpot's 3.3.5 guide. http://www.tankspot.com/showthread.php?67195-Halion-Encounter-Guide-Live
                                _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, 29000);
                                break;
                            case PHASE_THREE:
                                _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 5000);
                                // Load up corporeality data.
                                for (uint8 itr = DATA_HALION; itr <= DATA_TWILIGHT_HALION; itr++)
                                {
                                    Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(itr));
                                    if (!halion)
                                        continue;

                                    halion->CastSpell(halion, GetSpell(_materialCorporealityValue, itr == DATA_TWILIGHT_HALION), false);
                                    halion->AI()->SetData(DATA_FIGHT_PHASE, PHASE_THREE);

                                    if (itr == DATA_TWILIGHT_HALION)
                                        continue;

                                    halion->RemoveAurasDueToSpell(SPELL_TWILIGHT_PHASING);
                                    halion->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                }

                                // Summon Twilight portals
                                DoCast(me, SPELL_SUMMON_EXIT_PORTALS);

                                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TOGGLE, 1);
                                // Hardcoding doesn't really matter here.
                                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_MATERIAL, 50);
                                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TWILIGHT, 50);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
            }

        private:
            /// TODO: Find out a better scaling, if any.
            // [0   , 0.98[: Corporeality goes down
            // [0.98, 0.99]: Do nothing
            // ]0.99, 1.01[: Twilight Mending
            // [1.01, 1.02]: Do nothing
            // ]1.02, +oo [: Corporeality goes up
            void UpdateCorporeality()
            {
                uint8 oldValue = _materialCorporealityValue;
                if (_twilightDamageTaken == 0 || _materialDamageTaken == 0)
                {
                    _events.ScheduleEvent(EVENT_TWILIGHT_MENDING, 100);
                    _twilightDamageTaken = 0;
                    _materialDamageTaken = 0;
                    return;
                }

                float damageRatio = float(_materialDamageTaken) / float(_twilightDamageTaken);

                CorporealityEvent action = CORPOREALITY_NONE;
                if (damageRatio < 0.98f)                            // [0   , 0.98[: Corporeality goes down
                    action = CORPOREALITY_DECREASE;
                else if (0.99f < damageRatio && damageRatio < 1.0f) // ]0.99, 1.01[: Twilight Mending
                    action = CORPOREALITY_TWILIGHT_MENDING;
                else if (1.02f < damageRatio)                       // ]1.02, +oo [: Corporeality goes up
                    action = CORPOREALITY_INCREASE;

                switch (action)
                {
                    case CORPOREALITY_NONE:
                        return;
                    case CORPOREALITY_INCREASE:
                    {
                        if (_materialCorporealityValue >= (MAX_CORPOREALITY_STATE - 1))
                            return;
                        ++_materialCorporealityValue;
                        break;
                    }
                    case CORPOREALITY_DECREASE:
                    {
                        if (_materialCorporealityValue <= 0)
                            return;
                        --_materialCorporealityValue;
                        break;
                    }
                    case CORPOREALITY_TWILIGHT_MENDING:
                    {
                        _events.ScheduleEvent(EVENT_TWILIGHT_MENDING, 100);
                        _materialDamageTaken = 0;
                        _twilightDamageTaken = 0;
                        return;
                    }
                    default:
                        break;
                }

                _materialDamageTaken = 0;
                _twilightDamageTaken = 0;

                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_MATERIAL, _materialCorporealityValue * 10);
                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TWILIGHT, 100 - _materialCorporealityValue * 10);

                for (uint8 itr = DATA_HALION; itr <= DATA_TWILIGHT_HALION; itr++)
                {
                    if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(itr)))
                    {
                        RemoveCorporeality(halion, itr == DATA_TWILIGHT_HALION);
                        halion->CastSpell(halion, GetSpell(_materialCorporealityValue, itr == DATA_TWILIGHT_HALION), true);

                        if (itr == DATA_TWILIGHT_HALION)
                            halion->AI()->Talk(oldValue < _materialCorporealityValue ? EMOTE_CORPOREALITY_TOT : EMOTE_CORPOREALITY_TIT, halion->GetGUID());
                        else // if (itr == DATA_HALION)
                            halion->AI()->Talk(oldValue > _materialCorporealityValue ? EMOTE_CORPOREALITY_POT : EMOTE_CORPOREALITY_PIP, halion->GetGUID());
                    }
                }
            }

            void RemoveCorporeality(Creature* who, bool isTwilight = false)
            {
                for (uint8 i = 0; i < MAX_CORPOREALITY_STATE; i++)
                {
                    uint32 spellID = (isTwilight ? _corporealityReference[i].twilightRealmSpell : _corporealityReference[i].materialRealmSpell);
                    if (who->HasAura(spellID))
                    {
                        who->RemoveAurasDueToSpell(spellID);
>>>>>>> TC/master
                        break;
                    }
                }
            }

<<<<<<< HEAD
            EventMap _events;
            InstanceScript* _instance;
            SummonList _summons;
            uint32 TwilightDamageTaken;
            uint32 MaterialDamageTaken;
            uint8 materialCorporealityValue;
=======
            uint32 GetSpell(uint8 pctValue, bool isTwilight = false) const
            {
                CorporealityEntry entry = _corporealityReference[pctValue];
                return isTwilight ? entry.twilightRealmSpell : entry.materialRealmSpell;
            }

            EventMap _events;
            InstanceScript* _instance;
            SummonList _summons;

            bool _corporealityCheck;

            uint32 _twilightDamageTaken;
            uint32 _materialDamageTaken;
            uint8 _materialCorporealityValue;
>>>>>>> TC/master
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_halion_controllerAI>(creature);
        }
};

typedef npc_halion_controller::npc_halion_controllerAI controllerAI;

<<<<<<< HEAD
=======
class npc_orb_carrier : public CreatureScript
{
    public:
        npc_orb_carrier() : CreatureScript("npc_orb_carrier") { }

        struct npc_orb_carrierAI : public ScriptedAI
        {
            npc_orb_carrierAI(Creature* creature) : ScriptedAI(creature),
                instance(creature->GetInstanceScript())
            {
                ASSERT(creature->GetVehicleKit());
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                /// According to sniffs this spell is cast every 1 or 2 seconds.
                /// However, refreshing it looks bad, so just cast the spell if
                /// we are not channeling it.
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    me->CastSpell((Unit*)NULL, SPELL_TRACK_ROTATION, false);

                /// Workaround: This is here because even though the above spell has SPELL_ATTR1_CHANNEL_TRACK_TARGET,
                /// we are having two creatures involded here. This attribute is handled clientside, meaning the client
                /// sends orientation update itself. Here, no packet is sent, and the creature does not rotate. By
                /// forcing the carrier to always be facing the rotation focus, we ensure everything works as it should.
                if (Creature* rotationFocus = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_ORB_ROTATION_FOCUS)))
                    me->SetFacingToObject(rotationFocus); // setInFront
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_SHOOT)
                {
                    Vehicle* vehicle = me->GetVehicleKit();
                    Unit* southOrb = vehicle->GetPassenger(SEAT_SOUTH);
                    Unit* northOrb = vehicle->GetPassenger(SEAT_NORTH);
                    if (southOrb && northOrb)
                    {
                        if (northOrb->GetTypeId() == TYPEID_UNIT)
                            northOrb->ToCreature()->AI()->Talk(EMOTE_WARN_LASER);
                        TriggerCutter(northOrb, southOrb);
                    }

                    if (!IsHeroic())
                        return;

                    Unit* eastOrb = vehicle->GetPassenger(SEAT_EAST);
                    Unit* westOrb = vehicle->GetPassenger(SEAT_WEST);
                    if (eastOrb && westOrb)
                        TriggerCutter(eastOrb, westOrb);
                }
            }
        private:
            InstanceScript* instance;

            void TriggerCutter(Unit* caster, Unit* target)
            {
                caster->CastSpell(caster, SPELL_TWILIGHT_PULSE_PERIODIC, true);
                target->CastSpell(target, SPELL_TWILIGHT_PULSE_PERIODIC, true);
                caster->CastSpell(target, SPELL_TWILIGHT_CUTTER, false);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_orb_carrierAI>(creature);
        }
};

>>>>>>> TC/master
class npc_meteor_strike_initial : public CreatureScript
{
    public:
        npc_meteor_strike_initial() : CreatureScript("npc_meteor_strike_initial") { }

        struct npc_meteor_strike_initialAI : public Scripted_NoMovementAI
        {
            npc_meteor_strike_initialAI(Creature* creature) : Scripted_NoMovementAI(creature),
                _instance(creature->GetInstanceScript())
            { }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_METEOR_STRIKE_AOE:
                        DoCast(me, SPELL_METEOR_STRIKE_AOE_DAMAGE, true);
                        DoCast(me, SPELL_METEOR_STRIKE_FIRE_AURA_1, true);
                        for (std::list<Creature*>::iterator itr = _meteorList.begin(); itr != _meteorList.end(); ++itr)
                            (*itr)->AI()->DoAction(ACTION_METEOR_STRIKE_BURN);
                        break;
                }
            }

            void IsSummonedBy(Unit* summoner)
            {
                Creature* owner = summoner->ToCreature();
                if (!owner)
                    return;

                // Let Halion Controller count as summoner
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);

                DoCast(me, SPELL_METEOR_STRIKE_COUNTDOWN);
                DoCast(me, SPELL_BIRTH_NO_VISUAL); // Unknown purpose

                if (HalionAI* halionAI = CAST_AI(HalionAI, owner->AI()))
                {
                    Position const* ownerPos = halionAI->GetMeteorStrikePosition();
                    Position newPos;
                    float angle[4];
                    angle[0] = me->GetAngle(ownerPos);
                    angle[1] = me->GetAngle(ownerPos) - static_cast<float>(M_PI/2);
                    angle[2] = me->GetAngle(ownerPos) - static_cast<float>(-M_PI/2);
                    angle[3] = me->GetAngle(ownerPos) - static_cast<float>(M_PI);

                    _meteorList.clear();
                    for (uint8 i = 0; i < 4; i++)
                    {
<<<<<<< HEAD
                        MapManager::NormalizeOrientation(angle[i]);
=======
                        angle[i] = MapManager::NormalizeOrientation(angle[i]);
>>>>>>> TC/master
                        me->SetOrientation(angle[i]);
                        me->GetNearPosition(newPos, 10.0f, 0.0f); // Exact distance
                        if (Creature* meteor = me->SummonCreature(NPC_METEOR_STRIKE_NORTH + i, newPos, TEMPSUMMON_TIMED_DESPAWN, 30000))
                            _meteorList.push_back(meteor);
                    }
                }
            }

            void UpdateAI(uint32 const /*diff*/) { }
            void EnterEvadeMode() { }
<<<<<<< HEAD

=======
>>>>>>> TC/master
        private:
            InstanceScript* _instance;
            std::list<Creature*> _meteorList;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_meteor_strike_initialAI>(creature);
        }
};

class npc_meteor_strike : public CreatureScript
{
    public:
        npc_meteor_strike() : CreatureScript("npc_meteor_strike") { }

        struct npc_meteor_strikeAI : public Scripted_NoMovementAI
        {
            npc_meteor_strikeAI(Creature* creature) : Scripted_NoMovementAI(creature),
                _instance(creature->GetInstanceScript())
            {
                _range = 5.0f;
                _spawnCount = 0;
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_METEOR_STRIKE_BURN)
                {
                    DoCast(me, SPELL_METEOR_STRIKE_FIRE_AURA_2, true);
                    me->setActive(true);
                    _events.ScheduleEvent(EVENT_SPAWN_METEOR_FLAME, 500);
                }
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                // Let Halion Controller count as summoner.
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);
            }

            void UpdateAI(uint32 const diff)
            {
                if (_spawnCount > 5)
                    return;

                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_SPAWN_METEOR_FLAME)
                {
                    Position pos;
                    me->GetNearPosition(pos, _range, 0.0f);

                    if (Creature* flame = me->SummonCreature(NPC_METEOR_STRIKE_FLAME, pos, TEMPSUMMON_TIMED_DESPAWN, 25000))
                    {
                        if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                            controller->AI()->JustSummoned(flame);

                        flame->CastSpell(flame, SPELL_METEOR_STRIKE_FIRE_AURA_2, true);
                        ++_spawnCount;
                    }
                    _range += 5.0f;
                    _events.ScheduleEvent(EVENT_SPAWN_METEOR_FLAME, 800);
                }
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            float _range;
            uint8 _spawnCount;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_meteor_strikeAI>(creature);
        }
};

class npc_combustion_consumption : public CreatureScript
{
    public:
        npc_combustion_consumption() : CreatureScript("npc_combustion_consumption") { }

        struct npc_combustion_consumptionAI : public Scripted_NoMovementAI
        {
            npc_combustion_consumptionAI(Creature* creature) : Scripted_NoMovementAI(creature),
<<<<<<< HEAD
                   _summonerGuid(0), _instance(creature->GetInstanceScript())
=======
                   _instance(creature->GetInstanceScript()), _summonerGuid(0)
>>>>>>> TC/master
            {
                switch (me->GetEntry())
                {
                    case NPC_COMBUSTION:
                        _explosionSpell = SPELL_FIERY_COMBUSTION_EXPLOSION;
                        _damageSpell = SPELL_COMBUSTION_DAMAGE_AURA;
<<<<<<< HEAD
=======
                        me->SetPhaseMask(0x01, true);
>>>>>>> TC/master
                        break;
                    case NPC_CONSUMPTION:
                        _explosionSpell = SPELL_SOUL_CONSUMPTION_EXPLOSION;
                        _damageSpell = SPELL_CONSUMPTION_DAMAGE_AURA;
                        me->SetPhaseMask(0x20, true);
                        break;
                    default: // Should never happen
                        _explosionSpell = 0;
                        _damageSpell = 0;
                        break;
                }
<<<<<<< HEAD
=======

>>>>>>> TC/master
                if (IsHeroic())
                    me->SetPhaseMask(0x01 | 0x20, true);
            }

            void IsSummonedBy(Unit* summoner)
            {
                // Let Halion Controller count as summoner
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);

                _summonerGuid = summoner->GetGUID();
            }

<<<<<<< HEAD
            void SetData(uint32 type, uint32 value)
=======
            void SetData(uint32 type, uint32 stackAmount)
>>>>>>> TC/master
            {
                Unit* summoner = ObjectAccessor::GetUnit(*me, _summonerGuid);

                if (type != DATA_STACKS_DISPELLED || !_damageSpell || !_explosionSpell || !summoner)
                    return;

<<<<<<< HEAD
                me->CastCustomSpell(SPELL_SCALE_AURA, SPELLVALUE_AURA_STACK, value, me);
                DoCast(me, _damageSpell);

                int32 damage = 1200 + (value * 1290); // Needs moar research.
                // Target is TARGET_UNIT_AREA_ALLY_SRC (TARGET_SRC_CASTER)
=======
                me->CastCustomSpell(SPELL_SCALE_AURA, SPELLVALUE_AURA_STACK, stackAmount, me);
                DoCast(me, _damageSpell);

                int32 damage = 1200 + (stackAmount * 1290); // Needs more researches.
>>>>>>> TC/master
                summoner->CastCustomSpell(_explosionSpell, SPELLVALUE_BASE_POINT0, damage, summoner);
            }

            void UpdateAI(uint32 const /*diff*/) { }

        private:
            InstanceScript* _instance;
            uint32 _explosionSpell;
            uint32 _damageSpell;
            uint64 _summonerGuid;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_combustion_consumptionAI>(creature);
        }
};

<<<<<<< HEAD
class npc_orb_carrier : public CreatureScript
{
    public:
        npc_orb_carrier() : CreatureScript("npc_orb_carrier") { }

        struct npc_orb_carrierAI : public ScriptedAI
        {
            npc_orb_carrierAI(Creature* creature) : ScriptedAI(creature)
            {
                ASSERT(creature->GetVehicleKit());
                me->setActive(true);
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                //! According to sniffs this spell is cast every 1 or 2 seconds.
                //! However, refreshing it looks bad, so just cast the spell if
                //! we are not channeling it.
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    me->CastSpell((Unit*)NULL, SPELL_TRACK_ROTATION, false);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_SHOOT)
                {
                    Vehicle* vehicle = me->GetVehicleKit();
                    Unit* southOrb = vehicle->GetPassenger(SEAT_SOUTH);
                    Unit* northOrb = vehicle->GetPassenger(SEAT_NORTH);
                    if (southOrb && northOrb)
                    {
                        if (northOrb->GetTypeId() != TYPEID_UNIT || southOrb->GetTypeId() != TYPEID_UNIT)
                            return;

                        northOrb->ToCreature()->AI()->Talk(EMOTE_WARN_LASER);
                        northOrb->CastSpell(northOrb, SPELL_TWILIGHT_PULSE_PERIODIC, true);
                        southOrb->CastSpell(southOrb, SPELL_TWILIGHT_PULSE_PERIODIC, true);
                        northOrb->CastSpell(southOrb, SPELL_TWILIGHT_CUTTER, false);
                    }

                    if (!IsHeroic())
                        return;

                    Unit* eastOrb = vehicle->GetPassenger(SEAT_EAST);
                    Unit* westOrb = vehicle->GetPassenger(SEAT_WEST);
                    if (eastOrb && westOrb)
                    {
                        if (eastOrb->GetTypeId() != TYPEID_UNIT || westOrb->GetTypeId() != TYPEID_UNIT)
                            return;

                        eastOrb->CastSpell(eastOrb, SPELL_TWILIGHT_PULSE_PERIODIC, true);
                        westOrb->CastSpell(westOrb, SPELL_TWILIGHT_PULSE_PERIODIC, true);
                        eastOrb->CastSpell(westOrb, SPELL_TWILIGHT_CUTTER, false);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_orb_carrierAI>(creature);
        }
};

class npc_combat_stalker : public CreatureScript
{
    public:
        npc_combat_stalker() : CreatureScript("npc_combat_stalker") { }

        struct npc_combat_stalkerAI : public Scripted_NoMovementAI
        {
            npc_combat_stalkerAI(Creature* creature) : Scripted_NoMovementAI(creature),
                   _instance(creature->GetInstanceScript())
            {
                creature->SetPhaseMask(0x20|0x1, true);
                me->setActive(true);
            }

            void EnterCombat(Unit* who)
            {
                DoZoneInCombat();
                if (who->GetTypeId() == TYPEID_UNIT)
                    if (who->ToCreature()->GetEntry() == NPC_HALION || who->ToCreature()->GetEntry() == NPC_TWILIGHT_HALION)
                        me->AddThreat(who, float(urand(1,3) * 100.0f));

                _wipeCheck = true;
            }

            void EnterEvadeMode()
            {
                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                    halion->AI()->EnterEvadeMode();

                if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_TWILIGHT_HALION)))
                    twilightHalion->AI()->EnterEvadeMode();

                _wipeCheck = false;

                ScriptedAI::EnterEvadeMode();
            }

            void UpdateAI(uint32 const diff)
            {
                if (!me->isInCombat())
                    return;

                std::list<HostileReference*> const& threatList = me->getThreatManager().getThreatList();
                if (threatList.empty())
                {
                    EnterEvadeMode();
                    return;
                }

                if (!_wipeCheck)
                    return;

                _wipeCheck = !_wipeCheck;
                for (std::list<HostileReference*>::const_iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
                    if (Unit* refTarget = (*itr)->getTarget())
                        if (refTarget->GetTypeId() == TYPEID_PLAYER)
                            return;

                EnterEvadeMode();
            }

        private:
            InstanceScript* _instance;
            bool _wipeCheck;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_combat_stalkerAI>(creature);
        }
};

=======
>>>>>>> TC/master
class npc_living_inferno : public CreatureScript
{
    public:
        npc_living_inferno() : CreatureScript("npc_living_inferno") { }

        struct npc_living_infernoAI : public ScriptedAI
        {
            npc_living_infernoAI(Creature* creature) : ScriptedAI(creature) { }

            void JustSummoned(Creature* /*summoner*/)
            {
                me->SetInCombatWithZone();
                DoCast(me, SPELL_BLAZING_AURA);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_living_infernoAI>(creature);
        }
};

//! Need sniff data
class npc_living_ember : public CreatureScript
{
    public:
        npc_living_ember() : CreatureScript("npc_living_ember") { }

        struct npc_living_emberAI : public ScriptedAI
        {
            npc_living_emberAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                _hasEnraged = false;
            }

            void EnterCombat(Unit* /*who*/)
            {
<<<<<<< HEAD
                _events.Reset();
                _events.ScheduleEvent(EVENT_EMBER_ENRAGE, 20000);
=======
                _enrageTimer = 20000;
                _hasEnraged = false;
>>>>>>> TC/master
            }

            void UpdateAI(uint32 const diff)
            {
<<<<<<< HEAD
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (!_hasEnraged && _events.ExecuteEvent() == EVENT_EMBER_ENRAGE)
=======
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (!_hasEnraged && _enrageTimer <= diff)
>>>>>>> TC/master
                {
                    _hasEnraged = true;
                    DoCast(me, SPELL_BERSERK);
                }
<<<<<<< HEAD
=======
                else _enrageTimer -= diff;
>>>>>>> TC/master

                DoMeleeAttackIfReady();
            }

        private:
<<<<<<< HEAD
            EventMap _events;
=======
            uint32 _enrageTimer;
>>>>>>> TC/master
            bool _hasEnraged;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_living_emberAI>(creature);
        }
};

<<<<<<< HEAD
class spell_halion_meteor_strike_marker : public SpellScriptLoader
{
    public:
        spell_halion_meteor_strike_marker() : SpellScriptLoader("spell_halion_meteor_strike_marker") { }

        class spell_halion_meteor_strike_marker_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_meteor_strike_marker_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster())
                    return;

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    if (Creature* creCaster = GetCaster()->ToCreature())
                        creCaster->AI()->DoAction(ACTION_METEOR_STRIKE_AOE);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_meteor_strike_marker_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_meteor_strike_marker_AuraScript();
        }
};

class spell_halion_fiery_combustion : public SpellScriptLoader
{
    public:
        spell_halion_fiery_combustion() : SpellScriptLoader("spell_halion_fiery_combustion") { }

        class spell_halion_fiery_combustion_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_fiery_combustion_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MARK_OF_COMBUSTION))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->HasAura(SPELL_MARK_OF_COMBUSTION))
                    GetTarget()->RemoveAurasDueToSpell(SPELL_MARK_OF_COMBUSTION, 0, 0, AURA_REMOVE_BY_EXPIRE);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_COMBUSTION, true);
            }

            void AddMarkStack(AuraEffect const* /*aurEff*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_COMBUSTION, true);
=======
class go_twilight_portal : public GameObjectScript
{
    public:
        go_twilight_portal() : GameObjectScript("go_twilight_portal") { }

        struct go_twilight_portalAI : public GameObjectAI
        {
            go_twilight_portalAI(GameObject* gameobject) : GameObjectAI(gameobject),
                _instance(gameobject->GetInstanceScript()), _deleted(false)
            {
                switch (gameobject->GetEntry())
                {
                    case GO_HALION_PORTAL_EXIT:
                        gameobject->SetPhaseMask(0x20, true);
                        _spellId = gameobject->GetGOInfo()->goober.spellId;
                        break;
                    case GO_HALION_PORTAL_1:
                    case GO_HALION_PORTAL_2: // Not used, not seen in sniffs. Just in case.
                        gameobject->SetPhaseMask(0x1, true);
                        /// Because WDB template has non-existent spell ID, not seen in sniffs either, meh
                        _spellId = SPELL_TWILIGHT_REALM;
                        break;
                    default:
                        _spellId = 0;
                        break;
                }
            }

            bool GossipHello(Player* player)
            {
                if (_spellId != 0)
                    player->CastSpell(player, _spellId, true);
                return true;
            }

            void UpdateAI(uint32 /*diff*/)
            {
                if (_instance->GetBossState(DATA_HALION) == IN_PROGRESS)
                    return;

                if (!_deleted)
                {
                    _deleted = true;
                    go->Delete();
                }
            }

        private:
            InstanceScript* _instance;
            uint32 _spellId;
            bool _deleted;
        };

        GameObjectAI* GetAI(GameObject* gameobject) const
        {
            return GetRubySanctumAI<go_twilight_portalAI>(gameobject);
        }
};

class spell_halion_meteor_strike_marker : public SpellScriptLoader
{
    public:
        spell_halion_meteor_strike_marker() : SpellScriptLoader("spell_halion_meteor_strike_marker") { }

        class spell_halion_meteor_strike_marker_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_meteor_strike_marker_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster())
                    return;

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    if (Creature* creCaster = GetCaster()->ToCreature())
                        creCaster->AI()->DoAction(ACTION_METEOR_STRIKE_AOE);
>>>>>>> TC/master
            }

            void Register()
            {
<<<<<<< HEAD
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halion_fiery_combustion_AuraScript::AddMarkStack, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectApply += AuraEffectApplyFn(spell_halion_fiery_combustion_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_fiery_combustion_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
=======
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_meteor_strike_marker_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
>>>>>>> TC/master
            }
        };

        AuraScript* GetAuraScript() const
        {
<<<<<<< HEAD
            return new spell_halion_fiery_combustion_AuraScript();
        }
};

class spell_halion_soul_consumption : public SpellScriptLoader
{
    public:
        spell_halion_soul_consumption() : SpellScriptLoader("spell_halion_soul_consumption") { }

        class spell_halion_soul_consumption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_soul_consumption_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MARK_OF_CONSUMPTION))
=======
            return new spell_halion_meteor_strike_marker_AuraScript();
        }
};

class spell_halion_combustion_consumption : public SpellScriptLoader
{
    public:
        spell_halion_combustion_consumption(char const* scriptName, uint32 spell) : SpellScriptLoader(scriptName), _spellID(spell) { }

        class spell_halion_combustion_consumption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_combustion_consumption_AuraScript);

        public:
            spell_halion_combustion_consumption_AuraScript(uint32 spellID) : AuraScript(), _markSpell(spellID) { }

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(_markSpell))
>>>>>>> TC/master
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
<<<<<<< HEAD
                if (GetTarget()->HasAura(SPELL_MARK_OF_CONSUMPTION))
                    GetTarget()->RemoveAurasDueToSpell(SPELL_MARK_OF_CONSUMPTION, 0, 0, AURA_REMOVE_BY_EXPIRE);
=======
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
                    return;

                if (GetTarget()->HasAura(_markSpell))
                    GetTarget()->RemoveAurasDueToSpell(_markSpell, 0, 0, AURA_REMOVE_BY_EXPIRE);
>>>>>>> TC/master
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
<<<<<<< HEAD
                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_CONSUMPTION, true);
=======
                GetTarget()->CastSpell(GetTarget(), _markSpell, true);
>>>>>>> TC/master
            }

            void AddMarkStack(AuraEffect const* /*aurEff*/)
            {
<<<<<<< HEAD
                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_CONSUMPTION, true);
=======
                GetTarget()->CastSpell(GetTarget(), _markSpell, true);
>>>>>>> TC/master
            }

            void Register()
            {
<<<<<<< HEAD
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halion_soul_consumption_AuraScript::AddMarkStack, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectApply += AuraEffectApplyFn(spell_halion_soul_consumption_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_soul_consumption_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
=======
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halion_combustion_consumption_AuraScript::AddMarkStack, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectApply += AuraEffectApplyFn(spell_halion_combustion_consumption_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_combustion_consumption_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }

            uint32 _markSpell;
>>>>>>> TC/master
        };

        AuraScript* GetAuraScript() const
        {
<<<<<<< HEAD
            return new spell_halion_soul_consumption_AuraScript();
        }
};

class spell_halion_mark_of_combustion : public SpellScriptLoader
{
    public:
        spell_halion_mark_of_combustion() : SpellScriptLoader("spell_halion_mark_of_combustion") { }

        class spell_halion_mark_of_combustion_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_mark_of_combustion_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_FIERY_COMBUSTION_SUMMON))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_FIERY_COMBUSTION_EXPLOSION))
=======
            return new spell_halion_combustion_consumption_AuraScript(_spellID);
        }

    private:
        uint32 _spellID;
};

class spell_halion_marks : public SpellScriptLoader
{
    public:
        spell_halion_marks(char const* scriptName, uint32 summonSpell, uint32 removeSpell) : SpellScriptLoader(scriptName),
            _summonSpell(summonSpell), _removeSpell(removeSpell) { }

        class spell_halion_marks_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_marks_AuraScript);

        public:
            spell_halion_marks_AuraScript(uint32 summonSpell, uint32 removeSpell) : AuraScript(),
                _summonSpellId(summonSpell), _removeSpellId(removeSpell) { }

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(_summonSpellId))
>>>>>>> TC/master
                    return false;
                return true;
            }

<<<<<<< HEAD
            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                InstanceScript* instance = target->GetInstanceScript();
                if (!instance)
                    return;

                uint8 stacks = aurEff->GetBase()->GetStackAmount();

                // Keep track of stacks when dispelling, there's only one effect in the spell.
                CustomSpellValues values;
                values.AddSpellMod(SPELLVALUE_BASE_POINT1, stacks);

                // TEMP FIX : target->CastCustomSpell(SPELL_FIERY_COMBUSTION_SUMMON, values, target, true, NULL, NULL, GetCasterGUID());
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_mark_of_combustion_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_mark_of_combustion_AuraScript();
        }
};

class spell_halion_mark_of_consumption : public SpellScriptLoader
{
    public:
        spell_halion_mark_of_consumption() : SpellScriptLoader("spell_halion_mark_of_consumption") { }

        class spell_halion_mark_of_consumption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_mark_of_consumption_AuraScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SOUL_CONSUMPTION_SUMMON))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SOUL_CONSUMPTION_EXPLOSION))
                    return false;
                return true;
=======
            /// We were purged. Force removed stacks to zero and trigger the appropriated remove handler.
            void BeforeDispel(DispelInfo* dispelData)
            {
                // Prevent any stack from being removed at this point.
                dispelData->SetRemovedCharges(0);

                if (Unit* dispelledUnit = GetUnitOwner())
                    if (dispelledUnit->HasAura(_removeSpellId))
                        dispelledUnit->RemoveAurasDueToSpell(_removeSpellId, 0, 0, AURA_REMOVE_BY_EXPIRE);
>>>>>>> TC/master
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
<<<<<<< HEAD
                Unit* target = GetTarget();

                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                InstanceScript* instance = target->GetInstanceScript();
                if (!instance)
                    return;

                uint8 stacks = aurEff->GetBase()->GetStackAmount();

                // Keep track of stacks when dispelling, there's only one effect in the spell.
                CustomSpellValues values;
                values.AddSpellMod(SPELLVALUE_BASE_POINT1, stacks);

                // TEMP FIX : target->CastCustomSpell(SPELL_SOUL_CONSUMPTION_SUMMON, values, target, true, NULL, NULL, GetCasterGUID());
=======
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                // Stacks marker
                GetTarget()->CastCustomSpell(_summonSpellId, SPELLVALUE_BASE_POINT1, aurEff->GetBase()->GetStackAmount(), GetTarget(), TRIGGERED_FULL_MASK, NULL, NULL, GetCasterGUID());
>>>>>>> TC/master
            }

            void Register()
            {
<<<<<<< HEAD
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_mark_of_consumption_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
=======
                OnDispel += AuraDispelFn(spell_halion_marks_AuraScript::BeforeDispel);
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_marks_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

            uint32 _summonSpellId;
            uint32 _removeSpellId;
>>>>>>> TC/master
        };

        AuraScript* GetAuraScript() const
        {
<<<<<<< HEAD
            return new spell_halion_mark_of_consumption_AuraScript();
        }
};

class spell_halion_combustion_consumption_summon : public SpellScriptLoader
{
    public:
        spell_halion_combustion_consumption_summon() : SpellScriptLoader("spell_halion_combustion_consumption_summon") { }

        class spell_halion_combustion_consumption_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_combustion_consumption_summon_SpellScript);
=======
            return new spell_halion_marks_AuraScript(_summonSpell, _removeSpell);
        }

    private:
        uint32 _summonSpell;
        uint32 _removeSpell;
};

class spell_halion_damage_aoe_summon : public SpellScriptLoader
{
    public:
        spell_halion_damage_aoe_summon() : SpellScriptLoader("spell_halion_damage_aoe_summon") { }

        class spell_halion_damage_aoe_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_damage_aoe_summon_SpellScript);
>>>>>>> TC/master

            void HandleSummon(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Unit* caster = GetCaster();
                uint32 entry = uint32(GetSpellInfo()->Effects[effIndex].MiscValue);
                SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetSpellInfo()->Effects[effIndex].MiscValueB));
                uint32 duration = uint32(GetSpellInfo()->GetDuration());

<<<<<<< HEAD
                InstanceScript* instance = caster->GetInstanceScript();
                if (!instance)
                    return;

=======
>>>>>>> TC/master
                Position pos;
                caster->GetPosition(&pos);
                if (Creature* summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, caster, GetSpellInfo()->Id))
                    if (summon->IsAIEnabled)
                        summon->AI()->SetData(DATA_STACKS_DISPELLED, GetSpellValue()->EffectBasePoints[EFFECT_1]);
            }

            void Register()
            {
<<<<<<< HEAD
                OnEffectHit += SpellEffectFn(spell_halion_combustion_consumption_summon_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
=======
                OnEffectHit += SpellEffectFn(spell_halion_damage_aoe_summon_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
>>>>>>> TC/master
            }
        };

        SpellScript* GetSpellScript() const
        {
<<<<<<< HEAD
            return new spell_halion_combustion_consumption_summon_SpellScript();
        }
};

class spell_halion_leave_twilight_realm : public SpellScriptLoader
{
    public:
        spell_halion_leave_twilight_realm() : SpellScriptLoader("spell_halion_leave_twilight_realm") { }

        class spell_halion_leave_twilight_realm_AuraScript: public AuraScript
        {
            PrepareAuraScript(spell_halion_leave_twilight_realm_AuraScript);

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*handle*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_TWILIGHT_REALM);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_leave_twilight_realm_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        class spell_halion_leave_twilight_realm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_leave_twilight_realm_SpellScript);

            void HandleBeforeHit()
            {
                if (Player* player = GetHitPlayer())
                    player->RemoveAurasDueToSpell(SPELL_SOUL_CONSUMPTION, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!targets.empty())
                    targets.remove_if(Trinity::UnitAuraCheck(false, SPELL_TWILIGHT_REALM));
            }

            void Register()
            {
                BeforeHit += SpellHitFn(spell_halion_leave_twilight_realm_SpellScript::HandleBeforeHit);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_halion_leave_twilight_realm_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_TARGET_ANY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_leave_twilight_realm_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_leave_twilight_realm_AuraScript();
        }
};

class spell_halion_enter_twilight_realm : public SpellScriptLoader
{
    public:
        spell_halion_enter_twilight_realm() : SpellScriptLoader("spell_halion_enter_twilight_realm") { }

        class spell_halion_enter_twilight_realm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_enter_twilight_realm_SpellScript);

            void HandleBeforeHit()
            {
                if (Player* player = GetHitPlayer())
                    player->RemoveAurasDueToSpell(SPELL_FIERY_COMBUSTION, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);
=======
            return new spell_halion_damage_aoe_summon_SpellScript();
        }
};

class spell_halion_twilight_realm_handlers : public SpellScriptLoader
{
    public:
        spell_halion_twilight_realm_handlers(const char* scriptName, uint32 beforeHitSpell, bool isApplyHandler) : SpellScriptLoader(scriptName),
            _beforeHitSpell(beforeHitSpell), _isApplyHandler(isApplyHandler)
        { }

        class spell_halion_twilight_realm_handlers_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_twilight_realm_handlers_AuraScript);

        public:
            spell_halion_twilight_realm_handlers_AuraScript(uint32 beforeHitSpell, bool isApplyHandler) : AuraScript(),
                _isApply(isApplyHandler), _beforeHitSpellId(beforeHitSpell)
            { }

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(_beforeHitSpellId))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*handle*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_TWILIGHT_REALM);
                if (InstanceScript* instance = GetTarget()->GetInstanceScript())
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_UNK7);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*handle*/)
            {
                Unit* target = GetTarget();
                if (!target)
                    return;

                target->RemoveAurasDueToSpell(_beforeHitSpellId, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);
                if (InstanceScript* instance = target->GetInstanceScript())
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_UNK7);
>>>>>>> TC/master
            }

            void Register()
            {
<<<<<<< HEAD
                BeforeHit += SpellHitFn(spell_halion_enter_twilight_realm_SpellScript::HandleBeforeHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_enter_twilight_realm_SpellScript();
        }
};

class spell_halion_twilight_phasing : public SpellScriptLoader
{
    public:
        spell_halion_twilight_phasing() : SpellScriptLoader("spell_halion_twilight_phasing") { }

        class spell_halion_twilight_phasing_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_twilight_phasing_SpellScript);

            void Phase()
            {
                Unit* caster = GetCaster();
                caster->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                caster->CastSpell(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), SPELL_SUMMON_TWILIGHT_PORTAL, true);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_halion_twilight_phasing_SpellScript::Phase);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_twilight_phasing_SpellScript();
        }
=======
                if (!_isApply)
                {
                    AfterEffectApply += AuraEffectApplyFn(spell_halion_twilight_realm_handlers_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                    AfterEffectRemove += AuraEffectRemoveFn(spell_halion_twilight_realm_handlers_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                }
                else
                    AfterEffectApply += AuraEffectApplyFn(spell_halion_twilight_realm_handlers_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
            }

            bool _isApply;
            uint32 _beforeHitSpellId;
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_twilight_realm_handlers_AuraScript(_beforeHitSpell, _isApplyHandler);
        }

    private:
        uint32 _beforeHitSpell;
        bool _isApplyHandler;
>>>>>>> TC/master
};

class spell_halion_clear_debuffs : public SpellScriptLoader
{
    public:
        spell_halion_clear_debuffs() : SpellScriptLoader("spell_halion_clear_debuffs") { }

        class spell_halion_clear_debuffs_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_clear_debuffs_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CLEAR_DEBUFFS))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_TWILIGHT_REALM))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
<<<<<<< HEAD
                if (GetHitUnit()->HasAura(GetSpellInfo()->Effects[effIndex].BasePoints))
                    GetHitUnit()->RemoveAurasDueToSpell(GetSpellInfo()->Effects[effIndex].BasePoints);
=======
                if (GetHitUnit()->HasAura(GetSpellInfo()->Effects[effIndex].CalcValue()))
                    GetHitUnit()->RemoveAurasDueToSpell(GetSpellInfo()->Effects[effIndex].CalcValue());
>>>>>>> TC/master
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_halion_clear_debuffs_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_clear_debuffs_SpellScript();
        }
};

class TwilightCutterSelector
{
    public:
        TwilightCutterSelector(Unit* caster, Unit* cutterCaster) : _caster(caster), _cutterCaster(cutterCaster) {}

<<<<<<< HEAD
        bool operator()(WorldObject* unit) const
=======
        bool operator()(WorldObject* unit)
>>>>>>> TC/master
        {
            return !unit->IsInBetween(_caster, _cutterCaster, 4.0f);
        }

    private:
        Unit* _caster;
        Unit* _cutterCaster;
};

class spell_halion_twilight_cutter : public SpellScriptLoader
{
    public:
        spell_halion_twilight_cutter() : SpellScriptLoader("spell_halion_twilight_cutter") { }

        class spell_halion_twilight_cutter_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_twilight_cutter_SpellScript);

<<<<<<< HEAD
            void RemoveNotBetween(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
=======
            void RemoveNotBetween(std::list<WorldObject*>& unitList)
            {
                if (unitList.empty())
>>>>>>> TC/master
                    return;

                Unit* caster = GetCaster();
                if (Aura* cutter = caster->GetAura(SPELL_TWILIGHT_CUTTER))
                {
                    if (Unit* cutterCaster = cutter->GetCaster())
                    {
<<<<<<< HEAD
                        targets.remove_if(TwilightCutterSelector(caster, cutterCaster));
=======
                        unitList.remove_if(TwilightCutterSelector(caster, cutterCaster));
>>>>>>> TC/master
                        return;
                    }
                }

                // In case cutter caster werent found for some reason
<<<<<<< HEAD
                targets.clear();
=======
                unitList.clear();
>>>>>>> TC/master
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_halion_twilight_cutter_SpellScript::RemoveNotBetween, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_twilight_cutter_SpellScript();
        }
};

<<<<<<< HEAD
=======
class spell_halion_twilight_phasing : public SpellScriptLoader
{
    public:
        spell_halion_twilight_phasing() : SpellScriptLoader("spell_halion_twilight_phasing") { }

        class spell_halion_twilight_phasing_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_twilight_phasing_SpellScript);

            void Phase()
            {
                Unit* caster = GetCaster();
                caster->CastSpell(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), SPELL_SUMMON_TWILIGHT_PORTAL, true);
                caster->GetMap()->SummonCreature(NPC_TWILIGHT_HALION, HalionSpawnPos);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_halion_twilight_phasing_SpellScript::Phase);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_twilight_phasing_SpellScript();
        }
};

class spell_halion_summon_exit_portals : public SpellScriptLoader
{
    public:
        spell_halion_summon_exit_portals() : SpellScriptLoader("spell_halion_summon_exit_portals") { }

        class spell_halion_summon_exit_portals_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_summon_exit_portals_SpellScript);

            void OnSummon(SpellEffIndex effIndex)
            {
                WorldLocation summonPos = *GetExplTargetDest();
                Position offset = {0.0f, 20.0f, 0.0f, 0.0f};
                if (effIndex == EFFECT_1)
                    offset.m_positionY = -20.0f;

                summonPos.RelocateOffset(offset);

                SetExplTargetDest(summonPos);
                GetHitDest()->RelocateOffset(offset);
            }

            void Register()
            {
                OnEffectLaunch += SpellEffectFn(spell_halion_summon_exit_portals_SpellScript::OnSummon, EFFECT_0, SPELL_EFFECT_SUMMON_OBJECT_WILD);
                OnEffectLaunch += SpellEffectFn(spell_halion_summon_exit_portals_SpellScript::OnSummon, EFFECT_1, SPELL_EFFECT_SUMMON_OBJECT_WILD);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_summon_exit_portals_SpellScript();
        }
};

>>>>>>> TC/master
void AddSC_boss_halion()
{
    new boss_halion();
    new boss_twilight_halion();
<<<<<<< HEAD
=======
    
>>>>>>> TC/master
    new npc_halion_controller();
    new npc_meteor_strike_initial();
    new npc_meteor_strike();
    new npc_combustion_consumption();
    new npc_orb_carrier();
    new npc_living_inferno();
    new npc_living_ember();
<<<<<<< HEAD
    new spell_halion_meteor_strike_marker();
    new spell_halion_combustion_consumption_summon();
    new spell_halion_mark_of_combustion();
    new spell_halion_mark_of_consumption();
    new spell_halion_fiery_combustion();
    new spell_halion_soul_consumption();
    new spell_halion_leave_twilight_realm();
    new spell_halion_enter_twilight_realm();
=======

    new go_twilight_portal();

    new spell_halion_meteor_strike_marker();
    new spell_halion_combustion_consumption("spell_halion_soul_consumption", SPELL_MARK_OF_CONSUMPTION);
    new spell_halion_combustion_consumption("spell_halion_fiery_combustion", SPELL_MARK_OF_COMBUSTION);
    new spell_halion_marks("spell_halion_mark_of_combustion", SPELL_FIERY_COMBUSTION_SUMMON, SPELL_FIERY_COMBUSTION);
    new spell_halion_marks("spell_halion_mark_of_consumption", SPELL_SOUL_CONSUMPTION_SUMMON, SPELL_SOUL_CONSUMPTION);
    new spell_halion_damage_aoe_summon();
    new spell_halion_twilight_realm_handlers("spell_halion_leave_twilight_realm", SPELL_SOUL_CONSUMPTION, false);
    new spell_halion_twilight_realm_handlers("spell_halion_enter_twilight_realm", SPELL_FIERY_COMBUSTION, true);
    new spell_halion_summon_exit_portals();
>>>>>>> TC/master
    new spell_halion_twilight_phasing();
    new spell_halion_twilight_cutter();
    new spell_halion_clear_debuffs();
}
