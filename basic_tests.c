//
// Created by Red on 3/21/2018.
//

#include <stdio.h>
//#include <w32api/vss.h>
#include "lib/c_sorts.h"
//#include <gtest>

#define ARRAYLENGTH(a) ( sizeof (a) / sizeof (*(a)) )

int is_sorted(int carr[], int size){
    for (int i = 0; i < size-1; ++i) {
        if(carr[i] > carr[i+1]){ return 0; }
    }
    return 1;
}

int main(int argc, char* argv[]) {
    int bingo[16] = {5,6,89,458,1583,684,15,384,8,3847,4,654,39,987,139, 23};
    printf("SIZE:\t%d\n", (int)ARRAYLENGTH(bingo));
//    bubblesort(bingo, (int)ARRAYLENGTH(bingo));
    td_mergesort(bingo,  (int)ARRAYLENGTH(bingo));
    if (is_sorted(bingo,  (int)ARRAYLENGTH(bingo))) { printf("SORTED\n"); }
    else { printf("NOPE\n"); }
    for (int i = 0; i< (int)ARRAYLENGTH(bingo); i++) {
        printf("%d, ", bingo[i]);
    }


    return 0;
}