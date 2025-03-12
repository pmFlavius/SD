#ifndef FUNCTII2_H_
#define FUNCTII2_H_

struct Nod{
    int data;
    Nod *succ;
};

void inserare(Nod *&cap,int val);
void insertlist(Nod *&cap);
void parcurgere(Nod *cap);
void permutari(Nod *cap);
void inversare(Nod *&cap);
#endif