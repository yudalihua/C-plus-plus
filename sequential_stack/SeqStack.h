#ifndef SEQSTACK_H
#define SEQSTACK_H

#define MAX_SIZE 1024

//the struct is important!!!
typedef struct SEQSTACK(
    void* data[MAX_SIZE];
    int size;

)SeqStack;

#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

//initialization
SeqStack* Init_SeqStack();

//push
void Push_SeqStack(SeqStack* stack, void* data);

//return the top element of the stack
void* Top_SeqStack(SeqStack* stack);

//pop
void* Pop_SeqStack(SeqStack* stack);

//whether the stack is empty
int IsEmpty(SeqStack* stack);

//return the size of stack
int Size_SeqStack(SeqStack* stack);

//destroy the stack
void FreeSpace_SeqStack(SeqStack* stack);

//clear the stack
void Clear_SeqStack(SeqStack* stack);

#endif