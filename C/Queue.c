#include<stdio.h>
#include<stdlib.h>

struct node{
       int data;
       struct node * next;
};

typedef struct node * node;

struct queue{
       int itemN;
       node front;
       node rear;
};       

typedef struct queue queue;

queue * makeQueue(){
      queue* Q = (queue*)malloc(sizeof(queue));
      Q->front = NULL;
      Q->rear = NULL;
      Q->itemN = 0; 
      return Q;
} 

node makeNode(int x){
     node newNode = (node)malloc(sizeof(struct node));
     newNode->data = x;
     newNode->next = NULL;
     return newNode;
}

int isEmpty(queue Q){
    if(Q.front == NULL){
               return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int x, queue * Q){
	if(isEmpty(*Q)){    
		node newNode = makeNode(x); 
		Q->front = newNode;
                Q->rear = newNode;
		Q->itemN++;
     }
     else{
	  node newNode = makeNode(x);
          Q->rear->next = newNode;
          Q->rear = newNode;
	  Q->itemN++;
     }
}

void dequeue(queue * Q){
	if(isEmpty(*Q)){
		printf("The list is empty\n");
		return;
	}
	else{
		printf("%d\n",Q->front->data);
		node temp = (Q->front);
		Q->front = Q->front->next;
		free(temp);
		Q->itemN--;
	}	
}



void printList(node head){
               node current = head;
               while(current != NULL){
                             printf("%d\n", current->data);
                             current = current->next;
               }
}
