//Heapsort

#include<stdio.h>
#include<stdlib.h>
#define size 1000000

struct heap{
	int arr[size+1];
	int n;
};

typedef struct heap heap;

void swap(int id1, int id2, int arr[]){
	int temp = arr[id1];
	arr[id1] = arr[id2];
	arr[id2] = temp;
	return;
}

void reduceKey(int id, int x, heap * h){
	if(h->n == 1){
	       	h->arr[1] = x;
		return;
	}
	int q = id;
	int p = id/2;
	h->arr[id] = x;
	while(p >= 1){
		if(h->arr[p] > h->arr[q]){
			swap(p, q, h->arr);
			q = p;
			p = p/2;
		}
		else{
			break;
		}
	}
}

void increaseKey(int id, int x, heap * h){
	h->arr[id]=x;
	int len=h->n;
	while(2*id <= len){
		if(2*id+1 <= len){
			if((h->arr[2*id] >= h->arr[id])&&(h->arr[2*id+1] >= h->arr[id])){
			       break;
			}
			else if(h->arr[2*id] <= h->arr[2*id+1]){
				swap(2*id, id, h->arr);
				id = 2*id;
			}
			else{
				swap(2*id+1, id, h->arr);
				id = 2*id + 1;
			}
		}
		else{
			if((h->arr[2*id]>=h->arr[id])){
				break;
			}
			else{
				swap(2*id, id, h->arr);
				id = 2*id;
			}
		}
	}
}

int findmin(heap * h){
	return h->arr[1];
}

int delMin(heap * h){
	int x = h->arr[1];
	int y = h->arr[h->n];
	h->arr[1] = -1;
	h->arr[h->n] = 0;
	h->n--;
	increaseKey(1, y, h);
	return x;
}

void insert(int x, heap * h){
	h->n++;
	h->arr[h->n] = 500001;
	reduceKey(h->n, x, h);
}

void print(heap * h){
	for(int i = 1; i <= h->n; i++){
		printf("%d\n", h->arr[i]);
	}
	printf("-------------\n");
}

int main(){
	heap * h = (heap *)malloc(sizeof(heap));
	h->n = 0;
	h->arr[0] = 0;
	for(int i = 1; i <= size; i++){
		h->arr[i] = -1;
	}
	FILE * fp = fopen("number.txt", "r");
	int num;
	for(int i = 1; i <= size; i++){
		fscanf(fp,"%d", &num);
		insert(num, h);
	}
	for(int i = 1; i <= size; i++){
		printf("%d\n", delMin(h));
	}
	free(h);
	return 0;
}
