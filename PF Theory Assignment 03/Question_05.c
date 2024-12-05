#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPECIES 10
#define MAX_SUPPLIES 20
char*** speciesSupplies;
int speciesCount = 0;
void initializeInventory(int count) {
    speciesCount = count;
    speciesSupplies = malloc(speciesCount * sizeof(char**));
    for (int i = 0; i < speciesCount; i++) {
        speciesSupplies[i] = malloc(MAX_SUPPLIES * sizeof(char*));
        for (int j = 0; j < MAX_SUPPLIES; j++) {
            speciesSupplies[i][j] = NULL;
        }
    }
}
void addSupplies(int speciesIndex, char* supply) {
    for (int j = 0; j < MAX_SUPPLIES; j++) {
        if (speciesSupplies[speciesIndex][j] == NULL) {
            speciesSupplies[speciesIndex][j] = malloc((strlen(supply) + 1) * sizeof(char));
            strcpy(speciesSupplies[speciesIndex][j], supply);
            break;
        }
    }
}
void updateSupplies(int speciesIndex, int supplyIndex, char* newSupply) {
    if (speciesSupplies[speciesIndex][supplyIndex] != NULL) {
        free(speciesSupplies[speciesIndex][supplyIndex]);
        speciesSupplies[speciesIndex][supplyIndex] = malloc((strlen(newSupply) + 1) * sizeof(char));
        strcpy(speciesSupplies[speciesIndex][supplyIndex], newSupply);
    }
}
void removeSpecies(int speciesIndex) {
    for (int j = 0; j < MAX_SUPPLIES; j++) {
        if (speciesSupplies[speciesIndex][j] != NULL) {
            free(speciesSupplies[speciesIndex][j]);
        }
    }
    free(speciesSupplies[speciesIndex]);
    for (int i = speciesIndex; i < speciesCount - 1; i++) {
        speciesSupplies[i] = speciesSupplies[i + 1];
    }
    speciesCount--;
}
void displayInventory() {
    for (int i = 0; i < speciesCount; i++) {
        printf("Species %d Supplies:\n", i + 1);
        for (int j = 0; j < MAX_SUPPLIES; j++) {
            if (speciesSupplies[i][j] != NULL) {
                printf(" - %s\n", speciesSupplies[i][j]);
            }
        }
    }
}
int main() {
    initializeInventory(3);
    addSupplies(0, "Food");
    addSupplies(0, "Leash");
    addSupplies(1, "Toys");
    displayInventory();
    updateSupplies(0, 0, "Dog Food");
    displayInventory();
    removeSpecies(1);
    displayInventory();
    for (int i = 0; i < speciesCount; i++) {
        for (int j = 0; j < MAX_SUPPLIES; j++) {
            if (speciesSupplies[i][j] != NULL) {
                free(speciesSupplies[i][j]);
            }
        }
        free(speciesSupplies[i]);
    }
    free(speciesSupplies);
    return 0;
}

