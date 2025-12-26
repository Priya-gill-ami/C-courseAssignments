#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PARTS 10000
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 200
#define MAX_URL_LEN 100
#define MAX_ID_LEN 9  // 8 characters + null terminator

typedef struct {
    char id[MAX_ID_LEN];
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    char manufacturer_part_number[MAX_NAME_LEN];
    char datasheet_url[MAX_URL_LEN];
    float cost;
} part_t;

// Function Prototypes
void initializeInventory();
int findNextOpenIndex();
void addPart();
void modifyPart();
void deletePart();
void findPart();
void displayMenu();

#endif // INVENTORY_H
