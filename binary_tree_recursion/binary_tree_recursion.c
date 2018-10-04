#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//define a binary tree node struct.
typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

void Recursion(BinaryNode* root){
    if(root==NULL){
        return;
    }
    printf("%c",root->ch);
    Recursion(root->lchild);
    Recursion(root->rchild);
}

int num=0;
void CalculateLeafNum(BinaryNode* root){
    if(root==NULL){
        return;
    }
    //when meet a leaf node,num++;
    if(root->lchild==NULL && root->rchild == NULL){
        num++;
    }
    CalculateLeafNum(root->lchild);
    CalculateLeafNum(root->rchild);

}


BinaryNode* CopyBinaryNode(BinaryNode* root){
    if(root=NULL){
        return NULL;
    }
    BinaryNode* lchild=CopyBinaryNode(root->lchild);
    BinaryNode* rchild=CopyBinaryNode(root->rchild);

    BinaryNode* newnode=(BinaryNode*)malloc(sizeof(BinaryNode));
    newnode->ch=root->ch;
    newnode->lchild=lchild;
    newnode->rchild=rchild;
    return newnode;

}

void CreateBinaryTree(){
    //create 8 nodes;
    BinaryNode* node1 = {'A',NULL,NULL};
    BinaryNode* node2 = {'B',NULL,NULL};
    BinaryNode* node3 = {'C',NULL,NULL};
    BinaryNode* node4 = {'D',NULL,NULL};
    BinaryNode* node5 = {'E',NULL,NULL};
    BinaryNode* node6 = {'F',NULL,NULL};
    BinaryNode* node7 = {'G',NULL,NULL};
    BinaryNode* node8 = {'H',NULL,NULL};

    //create the relations between nodes;
    node1.lchild=&node2;
    node1.rchild=&node6;
    node2.rchild=&node3;
    node3.lchild=&node4;
    node3.rchild=&node5;
    node6.rchild=&node7;
    node7.lchild=&node8;
}

void FreeSpaceBinaryTree(BinaryNode* root){
    if(root == NULL){
        return;
    }
    FreeSpaceBinaryTree(root->lchild);
    FreeSpaceBinaryTree(root->rchild);
    free(root);
}

int main(void){
    CreateBinaryTree();
    BinaryNode* root=CopyBinaryNode(&node1);
    Recursion(root);
    FreeSpaceBinaryTree(root);
    return 0;

}