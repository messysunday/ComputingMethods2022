#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int Z;//do testowania
    cout << "Podaj ilosc powtorzen: ";
    cin >> Z;
    for (int z = 0; z < Z; ++z) //do wywolania wielu powtorzen
    {
        //deklaracje zmiennych
        int n; //wymiary macierzy nxn

        //pobieranie danych wejsciowych
        ifstream czytaj("RURL_dane1.txt"); //wczytywanie z pliku
        czytaj >> n; //wczytanie ilosci wezlow
        vector <double> wolne(n, 0); //na wyrazy wolne
        vector <double> wyniki(n, 0); // na rozwiazania
        vector <vector<double>> wspolczynniki(n, wolne); //na wspolczynniki
        for (int i = 0; i < n; ++i) //wczytywanie wspolrzednych wezlow
        {
            for (int j = 0; j < n; ++j)
            {
                double a;
                czytaj >> a;
                if (i == j && a == 0)
                {
                    cout << "Wartosc na przekatnej = 0, brak rozwiazania rownania!";
                    return 0;
                }
                wspolczynniki[i][j] = a;
            }
            double b;
            czytaj >> b;
            wolne[i] = b;
        }
    
    //wypisanie macierzy przed obliczeniami:
        cout << "Przed obliczeniami: \n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << setw(10) << right << wspolczynniki[i][j] << " ";
            }
            cout << setw(10) << right << wolne[i] << "\n";
        }

    //czesc 1: postepowanie proste
        double mnoznik = 0.0;
        for (int i = 0; i < n-1; ++i) //petla po wierszach
        {
            for (int j = i + 1; j < n; ++j) //petla po elementach wiersza != 0
            {
                mnoznik = wspolczynniki[j][i] / wspolczynniki[i][i];
                for (int k = i; k < n; ++k)
                {
                    wspolczynniki[j][k] -= mnoznik * wspolczynniki[i][k];
                }
                wolne[j] -= wolne[i] * mnoznik;
            }
        }
        cout << "Po doprowadzeniu do macierzy trojkatnej: \n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << setw(10) << right <<  wspolczynniki[i][j] << " ";
            }
            cout << setw(10) << right << wolne[i] << "\n";
        }

        //czesc 2: postepowanie odwrotne
        for (int i = n - 1; i >= 0; --i)
        {
            double skladnik = 0;
            for (int k = i; k < n; k++)
            {
                skladnik += wyniki[k] * wspolczynniki[i][k];
            }
            wyniki[i] = (wolne[i] - skladnik) / wspolczynniki[i][i];
        }
        cout << "Rozwiazanie:\n";
        for (int i = 0; i < n; ++i)
        {
            cout << setw(10) << right << wyniki[i] << "\n";
        }
    }
}