#include "includes.h"
#include <stdlib.h>
#include <time.h>
#include <process.h>

int ranged_rand(int range_max) //Rand'o'machine
{
    range_max++;
    int num;
    srand(_getpid() + (time(NULL) * clock()));
    Sleep(1);
    num = rand() % range_max;
    return (num);
}

t_sp pos_generator(t_sp p, int l_ship) //Générateur de position
{
    int orientation;
    orientation = ranged_rand(1);
    if (orientation == 0)
        p.orientation = HORIZONTAL;
    if (orientation == 1)
        p.orientation = VERTICAL;
    if (orientation == VERTICAL)
    {
        p.column = ranged_rand(9);
        p.line = ranged_rand(9 - l_ship);
    }
    if (orientation == HORIZONTAL)
    {
        p.column = ranged_rand(9 - l_ship);
        p.line = ranged_rand(9);
    }
    return(p);
}

int rand_ship_tester(t_sp p, int l_ship) //Teste si le vaisseau ne sort pas de la map
{
    bool ok = true;
    if (p.orientation == VERTICAL)
        if (l_ship + p.line > 10)
            ok = false;
    if (p.orientation == HORIZONTAL)
        if (l_ship + p.column > 10)
            ok = false;
    if (ok == false)
        return(-1);
    return (0);
}

int rand_map_tester(t_sp p, t_map maps, int type_ship) //Test si il n'y a pas de navire déjà présent (sans affichage)
{
    int i;
    int lenght;
    lenght = get_lenght(type_ship);
    if (p.orientation == VERTICAL)
        for (i = 0; i < lenght; i++)
            if (maps.player_map[p.column][p.line + i] != '.')
                return (-1);
    if (p.orientation == HORIZONTAL)
        for (i = 0; i < lenght; i++)
            if (maps.player_map[p.column + i][p.line] != '.')
                return (-1);
    return (0);
}

t_map put_random_ship(t_sp p, t_map maps, int type_ship) //Met en place le navire (sans affichage)
{
    int i;
    int lenght;
    char letter;
    letter = get_letter(type_ship);
    lenght = get_lenght(type_ship);
    if (p.orientation == VERTICAL)
    {
        for (i = 0; i < lenght; i++)
            maps.player_map[p.column][p.line + i] = letter;
    }
    if (p.orientation == HORIZONTAL)
    {
        for (i = 0; i < lenght; i++)
            maps.player_map[p.column + i][p.line] = letter;
    }
    return (maps);
}


t_map map_generator(t_map maps) //Génère la map
{
    t_sp p;
    bool ok = false;
    int type_ship = 5;
    while(type_ship > 0)
    {
        while (ok != true)
        {
            p.column = 0;
            p.line = 0;
            p.orientation = O_ERROR;
                p = pos_generator(p, get_lenght(type_ship));
            if (rand_map_tester(p, maps, type_ship) != -1 &&
                rand_ship_tester(p, get_lenght(type_ship)) != -1)
            {
                if (type_ship == 5)
                    maps.p_ships.carrier = p;
                if (type_ship == 4)
                    maps.p_ships.battleship = p;
                if (type_ship == 3)
                    maps.p_ships.cruiser = p;
                if (type_ship == 2)
                    maps.p_ships.submarine = p;
                if (type_ship == 1)
                    maps.p_ships.destroyer = p;
                maps = put_random_ship(p, maps, type_ship);
                ok = true;
            }
        }
        ok = false;
        type_ship--;
    }
    return(maps);
}

t_map generate_maps(t_map maps, bool choice) //Transfère la map générée sur la princiale
{
    t_map m_temp;
    int x;
    int y;

    m_temp = map_init(m_temp);
    m_temp = map_generator(m_temp);
    if (choice == true) //choice = 1 -> Genere la map ennemie
    {
        for (y = 0; y < 10; y++)
            for (x = 0; x < 10; x++)
                maps.e_map[y][x] = m_temp.player_map[y][x];
        maps.e_ships = m_temp.p_ships;
    }
    if (choice == false) //choice = 0 -> Genere la map joueur
    {
        for (y = 0; y < 10; y++)
            for (x = 0; x < 10; x++)
                maps.player_map[y][x] = m_temp.player_map[y][x];
        maps.p_ships = m_temp.p_ships;
    }
   // aff_map(maps);
    return(maps);
}
