#include<stdio.h>
#include<stdlib.h>

typedef struct list {

	int data;
	struct list *next;
} Node;

Node *merge_list(Node *list_a, Node *list_b) {

	Node *tempNode = NULL;
	Node *currNode = list_a;

	if(currNode->data > list_b->data){

		tempNode = currNode;
		currNode = list_b;
		list_b = tempNode;
	}

	Node *newHead = currNode;

	while(NULL != currNode->next){

		if(currNode->next->data > list_b->data)
		{
			tempNode = currNode->next;
			currNode->next = list_b;
			list_b = tempNode;
		}
		currNode = currNode->next;
	}
	if(NULL != list_b)
		currNode->next = list_b;

	return newHead;
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

	Node *printHead = Head;
	while(NULL != printHead){
		printf("\t%d-->", printHead->data);
		printHead = printHead->next;
	}
	printf("\tNULL\n\n");
}

int main(){

	printf("\n\n Program to merger two sorted linked list recursively:-");

	Node *list1_head = NULL;
	int index, data = 10;

	for(index = 0; index < 9; index++){

		create_list(&list1_head, data);
		data += 10;
	} 

	printf("\n\n-:Printing List A::-");
	print_list(list1_head);

	Node *list2_head = NULL;
	data = 11;

	for(index = 0; index < 10; index++){

		create_list(&list2_head, data);
		data += 10;
	}
	printf("\n\n-:Printing List B::-");
	print_list(list2_head);


	Node *merged_head = merge_list(list1_head,list2_head);

	printf("\n\n-::Printing sorted merged List::-");	
	print_list(merged_head);

	return 0;
}
