#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

constexpr auto e = 2.718281828459;

double rownanie(double x, double y)
{
	double dy = -1 * pow(10, -12) * (pow(y, 4) - 0);
	return dy;
}

double rozwiazanie(double x)
{
	double wyn = 30000.0 / pow((81 * x + 15625), (double)(1.0 / 3.0));
	return wyn;
}

double Euler(int n, double x, double x0, double y0, double (f)(double, double))
{
	double h = abs(x - x0) / n;
	for (int i = 0; i < n; ++i)
	{
		double pomoc = f(x0, y0);
		x0 += h;
		y0 += h * pomoc;
	}
	return y0;
}

double RK2(int n, double x, double x0, double y0, double (f)(double, double))
{
	double h = abs(x - x0) / n;
	for (int i = 0; i < n; ++i)
	{
		double k1 = f(x0, y0);
		double k2 = f(x0 + h, y0 + h * k1);
		x0 += h;
		y0 += h * (double)(1.0 / 2.0) * (k1 + k2);

	}
	return y0;
}

double RK4(int n, double x, double x0, double y0, double (f)(double, double))
{
	double h = abs(x - x0) / n;
	for (int i = 0; i < n; ++i)
	{
		double k1 = f(x0, y0);
		double k2 = f(x0 + 1.0 / 2.0 * h, y0 + 1.0 / 2.0 * h * k1);
		double k3 = f(x0 + 1.0 / 2.0 * h, y0 + 1.0 / 2.0 * h * k2);
		double k4 = f(x0 + h, y0 + h * k3);
		x0 += h;
		y0 += h * (double)(1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);

	}
	return y0;
}

int main()
{
	int n1 = 10;
	double y1 = 1200;
	double x1 = 0.0;
	double punkt1 = 300.0;
	cout << "Rozwiazanie rzeczywiste f1 w punkcie x = " << punkt1 << ": " << rozwiazanie(punkt1) << "\n";
	cout << "Rozwiazanie metoda eulera dla f1 w punkcie x = " << punkt1 << " dla N = " << n1 << " i warunku poczatkowego y(0) = " << y1;
	cout << " to: " << Euler(n1, punkt1, x1, y1, rownanie) << "\n";
	cout << "Rozwiazanie metoda RK2 dla f1 w punkcie x = " << punkt1 << " dla N = " << n1 << " i warunku poczatkowego y(0) = " << y1;
	cout << " to: " << RK2(n1, punkt1, x1, y1, rownanie) << "\n";
	cout << "Rozwiazanie metoda RK4 dla f1 w punkcie x = " << punkt1 << " dla N = " << n1 << " i warunku poczatkowego y(0) = " << y1;
	cout << " to: " << RK4(n1, punkt1, x1, y1, rownanie) << "\n";
	vector <double> pomoc(3, 0.0);
	vector <vector <double>> tabela(1000, pomoc);
	for (int i = 0; i < 1000; ++i)
	{
		tabela[i][0] = Euler(i + 1, punkt1, x1, y1, rownanie);
		tabela[i][1] = RK2(i + 1, punkt1, x1, y1, rownanie);
		tabela[i][2] = RK4(i + 1, punkt1, x1, y1, rownanie);
	}
	cout << setw(15) << right << "              n             E 1           RK2 1           RK4 1\n";
	for (int i = 0; i < 1000; ++i)
	{
		cout << setw(15) << right << i + 1 << " ";
		for (auto j : tabela[i])
		{
			cout << setw(15) << right << j << " ";
		}
		cout << "\n";
	}
}