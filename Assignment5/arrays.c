#include <stdio.h>
#include "arrays.h"

// Initialize array with values 0
void initialize_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

// Print a single array element specified by the user
void print_array_element(int arr[], int index, int size) {
    if (index >= 0 && index < size) {
        printf("Element at index %d: %d\n", index, arr[index]);
    } else {
        printf("Index out of bounds!\n");
    }
}

// For Printing the entire array
void print_array(int arr[], int size){
    for(int i= 0; i< size; i++){
    printf("%d", arr[i]);
    }
    printf("\n");
}

// for the user to set a particular array element to a value they input
void set_array_element(int arr[], int index, int value, int size){
    if(index >= 0 && index < size){
        arr[index] = value;
        printf("Element at index %d has value of %d",index, value);
    }else{
        printf("Index is not in range.");
    }
}

//for obtaining the address of a selected array index
void get_array_element_address(int arr[], int index, int size){
    if(index >= 0 && index < size){
        printf("Address of the element at index %d is : %p", index, (void*)&arr[index]);
    }
}

//for returning the start and end address of the array
void get_array_start_end_address(int arr[], int size) {
    printf("Start address of the array: %p\n", (void*)&arr[0]);
    printf("End address of the array: %p\n", (void*)&arr[size - 1]);
}


