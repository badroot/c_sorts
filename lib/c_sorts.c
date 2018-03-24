//
// Created by Red on 3/21/2018.
//

/**
 * Algs to implement
 * TODO Bubblesort
 * TODO Insertion Sort
 * TODO Quicksort
 * TODO Shell sort
 * TODO Mergesort
 * TODO Heapsort
 * TODO Radix Sort
 */

#include "c_sorts.h"
#include <stdio.h>
#include <stdlib.h>

void hello(void) {
    printf("Hello, World!\n");
}

void swap(int data_set[], int i, int j) {
    int temp = data_set[i];
    data_set[i] = data_set[j];
    data_set[j] = temp;
}

/*
 * Assumes array is not null, otherwise division for array size will fail
 * for int arrays
 */
void bubblesort(int data_set[], int size){
    int bound = 1;
    int changes = 1;
    int i = 2;
    while( i > 1 && changes > 0 ) {
//        printf("HERE\n");
        changes = 0;
        for (i = 0; i < size - bound; i++) {
            if (data_set[i] > data_set[i+1]) {
//                printf("SWAP\n");
                int temp = data_set[i];
                data_set[i] = data_set[i+1];
                data_set[i+1] = temp;
                changes++;
            }
//            printf("%d\n", i);
        }
        bound++;    //Increase bound to not touch the sorted section of the array
    }
}

void sel_sort(int data_set[], int size){
    for (int i = 0; i < size; ++i) {
        int min = i;
        for (int j = i+1; j < size; ++j) {
            if( data_set[j] < data_set[min] ) { min = j; }
        }
        swap(data_set, i, min);
    }
}

void td_mergesort(int data_set[], int size) {
    int* aux = (int *)calloc(size, sizeof(int));
    td_sort(data_set, aux, 0, size-1);
}

void td_sort(int arr[], int aux[], int lo, int hi) {
    if(hi <= lo) { return; }
    int mid = lo + ( ( hi - lo) / 2 );
    td_sort(arr, aux, lo, mid);
    td_sort(arr, aux, mid+1, hi);
    merge(arr, aux, lo, mid, hi);
}

void merge(int arr[], int aux[], int lo, int mid, int hi){
    int i = lo;
    int j = mid+1;
    for (int k = lo; k <= hi; ++k) { aux[k] = arr[k]; }

    for (int k = lo; k <= hi ; ++k) {
        if ( i > mid ) { arr[k] = aux[j++]; }
        else if ( j > hi ) { arr[k] = aux[i++]; }
        else if ( aux[j] < aux[i] ) { arr[k] = aux[j++]; }
        else { arr[k] = aux[i++]; }
    }

}



