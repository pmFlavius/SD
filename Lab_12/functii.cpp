#include <iostream>
#include "functii.h"

using namespace std;

void initQ(Queue &q)
{
    q.head=q.tail=0;
}
bool isEmptyQ(Queue &q)
{
    if(q.head==0 && q.tail==0)
        return 1;
    return 0;
}
void put(Queue &q,int val,int pri)
{
    nod *p=new nod;
    p->data=val;
    p->pri=pri;
    p->succ=0;
    if(isEmptyQ(q))
    {
        q.head=q.tail=p;
    }
    else
    {
        q.tail->succ=p;
        q.tail=p;
    }
}
int get(Queue &q)
{
    int maxim=-1;
    Queue p=q;
    while(p.head!=p.tail)
    {
        if(maxim<p.head->pri)
            maxim=p.head->pri;
        p.head=p.head->succ;
    }
    if(maxim<p.head->pri)
        maxim=p.head->pri;
    /*nod *prev=0,*r=q.head;
    int dereturnat;
    while(r)
    {
        if(r->data==maxim)
        {
            nod *ds=r;
            dereturnat=ds->data;
            prev->succ=r->succ;
            delete ds;
            ds=0;
            break;
        }
        r=r->succ;
        prev=r;
    }
    return dereturnat;*/
}

//Heap uri
void insertHeap(int heap[],int &n,int val)
{
    heap[++n]=val;
    int fiu=n;
    int parinte=n/2;
    while(parinte>=1)
    {
        if(heap[parinte]<heap[fiu])
        {
            swap(heap[fiu],heap[parinte]);
            fiu=parinte;
            parinte=parinte/2;
        }
        else
            parinte=0;
    }
}

int removeHeap(int heap[],int &n)
{
    if(!n)
    {
        perror("Heap gol");
        exit(EXIT_FAILURE);
        return -1;
    }
    int maxim=heap[1];
    heap[1]=heap[n];
    n--;
    int fiu=2;
    int parinte=1;
    while(fiu<=n)
    {
        int fiustanga=parinte*2;
        int fiudreapta=parinte*2+1;
        
        if(fiudreapta<=n && heap[fiustanga]<heap[fiudreapta])
        {
            fiu=fiudreapta;
        }
        else
            fiu=fiustanga;
        if(heap[parinte]<heap[fiu])
        {
            swap(heap[parinte],heap[fiu]);
            parinte=fiu;
            fiu=fiu*2;
        }
        else
            fiu=n+1;
    }
    return maxim;
}

void buildHeap2(int heap[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        retro(heap, n, i);
    }
}

void retro(int heap[], int n, int i)
{
    int parinte = i;
    int fiu = 2 * i;
    while (fiu <= n)
    {
        int FiuStanga = 2 * parinte;
        int FiuDreapta = 2 * parinte + 1;

        if ((FiuDreapta <= n) && (heap[FiuStanga] < heap[FiuDreapta]))
        {
            fiu = FiuDreapta;
        }
        else
        {
            fiu = FiuStanga;
        }
        if (heap[parinte] < heap[fiu])
        {
            int aux = heap[parinte];
            heap[parinte] = heap[fiu];
            heap[fiu] = aux;
            parinte = fiu;
            fiu = fiu * 2;
        }
        else
            fiu = n + 1;
    }
}