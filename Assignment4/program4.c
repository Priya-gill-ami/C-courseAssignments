#include <stdio.h>
#include "fncts.h"

int main() {
    char choice;
    float x, y, z, distance;

    while (1) {  // infinite loop 
        // Get the coordinates from the user
        x = getX();
        y = getY();
        z = getZ();

        // Calculate the distance
        distance = calcDist(x, y, z);

        // Display the result
        dispRes(distance);

        // Ask the user if they want to continue
        printf("Would you like to continue or not? ");
        scanf(" %c", &choice);  
        if (choice != 'y' && choice != 'Y') {
            break;  // Exit the loop 
        }
    }

    return 0;
}
