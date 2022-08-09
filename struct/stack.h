#include <stdio.h>
#include <stdlib.h>
#ifndef BOOL_H
#define BOOL_H
typedef enum{true = 1,false = 0}bool;//cpp关键字报错
#endif
#define MAX_SIZE 100//栈最大容量100
typedef struct stack
{
    int s[MAX_SIZE];
    int top;
}stack;

stack* init_stack()
{
    stack* newS = (stack*)malloc(sizeof(stack));
    for(int i=0;i<MAX_SIZE;i++){
        newS->s[i] = 0;
    }
    newS->top = -1;
    return newS;
}

/*判空*/
bool stack_empty(stack* stack)
{
    return stack->top < 0 ? true:false;
}
/*返回栈顶元素*/
int topOfStack(stack* stack)
{
    if(stack_empty(stack)){
        printf("empty stack!\n");
        return 0;
    }else{
        return stack->s[stack->top];
    }
}

/*压栈*/
void pushStack(stack* stack, int x)
{
    if(stack->top+1 >= MAX_SIZE){
        printf("oversize!\n");
    }else{
        stack->s[++stack->top] = x;
    }
}

/*出栈*/
void popStack(stack* stack)
{
    if(stack_empty(stack)){
        printf("empty stack!\n");
    }else{
        stack->top--;
    }
}

int stack_size(stack* stack)
{
    return stack->top+1;
}
