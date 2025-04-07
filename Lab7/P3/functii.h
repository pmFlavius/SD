#ifndef FUNCTII_H_
#define FUNCTII_H_

#define M 26

struct Nod{
    char *key;
    int cnt;
    Nod *succ;
};

unsigned int h(char *key);
char toupper(char c);
bool estelitera(char c);
void init(Nod *HT[]);
void insert(Nod *HT[],char *cheie);
Nod *find(Nod *HT[],char *cheie);
void remove(Nod *HT[],char *cheie);
void afisareHT(Nod *HT[]);

#endif