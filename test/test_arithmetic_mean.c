#include <criterion/criterion.h>

#include "../src/means.h"

Test(arithmetic_mean_tests, dummy) {
    double nums[] = {1, 1};
    double mean = arithmetic_mean(nums, 2);

    cr_expect(mean == 1, "Arithmetic mean of 1 and 1 should be 1");
}
