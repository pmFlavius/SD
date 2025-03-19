#ifndef FUNCTII_H_
#define FUNCTII_H_

struct Nod{
    int index;
    Nod *succ;
};

void inserare(Nod *&cap,int n);
void afisare(Nod *cap);
int executare(Nod *&cap,int p0,int m);
int pozinit(int n, int m, int X);
#endif