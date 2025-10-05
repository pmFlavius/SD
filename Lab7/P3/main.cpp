#include <iostream>
#include <cstring>
#include "functii.h"

using namespace std;

int main()
{
    Nod *HT[M];
    init(HT);
    char buffer[30];
    fgets(buffer,30,stdin);
    int n=strlen(buffer);
    for(int i=0;i<n;i++)
    {
        if(estelitera(buffer[i]))
        {
            char s=toupper(buffer[i]);
            char litera[2];
            litera[0]=s;
            litera[1]=NULL;
            insert(HT,litera);
        }
    }
    afisareHT(HT);
    return 0;
}
