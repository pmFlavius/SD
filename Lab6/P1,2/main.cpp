#include <iostream>
#include "functii.h"

using namespace std;

int main()
{
    //coada statica
    queue q[DIM_MAX];
    init(*q);
    cout<<"Introduceti elemente in coada statica (0-pt iesire)";
    int x;
    cin>>x;
    while(x && !isFull(*q))
    {
        put(*q,x);
        cin>>x;
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
    cout<<"Introduceti elemente in coada dinamica (0-pt iesire)";
    cin>>x;
    while(x)
    {
        putQ(Q,x);
        cin>>x;      
    }
    while(!isEmptyQ(Q))
    {
        cout<<frontQ(Q)<<" ";
        getQ(Q);
    }
    return 0;
}