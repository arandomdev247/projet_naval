#include "includes.h"

int reponse_tester(t_sp p, bool orientation) //Teste si toutes les réponses sont bonnes
{
    bool error = false;

    if (p.column == -1)
    {
        cerr << "Erreur ! Coordonnée de colonne incorrecte !" << endl;
        error = true;
    }
    if (p.line == -1)
    {
        cerr << "Erreur ! Coordonnées de lignes incorrecte !" << endl;
        error = true;
    }
    if (p.orientation == 2 && orientation)
    {
        cerr << "Erreur ! Orientation incorrecte !" << endl;
        error = true;
    }
    if (error == true)
        return (-1);
    return(0);
}


t_map map_init(t_map maps)
{
    int x,y;
    for (y = 0; y < 10 ; y++)
        for (x = 0; x < 10 ; x++)
        {
            maps.player_map[y][x] = '.'; //map du joueur
            maps.hide_e_map[y][x] = '.'; //map ennemie affichée au joueur
            maps.e_map[y][x] = '.'; //map ennemie
        }
    return(maps);
}

void start_game()
{
    string choix;
    string difficulty;
    t_map   maps;

    int ok = 0;
    while (ok == 0)
    {
        cout << "------- POSITIONNEMENT DE LA FLOTTE -------"  << endl << endl;
        cout << "Souhaitez vous générer automatiquement la position de votre flotte ?" <<endl <<endl;
        cout << "1. Oui"<< endl << "2. Non" <<endl<<endl<< "Choix : ";
        getline(cin, choix);
        system("CLS");
        if (choix == "1" || choix == "2")
            ok = 1;
        else
        {
            cerr << "Erreur ! Veuillez choisir entre 1 et 2 !";
            system("PAUSE");
            system("CLS");
        }
    }
    ok = 0;
    while ( ok == 0)
    {
        cout << "------- DIFFICULTE DE L'IA -------" <<endl << endl;
        cout << "Selectionnez l'intelligence de l'adversaire : " << endl << endl;
        cout << "1. Inoffensive" << endl << "2. Faible" << endl;
        cout << "3. IMPOSSIBRU !!!" << endl << endl << "Choix : ";
        getline(cin, choix);
        system("CLS");
        if (choix == "1" || choix == "2" || choix == "3")
            ok = 1;
        else
        {
            cerr << "Erreur ! Veuillez choisir entre 1 et 3 !";
            system("PAUSE");
            system("CLS");
        }
    }
    ok = 0;
    maps = map_init(maps);
    if (choix == "1")
        maps = generate_maps(maps, 0);
    else
        maps = get_ship_position(true, maps);
    maps = generate_maps(maps, 1); // 1 : ennemi || 0 : joueur
    maps = update_maps(maps);
    while (ok == 0)
    {
        system("CLS");
        aff_maps(maps);
        maps = attacks(maps, 1, NULL);
        maps = attacks(maps, 0, my_atoi(difficulty));
        maps = update_maps(maps);
        ok = test_map_whole(maps);
    }
    system("CLS");
    if (ok == 1)
    {
        cout << endl << endl << endl << endl;
        cout << "Félicitation ! La flotte ennemie est vaincue !"<< endl;
        cout << endl << endl;
        cout << "Votre score : " << 100 - number_of_o(maps) << endl;
    }
    else
    {
        cout << "Repli général ! Notre flotte est anéantie !" <<endl;
        cout << endl << endl;
        cout << "Votre score : " << 100 - number_of_o(maps) << endl;
    }
    system("PAUSE");
}

int main()
{
    int     choix;
    bool    alive = 1;

    setlocale(LC_CTYPE, "fra");
    while (alive == 1)
    {
        aff_ascii();
        cout << "----------Menu----------" << endl;
        cout << "1. Jouer !" <<endl;
        cout << "2. Aide" << endl;
        cout << "3. Règles du jeu" << endl;
        cout << "4. Credits" << endl;
        cout << "5. Quitter" <<endl;
        cout << endl << "Choix : ";
        cin >> choix;
        if (choix == 1)
        {
            cin.ignore();
            system("CLS");
            start_game();
            system("CLS");
        }
        else if (choix == 2)
            help();
        else if (choix == 3)
            rules();
        else if (choix == 4)
            credits();
        else if (choix == 5)
            alive = 0;
        else
        {
            system("CLS");
            cout << "\n\n\n\n\n\n\n\n";
            cerr<<"Erreur ! Veuillez choisir un chiffre entre 1 et 5 !" << endl;
            cin.clear();
            cin.ignore();
            system("PAUSE");
            system("CLS");
        }
    }
    return (0);
}
