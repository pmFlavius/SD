#ifndef FUNCTII_H_
#define FUNCTII_H_

#define DIM_MAX 10


//coada statica(circulara)
struct queue{
    int head,tail;
    int vect[DIM_MAX];
};

void init(queue &q);
void put(queue &q,int val);
int get(queue &q);
int front(const queue &q);
bool isEmpty(const queue &q);
bool isFull(const queue &q);
int nextPoz(int index);

//coada dinamica

struct Nod{
    int data;
    Nod *succ;
};
struct Queue{
    Nod* head,*tail;
};

void initQ(Queue &q);
void putQ(Queue &q,int val);
void getQ(Queue &q);
int frontQ(Queue q);
bool isEmptyQ(Queue q);

#endif