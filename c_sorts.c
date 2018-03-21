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

#define ARRAYLENGTH(a) ( sizeof (a) / sizeof (*(a)) )

void hello(void) {
    printf("Hello, World!\n");
}

/*
 * Assumes array is not null, otherwise division for array size will fail
 * for int arrays
 */
void bubblesort(int data_set[]){
    int bound = 1;
    int changes = 0;
    int i = 0;
    while( i > 1 && changes > 0 ) {
        changes = 0;
        for (i = 0; i < ARRAYLENGTH(data_set) - bound; i++) {
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