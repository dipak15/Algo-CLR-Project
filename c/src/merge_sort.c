/*
 * merge_sort.c
 *
 *  Created on: Oct 18, 2015
 *      Author: Dipak K Narayan
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include <print_list.h>

void merge_int(int* array, int p, int q, int r) {
  int *arr_a;
  int *arr_b;
  int n1 = q - p + 1;
  int n2 = r - q;
  int i, j, k;

  arr_a = (int *) malloc((n1 + 1) * sizeof(int));
  arr_b = (int *) malloc((n2 + 1) * sizeof(int));

  for (i = 0; i < n1; i++) {
    arr_a[i] = array[p + i];
  }

  for (j = 0; j < n2; j++) {
    arr_b[j] = array[q + 1 + j];
  }

  arr_a[n1] = INT_MAX;
  arr_b[n2] = INT_MAX;

  i = 0;
  j = 0;
  for (k = p; k <= r; k++) {
    if (arr_a[i] <= arr_b[j]) {
      array[k] = arr_a[i];
      ++i;
    } else {
      array[k] = arr_b[j];
      ++j;
    }
  }

  free(arr_a);
  free(arr_b);

  return;
}

void merge_sort_int(int* array, int p, int r) {
  int q = (p + r) / 2;
  if (p < r) {
    merge_sort_int(array, p, q);
    merge_sort_int(array, q + 1, r);
    merge_int(array, p, q, r);
  }
  return;
}

void merge_sort(int* array, int size) {
  if ((array == NULL) || (size <= 0)) {
    printf("Invalid input parameters. Exiting.\n");
  }
  merge_sort_int(array, 0, size - 1);
  return;
}

void test_merge_sort(int* array, int size) {
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
  merge_sort(a, n);
  print_array(a, n);
  return;
}
