#include<stdio.h>

struct n{
	int data;
	struct n * next;
}

typedef struct n * node;

struct q{
	node front;
	node rear;
}

node makeNode(int x){
	node = (node)malloc(sizeof(struct n));
	node->data = x;
	node->next = NULL;
	return node;
}



int main(){
	
	return 0;
}
