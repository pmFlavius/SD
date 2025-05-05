#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int x;
    AVL *rad;
    init(rad);
    cin>>x;
    while(x)
    {
        inserare(rad,x);
        cin>>x;
    }
    inordine(rad);
    cout<<"\nRADACINA ESTE: "<<rad->data<<endl;

    afisarearbore(rad,0);
    dealocare(rad);
    return 0;
}