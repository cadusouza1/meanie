#include <math.h>

float arithmetic_mean(float nums[], int len) {
    float sum = 0;
    int i;

    for (i = 0; i < len; i++) {
        sum += nums[i];
    }

    return sum / len;
}

float geometric_mean(float nums[], int len) {
    float prod = 1;
    int i;

    for (i = 0; i < len; i++) {
        prod *= nums[i];
    }

    return pow(prod, 1.0 / len);
}
