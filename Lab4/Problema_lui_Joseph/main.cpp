#include <iostream>
#include "functii.h"

using namespace std;

int main()
{
    Nod *p = 0;
    int n, var;
    cout << "\nAlege subpunctul problemei a-1, b-2 ";
    cin >> var;
    if (var == 1)
    {
        cout << "\nCititi numarul de persoane:  ";
        cin >> n;
        inserare(p, n);
        int p0, m;
        cout << "\nIntroduceti pozitia de inceput si pasul de eliminare: ";
        cin >> p0 >> m;
        executare(p, p0, m);
    }
    else if (var == 2)
    {
        int m, X;
        cout << "\nCititi numarul de persoane:  ";
        cin >> n;
        cout << "\nIntroduceti pasul de eliminare: ";
        cin >> m;
        cout << "Introduceti persoana pe care doresti sa o salvezi: ";
        cin >> X;
        int p0 = pozinit(n, m, X);
        if (p0 != -1)
            cout << "\nPentru a salva persoana " << X << ", trebuie sa incepi de la p0 = " << p0;
        else
            cout << "\nNu exista solutie valida!";
    }
    return 0;
}