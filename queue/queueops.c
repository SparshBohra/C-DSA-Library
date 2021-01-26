#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue (int d);
void dequeue();
int peek();
int isEmpty();
void print();

int main (void) {
    for (int i=1; i<11; i++) {
        enqueue(i);
        print();
        dequeue();
    }

    if (isEmpty() == 1) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nQueue is not empty\n");
    }
}

void enqueue (int d) {
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = d;
    current->link = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = current;
        return;
    }
    rear->link = current;
    rear = current;
}

void dequeue() {
    if (front == NULL) {
        printf("there is no queue\n");
    }
    if (front == rear) {
        printf("there is no node to dequeue\n");
    } else {
        struct node *ptr = front;
        front = front->link;
        free(ptr);
    }
}

int peek() {
    return rear->data;
}

int isEmpty() {
    if (front == rear) {
        return 1; //empty
    } else {
        return 0; //not empty
    }
}

void print() {
    printf("Queue: ");

    if (front == NULL) {
        printf("queue is empty\n");
    }
    struct node *ptr = front;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
