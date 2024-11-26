#include <stdio.h>
#include <stdlib.h>

struct Car {
    int passenger;
    int flammable;
    struct Car *next;
};

void attachCar(struct Car *head, int passenger, int flammable) {
    struct Car *curr = head;
    while(curr->next) curr = curr->next;             // Find the end of the train

    struct Car *newcar = malloc(sizeof(struct Car)); // Make a new car
    newcar->passenger = passenger;                   // Let passengers in
    newcar->flammable = flammable;                   // Load flammable items
    newcar->next = NULL;                             // This is the last car

    curr->next = newcar;                             // Attach new car to the train
}

int fire(struct Car *head);

int main(int argc, char *argv[])
{
    int cars;
    int human[13], moeru[13];

    struct Car head;
    head.next = NULL; // passenger & flammable for head in useless

    scanf("%d", &cars);
    for (int i = 0; i < cars; ++i) {
        scanf("%d", &human[i]);
    }
    for (int i = 0; i < cars; ++i) {
        scanf("%d", &moeru[i]);
    }

    for (int i = 0; i < cars; ++i) {
        attachCar(&head, human[i], moeru[i]);
    }

    printf("%d", fire(&head)); // The train is on fire now

    return 0;
}
int fire(struct Car *head) {
	struct Car* temp = head;
    if(temp->next) temp = temp->next;
    int cnt = 0;
    while(temp->next!=NULL)
    {
        //printf("%d %d %d\n", temp->passenger, temp->flammable, cnt);
        if((temp->passenger) >= (temp->flammable)) break;
        else
        {
            cnt++;
            (temp->next)->passenger += (temp->passenger);
            temp = temp->next;
        }
    }
    if(temp->passenger < temp->flammable) cnt++;
    return cnt;
}

