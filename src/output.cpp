#include "includes.h"

void aff_ascii() //affiche logo
{
    cout << "        ######                                                         " << endl;
    cout << "        #     #   ##   ##### ##### #      ######  ####  #    # # ##### " << endl;
    cout << "        #     #  #  #    #     #   #      #      #      #    # # #    #" << endl;
    cout << "        ######  #    #   #     #   #      #####   ####  ###### # #    #" << endl;
    cout << "        #     # ######   #     #   #      #           # #    # # ##### " << endl;
    cout << "        #     # #    #   #     #   #      #      #    # #    # # #     " << endl;
    cout << "        ######  #    #   #     #   ###### ######  ####  #    # # #   \n" << endl;
}

void help() //affiche aide
{
    system("CLS");
    cout << "Aide pour mieux comprendre le jeu" <<endl << endl;

    cout << "Pour �crire les coordonn�es de placement, rien de plus" << endl
    << "simple ! Il suffit simplement d'�crire la lettre voulue... " <<endl
    << "Puis la colonne... " << endl
    << "Et si vous souhaitez positionner vous m�me votre flotte..." <<endl
    << "Il suffit de rajouter un H (horizontal) ou un V (vertical)" << endl
    << "apr�s avoir pr�cis� la coordonn�e !" << endl << endl;

    cout << "Bon jeu, et bonne chance !" << endl;
    system("PAUSE");
    system("CLS");
}

void rules() //affiche les r�gles
{
    system("CLS");
    cout << "R�gle de la Bataille navale" <<endl << endl;

    cout << "Ce jeu de soci�t� se joue � deux, l�un contre l�autre sur deux grilles o� sont" << endl
    << "plac�s 5 navires mis en place par les joueurs." << endl << endl;

    cout << "Le but �tant de faire couler tous les navires de l�adversaire. C�est � la fois" <<endl
    << "un jeu de r�flexion et un jeu de hasard." << endl << endl;

    cout << "Pour jouer � la bataille navale, il faut par joueur :" <<endl << endl;

    cout << "Une grille de jeu num�rot�e de 1 � 10 verticalement et de A � J" << endl
    << "horizontalement" <<endl << endl;

    cout << "1 porte avion (5 cases)" << endl << endl;

    cout << "1 croiseur (4 cases)"<< endl << endl;

    cout << "1 contre torpilleur (3 cases)" <<endl << endl;

    cout << "1 sous-marin (3 cases)" << endl << endl;

    cout << "1 torpilleur (2 cases)" << endl << endl;

    system("PAUSE");
    system("CLS");

    cout << "Commencer une partie de bataille navale :" << endl << endl;

    cout << "Au d�but du jeu, chaque joueur place � sa guise tous les bateaux sur sa grille" << endl
    << "de fa�on strat�gique. Le but �tant de compliquer au maximum la tache de son" << endl
    << "adversaire, c�est-�-dire d�truire tous vos navires. Bien entendu, le" << endl
    << "joueur ne voit pas la grille de son adversaire." << endl
    << "Une fois tous les bateaux en jeu, la partie peut commencer. Un � un, les" << endl
    << "joueurs se tirent dessus pour d�truire les navires ennemis." << endl;

    cout << "Exemple le joueur dit � voix haute H7 correspondant � la case au croisement" << endl
    << "de la lettre H et du num�ro 7 sur les c�t�s des grilles." << endl;

    cout << "Si un joueur tire sur un navire ennemi, l�adversaire doit le signaler en disant" << endl
    << "�touch�. Il ne peut pas jouer deux fois de suite et doit attendre le tour de" <<endl
    << "l�autre joueur." << endl;
    cout << "Si le joueur ne touche pas de navire, l�adversaire le signale en disant �rat�." << endl;
    cout << "Si le navire est enti�rement touch� l�adversaire doit dire �touch� coul�." << endl << endl;

    cout << "Les �O� et les �T� servent � se souvenir des tirs rat�s (�O�) et les tirs" << endl
    << "touch�s (�T�). Il est indispensable de les utiliser pour ne pas tirer deux" << endl
    << "fois au m�me endroit et donc ne pas perdre de temps inutilement. Ces pions" << endl
    << "se placent sur la grille sur le c�t�, repr�sentant la carte ennemie.." << endl << endl;

    system("PAUSE");
    system("CLS");

    cout << "Comment gagner une partie de bataille navale" << endl << endl;

    cout << "Une partie de bataille navale se termine lorsque l�un des joueurs" << endl
    << "n�a plus de navires." << endl << endl;

    cout << "Astuces pour gagner � la bataille navale" << endl << endl;

    cout << "Pour gagner plus rapidement, vous pouvez jouer vos tirs en croix, �tant donn�" << endl
    << "que le plus petit navire fait deux cases alors vous ne pourrez �viter aucun" << endl
    << "autre bateau sur votre chemin. Cette m�thode est infaillible car elle est" << endl
    << "purement logique." << endl;
    system("PAUSE");
    system("CLS");
}

void aff_info(int y) //affiche les infos
{
    if (y == 0)
        cout << " P : Porte-avion           |";
    if (y == 1)
        cout << " B : Cuirass� (Battleship) |";
    if (y == 2)
        cout << " C : Croiseur              |";
    if (y == 3)
        cout << " S : Sous-Marin            |";
    if (y == 4)
        cout << " D : Destroyer             |";
    if (y == 5)
        cout << "___________________________|";
    if (y == 6)
        cout << " Info map :                |";
    if (y == 7)
        cout << " O : Vide                  |";
    if (y == 8)
        cout << " T : Touch�                |";
    if (y == 9)
        cout << " X : Coul�                 |";
}

void aff_maps(t_map maps) //affiche les maps et autres infos
{
    cout << "  ______________________________________________" << endl;
    cout << " / Votre flotte :        | Flotte ennemie :      \\" << endl <<
            "|                        |                        |" << endl;
    cout << "|    A B C D E F G H I J |    A B C D E F G H I J |"
         << "__________________________" << endl;
    cout << "|                        |                        |"<<
            " Info Navire :            \\"<<endl;
    int x1,y,x2;
    for (y = 0; y < 10 ; y++)
    {
        if (y < 9)
            cout << "| " << y+1 << "  ";
        else
            cout << "| " << y+1 << " ";
        for (x1 = 0; x1 < 10 ; x1++)
            cout << maps.player_map[x1][y] << " "; //map du joueur
        if (y < 9)
            cout << "| " << y+1 << "  ";
        else
            cout << "| " << y+1 << " ";
        for (x2 = 0; x2 < 10 ; x2++)
            cout << maps.hide_e_map[x2][y] << " "; //map cach�e de l'ennemi
        cout << "|";
        aff_info(y);
        cout << endl;
    }
    cout << " \\________________________________________________|"
         << "__________________________/" << endl;
    cout << endl;
}

void credits() //affiche les credits
{
    system("CLS");
    cout << "\n\n\n\n";
    cout << "Battleship est un jeu cr�e par :" <<endl << endl;
    cout <<  "ADAMCZYK Benjamin" <<endl;
    cout << "BOHN Sebastien" <<endl;
    cout << "BALOU Alain" <<endl << endl;
    cout << "Ce jeu a �t� cr�e pour un projet en groupe." << endl;
    cout << "Le jeu est open source et libre." << endl;
    cout << "Utilisation comerciale interdite sans demande directe aux cr�ateurs !" << endl;

    system("PAUSE");
    system("CLS");
}


/*void aff_map(t_map maps) //Affiche la map du joueur (debug)
{
    cout << "   A B C D E F G H I J"<<endl<<endl;
    int x,y;
    for (y = 0; y < 10 ; y++)
    {
        if (y < 9)
            cout << y+1 << "  ";
        else
            cout << y+1 << " ";
        for (x = 0; x < 10 ; x++)
            cout << maps.hide_e_map[x][y] << " "; //map du joueur
        cout << endl;
    }
    cout << endl;
}*/
