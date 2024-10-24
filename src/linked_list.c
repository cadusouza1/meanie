#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    double data;
    struct _node *next;
} Node;

Node *node_new(double data) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
        fprintf(stderr, "Couldn't allocate memory for node with data %f\n",
                data);
        return NULL;
    }

    n->data = data;
    n->next = NULL;
    return n;
}
