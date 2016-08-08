#include<stdio.h>

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

void insert(int x, queue Q){
     if(isEmpty(Q)){
                    node newNode = makeNode(x);
                    Q.front = newNode;
                    Q.rear = newNode;
     }
     else{
          node newNode = makeNode(x);
          Q.rear->next = newNode;
          Q.rear = newNode;
     }
}

void printList(node head){
               node current = head;
               //printf("1\n");
               
               while(current != NULL){
                             printf("1\n");
                             printf("%d\n", current->data);
                             current = current->next;
               }
}

int main(){
    queue * Q = makeQueue(); 
    //printf("%d\n", isEmpty(*Q));
    insert(2,*Q);
    insert(5,*Q);
    insert(7,*Q);
    printf("%d\n", Q->front->data);
    printList(Q->front);
    //printf("%d\n", isEmpty(*Q));    
    system("PAUSE");
    return 0;
}
