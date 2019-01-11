#include<stdio.h>
#include<stdlib.h>

typedef struct list{

	int data;
	struct list *next;
} Node;

Node *reverse_list(Node *list_head){

	Node *prev = NULL;
	Node *next = NULL;
	Node *currNode = list_head;

	while(NULL != currNode){

		next = currNode->next;
		currNode->next = prev;
		prev = currNode;
		currNode = next;

	}
	return prev;
}


Node *create_Node(int data){

	Node *newNode = (Node *)malloc(sizeof(Node *));

	newNode->next = NULL;
	newNode->data = data;

	return newNode;
}

void create_list(Node **listHead, int data){

	Node *newNode = create_Node(data);

	if(NULL == *listHead){
		*listHead = newNode;
	}else{
		Node *currentNode = *listHead;

		while(currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}

}

void print_list(Node *Head){

	Node *print_Head = Head;

	while(NULL != print_Head){
		printf("\t%d-->", print_Head->data);
		print_Head = print_Head->next;
	}
	printf("\tNULL\n\n");
}

int main(){

	printf("\n\n Program to reverse linked list iteratively:-");

	Node *list_head = NULL;
	int index, data = 10;

	for(index = 0; index < 9; index++){

		create_list(&list_head, data);
		data += 10;
	} 

	printf("\n\n-:Printing a List::-");
	print_list(list_head);

	Node *new_head = reverse_list(list_head);

	printf("\n\n-::Printing reversed List::-");	
	print_list(new_head);

	return 0;
}
