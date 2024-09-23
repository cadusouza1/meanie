#include "line.h"
#include "means.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_CHUNK_SIZE 128
#define NUMS_MAX_LEN 1024

int main(int argc, char *argv[]) {
    Line *line;

    float nums[NUMS_MAX_LEN];
    int nums_len;
    char *raw_num;
    float parsed_num;

    while ((line = read_line(stdin, LINE_CHUNK_SIZE))) {
        if (line->len == 0) {
            break;
        }

        nums_len = 0;
        for (raw_num = strtok(line->content, " "); raw_num != NULL;
             raw_num = strtok(NULL, " ")) {
            parsed_num = strtof(raw_num, NULL);

            nums[nums_len] = parsed_num;
            nums_len++;
        }

        printf("%f ", arithmetic_mean(nums, nums_len));
        printf("%f ", geometric_mean(nums, nums_len));
        printf("\n");

        free(line);
    }

    return 0;
}
