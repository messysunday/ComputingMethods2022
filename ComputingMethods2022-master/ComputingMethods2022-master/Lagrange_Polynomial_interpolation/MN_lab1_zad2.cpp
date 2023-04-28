#include <iostream>
#include <vector>

using namespace std;

/*int main()
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
	for (int i = 0; i < n; ++ i)
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
	return 0;
}*/