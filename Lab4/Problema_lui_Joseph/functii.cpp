#include <iostream>
#include "functii.h"

using namespace std;

void inserare(Nod *&cap, int n)
{
    Nod *ultim = 0;
    for (int i = 1; i <= n; i++)
    {
        Nod *p = new Nod;
        p->index = i;
        if (!cap)
        {
            cap = p;
            p->succ = cap;
            ultim = cap;
        }
        else
        {
            p->succ = cap;
            ultim->succ = p;
            ultim = p;
        }
    }
}
void afisare(Nod *cap)
{
    if (!cap)
        return;
    Nod *p = cap;
    do
    {
        cout << p->index << " ";
        p = p->succ;
    } while (p != cap);
}

int executare(Nod *&cap, int p0, int m)
{
    Nod *p = cap;
    Nod *anterior = 0;
    for (int i = 1; i < p0; i++)
    {
        anterior = p;
        p = p->succ;
    }
    if (!anterior)
    {
        anterior = cap;
        while (anterior->succ != cap)
        {
            anterior = anterior->succ;
        }
    }
    while (p->succ != p)
    {
        for (int i = 1; i < m; i++)
        {
            anterior = p;
            p = p->succ;
        }
        cout << "A fost eliminata persoana: " << p->index << endl;
        anterior->succ = p->succ;
        if (p == cap)
        {
            cap = p->succ;
        }
        delete p;
        p = anterior->succ;
        // n--;
    }
    cout << "\nPersoana care a ramas in viata este: " << p->index << endl;
    return p->index;
}
int pozinit(int n, int m, int X)
{
    for (int p0 = 1; p0 <= n; p0++)
    {
        Nod *cap = 0;
        inserare(cap, n);
        int supravietuitor = executare(cap, p0, m);
        if (supravietuitor == X)
            return p0;
    }
    return -1;
}