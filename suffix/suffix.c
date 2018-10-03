#include "suffix.h"
#include<stdlib.h>
#include<stdio.h>

//the struct of data stored in stack.
typedef struct MYNUM{
    LinkNode node;    
    int val;
}MyNum;


//determine whether is number
int IsNumber(char c){
    return c>='0' && c<='9';
}
int Calculate(int left,int right,char c){
    int ret=0;
    switch(c){
        case '+':
            ret=left+right;
            break;
        case '-':
            ret=left-right;
            break;
        case '*':
            ret=left*right;
            break;
        case '/':
            ret=left/right;
            break;
    }
}







//the main function
int main(void){    
    LinkStack* stack=Init_LinkStack();
    //the sufix experssion
    char* str="831-5*+";    
    char* p=str;
    while(*p!='\0'){

        if(IsNumber(*p)){
            MyNum* num=(MyNum*)malloc(sizeof(MyNum));
            num->val=*p -'0';       
            Push_LinkStack(stack,(LinkNode*)num);    
        }
        else{
            //get the right operand.
            MyNum* right=(MyNum*)Top_LinkStack(stack);
            int RightNum=right->val;
            Pop_LinkStack(stack);
            free(right);

            //get the left operand.
            MyNum* left=(MyNum*)Top_LinkStack(stack);
            int LeftNum=left->val; 
            Pop_LinkStack(stack);
            free(left);

            //calculate the result,and push the result into stack.
            int ret=Calculate(LeftNum,RightNum,*p);
            MyNum* result=(MyNum*)malloc(sizeof(MyNum));
            result->val=ret;
            Push_LinkStack(stack,result);
        }         
       p++;   
    }
    if(Size_LinkStack(stack)==1){
        MyNum* num=(MyNum*)Top_LinkStack(stack);
        printf("the result of the expression is %d:\n",num->val);
        Pop_LinkStack(stack);
        free(num);
        }
    FreeSpace_LinkStack(stack);
  
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
