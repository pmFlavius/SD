#include <iostream>
#include <algorithm>
#include "functii2.h"

using namespace std;

void inserare(Nod *&cap,int val)
{
    Nod *p=new Nod;
    p->data=val;
    if(cap==0)
    {
        p->succ=p;
        cap=p;
    }
    else
    {
        Nod *q=cap;
        while(q->succ!=cap)
        {
            q=q->succ;
        }
        p->succ=cap;
        q->succ=p;
        cap=p;
    }
}
void insertlist(Nod *&cap)
{
    int n;
    cout<<"Introduceti n (0-iesire)";
    cin>>n;
    while(n)
    {
        inserare(cap,n);
        cin>>n;
    }
}
void parcurgere(Nod *cap)
{
    Nod *p=cap;
    do
    {
        cout<<p->data<<" ";
        p=p->succ;
    } while (p!=cap);
    
}
void permutari(Nod *cap)
{
    Nod *p=cap;
    cout<<"\nPermutarile circulare ale listei sunt: \n";
    do
    {
       parcurgere(p);
       cout<<endl;
       p=p->succ;
    } while (p!=cap);
    
}
/*void inversare(Nod *&cap)
{
    Nod *curent=cap,*prec=0,*urm=0,*cap2=cap;
    do
    {
        urm=curent->succ;
        curent->succ=prec;
        prec=curent;
        curent=urm;
    } while (curent!=cap);
    cap->succ=prec;
    cap=prec;
}*/

