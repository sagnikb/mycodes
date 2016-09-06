#include<stdio.h>
#include<stdlib.h>
#define size 800000

void merge(int right, int * arr){
	int i = 0;
	while(arr[i] <= arr[right]){
		i++;
	}
	int temp;
	for(int j = right; j > i; j--){
		temp = arr[j];
		arr[j] = arr[j-1];
		arr[j-1] = temp;
	}
}
void insertionSort(int right, int arr[]){
	if(right==0) return;
	insertionSort(right - 1, arr);
	merge(right, arr);
}

int main(){
	int arr[size];
	FILE * fp = fopen("number.txt", "r");
	for(int i = 0; i < size; i++){
		fscanf(fp, "%d", &arr[i]);
	}
	printf("\n");
	insertionSort(size-1, arr);
	//merge(size-1, arr);
	for(int i = 0; i < size; i++){
		printf("%d\n", arr[i]);
	}
	return 0;
}

