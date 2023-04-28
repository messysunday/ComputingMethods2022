#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

double sinus(double x)
{
	return sin(x);
}

double parabola(double x)
{
	return (pow(x, 2) + 2 * x + 5);
}

double exp(double x)
{
	double e = 2.718281828459;
	return (pow(e, x));
}

double prostakaty(double a, double b, double & n, vector <double>& elementy, double (f)(double))
{
	double s = (a - b) / n;
	double wyn = 0.0;
	for (int i = 0; i < n; ++i)
	{
		wyn += f(elementy[i] + s / 2);
	}
	wyn *= s;
	return wyn;
}

double trapezy(double a, double b, double& n, vector <double>& elementy, double (f)(double))
{
	double wyn = 0.0;
	for (int i = 0; i < n; ++i)
	{
		wyn += (elementy[i + 1] - elementy[i]) / 2 * (f(elementy[i]) + f(elementy[i + 1]));
	}
	return wyn;
}

double parabole(double a, double b, double& n, vector <double>& elementy, double (f)(double))
{
	double s = (a - b) / n;
	double wyn = 0.0;
	for (int i = 0; i < n; ++i)
	{
		wyn += (elementy[i + 1] - elementy[i]) / 6 * (f(elementy[i]) + 4 * f((elementy[i + 1] + elementy[i]) / 2) + f(elementy[i + 1]));
	}
	return wyn;
}

void zadanie1()
{
	cout << "Zadanie1:\n";
	double n = 4;
	vector <double> elementy(n + 1, 0);
	cout << "Wybierz funkcje podcalkowa:\n\t1. sin(x) w przedziale 0,5 - 2,5\n\t2. x^2 + 2x + 5 w przedziale 0,5 - 5,0\n\t3. exp(x) w przedziale 0,5 - 5,0\nTwoj wybor: ";
	int wybor;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
	{
		for (int i = 0; i < n + 1; ++i)
		{
			elementy[i] = 0.5 + i * (2.5 - 0.5) / n;
		}
		double wynik = prostakaty(2.5, 0.5, n, elementy, sinus);
		cout << "Wartosc calki metoda prostokatow: " << wynik << "\n";
		wynik = trapezy(2.5, 0.5, n, elementy, sinus);
		cout << "Wartosc calki metoda trapezow: " << wynik << "\n";
		wynik = parabole(2.5, 0.5, n, elementy, sinus);
		cout << "Wartosc calki metoda parabol: " << wynik << "\n";
		break;
	}
	case 2:
	{
		for (int i = 0; i < n + 1; ++i)
		{
			elementy[i] = 0.5 + i * (5.0 - 0.5) / n;
		}
		double wynik = prostakaty(5.0, 0.5, n, elementy, parabola);
		cout << "Wartosc calki metoda prostokatow: " << wynik << "\n";
		wynik = trapezy(5.0, 0.5, n, elementy, parabola);
		cout << "Wartosc calki metoda trapezow: " << wynik << "\n";
		wynik = parabole(5.0, 0.5, n, elementy, parabola);
		cout << "Wartosc calki metoda parabol: " << wynik << "\n";
		break;
	}
	case 3:
	{
		for (int i = 0; i < n + 1; ++i)
		{
			elementy[i] = 0.5 + i * (5.0 - 0.5) / n;
		}
		double wynik = prostakaty(5.0, 0.5, n, elementy, exp);
		cout << "Wartosc calki metoda prostokatow: " << wynik << "\n";
		wynik = trapezy(5.0, 0.5, n, elementy, exp);
		cout << "Wartosc calki metoda trapezow: " << wynik << "\n";
		wynik = parabole(5.0, 0.5, n, elementy, exp);
		cout << "Wartosc calki metoda parabol: " << wynik << "\n";
		break;
	}
	default:
		break;
	}
}

void zadanie2()
{
	cout << "Zadanie2:\n";
	cout << "Funkcja podcalkowa: exp(x) w przedziale 0,5 - 5,0\n";
	int przedzialy = 1000;
	vector <double> pomoc(3, 0);
	vector <vector <double>> wyniki(przedzialy, pomoc);
	ofstream czytaj("wynik.txt");
	for (double n = 1; n <= przedzialy; ++n)
	{
		vector <double> elementy(n + 1, 0);
		for (int i = 0; i < n + 1; ++i)
		{
			elementy[i] = 0.5 + i * (5.0 - 0.5) / n;
		}
		double wynik = prostakaty(5.0, 0.5, n, elementy, exp);
		wyniki[n - 1][0] = wynik;
		wynik = trapezy(5.0, 0.5, n, elementy, exp);
		wyniki[n - 1][1] = wynik;
		wynik = parabole(5.0, 0.5, n, elementy, exp);
		wyniki[n - 1][2] = wynik;
	}
	czytaj << "                   n" << "                    p" << "                    t" << "                    s" << "\n";
	int licz = 1;
	for (auto i : wyniki)
	{
		 czytaj << licz << " ";
		for (auto j : i)
		{
			czytaj << setprecision(15)<< j << " ";
		}
		czytaj << "\n";
		licz++;
	}
}

int main()
{
	zadanie1();
	//zadanie2();
}