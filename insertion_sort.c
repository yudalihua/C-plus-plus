#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10
int arr[MAX];
void Swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

long GetSystemTime(){
    struct timeb tb;
    ftime(&tb);
    return tb.time*1000+tb.millitm;
}

void PrintArray(int arr[],int length){
    int i;
    for(i=0;i<length;i++){
        printf("%d",arr[i]);
        
    }
    printf("\n");

}

void InsertionSort(int arr[],int length){
    int i;
    int j;
    for(i=1;i<length;i++){
        if(arr[i]<arr[i-1]){
            int temp =arr[i];
            for(j=i-1;j>=0 && temp<arr[j];j--){
                arr[j+1]=arr[j];

            }  
            arr[j+1]=temp;
        }
    }
}
int main(void){
    
    srand((unsigned int)time(NULL));
    int i;
    for(i=0;i<MAX;i++){
        arr[i]=rand()%MAX;
    }
    PrintArray(arr,MAX);
    long t_start=GetSystemTime();
    InsertionSort(arr,MAX);
    long t_ending=GetSystemTime();
    PrintArray(arr,MAX);
    //printf("sort time:%ld\n",t_ending-t_start);
    return 0;
}
