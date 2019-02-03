#include<stdio.h>
#include<stdlib.h>
#define false 0
#define true 1
typedef struct list{

	char data;
	struct list *next;
} Node;

int isPalindrome(Node **headA, Node *headB){

	int flag1 = false;
	if(headB == NULL)
		return true;
	
	int flag = isPalindrome(headA, headB->next);
	//printf("\nSHivaji :%c\n", headB->data);

	if(flag == false) {
		return false;
	}

	if((*headA)->data == headB->data){

		flag1 = true;
	}	 
	(*headA) = (*headA)->next;
	return flag1;
}


Node *create_Node(char data){

	Node *newNode = (Node *)malloc(sizeof(Node *));

	newNode->next = NULL;
	newNode->data = data;

	return newNode;
}

void create_list(Node **listHead, char data){

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
		printf("\t%c-->", print_Head->data);
		print_Head = print_Head->next;
	}
	printf("\tNULL\n\n");
}

int main(){

	printf("\n\n Program to check whether the list is palindrome:-");

	Node *list_head = NULL;
	int index;
	char data[] = "ELAMALE";

	for(index = 0; index < sizeof(data)-1; index++){

		create_list(&list_head, data[index]);
	} 

	printf("\n\n-:Printing a List::-");
	print_list(list_head);

	isPalindrome(&list_head, list_head) ? printf("\nlist is Palindrome\n\n") : printf("\nlist is not Palindrome\n\n");


	return 0;
}
