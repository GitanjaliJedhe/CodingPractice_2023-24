/*
* Algorithm:
* Traverse linked list using two pointers.
* Move one pointer(slow_p) by one and another pointer(fast_p) by two.
* If these pointers meet at the same node then there is a loop. If pointers do not meet then the linked list doesn’t have a loop.
*/

#include <iostream>

class node {
public:
	int data;
	node* next;
};

void push(node **pHead, int data) {
	node *newNode = new node();

	newNode->data = data;

	newNode->next = *pHead;

	*pHead = newNode;
}

bool detectLoop(struct node *list)  {

	node *slowPtr, *fastPtr;

	slowPtr = fastPtr = list;

	while (slowPtr && fastPtr && fastPtr->next) {
		slowPtr = slowPtr->next;
		
		fastPtr = fastPtr->next->next;

		if (slowPtr == fastPtr) {
			return true;
		}
	}

	return false;
}

int main() {
	struct node *head = nullptr;

	push(&head, 40);
	push(&head, 30);
	push(&head, 20);
	push(&head, 10);

	head->next->next->next->next = head;

	if (detectLoop(head)) {
		printf("Loop Found\n");
	}
	else {
		printf("No Loop\n");
	}

	return 0;
}

/*
* Output:
* Loop Found
*/

/*
* Time Complexity: O(N), Only one traversal of the loop is needed.
* Auxiliary Space: O(1).
*/
