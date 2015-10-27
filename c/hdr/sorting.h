/*
 * sorting.h
 *
 *  Created on: Oct 17, 2015
 *      Author: dk
 */

#ifndef C_SORTING_H_
#define C_SORTING_H_

extern void insertion_sort(int* array, int size);
extern void test_insertion_sort(int* array, int size);

extern void merge_sort(int* array, int size);
extern void test_merge_sort(int* array, int size);

extern void quick_sort_int(int *array, int p, int r);
extern void test_quick_sort(int* array, int size);

#endif /* C_SORTING_H_ */
