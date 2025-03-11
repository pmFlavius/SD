#include <iostream>
#include "functii.h"

using namespace std;

int main()
{
    int x,nr,k;
    Nod *p=0;
    CreateList(p);
    afisare(p);
    //cautare x in lista
    cin>>x;
    cautare(p,x);
    //inserare numar in lista pe o pozitie k
    cin>>nr>>k;
    inserare(p,nr,k);
    afisare(p);
    //stergere element pe pozitia k
    cin>>k;
    stergere(p,k);
    afisare(p);
    //afisare element pozitia k de la sfarsit la inceput
    cin>>k;
    afisareK(p,k);
    //verifbucla
    if(bucla(p)==1)
        cout<<endl<<"Lista are bucle"<<endl;
    else
        cout<<endl<<"Liste nu are bucle"<<endl;
    //mijlocul
    cout<<endl<<"Elementul din mijlocul listei este: "<<mijloc(p)<<endl;
    //inversare
    inversare(p);
    afisare(p);
    cout<<endl<<"Elementele listei afisate de la coada la cap sunt: ";
    parcurgere2(p);
    dealocare(p);
    return 0;
}