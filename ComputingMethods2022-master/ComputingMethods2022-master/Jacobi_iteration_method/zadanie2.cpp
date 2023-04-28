#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

/*void wypisz_macierz(vector <vector< double>>& macierz)
{
    for (auto i : macierz)
    {
        for (auto j : i)
        {
            cout << setw(10) << right << j << " ";
        }
        cout << "\n";
    }
}

vector <double> operator * (vector <vector <double>>& macierz1, vector <double>& macierz2)
{
    vector <double> wynik(macierz2.size(), 0);
    for (int i = 0; i < macierz1.size(); ++i)
    {
        double pomoc = 0.0;
        for (int k = 0; k < macierz1[i].size(); ++k)
        {
            pomoc += macierz1[i][k] * macierz2[k];
        }
        wynik[i] = pomoc;
    }
    return wynik;
}

vector <double> operator - (vector <double>& macierz1, vector <double>& macierz2)
{
    vector <double> wynik(macierz1.size(), 0.0);
    for (int i = 0; i < macierz1.size(); ++i)
    {
        wynik[i] = macierz1[i] - macierz2[i];
    }
    return wynik;
}

int main()
{
    int n; //wymiary macierzy nxn
    ifstream czytaj("RURL_dane1.txt"); //wczytywanie z pliku
    czytaj >> n; //wczytanie ilosci wezlow
    vector <double> wolne(n, 0); //na wyrazy wolne
    vector <double> wynik1(n, 0.0); // na rozwiazania
    vector <double> wynik2(n, 0.0); // na rozwiazania
    vector <vector<double>> wspolczynniki(n, wolne); //na wspolczynniki
    vector <vector<double>> L(n, wolne);
    vector <vector<double>> U(n, wolne);
    vector <vector<double>> D(n, wolne);
    vector <vector<double>> DO(n, wolne);
    vector <vector<double>> L_U(n, wolne);
    for (int i = 0; i < n; ++i) //wczytywanie wspolrzednych wezlow
    {
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
    cout << "Uklad Rownan:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << setw(5) << right << wspolczynniki[i][j] << " ";
        }
        cout << setw(5) << right << wolne[i] << "\n";
    }
    bool test1 = true; //jesli chociaz 1 test sie wywali to zmiana na false
    bool test2 = false; //jesli chociaz 1 test jest ok to zmiana na true
    for (int i = 0; i < n; ++i)
    {
        if (test2 = true)
        {
            break;
        }
        double suma = 0.0;
        for (int j = 0; j < n; ++i)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                suma += wspolczynniki[i][j];
            }
        }
        if (suma > wspolczynniki[i][i])
        {
            test1 = false;
            cout << "Warunek nie jest spelniony, przerwanie programu!\n";
            return 0;
        }
        if (suma < wspolczynniki[i][i])
        {
            test2 = true;
            break;
        }
    }
    if (test1 == true && test2 == true)
    {
        cout << "Macierz diagonalnie slabo dominujaca! Program kontunuuje dzialanie\n";
    }
    else
    {
        cout << "Warunek nie jest spelniony, przerwanie programu!\n";
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                D[i][i] = wspolczynniki[i][i];
                DO[i][i] = wspolczynniki[i][i];
                continue;
            }
            if (i > j)
            {
                L[i][j] = wspolczynniki[i][j];
                L_U[i][j] = wspolczynniki[i][j];
            }
            if (i < j)
            {
                U[i][j] = wspolczynniki[i][j];
                L_U[i][j] = wspolczynniki[i][j];
            }
        }
    }
    cout << "Macierz dolna:\n";
    wypisz_macierz(L);
    cout << "Macierz gorna:\n";
    wypisz_macierz(U);
    cout << "Macierz dolna + gorna:\n";
    wypisz_macierz(L_U);
    cout << "Macierz diagonalna:\n";
    wypisz_macierz(D);

    //wyznaczanie odwrotnej dopelnieniami algebraicznymi
    for (int i = 0; i < n; ++i)
    {
        DO[i][i] = 1 / D[i][i] * pow(-1, i + i);
    }
    cout << "Macierz diagonalna odwrotna:\n";
    wypisz_macierz(DO);
    cout << "Przyblizanie wartosci rozwiazan - wartosc bledu: " << 0.001 << "\nRoznice miedzy kolejnymi iteracjami:\n" << setw(15) << right << "nr";
    for (int i = 1; i <= n; ++i)
    {
        cout << setw(15) << right << "x" <<i << "";
    }
    cout << "\n";
    int licz = 0; //tu bedzie max ilosc iteracji
    while (licz <= 1000)
    {
        licz++;
        wynik1 = wynik2;
        vector <double> iloczyn = L_U * wynik1;
        vector <double> skladnik = wolne - iloczyn;
        wynik2 = DO * skladnik;
        bool test = false;
        cout << setw(15) << right << licz << ":";
        for (int i = 0; i < n; ++i)
        {
            cout << setw(15) << right << abs(wynik1[i] - wynik2[i]) << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; ++i)
        {
            if (abs(wynik1[i] - wynik2[i]) < 0.001)
            {
                test = true;
            }
            else
            {
                test = false;
                break;
            }
        }
        if (test)
        {
            cout << setw(15) << right << "zakonczono, ilosc iteracji: " << licz;
            break;
        }
    }
    //wypisz_macierz(wyniki);
    cout << "\nWyniki:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " = " << wynik2[i] << "\n";
    }
}*/