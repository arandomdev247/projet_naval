#include "includes.h"

t_map ia_inoffensive(t_map maps) //IA évitant totalement de toucher les navires ennemis
{
    t_sp pos;
    bool ok = false;
    while (ok != true)
    {
        pos.line = ranged_rand(10);
        pos.column = ranged_rand(10);
        if (maps.player_map[pos.column][pos.line] == '.' ||
            maps.player_map[pos.column][pos.line] == 'O' ||
            maps.player_map[pos.column][pos.line] == 'T')
                ok = true;
    }
    if (maps.player_map[pos.column][pos.line] != '.' &&
        maps.player_map[pos.column][pos.line] != 'O')
        maps.player_map[pos.column][pos.line] = 'T';
    if (maps.player_map[pos.column][pos.line] == '.')
        maps.player_map[pos.column][pos.line] = 'O';
    return (maps);
}

t_map ia_meh(t_map maps) // IA qui tire de manière totalement aléatoire
{
    t_sp pos;
    bool ok = false;
    while (ok != true)
    {
        pos.line = ranged_rand(10);
        pos.column = ranged_rand(10);
        if (!(maps.player_map[pos.column][pos.line] == 'X' ||
            maps.player_map[pos.column][pos.line] == 'O' ||
            maps.player_map[pos.column][pos.line] == 'T'))
                ok = true;
    }
    if (maps.player_map[pos.column][pos.line] != '.' &&
        maps.player_map[pos.column][pos.line] != 'O' &&
        maps.player_map[pos.column][pos.line] != 'X')
        maps.player_map[pos.column][pos.line] = 'T';
    if (maps.player_map[pos.column][pos.line] == '.')
        maps.player_map[pos.column][pos.line] = 'O';
    return (maps);
}

t_map ia_impossibru(t_map maps) //IA demandant un perfect pour gagner
{
    t_sp pos;
    bool ok = false;
    while (ok != true)
    {
        pos.line = ranged_rand(10);
        pos.column = ranged_rand(10);
        if (maps.player_map[pos.column][pos.line] != '.' ||
            maps.player_map[pos.column][pos.line] != 'O' ||
            maps.player_map[pos.column][pos.line] != 'X' ||
            maps.player_map[pos.column][pos.line] != 'T')
                ok = true;
    }
    if (maps.player_map[pos.column][pos.line] != '.' &&
        maps.player_map[pos.column][pos.line] != 'O' &&
        maps.player_map[pos.column][pos.line] != 'X')
        maps.player_map[pos.column][pos.line] = 'T';
    if (maps.player_map[pos.column][pos.line] == '.')
        maps.player_map[pos.column][pos.line] = 'O';
    return (maps);
}

t_map ia_manager(t_map maps, int difficulty) //Gestionnaire d'IA
{
    if (difficulty == 1)
        maps = ia_inoffensive(maps);
    else if (difficulty == 2)
        maps = ia_meh(maps);
    else
        maps = ia_impossibru(maps);
    return (maps);
}
