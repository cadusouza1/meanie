#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_double(const void *f1, const void *f2) {
    return *(double *)f1 >= *(double *)f2;
}

// Same as qsort, but for an array of doubles and returns a copy
double *qsort_double_array(double nums[], int len) {
    double *copy = malloc(len * sizeof(double));

    if (copy == NULL) {
        fprintf(stderr, "Couldn't allocate memory for sorting operation\n");
        return NULL;
    }

    memcpy(copy, nums, len * sizeof(double));
    qsort(copy, len, sizeof(double), &cmp_double);

    return copy;
}
