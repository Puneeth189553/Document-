#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// Function to shuffle an array
void shuffle(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to display the Bingo grid
void displayGrid(int grid[SIZE][SIZE], int marked[SIZE][SIZE]) {
    printf("_________________________________\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (marked[i][j]) {
                printf("|  #  "); // Marked number
            } else {
                printf("| %2d  ", grid[i][j]); // Unmarked number
            }
        }
        printf("|\n");
        printf("_________________________________\n");
    }
}

// Function to check if a row is completed
int checkRow(int marked[SIZE][SIZE], int row) {
    for (int j = 0; j < SIZE; j++) {
        if (!marked[row][j])
            return 0;
    }
    return 1;
}

// Function to check if a column is completed
int checkColumn(int marked[SIZE][SIZE], int col) {
    for (int i = 0; i < SIZE; i++) {
        if (!marked[i][col])
            return 0;
    }
    return 1;
}

// Check the main diagonal (top-left to bottom-right)
int checkMainDiagonal(int marked[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!marked[i][i])
            return 0;
    }
    return 1;
}

// Check the anti-diagonal (top-right to bottom-left)
int checkAntiDiagonal(int marked[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!marked[i][SIZE - i - 1])
            return 0;
    }
    return 1;
}

// Function to check for Bingo progress
void checkBingo(int marked[SIZE][SIZE], int *bingoCount) {
    int newBingo = 0;
    
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (checkRow(marked, i))
            newBingo++;
    }
    
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (checkColumn(marked, j))
            newBingo++;
    }
    
    // Check diagonals
    if (checkMainDiagonal(marked))
        newBingo++;
    if (checkAntiDiagonal(marked))
        newBingo++;
    
    // Ensure Bingo count does not exceed 5
    if (newBingo > 5) {
        newBingo = 5;
    }

    // Update only if there's progress
    *bingoCount = newBingo;
}

// Function to display "BINGO" progress
void displayBingo(int bingoCount) {
    printf("\nBINGO Progress: ");
    for (int i = 0; i < bingoCount; i++) {
        printf("%c ", "BINGO"[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));

    int numbers[SIZE * SIZE];
    int grid[SIZE][SIZE];
    int marked[SIZE][SIZE] = {0};  // 0 = unmarked, 1 = marked
    int bingoCount = 0;

    // Fill array with numbers 1 to 25
    for (int i = 0; i < SIZE * SIZE; i++) {
        numbers[i] = i + 1;
    }

    // Shuffle the numbers
    shuffle(numbers, SIZE * SIZE);

    // Fill the 5x5 grid with shuffled numbers
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = numbers[index++];
        }
    }

    // Game loop: mark numbers until Bingo (5 letters) is reached
    int choice;
    while (bingoCount < 5) {
        displayGrid(grid, marked);
        displayBingo(bingoCount);

        // Input choice
        printf("Enter a number to mark (1-25), or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting...\n");
            break;
        }

        // Find the chosen number and mark it if not already marked
        int found = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (grid[i][j] == choice && !marked[i][j]) {
                    marked[i][j] = 1;  // Mark it
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }

        if (!found) {
            printf("Number already marked or invalid. Try again.\n");
        } else {
            // Check for updated Bingo progress
            checkBingo(marked, &bingoCount);
        }
    }

    displayGrid(grid, marked);
    displayBingo(bingoCount);
    printf("\nBINGO! Game Over!\n");
    return 0;
}
    