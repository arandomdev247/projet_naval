#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <iostream>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

typedef enum	e_direction //donne l'orientation
{
    HORIZONTAL, // = 0
    VERTICAL, // = 1
    O_ERROR // = 2
}		t_orient;

typedef struct s_ship_placement //coordonnées de l'emplacement du bateau
{
    int		    column; //colone
    int	    	line; //ligne
    t_orient    orientation; //orientation
}   t_sp;

typedef struct s_ship_type //coordonnées de l'emplacement de chaques navires
{
    t_sp        carrier;
    t_sp        battleship;
    t_sp        cruiser;
    t_sp        submarine;
    t_sp        destroyer;
}   t_st;

typedef struct s_map
{
    char     player_map[10][10]; //map du joueur
    char     hide_e_map[10][10]; //map ennemie affichée au joueur
    char     e_map[10][10]; //map ennemie
    t_st     p_ships; //position des navires du joueur sur la map
    t_st     e_ships; //position des navires ennemis sur la map
}       t_map;

//main.cpp

int reponse_tester(t_sp p, bool orientation); //Teste si toutes les réponses sont bonnes
void start_game(); //Lance une partie
t_map map_init(t_map maps); //Initialise la map

//end_main.cpp

//input.cpp

int test_letter(string answer); //Teste si l'écriture de la colonne a bien été faite
int get_letter(string answer); //Obtient la lettre du string et renvois la colonne pour tableau
int my_atoi(string str); //Transforme un chiffre (1 à 10) string en int
int test_line(string answer); //Teste si l'écriture  de la ligne a bien été faite
int get_line(string answer); //Obtient le chiffre du string et renvois la ligne pour tableau
int test_orientation(string answer); //Teste si l'écriture de l'orientation a bien été faite
t_orient get_orientation(string answer); // Obtient l'orientation du string
t_sp input(bool orientation); //Récupère les coodonnées

//_end_input.cpp

//output.cpp

void aff_ascii(); //affiche logo
void help(); //affiche aide
void aff_map(t_map maps); //Affiche la map du joueur (debug)
void rules(); //affiche les règles
void credits(); //affiche les credits
void aff_maps(t_map maps); //affiche les maps et autres infos

//_end_output.cpp

//put_ship.cpp

int ship_tester(t_sp p, int l_ship); //Teste si le vaisseau ne sort pas de la map
int get_lenght(int type_ship); //Renvois la longueur du vaisseau associé au type
char get_letter(int type_ship); //Renvois la lettre du vaisseau associé au type
int map_tester(t_sp p, t_map maps, int type_ship); //Test si il n'y a pas de navire déjà présent
t_map put_ship(t_sp p, t_map maps, int type_ship); //Integre le navire dans le tablea
t_map get_ship_position(bool orientation, t_map maps); //Obtient la position du navire

//_end_putship.cpp

//maps.cpp

int ranged_rand(int range_max); //Rand'o'machine
t_sp pos_generator(t_sp p, int l_ship); //Générateur de position
int rand_ship_tester(t_sp p, int l_ship); //Teste si le vaisseau ne sort pas de la map
int rand_map_tester(t_sp p, t_map maps, int type_ship); //Test si il n'y a pas de navire déjà présent (sans affichage)
t_map put_random_ship(t_sp p, t_map maps, int type_ship); //Met en place le navire (sans affichage)
t_map map_generator(t_map maps); //Génère la map
t_map generate_maps(t_map maps, bool choice); //Transfère la map générée sur la princiale


//_end_maps.cpp

//destroy.cpp

int test_map_whole(t_map maps); //Teste si un des participant a été vaincu
int test_p_ship(t_map maps, int type_ship); //Teste la map joueur
int test_e_ship(t_map maps, int type_ship); //Teste la map ennemie
t_map destroy_p_ship(t_map maps, int type_ship); //Supprime un navire sur la map joueur
t_map destroy_e_ship(t_map maps, int type_ship); //Supprime le navire sur la map ennemie
int test_destroyed_ship(t_map maps, bool choice); //Fonction principale de test
t_map update_maps(t_map maps); //Met à jour la map "brouillard de guerre" avec la map ennemie et check la "vie" des navires

//_end_destroy.cpp

//battle.cpp

t_map attacks(t_map maps, bool player, int difficulty); //Envois une attaque sur la map ennemie
int number_of_o(t_map maps); //Renvois le nombre d'essais echoués

//_end_battle.cpp

//ia.cpp

t_map ia_inoffensive(t_map maps); //IA évitant totalement de toucher les navires ennemis
t_map ia_meh(t_map maps); // IA qui tire de manière totalement aléatoire
t_map ia_impossibru(t_map maps); //IA demandant un perfect pour gagner
t_map ia_manager(t_map maps, int difficulty); //Gestionnaire d'IA

//_end_ia.cpp

#endif /* _INCLUDES_H_ */
