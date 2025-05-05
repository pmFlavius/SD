#include <iostream>
#include "functii.h"
using namespace std;

int main()
{
    int x;
    Nod *rad;
    init(rad);
    cout << "Introduceti numerele: 0-oprire ";
    cin >> x;
    while (x)
    {
        inserare(rad, x);
        cin >> x;
    }
    cout << "\nParcurgerea in inordine este: ";
    inordine(rad);
    cout << "\nParcurgerea in postordine este: ";
    postordine(rad);
    cout << "\nParcurgerea in preordine este: ";
    preordine(rad);

    int val;
    cout << "\nIntroduceti o valoare care va fi cautata in arbore ";
    cin >> val;
    if (cautare(rad, val))
    {
        cout << "\nValoarea introdusa a fost gasita cu succes";
    }
    else
    {
        cout << "\nValoarea introdusa nu a fost gasita";
    }

    cout << "\nIntroduceti o valoare care sa fie stearsa din BST ";
    cin >> val;
    stergere(rad, val);
    cout << "\nNoua parcurgere in inordine este ";
    inordine(rad);

    cout << "\nIntoduceti o noua valoare care va fi cautata iterativ in BST ";
    cin >> val;
    if (cautareIterativ(rad, val))
    {
        cout << "\nValoarea a fost gasita cu succes";
    }
    else
    {
        cout << "\nValoarea nu a fost gasita";
    }
    cout << "\nIntroduceti noi valori in BST: 0-iesire ";
    cin >> x;
    while (x)
    {
        inserareIterativ(rad, x);
        cin >> x;
    }
    cout << endl;
    inordine(rad);

    /*cout << "\nIntroduceti o valoare care sa fie stearsa iterativ din BST: ";
    cin >> val;
    stergereIterativ(rad, val);
    cout << endl;
    inordine(rad);*/
    return 0;
}