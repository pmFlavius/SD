#include <iostream>
#include "functii.h"

using namespace std;

int main()
{
    //coada statica
    queue q[DIM_MAX];
    init(*q);
    cout<<"Introduceti elemente in coada statica (0-pt iesire)";
    int x=-1;
    while(x && !isFull(*q))
    {
        cin>>x;
        put(*q,x);
    }
    while(!isEmpty(*q))
    {
        cout<<front(*q)<<" ";
        get(*q);
    }
    cout<<"\n\n";
    //coada dinamica
    Queue Q;
    initQ(Q);
    x=-1;
    cout<<"Introduceti elemente in coada dinamica (0-pt iesire)";
    while(x)
    {
        cin>>x;
        putQ(Q,x);
    }
    while(!isEmptyQ(Q))
    {
        cout<<frontQ(Q)<<" ";
        getQ(Q);
    }
    return 0;
}