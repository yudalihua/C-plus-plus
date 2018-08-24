#include "DYNAMIC_ARRAY.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

dynamic_array * init_array(){
	dynamic_array* my_array=malloc(sizeof(dynamic_array));
	
	my_array ->size=0;
	my_array->capacity=20;
	my_array->ptr_addr=(int*)malloc(sizeof(int)*my_array->capacity);//int*��ǿ������ת���� 
	
	return my_array;
}
void push_back_array(dynamic_array* arr,int value){
	if (arr=NULL){
		return;
	}
	//�ж��Ƿ��пռ�
	if(arr->size==arr->capacity){
		//��һ���������ڴ�ռ䣬�¿ռ���ԭ�ռ��������
		int* new_space=malloc(sizeof(int)*arr->capacity*2);
		//�ڶ������������ݵ��¿ռ䡣��memcpy������
		memcpy(new_space,arr->ptr_addr,arr->capacity*sizeof(int));//��Ϊ������ʱ�������ֽ�Ϊ��λ�� 
		//���������ͷžɿռ���ڴ档 
		free(arr->ptr_addr);
		//���Ĳ�������������
		arr->capacity=arr->capacity*2;
		arr->ptr_addr=new_space; 
	} 
	//������Ԫ��
	arr->capacity[arr->size]=value;
	arr->size++; 


}
void remove_ByPos_array(dynamic_array* arr, int pos){
	if(arr=NULL){
		return;
	}
	//�ж�λ���Ƿ���Ч��
	if(pos<0||pos>=arr->size){
		return;
	} 
	//ɾ��Ԫ�ء��±���size-1�����3�����ݣ�λ�ô�0-2.�������1�������λ��3�����ݸ��ǵ�λ��2.��λ��3,2�����������ˡ� 
	for (i=pos;i<arr->size-1;i++){
		arr->ptr_addr[i]=arr->ptr_addr[i+1];
	} 
	arr->size--; 
	
	
}
//����ֵɾ���������ҵ����ֵ��λ�ã�Ȼ��ֱ�ӵ��ø���λ��ɾ���ķ����� 
void remove_ByVal_array(dynamic_array* arr, int value){
	if(arr=NULL){
		return;
	}
	//�ҵ�ֵ��λ�á�
	for(int i=0;i<arr->size;i++){
		if(arr->ptr_addr[i]==value){
			int	pos=i;
			break;//�ҵ����ֵ��һ�γ��ֵ�λ�ã�Ȼ�����ɾ���� 
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
