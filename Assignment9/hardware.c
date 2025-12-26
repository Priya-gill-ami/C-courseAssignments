#include <stdio.h>
#include "hardware.h"

// Function to clear the Enable bit
void clearEnable(struct HardwareRegister *hw) {
    hw->Enable = 0;
    printf("Enable bit cleared.\n");
}

// Function to set the Start Address
void setStartAddress(struct HardwareRegister *hw, unsigned startAddress) {
    hw->StartAddress = startAddress & 0x3F;  // Mask to 6 bits
    printf("Start Address set to: 0x%02X\n", hw->StartAddress);
}

// Function to set the End Address
void setEndAddress(struct HardwareRegister *hw, unsigned endAddress) {
    hw->EndAddress = endAddress & 0x3F;  
    printf("End Address set to: 0x%02X\n", hw->EndAddress);
}

// Function to set the Enable bit
void setEnable(struct HardwareRegister *hw) {
    hw->Enable = 1;
    printf("Enable bit set.\n");
}

// Function to check if the Done bit is set
bool checkDone(struct HardwareRegister *hw) {
    return hw->Done;
}

// Function to simulate the Done bit changing state
void simulateDoneBit(struct HardwareRegister *hw) {
    printf("Simulating hardware function...\n");
    hw->Done = 1;  // Simulate hardware setting the Done bit
    printf("Done bit is now set.\n");
}
