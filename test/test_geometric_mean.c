#include "../src/means.h"
#include <criterion/criterion.h>

#define EPSILON 1e-6

Test(geometric_mean, single_number) {
    double nums[] = {5.0};
    cr_assert_float_eq(
        geometric_mean(nums, 1), 5.0, EPSILON,
        "Geometric mean of single number should be the number itself");
}

Test(geometric_mean, same_numbers) {
    double nums[] = {2.0, 2.0, 2.0, 2.0};
    cr_assert_float_eq(
        geometric_mean(nums, 4), 2.0, EPSILON,
        "Geometric mean of identical numbers should be that number");
}

Test(geometric_mean, simple_case) {
    double nums[] = {1.0, 4.0};
    cr_assert_float_eq(geometric_mean(nums, 2), 2.0, EPSILON,
                       "Geometric mean of 1 and 4 should be 2");
}

Test(geometric_mean, positive_integers) {
    double nums[] = {2.0, 8.0, 32.0};
    cr_assert_float_eq(geometric_mean(nums, 3), 8.0, EPSILON,
                       "Geometric mean of 2,8,32 should be 8");
}

Test(geometric_mean, decimal_numbers) {
    double nums[] = {0.5, 2.0, 8.0};
    cr_assert_float_eq(geometric_mean(nums, 3), 2.0, EPSILON,
                       "Geometric mean of 0.5,2,8 should be 2");
}

Test(geometric_mean, ones) {
    double nums[] = {1.0, 1.0, 1.0, 1.0};
    cr_assert_float_eq(geometric_mean(nums, 4), 1.0, EPSILON,
                       "Geometric mean of ones should be one");
}

Test(geometric_mean, large_numbers) {
    double nums[] = {1e3, 1e4, 1e5};
    double expected = 1e4; // (1000 * 10000 * 100000)^(1/3)
    cr_assert_float_eq(geometric_mean(nums, 3), expected, 0.1,
                       "Geometric mean should handle large numbers");
}

Test(geometric_mean, small_numbers) {
    double nums[] = {1e-3, 1e-4, 1e-5};
    double expected = 1e-4; // (0.001 * EPSILON * 0.00001)^(1/3)
    cr_assert_float_eq(geometric_mean(nums, 3), expected, 1e-5,
                       "Geometric mean should handle small numbers");
}

Test(geometric_mean, zero_in_array) {
    double nums[] = {1.0, 0.0, 2.0};
    cr_assert_float_eq(geometric_mean(nums, 3), 0.0, EPSILON,
                       "Geometric mean with zero should be zero");
}

/* Test for more numerically stable implementation */
Test(geometric_mean, precision_test) {
    double nums[] = {1e-100, 1e100};
    double expected = 1.0; // sqrt(1e-100 * 1e100) = 1
    cr_assert_float_eq(geometric_mean(nums, 2), expected, EPSILON,
                       "Geometric mean should handle extreme values stably");
}

Test(geometric_mean, large_dataset) {
    // Testing with 1000 numbers, all 2.0
    double nums[1000];
    for (int i = 0; i < 1000; i++) {
        nums[i] = 2.0;
    }
    cr_assert_float_eq(geometric_mean(nums, 1000), 2.0, 0.0001,
                       "Geometric mean of 1000 twos should be 2");
}
