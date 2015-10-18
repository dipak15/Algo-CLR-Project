/*
 * insertion_sort.c
 *
 *  Created on: Oct 17, 2015
 *      Author: Dipak K Narayan
 */

#include <stdio.h>
#include <print_list.h>

void insertion_sort_int(int *array, int size) {
	int i, j, key;
	int n = size;
	for (i = 1; i < n; i++) { /* loop through elements 2 to n */
		key = array[i]; /* sort the current element */
		j = i - 1;
		while (j >= 0 && array[j] > key) {
			/* insert the current element is the sorted array */
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
	return;
}

void test_insertion_sort(int *array, int size) {
	int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int n = 10;
	int *list;

	if ((array == NULL) || (size <= 0)) {
		list = a;
		n = 10;
	} else {
		list = array;
		n = size;
	}

	printf("Testing Insertion Sort\n");
	printf("Input Array: ");
	print_array(list, n);
	insertion_sort_int(list, n);
	printf("Output Array: ");
	print_array(list, n);
	return;
}

void insertion_sort(int *array, int size) {
	/*	test_insertion_sort(array, size); */
	if ((array == NULL) || (size <= 0)) {
		printf("Invalid input parameters. Exiting.\n");
	}
	insertion_sort_int(array, size);
	return;
}
