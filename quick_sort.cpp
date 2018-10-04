#include<iostream>
using namespace std;


long GetSystemTime(){
    struct timeb tb;
    ftime(&tb);
    return tb.time*1000+tb.millitm;
}

void PrintArray(int arr[],int len){
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    } 
    cout<<endl;

}
//quick sort, form the small to the big.
void QuickSort(int arr[],int start,int end){
    int i=start;
    int j=end;
    //benchmark number;
    int temp=arr[start];
    if(i<j){
        while(i<j){
            //search the element that is smaller than base number from right to left;
            while(i<j && arr[j]>=temp){
                j--;
            }
            if(i<j){
                arr[i]=arr[j];
                i++;
            }
            //search the element that is bigger than base number from right to left;
            while(i<j && arr[i]<=temp){
                i++;
            }
            if(i<j){
                arr[j]=arr[i];
                j--;
            }

        }
        arr[i]=temp;
        //recursively call the QuickSort;
        QuickSort(arr,start,i-1);
        QuickSort(arr,i+1,end);
    }

    
}
int main(void){
    int arr[]={4,2,8,0,5,7,1,3,9};
    int len=sizeof(arr)/sizeof(int);  
    	      
    PrintArray(arr,len);
    //long t_start=GetSystemTime();
    QuickSort(arr,0,len-1);
    //long t_ending=GetSystemTime();
    PrintArray(arr,len);
    //printf("sort time:%ld\n",t_ending-t_start);
    return 0;
}
