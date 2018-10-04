#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//define a binary tree node struct.
typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

//preorder traversal;
void Recursion(BinaryNode* root){
    //exit condition;
    if(root==NULL){
        return;
    }    
    printf("%c:",root->ch);
    Recursion(root->lchild);
    Recursion(root->rchild);
   
}

//inorder traversal;
void Recursion(BinaryNode* root){
    //exit condition;
    if(root==NULL){
        return;
    }       
    Recursion(root->lchild);
    printf("%c:",root->ch);
    Recursion(root->rchild);
   
}
//postorder traversal;
//inorder traversal;
void Recursion(BinaryNode* root){
    //exit condition;
    if(root==NULL){
        return;
    }       
    Recursion(root->lchild);    
    Recursion(root->rchild);
    printf("%c:",root->ch);
   
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


int main(void){
    PreRecursion(&node1);
    return 0;

}