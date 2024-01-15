/* Algorithm:
* Solution is to copy the data from the next node to the node to be deleted and delete the next node
* // Find next node using next pointer
* struct Node *temp  = node_ptr->next;
* 
* // Copy data of next node to this node
* node_ptr->data  = temp->data;
* 
* // Unlink next node
* node_ptr->next  = temp->next;
* 
* // Delete next node
* free(temp);
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

void deleteNode(struct node *node) {
	if (node == NULL) {
		return;
	}
	else {
		struct node* temp = node->next;

		node->data = temp->data;

		node->next = temp->next;

		free(temp);

		temp = NULL;
	}
}

void push(struct node** pHead, int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = data;

	newNode->next = *pHead;

	*pHead = newNode;
}

void print(struct node* head) {
	struct node* temp = head;

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

	printf("Before Deleting: \n");
	print(head);

	deleteNode(head);

	printf("After Deleting: \n");
	print(head);

	return 0;
}

/*
* Output:
* Before Deleting:
* [ 10 -> 20 -> 30 -> 40 -> 50 -> NULL ]
* After Deleting:
* [ 20 -> 30 -> 40 -> 50 -> NULL ]
*/

/*
* Time Complexity: O(N)
* Auxiliary Space: O(1)
*/
