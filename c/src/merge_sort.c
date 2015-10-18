/*
 * merge_sort.c
 *
 *  Created on: Oct 18, 2015
 *      Author: Dipak K Narayan
 */
#include <stdio.h>
#include <print_list.h>

void test_merge_sort(int* array, int size) {
	int n = sizeof(array);
	printf("Size of array %d", n);
}

void merge_sort(int* array, int size) {
	if ((array == NULL) || (size <= 0)) {
		printf("Invalid input parameters. Exiting.\n");
	}
	return;
}
