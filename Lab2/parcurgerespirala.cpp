#include <iostream>

using namespace std;
int a[100][100],n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    int sus=0,jos=n-1,st=0,dr=n-1;
    while(st<=dr && sus<=jos)
    {
        //parcurgere stanga-dreapta sus
        for(int i=st;i<=dr;i++)
        {
            cout<<a[sus][i]<<" ";
        }
        sus++;
        //parcurgere sus-jos dreapta
        for(int i=sus;i<=jos;i++)
        {
            cout<<a[i][dr]<<" ";
        }
        dr--;
        //parcurgere dr-st jos
        for(int i=dr;i>=st;i--)
        {
            cout<<a[jos][i]<<" ";
        }
        jos--;
        //parcurgere jos-sus stanga
        for(int i=jos;i>=sus;i--)
        {
            cout<<a[i][st]<<" ";
        }
        st++;
    }
    return 0;
}
/* 3
1 2 3
8 9 4
7 6 5*/