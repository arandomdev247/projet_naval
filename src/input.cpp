#include "includes.h"

int test_letter(string answer, bool orientation) //Teste si l'écriture de la colonne a bien été faite
{
    int i = -1;
    int n_letter = 0;
    unsigned int counter;

    for (counter = 0; counter < answer.length(); counter++)
        if ((answer[counter] >= 'A' && answer[counter] <= 'J') ||
            (answer[counter] >= 'a' && answer[counter] <= 'j'))
        {
            n_letter++;
            if (n_letter == 1)
                i = counter;
        }
    if ((n_letter < 1 && n_letter > 2) || ((answer[i] < 'A' || answer[i] > 'J') &&
            (answer[i] < 'a' || answer[i] > 'j')))
        return (-1);
    if ((n_letter == 1 && orientation == true) && ((answer[i] < 'A' && answer[i] > 'J') &&
            (answer[i] < 'a' && answer[i] >='j')))
        return (-1);
    return (0);
}

int get_letter(string answer, bool orientation) //Obtient la lettre du string et renvois la colonne pour tableau
{
    int n_letter;
    unsigned int counter;
    int i;
    i = 0;
    n_letter = 0;
    if (test_letter(answer, orientation) == -1)
        return (-1);
    for (counter = 0; counter < answer.length(); counter++)
        if ((answer[counter] >= 'A' && answer[counter] <= 'J') ||
            (answer[counter] >= 'a' && answer[counter] <= 'j'))
        {
            n_letter++;
            if (n_letter == 1)
                i = counter;
        }
    if (answer[i] == 'A' || answer[i] == 'a')
        return (0);
    else if (answer[i] == 'B' || answer[i] == 'b')
        return (1);
    else if (answer[i] == 'C' || answer[i] == 'c')
        return (2);
    else if (answer[i] == 'D' || answer[i] == 'd')
        return (3);
    else if (answer[i] == 'E' || answer[i] == 'e')
        return (4);
    else if (answer[i] == 'F' || answer[i] == 'f')
        return (5);
    else if (answer[i] == 'G' || answer[i] == 'g')
        return (6);
    else if (answer[i] == 'H' || answer[i] == 'h')
        return (7);
    else if (answer[i] == 'I' || answer[i] == 'i')
        return (8);
    else if (answer[i] == 'J' || answer[i] == 'j')
        return (9);
    else
        return(-1);
    return (-1);
}

int my_atoi(string str) //Transforme un chiffre (1 à 10) string en int
{
    int i;
    int n_letter;
    unsigned int counter;
    n_letter = 0;
    i = -1;
    for (counter = 0; counter < str.length(); counter++)
        {
            if (str[counter] >= '1' && str[counter] <= '9')
            {
                n_letter++;
                if (n_letter == 1)
                    i = counter;
            }
        }
    if (str[i] == '1' && str[i + 1] == '0')
        return (10);
    if (str[i] == '1')
        return(1);
    if (str[i] == '2')
        return(2);
    if (str[i] == '3')
        return(3);
    if (str[i] == '4')
        return(4);
    if (str[i] == '5')
        return(5);
    if (str[i] == '6')
        return(6);
    if (str[i] == '7')
        return(7);
    if (str[i] == '8')
        return(8);
    if (str[i] == '9')
        return(9);
    return (-1);
}

int test_line(string answer) //Teste si l'écriture  de la ligne a bien été faite
{
    int i = 0;
    int n_letter = 0;
    unsigned int counter;

    for (counter = 0; counter < answer.length(); counter++)
        if (answer[counter] >= '1' && answer[counter] <= '9')
        {
            n_letter++;
            if (n_letter == 1)
                i = counter;
        }
    if (n_letter > 2 || n_letter < 1
        || !(answer[i] >= '1' && answer[1] <= '9'))
        return (-1);
    if (n_letter == 2 && answer[i] != '1' && answer[i + 1] != '0')
        return (-1);
    return (0);
}

int get_line(string answer) //Obtient le chiffre du string et renvois la ligne pour tableau
{
    int num;
    if (test_line(answer) == -1)
        return (-1);
    num = my_atoi(answer);
    if (num < 1 || num > 10)
        return (-1);
    return (num - 1);
}

int test_orientation(string answer) //Teste si l'écriture de l'orientation a bien été faite
{
    int i = -1;
    int n_letter = 0;
    unsigned int counter;

    for (counter = 0; counter < answer.length(); counter++)
        if (answer[counter] == 'H' || answer[counter] == 'h' ||
            answer[counter] == 'V' || answer[counter] == 'v')
        {
            n_letter++;
            if (n_letter == 1 || n_letter == 2)
                i = counter;
        }
    if (n_letter < 1 ||n_letter > 2)
        return (-1);
    else if (answer[i] != 'H' && answer[i] != 'h' &&
            answer[i] != 'V' && answer[i] != 'v')
        return (-1);
    else
        return (0);
    return (0);
}

t_orient     get_orientation(string answer) // Obtient l'orientation du string
{
    int i = -1;
    unsigned int counter;
    int n_letter = 0;

    if (test_orientation(answer) == -1)
        return (O_ERROR);
    for (counter = 0; counter < answer.length(); counter++)
        if (answer[counter] == 'H' || answer[counter] == 'h' ||
            answer[counter] == 'V' || answer[counter] == 'v')
        {
            n_letter++;
            if (n_letter == 1 || n_letter == 2)
                i = counter;
        }
    if (n_letter < 1 ||n_letter > 2)
        return (O_ERROR);
    if (answer[i] == 'H' || answer[i] == 'h')
        return (HORIZONTAL);
    if (answer[i] == 'V' || answer[i] == 'v')
        return (VERTICAL);
    return (O_ERROR);
}


t_sp input(bool orientation) //Récupère les coodonnées
{
    t_sp p;
    string answer;
    getline (cin, answer);
    if (answer.length() < 2)
    {
        cerr << "Veuillez écrire correctement les coordonnées ! (ex : B3)" << endl;
        p.column = -1;
        p.line = -1;
        p.orientation = O_ERROR;
    }
    else
    {
        p.column = get_letter (answer, orientation);
        p.line = get_line (answer);
        if (orientation)
            p.orientation = get_orientation(answer);
    }
    return (p);
}
