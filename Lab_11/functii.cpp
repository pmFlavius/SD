#include <iostream>
#include "functii.h"

using namespace std;

void insertHeap(int heap[], int &n, int val)
{
    heap[++n] = val;
    int fiu = n;
    int parinte = n / 2;
    while (parinte >= 1)
    {
        if (heap[parinte] < heap[fiu])
        {
            int aux = heap[parinte];
            heap[parinte] = heap[fiu];
            heap[fiu] = aux;
            fiu = parinte;
            parinte = parinte / 2;
        }
        else
            parinte = 0;
    }
}

int removeHeap(int heap[], int &n)
{
    if (n == 0)
    {
        perror("n=0");
        exit(EXIT_FAILURE);
    }
    int maxim = heap[1];
    heap[1] = heap[n];
    n--;
    int parinte = 1;
    int fiu = 2;
    while (fiu <= n)
    {
        int FiuStanga = 2 * parinte;
        int FiuDreapta = 2 * parinte + 1;

        if ((FiuDreapta <= n) && (heap[FiuStanga] < heap[FiuDreapta]))
        {
            fiu = FiuDreapta;
        }
        else
        {
            fiu = FiuStanga;
        }
        if (heap[parinte] < heap[fiu])
        {
            int aux = heap[parinte];
            heap[parinte] = heap[fiu];
            heap[fiu] = aux;
            parinte = fiu;
            fiu = fiu * 2;
        }
        else
            fiu = n + 1;
    }
    return maxim;
}

void sortare(int heap[])
{
    int n = 0, x;
    cout << "Cititi valorile din heap: 0-iesire\n";
    cin >> x;
    while (x)
    {
        insertHeap(heap, n, x);
        cin >> x;
    }
    while (n)
    {
        cout << removeHeap(heap, n) << " ";
    }
}

void buildHeap1(int heap[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        int x = i - 1;
        insertHeap(heap, x, heap[i]);
    }
}

void buildHeap2(int heap[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        retro(heap, n, i);
    }
}

void retro(int heap[], int n, int i)
{
    int parinte = i;
    int fiu = 2 * i;
    while (fiu <= n)
    {
        int FiuStanga = 2 * parinte;
        int FiuDreapta = 2 * parinte + 1;

        if ((FiuDreapta <= n) && (heap[FiuStanga] < heap[FiuDreapta]))
        {
            fiu = FiuDreapta;
        }
        else
        {
            fiu = FiuStanga;
        }
        if (heap[parinte] < heap[fiu])
        {
            int aux = heap[parinte];
            heap[parinte] = heap[fiu];
            heap[fiu] = aux;
            parinte = fiu;
            fiu = fiu * 2;
        }
        else
            fiu = n + 1;
    }
}

void heapsort(int heap[], int n)
{
    buildHeap2(heap, n);
    for (int i = n; i > 1; i--)
    {
        swap(heap[1], heap[i]);
        retro(heap, i - 1, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << heap[i] << " ";
    }
}