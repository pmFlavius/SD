#include <iostream>
#include <cstring>
#include "functii.h"

using namespace std;

int main()
{
    int (*pf[3])(char *)={h1,h2,h3};
    FILE *in=0;
    in=fopen("dictionar_termeni_PC.txt","r");
    if(in==0)
    {
        perror("Eroare la deschiderea fisierului");
        exit(EXIT_FAILURE);
    }
    char buffer[30]="";
    Nod *HT[M];;
    init(HT);
    //pt functia 1 dispersie modulara
    while(fgets(buffer,sizeof(buffer),in))
    {
        buffer[strlen(buffer)]='\0';
        insert(HT,buffer,pf[0]);
    }
    float gc[3]={};
    gc[0]=GC(HT);
    //pt functia 2 dispersie prin inmultire
    rewind(in);
    deleteHT(HT);
    /*while(fgets(buffer,sizeof(buffer),in))
    {
        buffer[strlen(buffer)]='\0';
        insert(HT,buffer,pf[0]);
    }
    gc[1]=GC(HT);*/
    //trebuie continuat
    for(int i=0;i<3;i++)
    {
        cout<<"Gradul de clusterizare pentru HT"<<i+1<<" este "<<gc[i]<<endl;
    }
    fclose(in);
    return 0;
}