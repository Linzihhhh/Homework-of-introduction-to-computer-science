#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

void recovering_order(char *, char **);
void test_compare();
void recovering_order2(char *, char **);
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
    //while(1) test_compare();
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}

void recovering_order(char *order, char **result) {
    const char *delim = ":";
    char *acronym = strtok(order, delim);
    int l = 0;
    //char *trueans = (char *)malloc(500 * sizeof(char));
    char trueans[500] = "";
    while(acronym != NULL)
    {
        int pos = 0;
        int minlength = 1e9;
        int flag = 0;
        char * ans;
        while(!flag)
        {
            char *best_ans;
            for(int i = 0 ; i <= GOODS_SIZE -1 ; i++)
            {
                char temp[1000] ="";
                int p = pos;
                int t = 0;
                for(p; strlen(temp) < strlen(acronym); p++)
                {
                    if(strlen(names[i]) <= p)
                    {
                        break;
                    }
                    temp[t] = names[i][p];
                    t++;
                }
                if(strcmp(temp, acronym) == 0)
                {
                    if(strlen(names[i]) < minlength)
                    {
                        minlength = strlen(names[i]);
                        flag = 1;
                        ans = names[i];
                        best_ans = names[i];
                    }
                    else if(strlen(names[i]) == minlength)
                    {
                        for(int j = 0 ; j < strlen(names[i]) ; j++)
                        {
                            if(names[i][j] < best_ans[j])
                            {
                                ans = names[i];
                                best_ans = names[i];
                                break;
                            }
                            else if(names[i][j] > best_ans[j])
                            {
                                break;
                            }
                        }
                    }
                }
            }
            pos ++;
        }
        //printf("%s", ans);
  
        for(int i = 0 ; i < strlen(ans) ; i++)
        {
            *(trueans + l) = ans[i];
            l++;
            
        }
        *(trueans + l) = '+';
        l++;
        
        acronym = strtok(NULL, delim);
        
    }
    trueans[l-1] = '\0';
    printf("%s", trueans);
    exit(0);
    return;
}
/*void recovering_order2(char *order, char **result) {
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
}*/


/*void test_compare() {
    srand(time(NULL));
    int index = rand() % GOODS_SIZE;
    int name_len = strlen(names[index]);
    if(name_len == 0) {
        printf("Selected name is empty.\n");
        return;
    }
    // Generate a random substring
    int start = rand() % name_len;
    int length = (rand() % (name_len - start)) + 1;
    char substring[MAX_NAME_LEN] = "";
    strncpy(substring, names[index] + start, length);
    substring[length] = '\0';
    
    printf("Testing substring: %s\n", substring);
    
    char *result1 = NULL;
    recovering_order(substring, &result1);
    
    char *result2 = NULL;
    recovering_order2(substring, &result2);
    
    
    
    if(strcmp(result1, result2) == 0){
        //printf("Both functions produce the same result.\n");
    } else {
        printf("recovering_order: %s\n", result1);
        printf("recovering_order2: %s\n", result2);
        printf("Results differ.\n");
    }
    
    free(result1);
    free(result2);
}
*/