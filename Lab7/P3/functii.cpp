#include <iostream>
#include <cstring>
#include "functii.h"

using namespace std;

unsigned int h(char *key)
{
    int i = 0, sum = 0;
    while (key[i])
    {
        char c = key[i];

        if (c >= 'A' && c <= 'Z')
            sum += c - 'A' ;
        else if (c >= 'a' && c <= 'z')
            sum += c - 'a' ;

        i++;
    }
    return (sum % M);
}

char toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}
bool estelitera(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
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
        HT[hash]->cnt=1;
    }
    else
    {
        HT[hash]->cnt++;
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
    char s = 'A';
    for (int i = 0; i < M; i++)
    {
        cout << s << (char)(s + 32) << ": ";
        s++;
        if(!HT[i])
            cout<<"0";
        else
            cout << HT[i]->cnt;
        cout << endl;
    }
}