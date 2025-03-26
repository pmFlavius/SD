#include <iostream>
#include "functii.h"

using namespace std;

queue initq()
{
    queue q;
    q.head = 0;
    q.tail = 0;
    return q;
}
bool isEmpty(queue q)
{
    if (q.head == 0 && q.tail == 0)
    {
        return 1;
    }
    return 0;
}
void put(queue &q, Pozitie a)
{
    nod *p = new nod;
    p->poz = a;
    p->succ = 0;
    if (!isEmpty(q))
    {
        q.tail->succ = p;
        q.tail = p;
    }
    else
    {
        q.tail = p;
        q.head = p;
    }
}
Pozitie front(queue q)
{
    if (!isEmpty(q))
    {
        return q.head->poz;
    }
    else
    {
        throw runtime_error("coada vida");
    }
}
void get(queue &q)
{
    if (isEmpty(q))
    {
        cout << "coada vida";
        return;
    }
    else
    {
        if(q.head==q.tail)
        {
            q.head=q.tail=0;
        }
        else
        {
            nod *p=q.head;
            q.head=p->succ;
            delete p;
        }
    }
}