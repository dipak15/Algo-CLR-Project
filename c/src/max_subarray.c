/*
 * max_subarray.c
 *
 *  Created on: Oct 20, 2015
 *      Author: dk
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include <print_list.h>

void find_max_cross_array(int *array, int p, int mid, int q, int *a, int *b,
		int *sum) {
	int left_sum, left_idx;
	int right_sum, right_idx;
	int i, temp;

	left_sum = array[mid];
	left_idx = mid;
	temp = 0;
	for (i = mid; i >= p; i--) {
		temp += array[i];
		if (temp > left_sum) {
			left_sum = temp;
			left_idx = i;
		}
	}

	right_sum = array[mid + 1];
	right_idx = mid + 1;
	temp = 0;
	for (i = mid + 1; i <= q; i++) {
		temp += array[i];
		if (temp > right_sum) {
			right_sum = temp;
			right_idx = i;
		}
	}

	a[0] = left_idx;
	b[0] = right_idx;
	sum[0] = left_sum + right_sum;

	return;
}

void find_max_subarray(int *array, int p, int q, int *a, int *b, int *sum) {

	int l1, l2, lsum;
	int r1, r2, rsum;
	int c1, c2, csum;
	int mid;

	if (p == q) {
		a[0] = p;
		b[0] = q;
		sum[0] = array[p];
		return;
	}

	mid = (p + q) / 2;

	find_max_subarray(array, p, mid, &l1, &l2, &lsum);
	find_max_subarray(array, mid + 1, q, &r1, &r2, &rsum);
	find_max_cross_array(array, p, mid, q, &c1, &c2, &csum);

	if ((lsum >= rsum) && (lsum >= csum)) {
		a[0] = l1;
		b[0] = l2;
		sum[0] = lsum;
	} else if ((rsum >= lsum) && (rsum >= csum)) {
		a[0] = r1;
		b[0] = r2;
		sum[0] = rsum;
	} else {
		a[0] = c1;
		b[0] = c2;
		sum[0] = csum;
	}
	return;
}

void find_max_subarray_linear(int *array, int p, int q, int *a, int *b,
		int *sum) {

	int i, idx, sumx;
	*a = p;
	*b = p;
	*sum = array[p];

	idx = p;
	sumx = array[p];

	for (i = p + 1; i <= q; i++) {
		/* add current element to buffer until sum-x is positive */
		if ((sumx <= 0) && (array[i] > 0)) {
			idx = i;
			sumx = array[i];
		} else if ((sumx + array[i]) > 0) {
			sumx = sumx + array[i];
		} else {
			idx = i;
			sumx = array[i];
		}

		/* compare new list with previous list */
		if (sumx > *sum) {
			*a = idx;
			*b = i;
			*sum = sumx;
		}
	}

	return;
}

void test_max_subarray(int* array, int size) {
	int MAX_RANDOM_NUMBER = 91;
	int a[30];
	int b[30] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15,
			-4, 7 };
	int n = 16;
	int i, p, q, sum;

	/* Initializes random number seed */
	srand(time(0));

	/* Generate random numbers for testing */
	for (i = 0; i < n; i++) {
		a[i] = rand() % MAX_RANDOM_NUMBER;
		if (a[i] % 11 < 6) {
			a[i] = -1 * a[i];
		}
	}

	print_array(b, n);
	print_array(a, n);

	find_max_subarray(a, 0, n - 1, &p, &q, &sum);
	printf("%d %d %d\n", p, q, sum);
	find_max_subarray_linear(a, 0, n - 1, &p, &q, &sum);
	printf("%d %d %d\n", p, q, sum);

	return;
}
