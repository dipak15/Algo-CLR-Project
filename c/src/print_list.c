/*
 * print_list.c
 *
 *  Created on: Oct 18, 2015
 *      Author: dk
 */

#include <stdio.h>

void print_array(int *array, int size) {
	int n = size;
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return;
}

