#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double funkcja1(double x)
{
	double wyn = 0.0;
	wyn = (-1.0) * pow(x, 3) + 10.0 * x + 5;
	return wyn;
}
double funkcja1_pochodna(double x)
{
	double wyn = 0.0;
	wyn = (-3.0) * pow(x, 2) + 10.0;
	return wyn;
}

double funkcja2(double x)
{
	double wyn = 0.0;
	wyn = (x - 3) * (x - 3);
	return wyn;
}
double funkcja2_pochodna(double x)
{
	double wyn = 0.0;
	wyn = 2 * x - 6;
	return wyn;
}

double funkcja3(double x)
{
	double wyn = 0.0;
	wyn = pow(x, 2) - 2.0;
	return wyn;
}
double funkcja3_pochodna(double x)
{
	double wyn = 0.0;
	wyn = 2.0 * x;
	return wyn;
}

double funkcja4(double x)
{
	double wyn = 0.0;
	wyn = pow(3, x) - 9;
	return wyn;
}

double funkcja4_pochodna(double x)
{
	return log(3) * pow(3, x);
}

double funkcja5(double x)
{
	return pow(x, 3.0) - 20;
}

double funkcja5_pochodna(double x)
{
	return 3 * pow(x, 2);
}

double metoda_stycznych(double & x, double (f)(double), double(f_poch)(double), int n)
{
	if (n == 5)
	{
		return x;
	}
	else
	{
		n++;
		x = x - f(x) / f_poch(x);
		cout << n << ": " <<setprecision(15) <<  x << "\n";
		metoda_stycznych(x, f, f_poch, n);
	}
}

double metoda_siecznych(double& x1, double & x0, double (f)(double), int n)
{
	if (n == 5)
	{
		return x1;
	}
	else
	{
		n++;
		double x1_kopia = x1;
		x1 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
		x0 = x1_kopia;
		cout << n << ": xk = " << x1 << ", xk-1 = " << x0 << "\n";
		metoda_siecznych(x1, x0, f, n);
	}
}

int main()
{
	double a = 0.5;
	cout << setprecision(15) << metoda_stycznych(a, funkcja4, funkcja4_pochodna, 0);
}