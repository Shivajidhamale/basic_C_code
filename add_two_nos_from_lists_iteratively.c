/*
1.

	6-->9-->4-->NULL
+	1-->2-->3-->NULL
	----------------
	8-->1-->7-->NULL

2.

	6-->9-->4-->NULL
+
	    1-->8-->NULL
	----------------
	7-->1-->2-->NULL
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct list{

	int data;
	struct list *next;
} Node;

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

/*add lists if the size of both the lists is same */

Node *add_lists(Node *listA_head, Node *listB_head){

        if(NULL == listA_head)
                return listB_head;
        if(NULL == listB_head)
                return listA_head;

	int sum_listA = 0;
	
	while(NULL != listA_head){

		sum_listA = (sum_listA * 10) + listA_head->data;
		listA_head = listA_head->next;

	} 
	
	int sum_listB = 0;
	while(NULL != listB_head){

		sum_listB = (sum_listB * 10) + listB_head->data;
		listB_head = listB_head->next;

	} 
	
        Node *result_head = NULL;
	
	int total = sum_listA + sum_listB;
	
	while(total > 0) {

		int rem = total % 10;

		Node *newNode = (Node *)malloc(sizeof(Node *));
		newNode->data = rem;
		newNode->next = result_head;	
		result_head = newNode;

		total = total / 10;	

	}
        return result_head;
}

void print_list(Node *Head){

	Node *print_Head = Head;

	while(NULL != print_Head){
		printf("\t%d-->", print_Head->data);
		print_Head = print_Head->next;
	}
	printf("\tNULL\n\n");
}

int main() {

	printf("\n\n Program to add 2 numbers represented by linked list iteratively:-");

	Node *list1_head = NULL;

	int index, data = 9;

	for(index = 0; index < 3; index++){

		create_list(&list1_head, data);
		data -= 1 ;
	} 
	printf("\n\n-:Printing a List::-\t");
	print_list(list1_head);
	
	Node *list2_head = NULL;
	data = 1;

	for(index = 0; index < 3; index++){

		create_list(&list2_head, data);
		data += 1;
	}
	printf("\n\n-:Printing a List::-\t");
	print_list(list2_head);
	
	/* Combines the number represented by each list and then adds with another */
	Node *result_list_head = add_lists(list1_head, list2_head);

	printf("\n\n-::Addition of two lists::-");
	print_list(result_list_head);

	return 0;
}
