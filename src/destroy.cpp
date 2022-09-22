#include "includes.h"

int test_map_whole(t_map maps) //Teste si un des participant a été vaincu
{
    int x, y, test;

    test = 0;
    for (y = 0; y < 10; y ++)
        for (x = 0 ; x < 10; x++)
            if (maps.player_map[y][x] == 'X' || maps.player_map[y][x] == '.' || maps.player_map[y][x] == 'O')
                test++;
    if (test == 100)
        return (2);
    test = 0;
    for (y = 0; y < 10; y ++)
        for (x = 0 ; x < 10; x++)
            if (maps.e_map[y][x] == 'X' || maps.e_map[y][x] == '.' || maps.e_map[y][x] == 'O')
                test++;
    if (test == 100)
        return (1);
    return (0);

}

int test_p_ship(t_map maps, int type_ship) //Teste la map joueur
{
    int lenght, i, x;

    x = 0;
    i = 0;
    lenght = get_lenght(type_ship);
    if (type_ship == 5) // Teste le porte avion
    {
        if (maps.p_ships.carrier.orientation == VERTICAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.player_map[maps.p_ships.carrier.column][maps.p_ships.carrier.line + i] == 'T')
                    x++;
            if (x == lenght)
                return(25);
        }
        if (maps.p_ships.carrier.orientation == HORIZONTAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.player_map[maps.p_ships.carrier.column + i][maps.p_ships.carrier.line] == 'T')
                    x++;
            if (x == lenght)
                return(25);
        }
    }
    if (type_ship == 4) //Teste le cuirassé
    {
            if (maps.p_ships.battleship.orientation == VERTICAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.player_map[maps.p_ships.battleship.column][maps.p_ships.battleship.line + i] == 'T')
                    x++;
            if (x == lenght)
                return(24);
        }
        if (maps.p_ships.battleship.orientation == HORIZONTAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.player_map[maps.p_ships.battleship.column + i][maps.p_ships.battleship.line] == 'T')
                    x++;
            if (x == lenght)
                return(24);

        }
    }
    if (type_ship == 3) //Teste le croiseur
    {
        if (maps.p_ships.cruiser.orientation == VERTICAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.player_map[maps.p_ships.cruiser.column][maps.p_ships.cruiser.line + i] == 'T')
                    x++;
            if (x == lenght)
                return(23);
        }
        if (maps.p_ships.cruiser.orientation == HORIZONTAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.player_map[maps.p_ships.cruiser.column + i][maps.p_ships.cruiser.line] == 'T')
                    x++;
            if (x == lenght)
                return(23);
        }
    }
    if (type_ship == 2) //Teste le sous-marin
    {
            if (maps.p_ships.submarine.orientation == VERTICAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.player_map[maps.p_ships.submarine.column][maps.p_ships.submarine.line + i] == 'T')
                    x++;
            if (x == lenght)
                return(22);
        }
        if (maps.p_ships.submarine.orientation == HORIZONTAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.player_map[maps.p_ships.submarine.column + i][maps.p_ships.submarine.line] == 'T')
                    x++;
            if (x == lenght)
                return(22);
        }
    }
    if (type_ship == 1) // Teste le destroyer
    {
        if (maps.p_ships.destroyer.orientation == VERTICAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.player_map[maps.p_ships.destroyer.column][maps.p_ships.destroyer.line + i] == 'T')
                    x++;
            if (x == lenght)
                return(21);
        }
        if (maps.p_ships.destroyer.orientation == HORIZONTAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.player_map[maps.p_ships.destroyer.column + i][maps.p_ships.destroyer.line] == 'T')
                    x++;
            if (x == lenght)
                return(21);
        }
    }
    return (0);
}

int test_e_ship(t_map maps, int type_ship) //Teste la map ennemie
{
    int lenght, i, x;

    x = 0;
    i = 0;
    lenght = get_lenght(type_ship);
    if (type_ship == 5) // Teste le porte avion
    {
        if (maps.e_ships.carrier.orientation == VERTICAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.e_map[maps.e_ships.carrier.column][maps.e_ships.carrier.line + i] == 'T')
                    x++;
            if (x == lenght)
                return(15);
        }
        if (maps.e_ships.carrier.orientation == HORIZONTAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.e_map[maps.e_ships.carrier.column + i][maps.e_ships.carrier.line] == 'T')
                    x++;
            if (x == lenght)
                return(15);
        }
    }
    if (type_ship == 4) //Teste le cuirassé
    {
            if (maps.e_ships.battleship.orientation == VERTICAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.e_map[maps.e_ships.battleship.column][maps.e_ships.battleship.line + i] == 'T')
                    x++;
            if (x == lenght)
                return(14);
        }
        if (maps.e_ships.battleship.orientation == HORIZONTAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.e_map[maps.e_ships.battleship.column + i][maps.e_ships.battleship.line] == 'T')
                    x++;
            if (x == lenght)
                return(14);
        }
    }
    if (type_ship == 3) //Teste le croiseur
    {
        if (maps.e_ships.cruiser.orientation == VERTICAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.e_map[maps.e_ships.cruiser.column][maps.e_ships.cruiser.line + i] == 'T')
                    x++;
            if (x == lenght)
                return(13);
        }
        if (maps.e_ships.cruiser.orientation == HORIZONTAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.e_map[maps.e_ships.cruiser.column + i][maps.e_ships.cruiser.line] == 'T')
                    x++;
            if (x == lenght)
                return(13);
        }
    }
    if (type_ship == 2) //Teste le sous-marin
    {
            if (maps.e_ships.submarine.orientation == VERTICAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.e_map[maps.e_ships.submarine.column][maps.e_ships.submarine.line + i] == 'T')
                    x++;
            if (x == lenght)
                return(12);
        }
        if (maps.e_ships.submarine.orientation == HORIZONTAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.e_map[maps.e_ships.submarine.column + i][maps.e_ships.submarine.line] == 'T')
                    x++;
            if (x == lenght)
                return(12);
        }
    }
    if (type_ship == 1) // Teste le destroyer
    {
        if (maps.e_ships.destroyer.orientation == VERTICAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.e_map[maps.e_ships.destroyer.column][maps.e_ships.destroyer.line + i] == 'T')
                    x++;
            if (x == lenght)
                return(11);
        }
        if (maps.e_ships.destroyer.orientation == HORIZONTAL)
        {
            for (i = 0; i < lenght; i++)
                if (maps.e_map[maps.e_ships.destroyer.column + i][maps.e_ships.destroyer.line] == 'T')
                    x++;
            if (x == lenght)
                return(11);
        }
    }
    return (0);
}

t_map destroy_p_ship(t_map maps, int type_ship) //Supprime un navire sur la map joueur
{
    int lenght, i;

    type_ship = type_ship - 20;
    lenght = get_lenght(type_ship);
    if (type_ship == 5) // Supprime le porte avion
    {
        if (maps.p_ships.carrier.orientation == VERTICAL)
            for (i = 0; i < lenght; i++)
                maps.player_map[maps.p_ships.carrier.column][maps.p_ships.carrier.line + i] = 'X';
        if (maps.p_ships.carrier.orientation == HORIZONTAL)
            for (i = 0; i < lenght; i++)
                maps.player_map[maps.p_ships.carrier.column + i][maps.p_ships.carrier.line] = 'X';
    }
    if (type_ship == 4) //Supprime le cuirassé
    {
        if (maps.p_ships.battleship.orientation == VERTICAL)
            for (i = 0; i < lenght; i++)
                maps.player_map[maps.p_ships.battleship.column][maps.p_ships.battleship.line + i] = 'X';
        if (maps.p_ships.battleship.orientation == HORIZONTAL)
            for (i = 0; i < lenght; i++)
                maps.player_map[maps.p_ships.battleship.column + i][maps.p_ships.battleship.line] = 'X';
    }
    if (type_ship == 3) //Supprime le croiseur
    {
        if (maps.p_ships.cruiser.orientation == VERTICAL)
            for (i = 0; i < lenght; i++)
                maps.player_map[maps.p_ships.cruiser.column][maps.p_ships.cruiser.line + i] = 'X';
        if (maps.p_ships.cruiser.orientation == HORIZONTAL)
            for (i = 0; i < lenght; i++)
                maps.player_map[maps.p_ships.cruiser.column + i][maps.p_ships.cruiser.line] = 'X';
    }
    if (type_ship == 2) //Supprime le sous-marin
    {
        if (maps.p_ships.submarine.orientation == VERTICAL)
            for (i = 0; i < lenght; i++)
                maps.player_map[maps.p_ships.submarine.column][maps.p_ships.submarine.line + i] = 'X';
        if (maps.p_ships.submarine.orientation == HORIZONTAL)
            for (i = 0; i < lenght; i++)
                maps.player_map[maps.p_ships.submarine.column + i][maps.p_ships.submarine.line] = 'X';
    }
    if (type_ship == 1) // Supprime le destroyer
    {
        if (maps.p_ships.destroyer.orientation == VERTICAL)
            for (i = 0; i < lenght; i++)
                maps.player_map[maps.p_ships.destroyer.column][maps.p_ships.destroyer.line + i] = 'X';
        if (maps.p_ships.destroyer.orientation == HORIZONTAL)
            for (i = 0; i < lenght; i++)
                maps.player_map[maps.p_ships.destroyer.column + i][maps.p_ships.destroyer.line] = 'X';
    }
    return (maps);
}

t_map destroy_e_ship(t_map maps, int type_ship) //Supprime le navire sur la map ennemie
{
    int lenght, i;

    type_ship = type_ship - 10;
    lenght = get_lenght(type_ship);
    if (type_ship == 5) // Supprime le porte avion
    {
        if (maps.e_ships.carrier.orientation == VERTICAL)
            for (i = 0; i < lenght; i++)
                maps.e_map[maps.e_ships.carrier.column][maps.e_ships.carrier.line + i] = 'X';
        if (maps.e_ships.carrier.orientation == HORIZONTAL)
            for (i = 0; i < lenght; i++)
                maps.e_map[maps.e_ships.carrier.column + i][maps.e_ships.carrier.line] = 'X';
    }
    if (type_ship == 4) //Supprime le cuirassé
    {
        if (maps.e_ships.battleship.orientation == VERTICAL)
            for (i = 0; i < lenght; i++)
                maps.e_map[maps.e_ships.battleship.column][maps.e_ships.battleship.line + i] = 'X';
        if (maps.e_ships.battleship.orientation == HORIZONTAL)
            for (i = 0; i < lenght; i++)
                maps.e_map[maps.e_ships.battleship.column + i][maps.e_ships.battleship.line] = 'X';
    }
    if (type_ship == 3) //Supprime le croiseur
    {
        if (maps.e_ships.cruiser.orientation == VERTICAL)
            for (i = 0; i < lenght; i++)
                maps.e_map[maps.e_ships.cruiser.column][maps.e_ships.cruiser.line + i] = 'X';
        if (maps.e_ships.cruiser.orientation == HORIZONTAL)
            for (i = 0; i < lenght; i++)
                maps.e_map[maps.e_ships.cruiser.column + i][maps.e_ships.cruiser.line] = 'X';
    }
    if (type_ship == 2) //Supprime le sous-marin
    {
        if (maps.e_ships.submarine.orientation == VERTICAL)
            for (i = 0; i < lenght; i++)
                maps.e_map[maps.e_ships.submarine.column][maps.e_ships.submarine.line + i] = 'X';
        if (maps.e_ships.submarine.orientation == HORIZONTAL)
            for (i = 0; i < lenght; i++)
                maps.e_map[maps.e_ships.submarine.column + i][maps.e_ships.submarine.line] = 'X';
    }
    if (type_ship == 1) // Supprime le destroyer
    {
        if (maps.e_ships.destroyer.orientation == VERTICAL)
            for (i = 0; i < lenght; i++)
                maps.e_map[maps.e_ships.destroyer.column][maps.e_ships.destroyer.line + i] = 'X';
        if (maps.e_ships.destroyer.orientation == HORIZONTAL)
            for (i = 0; i < lenght; i++)
                maps.e_map[maps.e_ships.destroyer.column + i][maps.e_ships.destroyer.line] = 'X';
    }
    return (maps);
}

int test_destroyed_ship(t_map maps, bool choice) //Fonction principale de test
{
    int i;

    i = 0;
    if (choice == 1)
    {
        for (i = 5; i > 0; i-- )
        {
            if (test_e_ship(maps, i) != 0) //teste map ennemie
                return (test_e_ship(maps, i));
        }
    }
    else
        for (i = 5; i > 0; i-- )
            if (test_p_ship(maps, i) != 0) //teste map joueur
                return (test_p_ship(maps, i));
    return (i);
}

t_map update_maps(t_map maps) //Met à jour la map "brouillard de guerre" avec la map ennemie et check la "vie" des navires
{
    int x ,y ,test;

    test = 0;
    test = test_destroyed_ship(maps, 0);
    if (test == 0)
        test = test_destroyed_ship(maps, 1);
    if (test > 20)
    {
        maps = destroy_p_ship(maps, test);
        cout << "Coulé !" << endl;
        Sleep(500);
    }
    else if (test > 10 && test < 20)
    {
        maps = destroy_e_ship(maps, test);
        cout << "Coulé !" << endl;
        Sleep(500);
    }
    for (y = 0; y < 10; y++)
        for (x = 0; x < 10; x++)
            if (maps.e_map[y][x] == 'O' || maps.e_map[y][x] == 'T' || maps.e_map[y][x] == 'X')
                maps.hide_e_map[y][x] = maps.e_map[y][x];
    return (maps);
}
