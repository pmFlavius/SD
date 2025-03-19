#ifndef FUNCTII_H_
#define FUNCTII_H_

//stiva statica
#define DIM_MAX 10
struct stackS{
    int vect[DIM_MAX];
    int vf;    
};
void initS(stackS &s);
void pushS(stackS &s,int val);
bool isFullS(const stackS &s);
int topS(const stackS &s);
void popS(stackS &s);
bool isEmptyS(const stackS &s);

//stiva dinamica 
struct stack{
    char data;
    stack *succ;
};
void init(stack *&s);
void push(stack *&s,char val);
void pop(stack *&s);
bool isEmpty(stack *s);
char top(stack *s);
int prioritate(char s);

#endif