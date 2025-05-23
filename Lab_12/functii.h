#ifndef FUNCTII_H_
#define FUNCTII_H_


//PQUEUE CU QUEUE NORMAL
struct nod{
    int data,pri;
    nod *succ;
};
struct Queue{
    nod *head,*tail;
};

void initQ(Queue &q);
void put(Queue &q,int val,int pri);
int get(Queue &q);
bool isEmptyQ(Queue &q);


//PQUEUE CU HEAP
const int DIM_MAX=100;

void insertHeap(int heap[],int &n,int val);
int removeHeap(int heap[],int &n);
void buildHeap2(int heap[],int n);
void retro(int heap[],int n,int i);

#endif