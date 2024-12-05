#include <stdio.h>
#include <string.h>

#define MAX_BALLS 12
#define NAME_LENGTH 50
struct Player {
    int ballScores[MAX_BALLS];
    char playerName[NAME_LENGTH];
    int totalScore;
};
void playGame(struct Player *player) {
    printf("Enter the name of the player: ");
    scanf("%s", player->playerName);
    player->totalScore = 0;

    for (int i = 0; i < MAX_BALLS; i++) {
        int score;
        printf("Enter score for ball %d (0-6): ", i + 1);
        scanf("%d", &score);
        if (score >= 0 && score <= 6) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            player->ballScores[i] = 0; 
        }
    }
}
int validateScore(int score) {
    return (score >= 0 && score <= 6);
}
void findWinner(struct Player player1, struct Player player2) {
    if (player1.totalScore > player2.totalScore) {
        printf("%s wins with a score of %d!\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("%s wins with a score of %d!\n", player2.playerName, player2.totalScore);
    } else {
        printf("It's a tie with both scoring %d!\n", player1.totalScore);
    }
}
void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\nMatch Scoreboard:\n");
    printf("%s's Scores: ", player1.playerName);
    for (int i = 0; i < MAX_BALLS; i++) {
        printf("%d ", player1.ballScores[i]);
    }
    printf("\nTotal Score: %d, Average Score: %.2f\n", player1.totalScore, (float)player1.totalScore / MAX_BALLS);
    printf("%s's Scores: ", player2.playerName);
    for (int i = 0; i < MAX_BALLS; i++) {
        printf("%d ", player2.ballScores[i]);
    }
    printf("\nTotal Score: %d, Average Score: %.2f\n", player2.totalScore, (float)player2.totalScore / MAX_BALLS);
}
int main() {
    struct Player player1, player2;
    printf("Welcome to Cricket Showdown!\n");
    playGame(&player1);
    playGame(&player2);
    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);
    return 0;
}


