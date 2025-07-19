#include <criterion/criterion.h>

#include "../src/means.h"

#define EPSILON 1e-6

Test(standard_deviation, simple_sequence) {
    double nums[] = {1, 2, 3, 4, 5};
    double std_dev = standard_deviation(nums, 5);

    cr_assert_float_eq(
        std_dev, 1.581138, EPSILON,
        "Simple standard deviation of dataset {1, 2, 3, 4, 5} should be approx 1.581138, it's %f", std_dev
    );
}
