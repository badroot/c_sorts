//
// Created by Red on 3/21/2018.
//

/**
 * Algs to implement
 * TODO Insertion Sort
 * TODO Quicksort
 * TODO Shell sort
 * TODO Heapsort
 * TODO American Flag
 */

#include "c_sorts.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * array-style queue
 * must interact with front/back manually
 */
struct Queue{
    int front, back;
    int* data;
};

/**
 * TEMPORARY
 * this will be kept in as a method to verify the library link of methods is functioning properly
 */
void hello(void) {
    printf("Hello, World!\n");
}

/**
 * is_sorted is used to confirm sorted-ness
 * @param carr array of data
 * @param size size of array
 * @return boolean value of sorted or not
 */
int is_sorted(const int data_set[], int size){
    for (int i = 0; i < size-1; ++i) {
        if(data_set[i] > data_set[i+1]){ return 0; }
    }
    return 1;
}

/**
 * swap changes the position of two elements in the array
 * @param data_set
 * @param i index of first element
 * @param j index of second element
 */
void swap(int data_set[], int i, int j) {
    int temp = data_set[i];
    data_set[i] = data_set[j];
    data_set[j] = temp;
}

/**
 *
 * @param a
 * @param b
 * @return
 */
int bin_min(int a, int b){
    return a < b ? a : b;
}


/**
 * max iterates through an array to find the largest value
 * @param data_set
 * @param size
 * @return value of largest element in array
 */
int max(const int data_set[], int size){
    int maxi = data_set[0];
    for (int i = 1; i < size; ++i) {
        if (data_set[i] > maxi ) { maxi = data_set[i]; }
    }
    return maxi;
}

/**
 * max_bit finds the number of bits needed to represent the largest value in the array
 * @param data_set
 * @param size
 * @return number of bits needed to represent the largest value
 */
int max_bit(const int data_set[], int size){
    int maxVal = max(data_set, size);
    int check = 0;
    int shift = 0;
    for (shift; check <= maxVal ; ++shift) {
        check = 0;
        check |= 1<<shift;
//        printf("MAX: %d\t CHECK: %d\t SHIFT: %d\n", maxVal, check, shift);    //FOR DEBUG
    }
    return shift-2;     //sub 1 to as the highest power after is not needed, sub 1 again to undo ++shift in loop
}

/**
 * array_copy makes a new array in memory identical to what is passed to it
 * @param data_set
 * @param size
 * @return pointer to copy array
 */
int* array_copy(const int data_set[], int size){
    int* newArr = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        newArr[i] = data_set[i];
    }
    return newArr;
}

/**
 * print_array prints a formatted version of the array data passed to it
 * @param data_set
 * @param size
 */
void print_array(const int data_set[], int size){
    for (int i = 0; i < size; ++i) {
        if ( 0 == i)        { printf("["); }
                              printf("%d", data_set[i]);
        if( size - 1 == i)  { printf("]\n"); }
        else                { printf(", "); }
    }
}

/**
 * bubblesort algorithm of sorting data
 * @param data_set
 * @param size
 */
void bubblesort(int data_set[], int size){
    int bound = 1;
    int changes = 1;
    int i = 2;
    while( i > 1 && changes > 0 ) {
        changes = 0;
        for (i = 0; i < size - bound; i++) {
            if (data_set[i] > data_set[i+1]) {
                int temp = data_set[i];
                data_set[i] = data_set[i+1];
                data_set[i+1] = temp;
                changes++;
            }
        }
        bound++;    //Increase bound to not touch the sorted section of the array
    }
}

/**
 * selection sort algorithm of sorting data
 * @param data_set
 * @param size
 */
void sel_sort(int data_set[], int size){
    for (int i = 0; i < size; ++i) {
        int min = i;
        for (int j = i+1; j < size; ++j) {
            if( data_set[j] < data_set[min] ) { min = j; }
        }
        swap(data_set, i, min);
    }
}

/**
 * top-down mergesort algorithm of sorting data
 * @param data_set
 * @param size
 */
void td_mergesort(int data_set[], int size) {
    int* aux = (int *)calloc(size, sizeof(int));
    td_sort(data_set, aux, 0, size-1);
}

/**
 * top-down sort section of td_mergesort
 * @param arr
 * @param aux
 * @param lo
 * @param hi
 */
void td_sort(int arr[], int aux[], int lo, int hi) {
    if(hi <= lo) { return; }
    int mid = lo + ( ( hi - lo) / 2 );
    td_sort(arr, aux, lo, mid);
    td_sort(arr, aux, mid+1, hi);
    merge(arr, aux, lo, mid, hi);
}

/**
 *
 * @param data_set
 * @param size
 */
void bu_mergesort(int data_set[], int size) {
    int* aux = (int *)calloc(size, sizeof(int));
    for (int m_len = 1; m_len < size; m_len *= 2){
        for (int lo = 0; lo < size - m_len; lo += 2*m_len) {
            merge(data_set, aux, lo, lo+m_len-1, bin_min( (2*m_len)+lo-1, size-1));
        }
    }
}

/**
 * merge is used for top-down and bottom-up mergesort
 * @param arr
 * @param aux
 * @param lo
 * @param mid
 * @param hi
 */
void merge(int arr[], int aux[], int lo, int mid, int hi){
    int i = lo;
    int j = mid+1;
    for (int k = lo; k <= hi; ++k) { aux[k] = arr[k]; }

    for (int k = lo; k <= hi ; ++k) {
        if ( i > mid )              { arr[k] = aux[j++]; }
        else if ( j > hi )          { arr[k] = aux[i++]; }
        else if ( aux[j] < aux[i] ) { arr[k] = aux[j++]; }
        else                        { arr[k] = aux[i++]; }
    }

}

/**
 * radix sort algorithm of sorting data
 * @param data_set
 * @param size
 */
void radix_sort(int data_set[], int size) {

    int maxbit = max_bit(data_set, size);

    for (int i = 0; i <= maxbit; ++i) {

        struct Queue* zqueue = malloc(sizeof(struct Queue));
        struct Queue* oqueue = malloc(sizeof(struct Queue));

        *zqueue = (struct Queue){0, 0, calloc(size, sizeof(int))};
        *oqueue = (struct Queue){0, 0, calloc(size, sizeof(int))};

        // Splits data by bit-set-ness for bit j
        for (int j = 0; j < size; ++j) {
            if ((data_set[j] >> i) & 1) { oqueue->data[oqueue->back++] = data_set[j]; }
            else                        { zqueue->data[zqueue->back++] = data_set[j]; }
        }
        int place = 0;
        // Reads data back into array
        for (; zqueue->front < zqueue->back; (zqueue->front)++) { data_set[place++] = zqueue->data[zqueue->front]; }
        for (; oqueue->front < oqueue->back; (oqueue->front)++) { data_set[place++] = oqueue->data[oqueue->front]; }

        free(zqueue);
        free(oqueue);
    }
}



