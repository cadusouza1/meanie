#include <criterion/criterion.h>

#include "../src/means.h"

#define EPSILON 1e-6

Test(quartiles, simple_odd_len_sequence) {
    double nums[] = {1, 2, 3, 4, 5};
    int len = sizeof(nums) / sizeof(*nums);

    double q1 = quartile1(nums, len);
    double q2 = quartile2(nums, len);
    double q3 = quartile3(nums, len);
    double iq_range = iqr(nums, len);

    cr_assert_float_eq(q1, 1.5, EPSILON, "quartile1 = %f. Should be 1.5", q1);
    cr_assert_float_eq(q2, 3, EPSILON, "quartile2 = %f. Should be 3", q2);
    cr_assert_float_eq(q3, 4.5, EPSILON, "quartile3 = %f. Should be 4.5", q3);
    cr_assert_float_eq(iq_range, 3, EPSILON, "iqr = %f. Should be 3", iq_range);
}

Test(quartiles, simple_even_len_sequence) {
    double nums[] = {1, 2, 3, 4};
    int len = sizeof(nums) / sizeof(*nums);

    double q1 = quartile1(nums, len);
    double q2 = quartile2(nums, len);
    double q3 = quartile3(nums, len);
    double iq_range = iqr(nums, len);

    cr_assert_float_eq(q1, 1.5, EPSILON, "quartile1 = %f. Should be 1.5", q1);
    cr_assert_float_eq(q2, 2.5, EPSILON, "quartile2 = %f. Should be 2.5", q2);
    cr_assert_float_eq(q3, 3.5, EPSILON, "quartile3 = %f. Should be 3.5", q3);
    cr_assert_float_eq(iq_range, 2, EPSILON, "iqr = %f. Should be 2", iq_range);
}

Test(quartiles, long_odd_len_sequence) {
    double nums[] = {
        1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15,  16,  17,
        18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,  33,  34,
        35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,  50,  51,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,  67,  68,
        69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,  84,  85,
        86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101,
    };

    int len = sizeof(nums) / sizeof(*nums);

    double q1 = quartile1(nums, len);
    double q2 = quartile2(nums, len);
    double q3 = quartile3(nums, len);
    double iq_range = iqr(nums, len);

    cr_assert_float_eq(q1, 25.5, EPSILON, "quartile1 = %f. Should be 25.5", q1);
    cr_assert_float_eq(q2, 51, EPSILON, "quartile2 = %f. Should be 51", q2);
    cr_assert_float_eq(q3, 76.5, EPSILON, "quartile3 = %f. Should be 76.5", q3);
    cr_assert_float_eq(iq_range, 51, EPSILON, "iqr = %f. Should be 51",
                       iq_range);
}

Test(quartiles, long_even_len_sequence) {
    double nums[] = {
        1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15,  16, 17,
        18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,  33, 34,
        35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,  50, 51,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,  67, 68,
        69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,  84, 85,
        86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
    };

    int len = sizeof(nums) / sizeof(*nums);

    double q1 = quartile1(nums, len);
    double q2 = quartile2(nums, len);
    double q3 = quartile3(nums, len);
    double iq_range = iqr(nums, len);

    cr_assert_float_eq(q1, 25.5, EPSILON, "quartile1 = %f. Should be 25.5", q1);
    cr_assert_float_eq(q2, 50.5, EPSILON, "quartile2 = %f. Should be 50.5", q2);
    cr_assert_float_eq(q3, 75.5, EPSILON, "quartile3 = %f. Should be 75.5", q3);
    cr_assert_float_eq(iq_range, 50, EPSILON, "iqr = %f. Should be 50",
                       iq_range);
}
