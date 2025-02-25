#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[256];
    char rarity[4];
    char type[10];
    int vocal;
    int dance;
    int visual;
    int mental;
} Card;

int parse_card(char **rest_p, Card *card) {
    char *p = *rest_p;
    while (isspace(*p)) p++;
    if (*p != '"') return 0;
    p++;
    char *name_start = p;
    while (*p && *p != '"') p++;
    if (*p != '"') return 0;
    size_t name_len = p - name_start;
    if (name_len >= sizeof(card->name)) return 0;
    strncpy(card->name, name_start, name_len);
    card->name[name_len] = '\0';
    p++;
    while (isspace(*p)) p++;
    if (sscanf(p, "%3s", card->rarity) != 1) return 0;
    p += strlen(card->rarity);
    while (isspace(*p)) p++;
    if (sscanf(p, "%9s", card->type) != 1) return 0;
    p += strlen(card->type);
    while (isspace(*p)) p++;
    if (sscanf(p, "%d %d %d %d", &card->vocal, &card->dance, &card->visual, &card->mental) != 4) return 0;
    while (isdigit(*p) || isspace(*p)) p++;
    while (isdigit(*p) || isspace(*p)) p++;
    while (isdigit(*p) || isspace(*p)) p++;
    while (isdigit(*p) || isspace(*p)) p++;
    *rest_p = p;
    return 1;
}

int main() {
    char domain[1000];
    if (!fgets(domain, sizeof(domain), stdin)) return 1;
    size_t len = strlen(domain);
    if (domain[len - 1] == '\n') domain[len - 1] = '\0';

    char line[5000];
    while (fgets(line, sizeof(line), stdin)) {
        len = strlen(line);
        if (line[len - 1] == '\n') line[len - 1] = '\0';

        char *url, *rest;
        url = line;
        rest = NULL;
        char *space_pos = strchr(line, ' ');
        if (space_pos) {
            *space_pos = '\0';
            rest = space_pos + 1;
        }

        // Validate URL
        if (strncmp(url, "https://", 8) != 0) {
            printf("Url error\n");
            continue;
        }
        char *p_hostname = url + 8;
        char *p_slash = strchr(p_hostname, '/');
        if (!p_slash) {
            printf("Url error\n");
            continue;
        }
        *p_slash = '\0';
        char *pathname = p_slash + 1;
        if (strcmp(p_hostname, domain) != 0 || strcmp(pathname, "produce") != 0) {
            printf("Url error\n");
            continue;
        }

        // Parse cards
        Card card1, card2;
        int card_count = 0;
        if (rest) {
            char *rest_p = rest;
            if (parse_card(&rest_p, &card1)) {
                card_count++;
                if (parse_card(&rest_p, &card2)) {
                    card_count++;
                }
            }
        }

        if (card_count != 2) {
            printf("Card type error\n");
            continue;
        }

        int produce_count = 0, support_count = 0;
        Card *produce_card = NULL, *support_card = NULL;
        if (strcmp(card1.type, "Produce") == 0) {
            produce_count++;
            produce_card = &card1;
        } else if (strcmp(card1.type, "Support") == 0) {
            support_count++;
            support_card = &card1;
        }
        if (strcmp(card2.type, "Produce") == 0) {
            produce_count++;
            produce_card = &card2;
        } else if (strcmp(card2.type, "Support") == 0) {
            support_count++;
            support_card = &card2;
        }

        if (produce_count != 1 || support_count != 1) {
            printf("Card type error\n");
            continue;
        }

        // Get rarity base number
        int rarity_base = 0;
        if (strcmp(support_card->rarity, "R") == 0) {
            rarity_base = 13;
        } else if (strcmp(support_card->rarity, "SR") == 0) {
            rarity_base = 113;
        } else if (strcmp(support_card->rarity, "SSR") == 0) {
            rarity_base = 1103;
        } else {
            printf("Card type error\n");
            continue;
        }

        // Apply support formula
        int vocal = produce_card->vocal + (int)(pow(produce_card->vocal, support_card->vocal) + 0.5) % rarity_base;
        int dance = produce_card->dance + (int)(pow(produce_card->dance, support_card->dance) + 0.5) % rarity_base;
        int visual = produce_card->visual + (int)(pow(produce_card->visual, support_card->visual) + 0.5) % rarity_base;
        int mental = produce_card->mental + (int)(pow(produce_card->mental, support_card->mental) + 0.5) % rarity_base;

        // Simulate 10 weeks
        int prev_activity = 0;
        for (int week = 0; week < 10; week++) {
            int max_min_ability = -1;
            int selected_activity = 0;
            for (int activity = 1; activity <= 5; activity++) {
                if (activity == prev_activity) continue;
                int v = vocal, d = dance, vi = visual, m = mental;
                if (activity == 1) {
                    v += 10;
                } else if (activity == 2) {
                    vi += 10;
                } else if (activity == 3) {
                    d += 10;
                } else if (activity == 4) {
                    m += 2;
                    v += 3;
                } else if (activity == 5) {
                    m += 2;
                    vi += 3;
                }
                int min_ability = v;
                if (d < min_ability) min_ability = d;
                if (vi < min_ability) min_ability = vi;
                if (m < min_ability) min_ability = m;
                if (min_ability > max_min_ability) {
                    max_min_ability = min_ability;
                    selected_activity = activity;
                }
            }
            // Update abilities
            if (selected_activity == 1) {
                vocal += 10;
            } else if (selected_activity == 2) {
                visual += 10;
            } else if (selected_activity == 3) {
                dance += 10;
            } else if (selected_activity == 4) {
                mental += 2;
                vocal += 3;
            } else if (selected_activity == 5) {
                mental += 2;
                visual += 3;
            }
            prev_activity = selected_activity;
        }

        printf("Vocal: %d\n", vocal);
        printf("Visual: %d\n", visual);
        printf("Dance: %d\n", dance);
        printf("Mental: %d\n", mental);
    }
    return 0;
}