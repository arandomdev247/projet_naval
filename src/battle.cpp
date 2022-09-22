#include "includes.h"

int number_of_o(t_map maps)
{
    int x,y, counter;

    counter = 0;
    for (x = 0; x < 10; x++)
        for (y = 0; y < 10; y++)
            if (maps.e_map[x][y] == 'O')
                counter++;
    return (counter);
}

t_map attacks(t_map maps, bool player, int difficulty) //Lance une attaque contre l'adversaire
{                                   //1 = joueur || 0 = ennemi
    bool ok = false;
    t_sp pos;
    if (player == true) // Tour du joueur
    {
        while (ok != true)
        {
            cout << "Coordonnées pour détruire la cible : ";
            pos = input(0);
            if (pos.column == -1 || pos.line == -1)
            {
                cerr << "Veuillez écrire correctement les coordonnées !" <<endl;
                system("PAUSE");
                system("CLS");
                aff_maps(maps);
            }
            else
                ok = true;
        }
        if (maps.e_map[pos.column][pos.line] != '.' &&
            maps.e_map[pos.column][pos.line] != 'O')
        {
            maps.e_map[pos.column][pos.line] = 'T';
            cout << "Touché !" << endl;
            Sleep(500);
        }
        else if (maps.e_map[pos.column][pos.line] == '.')
        {
            maps.e_map[pos.column][pos.line] = 'O';
            cout << "Raté !" << endl;
            Sleep(500);
        }
        else if (maps.e_map[pos.column][pos.line] == 'O')
        {
            cout << "Raté !" << endl;
            Sleep(500);
        }
        else;
    }
    else //Tour de l'ennemi
    {
        maps = ia_manager(maps, difficulty);
        while (ok != true)
        {
            pos.line = ranged_rand(10);
            pos.column = ranged_rand(10);
            if (!(maps.player_map[pos.column][pos.line] == 'X' ||
                maps.player_map[pos.column][pos.line] == 'O' ||
                maps.player_map[pos.column][pos.line] == 'T'))
                    ok = true;
        }
        if (maps.player_map[pos.column][pos.line] != '.')
            maps.player_map[pos.column][pos.line] = 'T';
        if (maps.player_map[pos.column][pos.line] == '.')
            maps.player_map[pos.column][pos.line] = 'O';
    }
    return (maps);
}
