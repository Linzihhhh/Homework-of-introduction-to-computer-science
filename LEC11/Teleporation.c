#include <stdio.h>

unsigned long long  construct(unsigned char parts[16]);

int main()
{
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%llu", construct(parts));

    return 0;
}

unsigned long long construct(unsigned char parts[16])
{
	unsigned long long temp1 = 0;
    unsigned long long temp2 = 0;
    //printf("%u\n", parts[0]);
    for(int i = 0; i < 8; i++)
    {
        //printf("%x\n", parts[i]);
        temp1 = temp1 | (unsigned long long)parts[i] << (8 * i);
        temp2 = temp2 | (unsigned long long)parts[i + 8] << (8 * i);
    }
    unsigned long long ans = temp1 ^ temp2;
    return ans;
}


