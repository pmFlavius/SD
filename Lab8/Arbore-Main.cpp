#include <iostream>
#include "Arbore.h"

using namespace std;

int main()
{
	Nod *root = creareArbore();

	INORDINE(root);
	cout<<endl;
	POSTORDINE(root);
	cout<<endl;
	PREORDINE(root);
	cout<<endl;
	cout<<"Adancimea arborelui este: "<<adancime(root);
	cout<<endl;
	cout<<"Numarul de noduri al arborelui este: "<<noduri(root);
	cout<<endl;
	cout<<"Numarul de frunze al arborelui este: "<<frunze(root);
	cout<<endl;
	/*cout<<"Toate nodurile care au valoarea din radacina mai mare decat toate valorile din subarborii descendenti: ";
	nodurimax(root);
	cout<<endl;*/
	afisareident(root,0);
	schimbare(root);
	PREORDINE(root);
	cout<<endl;

	char s[20]="34+5+";
	Nod *r=BuildTree(s);
	INORDINE(r);
	return 0;
}