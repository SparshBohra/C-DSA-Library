#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "array.h"

void insert (int a[], int n);

int main (void) {
	int n;
	printf("Enter the length of the array: ");
	scanf("%d", &n);

	int arr[n];

	for (int i=0; i<n; i++) {
		scanf("%d", &(arr[i]));
	}

	insert (arr, n);
 	printArray(arr, n);
}

void insert (int a[], int n) {
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
