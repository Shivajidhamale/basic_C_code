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


void find_mirror(Node *root) {

	if (root == NULL)
		return;
	else {
		Node *temp;
		find_mirror(root->left); 
		find_mirror(root->right); 
		
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

int main() {
	
	printf("\n\n Program to perform mirror operation on BST:-\n\n");

	int arr[] = {8,3,1,6,7,10};
	
	int index, size = sizeof(arr)/sizeof(arr[0]);

	Node *root = NULL;
	root = create_BST(root, arr[0]);

	for(index = 1; index < size; index++)
	{
		create_BST(root, arr[index]);	
	} 

	/*printf("%d", root->data);
	printf("\n%d", root->left->data);
	printf("\n%d", root->right->data);
	printf("\n%d\n\n", root->left->left->data); */

	printf("\n\n In-order Traversal before mirroring:-\n");
	in_order(root);
	
	printf("NULL\n");
	
	find_mirror(root);	
	
	printf("\n\n In-order Traversal after mirroring:-\n");
	in_order(root);

	printf("NULL\n\n");
	return 0;
}
