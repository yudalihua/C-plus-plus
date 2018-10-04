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
void PreRecursion(BinaryNode* root){
    //exit condition;
    if(root==NULL){
        return;
    }    
    printf("%c:",root->ch);
    PreRecursion(root->lchild);
    PreRecursion(root->rchild);
   
}

//inorder traversal;
void InRecursion(BinaryNode* root){
    //exit condition;
    if(root==NULL){
        return;
    }       
    InRecursion(root->lchild);
    printf("%c:",root->ch);
    InRecursion(root->rchild);
   
}
//postorder traversal;
//inorder traversal;
void PostRecursion(BinaryNode* root){
    //exit condition;
    if(root==NULL){
        return;
    }       
    PostRecursion(root->lchild);    
    PostRecursion(root->rchild);
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
    PreRecursion(&node1);   
    
}


int main(void){    
    return 0;

}
