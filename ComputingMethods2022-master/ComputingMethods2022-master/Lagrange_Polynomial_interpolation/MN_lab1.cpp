#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

void zadanie1()
{
    //deklaracje zmiennych
    vector <pair <double, double>> wezly; //wektor na wezly interpolacji, porzedstawione jako pary doubli, first = x, second = y
    vector <double> wspolczynniki; //wektor na skladniki wielomianu lagrange'a
    int n; //ilosc wezlow
    pair <double, double> punkt; //punkt w ktorym obliczamy wartosci wezlow

    //pobieranie danych wejsciowych
    ifstream czytaj("dane.txt"); //wczytywanie z pliku
    czytaj >> n; //wczytanie ilosci wezlow
    for (int i = 0; i < n; ++i) //wczytywanie wspolrzednych wezlow
    {
        double a, b;
        czytaj >> a >> b;
        pair <double, double> pomoc = make_pair(a, b);
        wezly.push_back(pomoc);
    }
    cout << "Podaj x punktu w ktorym chcesz wyznaczyc wartosc wielomianu: ";
    cin >> punkt.first; //podanie x dla ktorego y chcemy interpolowac
    punkt.second = 0; //interpolowany y na razie jest rowny 0

    //obliczanie wartosci wielomianu lagrange'a
    //krok 1 - obliczanie iloczynow dla kazdego wezla z podstawieniem wspolrzednych szukanego punktu w miejsce x:
    for (int i = 0; i < n; ++i)
    {
        double skladnik = 1.0; //na poczatku skladniki wielomianu lagrange'a sa rowne 1
        for (int j = 0; j < n; ++j) //petla obliczajaca iloczyny
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                skladnik *= (punkt.first - wezly[j].first) / (wezly[i].first - wezly[j].first); //(x - xj)/(xi - xj)
            }
        }
        wspolczynniki.push_back(skladnik);
    }

    //krok 2 - przemnozenie wspolczynnikow razy wartosci w wezlach i dodanie ich do siebie
    for (int i = 0; i < n; ++i) //petla sumujaca
    {
        punkt.second += wezly[i].second * wspolczynniki[i]; //fx * (x - xj)/(xi - xj)
    }

    //wypisane wynikow
    cout << "Wyniki:\n\t-Ilosc wezlow: " << n << "\n\t-Wezly interpolacji i ich wartosci funkcji: \n\t\tx y\n";
    for (auto i : wezly)
    {
        cout << "\t\t" << i.first << " " << i.second << "\n";
    }
    cout << "\t-Punkt, ktorego wartosc wyznaczono za pomoca interpolacji: \n\t\tx: " << punkt.first << "\n\t\ty: " << punkt.second << "\n";
    return;
}

void zadanie2()
{
    //deklaracja zmiennych
    vector <pair <double, double>> wezly; //wspolrzedne wezlow interpolacji w postaci par x, y
    vector <double> wspolczynniki; //do obliczania wspolczynnikow wielomianu lagrange'a
    int n = 4; //ilosc wezlow interpolacji
    pair <double, double> punkt;
    punkt.first = 50.0;
    punkt.second = 0.0;
    pair <double, double> pomoc; //do tworzenia wezlow interpolacji

    //generowanie danych
    for (int i = 0; i < n; ++i)
    {
        double y = 3.0 + i;
        double x = pow(y, 3.0);
        pomoc.first = x;
        pomoc.second = y;
        wezly.push_back(pomoc);
    }
    //obliczanie wartosci wielomianu lagrange'a
    //krok 1 - obliczanie iloczynow dla kazdego wezla z podstawieniem wspolrzednych szukanego punktu w miejsce x:
    for (int i = 0; i < n; ++i)
    {
        double skladnik = 1.0; //na poczatku skladniki wielomianu lagrange'a sa rowne 1
        for (int j = 0; j < n; ++j) //petla obliczajaca iloczyny
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                skladnik *= (punkt.first - wezly[j].first) / (wezly[i].first - wezly[j].first); //(x - xj)/(xi - xj)
            }
        }
        wspolczynniki.push_back(skladnik);
    }

    //krok 2 - przemnozenie wspolczynnikow razy wartosci w wezlach i dodanie ich do siebie
    for (int i = 0; i < n; ++i) //petla sumujaca
    {
        punkt.second += wezly[i].second * wspolczynniki[i]; //fx * (x - xj)/(xi - xj)
    }
    //sprawdzenie poprawnosci generowanych danych i wynikow
    cout << "Wyniki:\n\t-Ilosc wezlow: " << n << "\n\t-Wezly interpolacji i ich wartosci funkcji: \n\t\tx y\n";
    for (auto i : wezly)
    {
        cout << "\t\t" << i.first << " " << i.second << "\n";
    }
    cout << "\t-Punkt, ktorego wartosc wyznaczono za pomoca interpolacji: \n\t\tx: " << punkt.first << "\n\t\ty: " << punkt.second << "\n";
    return;
}

int main()
{
    cout << "ZADANIE 1:\n";
    zadanie1();
    cout << "ZADANIE 2:\n";
    zadanie2();
}