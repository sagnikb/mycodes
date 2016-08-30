#include<stdio.h>
#include<stdlib.h>
#define size 1000000

void merge(int left, int right, int * arr){
	int leftlim = (left+right)/2;
	int rightlim = right;
	int lp = left;
	int rp = leftlim + 1;
	int temp[right-left+1];
	int id = 0;
	while((lp <= leftlim)&&(rp <= rightlim)){
		if(arr[lp] <= arr[rp]){
			temp[id] = arr[lp];
			lp++;
		}
		else{
			temp[id] = arr[rp];
			rp++;
		}
		id++;
	}
	while(rp <= rightlim){
		temp[id] = arr[rp];
		rp++;
		id++;
	}
	while(lp <= leftlim){
		temp[id] = arr[lp];
		lp++;
		id++;
	}
	for(int i = 0; i <= right - left; i++){
		arr[left+i] = temp[i];
	}
	return;
}

void mergeSort(int left, int right, int arr[]){
	if(left>=right){
		return;
	}
	int middle = (left+right)/2;
	mergeSort(left, middle, arr);
	mergeSort(middle+1, right, arr);
	merge(left, right, arr);
}

int main(){
	FILE * fp = fopen("number.txt", "r");
	int array[size];
	int num;
	for(int i = 0; i < size; i++){
		fscanf(fp, "%d", &num);
		array[i] = num;
	}
	mergeSort(0, size - 1, array);
	for(int i = 0; i < size; i++){
		printf("%d\n",array[i]);
	}
	return 0;
}
