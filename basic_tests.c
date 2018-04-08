//
// Created by Red on 3/21/2018.
//

#include <stdio.h>
#include "lib/c_sorts.h"
#include <stdlib.h>
//#include <gtest>

#define ARRAYLENGTH(a) ( sizeof (a) / sizeof (*(a)) )

int main(int argc, char* argv[]) {
//    int p = 2048;
//    int* l = &p;
//    int mb = max_bit(l, 1);
//    printf("%d", mb);
//    int m = (6 >> 1) & 1;
//    printf("%d\n", m);

    int bingo[16] = {5,6,89,458,1583,684,15,384,8,3847,4,654,39,987,139, 23};
    printf("SIZE:\t%d\n", (int)ARRAYLENGTH(bingo));
//    bubblesort(bingo, (int)ARRAYLENGTH(bingo));
//    td_mergesort(bingo,  (int)ARRAYLENGTH(bingo));
    radix_sort(bingo, (int)ARRAYLENGTH(bingo));
    if (is_sorted(bingo,  (int)ARRAYLENGTH(bingo))) { printf("SORTED\n"); }
    else { printf("NOPE\n"); }
    print_array(bingo, (int)ARRAYLENGTH(bingo));


    return 0;
}