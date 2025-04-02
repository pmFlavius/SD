#include <iostream>
#include <cstring>
#include "functii.h"

using namespace std;

int main()
{
    FILE *in=0;
    in=fopen("dictionar_termeni_PC.txt","r");
    if(in==0)
    {
        perror("Eroare la deschiderea fisierului");
        exit(EXIT_FAILURE);
    }
    char buffer[30]="";
    Nod *HT[M];
    init(HT);
    while(fgets(buffer,sizeof(buffer),in))
    {
        buffer[strlen(buffer)]='\0';
        insert(HT,buffer);
    }
    fclose(in);

    afisareHT(HT);
    return 0;
}