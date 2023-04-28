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

double expo(double x)
{
	double e = 2.718281828459;
	return (pow(e, x));
}

void cztery_wezly(double a, double b, double (f)(double))
{
	vector <double> wagi;
	double a1 = 1.0 / 36.0 * (18.0 - sqrt(30.0));
	double a2 = 1.0 / 36.0 * (18.0 + sqrt(30.0));
	wagi.push_back(a1);
	wagi.push_back(a2);
	wagi.push_back(a2);
	wagi.push_back(a1);
	vector <double> wezly;
	double x1 = (-1.0) / 35.0 * sqrt(525.0 + 70.0 * sqrt(30.0));
	double x2 = (-1.0) / 35.0 * sqrt(525.0 - 70.0 * sqrt(30.0));
	wezly.push_back(x1);
	wezly.push_back(x2);
	wezly.push_back(-1.0*x2);
	wezly.push_back(-1.0*x1);
	vector <double> t(4, 0);
	for (int i = 0; i < 4; ++i)
	{
		t[i] = (a + b) / 2.0 + ((b - a) / 2.0) * wezly[i];
	}
	double wynik = 0.0;
	for (int i = 0; i < 4; ++i)
	{
		wynik += (b - a) / 2.0 * (wagi[i] * f(t[i]));
	}
	cout << "Wynik calkowania: " << wynik << "\n";
}

void dwa_wezly(double a, double b, double (f)(double))
{
	vector <double> wagi(2, 1.0);
	double x1 = (-1) * sqrt(3.0) / 3.0;
	double x2 = sqrt(3.0) / 3.0;
	double t1 = (a + b) / 2 + (b - a) / 2 * x1;
	double t2 = (a + b) / 2 + (b - a) / 2 * x2;
	double wynik = (b - a) / 2.0 * (wagi[0] * f(t1) + wagi[1] * f(t2));
	cout << "Wynik calkowania: " << wynik << "\n";
}

int main()
{
	cout << "Cakluje funkcje: sin(x) w przedziale 0,5 - 2,5\n\t-Kwadratura dwuwezlowa: ";
	dwa_wezly(0.5, 2.5, sinus);
	cout << "\t-Kwadratura czterowezlowa: ";
	cztery_wezly(0.5, 2.5, sinus);
	cout << "Calkuje funkcje: x^2 + 2x + 5 w przedziale 0,5 - 5,0\n\t-Kwadratura dwuwezlowa: ";
	dwa_wezly(0.5, 5.0, parabola);
	cout << "\t-Kwadratura czterowezlowa: ";
	cztery_wezly(0.5, 5.0, parabola);
	cout << "Calkuje funkcje: exp(x) w przedziale 0,5 - 5,0\n\t-Kwadratura dwuwezlowa: ";
	dwa_wezly(0.5, 5.0, expo);
	cout << "\t-Kwadratura czterowezlowa: ";
	cztery_wezly(0.5, 5.0, expo);

	
}
