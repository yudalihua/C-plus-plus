#ifndef LINKLIST_H
#define LINKLIST_H


//node sturct of the list.
typedef struct LinkNode{
    void* data;
    struct LinkNode* next;
}LinkNode; 

//list struct
typedef struct LinkList{
    LinkNode* head;
    int size;
    //linked list has no concept of capacity
}LinkList;

LinkList * Init_LinkList();
//insert from a specified position
void Insert_LinkList(LinkList * list,int pos ,void* data);

//delete specified value by position
void RemoveByPos_LinkList(LinkList *list, int pos);

//get the length of linklist
int Size_LinkList(LinkList *);

//find
int Find_linkList(LinkList* list, void* data);

//return the value of first value
void* Front_LinkList(LinkList* list);

//print the nodes of LinkList
void Print_LinkList(LinkList* list,PRINTLINKNODE print);

//release the memory of the LinkList
void FreeSpace_LinkList(LinkList* list);












#endif
