#ifndef HEADER_H_
#define HEADER_H_

struct AVL{
    int data;
    int bf;
    AVL *stg,*drt;
};

void inordine(AVL *a);
void RSS(AVL *&a);
void RSD(AVL *&a);
void RDD(AVL *&a);
void RDS(AVL *&a);
void Echilibrare(AVL *&a, int x,bool stg);
void inserare(AVL *&a,int x);
void inserare(AVL *&a,int x);
AVL *MakeNodAVL(int x);
void init(AVL *&a);
void dealocare(AVL *&a);
void afisarearbore(AVL *a,int nivel);

#endif