#include "../src/means.h"
#include <criterion/criterion.h>

Test(median, single_number) {
    double nums[] = {5.0};
    cr_assert_float_eq(median(nums, 1), 5.0, 0.0001,
                       "Median of single number should be the number itself");
}

Test(median, odd_count_ordered) {
    double nums[] = {1.0, 2.0, 3.0};
    cr_assert_float_eq(
        median(nums, 3), 2.0, 0.0001,
        "Median of ordered odd-count array should be middle number");
}

Test(median, odd_count_unordered) {
    double nums[] = {3.0, 1.0, 2.0};
    cr_assert_float_eq(median(nums, 3), 2.0, 0.0001,
                       "Median of unordered odd-count array should be middle "
                       "number after sorting");
}

Test(median, even_count_ordered) {
    double nums[] = {1.0, 2.0, 3.0, 4.0};
    cr_assert_float_eq(median(nums, 4), 2.5, 0.0001,
                       "Median of ordered even-count array should be average "
                       "of middle numbers");
}

Test(median, even_count_unordered) {
    double nums[] = {4.0, 1.0, 3.0, 2.0};
    cr_assert_float_eq(median(nums, 4), 2.5, 0.0001,
                       "Median of unordered even-count array should be average "
                       "of middle numbers");
}

Test(median, repeated_values) {
    double nums[] = {1.0, 2.0, 2.0, 3.0, 2.0};
    cr_assert_float_eq(median(nums, 5), 2.0, 0.0001,
                       "Median should handle repeated values correctly");
}

Test(median, all_same_values) {
    double nums[] = {2.0, 2.0, 2.0, 2.0};
    cr_assert_float_eq(median(nums, 4), 2.0, 0.0001,
                       "Median of identical values should be that value");
}

Test(median, decimal_numbers) {
    double nums[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    cr_assert_float_eq(median(nums, 5), 3.5, 0.0001,
                       "Median should handle decimal numbers correctly");
}

Test(median, large_numbers) {
    double nums[] = {1e6, 2e6, 3e6};
    cr_assert_float_eq(median(nums, 3), 2e6, 1e3,
                       "Median should handle large numbers correctly");
}

Test(median, small_numbers) {
    double nums[] = {1e-6, 2e-6, 3e-6};
    cr_assert_float_eq(median(nums, 3), 2e-6, 1e-9,
                       "Median should handle small numbers correctly");
}

Test(median, negative_numbers) {
    double nums[] = {-3.0, -1.0, -2.0};
    cr_assert_float_eq(median(nums, 3), -2.0, 0.0001,
                       "Median should handle negative numbers correctly");
}

Test(median, mixed_numbers) {
    double nums[] = {-2.0, 0.0, 1.0, -1.0, 2.0};
    cr_assert_float_eq(
        median(nums, 5), 0.0, 0.0001,
        "Median should handle mixed positive and negative numbers");
}

/* Test that original array is modified (this might be important to document) */
Test(median, modifies_input) {
    double nums[] = {3.0, 1.0, 2.0};
    median(nums, 3);
    cr_assert_float_neq(nums[0], 1.0, 0.0001,
                        "Function should not sort the input array");
    cr_assert_float_neq(nums[1], 2.0, 0.0001,
                        "Function should not sort the input array");
    cr_assert_float_neq(nums[2], 3.0, 0.0001,
                        "Function should not sort the input array");
}
