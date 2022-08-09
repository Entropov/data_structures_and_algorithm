#include <stdio.h>
#include <stdlib.h>
#ifndef BOOL_H
#define BOOL_H
typedef enum{true = 1,false = 0}bool;//cpp关键字报错
#endif
#define MAX_SIZE 100//循环队列，最大容量99
typedef struct queue
{
    int q[MAX_SIZE];
    int h;
    int r;
}queue;

queue* init_queue()
{
    queue* newQ = (queue*)malloc(sizeof(queue));
    for(int i=0;i<MAX_SIZE;i++){
        newQ->q[i] = 0;
    }
    newQ->h=newQ->r=0;
    return newQ;
} 

/*返回队头元素*/
int frontOfQueue(queue* queue)
{
    return queue->q[queue->h];
}

/*返回队尾元素*/
int backOfQueue(queue* queue)
{
    return queue->q[queue->r-1];
}

/*判空*/
bool queue_empty(queue* queue)
{
    if(queue->h == queue->r){
        return true;
    }else{
        return false;
    }
}

int queue_size(queue* queue)
{
    return (queue->r-queue->h+MAX_SIZE)%MAX_SIZE;
}

/*队尾入队*/
void pushQueue(queue* queue, int x)
{
    if(queue_size(queue) == MAX_SIZE-1){
        printf("full queue!");
        return;
    }else{
        queue->q[queue->r] = x;
        queue->r = (queue->r+1)%MAX_SIZE;
    }
}

/*队头出队*/
void popQueue(queue* queue)
{
    if(queue_empty(queue)){
        printf("empty queue!");
        return;
    }else{
        queue->h = (queue->h+1)%MAX_SIZE;
    }
}
