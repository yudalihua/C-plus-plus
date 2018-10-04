#include "LinkStack.h"
#include<stdlib.h>
#include<stdio.h>

#define MY_FALSE 0
#define MY_TRUE 1
//define a binary tree node struct.
typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

//the node struct in stack
typedef struct BITREESTACKNODE{
    LinkNode node;
    BinaryNode* root;
    int flag;

}BiTreeStackNode;

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
    node1->lchild=&node2;
    node1->rchild=&node6;
    node2->rchild=&node3;
    node3->lchild=&node4;
    node3->rchild=&node5;
    node6->rchild=&node7;
    node7->lchild=&node8;
    
    NonRecursion(&node1);
} 

BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* node,int flag){
    BiTreeStackNode* newnode=(BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
    newnode->root=node;
    newnode->flag=flag;
    return newnode;
}

//pre-order non-recursive traversal.
void NonRecursion(BinaryNode* root){

    //create a stack;
    LinkStack* stack=Init_LinkStack();

    //push the root node into the stack
    Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(root,MY_FALSE));
    while(Size_LinkStack(stack)>0){
        BiTreeStackNode* node=(BiTreeStackNode*)Top_LinkStack(stack);
        Pop_LinkStack(stack);
        if(node->root==NULL){
            continue;
        }
        if(node->flag == MY_TRUE){
            printf("%c",node->root->ch);
        }
        //push the current node's left child into stack
        Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(node->root->rchild,MY_FALSE));
        
        //push the current node's right child into stack
        Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(node->root->lchild,MY_FALSE));

        //push the current node into stack
        node->flag=MY_TRUE;
        Push_LinkStack(stack,(LinkNode*)node);
    }


}

//the main function
int main(void){   
    CreateBinaryTree();
    return 0;
  
}


//initialization
LinkStack* Init_LinkStack(){
    LinkStack* stack=(LinkStack*)malloc(sizeof(LinkStack));
    stack->head.next=NULL;
    stack->size=0;
}


//push
void Push_LinkStack(LinkStack* stack, LinkNode* data){
    if(stack==NULL){
        return;
    }
    if(data==NULL){
        return;
    }
    data->next=stack->head.next;
    stack->head.next=data;
    stack->size++;


}

//pop
void Pop_LinkStack(LinkStack* stack){
    
    if(stack==NULL){
        return;
    }
    if(stack->size==0){
        return;
    }
    //the first valid node.
    LinkNode* pFirst=stack->head.next;
    stack->head.next=pFirst->next;
    stack->size--;


}

//return the top element of the stack
void* Top_LinkStack(LinkStack* stack){
     if(stack==NULL){
        return NULL;
    }
    if(stack->size==0){
        return NULL;
    }
    return stack->head.next;

}

//whether the stack is empty
int IsEmpty(LinkStack* stack){
    if(stack==NULL){
        return -1;
    }
}

//return the size of stack
int Size_LinkStack(LinkStack* stack){
    if(stack==NULL){
        return -1;
    }
    return stack->size;}




//clear the stack
void Clear_LinkStack(LinkStack* stack){
    if(stack==NULL){
        return;
    }
    stack->head.next=NULL;
    stack->size=0;
}

//destroy the stack
void FreeSpace_LinkStack(LinkStack* stack){
    if(stack==NULL){
        return;
    }
    free(stack);
}
