#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdlib.h>
#include<stdio.h>
//node of the linklist
typedef struct LINKNODE{
    struct LINKNODE* next;

}LinkNode;

//
typedef struct LINKLIST{
    LinkNode head;
    int size;
}LinkList;

typedef void (*PRINTNODE)(LinkNode*);

LinkList* Init_LinkList();

void Insert_LinkList(LinkList* list,int pos,LinkNode* data);

void Remove_LinkList(LinkList* list,int pos);

int Size_LinkList(LinkList* list);

void Print_LinkList(LinkList* list,PRINTNODE print);

void Free_Space_LinkList(LinkList list);

int Find_LinkList(LinkList* list,LinkNode* data);