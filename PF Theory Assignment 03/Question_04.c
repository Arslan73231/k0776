#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* scores;
    int totalPoints;
} TeamMember;

void collectScores(int** scores, int totalMembers, int totalPeriods) {
    for (int i = 0; i < totalMembers; i++) {
        for (int j = 0; j < totalPeriods; j++) {
            do {
                printf("Enter score for Team Member %d, Phase %d (1-10): ", i + 1, j + 1);
                scanf("%d", &scores[i][j]);
            } while (scores[i][j] < 1 || scores[i][j] > 10);
        }
    }
}

void displayScores(int** scores, int totalMembers, int totalPeriods) {
    for (int i = 0; i < totalMembers; i++) {
        printf("Team Member %d Scores: ", i + 1);
        for (int j = 0; j < totalPeriods; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
}

int topPerformer(int** scores, int totalMembers, int totalPeriods) {
    int bestMember = 0;
    float highestAvg = 0.0;
    for (int i = 0; i < totalMembers; i++) {
        float sum = 0.0;
        for (int j = 0; j < totalPeriods; j++) {
            sum += scores[i][j];
        }
        float avg = sum / totalPeriods;
        if (avg > highestAvg) {
            highestAvg = avg;
            bestMember = i;
        }
    }
    return bestMember;
}

int bestPhase(int** scores, int totalMembers, int totalPeriods) {
    int topPhase = 0;
    float maxAvg = 0.0;
    for (int j = 0; j < totalPeriods; j++) {
        float sum = 0.0;
        for (int i = 0; i < totalMembers; i++) {
            sum += scores[i][j];
        }
        float avg = sum / totalMembers;
        if (avg > maxAvg) {
            maxAvg = avg;
            topPhase = j;
        }
    }
    return topPhase;
}

int leastPerformer(int** scores, int totalMembers, int totalPeriods) {
    int worstMember = 0;
    float lowestAvg = 10.0;
    for (int i = 0; i < totalMembers; i++) {
        float sum = 0.0;
        for (int j = 0; j < totalPeriods; j++) {
            sum += scores[i][j];
        }
        float avg = sum / totalPeriods;
        if (avg < lowestAvg) {
            lowestAvg = avg;
            worstMember = i;
        }
    }
    return worstMember;
}

int main() {
    int totalMembers = 3;
    int totalPeriods = 4;
    int** scores = (int**)malloc(totalMembers * sizeof(int*));
    for (int i = 0; i < totalMembers; i++) {
        scores[i] = (int*)malloc(totalPeriods * sizeof(int));
    }

    collectScores(scores, totalMembers, totalPeriods);
    displayScores(scores, totalMembers, totalPeriods);

    int bestMember = topPerformer(scores, totalMembers, totalPeriods);
    printf("Top Performer: Team Member %d\n", bestMember + 1);

    int topPhase = bestPhase(scores, totalMembers, totalPeriods);
    printf("Best Phase: Phase %d\n", topPhase + 1);

    int worstMember = leastPerformer(scores, totalMembers, totalPeriods);
    printf("Least Performing Team Member: Team Member %d\n", worstMember + 1);

    for (int i = 0; i < totalMembers; i++) {
        free(scores[i]);
    }
    free(scores);
    return 0;
}
