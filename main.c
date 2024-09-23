#include "means.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_LEN 1024
#define NUMS_MAX_LEN 1024

int main(int argc, char *argv[]) {
    char line[LINE_MAX_LEN];

    float nums[NUMS_MAX_LEN];
    int nums_len;
    char *raw_num;
    float parsed_num;

    int i;

    while (fgets(line, LINE_MAX_LEN, stdin) != NULL) {
        nums_len = 0;

        /* raw_num = strtok(line, " "); */

        /* while (raw_num != NULL) { */
        /*     printf("%s\n", raw_num); */
        /* } */

        for (raw_num = strtok(line, " "); raw_num != NULL;
             raw_num = strtok(NULL, " ")) {
            parsed_num = strtof(raw_num, NULL);

            nums[nums_len++] = parsed_num;
            /* printf("parsed_num = %f\n", parsed_num); */
        }

        printf("%f ", arithmetic_mean(nums, nums_len));
        printf("%f ", geometric_mean(nums, nums_len));
        printf("\n");
    }

    return 0;
}
