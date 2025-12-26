#include "inventory.h"

int main()
{
    int choice;
    initializeInventory();

    while (true)
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addPart();
            break;
        case 2:
            modifyPart();
            break;
        case 3:
            deletePart();
            break;
        case 4:
            findPart();
            break;
        case 5:
            printf("Exiting the program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
