#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DESC_LENGTH 100

//Define a structure for product
typedef struct Product {
    char name[MAX_NAME_LENGTH + 1];
    int stock;
    float price;
    union {
        struct {
            float length;
            float width;
            float height;
        } dimensions;
        char description[MAX_DESC_LENGTH + 1];
    } info;
    struct Product *next; //Pointer to the next product in the list
} Product;

//Function prototypes
void displayMenu();
void addProduct(Product **inventory);
void displayProducts(Product *inventory);
void updateQuantity(Product *inventory);
void updatePrice(Product *inventory);
void deleteProduct(Product **inventory);
void freeInventory(Product *inventory);

int main() {
    Product *inventory = NULL;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                displayProducts(inventory);
                break;
            case 3:
                updateQuantity(inventory);
                break;
            case 4:
                updatePrice(inventory);
                break;
            case 5:
                deleteProduct(&inventory);
                break;
            case 6:
                freeInventory(inventory);
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

//Function to display the menu
void displayMenu() {
    printf("\n===== Inventory Management System Menu =====\n");
    printf("1. Add a new product\n");
    printf("2. Display information about all products\n");
    printf("3. Update the quantity of an existing product\n");
    printf("4. Update the price of an existing product\n");
    printf("5. Delete a product\n");
    printf("6. Exit\n");
}

//Function to add a new product in the inventory
void addProduct(Product **inventory) {
    Product *newProduct = (Product *)malloc(sizeof(Product));
    if (newProduct == NULL) {
        printf("Memory allocation failed. Unable to add product.\n");
        return;
    }

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct->name);
    printf("Enter stock quantity: ");
    scanf("%d", &newProduct->stock);
    printf("Enter price: ");
    scanf("%f", &newProduct->price);

    printf("Enter product description or dimensions (length width height): ");
    char input[MAX_DESC_LENGTH + 1];
    scanf(" %[^\n]", input);

    if (sscanf(input, "%f %f %f", &newProduct->info.dimensions.length,
               &newProduct->info.dimensions.width, &newProduct->info.dimensions.height) == 3) {
        newProduct->info.description[0] = '\0';
    } else {
        strncpy(newProduct->info.description, input, MAX_DESC_LENGTH);
        newProduct->info.description[MAX_DESC_LENGTH] = '\0';
    }

    newProduct->next = *inventory;
    *inventory = newProduct;
    printf("Product added successfully.\n");
}

//Function to display information about all products
void displayProducts(Product *inventory) {
    printf("\n===== Products in Inventory =====\n");
    if (inventory == NULL) {
        printf("Inventory is empty.\n");
        return;
    }

    while (inventory != NULL) {
        printf("Name: %s, Stock: %d, Price: %.2f", inventory->name, inventory->stock, inventory->price);
        if (inventory->info.description[0] != '\0') {
            printf(", Description: %s\n", inventory->info.description);
        } else {
            printf(", Dimensions: %.2f x %.2f x %.2f\n", inventory->info.dimensions.length,
                   inventory->info.dimensions.width, inventory->info.dimensions.height);
        }
        inventory = inventory->next;
    }
}

//Function to update the number of an existing product
void updateQuantity(Product *inventory) {
    char targetName[MAX_NAME_LENGTH + 1];
    printf("Enter the name of the product: ");
    scanf(" %[^\n]", targetName);

    while (inventory != NULL) {
        if (strcmp(inventory->name, targetName) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &inventory->stock);
            printf("Quantity updated successfully.\n");
            return;
        }
        inventory = inventory->next;
    }
    printf("Product not found.\n");
}

//Function to update the price of existing products
void updatePrice(Product *inventory) {
    char targetName[MAX_NAME_LENGTH + 1];
    printf("Enter the name of the product: ");
    scanf(" %[^\n]", targetName);

    while (inventory != NULL) {
        if (strcmp(inventory->name, targetName) == 0) {
            printf("Enter the new price: ");
            scanf("%f", &inventory->price);
            printf("Price updated successfully.\n");
            return;
        }
        inventory = inventory->next;
    }
    printf("Product not found.\n");
}

//Function to delete products from inventory
void deleteProduct(Product **inventory) {
    char targetName[MAX_NAME_LENGTH + 1];
    printf("Enter the name of the product to delete: ");
    scanf(" %[^\n]", targetName);

    Product *current = *inventory;
    Product *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, targetName) == 0) {
            if (prev == NULL) {
                *inventory = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Product deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Product not found.\n");
}

//Function to free memory allocated for inventory
void freeInventory(Product *inventory) {
    Product *temp;
    while (inventory != NULL) {
        temp = inventory;
        inventory = inventory->next;
        free(temp);
    }
}
