#ifndef FUNCTII_H_
#define FUNCTII_H_

struct Nod{
    int data;
    Nod *stg,*drt;
};

void init(Nod *&rad);
void inserare(Nod *&rad,int val);
void inordine(Nod *rad);
void preordine(Nod *rad);
void postordine(Nod *rad);
bool cautare(Nod *rad,int val);
void stergere(Nod *&rad,int val);
void Deleteroot(Nod *&rad);
Nod *RemoveGreatest(Nod *&rad);
bool cautareIterativ(Nod *rad,int val);
void inserareIterativ(Nod *&rad,int val);
void stergereIterativ(Nod *&rad,int val);

#endif
