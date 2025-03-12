#ifndef FUNCTII_H_
#define FUNCTII_H_

struct Nod{
    int data;
    Nod *pred,*succ;
};

void insert(Nod *&cap,int val);
void insertlist(Nod *&cap);
void parcurgere(Nod *cap);
void inserare(Nod *&cap,int nr,int k);
void stergere(Nod *&cap,int k);

#endif