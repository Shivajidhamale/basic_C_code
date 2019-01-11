#include<stdio.h>
#include<stdlib.h>

typedef struct list {

	int data;
	struct list *next;
} Node;

Node *merge_list(Node *list_a, Node *list_b){

	Node *sortedListHead = NULL;

	if(NULL == list_a)
		return list_b;

	if(NULL == list_b)
		return list_a;
	
	if(list_a->data <= list_b->data){

		sortedListHead = list_a;
		sortedListHead->next = merge_list(list_a->next, list_b);
	} else{
		sortedListHead = list_b;
		sortedListHead->next = merge_list(list_a, list_b->next);
	}
	
	return sortedListHead;
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

		while(NULL != currentNode->next){

			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
}

void print_list(Node *Head){
	
	Node *printNode = Head;

	while(NULL != printNode){

		printf("\t%d-->", printNode->data);
		printNode = printNode->next;

	}

	printf("\tNULL\n\n");
}

int main(){

	printf("\n\n Program to merger two sorted linked list recursively:-");

	Node *list1_head = NULL;
	int index, data = 10;

	for(index = 0; index < 10; index++){

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


	Node *merged_Head = merge_list(list1_head,list2_head);

	printf("\n\n-::Printing sorted merged List::-");	
	print_list(merged_Head);

	return 0;
}
