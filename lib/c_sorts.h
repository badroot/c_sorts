//
// Created by Red on 3/21/2018.
//

#ifndef PROJECT_C_SORTS_H
#define PROJECT_C_SORTS_H

void hello(void);

int is_sorted(int carr[], int size);
void swap(int data_set[], int i, int j);
int max(int data_set[], int size);
int max_bit(int data_set[], int size);
int* array_copy(int data_set[], int size);
void print_array(int data_set[], int size);

void bubblesort(int data_set[], int size);

void sel_sort(int data_set[], int size);

void td_mergesort(int data_set[], int size);

void td_sort(int arr[], int aux[], int lo, int hi);

void merge(int arr[], int aux[], int lo, int mid, int hi);

void radix_sort(int data_set[], int size);

#endif //PROJECT_C_SORTS_H
