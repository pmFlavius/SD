#include <iostream>
#include "Arbore.h"

using namespace std;

static char car = 0;

static void eroare()
{
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati tasta o tasta...");
	getchar();
	exit(1);
}

static char readchar()
{
	char c;
	do
		c = getchar();
	while (c == ' ');
	return c;
}

static char citesteNume()
{
	char c;
	if (!isalpha(car))
		eroare();
	c = car;
	car = readchar();
	return c;
}

static Nod *citesteArbore()
{
	Nod *rad;
	if (car == '-')
	{
		rad = 0;
		car = readchar();
	}
	else
	{
		rad = new Nod;
		rad->data = citesteNume();
		if (car != '(')
		{
			rad->stg = 0;
			rad->drt = 0;
		}
		else
		{
			car = readchar();
			rad->stg = citesteArbore();
			if (car != ',')
			{
				rad->drt = 0;
			}
			else
			{
				car = readchar();
				rad->drt = citesteArbore();
			}
			if (car != ')')
				eroare();
			car = readchar();
		}
	}
	return rad;
}

Nod *creareArbore()
{
	printf("Exemplu: A(B(-,C),D(E(F,-),G(H,-)))\n");
	printf("Introduceti arborele:");
	car = readchar();
	return citesteArbore();
}

void INORDINE(Nod *r)
{
	if (r)
	{
		INORDINE(r->stg);
		cout << r->data << " ";
		INORDINE(r->drt);
	}
	return;
}

void POSTORDINE(Nod *r)
{
	if (r)
	{
		POSTORDINE(r->stg);
		POSTORDINE(r->drt);
		cout << r->data << " ";
	}
	return;
}

void PREORDINE(Nod *r)
{
	if (r)
	{
		cout << r->data << " ";
		PREORDINE(r->stg);
		PREORDINE(r->drt);
	}
	return;
}

int adancime(Nod *r)
{
	if (!r)
		return 0;
	else
		return 1 + max(adancime(r->stg), adancime(r->drt));
}
int noduri(Nod *r)
{
	if (r)
	{
		return 1 + noduri(r->stg) + noduri(r->drt);
	}
	return 0;
}
int frunze(Nod *r)
{
	if (r)
	{
		if (!r->stg && !r->drt)
			return 1;
		return frunze(r->stg) + frunze(r->drt);
	}
	return 0;
}
/*void nodurimax(Nod *r)
{
	if (r && r->stg && r->drt)
	{
		if (r->data > r->stg->data && r->data > r->drt->data)
		{
			cout << r->data << " ";
		}
		nodurimax(r->stg);
		nodurimax(r->drt);
	}
	return;
}*/

void afisareident(Nod *r, int nivel)
{
	for (int i = 0; i < nivel; i++)
		cout << "\t";
	if (!r)
		cout << "-";
	else
	{
		cout << r->data << endl;
		if (r->stg && r->drt)
		{
			if (r->stg)
				afisareident(r->stg, nivel + 1);
			if (r->drt)
				afisareident(r->drt, nivel + 1);
		}
	}
	return;
}
void schimbare(Nod *&r)
{
	if (r)
	{
		Nod *aux = r->stg;
		r->stg = r->drt;
		r->drt = aux;
		schimbare(r->stg);
		schimbare(r->drt);
	}
	else
		return;
}

Nod *BuildTree(char *exp)
{
	stack *s;
	char ch;
	Nod *r = 0;
	init(s);
	while (ch = *exp++)
	{
		r = new Nod;
		r->data = ch;
		if (isdigit(ch))
		{
			r->stg = r->drt = 0;
			push(s,r);
		}
		else {
            if (isEmpty(s)) {
                delete r;
                return 0;
            }
            r->drt = top(s);
            pop(s);
            
            if (isEmpty(s)) {
                delete r;
                delete r->drt;
                return 0;
            }
            r->stg = top(s);
            pop(s);
            
            push(s, r);
        }
	}
	return r;
}

void init(stack *&s)
{
	s = 0;
}
bool isEmpty(stack *s)
{
	if (s == 0)
		return 1;
	return 0;
}
void push(stack *&s, Nod *val)
{
	stack *p = new stack;
	p->r = val;
	p->succ = s;
	s = p;
}
Nod *top(stack *s)
{
	if (!s)
		return NULL;
	return s->r;
}
void pop(stack *&s)
{
	if (!s)
		return;
	stack *p = s;
	s = s->succ;
	delete p;
}
