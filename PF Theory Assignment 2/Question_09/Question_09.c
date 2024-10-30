#include <stdio.h>

void moveVertical(char map[][5], int*, int*, int*, int*);
void moveHorizontal(char map[][5], int*, int*, int*, int*);
void displayMap(char map[5][5]);

int main() {
  
    char map[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    printf("Welcome to the Grid Adventure Game!\n\n");
    printf("Use the following keys to navigate:\nW: Up\nS: Down\nA: Left\nD: Right\nQ: Quit\n\n");
    printf("Let's begin!\n");

    int playerRow = 4, playerCol = 4, collectedItems = 0;
    char moveCommand;

    while (moveCommand != 'Q') {
        int nextPosition = 0;
        displayMap(map);
        printf("\nEnter your move: ");
        scanf(" %c", &moveCommand);

        if (moveCommand == 'W') {
            nextPosition = playerRow - 1;
            moveVertical(map, &playerCol, &playerRow, &nextPosition, &collectedItems);
        } 
        else if (moveCommand == 'S') {
            nextPosition = playerRow + 1;
            moveVertical(map, &playerCol, &playerRow, &nextPosition, &collectedItems);
        } 
        else if (moveCommand == 'A') {
            nextPosition = playerCol - 1;
            moveHorizontal(map, &playerRow, &playerCol, &nextPosition, &collectedItems);
        } 
        else if (moveCommand == 'D') {
            nextPosition = playerCol + 1;
            moveHorizontal(map, &playerRow, &playerCol, &nextPosition, &collectedItems);
        } 
        else if (moveCommand == 'Q') {
            printf("\nThe game has ended.\n");
            printf("Total collected items: %d\n", collectedItems);
            return 0;
        } 
        else {
            printf("Invalid input, please try again.\n");
        }
    }
}

void displayMap(char map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("|'%c'", map[i][j]);
        }
        printf("|\n");
    }
}

void moveVertical(char map[][5], int *col, int *row, int *newRow, int *items) {
    if (*newRow >= 0 && *newRow < 5) {
        if (map[*newRow][*col] == ' ' || map[*newRow][*col] == 'I') {
            if (map[*newRow][*col] == 'I') (*items)++;
            map[*row][*col] = ' ';
            map[*newRow][*col] = 'P';
            *row = *newRow;
        }
    } else {
        printf("Invalid move.\n");
    }
}

void moveHorizontal(char map[][5], int *row, int *col, int *newCol, int *items) {
    if (*newCol >= 0 && *newCol < 5) {
        if (map[*row][*newCol] == ' ' || map[*row][*newCol] == 'I') {
            if (map[*row][*newCol] == 'I') (*items)++;
            map[*row][*col] = ' ';
            map[*row][*newCol] = 'P';
            *col = *newCol;
        }
    } else {
        printf("Invalid move.\n");
    }
}
