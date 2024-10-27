#include "../src/means.h"
#include <criterion/criterion.h>

#define EPSILON 1e-6

Test(harmonic_mean, single_number) {
    double nums[] = {5.0};
    cr_assert_float_eq(
        harmonic_mean(nums, 1), 5.0, EPSILON,
        "Harmonic mean of single number should be the number itself");
}

Test(harmonic_mean, same_numbers) {
    double nums[] = {3.0, 3.0, 3.0};
    cr_assert_float_eq(
        harmonic_mean(nums, 3), 3.0, EPSILON,
        "Harmonic mean of identical numbers should be that number");
}

Test(harmonic_mean, simple_case) {
    double nums[] = {2.0, 6.0}; // H = 2/(1/2 + 1/6) = 3
    cr_assert_float_eq(harmonic_mean(nums, 2), 3.0, EPSILON,
                       "Harmonic mean of 2 and 6 should be 3");
}

Test(harmonic_mean, reciprocal_numbers) {
    double nums[] = {0.5, 2.0}; // H = 2/(2 + 0.5) = 0.8
    cr_assert_float_eq(harmonic_mean(nums, 2), 0.8, EPSILON,
                       "Harmonic mean of reciprocal numbers should be correct");
}

Test(harmonic_mean, larger_set) {
    // H = 5/(1/1 + 1/2 + 1/3 + 1/4 + 1/5) ≈ 2.19
    double nums[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    cr_assert_float_eq(harmonic_mean(nums, 5), 2.189781, EPSILON,
                       "Harmonic mean of sequence 1-5 should be correct");
}

Test(harmonic_mean, decimal_numbers) {
    double nums[] = {0.5, 0.25, 0.125};
    cr_assert_float_eq(harmonic_mean(nums, 3), 0.214286, EPSILON,
                       "Harmonic mean of decimal numbers should be correct");
}

Test(harmonic_mean, large_numbers) {
    double nums[] = {1e6, 2e6, 4e6};
    double expected = 1.714285714e6; // 3/(1/1e6 + 1/2e6 + 1/4e6)
    cr_assert_float_eq(harmonic_mean(nums, 3), expected, 1,
                       "Harmonic mean should handle large numbers");
}

Test(harmonic_mean, small_numbers) {
    double nums[] = {1e-6, 2e-6, 4e-6};
    double expected = 1.714285714e-6; // Same as large numbers but scaled
    cr_assert_float_eq(harmonic_mean(nums, 3), expected, EPSILON,
                       "Harmonic mean should handle small numbers");
}

Test(harmonic_mean, very_different_magnitudes) {
    double nums[] = {1e-6, 1.0, 1e6};
    // This case is particularly interesting for numerical stability
    cr_assert_float_eq(harmonic_mean(nums, 3), 2.99999e-6, EPSILON,
                       "Harmonic mean should handle mixed magnitudes");
}
