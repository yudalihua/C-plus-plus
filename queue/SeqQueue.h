#ifndef SEQQUEUE_H
#define SEQQUEUE_H


#define MAX_SIZE 8
typedef struct SEQQUEUE{
    void* data[MAX_SIZE];
    int size;

}SeqQueue;



//initialization
SeqQueue* Init_SeqQueue();

//push queue
void Push_SeqQueue(SeqQueue* queue, void* data);

//pop  queue
void Pop_SeqQueue(SeqQueue* queue);

//return the front element of the queue
void* Front_SeqQueue(SeqQueue* queue);

//return the last element of the queue
void* Back_SeqQueue(SeqQueue* queue);


//return the size of queue
int Size_SeqQueue(SeqQueue* queue);

//clear the queue
void Clear_SeqQueue(SeqQueue* queue);

//destroy the queue
void FreeSpace_SeqQueue(SeqQueue* queue);

#endif