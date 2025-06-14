#include <iostream>
#include <cstring>
#include "functii.h"

using namespace std;

unsigned int h(char *key)
{
    int i = 0, sum = 0;
    while (key[i])
    {
        sum += key[i];
        i++;
    }
    return sum % M;
}

void init(Nod *HT[])
{
    for (int i = 0; i < M; i++)
        HT[i] = NULL;
}
Nod *find(Nod *HT[], char *cheie)
{
    int hash = h(cheie);
    Nod *p = HT[hash];
    while (p)
    {
        if (strcmp(cheie, p->key) == 0)
            return p;
        p = p->succ;
    }
    return NULL;
}
void insert(Nod *HT[], char *cheie)
{
    Nod *p = new Nod;
    p->key = new char[strlen(cheie) + 1];
    strcpy(p->key, cheie);
    p->succ = 0;
    int hash = h(cheie);
    if (HT[hash] == NULL)
    {
        HT[hash] = p;
        p->succ = 0;
    }
    else
    {
        Nod *q = find(HT, cheie);
        if (!q)
        {
            p->succ = HT[hash];
            HT[hash] = p;
        }
        else
        {
            cout << "Elementul se afla deja n lista";
            delete p;
            return;
        }
    }
}

void remove(Nod *HT[], char *cheie)
{
    int hash = h(cheie);
    Nod *p = HT[hash], *prev = 0;
    while (p && strcmp(p->key, cheie) != 0)
    {
        prev = p;
        p = p->succ;
    }
    if (!p)
    {
        cout << "Elementul nu exista\n";
        return;
    }
    if (prev == 0)
    {
        HT[hash] = p->succ;
    }
    else
    {
        prev->succ = p->succ;
    }
    delete[] p->key;
    delete p;
}

void afisareHT(Nod *HT[])
{
    for(int i=0;i<M;i++)
    {
        Nod *p=HT[i];
        cout<<"Linia "<<i<<": ";
        while(p)
        {
            cout<<p->key<<" ";
            p=p->succ;
        }
        cout<<endl;
    }
}
