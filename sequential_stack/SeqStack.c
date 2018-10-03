#include "SeqStack.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct PERSON{
    char name[64];
    int age;
}Person;

int main(void){
    //create a stack
    SeqStack* stack=Init_SeqStack();

    //generate data
    Person p1={"aaa",10};
    Person p2={"bbb",20};
    Person p3={"ccc",30};
    Person p4={"ddd",40};
    Person p5={"eee",50};

    //push data to stack
    Push_SeqStack(stack,&p1);
    Push_SeqStack(stack,&p2);
    Push_SeqStack(stack,&p3);
    Push_SeqStack(stack,&p4);
    Push_SeqStack(stack,&p5);

    //output the elements of the stack
    while(Size_SeqStack(stack)>0){
        //the Top_SeqStack return the pointer of value of element. transform the pointer type ,and we can get the value.
        Person* person=(Person*)Top_SeqStack(stack);
        printf("name:%s,age:%d",person->name,person->age);

        //pop
        Pop_SeqStack(stack)
    }
    FreeSpace_SeqStack(stack);

}
//initialization
SeqStack* Init_SeqStack(){
    SeqStack* stack=(SeqStack*)malloc(sizeof(SeqStack));
    int i;
    for(i=0;i<MAX_SIZE;i++){
        stack->data[i]=NULL;
    }
    stack->size=0;

}

//push
void Push_SeqStack(SeqStack* stack, void* data){
    if(stack==NULL){
        return;
    }
    if(data==NULL){
        return;
    }
    if(stack->size==MAX_SIZE){
        return;
    }
    stack->data[stack->size]=data;
    stack->size++;
    
}

//return the top element of the stack
void* Top_SeqStack(SeqStack* stack){
    if(stack==NULL){
        return NULL;
    }
    stack->data[stack->size-1];
}

//pop
void* Pop_SeqStack(SeqStack* stack){
    if(stack==NULL){
        return;
    }
    if(stack->size==0){
        return;
    }
    stack->size--;
}

//whether the stack is empty
int IsEmpty(SeqStack* stack){
    if(stack==NULL){
        return -1;
    }
    if(stack->size==0){
        return SEQSTACK_TRUE;
    }
    return SEQSTACK_FALSE;

}

//return the size of stack
int Size_SeqStack(SeqStack* stack){
    return stack->size;

}

//clear the stack
void Clear_SeqStack(SeqStack* stack){
    if(stack==NULL){
        return;
    }
    stack->size=0;
}

//destroy the stack
void FreeSpace_SeqStack(SeqStack* stack){
    if(stack == NULL){
        return;
    }
    free(stack);   

}