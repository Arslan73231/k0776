// Name  : Arslan Rashid
// Roll no : 24k - 0776
// Instructor : Sir Farooque

#include <stdio.h>
#include <limits.h>

int main() {
    int smallest = INT_MAX; 
    int second_smallest = INT_MAX;
    int numbers[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 5; i++) {
        if (smallest > numbers[i]) { 
            second_smallest = smallest;
            smallest = numbers[i];
        } else if (smallest < numbers[i] && second_smallest > numbers[i]) {
            second_smallest = numbers[i];
        }
    }

    if (second_smallest == INT_MAX) {
        printf("No second smallest element found.\n");
    } else {
        printf("Second smallest element in the array is: %d", second_smallest);
    }

    return 0;
}
