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
