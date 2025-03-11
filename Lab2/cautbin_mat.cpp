#include <iostream>

using namespace std;
int a[101][101],n,m,x;
int main()
{
    cin>>x;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(x<a[i][0] ||  x>a[i][m-1])
            continue;
        else
        {
            int st=0,dr=m-1;           
            while(st<=dr)
            {
                int mij=(st+dr)/2;
                if(x==a[i][mij])
                {
                    cout<<"Elementul x: "<<x<<" se gaseste in matrice pe pozitiile "<<i<<" "<<mij;
                    return 0;
                }
                else if(x>a[i][mij])
                    st=mij+1;
                else if(x<a[i][mij])
                    dr=mij-1;
            }
        }
    }
}