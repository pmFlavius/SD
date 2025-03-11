#ifndef FUNCTII_H_
#define FUNCTII_H_

struct Nod{
    int data;
    Nod* succ;
};

void insert(Nod *&cap,int val);
void CreateList(Nod *&cap);
void afisare(Nod *cap);
void cautare(Nod *cap,int x);
void inserare(Nod *&cap,int nr,int k);
void stergere(Nod *&cap, int k);
void afisareK(Nod *cap,int k);
void parcurgere2(Nod *cap);
bool bucla(Nod *p);
int mijloc(Nod *p);
void inversare(Nod *&cap);
void dealocare(Nod *&p);
#endif