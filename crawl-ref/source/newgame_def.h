#ifndef NEWGAME_DEF_H
#define NEWGAME_DEF_H

#include "itemprop-enum.h"

enum startup_wand_type
{
    SWT_ENSLAVEMENT,
    SWT_CONFUSION,
    SWT_MAGIC_DARTS,
    SWT_FROST,
    SWT_FLAME,
    SWT_STRIKING, // actually a rod
    NUM_STARTUP_WANDS,

    SWT_NO_SELECTION = NUM_STARTUP_WANDS,
    SWT_RANDOM,
};

// Either a character definition, with real species, job, and
// weapon, book, wand as appropriate.
// Or a character choice, with possibly random/viable entries.
struct newgame_def
{
    std::string name;
    game_type type;
    std::string filename;

    // map name for sprint (or others in the future)
    // XXX: "random" means a random eligible map
    std::string map;

    std::string arena_teams;

    species_type species;
    job_type job;

    weapon_type weapon;
    startup_wand_type wand;

    // Only relevant for character choice, where the entire
    // character was randomly picked in one step.
    // If this is true, the species field encodes whether
    // the choice was for a viable character or not.
    bool fully_random;

    newgame_def();
    void clear_character();
};

#endif
