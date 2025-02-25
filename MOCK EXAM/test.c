#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15


void recovering_order(char *order, char **result);

char names[GOODS_SIZE][MAX_NAME_LEN] = {
    "aluminum", "ammunition", "orange", "aspirin", "ax",
    "basketball", "zipper", "bell", "blanket", "drum",
    "canvas", "flute", "eraser", "mirror", "comb",
    "eggplant", "diamond", "zucchini", "door", "butter",
    "egg", "dart", "chair", "encyclopedia", "china",
    "fan", "glue", "elevator", "flower", "hat",
    "garlic", "strawberry", "glove", "flour", "ice",
    "ship", "hammer", "fur", "key", "honey",
    "grape", "icecream", "lock", "iron", "ivory",
    "jacket", "oil", "uniform", "kiwi", "pan",
    "helmet", "keyboard", "yoyo", "jet", "knife",
    "tie", "lemon", "xerox", "ink", "mutton",
    "newspaper", "melon", "coconut", "motorcycle", "longan",
    "nail", "rice", "magnet", "peanut", "ointment",
    "oar", "jeans", "nut", "arrow", "oven",
    "jewel", "wool", "noodle", "pencil", "lamp",
    "refrigerator", "needle", "roast", "vest", "yarn",
    "saw", "hamburger", "soap", "glass", "wine",
    "tangerine", "pillow", "umbrella", "zinc", "train",
    "uglifruit", "toast", "underwear", "vanilla", "jeep",
    "unicycle", "vase", "rope", "violin", "warship",
    "volleyball", "water", "yogurt", "submarine", "passionfruit",
    "yacht", "rose", "window", "yolk", "kite",
    "liquor", "xylophone", "toothbrush", "battery", "doll"
};

int main(void) {
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}

void recovering_order(char *order, char **result) {
    char *tokens[MAX_ORDER_SIZE];
    int count = 0;
    char *token = strtok(order, ":");
    while (token != NULL && count < MAX_ORDER_SIZE) {
        tokens[count++] = token;
        token = strtok(NULL, ":");
    }


    char *res = (char *)malloc(500 * sizeof(char));
    res[0] = '\0';

    for(int i = 0; i < count; i++) {
        char *search = tokens[i];
        int best_pos = 1e9;
        int best_len = 1e9;
        char best_name[MAX_NAME_LEN] = "";

        for(int j = 0; j < GOODS_SIZE; j++) {
            char *found = strstr(names[j], search);
            if(found) {
                int pos = found - names[j];
                if(pos < best_pos ||
                   (pos == best_pos && strlen(names[j]) < best_len) ||
                   (pos == best_pos && strlen(names[j]) == best_len && strcmp(names[j], best_name) < 0)) {
                    best_pos = pos;
                    best_len = strlen(names[j]);
                    strcpy(best_name, names[j]);
                }
            }
        }

        if(i > 0) {
            strcat(res, "+");
        }
        strcat(res, best_name);
    }

    *result = res;
}