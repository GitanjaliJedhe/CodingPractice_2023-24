/* Algorithm:
* Initialize three pointers prev as NULL, curr as head, and next as NULL.
* Iterate through the linked list. In a loop, do the following:
*	Before changing the next of curr, store the next node 
*		next = curr -> next
*	Now update the next pointer of curr to the prev 
*		curr -> next = prev 
*	Update prev as curr and curr as next 
*		prev = curr 
*		curr = next
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void reverse(struct node **pHead) {
	struct node *prev, * current, * next;

	prev = NULL;
	current = *pHead;
	next = NULL;

	while (current != NULL) {
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}

	*pHead = prev;
}

void push(struct node **pHead, int data) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = data;

	newNode->next = *pHead;

	*pHead = newNode;
}

void print(struct node* head) {
	struct node *temp = head;

	printf("[ ");

	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}

	printf("NULL");
	printf(" ]\n");
}

int main() {

	struct node* head = NULL;

	push(&head, 50);
	push(&head, 40);
	push(&head, 30);
	push(&head, 20);
	push(&head, 10);

	printf("Given Linked List:\n");
	print(head);

	reverse(&head);

	printf("Reversed Linked List:\n");
	print(head);

	return 0;
}

/*
* Output:
* Given Linked List:
* [ 10 -> 20 -> 30 -> 40 -> 50 -> NULL ]
* Reversed Linked List:
* [ 50 -> 40 -> 30 -> 20 -> 10 -> NULL ]
*/

/*
* Time Complexity: O(N), Traversing over the linked list of size N. 
* Auxiliary Space: O(1)
*/
