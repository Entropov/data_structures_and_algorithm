#include <stdio.h>
#include <stdlib.h>
#include "adjList.h"
#define INF 1e7
/*邻接矩阵*/
const int graphMap[10][10] = 
{
    0,INF,2,3,4,5,6,7,8,INF,
    INF,0,2,3,4,5,6,7,INF,9,
    1,INF,0,3,4,5,6,INF,8,9,
    1,2,3,0,4,5,INF,7,8,9,
    1,2,3,4,0,INF,6,7,8,9,
    1,2,3,4,INF,0,6,7,8,9,
    1,2,3,INF,5,6,0,7,8,9,
    1,2,INF,4,5,6,7,0,8,9,
    1,INF,3,4,5,6,7,8,0,9,
    INF,2,3,4,5,6,7,8,9,0
};

typedef struct adjListGraph
{
    int edgeNum;
    int vexNum;
    adjList list;
}ALGraph;
