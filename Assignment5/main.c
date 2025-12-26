#include <stdio.h>
#include "arrays.h"

#define SIZE 10

int main()
{
    int arr[SIZE];
    int choice, index, value;

    initialize_array(arr, SIZE); // Initialize the array with 0s

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create an array (set to 0)\n");
        printf("2. Print a specific array element\n");
        printf("3. Print the entire array\n");
        printf("4. Set a particular array element\n");
        printf("5. Get the address of a particular element\n");
        printf("6. Get start and end address of the array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            initialize_array(arr, SIZE);
            printf("Array initialized to 0\n");
            break;
        case 2:
            printf("Enter index (0-%d): ", SIZE - 1);
            scanf("%d", &index);
            print_array_element(arr, index, SIZE);
            break;
        case 3:
            print_array(arr, SIZE);
            break;
        case 4:
            printf("Enter index (0-%d): ", SIZE - 1);
            scanf("%d", &index);
            printf("Enter value: ");
            scanf("%d", &value);
            set_array_element(arr, index, value, SIZE);
            break;
        case 5:
            printf("Enter index (0-%d): ", SIZE - 1);
            scanf("%d", &index);
            get_array_element_address(arr, index, SIZE);
            break;
        case 6:
            get_array_start_end_address(arr, SIZE);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
