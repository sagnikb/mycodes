/***Singly Linked list***/

/***Struct node and typedef**/
struct node{
  int data;
  struct node * next;
};

typedef struct node * node;

/***Making a node***/
node makeNode(int x){
  node newNode = (node)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->next = NULL;
  return newNode;
}
/***Printing a list***/
void printList(node head){
  node current = head;
  while(current != NULL){
    printf("%d\n", current->data);
    current = current->next;
  }
}
