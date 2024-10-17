#include <stdio.h>
#define int unsigned long long
signed main () {
    int d1, d2, d3;
    scanf("%llu%llu%llu", &d1, &d2, &d3);
    int ans = (d1 * 0x38E38E38E38E3800LLU) % 0x7CE66C50E2840000LLU;
    ans += (d2 * 0x2AAAAAAAAAAAAAAALLU) % 0x7CE66C50E2840000LLU;
    ans %= 0x7CE66C50E2840000LLU;
    ans += (d3 * 0x1C71C71C71C71C71LLU) % 0x7CE66C50E2840000LLU;
    ans %= 0x7CE66C50E2840000LLU;

    printf("%llu", ans);
    return 0;
}
