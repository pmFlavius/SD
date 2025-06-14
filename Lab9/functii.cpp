#include <iostream>
#include "functii.h"

using namespace std;

void init(Nod *&rad)
{
    rad->stg = rad->drt = 0;
}

void inserare(Nod *&rad, int val)
{
    if (!rad)
    {
        rad = new Nod;
        rad->data = val;
        rad->stg = 0;
        rad->drt = 0;
        return;
    }
    else
    {
        if (val < rad->data)
        {
            inserare(rad->stg, val);
        }
        else if (val > rad->data)
        {
            inserare(rad->drt, val);
        }
    }
}

bool cautare(Nod *rad, int val)
{
    if (!rad)
        return 0;
    if (rad->data == val)
        return 1;
    else
    {
        if (val < rad->data)
            return cautare(rad->stg, val);
        else
            return cautare(rad->drt, val);
    }
    return 0;
}
void inordine(Nod *rad)
{
    if (rad)
    {
        inordine(rad->stg);
        cout << rad->data << " ";
        inordine(rad->drt);
    }
}
void preordine(Nod *rad)
{
    if (rad)
    {
        cout << rad->data << " ";
        preordine(rad->stg);
        preordine(rad->drt);
    }
}
void postordine(Nod *rad)
{
    if (rad)
    {
        postordine(rad->stg);
        postordine(rad->drt);
        cout << rad->data << " ";
    }
}
void stergere(Nod *&rad, int val)
{
    if (!rad)
    {
        return;
    }
    if (val < rad->data)
    {
        stergere(rad->stg, val);
    }
    else if (val > rad->data)
    {
        stergere(rad->drt, val);
    }
    else
        Deleteroot(rad);
}

void Deleteroot(Nod *&rad)
{
    if (!rad->stg)
    {
        Nod *p = rad->drt;
        delete rad;
        rad = p;
    }
    else
    {
        if (!rad->drt)
        {
            Nod *p = rad->stg;
            delete rad;
            rad = p;
        }
        else
        {
            Nod *p = RemoveGreatest(rad->stg);
            p->stg = rad->stg;
            p->drt = rad->drt;
            delete rad;
            rad = p;
        }
    }
}

Nod *RemoveGreatest(Nod *&rad)
{
    if (rad->drt)
    {
        return RemoveGreatest(rad->drt);
    }
    else
    {
        Nod *p = rad;
        rad = rad->stg;
        return p;
    }
}

bool cautareIterativ(Nod *rad, int val)
{
    Nod *p = rad;
    while (p)
    {
        if (p->data == val)
            return 1;
        else if (val < p->data)
        {
            p = p->stg;
        }
        else if (val > p->data)
        {
            p = p->drt;
        }
    }
    return 0;
}

void inserareIterativ(Nod *&rad, int val)
{

    Nod *p = rad;
    while (p->stg || p->drt)
    {
        if (val < p->data)
        {
            p = p->stg;
        }
        else if (val > p->data)
        {
            p = p->drt;
        }
    }
    if (val < p->data)
    {
        Nod *q = new Nod;
        p->stg = q;
        q->data = val;
        q->stg = q->drt = 0;
    }
    if (val > p->data)
    {
        Nod *q = new Nod;
        p->drt = q;
        q->data = val;
        q->stg = q->drt = 0;
    }
}

/*void stergereIterativ(Nod *&rad, int val)
{
    Nod *p = rad;
    if (!p)
    {
        return;
    }
    while (p)
    {
        if (p->data > val)
            p = p->stg;
        else if (p->data < val)
            p = p->drt;
        else
        {
            Deleteroot(p);
            break;
        }
    }
}*/
