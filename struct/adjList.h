#include <stdio.h>
#include <stdlib.h>
int edgeNum, vexNum;
typedef char dataType;
typedef struct arcNode
{
    int adjVex;
    int weight;
    struct arcNode *next;
}edge;

typedef struct vertexNode
{
    dataType vex;
    edge *firstEdge;
}adjNode,adjList[];

/*为邻接表增加邻接边*/
void addEdge(int vex1, int vex2, adjList list)
{
        if(!list[vex1].firstEdge){
            list[vex1].firstEdge = (edge*)malloc(sizeof(edge));
            list[vex1].firstEdge->adjVex = vex2;
            list[vex1].firstEdge->weight = 1;//可达
            list[vex1].firstEdge->next = NULL;
        }else{
            edge* e = list[vex1].firstEdge;
            while (e->next)
            {
                e = e->next;
            }
            e->next = (edge*)malloc(sizeof(edge));
            e->next->adjVex = vex2;
            e->next->weight = 1;
            e->next->next = NULL;
        }
}

adjNode* init_adjList(int edgeNum, int vexNum)
{
    adjNode* list = (adjNode*)malloc(vexNum*sizeof(adjNode));
    printf("press 1 to name node defaulted or 2 by user.\n");
    again:
        fflush(stdin);
        char input = getchar();
        if(input == '1'){
            for(int i = 0; i < vexNum; i++){
                list[i].vex = i + 65;
                list[i].firstEdge = NULL;
            }

        }else if(input == '2'){
            for(int i = 0; i < vexNum; i++){
                fflush(stdin);
                printf("plz input(vex):\n");
                list[i].vex = getchar();
                list[i].firstEdge = NULL;
            }

        }else{
            printf("wrong input!\n");
            goto again;
        }
    for(int i = 0; i < edgeNum; i++){
        int vex1,vex2;
        printf("plz input vex and adj vex:\n");
        scanf("%d%d",&vex1,&vex2);
        if(vex1<0 || vexNum<=vex1 || vex2<0 || vexNum<=vex2){
            printf("wrong input!\n");
        }else{
            addEdge(vex1,vex2,list);
            addEdge(vex2,vex1,list);
        }       
    }
    printf("adj list is ok.\n");
    return list;
}

void showAdjList(adjList list)
{
    for(int i = 0; i < vexNum; i++){
        printf("%2d %c:",i,list[i].vex);
        edge* e = list[i].firstEdge;
        while(e){
            printf("%4d",e->adjVex);
            e = e->next;
        }
        printf("\n");
    }
}
