#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void populateArray(char array[6][5]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            array[i][j] = 'A' + (rand() % 26);
        }
    }
    array[5][0] = '0';
    array[5][1] = '5';
    array[5][2] = '6';
    array[5][3] = '0';
}

void displayArray(char array[6][5]) {
    printf("\nCharacter Array:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

int findString(char array[6][5], const char *searchString) {
    int length = strlen(searchString);
    
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 5 - length; j++) {
            if (strncmp(&array[i][j], searchString, length) == 0) {
                return 1; 
            }
        }
    }

    
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i <= 6 - length; i++) {
            int found = 1;
            for (int k = 0; k < length; k++) {
                if (array[i + k][j] != searchString[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return 1; 
            }
        }
    }

    return 0; 
}

int main() {
    char charArray[6][5];
    char userInput[100];
    int score = 0;

    srand(time(NULL)); 

    while (1) {
        populateArray(charArray);
        displayArray(charArray);

        while (1) {
            printf("Enter a string to search (or type 'END' to repopulate): ");
            scanf("%s", userInput);

            if (strcmp(userInput, "END") == 0) {
                break; 
            }

            if (findString(charArray, userInput)) {
                score++; 
                printf("%s is present. Current Score: %d\n", userInput, score);
            } else {
                score--; 
                printf("%s is not present. Current Score: %d\n", userInput, score);
            }
        }
    }

    return 0;
}
