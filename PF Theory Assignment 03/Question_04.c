#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* ratings;
    int totalScore;
} Employee;
void inputEmployees(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        for (int j = 0; j < numPeriods; j++) {
            do {
                printf("Enter rating for Employee %d, Period %d (1-10): ", i + 1, j + 1);
                scanf("%d", &ratings[i][j]);
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}
void displayPerformance(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d Ratings: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}
int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods) {
    int bestEmployee = 0;
    float highestAverage = 0.0;
    for (int i = 0; i < numEmployees; i++) {
        float total = 0.0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        float average = total / numPeriods;
        if (average > highestAverage) {
            highestAverage = average;
            bestEmployee = i;
        }
    }
    return bestEmployee;
}
int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) {
    int bestPeriod = 0;
    float highestAverage = 0.0;
    for (int j = 0; j < numPeriods; j++) {
        float total = 0.0;
        for (int i = 0; i < numEmployees; i++) {
            total += ratings[i][j];
        }
        float average = total / numEmployees;
        if (average > highestAverage) {
            highestAverage = average;
            bestPeriod = j;
        }
    }
    return bestPeriod;
}
int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods) {
    int worstEmployee = 0;
    float lowestAverage = 10.0;
    for (int i = 0; i < numEmployees; i++) {
        float total = 0.0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        float average = total / numPeriods;
        if (average < lowestAverage) {
            lowestAverage = average;
            worstEmployee = i;
        }
    }
    return worstEmployee;
}
int main() {
    int numEmployees = 3;
    int numPeriods = 4;
    int** ratings = (int**)malloc(numEmployees * sizeof(int*));
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
    }
    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);
    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("Employee of the Year: Employee %d\n", employeeOfTheYear + 1);
    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Period: Period %d\n", highestRatedPeriod + 1);
    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee + 1);
    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);
    return 0;
}
