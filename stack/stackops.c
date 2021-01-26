#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

void push(int d);
void pop();
int peek();
void print();

struct node *top = NULL;

int main (void) {
	for (int i=1; i<11; i++) {
        push(i);
        print();
    }

    for (int i=0; i<9; i++) {
        pop();
        print();
    }

    int t = peek();
    printf("\nStack top: %d\n", t);
}

void push (int d) {
	struct node *current = malloc(sizeof(struct node));
	current->data = d;
	current->link = top;
	top = current;
}

void pop () {
	if (top == NULL) {
		printf("empty\n");
	}
	struct node *ptr = top;
	top = top->link;
	free(ptr);
}

int peek() {
    return top->data;
}

void print() {
    printf("Stack: ");

    if (top == NULL) {
        printf("stack is empty\n");
    }
    struct node *ptr = top;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
