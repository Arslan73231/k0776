#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_STORAGE 20
char*** categoryItems;
int categoryCount = 0;

void initializeStorage(int count) {
    categoryCount = count;
    categoryItems = malloc(categoryCount * sizeof(char**));
    for (int i = 0; i < categoryCount; i++) {
        categoryItems[i] = malloc(MAX_STORAGE * sizeof(char*));
        for (int j = 0; j < MAX_STORAGE; j++) {
            categoryItems[i][j] = NULL;
        }
    }
}

void addItem(int categoryIndex, char* item) {
    for (int j = 0; j < MAX_STORAGE; j++) {
        if (categoryItems[categoryIndex][j] == NULL) {
            categoryItems[categoryIndex][j] = malloc((strlen(item) + 1) * sizeof(char));
            strcpy(categoryItems[categoryIndex][j], item);
            break;
        }
    }
}

void modifyItem(int categoryIndex, int itemIndex, char* updatedItem) {
    if (categoryItems[categoryIndex][itemIndex] != NULL) {
        free(categoryItems[categoryIndex][itemIndex]);
        categoryItems[categoryIndex][itemIndex] = malloc((strlen(updatedItem) + 1) * sizeof(char));
        strcpy(categoryItems[categoryIndex][itemIndex], updatedItem);
    }
}

void deleteCategory(int categoryIndex) {
    for (int j = 0; j < MAX_STORAGE; j++) {
        if (categoryItems[categoryIndex][j] != NULL) {
            free(categoryItems[categoryIndex][j]);
        }
    }
    free(categoryItems[categoryIndex]);
    for (int i = categoryIndex; i < categoryCount - 1; i++) {
        categoryItems[i] = categoryItems[i + 1];
    }
    categoryCount--;
}

void displayStorage() {
    for (int i = 0; i < categoryCount; i++) {
        printf("Category %d Contents:\n", i + 1);
        for (int j = 0; j < MAX_STORAGE; j++) {
            if (categoryItems[i][j] != NULL) {
                printf(" --> %s\n", categoryItems[i][j]);
            }
        }
    }
}

int main() {
    initializeStorage(3);
    addItem(0, "Dry Food");
    addItem(0, "Collar");
    addItem(1, "Play Items");
    displayStorage();

    modifyItem(0, 0, "Special Dog Food");
    displayStorage();

    deleteCategory(1);
    displayStorage();

    for (int i = 0; i < categoryCount; i++) {
        for (int j = 0; j < MAX_STORAGE; j++) {
            if (categoryItems[i][j] != NULL) {
                free(categoryItems[i][j]);
            }
        }
        free(categoryItems[i]);
    }
    free(categoryItems);
    return 0;
}
