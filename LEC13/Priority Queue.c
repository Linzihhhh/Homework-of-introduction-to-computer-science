#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int weight;
	int value;
	struct node_s *next;
} node_t;

typedef struct prio_queue_s {
	node_t *head;
} prio_queue_t;

void enqueue(prio_queue_t * const queue, int value, int weight);
node_t *dequeue(prio_queue_t * const queue);
void print_nodes(const prio_queue_t * const queue);

int main() {
	int N;
	scanf("%d", &N);
	prio_queue_t queue = {
		.head = NULL,
	};
	for (int i = 0; i < N; i++) {
		char op[8];
		scanf("%s", op);
		if (!strcmp(op, "ENQUEUE")) {
			int v, w;
			scanf("%d%d", &v, &w);
			enqueue(&queue, v, w);
		}
		else if (!strcmp(op, "DEQUEUE")) {
			free(dequeue(&queue));
        }
		print_nodes(&queue);
	}
	return 0;
}

void print_nodes(const prio_queue_t *const queue) {
	if (!queue->head) {
		printf("EMPTY\n");
		return;
	}
	for (node_t *node = queue->head; node; node = node->next) {
		printf(" -> %d", node->value);
    }
	printf("\n");
    return;
}
void enqueue(prio_queue_t *const queue, int value, int weight) {
    if(!queue->head)
    {
        node_t* newNode = malloc(sizeof(node_t));
        newNode->value = value;
        newNode->weight = weight;
        newNode ->next = NULL;
        queue->head = newNode;
        //printf("here1\n");
        return;
    }
    if(weight < queue->head->weight)
    {
        node_t* newNode= malloc(sizeof(node_t));\
        node_t* new = queue->head;
        newNode->next = new;
        queue->head = newNode;
        newNode->weight = weight;
        newNode->value = value;
        
        return;
    }
    for (node_t *node = queue->head, *temp = NULL; node; temp = node,node = node->next) 
    {
		if(node->weight <= weight) continue;
        else
        {
            node_t* newNode= malloc(sizeof(node_t));\
            if(temp)temp->next = newNode;
            newNode->next = node;
            newNode->value = value;
            newNode->weight = weight;
            //printf("here2 %d\n", node->weight);
            return;
        }
    }
    node_t *node = queue->head;
    while(node->next)
    {
        node = node->next;
        //printf("x");
    }
    node_t* newNode= malloc(sizeof(node_t));\
    node->next = newNode;
    newNode->next = NULL;
    newNode->value = value;
    newNode->weight = weight;
    //printf("here3\n");
    return;
}

node_t *dequeue(prio_queue_t *const queue) {

    node_t * node = queue->head;
    if(node) queue->head = node->next;
    return node;
}