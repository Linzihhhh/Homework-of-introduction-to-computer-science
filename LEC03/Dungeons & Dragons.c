#include <stdio.h>


int main() {
    int dice[6];
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &dice[i]);
    }

    int sum_d1_d2_d3 = dice[0] + dice[1] + dice[2];
    int player_turn = (sum_d1_d2_d3 <= 10);

    const char* attacker = player_turn ? "Player" : "Dragon";
    const char* hit;

    if (player_turn) {
        if (dice[3] == dice[4] && dice[4] == dice[5]) {
            hit = "Critical Hit";
        } else if (dice[3] + dice[4] >= dice[5]) {
            hit = "Normal Hit";
        } else {
            hit = "Miss";
        }
    } else {
        if (dice[3] == dice[4] || dice[4] == dice[5] || dice[3] == dice[5]) {
            hit = "Miss";
        } else if (dice[3] + dice[4] != dice[5]) {
            hit = "Normal Hit";
        } else {
            hit = "Critical Hit";
        }
    }

    printf("%s attacks: %s\n", attacker, hit);
    return 0;
}
