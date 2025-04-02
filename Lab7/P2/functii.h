#ifndef FUNCTII_H_
#define FUNCTII_H_

#define M 87

struct Nod
{
    char *key;
    Nod *succ;
};

unsigned int h1(char *key);
unsigned int h2(char *key);
unsigned int h3(char *key);
float GC(Nod *HT[]);
void init(Nod *HT[]);
void insert(Nod *HT[], char *cheie, unsigned int (*pf)(char *));
Nod *find(Nod *HT[], char *cheie,unsigned int (*pf)(char *));
void remove(Nod *HT[], char *cheie,unsigned int (*pf)(char *));
void afisareHT(Nod *HT[]);
void deleteHT(Nod *HT[]);
#endif