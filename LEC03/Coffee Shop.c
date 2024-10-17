#include <stdio.h>
#define AMERICANO  110
#define LATTE      150
#define CAPPUCCINO 135
#define MOCHA      145

int main() {
	int i, j;
    scanf("%d %d", &i, &j);
    int price = 0;
    switch(i)
    {   default: 
        	price = -1;
            break;
        case 1: 
            price = AMERICANO * j;
            break;
        case 2: 
            price = LATTE * j;
            break;
        case 3: 
            price = CAPPUCCINO * j;
            break;
        case 4: 
            price = MOCHA * j;
            break;
        
    }
    if(price == -1)
    {
        printf("Wait, what?");
    }
    else printf("The total price is %d dollars!", price);
    return 0;
}