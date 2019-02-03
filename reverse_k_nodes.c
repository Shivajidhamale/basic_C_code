#include<stdio.h>
#include<stdlib.h>

typedef struct list{

	int data;
	struct list *next;
} Node;

Node *reverse_list(Node *list_head, int k){

	Node *prev = NULL;
	Node *next;
	Node *currNode = list_head;
	Node *tempEnd = list_head;

	int count = 0;
	while(NULL != currNode && count < k){

		next = currNode->next;
		currNode->next = prev;
		prev = currNode;
		currNode = next;
		count ++;

	}
	if(tempEnd != NULL)
		tempEnd->next = currNode;
	count = 0;

	// move currNode k-1 times here bcoz the currNode is already pointing to 1st node of remaining list.

	while(count < k-1 && NULL != currNode) {
		currNode = currNode->next;
		count += 1;
	}	
	if(currNode != NULL)
		currNode->next  = reverse_list(currNode->next, k);

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

	printf("\n\n Program to reverse k nodes of linked list:-");

	Node *list_head = NULL;
	int index, data = 10;

	for(index = 0; index < 8; index++){

		create_list(&list_head, data);
		data += 10;
	} 

	printf("\n\n-:Printing a List::-");
	print_list(list_head);

	Node *new_head = reverse_list(list_head, 3);

	printf("\n\n-::Printing reversed List::-");	
	print_list(new_head);

	return 0;
}
