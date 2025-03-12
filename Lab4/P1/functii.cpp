#include <iostream>
#include "functii.h"

using namespace std;

void insert(Nod *&cap,int val)
{
    Nod *p=0;
    p=new Nod;
    if(cap==0)
    {
        cap=p;
        p->data=val;
        p->succ=0;
        p->pred=0;
    }
    else
    {
        p->data=val;
        p->succ=cap;
        p->pred=0;
        cap->pred=p;
        cap=p;
    }
    
}
void insertlist(Nod *&cap)
{
    int n;
    cout<<"Introduceti n: (0-iesire)";
    cin>>n;
    while(n)
    {
        insert(cap,n);
        cin>>n;
    }
}
void parcurgere(Nod *cap)
{
    Nod *p=cap;
    cout<<"\nLista parcursa de la stanga la dreapta este: ";
    while(p)
    {
        cout<<p->data<<" ";
        p=p->succ;
    }

}
void inserare(Nod *&cap,int nr,int k)
{
    int cnt=1;
    Nod *p=cap,*q=new Nod;
    while(p && cnt<k)
    {
        p=p->succ;
        cnt++;
    }
    q->data=nr;
    q->pred=p;
    q->succ=p->succ;
    p->succ=q;
    p->succ->pred=q;
}
void stergere(Nod *&cap,int k)
{
    int cnt=1;
    Nod *p=cap;
    while(p && cnt<k)
    {
        p=p->succ;
        cnt++;
    }
    p->pred->succ=p->succ;
    p->succ->pred=p->pred;
    cout<<"Numarul sters este: "<<p->data;
    delete p;
    p=0;
}