#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 1000000

void merge(int left, int right, int * arr){
	//printf("*(%d, %d)\n", arr[left], arr[right]);
	int leftlim = (left+right)/2;
	int rightlim = right;
	int lp = left;
	int rp = leftlim + 1;
	int temp[right-left+1];
	int id = 0;
	while((lp<=leftlim)&&(rp<=rightlim)){
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
	while(rp<=rightlim){
		temp[id] =arr[rp];
		rp++;
		id++;
	}
	while(lp <=leftlim){
		temp[id] = arr[lp];
		lp++;
		id++;
	}
	//printf("**(%d, %d)\n", temp[0], temp[1]);
	for(int i = 0; i <= right - left; i++){
		arr[left + i] = temp[i];
	}
	return;
}

int main(){
	int len = 1;
	int step = 0;
	FILE * fp = fopen("number.txt", "r");
	while(len < size){
		len = len*2;
		step++;
	}
	printf("%d\n", len);
	int arr[len];
	//int arr[size];
	for(int i = 0; i < size; i++){
		fscanf(fp, "%d", &arr[i]);
	}
	printf("\n\n");
	for(int j = size; j < len; j++){
		arr[j] = 500001;
	}
	int set, start;
	for(int i = 1; i <= step; i++){
		set = 1;
		for(int j = 0; j < i; j++){
			set = set*2;
		}
		start = 0;
		while(start + set - 1<len){
			merge(start, start + set - 1, arr);
			start = start + set;
		}
		//merge
	}
	for(int i = 0; i < size; i++){
		printf("%d\n", arr[i]);
	}
	return 0;
}
