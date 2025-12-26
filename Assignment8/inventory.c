#include "inventory.h"

// Global inventory array
part_t inventory[MAX_PARTS];

// Initialize the inventory to default values
void initializeInventory() {
    for (int i = 0; i < MAX_PARTS; i++) {
        inventory[i].id[0] = '\0';  // Mark unused slots with empty strings
    }
}

// Find the next open index in the inventory
int findNextOpenIndex() {
    for (int i = 0; i < MAX_PARTS; i++) {
        if (inventory[i].id[0] == '\0') {
            return i;
        }
    }
    return -1;  // No open slots
}

// Add a new part to the inventory
void addPart() {
    int index = findNextOpenIndex();
    if (index == -1) {
        printf("Inventory is full. Cannot add more parts.\n");
        return;
    }

    part_t new_part;

    printf("Enter Part ID (8 characters): ");
    scanf("%8s", new_part.id);

    printf("Enter Part Name: ");
    scanf(" %[^\n]s", new_part.name);

    printf("Enter Description: ");
    scanf(" %[^\n]s", new_part.description);

    printf("Enter Manufacturer's Part Number: ");
    scanf(" %[^\n]s", new_part.manufacturer_part_number);

    printf("Enter Data Sheet URL: ");
    scanf(" %[^\n]s", new_part.datasheet_url);

    printf("Enter Cost: ");
    scanf("%f", &new_part.cost);

    inventory[index] = new_part;
    printf("Part added successfully!\n");
}

// Modify an existing part
void modifyPart() {
    char id[MAX_ID_LEN];
    printf("Enter Part ID to modify: ");
    scanf("%8s", id);

    for (int i = 0; i < MAX_PARTS; i++) {
        if (strcmp(inventory[i].id, id) == 0) {
            printf("Part found. Enter new details.\n");

            printf("Enter Part Name: ");
            scanf(" %[^\n]s", inventory[i].name);

            printf("Enter Description: ");
            scanf(" %[^\n]s", inventory[i].description);

            printf("Enter Manufacturer's Part Number: ");
            scanf(" %[^\n]s", inventory[i].manufacturer_part_number);

            printf("Enter Data Sheet URL: ");
            scanf(" %[^\n]s", inventory[i].datasheet_url);

            printf("Enter Cost: ");
            scanf("%f", &inventory[i].cost);

            printf("Part modified successfully!\n");
            return;
        }
    }
    printf("Part with ID %s not found.\n", id);
}

// Delete a part from the inventory
void deletePart() {
    char id[MAX_ID_LEN];
    printf("Enter Part ID to delete: ");
    scanf("%8s", id);

    for (int i = 0; i < MAX_PARTS; i++) {
        if (strcmp(inventory[i].id, id) == 0) {
            inventory[i].id[0] = '\0';  // Mark the slot as unused
            printf("Part deleted successfully.\n");
            return;
        }
    }
    printf("Part with ID %s not found.\n", id);
}

// Find a part in the inventory
void findPart() {
    char id[MAX_ID_LEN];
    printf("Enter Part ID to find: ");
    scanf("%8s", id);

    for (int i = 0; i < MAX_PARTS; i++) {
        if (strcmp(inventory[i].id, id) == 0) {
            printf("Part Found:\n");
            printf("ID: %s\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Description: %s\n", inventory[i].description);
            printf("Manufacturer's Part Number: %s\n", inventory[i].manufacturer_part_number);
            printf("Data Sheet URL: %s\n", inventory[i].datasheet_url);
            printf("Cost: %.2f\n", inventory[i].cost);
            return;
        }
    }
    printf("Part with ID %s not found.\n", id);
}

// Display the menu
void displayMenu() {
    printf("\n--- Inventory Management System ---\n");
    printf("1. Add a new Part\n");
    printf("2. Modify an existing Part\n");
    printf("3. Delete a Part\n");
    printf("4. Find a Part\n");
    printf("5. Exit\n");
}
