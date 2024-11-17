#include <stdio.h>
#include <stdlib.h>

struct ESPer {
    char name[64];
    int level;
};

int cmp(const void *a, const void *b);
void sort_level(struct ESPer *arr, int length);

int main()
{
    int n;
    struct ESPer tokiwadai[100];

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
    }

    sort_level(tokiwadai, n);

    for(int i = 0;i < n;++i) {
        printf("%d %s\n", tokiwadai[i].level, tokiwadai[i].name);
    }

    return 0;
}
int cmp(const void *a, const void *b) {
	if(((struct ESPer *)a) -> level > ((struct ESPer *)b) -> level) {
        return 1;
    }
    else if(((struct ESPer *)a) -> level < ((struct ESPer *)b) -> level) {
        return -1;
    }
    else {
        return 0;
    }
}

void sort_level(struct ESPer *arr, int length) {
    qsort(arr, length, sizeof(struct ESPer), cmp);
}
