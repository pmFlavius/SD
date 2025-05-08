#ifndef FUNCTII_H_
#define FUNCTII_H_

const int DIM_MAX=100;

void insertHeap(int heap[],int &n,int val);
int removeHeap(int heap[],int &n);
void sortare(int heap[]);
void buildHeap1(int heap[],int n);
void buildHeap2(int heap[],int n);
void retro(int heap[],int n,int i);
void heapsort(int heap[],int n);

#endif