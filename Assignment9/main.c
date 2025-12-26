#include <stdio.h>
#include "hardware.h"

int main() {
    // Initialization
    struct HardwareRegister hwRegister = {0};

    printf("Hardware Enablement Process:\n");

    // Step 1: Clear the Enable bit
    clearEnable(&hwRegister);

    // Step 2: Set the Start Address
    setStartAddress(&hwRegister, 0x12); 

    // Step 3: Set the End Address
    setEndAddress(&hwRegister, 0x34); 

    // Step 4: Set the Enable bit
    setEnable(&hwRegister);

    // Simulate the hardware function setting the Done bit
    simulateDoneBit(&hwRegister);

    // Check the Done bit
    if (checkDone(&hwRegister)) {
        printf("Function complete. Done bit is set.\n");
    } else {
        printf("Function not complete. Done bit is not set.\n");
    }

    return 0;
}
