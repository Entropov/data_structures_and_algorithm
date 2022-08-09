#include <stdio.h>
#include <stdlib.h>
#ifndef BOOL_H
#define BOOL_H
typedef enum{true = 1,false = 0}bool;//cpp关键字报错
#endif
#define dataType int

/**
 * @brief root->value = 7
 *        7
 *      /   \
 *     4     9 
 *    / \   / \
 *   3   6 8   10
 *      / 
 *     5
 */
dataType testList[7] = {4,9,3,6,8,10,5};

typedef struct tree_node
{
    dataType value;
    struct tree_node *left;
    struct tree_node *right;
} binaryNode;

binaryNode *init_binaryTree()
{
    binaryNode *root = (binaryNode *)malloc(sizeof(binaryNode));
    root->left = NULL;
    root->right = NULL;
    printf("plz input(root):\n");
    scanf("%d", &root->value);
    return root;
}

/*获得二叉树的高*/
int getDepthOfBinary(binaryNode* root)
{
    int depthLeft;
    int depthRight;
    if(root == NULL){
        return -1;//根节点深度为0
    }else{
        depthLeft = getDepthOfBinary(root->left);
        depthRight = getDepthOfBinary(root->right);
        return depthLeft > depthRight ? ++depthLeft : ++depthRight; 
    }
}

/*添加叶子节点*/
void addLeaf(binaryNode *root, dataType data)
{
    if (data < root->value)
    {
        if (root->left == NULL)
        {
            root->left = (binaryNode *)malloc(sizeof(binaryNode));
            root->left->left = NULL;
            root->left->right = NULL;
            root->left->value = data;
        }
        else
        {
            addLeaf(root->left,data);
        }
    }
    else if (data > root->value)
    {
        if (root->right == NULL)
        {
            root->right = (binaryNode *)malloc(sizeof(binaryNode));
            root->right->left = NULL;
            root->right->right = NULL;
            root->right->value = data;
        }
        else
        {
            addLeaf(root->right,data);
        }
    }
    else
    {
        return;
    }
}

/*查找节点*/
bool findBinaryNode(binaryNode* root, dataType data)
{
    bool flag = false;
    if(root == NULL){
        flag = false;
    }else{
        if(root->value == data){
            flag = true;
        }else if (root->value > data)
        {
            flag = findBinaryNode(root->left,data);
        }else{
            flag = findBinaryNode(root->right,data);
        }    
    }
    return flag;
}

/*修改节点*/
void setBinaryNode(binaryNode* root, dataType data)
{
    if(root == NULL){
        printf("The data %d does not exist!\n",data);
    }else{
        if(root->value == data){
            printf("plz input(reset):\n");
            scanf("%d",&root->value);
        }else if (root->value > data)
        {
            setBinaryNode(root->left,data);
        }else{
            setBinaryNode(root->right,data);
        }
    }
}

/*删除节点*/
void deleteBinaryNode(binaryNode* root, dataType data)
{
    if(root == NULL){
        printf("The data %d does not exist!\n",data);
    }else{    
        if(root->value > data){
            if(root->left->value == data && !root->left->left && !root->left->right){
                free(root->left);
                root->left = NULL;
            }else{
                deleteBinaryNode(root->left,data);
            }
        }else if(root->value < data){
            if(root->right->value == data && !root->right->left && !root->right->right){
                free(root->right);
                root->right = NULL;
            }else{
                deleteBinaryNode(root->right,data);
            }
        }else{   
            if(root->left != NULL && root->right != NULL){
                if(getDepthOfBinary(root->left) > getDepthOfBinary(root->right)){
                    binaryNode* max = root->left;
                        while (max->right)
                        {
                            if(!max->right->left && !max->right->right){
                                root->value = max->right->value;
                                free(max->right);
                                max->right = NULL;
                                return;
                            }else{
                                max = max->right;
                            }
                        }
                        root->value = max->value;
                        deleteBinaryNode(max,max->value);
                }else{
                    if(!root->right->left && !root->right->right){
                        root->value = root->right->value;
                        free(root->right);
                        root->right = NULL;
                    }else
                    {
                        binaryNode* min = root->right;
                        while (min->left)
                        {
                            if(!min->left->left && !min->left->right){
                                root->value = min->left->value;
                                free(min->left);
                                min->left = NULL;
                                return;
                            }else{
                                min = min->left;
                            }
                        }
                        root->value = min->value;
                        deleteBinaryNode(min,min->value);
                    }
                }
            }else if(root->left || root->right){
                binaryNode* del = root->left != NULL ? root->left : root->right;
                root->left = del->left;
                root->right = del->right;
                root->value = del->value;
                free(del);
                del = NULL;
                return;
            }else{
                printf("The data %d belong to the only root node, you cannot handle it in this function!\n",data);
            }
        }
    }
}

/*创建二叉查找树*/
void creatBST(binaryNode *root)
{
    fflush(stdin);
    printf("plz input(leaf):\n");
    //int data = getchar()-48;
    /**getchar()得到的是ascii码
     * 只能输入单字符
     */
    int data;
    scanf("%d",&data);
    //while (data +48 != '\n')
    while (data != -1)    
    {
        addLeaf(root,data);
        fflush(stdin);
        printf("plz input(leaf):\n");
        //data = getchar()-48;
        scanf("%d",&data);
    }
}

/*前序遍历*/
void preOrder(binaryNode *root)
{
    if (root == NULL){
        return;
    }else{
        printf("%4d", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/*中序遍历*/
void inOrder(binaryNode* root)
{
    if(root == NULL){
        return;
    }else{
        inOrder(root->left);
        printf("%4d",root->value);
        inOrder(root->right);
    }
}

/*后序遍历*/
void postOrder(binaryNode* root)
{
    if(root == NULL){
        return;
    }else{
        postOrder(root->left);
        postOrder(root->right);
        printf("%4d",root->value);
    }
}
