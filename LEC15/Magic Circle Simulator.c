#include <stdio.h>
#include <stdlib.h>

// Enumerations
enum orb_type {
    O_UNSET = -1,
    O_RED = 17, O_BLUE = 1, O_GREEN = 6, O_YELLOW = 24,
    O_FLOAT = 5, O_CLONE = 2, O_EXPAND = 4, O_DYSON = 3
};

// Structure Declarations
struct node_t {
    struct node_t *next;
    enum orb_type orb;
};

struct head_t {
    struct node_t *head;
    int count;
    enum orb_type orb;
};

// Function Prototypes
struct head_t *alloc_list_heads(int size);
void init_head_arr(struct head_t *arr, int size);
void print_magic_circle(struct head_t *arr, int size);
void insert_next(struct head_t *arr, int size, const char c);

// Main Function
int main() {
    int size, count;
    scanf("%d%d%*c", &size, &count);
    struct head_t *center_ring = alloc_list_heads(size);
    init_head_arr(center_ring, size);
    for (int i = 0; i < count; ++i) {
        insert_next(center_ring, size, getchar());
    }
    print_magic_circle(center_ring, size);
    return 0;
}

// Function Definitions
void print_magic_circle(struct head_t *arr, int size) {
    if (!arr) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        printf("CO_%c", arr[i].orb + 'A');
        struct node_t *cur = arr[i].head;
        while (cur) {
            printf(" -> %c", 'A' + cur->orb);
            cur = cur->next;
        }
        if (i + 1 < size) putchar('\n');
    }
    return;
}

enum orb_type char_to_orb_type(char c);
void append_orb(struct head_t *s, enum orb_type orb);
int has_floater(struct node_t *head);
void move_new_nodes_to_beginning(struct head_t *s);
void process_cloning(struct head_t *arr, int size, struct head_t *s, int stem_index);
void process_expand(struct head_t *arr, int size, struct head_t *s);
void process_dyson(struct head_t *arr, int size, struct head_t *s, int stem_index);
void free_stem(struct node_t *head);
struct node_t *clone_stem(struct node_t *head);

struct head_t *alloc_list_heads(int size) {
    return (struct head_t *)malloc(sizeof(struct head_t) * size);
}

void init_head_arr(struct head_t *arr, int size) {
    for (int i = 0; i < size; i++) {
        char c;
        scanf("%c", &c);
        arr[i].orb = char_to_orb_type(c);
        arr[i].head = NULL;
        arr[i].count = 0;
    }
    getchar();
}

enum orb_type char_to_orb_type(char c) {
    switch (c) {
        case 'R': return O_RED;
        case 'G': return O_GREEN;
        case 'B': return O_BLUE;
        case 'Y': return O_YELLOW;
        case 'F': return O_FLOAT;
        case 'C': return O_CLONE;
        case 'E': return O_EXPAND;
        case 'D': return O_DYSON;
        default: return O_UNSET;
    }
}

void append_orb(struct head_t *s, enum orb_type orb) {
    struct node_t *new_node = (struct node_t *)malloc(sizeof(struct node_t));
    new_node->orb = orb;
    new_node->next = NULL;
    if (s->head == NULL) {
        s->head = new_node;
    } else {
        struct node_t *curr = s->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

int has_floater(struct node_t *head) {
    struct node_t *curr = head;
    while (curr != NULL) {
        if (curr->orb == O_FLOAT) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void move_new_nodes_to_beginning(struct head_t *s) {
    struct node_t *floater = NULL, *prev = NULL, *curr = s->head;
    while (curr != NULL) {
        if (curr->orb == O_FLOAT) {
            floater = curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if (floater == NULL || floater->next == NULL) {
        return;
    }
    struct node_t *nodes_after_floater = floater->next;
    floater->next = NULL;
    struct node_t *last = nodes_after_floater;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = s->head;
    s->head = nodes_after_floater;
}

void free_stem(struct node_t *head) {
    struct node_t *curr = head;
    while (curr != NULL) {
        struct node_t *temp = curr;
        curr = curr->next;
        free(temp);
    }
}

struct node_t *clone_stem(struct node_t *head) {
    if (head == NULL) return NULL;
    struct node_t *new_head = NULL, *new_tail = NULL;
    struct node_t *curr = head;
    while (curr != NULL) {
        struct node_t *new_node = (struct node_t *)malloc(sizeof(struct node_t));
        new_node->orb = curr->orb;
        new_node->next = NULL;
        if (new_head == NULL) {
            new_head = new_tail = new_node;
        } else {
            new_tail->next = new_node;
            new_tail = new_node;
        }
        curr = curr->next;
    }
    return new_head;
}

void process_cloning(struct head_t *arr, int size, struct head_t *s, int stem_index) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        struct node_t *curr = arr[i].head;
        while (curr != NULL) {
            if (curr->orb == O_CLONE) {
                k++;
            }
            curr = curr->next;
        }
    }
    int target_index = (stem_index - k + size) % size;
    if (target_index != stem_index) {
        free_stem(arr[target_index].head);
        arr[target_index].head = clone_stem(s->head);
    }
}

void process_expand(struct head_t *arr, int size, struct head_t *s) {
    enum orb_type root_orb = s->orb;
    for (int i = 0; i < size; i++) {
        append_orb(&arr[i], root_orb);
        if (has_floater(arr[i].head)) {
            move_new_nodes_to_beginning(&arr[i]);
        }
    }
}

void process_dyson(struct head_t *arr, int size, struct head_t *s, int stem_index) {
    enum orb_type root_orb = s->orb;
    struct node_t *collected_orbs = NULL;
    struct node_t *collected_orbs_tail = NULL;
    for (int i = 0; i < size; i++) {
        if (i == stem_index) continue;
        if (arr[i].orb != root_orb) continue;
        struct node_t *prev = NULL, *curr = arr[i].head;
        while (curr != NULL) {
            struct node_t *next = curr->next;
            if (curr->orb == O_RED || curr->orb == O_BLUE || curr->orb == O_GREEN || curr->orb == O_YELLOW) {
                if (prev == NULL) {
                    arr[i].head = next;
                } else {
                    prev->next = next;
                }
                curr->next = NULL;
                if (collected_orbs == NULL) {
                    collected_orbs = collected_orbs_tail = curr;
                } else {
                    collected_orbs_tail->next = curr;
                    collected_orbs_tail = curr;
                }
                curr = next;
            } else {
                prev = curr;
                curr = next;
            }
        }
    }
    if (collected_orbs != NULL) {
        struct node_t *curr = s->head;
        while (curr != NULL) {
            if (curr->orb == O_DYSON) {
                break;
            }
            curr = curr->next;
        }
        if (curr == NULL) {
            curr = s->head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
        }
        struct node_t *after_dyson = curr->next;
        curr->next = collected_orbs;
        collected_orbs_tail->next = after_dyson;
    }
    if (has_floater(s->head)) {
        move_new_nodes_to_beginning(s);
    }
}

void insert_next(struct head_t *arr, int size, const char c) {
    static int stem_index = 0;
    enum orb_type orb = char_to_orb_type(c);
    struct head_t *s = &arr[stem_index];
    if (orb == O_FLOAT) {
        if (!has_floater(s->head)) {
            append_orb(s, orb);
        }
    } else {
        append_orb(s, orb);
        if (has_floater(s->head)) {
            move_new_nodes_to_beginning(s);
        }
        if (orb == O_CLONE) {
            process_cloning(arr, size, s, stem_index);
        } else if (orb == O_EXPAND) {
            process_expand(arr, size, s);
        } else if (orb == O_DYSON) {
            process_dyson(arr, size, s, stem_index);
        }
    }
    stem_index = (stem_index + 1) % size;
}
