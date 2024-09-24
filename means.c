#include <math.h>

float arithmetic_mean(float nums[], int len) {
    float sum = 0;
    int i;

    for (i = 0; i < len; i++) {
        sum += nums[i] / len;
    }

    return sum;
}

float geometric_mean(float nums[], int len) {
    float prod = 1;
    int i;

    for (i = 0; i < len; i++) {
        prod *= pow(nums[i], 1.0 / len);
    }

    return prod;
}

float harmonic_mean(float nums[], int len) {
    float inverse_sum = 0;
    int i;

    for (i = 0; i < len; i++) {
        inverse_sum += 1 / nums[i];
    }

    return len / inverse_sum;
}

// The pairs are in the form {value1, weight1, value2, weight2, ...}.
// Last value will be ignored if there is no weight associated.
float weighted_arithmetic_mean(float nums_weight_pairs[], int len) {
    float weighted_sum = 0;
    float weight_sum = 0;
    int i;

    for (i = 0; i < len - 1; i += 2) {
        weighted_sum += nums_weight_pairs[i] * nums_weight_pairs[i + 1];
        weight_sum += nums_weight_pairs[i + 1];
    }

    return weighted_sum / weight_sum;
}
