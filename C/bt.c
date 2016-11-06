//binary trees

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * leftNode;
	struct node * rightNode;
	struct node * parent;
};

typedef struct node Node;

struct tree{
	Node * root;
};

typedef struct tree Tree;

Node * makeNode(int data){
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	newNode->parent = newNode;
	newNode->data = data;
	return newNode;
}

Tree * makeTree(){
	Tree * newTree = (Tree *)malloc(sizeof(Tree));
	newTree->root = NULL;
	return newTree;
}

void inOrder(Node * node){
	if(node->leftNode != NULL){
		inOrder(node->leftNode);
	}
	printf("%d\n", node->data);
	if(node->rightNode != NULL){
		inOrder(node->rightNode);
	}
}

void preOrder(Node * node){
	printf("%d\n", node->data);
	if(node->leftNode != NULL){
		preOrder(node->leftNode);
	}
	if(node->rightNode != NULL){
		preOrder(node->rightNode);
	}
}

Node * search(int query, Node * root){
	if(query < root->data){
       		if(root->leftNode != NULL){
			return search(query, root->leftNode);
		}
	}
	if(query > root->data){ 
		if(root->rightNode != NULL){
			return search(query, root->rightNode);
		}
	}
	return root;
}

Node * findSmallest(Node * node){
	if (node->leftNode != NULL){
		findSmallest(node->leftNode);
	}
	else{
		return node;
	}
}

Node * findLargest(Node * node){
	if (node->rightNode != NULL){
		findLargest(node->rightNode);
	}
	else{
		return node;
	}
}

void insert(int data, Tree * tree){
	Node * newNode = makeNode(data);
	if(tree->root = NULL){
		tree->root = newNode;
		return;
	}
	Node * location = search(data, tree->root);
	if (location->data == data) return;
	if (data > location->data){
		location->rightNode = newNode;
		newNode->parent = location;
	}
	if (data < location->data){
		location->leftNode = newNode;
		newNode->parent = location;
	}
}

void delete(int data, Tree * tree){
	if (tree->root == NULL) return;
	Node * location = search(data, tree->root);
	if(location->data != data) return;
	Node * parent = location->parent;
	if((location->leftNode == NULL)&&(location->rightNode == NULL)){
		if(parent = location){
			tree->root == NULL;
			free(location);
		}
		if(parent->leftNode == location){
			parent->leftNode = NULL;
		}
		if(parent->rightNode == location){
			parent->rightNode = NULL;
		}
		free(location);
		return;
	}
	if(location->leftNode == NULL){
		if(parent = location){
			tree->root == location->rightNode;
			free(location);
			return;
		}
		location->rightNode->parent = parent;
		if(parent->rightNode == location){
			parent->rightNode = location->rightNode;
		}
		else if(parent->rightNode == location){
			parent->leftNode = location->rightNode;
		}
		free(location);
		return;
	}
	if(location->rightNode == NULL){
		if(parent = location){
			tree->root == location->leftNode;
			free(location);
			return;
		}
		location->leftNode->parent = parent;
		if(parent->rightNode == location){
			parent->rightNode = location->leftNode;
		}
		else if(parent->leftNode == location){
			parent->leftNode = location->leftNode;
		}
		free(location);
		return;
	}
	if(parent->leftNode == location){
		Node * y = findSmallest(location->rightNode);
		y->parent->leftNode = NULL;
		y->parent = parent;
		parent->leftNode == y;
		y->leftNode = location->leftNode;
		y->rightNode = location->rightNode;
		free(location);
	}
	if(parent->rightNode == location){
		Node * y = findLargest(location->leftNode);
		y->parent->rightNode = NULL;
		y->parent = parent;
		parent->rightNode == y;
		y->leftNode = location->leftNode;
		y->rightNode = location->rightNode;
		free(location);	
	}
}

int main(){
	Tree * tree = makeTree();
	for(int i = 1; i <= 1; i++){
		//printf("%d\n", i);
		insert(i, tree);
		insert(i-1, tree);
		printf("%d\n", i);
	}
	return 0;
}
