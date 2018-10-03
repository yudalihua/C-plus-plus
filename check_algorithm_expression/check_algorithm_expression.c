#include "LinkStack.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct MYCHAR{
    LinkNode node;    
    char* pAddr;
    int index;
}MyChar;

MyChar* Create_MyChar(char* p,int index){
    MyChar* mychar=(MyChar*)malloc(sizeof(MyChar));
    mychar->pAddr=p;
    mychar->index=index;
    return mychar;
}

int IsLeft(char c){
    return c=='(';
}
int IsRight(char c){
    return c==')';
}

void ShowError(char* str,int pos){
    printf("%s",str);
    int i;
    for(i=0;i<pos;i++){
        printf(" ");
    }
    printf("A");
}

int main(void){

    LinkStack* stack=Init_LinkStack();
    char* str="1+2*5*(2_8)ds(()";
    int index=0;
    char* p=str;
    while(*p!='\0'){

        //when we meet the left bracket,push it into stack
        if(IsLeft(*p)){
            Push_LinkStack(stack,Create_MyChar(p,index));
        }
        //when we meet the right bracket,pop the stack ,and find whether the top element is left bracket.
        if(IsRight(*p)){
            if(Size_SeqStack(stack)>0){
                MyChar* mychar=(MyChar*)Top_LinkStack(stack);
                if(IsLeft(*(mychar->pAddr))){
                    Pop_LinkStack(stack);
                    free(mychar);
                 }   
            }
                    
        }
        else {
            printf("there is no equivalent left bracket to the right bracket\n");
            ShowError(str,index);
            break;
           
        }
        p++;
        index++;
    }
    while(Size_LinkStack(stack)>0){
        MyChar* mychar=(MyChar*)Top_LinkStack(stack);
        printf("there is no equivalent left bracket to the right bracket\n");
        ShowError(str,mychar->index);
        Pop_LinkStack(stack);
        free(mychar);

    }
   
}


//initialization
LinkStack* Init_LinkStack(){
    LinkStack* stack=(LinkStack*)malloc(sizeof(LinkStack));
    stack->head.next=NULL;
    stack->size=0;

}


//push
void Push_LinkStack(LinkStack* stack, void* data){
    if(stack==NULL){
        return;
    }
    if(data==NULL){
        return;
    }
    data->next=stack->head.next;
    stack->head.next=data;
    stack->size++;


}

//pop
void Pop_LinkStack(LinkStack* stack){
    
    if(stack==NULL){
        return;
    }
    if(stack->size==0){
        return;
    }
    //the first valid node.
    LinkNode* pFirst=stack->head.next;
    stack->head.next=pFirst->next;
    stack->size--;


}

//return the top element of the stack
void* Top_LinkStack(LinkStack* stack){
     if(stack==NULL){
        return NULL;
    }
    if(stack->size==0){
        return NULL;
    }
    return stack->head.next;

}

//whether the stack is empty
int IsEmpty(LinkStack* stack){
    if(stack==NULL){
        return -1;
    }
}

//return the size of stack
int Size_LinkStack(LinkStack* stack){
    if(stack==NULL){
        return -1;
    }
    return stack->size;}




//clear the stack
void Clear_LinkStack(LinkStack* stack){
    if(stack==NULL){
        return;
    }
    stack->head.next=NULL;
    stack->size=0;
}

//destroy the stack
void FreeSpace_LinkStack(LinkStack* stack){
    if(stack==NULL){
        return;
    }
    free(stack);
}
