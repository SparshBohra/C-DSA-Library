//print an array

// A utility function to print an array of size n
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
