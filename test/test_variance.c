#include <criterion/criterion.h>

#include "../src/means.h"

#define EPSILON 1e-6

Test(variance, simple_sequence) {
    double nums[] = {1, 2, 3, 4, 5};

    cr_assert_float_eq(
        variance(nums, 5), 2.5, EPSILON,
        "Simple variance of dataset {1, 2, 3, 4, 5} should be 2.5");
}
