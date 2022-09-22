#include "includes.h"

int ship_tester(t_sp p, int l_ship) //Teste si le vaisseau ne sort pas de la map
{
    bool ok = true;
    if (p.orientation == VERTICAL)
    {
        if (l_ship + p.line > 10)
            ok = false;
    }
    if (p.orientation == HORIZONTAL)
    {
        if (l_ship + p.column > 10)
            ok = false;
    }
    if (ok == false)
    {
        cerr << "Erreur : Le navire ne peut pas être posé ici !" <<endl;
        return(-1);
    }
    return (0);
}

int get_lenght(int type_ship) //Renvois la longueur du vaisseau associé au type
{
    if (type_ship == 5)
        return(5);
    if (type_ship == 4)
        return(4);
    if (type_ship == 3)
        return(3);
    if (type_ship == 2)
        return(3);
    if (type_ship == 1)
        return(2);
    return (-1);
}

char get_letter(int type_ship) //Renvois la lettre du vaisseau associé au type
{
    if (type_ship == 5)
        return('P');
    if (type_ship == 4)
        return('B');
    if (type_ship == 3)
        return('C');
    if (type_ship == 2)
        return('S');
    if (type_ship == 1)
        return('D');
    return (0);
}

int map_tester(t_sp p, t_map maps, int type_ship) //Test si il n'y a pas de navire déjà présent
{
    int i;
    int lenght;
    lenght = get_lenght(type_ship);
    if (p.orientation == VERTICAL)
    {
        for (i = 0; i < lenght; i++)
            if (maps.player_map[p.column][p.line + i] != '.')
            {
                cerr << "Erreur ! Un navire est déjà positioné ici !" <<endl;
                return (-1);
            }
    }
    if (p.orientation == HORIZONTAL)
    {
        for (i = 0; i < lenght; i++)
            if (maps.player_map[p.column + i][p.line] != '.')
            {
                cerr << "Erreur ! Un navie est déjà positioné ici !" <<endl;
                return (-1);
            }
    }
    return (0);
}

t_map put_ship(t_sp p, t_map maps, int type_ship)
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

t_map get_ship_position(bool orientation, t_map maps)
{
    t_sp    pos;
    int     etape = 1; //Recupération de l'etape des input, sert en cas de mauvaise input de l'user
    bool    ok = 0; //Confrmation de toute les infos
    aff_maps(maps);
    while (ok != 1)
    {
        if (etape == 1) //Input du porte-avion
        {
            cout << endl <<"Veuillez donner l'emplacement du navire :" << endl << endl;
            cout << "Porte-Avion (5) : ";
            pos = input(true);
            cout <<endl;
            if (reponse_tester(pos, true) != -1 && ship_tester(pos, 5) != -1
                && map_tester(pos, maps, 5) != -1)
            {
                maps.p_ships.carrier = pos;
                etape = 2;
                maps = put_ship(pos, maps, 5);
                system("CLS");
                aff_maps(maps);
            }
        }
        if (etape == 2) //Input du cuirassé
        {
            cout << "\nVeuillez donner l'emplacement du navire :" << endl << endl;
            cout << "Cuirassé (4) : ";
            pos = input(1);
            if (reponse_tester(pos, true) != -1 && ship_tester(pos, 4) != -1
                && map_tester(pos, maps, 4) != -1)
            {
                maps.p_ships.battleship = pos;
                etape = 3;
                maps = put_ship(pos, maps, 4);
                system("CLS");
                aff_maps(maps);
            }
        }
        if (etape == 3) //Input du croiseur
        {
            cout << "\nVeuillez donner l'emplacement du navire :" << endl << endl;
            cout << "Croiseur (3) : ";
            pos = input(1);
            if (reponse_tester(pos, true) != -1 && ship_tester(pos, 3) != -1
                && map_tester(pos, maps, 3) != -1)
            {
                maps.p_ships.cruiser = pos;
                etape = 4;
                maps = put_ship(pos, maps, 3);
                system("CLS");
                aff_maps(maps);
            }
        }
        if (etape == 4) //Input du sous-marin
        {
            cout << "\nVeuillez donner l'emplacement du navire :" << endl << endl;
            cout << "Sous-marin (3) : ";
            pos = input(1);
            if (reponse_tester(pos, true) != -1 && ship_tester(pos, 2) != -1
                && map_tester(pos, maps, 2) != -1)
            {
                maps.p_ships.submarine = pos;
                etape = 5;
                maps = put_ship(pos, maps, 2);
                system("CLS");
                aff_maps(maps);
            }
        }
        if (etape == 5) //Input du destroyer
        {
            cout << "\nVeuillez donner l'emplacement du navire :" << endl << endl;
            cout << "Destroyer (2) : ";
            pos = input(1);
            if (reponse_tester(pos, true) != -1 && ship_tester(pos, 1) != -1
                && map_tester(pos, maps, 1) != -1)
            {
                maps.p_ships.destroyer = pos;
                ok = 1;
                maps = put_ship(pos, maps, 1);
                system("CLS");
            }
        }
    }
    return (maps);
}
