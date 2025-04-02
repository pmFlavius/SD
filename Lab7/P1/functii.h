#ifndef FUNCTII_H_
#define FUNCTII_H_

#define M 87

struct Nod{
    char *key;
    Nod *succ;
};

int h(char *key);
void init(Nod *HT[]);
void insert(Nod *HT[],char *cheie);
Nod *find(Nod *HT[],char *cheie);
void remove(Nod *HT[],char *cheie);
void afisareHT(Nod *HT[]);
#endif