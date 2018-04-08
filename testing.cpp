//
// Created by Red on 4/7/2018.
//
//#define verbose
#include <random>
#include <iostream>
extern "C" {
#include "lib/c_sorts.h"
}

using namespace std;

/**
 * randomize_array is a utility to generate a new random set of data in a fixed-size array
 * @param array is the pointer to the array
 * @param arr_max is the size of the array
 * @param range is the top of the range of the desired number generation, ie. from 1 to range
 */
void randomize_array(int* array, int arr_max, int range){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, range);
    for (int i = 0; i < arr_max; ++i) {
        array[i] = dist(gen);
    }
}

int main(int argc, char *argv[]){
    int arr_max = 40;
    int range = 100;
    int sort_arr[arr_max];
    cout<<"STARTING TESTS"<<endl;

    cout<<"============UTILITIES============"<<endl;
    cout<<"Randomize: ";
    randomize_array(sort_arr, arr_max, range);
    int element_1 = sort_arr[0];
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif
    randomize_array(sort_arr, arr_max, range);
    int element_2 = sort_arr[0];
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif
    if(element_1 != element_2){
        cout<<"Success"<<endl;
    } else {
        cout<<"Failure"<<endl<<"Aborting tests"<<endl;
        return 0;
    }
    //TODO COMPLETE TESTS FOR THE REST OF THE UTILITIES

    cout<<"==============SORTS=============="<<endl;
    cout<<"Bubblesort: ";
    bubblesort(sort_arr, arr_max);
    if (is_sorted(sort_arr, arr_max)){
        cout<<"Sorted"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif
    randomize_array(sort_arr, arr_max, range);
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif

    cout<<"Selection sort: ";
    sel_sort(sort_arr, arr_max);
    if (is_sorted(sort_arr, arr_max)){
        cout<<"Sorted"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif
    randomize_array(sort_arr, arr_max, range);
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif

    cout<<"Top-Down Mergesort: ";
    td_mergesort(sort_arr, arr_max);
    if (is_sorted(sort_arr, arr_max)){
        cout<<"Sorted"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif
    randomize_array(sort_arr, arr_max, range);
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif

    cout<<"Bottom-Up Mergesort: ";
    bu_mergesort(sort_arr, arr_max);
    if (is_sorted(sort_arr, arr_max)){
        cout<<"Sorted"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif
    randomize_array(sort_arr, arr_max, range);
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif

    cout<<"Radix sort: ";
    radix_sort(sort_arr, arr_max);
    if (is_sorted(sort_arr, arr_max)){
        cout<<"Sorted"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif
    randomize_array(sort_arr, arr_max, range);
#ifdef verbose
    print_array(sort_arr, arr_max);
#endif

    cout<<"END TESTS"<<endl;

}
