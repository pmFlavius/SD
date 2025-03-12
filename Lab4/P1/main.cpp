#include <iostream>
#include "functii.h"
using namespace std;

int main()
{
    int nr,k;
    Nod *p=0;
    //creare lista
    insertlist(p);
    //parcurgere
    parcurgere(p);
    //inserare element in fata unei pozitii k
    cout<<"\nCititi numarul si pozitia dupa care sa fie adaugat: ";
    cin>>nr>>k;
    inserare(p,nr,k);
    cout<<"\n";
    parcurgere(p);
    //sterge element pozitie k
    cout<<"\n";
    cout<<"\nCititi pozitia de pe care sa fie sters: ";
    cin>>k; 
    stergere(p,k);
    parcurgere(p);
    return 0;
}