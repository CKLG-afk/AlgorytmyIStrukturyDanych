#include <iostream>

using namespace std;

double silnia(double);
double finbonacci_r(double);

int main()
{
    double n;
    cout << "Podaj numer silni oraz ilosc wyrazow ciagu finbonacciego: ";
    cin >> n;
    cout << "Wartosc silni wynosi: " <<silnia(n) << endl;
    cout << "wartosc ciagu finbonacciego o " << n << " wyrazach wynosi: " << finbonacci_r(n);
    return 0;
}
double silnia(double s)
{
    if (s==0.0)
    {
        return 1.0;
    }
    else
    {
        return s * silnia(s-1.0);
    }
}
double finbonacci_r(double f)
{
    if (f==0.0)
    {
        return 0.0;
    }
    if (f==1.0)
    {
        return 1.0;
    }
    else
    {
        return  finbonacci_r(f-1.0)+ finbonacci_r(f-2.0);
    }
}
