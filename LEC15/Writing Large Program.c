#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Copilot Generated
#define NUM_PLAYERS 4
#define NUM_CARDS 5

typedef enum {
    CLUBS = 0,
    DIAMONDS,
    HEARTS,
    SPADES
} Suit;

typedef struct {
    int rank; // 2 to 14 (Ace high)
    Suit suit;
} Card;

typedef struct {
    Card cards[NUM_CARDS];
    char player; // 'A', 'B', 'C', 'D'
    int category; // 1 to 9 (best to worst)
    int tiebreaker_rank;
    int tiebreaker_suit;
} Hand;

int rank_char_to_value(char c) {
    if (c >= '2' && c <= '9') {
        return c - '0';
    } else if (c == 't') {
        return 10;
    } else if (c == 'j') {
        return 11;
    } else if (c == 'q') {
        return 12;
    } else if (c == 'k') {
        return 13;
    } else if (c == 'a') {
        return 14;
    }
    return -1;
}

Suit suit_char_to_value(char c) {
    if (c == 'c') {
        return CLUBS;
    } else if (c == 'd') {
        return DIAMONDS;
    } else if (c == 'h') {
        return HEARTS;
    } else if (c == 's') {
        return SPADES;
    }
    return -1;
}

int compare_cards(const void *a, const void *b) {
    const Card *cardA = (const Card *)a;
    const Card *cardB = (const Card *)b;
    if (cardA->rank != cardB->rank) {
        return cardA->rank - cardB->rank;
    } else {
        return cardA->suit - cardB->suit;
    }
}

void evaluate_hand(Hand *hand) {
    qsort(hand->cards, NUM_CARDS, sizeof(Card), compare_cards);

    int is_flush = 1;
    int is_straight = 1;

    Suit first_suit = hand->cards[0].suit;
    for (int i = 1; i < NUM_CARDS; i++) {
        if (hand->cards[i].suit != first_suit) {
            is_flush = 0;
            break;
        }
    }

    for (int i = 1; i < NUM_CARDS; i++) {
        if (hand->cards[i].rank != hand->cards[i - 1].rank + 1) {
            is_straight = 0;
            break;
        }
    }

    int ranks_count[15] = {0};
    for (int i = 0; i < NUM_CARDS; i++) {
        ranks_count[hand->cards[i].rank]++;
    }

    int pairs = 0;
    int three_of_a_kind = 0;
    int four_of_a_kind = 0;

    for (int i = 2; i <= 14; i++) {
        if (ranks_count[i] == 2) {
            pairs++;
        } else if (ranks_count[i] == 3) {
            three_of_a_kind = i;
        } else if (ranks_count[i] == 4) {
            four_of_a_kind = i;
        }
    }

    if (is_straight && is_flush) {
        hand->category = 1;
        hand->tiebreaker_rank = hand->cards[NUM_CARDS - 1].rank;
        hand->tiebreaker_suit = hand->cards[NUM_CARDS - 1].suit;
    } else if (four_of_a_kind) {
        hand->category = 2;
        hand->tiebreaker_rank = four_of_a_kind;
    } else if (three_of_a_kind && pairs == 1) {
        hand->category = 3;
        hand->tiebreaker_rank = three_of_a_kind;
    } else if (is_flush) {
        hand->category = 4;
        hand->tiebreaker_rank = hand->cards[NUM_CARDS - 1].rank;
        hand->tiebreaker_suit = hand->cards[NUM_CARDS - 1].suit;
    } else if (is_straight) {
        hand->category = 5;
        hand->tiebreaker_rank = hand->cards[NUM_CARDS - 1].rank;
        hand->tiebreaker_suit = hand->cards[NUM_CARDS - 1].suit;
    } else if (three_of_a_kind) {
        hand->category = 6;
        hand->tiebreaker_rank = three_of_a_kind;
    } else if (pairs == 2) {
        hand->category = 7;
        int high_pair_rank = 0;
        int high_pair_suit = 0;
        for (int i = 14; i >= 2; i--) {
            if (ranks_count[i] == 2) {
                high_pair_rank = i;
                for (int j = 0; j < NUM_CARDS; j++) {
                    if (hand->cards[j].rank == i && hand->cards[j].suit > high_pair_suit) {
                        high_pair_suit = hand->cards[j].suit;
                    }
                }
                break;
            }
        }
        hand->tiebreaker_rank = high_pair_rank;
        hand->tiebreaker_suit = high_pair_suit;
    } else if (pairs == 1) {
        hand->category = 8;
        int pair_rank = 0;
        int pair_suit = 0;
        for (int i = 14; i >= 2; i--) {
            if (ranks_count[i] == 2) {
                pair_rank = i;
                for (int j = 0; j < NUM_CARDS; j++) {
                    if (hand->cards[j].rank == i && hand->cards[j].suit > pair_suit) {
                        pair_suit = hand->cards[j].suit;
                    }
                }
                break;
            }
        }
        hand->tiebreaker_rank = pair_rank;
        hand->tiebreaker_suit = pair_suit;
    } else {
        hand->category = 9;
        hand->tiebreaker_rank = hand->cards[NUM_CARDS - 1].rank;
        hand->tiebreaker_suit = hand->cards[NUM_CARDS - 1].suit;
    }
}

int compare_hands(const void *a, const void *b) {
    const Hand *handA = (const Hand *)a;
    const Hand *handB = (const Hand *)b;

    if (handA->category != handB->category) {
        return handA->category - handB->category;
    } else {
        if (handA->tiebreaker_rank != handB->tiebreaker_rank) {
            return handB->tiebreaker_rank - handA->tiebreaker_rank;
        } else {
            return handB->tiebreaker_suit - handA->tiebreaker_suit;
        }
    }
}

int main() {
    Hand hands[NUM_PLAYERS];
    char line[100];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        fgets(line, sizeof(line), stdin);
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }
        hands[i].player = 'A' + i;
        hands[i].category = 9;
        hands[i].tiebreaker_rank = 0;
        hands[i].tiebreaker_suit = 0;
        int card_index = 0;
        char *ptr = strtok(line, " ");
        while (ptr != NULL && card_index < NUM_CARDS) {
            if (strlen(ptr) != 2) {
                fprintf(stderr, "Invalid card format: %s\n", ptr);
                return 1;
            }
            char rank_char = ptr[0];
            char suit_char = ptr[1];
            int rank = rank_char_to_value(rank_char);
            Suit suit = suit_char_to_value(suit_char);
            if (rank == -1 || suit == -1) {
                fprintf(stderr, "Invalid card: %s\n", ptr);
                return 1;
            }
            hands[i].cards[card_index].rank = rank;
            hands[i].cards[card_index].suit = suit;
            card_index++;
            ptr = strtok(NULL, " ");
        }
    }

    for (int i = 0; i < NUM_PLAYERS; i++) {
        evaluate_hand(&hands[i]);
    }

    qsort(hands, NUM_PLAYERS, sizeof(Hand), compare_hands);

    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%c ", hands[i].player);
    }
    printf("\n");

    return 0;
}


