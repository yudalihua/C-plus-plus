#include "LinkStack.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct PERSON{
    LinkNode node;
    char name[64];
    int age;
}Person;

int main(void){
    //create a link stack
    LinkStack* stack=Init_LinkStack();

    //generate data
    Person p1,p2,p3,p4,p5;
    strcpy(p1.name,"aaa");
    strcpy(p2.name,"bbb");
    strcpy(p3.name,"ccc");
    strcpy(p4.name,"ddd");
    strcpy(p5.name,"eee");
    
    p1.age=10;
    p2.age=20;
    p3.age=30;
    p4.age=40;
    p5.age=50;

    //push stack
    Push_LinkStack(stack,(LinkNode*)&p1);
    Push_LinkStack(stack,(LinkNode*)&p2);
    Push_LinkStack(stack,(LinkNode*)&p3);
    Push_LinkStack(stack,(LinkNode*)&p4);
    Push_LinkStack(stack,(LinkNode*)&p5);

    //
    while(Size_LinkStack>0){
        Person* p=(Person*)Top_LinkStack(stack);
        printf("name:%s,age:%d",p->name,p->age);
        //pop
        Pop_LinkStack(stack);
    }

}


//initialization
LinkStack* Init_LinkStack(){
    LinkStack* stack=(LinkStack*)malloc(sizeof(LinkStack));
    stack->head.next=NULL;
    stack->size=0;

}

//push
void Push_LinkStack(LinkStack* stack, void* data){
    if(stack==NULL){
        return;
    }
    if(data==NULL){
        return;
    }
    data->next=stack->head.next;
    stack->head.next=data;
    size++;


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