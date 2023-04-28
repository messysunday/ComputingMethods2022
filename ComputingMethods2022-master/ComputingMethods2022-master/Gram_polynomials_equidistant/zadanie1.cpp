#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int factorial(int n)
{
	int wynik = 1.0;
	for (int i = 1; i <= n; ++i)
	{
		wynik *= i;
	}
	return wynik;
}

int dwumian(int n, int k)
{
	int wynik = 0;
	wynik = factorial(n) / (factorial(k) * factorial(n - k));
	return wynik;
}

int x_s(int x, int s)
{
	int wynik = 1;
	for (int i = 0; i < s; ++i)
	{
		wynik *= (x - i);
	}
	return wynik;
}

double wielomianOrtogonalny(int q, int n, int k)
{
	double F = 0.0;
	for (int s = 0; s <= k; ++s)
	{
		F += pow(-1, s) * dwumian(k, s) * dwumian(k + s, s) * x_s(q, s) / x_s(n, s);
	}
	return F;
}

double s(int n, int k)
{
    double wynik = 0.0;
    for (int q = 0; q <= n; ++q)
    {
        wynik += pow(wielomianOrtogonalny(q, n, k), 2);
    }
    return wynik;
}

double c(vector <pair <double, double>>& punkty, int n, int k)
{
    double wynik = 0.0;
    for (int i = 0; i <= n; ++i)
    {
        wynik += punkty[i].second * wielomianOrtogonalny(i, n, k);
    }
    return wynik;
}

int main()
{
	int m = 2; //stopien wielomianu
	int wezly = 8;
	int n = wezly - 1;
	vector <double> F(n + 1, 0);
    vector <double> C(m + 1, 0);
    vector <double> S(m + 1, 0);
    vector <double> B(m + 1, 0);
	vector <vector <double>> macierz(n + 1, C); //macierz
	vector <pair <double, double>> punkty;
    punkty.push_back(make_pair(1.0, 2.0));
    punkty.push_back(make_pair(2.0, 4.0));
    punkty.push_back(make_pair(3.0, 3.0));
    punkty.push_back(make_pair(4.0, 5.0));
    punkty.push_back(make_pair(5.0, 6.0));
    punkty.push_back(make_pair(6.0, 9.0));
    punkty.push_back(make_pair(7.0, 11.0));
    punkty.push_back(make_pair(8.0, 11.0));

    /*punkty.push_back(make_pair(1.0, 3.0));
    punkty.push_back(make_pair(1.5, 4.75));
    punkty.push_back(make_pair(2.0, 7.0));
    punkty.push_back(make_pair(2.5, 9.75));
    punkty.push_back(make_pair(3.0, 13.0));*/
    for (int q = 0; q <= n; ++q)
    {
        for (int k = 0; k <= m; ++k)
        {
            macierz[q][k] = wielomianOrtogonalny(q, n, k);
        }
    }
    for (int i = 0; i <= m; ++i)
    {
        C[i] = c(punkty, n, i);
        S[i] = s(n, i);
        B[i] = C[i] / S[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int k = 0; k <= m; ++k)
        {
            F[i] += B[k] * wielomianOrtogonalny(i, n, k); //k - stopien
        }
    }
    cout << "Macierz F:\n";
    for (auto i : macierz)
    {
        for (auto j : i)
        {
            cout << setw(10) << right << j << " ";
        }
        cout << "\n";
    }
    cout << "\nwspolczynnik S: ";
    for (auto i : S)
    {
        cout << setw(10) << right << i << " ";
    }
    cout << "\nwspolczynnik C: ";
    for (auto i : C)
    {
        cout << setw(10) << right << i << " ";
    }
    cout << "\nwspolczynnik B: ";
    for (auto i : B)
    {
        cout << setw(10) << right << i << " ";
    }
    cout << "\nWartosci dla punktow:\n";
    for (int i = 0; i <= n; ++i)
    {
        cout << setw(10) << right << punkty[i].first << ": " << F[i] << "\n";
    }
}