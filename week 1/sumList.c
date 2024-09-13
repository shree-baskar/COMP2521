#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};


// using a while loop
int sumList(struct node *list) {
    struct node *curr = list;
    int sum = 0;

    while (curr != NULL) {
        sum += curr->value;
        curr = curr->next;
    }

    return sum;
}


// using a for loop
int sumList(struct node *list) {
    int sum = 0;

    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        sum += curr->value;
    }

    return sum;
}
