#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

/*int factorial(int n)
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

double G(int q, int n, int k)
{
	double g = 0.0;
	for (int s = 0; s <= k; ++s)
	{
		g += pow(-1, s) * dwumian(k, s) * dwumian(k + s, s) * (double)x_s(q, s)/(double)x_s(n, n);
		//cout << "\nk = " << k << ": " << pow(-1, s) << " * " << dwumian(k, s) * dwumian(k + s, s)  <<" * " << (double)((double)(factorial(q) / (double)factorial(q - s)) / ((double)((double)factorial(n) / (double)factorial(n - s)))) << "\n";
	}
	return g;
}

double C(vector<pair <double, double>> & punkty, int & n, int & k)
{
	double c = 0.0;
	for (int i = 0; i <= n; ++i)
	{
		c += (punkty[i].second * G(punkty[i].first, n, k));
	}
	return c;
}

double S(int n, int k)
{
	double s = 0.0;
	for (int q = 0; q <= n; ++q)
	{
		s += pow(G(q, n, k), 2);
	}
	return s;
}*/

/*int main()
{
	int wezly = 5;
	int n = wezly - 1;
	int M = 4; //stopien
	vector <pair <double, double>> punkty;
	punkty.push_back(make_pair(1.0, 3.0));
	punkty.push_back(make_pair(1.5, 4.75));
	punkty.push_back(make_pair(2.0, 7.0));
	punkty.push_back(make_pair(2.5, 9.75));
	punkty.push_back(make_pair(3.0, 13.0));
	vector <double> F(M + 1, 0.0); //wielomian
	vector <double> q(wezly, 0.0);
	for (int i = 0; i < wezly; ++i)
	{
		q[i] = (punkty[i].first - punkty[0].first) / (0.5); // (x - x0)/h gdzie h to odl miedzy wezlami
	}
	for (int k = 0; k <= M; ++k)
	{
		for (int i = 0; i <= n; ++i)
		{
			F[k] += (C(punkty, n, k) / S(n, k)) * G(q[i], n, k);	
		}
	}
	for (int k = 0; k <= M; ++k)
	{
		cout << C(punkty, n, k) << "\n";
	}
	for (auto i : F)
	{
		//cout << i << "\n";
	}
}*/