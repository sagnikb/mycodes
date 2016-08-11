/***Queue***/

#include<stdio.h>
#include<stdlib.h>

/***Linked list functions***/
struct node{
  int data;
  struct node * next;
};

typedef struct node * node;

node makeNode(int x){
  node newNode = (node)malloc(sixeof(struct node));
  newNode->data = x;
  newNode->next = NULL;
  return newNode;
}

void printList(node head){
  node current = head;
  while(curretn != NULL){
    printf("%d\n", current->data);
    current = current->next;
  }
}
