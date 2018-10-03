#include "SeqQueue.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct PERSON{
    char name[64];
    int age;
}Person;

int main(void){
    SeqQueue* queue=Init_SeqQueue();

    //generate data
     //generate data
    Person p1={"aaa",10};
    Person p2={"bbb",20};
    Person p3={"ccc",30};
    Person p4={"ddd",40};
    Person p5={"eee",50};
    
    //push data into queue
    Push_SeqQueue(queue,&p1);
    Push_SeqQueue(queue,&p2);
    Push_SeqQueue(queue,&p3);
    Push_SeqQueue(queue,&p4);
    Push_SeqQueue(queue,&p5);

    //output
    while(queue->size>0){
        Person* p=(Person*)Front_SeqQueue(queue);
        printf("name:%s,age:%s",p->name,p->age);
        Pop_SeqQueue(stack);

    }
    FreeSpace_SeqQueue(queue);
}

//initialization
SeqQueue* Init_SeqQueue(){
    
    SeqQueue* queue=(SeqQueue*)malloc(sizeof(SeqQueue));
    int i;
    for(i=0;i<MAX_SIZE;i++){
        queue->data[i]=NULL;
        
    }
    queue->size=0;
    return queue;

}

//push queue
void Push_SeqQueue(SeqQueue* queue, void* data){
    if(queue==NULL){
        return;
    }
    if(data==NULL){
        return;
    }
    if(queue->size==MAX_SIZE){
        return;
    }
    queue->data[queue->size]=data;
    queue->size++;

}

//pop  queue
void Pop_SeqQueue(SeqQueue* queue){

    if(queue==NULL){
        return;
    }
    if(queue->size==0){
        return;
    }
    int i;
    for(i=0;i<queue->size-1;i++){
        queue->data[i]=queue->data[i+1];
    }
    queue->size--;   

}

//return the front element of the queue
void* Front_SeqQueue(SeqQueue* queue){
    if(queue==NULL){
        return;
    }
    if(queue->size==0){
        return;
    }
    return queue->data[0];
}

//return the last element of the queue
void* Back_SeqQueue(SeqQueue* queue){
    if(queue==NULL){
        return;
    }
    if(queue->size==0){
        return;
    }
    return queue->data[queue->size-1];

}

//return the size of queue
int Size_SeqQueue(SeqQueue* queue){
    if(queue==NULL){
        return -1;
    }
    return queue->size;

}

//clear the queue
void Clear_SeqQueue(SeqQueue* queue){
    if(queue==NULL){
        return;
    }
    queue->size=0;


}

//destroy the queue
void FreeSpace_SeqQueue(SeqQueue* queue){
    if(queue==NULL){
    return;
    }
    free(queue);

}