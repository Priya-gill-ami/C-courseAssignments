#include <stdio.h>
#include <math.h>

// Function to get X coordinate 
float getX() {
    float x;
    printf("Enter the x coordinate: ");
    scanf("%f", &x);
    return x;
}

// Function to get Y coordinate 
float getY() {
    float y;
    printf("Enter the y coordinate: ");
    scanf("%f", &y);
    return y;
}

// Function to get Z coordinate 
float getZ() {
    float z;
    printf("Enter the z coordinate: ");
    scanf("%f", &z);
    return z;
}

// Function to calculate distance
float calcDist(float x, float y, float z) {
    return sqrt(x * x + y * y + z * z);
}

// Function for the result
void dispRes(float distance) {
    printf("The distance from the origin is: %.2f\n", distance);
}
