#include <criterion/criterion.h>

#include "../src/means.h"

#define EPSILON 1e-6

Test(arithmetic_mean, single_number) {
    double nums[] = {5.0};
    cr_assert_float_eq(
        arithmetic_mean(nums, 1), 5.0, EPSILON,
        "Arithmetic mean of single number should be the number itself");
}

Test(arithmetic_mean, positive_integers) {
    double nums[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    cr_assert_float_eq(arithmetic_mean(nums, 5), 3.0, EPSILON,
                       "Arithmetic mean of 1,2,3,4,5 should be 3.0");
}

Test(arithmetic_mean, negative_numbers) {
    double nums[] = {-1.0, -2.0, -3.0, -4.0, -5.0};
    cr_assert_float_eq(arithmetic_mean(nums, 5), -3.0, EPSILON,
                       "Arithmetic mean of -1,-2,-3,-4,-5 should be -3.0");
}

Test(arithmetic_mean, mixed_numbers) {
    double nums[] = {-2.0, 0.0, 2.0};
    cr_assert_float_eq(arithmetic_mean(nums, 3), 0.0, EPSILON,
                       "Arithmetic mean of -2,0,2 should be 0.0");
}

Test(arithmetic_mean, decimal_numbers) {
    double nums[] = {1.5, 2.5, 3.5};
    cr_assert_float_eq(arithmetic_mean(nums, 3), 2.5, EPSILON,
                       "Arithmetic mean of 1.5,2.5,3.5 should be 2.5");
}

Test(arithmetic_mean, large_numbers) {
    double nums[] = {1e6, 2e6, 3e6};
    cr_assert_float_eq(
        arithmetic_mean(nums, 3), 2e6, EPSILON,
        "Arithmetic mean of large numbers should be calculated correctly");
}

Test(arithmetic_mean, small_numbers) {
    double nums[] = {1e-6, 2e-6, 3e-6};
    cr_assert_float_eq(
        arithmetic_mean(nums, 3), 2e-6, EPSILON,
        "Arithmetic mean of small numbers should be calculated correctly");
}

Test(arithmetic_mean, zero_array) {
    double nums[] = {0.0, 0.0, 0.0};
    cr_assert_float_eq(arithmetic_mean(nums, 3), 0.0, EPSILON,
                       "Arithmetic mean of zeros should be zero");
}
