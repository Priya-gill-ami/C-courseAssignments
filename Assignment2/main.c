#include <stdio.h>

/*/************************************************************************
* Name: Program #2
*try
* Description: calculating the range of an electric vehicle based on the charge level and outside temperature.
*
**************************************************************************/

int main(){

    float chargeLevel, outsideTemp, range, tempFactor; 

    const float fullRange = 300.0;  // Full range of the vehicle at 25°C
    const float baseTemp = 25.0;    // Temperature at full range
    const float lowestTemp = -20.0; // Temperature at which range is 50%

    //query user for starting charge level at 75 F
    printf("Enter the charge level as a percentage: ");
    scanf("%f", &chargeLevel);

    //query the user for the temperature of operation
    printf("Enter the outside temperature in degrees Celsius: ");
    scanf("%f", &outsideTemp);

    //implement algorithm to calculate range from a base charge level and a temperature

    tempFactor = (0.5 / (baseTemp - lowestTemp)) * (outsideTemp - lowestTemp) + 0.5;
    tempFactor = (tempFactor > 1.0) ? 1.0 : tempFactor;
    range = fullRange * (chargeLevel / 100.0) * tempFactor;

    printf("The estimated range of the vehicle is: %.2f miles\n", range);

    return 0;

}