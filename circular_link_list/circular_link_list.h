#ifndef CIRCULAR_LINK_LIST
#define CIRCULAR_LINK_LIST


//the struct of node.
typedef  struct CYCULARLINKNODE{
    struct CIRCULARLINKNODE* next;

}CircularLinkNode;

//the struct of cycular linked list.
typedef struct CIRCULARLINKLIST{
    //head is not a pointer ,it is a struct variable.
    CircularLinkNode head;
    int size;

}CircularLinkList;

typedef  int(*COMPARENODE)(CircularLinkNode*,CircularLinkNode*);

typedef void(*PRINTNODE)(CircularLinkNode*);

CircularLinkList* Init_CircularLinkList();


//insert
void Insert_CircularLinkList(CircularLinkList* list,int pos, CircularLinkNode* data);

//get the firsr element
CircularLinkList* Front_CircularLinkList(CircularLinkList* list);

//remove node by position
void Remove_ByPos_CircularLinkList(CircularLinkList* list, int pos);

void Remove_ByVal_CircularLinkList(CircularLinkList* list, CircularLinkNode* data,COMPARENODE compare);
int Size_CircularLinkList(CircularLinkList* list);
int IsEmpty(CircularLinkList* list);
int Find_CircularLinkList(CircularLinkList* list,CircularLinkNode* data, COMPARENODE compare);
void Print_CircularLinkList(CircularLinkList* list,PRINTNODE print);

void FreeSpace_CircularLinkList(CircularLinkList* list);
















#endif
