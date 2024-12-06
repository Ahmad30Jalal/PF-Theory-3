#include <stdio.h>
#include <string.h>

#define BALLS 12

// Structure for Player
typedef struct {
    int ball_scores[BALLS];
    char player_name[50];
    int total_score;
} Player;

// Function declarations
void play_game(Player *player);
int is_valid_score(int score);
void determine_winner(Player player1, Player player2);
void display_scoreboard(Player player1, Player player2);

int main() {
    Player player1 = {{0}, "", 0};
    Player player2 = {{0}, "", 0};

    printf("Enter Player 1's name: ");
    fgets(player1.player_name, sizeof(player1.player_name), stdin);
    player1.player_name[strcspn(player1.player_name, "\n")] = 0; // Remove newline

    printf("Enter Player 2's name: ");
    fgets(player2.player_name, sizeof(player2.player_name), stdin);
    player2.player_name[strcspn(player2.player_name, "\n")] = 0; // Remove newline

    // Play game for both players
    printf("\n--- %s's Turn ---\n", player1.player_name);
    play_game(&player1);

    printf("\n--- %s's Turn ---\n", player2.player_name);
    play_game(&player2);

    // Display scoreboard and determine winner
    printf("\n--- Match Scoreboard ---\n");
    display_scoreboard(player1, player2);

    determine_winner(player1, player2);

    return 0;
}

// Function to play the game for a player
void play_game(Player *player) {
    for (int i = 0; i < BALLS; i++) {
        int score;
        printf("Enter score for ball %d: ", i + 1);
        scanf("%d", &score);

        if (is_valid_score(score)) {
            player->ball_scores[i] = score;
            player->total_score += score;
        } else {
            printf("Invalid score! Marking ball %d as 0.\n", i + 1);
            player->ball_scores[i] = 0;
        }
    }
}

// Function to check if the score is valid
int is_valid_score(int score) {
    return score >= 0 && score <= 6;
}

// Function to determine the winner
void determine_winner(Player player1, Player player2) {
    if (player1.total_score > player2.total_score) {
        printf("\nWinner: %s with %d runs!\n", player1.player_name, player1.total_score);
    } else if (player2.total_score > player1.total_score) {
        printf("\nWinner: %s with %d runs!\n", player2.player_name, player2.total_score);
    } else {
        printf("\nIt's a tie! Both players scored %d runs.\n", player1.total_score);
    }
}

// Function to display the scoreboard
void display_scoreboard(Player player1, Player player2) {
    Player players[2] = {player1, player2};

    for (int i = 0; i < 2; i++) {
        Player player = players[i];
        printf("\n%s's Performance:\n", player.player_name);
        printf("Ball Scores: ");
        for (int j = 0; j < BALLS; j++) {
            printf("%d ", player.ball_scores[j]);
        }
        double average = player.total_score / (double)BALLS;
        printf("\nTotal Score: %d", player.total_score);
        printf("\nAverage Score: %.2f\n", average);
    }
}
