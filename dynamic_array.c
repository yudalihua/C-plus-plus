#include "DYNAMIC_ARRAY.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

dynamic_array * init_array(){
	dynamic_array* my_array=malloc(sizeof(dynamic_array));
	
	my_array ->size=0;
	my_array->capacity=20;
	my_array->ptr_addr=(int*)malloc(sizeof(int)*my_array->capacity);//int*是强制类型转换。 
	
	return my_array;
}
void push_back_array(dynamic_array* arr,int value){
	if (arr=NULL){
		return;
	}
	//判断是否还有空间
	if(arr->size==arr->capacity){
		//第一步，申请内存空间，新空间是原空间的两倍。
		int* new_space=malloc(sizeof(int)*arr->capacity*2);
		//第二步，拷贝数据到新空间。用memcpy函数。
		memcpy(new_space,arr->ptr_addr,arr->capacity*sizeof(int));//因为拷贝的时候是以字节为单位。 
		//第三步，释放旧空间的内存。 
		free(arr->ptr_addr);
		//第四步，更新容量。
		arr->capacity=arr->capacity*2;
		arr->ptr_addr=new_space; 
	} 
	//插入新元素
	arr->capacity[arr->size]=value;
	arr->size++; 


}
void remove_ByPos_array(dynamic_array* arr, int pos){
	if(arr=NULL){
		return;
	}
	//判断位置是否有效。
	if(pos<0||pos>=arr->size){
		return;
	} 
	//删除元素。下边是size-1，如果3个数据，位置从0-2.如果不减1，最后会把位置3的数据覆盖到位置2.但位置3,2都不属于我了。 
	for (i=pos;i<arr->size-1;i++){
		arr->ptr_addr[i]=arr->ptr_addr[i+1];
	} 
	arr->size--; 
	
	
}
//根据值删除，是先找到这个值的位置，然后直接调用根据位置删除的方法。 
void remove_ByVal_array(dynamic_array* arr, int value){
	if(arr=NULL){
		return;
	}
	//找到值的位置。
	for(int i=0;i<arr->size;i++){
		if(arr->ptr_addr[i]==value){
			int	pos=i;
			break;//找到这个值第一次出现的位置，然后进行删除。 
		}
	} 
	remove_ByPos_array(arr,pos);
	
	
}
void find_array (dynamic_array * arr,int value){
	
	if(arr=NULL){
		return;
	}
		for(int i=0;i<arr->size;i++){
			if(arr->ptr_addr[i]==value){
				pos=i;
				break;
			}
		}
	return pos; 
}
void free_space_array(dynamic_array* arr){
	if (arr=NULL){
		return;
	}
	if(arr->ptr_addr!=NULL){
		free(arr->ptr_addr);
	}
	
}

void print_array(dynamic_array * arr){
	if (arr==NULL){
		return;
	}
	for (int i=0;i<arr->size;i++){
		printf("%d",arr->ptr_addr[i]);
	}
	printf("\n");
	
}

void clear_array(dynamic_array * arr){
	if (arr=NULL){
		return;
	}
	arr->size=0;
	
}
int capacity_array(dynamic_array* arr){
	if (arr=NULL){
		return;
	}
	
	return arr->capacity;
	
}
int size_array(dynamic_array* arr){
	if (arr=NULL){
		return;
	}
	return arr->size;
	
}







int main(int argc, char** argv) {
	return 0;
}
