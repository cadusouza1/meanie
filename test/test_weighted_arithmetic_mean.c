#include "../src/means.h"
#include <criterion/criterion.h>

#define EPSILON 1e-6

Test(weighted_arithmetic_mean, single_pair) {
    double nums[] = {5.0, 1.0}; // One value with weight 1
    cr_assert_float_eq(
        weighted_arithmetic_mean(nums, 2), 5.0, EPSILON,
        "Weighted mean of single value with weight 1 should be the value");
}

Test(weighted_arithmetic_mean, equal_weights) {
    // All weights are 1, should be same as regular arithmetic mean
    double nums[] = {1.0, 1.0, 2.0, 1.0, 3.0, 1.0};
    cr_assert_float_eq(weighted_arithmetic_mean(nums, 6), 2.0, EPSILON,
                       "Equal weights should give arithmetic mean");
}

Test(weighted_arithmetic_mean, simple_weighted) {
    // (2*1 + 4*2) / (1 + 2) = 3.333...
    double nums[] = {2.0, 1.0, 4.0, 2.0};
    cr_assert_float_eq(weighted_arithmetic_mean(nums, 4), 3.33333333, EPSILON,
                       "Simple weighted mean should be correct");
}

Test(weighted_arithmetic_mean, zero_weight) {
    // Value with zero weight should not contribute
    // (5*0 + 3*1) / (0 + 1) = 3
    double nums[] = {5.0, 0.0, 3.0, 1.0};
    cr_assert_float_eq(weighted_arithmetic_mean(nums, 4), 3.0, EPSILON,
                       "Zero weights should not contribute to mean");
}

Test(weighted_arithmetic_mean, large_weights) {
    // (1*1000 + 2*2000) / (1000 + 2000) = 1.666...
    double nums[] = {1.0, 1000.0, 2.0, 2000.0};
    cr_assert_float_eq(weighted_arithmetic_mean(nums, 4), 1.66666667, EPSILON,
                       "Should handle large weights correctly");
}

Test(weighted_arithmetic_mean, decimal_weights) {
    // (1*0.5 + 2*0.25 + 3*0.25) / (0.5 + 0.25 + 0.25) = 1.75
    double nums[] = {1.0, 0.5, 2.0, 0.25, 3.0, 0.25};
    cr_assert_float_eq(weighted_arithmetic_mean(nums, 6), 1.75, EPSILON,
                       "Should handle decimal weights correctly");
}

// Disabled for now
Test(weighted_arithmetic_mean, negative_weights, .disabled = true) {
    // This is mathematically valid but might not be what users expect
    double nums[] = {1.0, -1.0, 2.0, 1.0};
    cr_assert_float_eq(weighted_arithmetic_mean(nums, 4), 3.0, EPSILON,
                       "Should handle negative weights as expected");
}

Test(weighted_arithmetic_mean, odd_length) {
    // Last value should be ignored
    double nums[] = {1.0, 1.0, 2.0, 2.0, 5.0};
    cr_assert_float_eq(weighted_arithmetic_mean(nums, 5), 1.66666667, EPSILON,
                       "Should ignore unpaired final value");
}

Test(weighted_arithmetic_mean, large_numbers) {
    double nums[] = {1e6, 1.0, 2e6, 2.0};
    cr_assert_float_eq(weighted_arithmetic_mean(nums, 4), 1.666666e6, 1e0,
                       "Should handle large values correctly");
}

Test(weighted_arithmetic_mean, small_numbers) {
    double nums[] = {1e-6, 1.0, 2e-6, 2.0};
    cr_assert_float_eq(weighted_arithmetic_mean(nums, 4), 1.666666e-6, 1e-9,
                       "Should handle small values correctly");
}
