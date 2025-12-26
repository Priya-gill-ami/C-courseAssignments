#ifndef HARDWARE_H
#define HARDWARE_H

#include <stdbool.h>

struct HardwareRegister {
    unsigned Done : 1;           // Bit 0: Done bit
    unsigned unused1 : 1;        // Bit 1: Unused
    unsigned EndAddress : 6;     // Bits 2-7: End Address
    unsigned unused2 : 4;        // Bits 8-11: Unused
    unsigned StartAddress : 6;   // Bits 12-17: Start Address
    unsigned unused3 : 13;       // Bits 18-30: Unused
    unsigned Enable : 1;         // Bit 31: Enable bit
};

// Function prototypes
void clearEnable(struct HardwareRegister *hw);
void setStartAddress(struct HardwareRegister *hw, unsigned startAddress);
void setEndAddress(struct HardwareRegister *hw, unsigned endAddress);
void setEnable(struct HardwareRegister *hw);
bool checkDone(struct HardwareRegister *hw);
void simulateDoneBit(struct HardwareRegister *hw);

#endif 
