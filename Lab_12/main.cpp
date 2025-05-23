#include <iostream>
#include "functii.h"

using namespace std;

int main()
{
    int pri,a;
    Queue q;
    initQ(q);
    cin>>a>>pri;
    while(a)
    {
        put(q,a,pri);
        cin>>a>>pri;
    }
    while(q.head !=q.tail)
    {
        cout<<get(q)<<" ";
    }
    return 0;
}