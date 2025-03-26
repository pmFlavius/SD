#include <iostream>
#include "functii.h"

using namespace std;

// coada statica
int nextPoz(int index)
{
    if (index < DIM_MAX - 1)
        return index + 1;
    return 0;
}
bool isFull(const queue &q)
{
    if (nextPoz(q.tail) == q.head)
        return 1;
    return 0;
}
bool isEmpty(const queue &q)
{
    if (q.head == q.tail)
        return 1;
    return 0;
}
void init(queue &q)
{
    q.head = 0;
    q.tail = 0;
}
int front(const queue &q)
{
    if (!isEmpty(q))
    {
        return q.vect[q.head];
    }
    return -1;
}
int get(queue &q)
{
    int aux;
    if (!isEmpty(q))
    {
        aux = q.vect[q.head];
        q.head = nextPoz(q.head);
        return aux;
    }
    else
    {
        cout << "coada vida";
        return -1;
    }
}
void put(queue &q, int val)
{
    if (!isFull(q))
    {
        q.vect[q.tail] = val;
        q.tail = nextPoz(q.tail);
    }
    else
    {
        cout << "coada plina";
        return;
    }
}

// coada dinamica
void initQ(Queue &q)
{
    q.head = 0;
    q.tail = 0;
}
bool isEmptyQ(Queue q)
{
    if (q.head == 0 && q.tail == 0)
        return 1;
    return 0;
}
void putQ(Queue &q, int val)
{
    Nod *p = new Nod;
    p->data = val;
    p->succ = 0;
    if (!isEmptyQ(q))
    {
        q.tail->succ = p;
        q.tail = p;
    }
    else
    {
        q.head = q.tail = p;
    }
}
void getQ(Queue &q)
{
    if (isEmptyQ(q))
    {
        cout << "Coada vida";
        return;
    }
    else
    {
        
        if (q.head == q.tail)
        {
            q.head = 0;
            q.tail = 0;
        }
        else
        {
            Nod *p = q.head;
            q.head = q.head->succ;
            cout << "A fost eliminat elementul " << p->data<<endl;
            delete p;
        }
    }
}
int frontQ(Queue q)
{
    if (isEmptyQ(q))
    {
        throw runtime_error("Eroare: coada vida");
    }
    else
    {
        return q.head->data;
    }
}