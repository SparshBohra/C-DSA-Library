#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *create (int n);
void print (struct node *head);
void del (struct node *head, int pos);

int main (void) {
	int n;
	struct node *ll = NULL;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	ll = create(n);
	print(ll);

	del(ll, 3);
	printf("New ");
	print(ll);

	free(ll);
}

struct node *create (int n) {
	struct node *current = NULL;
	struct node *ptr = NULL;
	struct node *head = NULL;

	for (int i=0; i<n; i++) {
		current = malloc(sizeof(struct node));
		printf("Enter data for node %d: ", i+1);
		scanf("%d", &(current->data));
		current->link = NULL;

		if (head == NULL) {
			head = current;
		} else {
			ptr = malloc(sizeof(struct node));
			ptr = head;

			while (ptr->link != NULL) {
				ptr = ptr->link;
			}
			ptr->link = current;
		}
	}
	return head;
}

void del (struct node *head, int pos) {
	struct node *preptr = head;
	struct node *ptr = head;

	if (pos == 0) {
		head = ptr;
		head = head->link;
	} else {
		pos--;

		while (pos != 0) {
			preptr = ptr;
			ptr = ptr->link;
			pos--;
		}
		preptr->link = preptr->link->link;
	}
}

void print (struct node *head) {
	printf("Linked List: ");

	if (head == NULL) {
		printf("empty\n");
	}
	struct node *ptr = head;

	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}
