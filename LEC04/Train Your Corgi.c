#include <stdio.h>

typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

int main()
{
    char ch;
    int cnt = 0;
    Strength iS = INIT_STRENGTH;
    Obedience iO = INIT_OBEDIENCE;

    while ((ch = getchar()) != '\n')
    {
        if (ch == 'e')
        {
            iS += STRENGTH_EAT;
            iO -= OBEDIENCE_EAT;
        }
        else if (ch == 't')
        {
            iS -= STRENGTH_TRAIN;
            iO += OBEDIENCE_TRAIN;
            if (iO >= LEARN_OBEDIENCE && iS <= LEARN_STRENGTH)
            {
                cnt++;
                iO = INIT_OBEDIENCE;
            }
        }
    }

    if (cnt >= 5)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
