#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

int PartialPivoting(vector <vector <double>>& macierz, vector <double>& x, int wiersz)
{
    double maks = -1.0; //tu bedzie element o najwiekszym module
    int p = 0; //indeksy wiersza zamienianego z rozpatrywanym
    for (int j = wiersz; j < macierz[wiersz].size(); ++j)
    {
        if (abs(macierz[j][wiersz]) > maks)
        {
            maks = abs(macierz[j][wiersz]);
            p = j; //zapisujemy nr wiersza
        }
    }
    if (maks == 0)
    {
        return -1; //uklad osobliwy, ABORT THE MISSION
    }
    else if (wiersz == p)
    {
        return 1; //uklad rozwiazywalny, ale zamiana nie jest potrzebna
    }
    else if (maks > 0) //zamiana jest potrzebna
    {
        double pomoc = 0.0;
        for (int i = wiersz; i < macierz.size(); ++i) //nie trzeba zamieniac przed elementem o nr wiersz, bo te elementy sa = 0
        {
            pomoc = macierz[wiersz][i];
            macierz[wiersz][i] = macierz[p][i];
            macierz[p][i] = pomoc;
        }
        pomoc = x[wiersz];
        x[wiersz] = x[p];
        x[p] = pomoc;
        return 1;
    }
}

int GaussCrout(vector <vector <double>>& macierz, vector <double>& x, vector <int> & kolejnosc, int wiersz)
{
    double maks = -1.0; //tu bedzie element o najwiekszym module
    int p = 0; //indeks kolumny zamienianej z rozpatrywana
    for (int j = wiersz; j < macierz[wiersz].size(); ++j)
    {
        if (abs(macierz[wiersz][j]) > maks) //maksimum w wierszu
        {
            maks = abs(macierz[wiersz][j]);
            p = j; //zapisujemy 
        }
    }
    if (maks == 0)
    {
        return -1; //uklad osobliwy, ABORT THE MISSION
    }
    else if (wiersz == p)
    {
        return 1; //uklad rozwiazywalny, ale zamiana nie jest potrzebna
    }
    else if (maks > 0) //zamiana jest potrzebna
    {
        double pomoc = 0.0;
        for (int i = 0; i < macierz.size(); ++i) //nie trzeba zamieniac przed elementem o nr wiersz, bo te elementy sa = 0
        {
            pomoc = macierz[i][wiersz];
            macierz[i][wiersz] = macierz[i][p];
            macierz[i][p] = pomoc;
        }
        pomoc = kolejnosc[wiersz];
        kolejnosc[wiersz] = kolejnosc[p];
        kolejnosc[p] = pomoc;
        return 1;
    }
}

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
        ifstream czytaj("RURL_dane3.txt"); //wczytywanie z pliku
        czytaj >> n; //wczytanie ilosci wezlow
        vector <double> wolne(n, 0); //na wyrazy wolne
        vector <double> wyniki(n, 0); // na rozwiazania
        vector <int> kolejnosc(n, 0); //przy przestawianiu kolumn, zeby nie zgubic kolejnosci
        vector <vector<double>> wspolczynniki(n, wolne); //na wspolczynniki
        for (int i = 0; i < n; ++i) //wczytywanie wspolrzednych wezlow
        {
            kolejnosc[i] = i; //wypelnienie vectora kolejnosci
            for (int j = 0; j < n; ++j)
            {
                double a;
                czytaj >> a;
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
        for (int i = 0; i < n - 1; ++i) //petla po wierszach
        {
            for (int j = i + 1; j < n; ++j) //petla po elementach wiersza != 0
            {
                int kontrol = GaussCrout(wspolczynniki, wolne, kolejnosc, i);
                if (kontrol == -1)
                {
                    cout << "UKLAD OSOBLIWY, PRZERWANIE DZIALANIA PROGRAMU!\n";
                    return 0;
                }
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
                cout << setw(10) << right << wspolczynniki[i][j] << " ";
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
            cout << setw(10) << right << "x" << kolejnosc[i] + 1<< " = " << wyniki[i] << "\n";
        }
    }
    return 0;
}