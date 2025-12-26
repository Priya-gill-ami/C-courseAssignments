
/****
 *  @author Priya Gill
 ****/

#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t arr_unt1[10];
    int16_t arr_int[10];
    uint32_t arr_unt2[10];

    uint8_t *ptrarr_unt1;
    int16_t *ptrarr_int;
    uint32_t *ptrarr_unt2;

    // for loop to initialize uint8_t array (0 to 9)
    for (int i = 0; i < 10; i++)
    {
        arr_unt1[i] = i;
    }

    // while loop to initialize int16_t array (0 to 9)
    int i = 0;
    while (i < 10)
    {
        arr_int[i] = i;
        i++;
    }

    // do-while loop to initialize uint32_t array (0 to 9)
    i = 0;
    do
    {
        arr_unt2[i] = i;
        i++;
    } while (i < 10);

    ptrarr_unt1 = (uint8_t *)arr_unt1;
    ptrarr_int = (int16_t *)arr_int;
    ptrarr_unt2 = (uint32_t *)arr_unt2;

    printf("Values in uint8_t array:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(ptrarr_unt1 + i)); // Print value at each pointer location
    }
    printf("\n");

    printf("Values in uint16_t array:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(ptrarr_int + i)); // Print value at each pointer location
    }
    printf("\n");

    printf("Values in uint32_t array:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(ptrarr_unt2 + i)); // Print value at each pointer location
    }
    printf("\n");

    /****
    - The uint8_t pointer increments by 1 byte, since uint8_t is 1 byte in size.
    - The int16_t pointer increments by 2 bytes, since int16_t is 2 bytes in size.
    - The uint32_t pointer increments by 4 bytes, since uint32_t is 4 bytes in size.
    - This is due to the size of each type (1 byte for uint8_t, 2 bytes for int16_t, and 4 bytes for uint32_t).
    - The output is same because of casting as it matches the pointer type with the array where it is necessary.
   ****/

    return 0;
}