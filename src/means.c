#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEANS_SIZE 5

typedef double (*MeanFunc)(double nums[], int len);

double arithmetic_mean(double nums[], int len) {
    double sum = 0;
    int i;

    for (i = 0; i < len; i++) {
        sum += nums[i] / len;
    }

    return sum;
}

double geometric_mean(double nums[], int len) {
    double prod = 1;
    int i;

    for (i = 0; i < len; i++) {
        prod *= pow(nums[i], 1.0 / len);
    }

    return prod;
}

double harmonic_mean(double nums[], int len) {
    double inverse_sum = 0;
    int i;

    for (i = 0; i < len; i++) {
        inverse_sum += 1 / nums[i];
    }

    return len / inverse_sum;
}

/* The pairs are in the form {value1, weight1, value2, weight2, ...}.
Last value will be ignored if there is no weight associated. */
double weighted_arithmetic_mean(double nums_weight_pairs[], int len) {
    double weighted_sum = 0;
    double weight_sum = 0;
    int i;

    for (i = 0; i < len - 1; i += 2) {
        weighted_sum += nums_weight_pairs[i] * nums_weight_pairs[i + 1];
        weight_sum += nums_weight_pairs[i + 1];
    }

    return weighted_sum / weight_sum;
}

int cmp_double(const void *f1, const void *f2) {
    return *(double *)f1 >= *(double *)f2;
}

double median(double nums[], int len) {
    /* Since I don't want to change the original array, I need to create a copy
    of it */
    double *copy = malloc(len * sizeof(double));
    double result;

    if (copy == NULL) {
        fprintf(stderr, "Couldn't allocate memory for median calculation\n");
        return 0.0;
    }

    memcpy(copy, nums, len * sizeof(double));
    qsort(copy, len, sizeof(double), &cmp_double);

    if (len % 2 == 1) {
        result = copy[len / 2];
    } else {
        result = (copy[len / 2] + copy[len / 2 - 1]) / 2;
    }

    free(copy);

    return result;
}

/* double mode(double nums[], int len) { */
/*     qsort(nums, len, sizeof(double), &cmp_double); */

/*     return 0.0; */
/* } */
