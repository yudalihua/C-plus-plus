#ifndef SUFFIX_H
#define SUFFIX_H

//the node struct of linked stack.
typedef struct LinkNode{
	struct LinkNode* next;
}LinkNode;
    
typedef struct LINKSTACK{
    LinkNode head;
    int size;
}LinkStack;


//initialization
LinkStack* Init_LinkStack();

//push
void Push_LinkStack(LinkStack* stack, void* data);

//pop
void Pop_LinkStack(LinkStack* stack);

//return the top element of the stack
void* Top_LinkStack(LinkStack* stack);

//whether the stack is empty
int IsEmpty(LinkStack* stack);

//return the size of stack
int Size_LinkStack(LinkStack* stack);

//clear the stack
void Clear_LinkStack(LinkStack* stack);

//destroy the stack
void FreeSpace_LinkStack(LinkStack* stack);

#endif
