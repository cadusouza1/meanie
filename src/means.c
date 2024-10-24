#include <math.h>
#include <stdlib.h>

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
    qsort(nums, len, sizeof(double), &cmp_double);

    if (len % 2 == 1) {
        return nums[len / 2];
    }

    return (nums[len / 2] + nums[len / 2 - 1]) / 2;
}

/* double mode(double nums[], int len) { */
/*     qsort(nums, len, sizeof(double), &cmp_double); */

/*     return 0.0; */
/* } */
