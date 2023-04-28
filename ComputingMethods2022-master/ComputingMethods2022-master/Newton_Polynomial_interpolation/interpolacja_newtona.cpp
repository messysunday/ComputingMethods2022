#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int Z;//do testowania
    cout << "Podaj ilosc powtorzen: ";
    cin >> Z;
    for (int z = 0; z < Z; ++z) //do wywolania wielu powtorzen
    {
        //deklaracje zmiennych
        vector <pair <double, double>> wezly; //wektor na wezly interpolacji, porzedstawione jako pary doubli, first = x, second = y
        vector <double> pk; //vector do wspolczynnkiow pk
        vector <double> bk; //vector do wspolczynnkiow bk
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
        n--; //zgodnie z trescia zadania mamy n+1 punktow, zeby uproscic obliczenia za n przyjeto ilosc pkt - 1 -> n
        //obliczanie pk
        pk.push_back(1); // poniewaz p0 = 1

        for (int k = 1; k <= n; ++k) //dla k od 1 do n
        {
            double skladnik = 1.0;
            for (int i = 0; i < k; ++i) //dla i od 0 do k-1
            {
                skladnik *= (punkt.first - wezly[i].first); //(x - xi)
            }
            pk.push_back(skladnik);
        }
        cout << "p: ";
        for (auto i : pk)
        {
            cout << i << " ";
        }
        cout << "\n";

        //obliczanie bk
        bk.push_back(wezly[0].second); // poniewaz b0 = f(x0)
        for (int k = 1; k <= n; ++k) //dla k od 1 do n, petla oblcizajaca sume
        {
            double skladnik1 = 0.0; //do sumowania
            double skladnik2 = 0.0; //do obliczneia ilorazu
            double skladnik3 = 1.0; //do obliczenia mianownika
            for (int i = 0; i <= k; ++i) //obliczanie skladnika sumy
            {
                skladnik2 = wezly[i].second;
                for (int j = 0; j <= k; ++j) //obliczanie mianownika skladnika sumy
                {
                    if (j == i)
                    {
                        continue;
                    }
                    else
                    {
                        skladnik3 *= (wezly[i].first - wezly[j].first); //(xi - xj)
                    }
                }
                skladnik2 /= skladnik3; //f(xi)/iloczyn
                skladnik3 = 1.0;
                skladnik1 += skladnik2; //dodanie skladnika do sumy
            }
            bk.push_back(skladnik1);
        }

        cout << "b: ";
        for (auto i : bk)
        {
            cout << i << " ";
        }
        cout << "\n";

        //obliczanie wartosci wielomianu interpolacyjnego
        punkt.second += pk[0] * bk[0]; //w0(x) = p0*b0
        for (int k = 1; k <= n; ++k)
        {
            punkt.second += pk[k] * bk[k];
        }

        //wypisane wynikow
        cout << "Wyniki:\n\t-Ilosc wezlow: " << n+1 << "\n\t-Wezly interpolacji i ich wartosci funkcji: \n\t\tx y\n";
        for (auto i : wezly)
        {
            cout << "\t\t" << i.first << " " << i.second << "\n";
        }
        cout << "\t-Punkt, ktorego wartosc wyznaczono za pomoca interpolacji: \n\t\tx: " << punkt.first << "\n\t\ty: " << punkt.second << "\n";
    }
    return 0;
}