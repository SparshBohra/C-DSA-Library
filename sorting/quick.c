//quicksort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "array.h"

int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main (void) {
	int n;
	printf("Enter the length of the array: ");
	scanf("%d", &n);

	int arr[n];

	for (int i=0; i<n; i++) {
		scanf("%d", &(arr[i]));
	}

	quickSort(arr, 0, n-1);

    printf("Sorted array: \n");
    printArray(arr, n);
}

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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
