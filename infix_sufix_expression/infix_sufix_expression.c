#include "LinkStack.h"
#include<stdlib.h>
#include<stdio.h>

//the struct of data stored in stack.
typedef struct MYCHAR{
    LinkNode node;    
    char* p;
}MyChar;

//create a struct stored in the stack by the  element of data.
MyChar* Create_MyChar(char* p){

    MyChar* mychar=(MyChar*)malloc(sizeof(MyChar));
    mychar->p=p;

    return mychar;
}
//determine whether is number
int IsNumber(char c){
    return c>='0' && c<='9';
}
int IsLeft(char c){
    return c=='(';
}
int IsRight(char c){
    return c==')';
}
int IsOperator(char c){
    return c=="+" || c=="-" || c=="*" ||c=="/";
}

//return the priority of operators
int GetPriority(char c){
    if(c=="*" || c=="/"){
        return 3;
    }
    if(c=="+" || c=="-"){
        return 2;
    }
    //if the symbol is left bracket,then rturn 0. cause the left bracket has the least priority.   
    return 0;
}

//operations when we meet a character.
int NumberOperation(char* p){
    printf("%c",*p);
}
void LeftOperation(LinkStack* stack,char*p){
    Push_LinkStack(stack,(LinkNode*)Create_MyChar(p));
}
void RightOperation(LinkStack* stack){
      while(Size_LinkStack(stack)>0){
                //get the top element of the stack,and tramsform its type to 'a pointer to mychar',so that we can fetch the data.
               MyChar* mychar=(MyChar*)Top_LinkStack(stack);
               //dereference the top element,if we find a left bracket,we pop it,and break the downside code ,and scan the next character.
               if(IsLeft(*(mychar->p))){
                   Pop_LinkStack(stack);
                   break;
               }
               //dereference the top element,if we find it's not a left bracket,we pop and output it.
               printf("%c",*(mychar->p));
               Pop_LinkStack(stack);
               free(mychar);
           }
}

void OperatorOperation(LinkStack* stack,char* p){
    //get the stack top operator
    MyChar* mychar=(MyChar*)Top_LinkStack(stack);
    if(mychar==NULL){
        Push_LinkStack(stack,(LinkNode*)Create_MyChar(p));
        return;
    }

    //if priority of the top operator is less than the priority of current operator, push the current operator into stack.
    if(GetPriority(*(mychar->p))<GetPriority(*p)){
        Push_LinkStack(stack,(LinkNode*)Create_MyChar(p));
        return;
    }
    else{
        while(Size_LinkStack(stack)>0){
            MyChar* mychar=(MyChar*)Top_LinkStack(stack);
            printf("%c",*(mychar->p));
            Pop_LinkStack(stack);
            free(mychar);

        }
    }  


}


//the main function
int main(void){    
    LinkStack* stack=Init_LinkStack();
    char* str="8+(3-1)*5";    
    char* p=str;
    while(*p!='\0'){

       if(IsNumber(*p)){
           NumberOperation(*p);
       }
       if(IsLeft(*p)){
           LeftOperation(stack,p);
       }
       if(IsRight(*p)){
           RightOperation(stack);
         
       }
       if(IsOperator(*p)){
           OperatorOperation(stack,p);
       }
       p++;      
    }
    while(Size_LinkStack(stack)>0){
        MyChar* mychar=(MyChar*)Top_LinkStack(stack);
        printf("%c",*(mychar->p));
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
