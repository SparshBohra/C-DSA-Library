/* SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT SKRRT */
/* DOCUMENTATION DOCUMENTATION DOCUMENTATION DOCUMENTATION DOCUMENTATION DOCUMENTATION DOCUMENTATION DOCUMENTATION DOCUMENTATION */

// DATA STRUCTURES AND ALGORITHMS LIIBRARY FOR C

/*
	DATA STRUCTURES COVERED:
		1. ARRAY
		2. LINKED LIST
		3. STACK
		4. QUEUE
		5. HASH TABLE
		6. BINARY SEARCH TREE
		7. HEAP

	ALGORITHMS COVERED:
		8. SORTING
			-> Bubble Sort
			-> Insertion Sort
			-> Merge Sort
			-> Quicksort
			-> Heapsort
			-> Radix Sort
		9. SEARCHING
			-> Linear Search
			-> Binary Search
			-> Linear Probing (HASH TABLE)
			-> Quadratic Probing (HASH TABLE)
			-> Double Hashing (HASH TABLE)
		10. MINIMUM SPANNING TREE
			-> Prim's
			-> Kruskal's
		11. SHORTEST DISTANCE (PATH FINDING)
			-> Dijkstra
			-> A*


	** 	OPERATIONS FOR EACH DS IS WRITTEN AS: (DS NAME)_(OPERATION)
			Eg: Call a function to delete a node in Linked List
				It is written as ll_delNode()

	** 	LINKED, STACK, QUEUE use the same structure "node"
			The functions are written for a single data type: "int"
			However, it can be changed as needed

	** 	BINARY SEARCH TREE uses structure "bst_node"
			The functions are written for a single data type: "char"
				However, it can be changed as needed

    ** 	HASH TABLE uses structure "DataItem"
            Default size for the table is 20
                However, it can be changed as needed


	PARAMETERS FOR FUNCTIONS:

		1. ARRAY
			void printArray (int arr[], int n)
			void swap (int* a, int* b)

		2. LINKED LIST
			struct node *ll_create (int n)
			void ll_print (struct node *head)
			void ll_addNode (struct node *head, int d, int pos)
			void ll_delNode (struct node *head, int pos)
			struct node *ll_reverse (struct node *head)

		3. STACK
			void stack_push(int d);
			void stack_pop();
			int stack_peek();
			void stack_print();

		4. QUEUE
			void queue_enqueue (int d);
			void queue_dequeue();
			int queue_peek();
			int queue_isEmpty();
			void queue_print();

		5. HASH TABLE
            struct DataItem *hash_search(int key)
            void hash_insert(int key,int data)
            struct DataItem* hash_delete(struct DataItem* item)
            void hash_display()

		6. BINARY SEARCH TREE
			struct bstnode *bst_insert (struct bstnode *root, int d)
			int bst_search (struct bstnode *root, int d)
			int bst_findmin (struct bstnode *root)
			int bst_findmax (struct bstnode *root)
			int bst_height (struct bstnode *root)

			Traversing:
				void bst_bfs (struct bstnode *root)
				void bst_preorder (struct bstnode *root)
				void bst_inorder (struct bstnode *root)
				void bst_postorder (struct bstnode *root)

		7. HEAP
			?????YET TO FINISH?????

		8. SORTING
			-> Bubble Sort
				?????YET TO FINISH????? //nobody wants O(n^2) ayways lmao

			-> Insertion Sort
				void insertSort (int a[], int n);

			-> Merge Sort
				void merge(int arr[], int l, int m, int r);
				void mergeSort(int arr[], int l, int r);

			-> Quicksort
				void quickSort(int arr[], int low, int high);

			-> Heapsort
				?????YET TO FINISH?????

			-> Radix Sort
				?????YET TO FINISH?????

		9. SEARCHING
			-> Linear Search

			-> Binary Search

			-> Linear Probing (HASH TABLE)
				?????YET TO FINISH?????

			-> Quadratic Probing (HASH TABLE)
				?????YET TO FINISH?????

			-> Double Hashing (HASH TABLE)
				?????YET TO FINISH?????

		10. MINIMUM SPANNING TREE
			?????YET TO FINISH?????

		11. SHORTEST DISTANCE (PATH FINDING)
			?????YET TO FINISH?????

*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ARRAY

/*

*/

void printArray (int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap (int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// LINKED LIST

/*

*/

struct node {
	int data;
	struct node *link;
};

struct node *ll_create (int n) {
	struct node *head = NULL;
	struct node *current = NULL;
	struct node *ptr = NULL;

	for (int i=0; i<n; i++) {
		current = (struct node *)malloc(sizeof(struct node));
		printf("Enter data for node %d: ", i+1);
		scanf("%d", &(current->data));
		current->link = NULL;

		if (head == NULL) {
			head = current;
		} else {
			ptr = (struct node *)malloc(sizeof(struct node));
			ptr = head;

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

void ll_addNode (struct node *head, int d, int pos) {
	struct node *new = malloc(sizeof(struct node));
	new->data = d;
	new->link = NULL;
	struct node *ptr = head;

	pos--;
	while (pos != 1) {
		ptr = ptr->link;
		pos--;
	}
	new->link = ptr->link;
	ptr->link = new;
}

void ll_delNode (struct node *head, int pos) {
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

struct node *ll_reverse (struct node *head) {
	struct node *current, *prev, *link;
	current = head;
	prev = NULL;

	while (current != NULL) {
		link = current->link;
		current->link = prev;
		prev = current;
		current = link;
	}
	head = prev;
	return head;
}

void ll_print (struct node *head) {
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// STACK

/*

*/

struct node *top = NULL;

void stack_push (int d) {
	struct node *current = malloc(sizeof(struct node));
	current->data = d;
	current->link = top;
	top = current;
}

void stack_pop () {
	if (top == NULL) {
		printf("empty\n");
	}
	struct node *ptr = top;
	top = top->link;
	free(ptr);
}

int stack_peek() {
    return top->data;
}

void stack_print() {
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// QUEUE

/*

*/

struct node *front = NULL;
struct node *rear = NULL;

void queue_enqueue (int d) {
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

void queue_dequeue() {
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

int queue_peek() {
    return rear->data;
}

int queue_isEmpty() {
    if (front == rear) {
        return 1; //empty
    } else {
        return 0; //not empty
    }
}

void queue_print() {
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// BINARY SEARCH TREE (BST)

/*

*/

struct bstnode {
    int data;
    struct bstnode *left;
    struct bstnode *right;
};

struct bstnode *front = NULL;
struct bstnode *rear = NULL;

struct bstnode *bst_newnode (int d) {
    struct bstnode *newnode = (struct bstnode *)malloc(sizeof(struct bstnode));
    newnode->data = d;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct bstnode *bst_insert (struct bstnode *root, int d) {
    if (root == NULL) {
        root = newnode(d);
    }
    else if (d <= root->data) {
        root->left = bst_insert (root->left, d);
    }
    else {
        root->right = bst_insert (root->right, d);
    }
    return root;
}

int bst_search (struct bstnode *root, int d) {
    if (root == NULL) {
        return 0;
    }
    else if (root->data == d) {
        return 1;
    }
    else if (d <= root->data) {
        return bst_search (root->left, d);
    }
    else {
        return bst_search (root->right, d);
    }
}

int bst_findmin (struct bstnode *root) {
    if (root == NULL) {
        printf("tree is empty\n");
        return -1;
    }
    struct bstnode *ptr = root;

    while (ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr->data;
}

int bst_findmax (struct bstnode *root) {
    if (root == NULL) {
        printf("tree is empty\n");
        return -1;
    }
    struct bstnode *ptr = root;

    while (ptr->right != NULL) {
        ptr = ptr->right;
    }
    return ptr->data;
}

int bst_height (struct bstnode *root) {
    if (root == NULL) {
        return -1;
    }
    else {
        int left = bst_height (root->left);
        int right = bst_height (root->right);

        int bst_height = (left < right) ? right+1 : left+1;
        return bst_height;
    }
}

//depth first search 3 ways
void bst_preorder (struct bstnode *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    bst_preorder (root->left);
    bst_preorder (root->right);
    return;
}

void bst_inorder (struct bstnode *root) {
    if (root == NULL) {
        return;
    }

    bst_inorder (root->left);
    printf("%d ", root->data);
    bst_inorder (root->right);
    return;
}

void bst_postorder (struct bstnode *root) {
    if (root == NULL) {
        return;
    }

    bst_postorder (root->left);
    bst_postorder (root->right);
    printf("%d ", root->data);
    return;
}

//level order traversal using queue
void bst_bfs (struct bstnode *root) {
    struct bstnode *current = root;

    while (current != NULL) {
        printf("%c ", current->data);

        if (current->left != NULL) {
            bst_enqueue(current->left);
        }
        if (current->right != NULL) {
            bst_enqueue(current->right);
        }
        current = bst_dequeue();  //remove char at front
    }
}

//enqueue children
void bst_enqueue (struct bstnode *root) {
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
struct bstnode *bst_dequeue() {
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// INSERT SORT

/*

*/

void insertSort (int a[], int n) {
	int key, hole;

	for (int i=1; i<n; i++) {
		key = a[i];
		hole = i;

		while ((hole > 0) && (a[hole-1] > key)) {
			a[hole] = a[hole-1];
			hole--;
		}

		a[hole] = key;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// MERGE SORT

/*

*/

void merge (int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort (int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// QUICKSORT

/*

*/

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort (int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// HASH TABLE

/*

*/

#define SIZE 20

struct DataItem {
   int data;
   int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
   	return key % SIZE;
}

struct DataItem *hash_search(int key) {
   	int hashIndex = hashCode(key);

   	while(hashArray[hashIndex] != NULL) {

      	if(hashArray[hashIndex]->key == key)
         	return hashArray[hashIndex];

      		++hashIndex;
      		hashIndex %= SIZE;
   	}

   	return NULL;
}

void hash_insert(int key, int data) {

   	struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   	item->data = data;
   	item->key = key;

   	int hashIndex = hashCode(key);

   	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      		++hashIndex;
      		hashIndex %= SIZE;
   	}

   	hashArray[hashIndex] = item;
}

struct DataItem* hash_delete(struct DataItem* item) {
   	int key = item->key;

   	int hashIndex = hashCode(key);

   	while(hashArray[hashIndex] != NULL) {
      		if(hashArray[hashIndex]->key == key) {
         		struct DataItem* temp = hashArray[hashIndex];
	
         		hashArray[hashIndex] = dummyItem;
         		return temp;
      		}

      		++hashIndex;
      		hashIndex %= SIZE;
   	}

   	return NULL;
}

void hash_display() {
   	for(int i = 0; i<SIZE; i++) {
      		if(hashArray[i] != NULL) {
        	 	printf(" (%d,%d)",hashArray[i]->key, hashArray[i]->data);
        	}
      		else {
        	 	printf(" ~~ ");
        	}
   	}
   	printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// XYZ

/*

*/
