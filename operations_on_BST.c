#include<stdio.h>
#include<stdlib.h>

typedef struct BST {

	int data;
	struct BST *left;
	struct BST *right;
} Node;


Node *create_Node(int data) {

	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void creare_Root_of_entire_BST(Node **root, int data) {

	if((*root) == NULL) {
	
		Node *newNode = create_Node(data);
		(*root) = newNode;
	} 
		
}

Node *create_BST(Node *root, int data) {

	if(root == NULL) {

		return create_Node(data);
	}
	if(data < root->data) {

		root->left = create_BST(root->left, data);

	} else if(data > root->data) {

		root->right = create_BST(root->right, data);
	}
	
	return root;
}

void in_order(Node* root) {

	if(root == NULL)
		return;

	in_order(root->left);

	printf(" %d ->", root->data);

	in_order(root->right);
}

void pre_order(Node* root) {

	if(root == NULL)
		return;

	printf(" %d ->", root->data);

	pre_order(root->left);

	pre_order(root->right);
}

void post_order(Node* root) {

        if(root == NULL)
                return;

        post_order(root->left);

        post_order(root->right);
        
	printf(" %d ->", root->data);
}

int main() {
	
	printf("\n\n Program to perform operations on BST:-\n\n");

	//int arr[] = {8,3,10,1,6,14,4,7};
	
	int arr[] = {8,3,1,6,7,10,14,4};
	int index, size = sizeof(arr)/sizeof(arr[0]);

	Node *root = NULL;
	root = create_BST(root, arr[0]);

	for(index = 1; index < size; index++)
	{
		create_BST(root, arr[index]);	
	} 

	printf("\n\n In-order Traversal:-\n");
	in_order(root);
	printf("NULL\n\n");
	
	printf("\n\n Pre-order Traversal:-\n");
	pre_order(root);
	printf("NULL\n\n");	
	
	printf("\n\n Post-order Traversal:-\n");
	post_order(root);
	printf("NULL\n\n");	

	return 0;
}
