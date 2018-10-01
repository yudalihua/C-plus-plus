#include "LinkList.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Person{
	char name[64];
    int age;
    int score;
}Person;

void MyPrint(void* data){
    Person* p=(Person*)data;
    printf("name:%s age:%d score:%d\n",p->name,p->age,p->score);
}


int main(void){
    //create linklist
    LinkList* list=Init_LinkList();

    //create data;
    Person p1={'aa',18,99};
    Person p2={'bb',19,56};
    Person p3={'cc',20,78};
    Person p4={'dd',21,87};
    Person p5={'ee',22,60};

    //insert the data to linklist.
    Insert_LinkList(list,0,&p1);
    Insert_LinkList(list,1,&p2);
    Insert_LinkList(list,2,&p3);
    Insert_LinkList(list,3,&p4);
    Insert_LinkList(list,4,&p5);

    //print the linklist
    Print_LinkList(list,MyPrint);

    //destroy linklist
    FreeSpace_LinkList(list);


    printf("\n");
    system("pause");
    return 0;
}

//initialize a LinkList
LinkList * Init_LinkList(){
    //create a linklist.
    LinkList* list=(LinkList*)malloc(sizeof(LinkList));
    list->size=0;
    //create the head node of the linklist.
    list->head=(LinkNode*)malloc(sizeof(LinkNode));

    //initialize the head node.
    list->head->data=NULL;
    list->head->next=NULL;

    return list;


}
//insert from a specified position
void Insert_LinkList(LinkList * list,int pos ,void* data){
    if(list==NULL){
        return;
    }
    if(data==NULL){
        return;
    }
    if(pos<0 || pos>list->size){
        pos=list->size;
    }

    //1.create new linknode
    LinkNode* new_node=(LinkNode*)malloc(sizeof(LinkNode));
    new_node->data=data;
    new_node->next=NULL;

    //2.search the node before the insertion point.
    LinkNode* pCurrent=list->head;
    int i;
    for(i=0;i<pos;i++){
        pCurrent=pCurrent->next;
    }
    //3.insert the new node.
    new_node->next=pCurrent->next;
    pCurrent->next=new_node;
    list->size++;
}

//delete specified value by position
void RemoveByPos_LinkList(LinkList *list, int pos){
    if(list==NULL){
        return;
    }
    if(pos<0 || pos>list->size){
        return;
    }
    //search the former node of the object node.
    LinkNode* pCurrent=list->head;
    int i;
    for(i=0;i<pos;i++){
        pCurrent=pCurrent->next;
    }
    //save the node which is being deleted
    LinkNode* pDel=pCurrent->next;
    pCurrent->next=pDel->next;
    free(pDel);
    
    list->size++;
}

//get the length of linklist
int Size_LinkList(LinkList * list){
    return list->size;
}

//findn node by data.
int Find_linkList(LinkList* list, void* data){
    if(list==NULL){
        return -1;
    }
    if(data=NULL){
        return -1;
    }
    //what if there is no node which has the value of data?
    LinkNode* pCurrent=list->head->next;
    int i=0;
    while(pCurrent != NULL){
        if(pCurrent->data==data){
            break;
        }
        i++;
        pCurrent=pCurrent->next;
    }
    return i;
}

//return the pointer to the first node
void* Front_LinkList(LinkList* list){
    return list->head->next;
}

//print the nodes of LinkList. pass the linklist and the recall the print function when we print each node of linklist.
void Print_LinkList(LinkList* list,PRINTLINKNODE print){
    if(list==NULL){
        return;
    }

    LinkNode* pCurrent=list->head->next;
    while(pCurrent != NULL){
        print(pCurrent->data);
        pCurrent=pCurrent->next;
    }
}

//release the memory of the LinkList
void FreeSpace_LinkList(LinkList* list){
    if(list==NULL){
        return;
    }

    LinkNode* pCurrent=list->head;
    //release the memory of nodes.before delete one node,we need first save the next node.
    while(pCurrent != NULL){
        LinkNode* pNext=pCurrent->next;
        free(pCurrent);
        pCurrent=pNext;
    }
    free(list);
}

