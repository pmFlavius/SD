#include <iostream>
#include <cstring>
#include <cmath>
#include "functii.h"

using namespace std;

unsigned int h1(char *key) // modulara
{
    int i = 0, sum = 0;
    while (key[i])
    {
        sum += key[i];
        i++;
    }
    return sum % M;
}

unsigned int h2(char *key) // prin inmultire
{
    int i = 0, sum = 0;
    while (key[i])
    {
        sum += key[i];
        i++;
    }
    float a = (sqrt(5) - 1) / 2;
    float nr = sum * a - floor(sum * a);
    return (int)floor(M * nr);
}

unsigned int h3(char *key) // Bernstein
{
    unsigned int h = 5381;
    char c;
    while (c = *key++)
    {
        h = (h << 5) + h + c;
    }
    return h%M;
}
void init(Nod *HT[])
{
    for (int i = 0; i < M; i++)
        HT[i] = NULL;
}
Nod *find(Nod *HT[], char *cheie,unsigned int (*pf)(char *))
{
    int hash = pf(cheie);
    Nod *p = HT[hash];
    while (p)
    {
        if (strcmp(cheie, p->key) == 0)
            return p;
        p = p->succ;
    }
    return NULL;
}
void insert(Nod *HT[], char *cheie,unsigned int (*pf)(char *))
{
    Nod *p = new Nod;
    p->key = new char[strlen(cheie) + 1];
    strcpy(p->key, cheie);
    p->succ = 0;
    int hash = pf(cheie);
    if (HT[hash] == NULL)
    {
        HT[hash] = p;
        p->succ = 0;
    }
    else
    {
        Nod *q = find(HT, cheie, pf);
        if (!q)
        {
            p->succ = HT[hash];
            HT[hash] = p;
        }
        else
        {
            cout << "Elementul se afla deja n lista";
            return;
        }
    }
}

void remove(Nod *HT[], char *cheie,unsigned int (*pf)(char *))
{
    int hash = pf(cheie);
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
    for (int i = 0; i < M; i++)
    {
        Nod *p = HT[i];
        cout << "Linia " << i << ": ";
        while (p)
        {
            cout << p->key << " ";
            p = p->succ;
        }
        cout << endl;
    }
}

float GC(Nod *HT[])
{
    int N=87;
    float alpha=(float)N/M,sum=0;
    for(int i=0;i<M;i++)
    {
        Nod *p=HT[i];
        int cnt=0;
        while(p)
        {
            cnt++;
            p=p->succ;
        }
        sum+=(float)(cnt*cnt)/N;
    }
    return sum-alpha;
}

void deleteHT(Nod *HT[])
{
    for(int i = 0; i < M; i++)
    {
        Nod *p = HT[i];
        while (p)
        {
            Nod *q = p;
            p = p->succ;
            delete q;
        }
        HT[i] = 0;
    }
}
