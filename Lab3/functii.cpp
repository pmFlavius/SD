#include <iostream>
#include "functii.h"
using namespace std;
void insert(Nod *&cap,int val)
{
    Nod *p=new Nod;
    p->data=val;
    p->succ=cap;
    cap=p;
}
void CreateList(Nod *&cap)
{
    int x;
    cout<<"Citeste lista (0-stop) ";
    cin>>x;
    while(x)
    {
        insert(cap,x);
        cin>>x;
    }
}
void afisare(Nod *cap)
{
    Nod *p=cap;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->succ;
    }
    cout<<endl;
}
void cautare(Nod *cap,int x)
{
    Nod *p=cap;
    int cnt=1;
    while(p)
    {
        if(x==p->data)
        {
            cout<<"Elementul "<<x<<" se gaseste in lista pe pozitia "<<cnt<<endl<<endl;
            return;
        }
        cnt++;
        p=p->succ;
    }
}
void inserare(Nod *&cap,int nr,int k)
{
    Nod *p=cap,*q=0;
    int cnt=1;
    while(p && cnt<k-1)
    {
        p=p->succ;
        cnt++;
    }
    q=new Nod;
    q->data=nr;
    q->succ=p->succ;
    p->succ=q;

}
void stergere(Nod *&cap,int k)
{
    Nod *p=cap,*q=0;
    int cnt=1;
    while(p && cnt < k-1)
    {
        p=p->succ;
        cnt++;
    }
    q=p->succ;
    p->succ=q->succ;
    delete q;
    q=0;

}
void afisareK(Nod *cap,int k)
{
    Nod *p=cap,*q=cap;
    for(int i=1;i<=k;i++)
    {
        if(!p)
        {
            cout<<"Lista este mai scurta decat k ";
        }
        p=p->succ;
    }
    while(p)
    {
        p=p->succ;
        q=q->succ;
    }
    cout<<"Elementul de pe pozitia k numarat de la coada la capat este "<<q->data<<endl;
}
void parcurgere2(Nod *cap)
{
    if(!cap)
        return;
    parcurgere2(cap->succ);
    cout<<cap->data<<" ";

}
bool bucla(Nod *cap)
{
    Nod *p=cap;
    while(p)
    {
        p=p->succ;
        if(p==cap)
            return 1;
    }
    return 0;
}
int mijloc(Nod *cap)
{
    Nod *p=cap,*q=cap;
    while(p && p->succ)
    {
        p=p->succ->succ;
        q=q->succ;
    }
    return q->data;
}
void inversare(Nod *&cap)
{
    Nod *prec=0,*p=cap,*next=0;
    while(next)
    {
        next=p->succ;
        p->succ=prec;
        prec=p;
        p=next;
    }
    p=prec;
}
void dealocare(Nod *&cap)
{
    Nod *p=cap,*q=0;
    while(p)
    {
        q=p->succ;
        delete p;
        p=q;
    }
    cap=0;
}