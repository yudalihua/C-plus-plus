#include "circular_link_list.h"
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

typedef struct MYNUM{
    CircularLinkNode node;
    int val;

}MyNum;

int M=8;
int N=3;

void MyPrint(CircularLinkNode* data){
    MyNum* num=(MyNum*)data;
    printf("%d, ",num->val);
    
}

int MyCompare(CircularLinkNode* data1,CircularLinkNode* data2){
    MyNum* num1=(MyNum*) data1;
    MyNum* num2=(MyNum*)data2;
    if(num1->val==num2->val){
        return CIRCULARLINKLIST_TRUE;
    }
    return CIRCULARLINKLIST_FALSE;
}
int main(void){
    //create circular link list.
    CircularLinkList* list=Init_CircularLinkList();

    MyNum num[M];
    int i;
    for(i=0;i<8;i++){
        num[i].val=i+1;
        Insert_CircularLinkList(list,i,(CircularLinkNode*)&num[i]);
    }

    Print_CircularLinkList(list,MyPrint);
    int index=1;
    CircularLinkNode* pCurrent=list->head.next;
    while(Size_CircularLinkList(list)>1){
        if(index==N){
            MyNum* temNum=(MyNum*)pCurrent;
            printf("%d",temNum);

            //save the latter node of one which is being deleted.
            CircularLinkNode* pNext=pCurrent->next;
            Remove_ByVal_CircularLinkList(list,pCurrent,Mycompare)
            pCurrent=pNext;
            if(pCurrent==&(list->head)){
                pCUrrent=pCurrent->next;
            }
            index=1;
        }
    }
    if(Size_CircularLinkList(list)==1){
        MyNum* num=(MyNum*)Find_CircularLinkList(list);
        printf("%d",num->val);
    }
    else{
        printf("error");
    }

  

  t
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


