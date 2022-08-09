#include<stdio.h>
#include<stdlib.h>
#include "struct\adjList.h"
#include "struct\binaryTree.h"
#include "struct\queue.h"
#include "struct\stack.h"
#include "struct\linkList.h"

void testQueue();
void testStack();
void testLinkList();
void testBinaryTree();
void testBinaryTree2();
void testAdjList();

int main()
{
    int a;
    printf("This is a test:\n");
    printf("    press 1 to test Queue.\n");
    printf("    press 2 to test Stack.\n");
    printf("    press 3 to test LinkList.\n");
    printf("    press 4 to test BinaryTree.\n");
    printf("    press 5 to test BinaryTree2.\n");
    printf("    press 6 to test AdjList.\n");
    printf("    press 0 to quit.\n");
    scanf("%d",&a);
    while (a)
    {
        switch (a)
        {
        case 1:
            testQueue();
            break;
        case 2:
            testStack();
            break;
        case 3:
            testLinkList();
            break;
        case 4:
            testBinaryTree();
            break;
        case 5:
            testBinaryTree2();
            break;
        case 6:
            testAdjList();
            break;
        default:
            printf("wrong input!\n");
            break;
        }
        printf("\n");
        system("pause");
            printf("This is a test:\n");
            printf("    press 1 to test Queue.\n");
            printf("    press 2 to test Stack.\n");
            printf("    press 3 to test LinkList.\n");
            printf("    press 4 to test BinaryTree.\n");
            printf("    press 5 to test BinaryTree2.\n");
            printf("    press 6 to test AdjList.\n");
            printf("    press 0 to quit.\n");
        scanf("%d",&a);
    }
    return 0;
}

void testQueue()
{
    queue* q = init_queue();
}

void testStack()
{
    stack* s = init_stack();
}

void testLinkList()
{
    linkNode* list = init_link();
    int size;
    printf("plz input size:\n");
    scanf("%d",&size);
    creatLink(list,size);
}

void testBinaryTree()
{
    printf("(^_^)-_-_-  plz input root 7    -_-_-(^_^)\n");
    binaryNode* root = init_binaryTree();
    for(int i=0;i<7;i++){
        addLeaf(root,testList[i]);
    }
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n plz input data to delete:\n");
    int aq;
    scanf("%d",&aq);
    deleteBinaryNode(root,aq);
    inOrder(root);
}

void testBinaryTree2()
{
    printf("(^_^)-_-_-  plz input root 20   -_-_-(^_^)\n");
    int a[14]={10,30,5,15,3,7,13,17,25,35,33,36,34,24};
    binaryNode* root = init_binaryTree();
    for(int i=0;i<14;i++){
        addLeaf(root,a[i]);
    }
    printf("%d\n",getDepthOfBinary(root));
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n plz input data to delete:\n");
    int aq;
    scanf("%d",&aq);
    deleteBinaryNode(root,aq);
    inOrder(root);
    printf("\n");
    printf("%d\n",getDepthOfBinary(root));
}

void testAdjList()
{
    printf("plz input edge num:\n");
    scanf("%d",&edgeNum);
    printf("plz input vex num:\n");
    scanf("%d",&vexNum);
    adjNode* list = init_adjList(edgeNum,vexNum);
    showAdjList(list);
}