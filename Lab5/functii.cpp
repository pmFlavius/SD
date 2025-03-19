#include <iostream>
#include "functii.h"

using namespace std;

//stiva statica
void initS(stackS &s)
{
    s.vf=-1;
}
bool isFullS(const stackS &s)
{
    if(s.vf==DIM_MAX-1)
        return 1;
    return 0;
}
bool isEmptyS(const stackS &s)
{
    if(s.vf==-1)
        return 1;
    return 0;
}
void pushS(stackS &s,int val)
{
    if(isFullS(s)==1)
    {
        cout<<"Stiva plina ";
        return;
    }
    s.vect[++s.vf]=val;
}
int topS(const stackS &s)
{
    return s.vect[s.vf];
}
void popS(stackS &s)
{
    if(isEmptyS(s))
    {
        cout<<"Stiva goala";
        return;
    }
    else
    {
        --s.vf;
    }
}
//stiva dinamica
void init(stack *&s)
{
    s=0;
}
bool isEmpty(stack *s)
{
    if(s==0)
        return 1;
    return 0;
}
void push(stack *&s,char val)
{
    stack *p=new stack;
    p->data=val;
    p->succ=s;
    s=p;
}
char top(stack *s)
{
    return s->data;
}
void pop(stack *&s)
{
    if(!s)
        return;
    stack *p=s;
    s=s->succ;
    delete p;
}
int prioritate(char s)
{
    if(s=='+' || s=='-')
        return 1;
    else if(s=='*' || s=='/')
        return 2;
    return 0;
}