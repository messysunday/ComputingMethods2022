#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double funkcja(double x)
{
	double wynik;
	wynik = cos(pow(x, 3) - 2 * x);
	return wynik;
}

double funkcja1(double x)
{
	double wyn = 0.0;
	wyn = (-1.0) * pow(x, 3) + 10.0 * x + 5;
	return wyn;
}

double funkcja2(double x)
{
	double wynik = 0.0;
	wynik = (x - 3.0) * (x + 3.0);
	return wynik;
}

double funkcja3(double x)
{
	double wyn = 0.0;
	wyn = pow(x, 2) - 2.0;
	return wyn;
}

double bisekcja(double a, double b, double epsilon, double (f)(double), int iteracje)
{
	iteracje++;
	double x0 = (double)(a + b) / 2.0;
	cout << right <<setw(3) << iteracje << setw(15) << a << setw(15) << b << setw(15) << f(a) << setw(15) << f(b) << setw(15) << x0 << setw(15) << f(x0) << setw(15) << f(a) * f(x0) << "\n";
	if (abs(f(x0)) < epsilon)
	{
		return x0;
	}
	else
	{
		if (f(x0) * f(a) < 0)
		{
			b = x0;
		}
		else
		{
			a = x0;
		}
		bisekcja(a, b, epsilon, f, iteracje);
	}
}

double falsi(double a, double b, double epsilon, double (f)(double), int iteracje)
{
	iteracje++;
	double x1 = a - (f(a)*(b - a))/(f(b) - f(a));
	cout << right << setw(3) << iteracje << setw(15) << a << setw(15) << b << setw(15) << f(a) << setw(15) << f(b) << setw(15) << x1 << setw(15) << f(x1) << setw(15) << f(a) * f(x1) << "\n";
	if (abs(f(x1)) < epsilon)
	{
		return x1;
	}
	else
	{
		if (f(x1) * f(a) < 0)
		{
			b = x1;
		}
		else
		{
			a = x1;
		}
		falsi(a, b, epsilon, f, iteracje);
	}
}

int main()
{
	//funkcja
	double a1 = 0.0;
	double b1 = 2.0;
	double epsilon1 = 0.0000001;
	/*cout << "Funkcja 1\nMETODA BISEKCJI:\n" << setw(3) << "n" << setw(15) << "a" << setw(15) << "b"
		<< setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15)
		<< "x0" << setw(15) << "f(x0)" << setw(15) << " f(a) * f(x0)\n";
	double wyn = bisekcja(a1, b1, epsilon1, funkcja, 0);
	a1 = 0.0;
	b1 = 2.0;
	epsilon1 = 0.01;
	cout << "METODA FALSI: \n" << setw(3) << "n" << setw(15) << "a" << setw(15) << "b"
		<< setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15)
		<< "x0" << setw(15) << "f(x0)" << setw(15) << " f(a) * f(x0)\n";
	wyn = falsi(a1, b1, epsilon1, funkcja, 0);
	system("pause");
	system("cls");
	//funkcja1
	a1 = 2.0;
	b1 = 6.0;
	epsilon1 = 0.01;
	cout << "Funkcja 2\nMETODA BISEKCJI:\n" << setw(3) << "n" << setw(15) << "a" << setw(15) << "b"
		<< setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15)
		<< "x0" << setw(15) << "f(x0)" << setw(15) << " f(a) * f(x0)\n";
	bisekcja(a1, b1, epsilon1, funkcja1, 0);
	a1 = 2.0;
	b1 = 6.0;
	epsilon1 = 0.01;
	cout << "METODA FALSI: \n" << setw(3) << "n" << setw(15) << "a" << setw(15) << "b"
		<< setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15)
		<< "x0" << setw(15) << "f(x0)" << setw(15) << " f(a) * f(x0)\n";
	falsi(a1, b1, epsilon1, funkcja1, 0);
	system("pause");
	system("cls");*/
	//funkcja2
	a1 = 2.0;
	b1 = 6.0;
	cout << "Funkcja 2\nMETODA BISEKCJI:\n" << setw(3) << "n" << setw(15) << "a" << setw(15) << "b"
		<< setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15)
		<< "x0" << setw(15) << "f(x0)" << setw(15) << " f(a) * f(x0)\n";
	bisekcja(a1, b1, epsilon1, funkcja2, 0);
	a1 = 2.0;
	b1 = 6.0;
	cout << "METODA FALSI: \n" << setw(3) << "n" << setw(15) << "a" << setw(15) << "b"
		<< setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15)
		<< "x0" << setw(15) << "f(x0)" << setw(15) << " f(a) * f(x0)\n";
	falsi(a1, b1, epsilon1, funkcja2, 0);
	system("pause");
	system("cls");
	//funkcja3
	a1 = 0.0;
	b1 = 2.0;
	cout << "Funkcja 3\nMETODA BISEKCJI:\n" << setw(3) << "n" << setw(15) << "a" << setw(15) << "b"
		<< setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15)
		<< "x0" << setw(15) << "f(x0)" << setw(15) << " f(a) * f(x0)\n";
	bisekcja(a1, b1, epsilon1, funkcja3, 0);
	a1 = 0.0;
	b1 = 2.0;
	cout << "METODA FALSI: \n" << setw(3) << "n" << setw(15) << "a" << setw(15) << "b"
		<< setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15)
		<< "x0" << setw(15) << "f(x0)" << setw(15) << " f(a) * f(x0)\n";
	falsi(a1, b1, epsilon1, funkcja3, 0);
	return 0;
}