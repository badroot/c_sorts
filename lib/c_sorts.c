//
// Created by Red on 3/21/2018.
//

/**
 * Algs to implement
 * TODO Insertion Sort
 * TODO Quicksort
 * TODO Shell sort
 * TODO Bottom Up Mergesort
 * TODO Heapsort
 * TODO Radix Sort
 */

#include "c_sorts.h"
#include <stdio.h>
#include <stdlib.h>

//#define BIT_SET(var, shift) ( (var) & (1<<(shift) ) )

struct Queue{
    int front, back;
    int* data;
};

void hello(void) {
    printf("Hello, World!\n");
}

int is_sorted(int carr[], int size){
    for (int i = 0; i < size-1; ++i) {
        if(carr[i] > carr[i+1]){ return 0; }
    }
    return 1;
}

void swap(int data_set[], int i, int j) {
    int temp = data_set[i];
    data_set[i] = data_set[j];
    data_set[j] = temp;
}

int max(int data_set[], int size){
    int maxi = data_set[0];
    for (int i = 1; i < size; ++i) {
        if (data_set[i] > maxi ) { maxi = data_set[i]; }
    }
    return maxi;
}

int max_bit(int data_set[], int size){
    int maxVal = max(data_set, size);
    int check = 0;
    int shift = 0;
    for (shift; check <= maxVal ; ++shift) {
        check = 0;
        check |= 1<<shift;
//        printf("MAX: %d\t CHECK: %d\t SHIFT: %d\n", maxVal, check, shift);
    }
    return shift-2;     //sub 1 to as the highest power after is not needed, sub 1 again to undo ++shift in loop
}

int* array_copy(int data_set[], int size){
    int* newArr = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        newArr[i] = data_set[i];
    }
    return newArr;
}

void print_array(int data_set[], int size){
    for (int i = 0; i < size; ++i) {
        if ( 0 == i)        { printf("["); }
        printf("%d", data_set[i]);
        if( size - 1 == i)  { printf("]\n"); }
        else                { printf(", "); }
    }
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

void radix_sort(int data_set[], int size) {
    printf("GETS TO SORT\n");
    int maxbit = max_bit(data_set, size);
//    printf("MAXBIT: %d\n", maxbit);
    for (int i = 0; i <= maxbit; ++i) {
//        printf("MB LOOP\n");
        struct Queue* zqueue = (struct Queue*)malloc(sizeof(struct Queue));
        struct Queue* oqueue = (struct Queue*)malloc(sizeof(struct Queue));
//        *zqueue = (struct Queue)(0, 0, );
        zqueue->front = 0;
        zqueue->back = 0;
        oqueue->front = 0;
        oqueue->back = 0;
        zqueue->data = (int*)calloc(size, sizeof(int));
        oqueue->data = (int*)calloc(size, sizeof(int));
//        printf("MB INIT\n");
        for (int j = 0; j < size; ++j) {
//            printf("BUCKET LOOP %d\n", j);
//            print_array(zqueue->data, size);
//            print_array(oqueue->data, size);
            int tt = (data_set[j] << i) & 1;
//            printf("BOOL %d\n", tt);
            if ((data_set[j] >> i) & 1) { oqueue->data[oqueue->back++] = data_set[j]; }
            else                        { zqueue->data[zqueue->back++] = data_set[j]; }
        }
        int place = 0;
//        printf("TO PLACE\n");
        for (; zqueue->front < zqueue->back; (zqueue->front)++) {
            data_set[place++] = zqueue->data[zqueue->front];
        }
//        print_array(data_set, size);

        for (; oqueue->front < oqueue->back; (oqueue->front)++) {
            data_set[place++] = oqueue->data[oqueue->front];
//            place++;
        }
//        print_array(data_set, size);

        free(zqueue);
        free(oqueue);
    }
}



