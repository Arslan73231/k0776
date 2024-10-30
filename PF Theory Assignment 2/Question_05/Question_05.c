#include <stdio.h>

int main() {
    int n, max = 0;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Input value %d: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }

    printf("\nHorizontal Histogram:\n");
    for (int i = 0; i < n; i++) {
        printf("Data Point %d: ", i + 1);
        for (int j = 0; j < arr[i]; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\nVertical Histogram:\n");
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] >= max - i) printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
    printf("\n");


    printf("Values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
