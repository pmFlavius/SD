#pragma once

struct Nod {
	char data;
	Nod* stg, *drt;
};

struct stack{
	Nod *r;
	stack *succ;
};

Nod* creareArbore();
void PREORDINE(Nod *r);
void POSTORDINE(Nod *r);
void INORDINE(Nod *r);
int adancime(Nod *r);
int frunze(Nod *r);
int noduri(Nod *r);
void schimbare(Nod *&r);
void afisareident(Nod *r,int nivel);
void nodurimax(Nod *r);

void init(stack *&s);
void push(stack *&s,Nod *val);
void pop(stack *&s);
bool isEmpty(stack *s);
Nod *top(stack *s);
Nod *BuildTree(char *exp);


