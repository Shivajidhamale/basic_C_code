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


int sum_of_childs(Node *root) {

	if (root == NULL)
		return 0;
	else {
		int prev_data = root->data;

		root->data = sum_of_childs(root->left) + sum_of_childs(root->right); 
	
		//printf("\n . %d", root->data);
		
		return  root->data + prev_data;		
	}
}

int main() {
	
	printf("\n\n Program to find sum of its childs and replace it with root:-\n\n");

	int arr[] = {8,3,1,6,7,10};
	
	int index, size = sizeof(arr)/sizeof(arr[0]);

	Node *root = NULL;
	root = create_BST(root, arr[0]);

	for(index = 1; index < size; index++)
	{
		create_BST(root, arr[index]);	
	} 

	printf("\n\n In-order Traversal before addition:-\n");
	in_order(root);
	
	printf("NULL\n");
	
	sum_of_childs(root);	
	
	printf("\n\n In-order Traversal after addition:-\n");
	in_order(root);
	printf("NULL\n\n");
	return 0;
}

