#ifndef FUNCTII_H_
#define FUNCTII_H_

struct Pozitie {
    int x, y;
};
struct nod{
    Pozitie poz;
    nod *succ;
};
struct queue{
    nod *head,*tail;
};
queue initq();
void put(queue &q,Pozitie a);
void get(queue &q);
bool isEmpty(queue q);
Pozitie front(queue q);

#endif