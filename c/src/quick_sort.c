/*
 * quick_sort.c
 *
 *  Created on: Oct 27, 2015
 *      Author: dk
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include <print_list.h>

void swap(int *array, int x, int y) {
	int t;
	t = array[x];
	array[x] = array[y];
	array[y] = t;
	return;
}

int partition(int * array, int p, int r) {
	int i, j, x;

	x = array[r];
	i = p - 1;
	for (j = p; j < r; j++) {
		if (array[j] <= x) {
			++i;
			swap(array, i, j);
		}
	}
	++i;
	swap(array, i, r);
	return i;
}

void quick_sort_int(int *array, int p, int r) {
	int q;
	if (p < r) {
		q = partition(array, p, r);
		quick_sort_int(array, p, q - 1);
		quick_sort_int(array, q + 1, r);
	}
}

void qs(int* array, int size) {
	if ((array == NULL) || (size <= 0)) {
		printf("Invalid input parameters. Exiting.\n");
	}
	quick_sort_int(array, 0, size - 1);
	return;
}

void test_quick_sort(int* array, int size) {
	int MAX_RANDOM_NUMBER = 101;
	int i, a[20];
	int n = 20;

	/* Initializes random number seed */
	srand(time(0));

	/* Generate random numbers for testing */
	for (i = 0; i < n; i++) {
		a[i] = rand() % MAX_RANDOM_NUMBER;
	}
	print_array(a, n);
	qs(a, n);
	print_array(a, n);
	return;
}
