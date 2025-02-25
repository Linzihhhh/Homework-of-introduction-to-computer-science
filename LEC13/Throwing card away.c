#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Node* top = (struct Node*)malloc(sizeof(struct Node));
    struct Node* pre = top;
    for(int i = 0; i <= n-1; i++)
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = i+1;
        pre->next = temp;
        temp->next = NULL;
        pre = temp;
    }
    while(m--)
    {
        printf("%d ", top->next->data);
        struct Node* throw = top->next;
        struct Node* putDown = top->next->next;
        
        free(throw);
        struct Node* go = putDown;
        if(m!= 0)
        {
            while(go->next != NULL) go = go->next;
            go->next = putDown;
            top->next = putDown->next;
            putDown->next = NULL;
        } 
    }
    
}
