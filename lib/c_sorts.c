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

void hello(void) {
    printf("Hello, World!\n");
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