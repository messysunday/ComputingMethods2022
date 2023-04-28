#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

double alfa(int j, vector <pair<double, double>>& punkty, vector <double>& A, vector <double>& B);

double beta(int j, vector <pair <double, double>>& punkty, vector <double>& A, vector <double>& B);

double fi(int j, double x, vector <pair <double, double>>& punkty, vector <double>& A, vector <double>& B);

double s(int n, int k, vector <pair <double, double>> & punkty, vector <double>& A, vector <double>& B)
{
    double wynik = 0.0;
    for (int i = 0; i <= n; ++i)
    {
        wynik += pow(fi(k, punkty[i].first, punkty, A, B), 2);
    }
    return wynik;
}

double c(vector <pair <double, double>>& punkty, int n, int k, vector <double>& A, vector <double>& B)
{
    double wynik = 0.0;
    for (int i = 0; i <= n; ++i)
    {
        wynik += punkty[i].second * fi(k, punkty[i].first, punkty, A, B);
    }
    return wynik;
}

int main()
{
    int m = 1; //stopien wielomianu
    int wezly = 8;
    int n = wezly - 1;
    vector <double> F(n + 1, 0.0);
    vector <double> Alfa(m + 1, 10000000);
    vector <double> Beta(m + 1, 10000000);
    vector <double> C(m + 1, 0);
    vector <double> S(m + 1, 0);
    vector <double> B(m + 1, 0);
    vector <double> pomoc(m + 1, 0.0);
    vector <vector <double>> macierz(n + 1, pomoc); //macierz
    vector <pair <double, double>> punkty;
    /*punkty.push_back(make_pair(1.0, 2.0));
    punkty.push_back(make_pair(2.0, 4.0));
    punkty.push_back(make_pair(3.0, 3.0));
    punkty.push_back(make_pair(4.0, 5.0));
    punkty.push_back(make_pair(5.0, 6.0));
    punkty.push_back(make_pair(6.0, 9.0));
    punkty.push_back(make_pair(7.0, 11.0));
    punkty.push_back(make_pair(8.0, 11.0));*/
    punkty.push_back(make_pair(2.0, 5.0));
    punkty.push_back(make_pair(3.5, 1));
    punkty.push_back(make_pair(4, 3.5));
    punkty.push_back(make_pair(8, 4));
    punkty.push_back(make_pair(10, 5));
    punkty.push_back(make_pair(11, 10));
    punkty.push_back(make_pair(16, 8));
    punkty.push_back(make_pair(16.5, 9));

    /*punkty.push_back(make_pair(1.0, 3.0));
    punkty.push_back(make_pair(1.5, 4.75));
    punkty.push_back(make_pair(2.0, 7.0));
    punkty.push_back(make_pair(2.5, 9.75));
    punkty.push_back(make_pair(3.0, 13.0));*/
    for (int i = 0; i <= n; ++i)
    {
        for (int k = 0; k <= m; ++k)
        {
            macierz[i][k] = fi(k, punkty[i].first, punkty, Alfa, Beta);
        }
    }
    for (int i = 0; i <= m; ++i)
    {
        C[i] = c(punkty, n, i, Alfa, Beta);
        S[i] = s(n, i, punkty, Alfa, Beta);
        B[i] = C[i] / S[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int k = 0; k <= m; ++k)
        {
            F[i] += B[k] * macierz[i][k]; //k - stopien
        }
    }
    cout << "Macierz F:\n";
    for (auto i : macierz)
    {
        for (auto j : i)
        {
            cout <<setw(10) <<right << j << " ";
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
        cout << setw(10) << right<< i << " ";
    }
    cout << "\nwspolczynnik B: ";
    for (auto i : B)
    {
        cout << setw(10) << right<< i << " ";
    }
    cout << "\nwspolczynnik Alfa: ";
    for (auto i : Alfa)
    {
        cout << setw(10) << right << i << " ";
    }
    cout << "\nwspolczynnik Beta: ";
    for (auto i : Beta)
    {
        cout << setw(10) << right << i << " ";
    }
    cout << "\nWartosci dla punktow:\n";
    for (int i = 0; i <= n; ++i)
    {
        cout << punkty[i].first << ": " << setw(10) << right<< F[i] << "\n";
    }
}

double alfa(int j, vector <pair<double, double>>& punkty, vector <double> & A, vector <double>& B)
{
    //if (A[j] == 10000000)
    {
        double Alfa1 = 0.0;
        double Alfa2 = 0.0;
        double Alfa = 0.0;
        for (auto i : punkty)
        {
            Alfa1 += i.first * pow(fi(j - 1, i.first, punkty, A, B), 2);
            Alfa2 += pow(fi(j - 1, i.first, punkty, A, B), 2);
        }
        Alfa = Alfa1 / Alfa2;
        A[j] = Alfa;
    }
    return A[j];
}

double beta(int j, vector <pair <double, double>>& punkty, vector <double>& A, vector <double>& B)
{
    if (B[j] == 10000000)
    {
        double Beta1 = 0.0;
        double Beta2 = 0.0;
        double Beta = 0.0;
        for (auto i : punkty)
        {
            Beta1 += i.first * (fi(j, i.first, punkty, A, B) * fi(j - 1, i.first, punkty, A, B));
            Beta2 += pow(fi(j - 1, i.first, punkty, A, B), 2);
        }
        Beta = Beta1 / Beta2;
        B[j] = Beta;
    }
    return B[j];
}

double fi(int j, double x, vector <pair <double, double>>& punkty, vector <double>& A, vector <double>& B)
{
    double Fi = 0.0;
    if (j == -1)
    {
        return 0;
    }
    else if (j == 0)
    {
        return 1;
    }
    else if (j == 1)
    {
        Fi = (x - alfa(j, punkty, A, B)) * fi(j - 1, x, punkty, A, B);
        return Fi;
    }
    else
    {
        Fi = (x - alfa(j, punkty, A, B)) * fi(j - 1, x, punkty, A, B) - beta(j - 1, punkty, A, B) * fi(j - 2, x, punkty, A, B);
        return Fi;
    }
}