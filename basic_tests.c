//
// Created by Red on 3/21/2018.
//

#include <stdio.h>
#include "lib/c_sorts.h"
//#include <gtest>

#define ARRAYLENGTH(a) ( sizeof (a) / sizeof (*(a)) )

int main(int argc, char* argv[]) {
    int bingo[15] = {5,6,89,458,1583,684,15,384,8,3847,4,654,39,987,139};
    printf("SIZE:\t%d\n", ((int)ARRAYLENGTH(bingo)));
    bubblesort(bingo, (int)ARRAYLENGTH(bingo));
    for (int i = 0; i<15; i++) {
        printf("%d, ", bingo[i]);
    }


    return 0;
}