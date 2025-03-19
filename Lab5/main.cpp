#include <iostream>
#include <cstring>
#include "functii.h"

using namespace std;

int main()
{
    char sir[256]="";
    stack *s;
    init(s);
    cin.get(sir,256);
    for(int i=0;i<strlen(sir);i++)
    {
        if(sir[i]>='0' && sir[i]<='9')
        {
            cout<<sir[i];
        }
        else if(sir[i]=='(')
        {
            push(s,sir[i]);
        }
        else if(sir[i]==')')
        {
            while(!isEmpty(s) && top(s)!='(')
            {
                cout<<top(s);
                pop(s);
            }
            pop(s);
        }
        else
        {
            while(!isEmpty(s) && (prioritate(top(s))>=prioritate(sir[i])))
            {
                
                cout<<top(s);
                pop(s);
            }
            push(s,sir[i]);
        }

    }
    while(!isEmpty(s))
    {
        cout<<top(s);
        pop(s);
    }
    delete s;
    return 0;
}