#include <iostream>

using namespace std;

int suma_cyfr(int);
int najmniejsza_wartosc(int *);
int najwieksza_wartosc(int *);
int index_najmniejsza_wartosc(int *);
int index_najwieksza_wartosc(int *);
void najmniejsza_wiersz(int [4][4]);
void najmniejsza_kolumna(int A[4][4]);
void transponowana(int A[4][4]);
double iloczynKwadratowOdwrotnejPrzekatnej(double tablica[4][4]);
int ilemniejszych (char *);
void zamiana(int *);
double sumaKwadratow(double A[4][4]);
int ilosc_cyfr(char*);
int main()
{
    int tablica[7] = {1,5,8,3,4,97,243};
    int tablicaB[4][4]= {
                        {1,2,546,5},
                        {0,5,6,7},
                        {45,65,26,70},
                        {10,521,67,75}
                        };
    double tablicaC[4][4]= {
                        {1.0,2.0,546.0,1.0},
                        {0.0,5.0,5.0,7.0},
                        {45.0,1.0,1.0,70.0},
                        {1.0,521.0,67.0,1.0}
                        };
    int liczba;
    char * tekst = "SProbujmy cos napisac";
       cout << "Podaj liczbe: ";
    cin >> liczba;
    if (liczba<0)
    {
        cout << "Podales zla liczbe! Podaj liczbe dodatnia!" << endl;
    }
    else
    {
        cout << "Suma cyfr wynosi: " << suma_cyfr(liczba) << endl;
    }
    cout << "Znajdzmy najmniejsza wartosc tablicy:" << endl;
    cout << "Najmniejsza wartosc wynosi: " << najmniejsza_wartosc(tablica) << endl;
    cout << "Jej indeks wynosi: " << index_najmniejsza_wartosc(tablica) << endl;
    cout << "Znajdzmy najwieksza wartosc tablicy:" << endl;
    cout << "najwieksza wartosc wynosi: " << najwieksza_wartosc(tablica) << endl;
    cout << "Jej indeks wynosi: " << index_najwieksza_wartosc(tablica) << endl;
    najmniejsza_wiersz(tablicaB);
    najmniejsza_kolumna(tablicaB);
    transponowana(tablicaB);
    cout << "iloczyn kwadratow przekatnej wynosi: " << iloczynKwadratowOdwrotnejPrzekatnej(tablicaC) << endl;
    cout << "liczba malych liter wynosi: " << ilemniejszych(tekst) << endl;
    zamiana(tablica);
    cout << endl << "suma kwadratow wynosi: " << sumaKwadratow(tablicaC) << endl ;
    cout << "ilosc cyfr w tekscie wynosi: " << ilosc_cyfr(tekst) << endl;
    return 0;
}

int suma_cyfr(int liczba)
{
    int suma=0;
    while(liczba>0)
    {
        suma += liczba%10;
        liczba/=10;
    }
    return suma;
}
int najmniejsza_wartosc(int A[7])
{
    int mini=A[1];
    for (int i=0; i<7;i++)
    {
        if (A[i]<=mini)
        {
            mini = A[i];
        }
    }
    return mini;
}
int index_najmniejsza_wartosc(int A[7])
{
    int mini=A[0];
    int indeks=0;
    for (int i=0; i<7;i++)
    {
        if (A[i]<=mini)
        {
            indeks=i+1;
        }
    }
    return indeks;
}
int najwieksza_wartosc(int A[7])
{
    int maks=A[1];
    for (int i=0; i<7;i++)
    {
        if (A[i]>=maks)
        {
            maks = A[i];
        }
    }
    return maks;
}
int index_najwieksza_wartosc(int A[7])
{
    int maks=A[1];
    int indeks=0;
    for (int i=0; i<7;i++)
    {
        if (A[i]>=maks)
        {
            indeks=i+1;
        }
    }
     return indeks;
}
void najmniejsza_wiersz(int A[4][4])
{

    for (int i = 0 ; i<4; i++)
    {
        int mini=A[i][0];
        int index_i=0;
        int index_j=0;
        for (int j = 0; j<4; j++)
        {
            if (mini>=A[i][j])
            {
                mini=A[i][j];
                index_i=i;
                index_j=j;
            }
        }
        cout << "Najmniejsza wartoscia w wierszu " << i << " jest: " << mini << " A jej indeks to: [" << index_i << "] [" << index_j <<"]" << endl;
    }
}
void najmniejsza_kolumna(int A[4][4])
{
    int index_i=0;
    int index_j=0;
    for (int j = 0 ; j<4; j++)
    {
        int mini=A[0][j];
        for (int i = 0; i<4; i++)
        {
            if (mini>=A[i][j])
            {
                mini=A[i][j];
                index_i=i;
                index_j=j;
            }
        }
        cout << "Najmniejsza wartoscia w kolumnie " << j << " jest: " << mini << " A jej indeks to: [" << index_j << "] [" << index_i <<"]" << endl;
    }
}
void transponowana(int A[4][4])
{
    int temp;
    for (int i=0;i<4;i++)
    {
        for (int j=i+1;j<4;j++)
        {
            temp = A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=temp;
        }
    }
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
double iloczynKwadratowOdwrotnejPrzekatnej(double tablica[4][4])
{
    double iloczyn=1.0;
    for (int i=0; i<4; i++)
    {
        iloczyn*=tablica[i][3-i]*tablica[i][3-i];
    }
    return iloczyn;
}
int ilemniejszych (char * tekst)
{
    int ilosc=0;
    while(*tekst)
    {
        if (*tekst>=97 && *tekst<=122)
        {
            ilosc++;
        }
        tekst++;
    }
    return ilosc;
}
void zamiana(int A[7])
{
    int temp = 0;
    for (int i=0; i<7/2; i++)
    {
        temp = A[i];
        A[i] = A[7-1-i];
        A[7-1-i] = temp;
    }
    for (int i=0;i<7;i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
double sumaKwadratow(double A[4][4])
{
    double suma=0;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (i==j)
            {
                suma+=A[i][j]*A[i][j];
            }
        }
    }
    return suma;
}
int ilosc_cyfr(char * tekst)
{
    int ilosc=0;
    while(*tekst)
    {
        if (*tekst>=48 && *tekst<=57)
        {
            ilosc++;
        }
        tekst++;
    }
    return ilosc;
}
