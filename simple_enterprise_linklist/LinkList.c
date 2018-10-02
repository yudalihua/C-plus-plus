#include "LinkList.h"

LinkList* Init_LinkList(){
    LinkList* list=(LinkList*)malloc(sizeof(LinkList));
    list->head.next=NULL;
    list->size=0;
    return list;

}

void Insert_LinkList(LinkList* list,int pos,LinkNode* data){
    if(list==NULL){
        return;
    }
    if(data==NULL){
        return;
    }
    if(pos<0 || pos>list->size){
        pos=list->size;
    }
    //find the insertion point.
    LinkNode* pCurrent=&(list->head);
    int i;
    for(i=0;i<pos;i++){
        pCurrent=pCurrent->next;
    }

    //insert new node. this way we do not need a medium node.
    data->next=pCurrent->next;
    pCurrent->next=data;
    list->size++;

}

int Size_LinkList(LinkList* list){
    return list->size;

}

void Print_LinkList(LinkList* list,PRINTNODE print){
    if(list==NULL){
        return;
    }
    LinkNode* pCurrent=&(list->head)->next;
    while(pCurrent != NULL){
        print(pCurrent);
        pCurrent=pCurrent->next;
    }


}

void Free_Space_LinkList(LinkList list){
    if(list==NULL){
        return;
    }
    free(list);
    }
