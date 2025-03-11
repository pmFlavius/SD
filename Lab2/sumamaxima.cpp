#include <iostream>

using namespace std;
int v[101],x[101][101],n,maxi,poz1,poz2;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    for(int i=0;i<n;i++)
    {
        x[i][i]=v[i];
        for(int j=i+1;j<n;j++)
        {
            x[i][j]=x[i][j-1]+v[j];
        }
    }
    maxi=x[0][0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(x[i][j]>maxi && i<j)
            {
                maxi=x[i][j];
                poz1=i;
                poz2=j;
            }
        }
    }
    cout<<"Suma secventei maxime este "<<maxi<<" ,iar indicii i si j ai secventei sunt "<<poz1<<",respectiv "<<poz2;
    /*for(int i=1;i<n;i++)
    {
        x[i]=x[i-1]+v[i];
    }
    maxi=x[0];
    for(int i=0;i<n;i++)
    {
        if(x[i]>maxi)
        {
            maxi=x[i];
            poz=i;
        }
    }
    cout<<"Suma sectiunii maxime este "<<maxi<<", iar indicii i si j sunt 0 si "<<poz; */
}