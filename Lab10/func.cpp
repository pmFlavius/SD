#include <iostream>
#include "header.h"

using namespace std;

bool Eq_Required;
void inordine(AVL *rad)
{
    if (rad)
    {
        inordine(rad->stg);
        cout << rad->data<<" ";
        inordine(rad->drt);
    }
}

void RSS(AVL *&a)
{
    AVL *b;
    b = a->drt;
    a->drt = b->stg;
    b->stg = a;
    a->bf = b->bf = 0;
    a = b;
}

void RSD(AVL *&a)
{
    AVL *b;
    b = a->stg;
    a->stg = b->drt;
    b->drt = a;
    a->bf = b->bf = 0;
    a = b;
}

void RDD(AVL *&a)
{
    AVL *b,*c;
    b=a->stg;
    c=b->drt;
    switch(c->bf)
    {
        case 0:
            //h(t2s)=h(t2d) inainte de refacerea legaturilor
            a->bf=b->bf=0;
            //inserare echilibreaza
            break;
        case -1:
            //h(t2s)<h(t2d) initial inainte de refacerea legaturilor
            a->bf=0;
            b->bf=1;
            break;
        case 1:
            //h(t2s)>h(t2d) initial inainte de refacerea legaturilor
            a->bf=-1;
            b->bf=0;
    }
    a->stg=c->drt;
    b->drt=c->stg;
    c->bf=0;
    c->drt=a;
    c->stg=b;
    a=c;
}

void RDS(AVL *&a)
{
    AVL *b,*c;
    b=a->drt;
    c=b->stg;
    switch(c->bf)
    {
        case 0:
            //h(t2s)=h(t2d) inainte de refacerea legaturilor
            a->bf=b->bf=0;
            //inserare echilibreaza
            break;
        case -1:
            //h(t2s)<h(t2d) initial inainte de refacerea legaturilor
            a->bf=0;
            b->bf=1;
            break;
        case 1:
            //h(t2s)>h(t2d) initial inainte de refacerea legaturilor
            a->bf=-1;
            b->bf=0;
    }
    a->drt=c->stg;
    b->stg=c->drt;
    c->bf=0;
    c->drt=b;
    c->stg=a;
    a=c;
}
void Echilibrare(AVL *&a, int x,bool stg)
{
    if(Eq_Required)
    {
        if(stg==1)//inserare la stg
        {
            switch(a->bf)
            {
                case 1://adancime SAS e mai mare
                    Eq_Required=0;
                    //acum aleg tipul de rotatie
                    if(x<a->stg->data)
                        RSD(a);
                    else
                        RDD(a);
                        break;
                case 0://nu e dezechilibru dar se produce acum
                    a->bf=1;
                    break;

                case -1://adancimea pe SAD e mai mare
                    a->bf=0;
                    Eq_Required=0;
                    break;
            }
        }
        else
        {
            switch(a->bf)
            {
                case -1://adancime pe SAD mai mare
                Eq_Required=0;
                //acum aleg tipul de rotatie
                if(x>a->drt->data)
                    RSS(a);
                else
                    RDS(a);
                    break;
            case 0://nu e dezechilibru dar se produce acum
                a->bf=-1;
                break;

            case 1://adancimea pe SAS e mai mare
                a->bf=0;
                Eq_Required=0;
                break;
            }
        }
    }
    else
        Eq_Required=0;
}
void init(AVL *&rad)
{
    rad->stg=0;
    rad->drt=0;
    rad->bf=0;
    rad=0;
}
AVL *MakeNodAVL(int x)
{
    AVL *p=new AVL;
    p->data=x;
    p->stg=0;
    p->drt=0;
    p->bf=0;
    return p;
}
void inserare(AVL *&a,int x)
{
    if(!a)
    {
        a=MakeNodAVL(x);
        Eq_Required=1;
    }
    else
    {
        if(x<a->data)
        {
            inserare(a->stg,x);
            Echilibrare(a,x,1);
        }
        else if(x>a->data)
        {
            inserare(a->drt,x);
            Echilibrare(a,x,0);
        }
    }
}

void dealocare(AVL *&a)
{
    if(a)
    {
        dealocare(a->stg);
        dealocare(a->drt);
        delete a;
        a=0;
    }
}

void afisarearbore(AVL *a, int nivel)
{
	for (int i = 0; i < nivel; i++)
		cout << "\t";
	if (!a)
		cout << "-";
	else
	{
		cout << a->data << endl;
		if (a->stg && a->drt)
		{
			if (a->stg)
				afisarearbore(a->stg, nivel + 1);
			if (a->drt)
				afisarearbore(a->drt, nivel + 1);
		}
	}
	return;
}