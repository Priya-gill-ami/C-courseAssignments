#include <stdio.h>
#include <stdint.h>

int main() {
    // Step 1: Assigning the largest possible positive value to an integer
    int largest_int = 648467;  // Max value for int
    printf("Largest int: %d\n", largest_int);

    // Step 2: Cast the integer to a short int
    short int casted_to_short = (short int)largest_int;
    printf("After casting to short int: %d\n", casted_to_short);
    /**** Explanation: For the int value = 64846756 program compiled successfully. But for value = 64846756787, got the error - warning: overflow in implicit constant conversion [-Woverflow]'short int' has a smaller range than 'int', so casting causes overflow, wrapping the value. ****/

    // Step 3: Assign the largest possible negative value to an integer
    int smallest_int = -12;  // Min value for int
    printf("Smallest int: %d\n", smallest_int);

    // Step 4: Cast the negative integer to a short int
    casted_to_short = (short int)smallest_int;
    printf("After casting smallest int to short int: %d\n", casted_to_short);
    /**Explanation: When casting the smallest int to short int, overflow causes the value to wrap around. 
      I entered values of Largest int: 648467
      After casting to short int: -6893 
      smallest int: -12
      After casting smallest int to short int: -12 **/

    // Step 5: Cast the smallest negative integer to an unsigned integer
    unsigned int casted_to_unsigned = (unsigned int)smallest_int;
    printf("After casting smallest int to unsigned int: %u\n", casted_to_unsigned);
    /*** Explanation: Negative values, when cast to unsigned, become large positive numbers because unsigned types do not store negative values.  
        After casting smallest int to unsigned int: 4294967284   ***/

    // Step 6: Illustrating user input
    int userInt;
    printf("\nEnter an integer: ");
    scanf("%d", &userInt);
    printf("Entered integer: %d\n", userInt);

    char userChar;
    printf("\nEnter a character: ");
    scanf("%d", &userChar);
    printf("Entered character: %d\n", userChar);

    // Step 7: Floating-point number example
    float pi = 3.14159;  // Approximate value of pi
    printf("Pi as a float: %f\n", pi);

    // Step 8: Cast the float to an integer
    int pi_as_int = (int)pi;
    printf("Pi after casting to int: %d\n", pi_as_int);
    /** Explanation: Casting a float to an int removes the decimal part, resulting in 3. 
    Enter an integer: 75
    Entered integer: 75
    Enter a character: P
    Entered character: 117
    Pi as a float: 3.141590
    Pi after casting to int: 3        **/

    return 0;
}