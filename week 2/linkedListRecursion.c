#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

void listDelete(struct list *l, int value);
struct node *listDeleteRec(struct node *l, int value);
bool listIsSorted(struct list *l);
bool listIsSortedRec(struct node *l);
int listCountOdds(struct list *l);
int listCountOddsRec(struct node *l);
int listLength(struct list *l);
int listLengthRec(struct node *l);
struct node *newNode(int value);
void listPrepend(struct list *l, struct node *n);
void printList(struct node *l);

int main(void) {
    struct list *l = malloc(sizeof(struct list));
    l->head = NULL;
    printf("Enter list values (values are inserted to the head of the list): ");
    int val;
    while (scanf("%d", &val) != -1) {
        struct node *n = newNode(val);
        listPrepend(l, n);
    }

    printf("Here is our list: ");
    printList(l->head);
    printf("List length v1: %d\n", listLengthRec(l->head));
    printf("List length v2: %d\n", listLength(l));
    printf("List count odds v1: %d\n", listCountOddsRec(l->head));
    printf("List count odds v2: %d\n", listCountOdds(l));
    printf("List is sorted v1: %d\n", listIsSortedRec(l->head));
    printf("List is sorted v2: %d\n", listIsSorted(l));

    printf("Here is our list before deleting node 3: ");
    printList(l->head);
    listDelete(l, 3);
    printf("Here is our list after deleting node 3: ");
    printList(l->head);
}

void printList(struct node *l) {
    struct node *curr = l;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

void listPrepend(struct list *l, struct node *n) {
    n->next = l->head;
    l->head = n;
}

struct node *newNode(int value) {
    struct node *newN = malloc(sizeof(struct node));
    newN->value = value;
    newN->next = NULL;
    return newN;
}

int listLengthRec(struct node *l) {
    // Base case: when the list is empty
    if (l == NULL) {
        return 0;
    }

    // Recursive step:
    return 1 + listLengthRec(l->next);
}

int listLength(struct list *l) {
    return listLengthRec(l->head);
}

int listCountOddsRec(struct node *l) {
    // Base case:
    if (l == NULL) {
        return 0;
    }

    // Recursive case:
    if (l->value % 2 == 0) {
        return listCountOddsRec(l->next);
    } else {
        return 1 + listCountOddsRec(l->next);
    }

}

int listCountOdds(struct list *l) {
    return listCountOddsRec(l->head);
}

bool listIsSortedRec(struct node *l) {
    if (l == NULL) {
        return true;
    }

    if (l->next == NULL) {
        return true;
    }

    if (l->value > l->next->value) {
        return false;
    }

    return listIsSortedRec(l->next);
    return true;
}

bool listIsSorted(struct list *l) {
    return listIsSortedRec(l->head);
}

struct node *listDeleteRec(struct node *l, int value) {
    if (l == NULL) {
        return NULL;
    }

    if (l->value == value) {
        struct node *temp = l->next;
        free(l);
        return temp;
    } else {
        l->next = listDeleteRec(l->next, value);
        return l;
    }
}

void listDelete(struct list *l, int value) {
    l->head = listDeleteRec(l->head, value);
}
