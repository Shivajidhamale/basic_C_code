
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
#define TRUE 1
#define FALSE 0

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

Node *add_lists(Node *listA_head, Node *listB_head, int *carry){

        if(NULL == listA_head)
                return NULL;
        if(NULL == listB_head)
                return NULL;

        Node *result_head = (Node *)malloc(sizeof(Node *));
	
	result_head->next = add_lists(listA_head->next, listB_head->next, carry);

	int sum = listA_head->data + listB_head->data + *carry;
	
	*carry = sum / 10;
	sum %= 10;
	
	result_head->data = sum;

	 
        return result_head;
}

/*this function is to add carry and remaining nodes of listA */

void add_carry_to_list(Node *headA, Node *currNode, Node **result, int *carry){
	
	if(headA != currNode){


		add_carry_to_list(headA->next, currNode, result, carry);
	

		int sum = headA->data + *carry;
		*carry = sum / 10;
		sum %= 10;

		Node *newNode = (Node *)malloc(sizeof(Node *));
                newNode->data = sum;
                newNode->next = (*result);
                (*result) = newNode;
	}

}
int getSize(Node *head){

	int count = 0;

	while(NULL != head){
		count+= 1;
		head = head->next;
	}

	return count;
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

	printf("\n\n Program to reverse linked list recursively:-");

	Node *list1_head = NULL;


	int index, data = 9;

	for(index = 0; index < 2; index++){

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
	
	int carry = 0;

	int size1 = getSize(list1_head);
	int size2 = getSize(list2_head);

	Node *result_list_head = NULL;	

	/* call directly add_lists function if the size of 2 lists is same. */

	if(size1 == size2){
		
		result_list_head = add_lists(list1_head, list2_head, &carry);
	} else {
	
		// first list size should always greater than second list, if not swap the pointers

		if(size1 < size2) {
			Node *temp = list1_head;
			list1_head = list2_head;
			list2_head = temp;
		}
		
		int diff = abs(size1 - size2);

		/* move the current(list1_head) pointer till (size1-size2) times, 
		   so that list starting from current can be added with list2_head */
		
		Node *current = NULL;
	
		for(current = list1_head; diff--; current=current->next);	
		
		/* now the size of current to null and size of list2 are equal, add them, 
		   remaining part of list A will be handled in add_carry_to_list() */

		result_list_head = add_lists(current, list2_head, &carry);
	
		/* Now add initial digits of listA and carry if any */
		
		add_carry_to_list(list1_head, current, &result_list_head, &carry);	
	}

	/* after adding say 999 & 111 result created in function add_lists() will be 0->0->0->NULL, 
	   so to create the carry node 1 follwoing code is added */

	if(carry) {

        	Node *node_carry = (Node *)malloc(sizeof(Node *));
		node_carry->data = carry;
		node_carry->next = result_list_head;
		result_list_head = node_carry;
	
	} 
		

	printf("\n\n-::Addition of two lists::-");
	print_list(result_list_head);

	return 0;
}
