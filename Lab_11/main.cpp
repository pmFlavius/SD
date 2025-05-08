#include <iostream>
#include "functii.h"

using namespace std;

int main()
{
    int n;
    int heap[DIM_MAX]={};
    sortare(heap);
    cout<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>heap[i];
    }
    heapsort(heap,n);
}