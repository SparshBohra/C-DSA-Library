//bfs - level order traversal - USING QUEUE

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct bstnode {
    char data;
    struct bstnode *left;
    struct bstnode *right;
};

struct bstnode *front = NULL;
struct bstnode *rear = NULL;

struct bstnode *newnode (char d);
struct bstnode *insert (struct bstnode *root, char d);
void bfs (struct bstnode *root);
void enqueue (struct bstnode *root);
struct bstnode *dequeue();

int main (void) {
    struct bstnode *root = NULL;

    root = insert (root, 'F');
    root = insert (root, 'D');
    root = insert (root, 'B');
    root = insert (root, 'A');
    root = insert (root, 'E');
    root = insert (root, 'C');
    root = insert (root, 'J');
    root = insert (root, 'K');
    root = insert (root, 'G');
    root = insert (root, 'I');
    root = insert (root, 'H');

    bfs(root);
}

//create node
struct bstnode *newnode (char d) {
    struct bstnode *newnode = (struct bstnode *)malloc(sizeof(struct bstnode));
    newnode->data = d;
    newnode->left = newnode->right = NULL;
    return newnode;
}

//insert in bst
struct bstnode *insert (struct bstnode *root, char d) {
    if (root == NULL) {
        root = newnode(d);
    }
    else if (d <= root->data) {
        root->left = insert (root->left, d);
    }
    else {
        root->right = insert (root->right, d);
    }
    return root;
}

//level order traversal using queue
void bfs (struct bstnode *root) {
    struct bstnode *current = root;

    while (current != NULL) {
        printf("%c ", current->data);

        if (current->left != NULL) {
            enqueue(current->left);
        }
        if (current->right != NULL) {
            enqueue(current->right);
        }
        current = dequeue();  //remove char at front
    }
}

//enqueue children
void enqueue (struct bstnode *root) {
    struct bstnode *current = (struct bstnode *)malloc(sizeof(struct bstnode));
    current->data = root->data;
    current->left = root;
    current->right = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = current;
        return;
    }
    rear->right = current;
    rear = current;
}

//pop element at front
struct bstnode *dequeue() {
    struct bstnode *ptr = front;

    if (front == NULL) {
        printf("there is no queue\n");
    }
    if (front == rear) {
        front = rear = ptr;
    } else {
        front = front->right;
    }

    struct bstnode *next = ptr->left;
    free(ptr);
    return next;
}
