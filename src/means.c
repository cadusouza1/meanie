#include "sort.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MEANS_SIZE 11

typedef double (*MeanFunc)(double nums[], int len);

double arithmetic_mean(double nums[], int len) {
    double sum = 0;

    for (int i = 0; i < len; i++) {
        sum += nums[i];
    }

    return sum / len;
}

double geometric_mean(double nums[], int len) {
    double prod = 1;

    for (int i = 0; i < len; i++) {
        prod *= nums[i];
    }

    return pow(prod, 1.0 / len);
}

double harmonic_mean(double nums[], int len) {
    double inverse_sum = 0;

    for (int i = 0; i < len; i++) {
        inverse_sum += 1 / nums[i];
    }

    return len / inverse_sum;
}

/* The pairs are in the form {value1, weight1, value2, weight2, ...}.
Last value will be ignored if there is no weight associated. */
double weighted_arithmetic_mean(double nums_weight_pairs[], int len) {
    double weighted_sum = 0;
    double weight_sum = 0;

    for (int i = 0; i < len - 1; i += 2) {
        weighted_sum += nums_weight_pairs[i] * nums_weight_pairs[i + 1];
        weight_sum += nums_weight_pairs[i + 1];
    }

    return weighted_sum / weight_sum;
}

double median(double nums[], int len) {
    double result;
    double *copy = qsort_double_array(nums, len);

    if (copy == NULL) {
        return 0;
    }

    if (len % 2 == 1) {
        result = copy[len / 2];
    } else {
        result = (copy[len / 2] + copy[len / 2 - 1]) / 2;
    }

    free(copy);

    return result;
}

double variance(double nums[], int len) {
    double avg = arithmetic_mean(nums, len);
    double v = 0;

    for (int i = 0; i < len; i++) {
        v += pow(nums[i] - avg, 2);
    }

    return v / (len - 1);
}

double standard_deviation(double nums[], int len) {
    return sqrt(variance(nums, len));
}

double quartile1(double nums[], int len) { return median(nums, len / 2); }

double quartile2(double nums[], int len) { return median(nums, len); }

double quartile3(double nums[], int len) {
    if (len % 2 == 0) {
        return median(nums + (len / 2), len / 2);
    }

    return median(nums + (len / 2 + 1), len / 2);
}

double iqr(double nums[], int len) {
    return quartile3(nums, len) - quartile1(nums, len);
}
