#include<stdlib.h>
#include<stdio.h>
#define dataType int
typedef struct node
{
    dataType data;
    struct node* next;
}linkNode;

linkNode* init_link()
{
    linkNode* newNode =(linkNode*)malloc(sizeof(linkNode));
    if(newNode == NULL){
        printf("malloc fail!\n");
        return NULL;
    }else{
        newNode->data = -1;
        newNode->next = NULL;
        return newNode;
    }
}

void creatLink(linkNode* head, int size)
{
    if(size>0){
        head ->next = (linkNode*)malloc(sizeof(linkNode));
        linkNode* newNode = head->next;
        printf("plz input:\n");
        scanf("%d",&newNode->data);
        for(int i=1;i<size;i++){
            newNode->next =(linkNode*)malloc(sizeof(linkNode));
            newNode = newNode->next;
            printf("plz input:\n");
            scanf("%d",&newNode->data);
        }
        newNode->next = NULL;
    }else{
        printf("wrong size!\n");
    }
}

int link_size(linkNode* head)
{
    linkNode* node = head;
    int cnt = 0;
    while (node->next != NULL)
    {
        node = node->next;
        cnt++;
    }
    return cnt;
}

void addNode(linkNode* head, dataType data, int location)
{
    linkNode* node = head;
    if(location<0){
        printf("wrong location!\n");
    }else{
        while (node)
        {
            if(location == 0 || node->next == NULL){
                linkNode* newNode = (linkNode*)malloc(sizeof(linkNode));
                newNode->next = node ->next;
                node->next = newNode;
                newNode->data =data;
                break;
            }else{
                location--;
            }
            node = node->next;
        }
    }
}

void deleteNode(linkNode* head, int location)
{
    linkNode* node = head;
    if(location<0){
        printf("wrong location!\n");
    }else{
        while (node)
        {
            if(node->next == NULL){
                printf("oversize!\n");
            }else if (location == 0)
            {
                linkNode* del = node->next;
                node->next = del->next;
                free(del);
                del = NULL;
                break;
            }else{
                location--;
            }
            node = node->next;
        }
    }
}

void setNode(linkNode* head, dataType data, int location)
{
    linkNode* node = head;
    if(location<0){
        printf("wrong location!\n");
    }else{
        while (node)
        {
            if(node->next == NULL){
                printf("oversize!\n");
            }else if (location == 0)
            {
                node->next->data = data;
                break;
            }else{
                location--;
            }
            node = node->next;
        }
    }
}

void locateNode(linkNode* head, int location)
{
    linkNode* node =head;
    if(location<0){
        printf("wrong location!\n");
    }else{
        while (node)
        {
            if(node->next == NULL){
                printf("oversize!\n");
            }else if (location == 0)
            {
                printf("the local data is:%4d\n",node->next->data);
                break;
            }else{
                location--;
            }
            node = node->next;
        }
    }
}

void showList(linkNode* head)
{
    if(head->next){
        linkNode* node = head;
        printf("list:");
        while (node->next)
        {
            printf("%4d",node->next->data);
            node=node->next;
        }
        printf("\n");
    }else{
        printf("empty list!\n");
    }
}