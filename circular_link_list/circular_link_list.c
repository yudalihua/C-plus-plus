#include "circular_link_list.h"
#include<stdlib.h>
#include<stdio.h>
#include <string.h>


typedef struct PERSON{
    CircularLinkNode node;
    char name[64];
    int age;
    int score;
}Person;
void MyPrint(CircularLinkNode* data){
    Person* p=(Person*)data;
    printf("name:%s,age:%d,score:%d",p->name,p->age,p->score);
    
}
int main(void){
    //create circular link list.
    CircularLinkList* list=Init_CircularLinkList();

    //create data;
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


    p1.score=50;
    p2.score=60;
    p3.score=70;
    p4.score=80;
    p5.score=90;

    //put the data to circular link list
    Insert_CircularLinkList(list,100,(CircularLinkNode*)&p1);
    Insert_CircularLinkList(list,100,(CircularLinkNode*)&p2);
    Insert_CircularLinkList(list,100,(CircularLinkNode*)&p3);
    Insert_CircularLinkList(list,100,(CircularLinkNode*)&p4);
    Insert_CircularLinkList(list,100,(CircularLinkNode*)&p5);

    //print the nodes
    Print_CircularLinkList(list,MyPrint);

    //free space of circular link list
    Free_Space_LinkList(list);       

}

CircularLinkList* Init_CircularLinkList(){
    CircularLinkList* list=(CircularLinkList*)malloc(sizeof(CircularLinkList));
    //the head node points to itself. use the linklist of enterprise.
    list->head.next=&(list->head);
    list->size=0;
}
//insert
void Insert_CircularLinkList(CircularLinkList* list,int pos, CircularLinkNode* data){
    if(list==NULL){
        return;
    }
    if(data==NULL){
        return;
    }
    if(pos<0 || pos>list->size){
        pos=list->size;
    }
    //create a medium node
    CircularLinkNode* pCurrent=&(list->head);
    int i;
    for(i=0;i<pos;i++){
        pCurrent=pCurrent->next;
    }
    data->next=pCurrent->next;
    pCurrent->next=data;
    list->size++;


}

//get the firsr element
CircularLinkList* Front_CircularLinkList(CircularLinkList* list){
    return list->head.next;
}

//remove node by position
void Remove_ByPos_CircularLinkList(CircularLinkList* list, int pos){
    if(list==NULL){
        return;
    }
    if(pos<0 ||pos>=list->size){
        return;
    }
    CircularLinkNode* pCurrent=&(list->head);
    int i;
    for(i=0;i<pos;i++){
        pCurrent=pCurrent->next;
    }
    CircularLinkNode* pNext=pCurrent->next;
    pCurrent->next=pNext->next;
    list->size--;
    

}

void Remove_ByVal_CircularLinkList(CircularLinkList* list, CircularLinkNode* data,COMPARENODE compare){
    if(list==NULL){
        return;
    }
    if(data==NULL){
        return;
    }
    CircularLinkNode* pPrev=&(list->head);
    CircularLinkNode* pCurrent=pPrev->next;    
    int i;
    for(i=0;i<list->size;i++){
        if(compare(pCurrent,data)==CIRCULARLINKLIST_TRUE){
            pPrev->next=pCurrent->next;           
            break;
        }
        //the pointer of the object node and the former one move from head to tail.
        pPrev=pCurrent;
        pCurrent=pPrev->next;     

    }
   

}

int Size_CircularLinkList(CircularLinkList* list){
    return list->size;

}
int IsEmpty(CircularLinkList* list){
    if(list->size==0){
        return CIRCULARLINKLIST_TRUE;
    }
    return CIRCULARLINKLIST_FALSE;

}

int Find_CircularLinkList(CircularLinkList* list,CircularLinkNode* data, COMPARENODE compare){
    if(list==NULL){
        return -1;
    }
    if(data==NULL){
        return -1;
    }
    CircularLinkNode* pCurrent=list->head.next;
    int i;
    int flag=-1;
    for(i=0;i<list->size;i++){
        if(compare(pCurrent,data)==CIRCULARLINKLIST_TRUE){
            flag=i;
            break;
        }
        pCurrent=pCurrent->next;

    }
    return flag;

}

void Print_CircularLinkList(CircularLinkList* list,PRINTNODE print){
    if(list==NULL){
        return;
    }
    CircularLinkNode* pCurrent=list->head.next;
    int i;
    for(i=0;i<list->size;i++){
        print(pCurrent);
        pCurrent=pCurrent->next;
    }   

}

void FreeSpace_CircularLinkList(CircularLinkList* list){
    if(list==NULL){
        return;
    }
    free(list);

}


