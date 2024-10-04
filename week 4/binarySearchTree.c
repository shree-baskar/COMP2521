#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
};

int bstNumNodes(struct node *t);
int bstCountOdds(struct node *t);
int bstCountInternal(struct node *t);
int bstHeight(struct node *t);
int bstNodeLevel(struct node *t, int key);
int bstCountGreater(struct node *t, int val);
struct node *bstInsert(struct node *t, int val);
struct node *newNode(int val);

int main(void) {
    struct node *tree = NULL;
    tree = bstInsert(tree, 5);
    tree = bstInsert(tree, 3);
    tree = bstInsert(tree, 8);
    tree = bstInsert(tree, 1);
    tree = bstInsert(tree, 4);
    tree = bstInsert(tree, 7);
    tree = bstInsert(tree, 9);

	printf("number of nodes: %d\n", bstNumNodes(tree));
    printf("number of odds: %d\n", bstCountOdds(tree));
    printf("height: %d\n", bstHeight(tree));
    printf("number of nodes greater than 5: %d\n", bstCountGreater(tree, 5));

    return 0;
}

/*
* Inserts a node into the binary search tree
*/
struct node *bstInsert(struct node *t, int val) {
    if (t == NULL) {
        return newNode(val);
    }

    if (t->val > val) {
        t->left = bstInsert(t->left, val);
    } else if (t->val < val) {
        t->right = bstInsert(t->right, val);
    }

    return t;
}

/*
* Creates a new node
*/
struct node *newNode(int val) {
    struct node *newN = malloc(sizeof(struct node));
    newN->val = val;
    newN->left = NULL;
    newN->right = NULL;
}

/*
* Counts the number of nodes in the tree
*/
int bstNumNodes(struct node *t) {
	if (t == NULL) {
		return 0;
	}

	int numNodeLeft = bstNumNodes(t->left);
	int numNodeRight = bstNumNodes(t->right);
    return numNodeLeft + numNodeRight + 1;
}

/*
* Counts the number of odd nodes in the tree
*/
int bstCountOdds(struct node *t) {
	if (t == NULL) {
		return 0;
	}

	int numOddsLeft = bstCountOdds(t->left);
	int numOddsRight = bstCountOdds(t->right);

	if (t->val % 2 == 0) {
		return numOddsLeft + numOddsRight;
	} else {
		return numOddsLeft + numOddsRight + 1;
	}
}

int bstCountInternal(struct node *t) {
    // TODO
    return 0;
}

/*
* Find the height of a tree
*/
int bstHeight(struct node *t) {
	if (t == NULL) {
		return -1;
	}

	int rightHeight = bstHeight(t->right);
	int leftHeight = bstHeight(t->left);

	int max = (rightHeight > leftHeight) ? rightHeight : leftHeight;

    return max + 1;
}

int bstNodeLevel(struct node *t, int key) {
    // TODO
    return 0;
}

/*
* Counts the number of nodes greater than a certain value
*/
int bstCountGreater(struct node *t, int val) {
	if (t == NULL) {
		return 0;
	}

	if (val > t->val) {
		return bstCountGreater(t->right, val);
	} else if (val < t->val) {
		return bstCountGreater(t->right, val) + bstCountGreater(t->left, val) + 1;
	} else if (val == t->val) {
		return bstCountGreater(t->right, val);
	}
}
