#include <stdio.h>
#include <stdlib.h>
#include "adjList.h"
#define INF 1e7
/*邻接矩阵*/
const int graphMap[10][10] = 
{
    0,1,2,3,4,5,6,7,8,9,
    1,0,2,3,4,5,6,7,8,9,
    1,2,0,3,4,5,6,7,8,9,
    1,2,3,0,4,5,6,7,8,9,
    1,2,3,4,0,5,6,7,8,9,
    1,2,3,4,5,0,6,7,8,9,
    1,2,3,4,5,6,0,7,8,9,
    1,2,3,4,5,6,7,0,8,9,
    1,2,3,4,5,6,7,8,0,9,
    1,2,3,4,5,6,7,8,9,0
};

typedef struct adjListGraph
{
    int edgeNum;
    int vexNum;
    adjList list;
}ALGraph;