#include <stdio.h>
#include <stdlib.h>
#include "../struct/graph.h"
#include "../struct/queue.h"
#define VEX_NUM 10 

void mapBFS(const int (*map)[VEX_NUM], int size)
{
    int visited[size];
    for(int i = 0;i < size; i++){
        visited[i] = 0;
    }
    queue* q = init_queue();
    pushQueue(q,0);
    visited[0] = 1;
    while (!queue_empty(q))
    {
        int curNode = frontOfQueue(q);
        printf("%4d",curNode);
        for(int i = 0; i < size; i++){
            if(map[curNode][i] != INF && i != curNode){
                if(!visited[i]){
                    pushQueue(q,i);
                    visited[i] = 1;
                }
            }
        }
        popQueue(q);
    }
}

void graphBFS(ALGraph* graph)
{

}

int main()
{
    mapBFS(graphMap,VEX_NUM);
    return 0;
}
