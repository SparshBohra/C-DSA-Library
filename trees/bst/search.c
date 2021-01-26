#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bstnode {
	int data;
	struct bstnode *left;
	struct bstnode *right;
};

struct bstnode *newnode (char d);
struct bstnode *insert (struct bstnode *root, char d);
int search (struct bstnode *root, char d);

int main (void) {
	struct bstnode *root = NULL;
    root = insert (root, 15);
    root = insert (root, 10);
    root = insert (root, 20);
    root = insert (root, 25);
    root = insert (root, 8);
    root = insert (root, 12);

	int n;
    printf("Enter number to be searched: ");
    scanf("%d", &n);

    if (search (root, n) == 1) {
        printf("Number found\n");
    } else {
        printf("Number not found\n");
    }
}

struct bstnode *newnode (char d) {
	struct bstnode *current = (struct bstnode *)malloc(sizeof(struct bstnode));
	current->data = d;
	current->left = NULL;
	current->right = NULL;
	return current;
}

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

int search (struct bstnode *root, char d) {
	if (root == NULL) {
		return 0;
	}
	else if (root->data == d) {
		return 1;
	}
	else if (d <= root->data) {
		return search (root->left, d);
	}
	else {
		return search (root->right, d);
	}
}
