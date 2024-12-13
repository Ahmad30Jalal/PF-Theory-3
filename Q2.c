#include <stdio.h>

typedef struct {
    int score[12];
    char name[30];
    int total;
} Player;

Player Play(Player p) {
    for (int i = 0; i < 12; i++) {
        printf("%s (ball %d score): ", p.name, i + 1);
        scanf("%d", &p.score[i]);
        if (p.score[i] < 0 || p.score[i] > 6) {
            printf("Invalid score.Ball missed\n");
            
        }
    }
    return p;
}

void winner(Player p1, Player p2) {
    p1.total = 0;
    p2.total = 0;

    for (int i = 0; i < 12; i++) {
        p1.total += p1.score[i];
        p2.total += p2.score[i];
    }

    printf("\nFinal Scores:\n");
    printf("%s Total: %d\n", p1.name, p1.total);
    printf("%s Total: %d\n", p2.name, p2.total);

    if (p1.total > p2.total) {
        printf("%s is the winner!\n", p1.name);
    } else if (p2.total > p1.total) {
        printf("%s is the winner!\n", p2.name);
    } else {
        printf("It's a tie!\n");
    }
}

void display(Player p1, Player p2) {
    printf("\nEach Ball's Scores:\n");
    for (int i = 0; i < 12; i++) {
        printf("Ball %d:\n", i + 1);
        printf("  %s Score: %d\n", p1.name, p1.score[i]);
        printf("  %s Score: %d\n", p2.name, p2.score[i]);
    }
}

int main() {
    Player p1, p2;

    printf("Enter Player 1 Name: ");
    scanf("%s", p1.name);
    printf("Enter Player 2 Name: ");
    scanf("%s", p2.name);

    p1 = Play(p1);
    p2 = Play(p2);

    // Display the winner
    winner(p1, p2);

    display(p1, p2);

    return 0;
}
