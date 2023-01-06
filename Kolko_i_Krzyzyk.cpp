#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

char tablica[9] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };

void drukuj_tablice();
void ruch_gracza_x();
void ruch_gracza_y();
void ruch_komputera();
int zlicz_tablice(char symbol);
char sprawdz_wygrana();
void rozgrywka_z_komputerem();
void rozgrywka_z_graczem();

int main() 
{
    cout << "**********************************************" << endl;
    cout << "            Gra w kolko i krzyzyk             " << endl;
    cout << "**********************************************" << endl << endl;
    int tryb_gry;
    cout << "Wybierz, z kim chcesz zagrac:" << endl;
    cout << "1. Rozgrywka z komputerem. " << endl;
    cout << "2. Rozgrywka z drugim graczem. " << endl<< endl;
    
    cin >> tryb_gry;

    switch (tryb_gry) 
    {
    case 1 :
        cout << "Wybrales rozgrzywke z komputerem. " << endl << endl;
        rozgrywka_z_komputerem();
        break;
    case 2 :
        cout << "Wybrales rozgrzywke z drugim graczem. " << endl << endl;
        rozgrywka_z_graczem();
        break;
    default :
        cout << "Wybrales niewlasciwy tryb gry. Wybierz ponownie (1 albo 2). " << endl;
        break;
    }
    
    return 0;
}

void rozgrywka_z_komputerem() 
{
    while (true) 
    {

        drukuj_tablice();
        if (zlicz_tablice('X') == zlicz_tablice('Y')) 
        {
            cout << endl << "Twoj ruch [X]." << endl;
            ruch_gracza_x();
        }
        else 
        {
            ruch_komputera();
        }

        char wygrany = sprawdz_wygrana();
        if (wygrany == 'X') 
        {
            drukuj_tablice();
            cout << endl << "Gracz pierwszy [X] wygral gre. " << endl;
            break;
        }
        else if (wygrany == 'Y') 
        {
            drukuj_tablice();
            cout << endl << "Komputer wygral gre. " << endl;
            break;
        }
        else if (wygrany == 'D') 
        {
            drukuj_tablice();
            cout << endl << "Gra pozostala nierozstrzygnieta. " << endl;
            break;
        }
    }
 }

void rozgrywka_z_graczem() 
{
    while (true)
    {
        drukuj_tablice();
        if (zlicz_tablice('X') == zlicz_tablice('Y')) 
        {
            cout << endl << "Twoj ruch [X]." << endl;
            ruch_gracza_x();
        }
        else 
        {
            cout << endl << "Ruch drugiego gracza [Y]." << endl;
            ruch_gracza_y();
        }
        char wygrany = sprawdz_wygrana();
        if (wygrany == 'X')
        {
            drukuj_tablice();
            cout << endl << "Gracz pierwszy [X] wygral gre. " << endl;
            break;
        }
        else if (wygrany == 'Y')
        {
            drukuj_tablice();
            cout << endl <<"Gracz drugi [Y] wygral gre. " << endl;
            break;
        }
        else if (wygrany == 'D')
        {
            drukuj_tablice();
            cout << endl << "Gra pozostala nierozstrzygnieta. " << endl;
            break;
        }
    }
}


void ruch_komputera() 
{
    srand(time(NULL));
    int wybor;
    do    
    {
        wybor = rand()%9;
    } while (tablica[wybor] != ' ');
        tablica[wybor] = 'Y';
        cout << endl << "Komputer wybral pole: " << wybor + 1 << endl;
}

void ruch_gracza_x() 
{
    while (true) 
    {
        cout << "Wybierz pole (1-9): ";
        int wybor;
        cin >> wybor;
        cout << endl << "Gracz pierwszy [X] wybral pole: " << wybor << endl;
        wybor--;
        if (wybor < 0 || wybor > 8)
        {
            cout << "Wybrales z niewlasciwego zakresu. Wybierz ponownie (1-9)." << endl;
        }
        else if (tablica[wybor] != ' ')
        {
            cout << "Wybrales zajete pole. Wybierz puste pole." << endl;
        }
        else 
        {
            tablica[wybor] = 'X';
            break;
        }
    }
}

void ruch_gracza_y() 
{
    while (true) 
    {
        cout << "Wybierz pole (1-9): ";
        int wybor;
        cin >> wybor;
        cout << endl << "Gracz drugi [Y] wybral pole: " << wybor << endl;
        wybor--;
        if (wybor < 0 || wybor > 8)
        {
            cout << "Wybrales z niewlasciwego zakresu. Wybierz ponownie (1-9)" << endl;
        }
        else if (tablica[wybor] != ' ')
        {
            cout << "Wybrales zajete pole. Wybierz puste pole." << endl;
        }
        else 
        {
            tablica[wybor] = 'Y';
            break;
        }
    } 
}

int zlicz_tablice(char symbol) 
{
    int total = 0;
    for (int i = 0; i < 9; i++) 
    {
        if (tablica[i] == symbol)
            total += 1;
    }
    return total;
}

char sprawdz_wygrana()  
{
    // w wierszach
    if (tablica[0] == tablica[1] && tablica[1] == tablica[2] && tablica[0] != ' ')
        return tablica[0];
    if (tablica[3] == tablica[4] && tablica[4] == tablica[5] && tablica[3] != ' ')
        return tablica[3];
    if (tablica[6] == tablica[7] && tablica[7] == tablica[8] && tablica[6] != ' ')
        return tablica[6];
    // w kolumnach
    if (tablica[0] == tablica[3] && tablica[3] == tablica[6] && tablica[0] != ' ')
        return tablica[0];
    if (tablica[1] == tablica[4] && tablica[4] == tablica[7] && tablica[1] != ' ')
        return tablica[1];
    if (tablica[2] == tablica[5] && tablica[5] == tablica[8] && tablica[2] != ' ')
        return tablica[2];
    // w przekątnych
    if (tablica[0] == tablica[4] && tablica[4] == tablica[8] && tablica[0] != ' ')
        return tablica[0];
    if (tablica[2] == tablica[4] && tablica[4] == tablica[6] && tablica[2] != ' ')
        return tablica[2];
    if (zlicz_tablice('X') + zlicz_tablice('Y') < 9)
        return 'C'; //gra trwa dalej
    else
        return 'D'; //gra nierozstrzygnieta
}

void drukuj_tablice() 
{
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << tablica[0] << "  |   " << tablica[1] << "  |   " << tablica[2] << endl;
    cout << "___" << "___|___" << "___|______" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << tablica[3] << "  |   " << tablica[4] << "  |   " << tablica[5] << endl;
    cout << "___" << "___|___" << "___|______" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << tablica[6] << "  |   " << tablica[7] << "  |   " << tablica[8] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
}