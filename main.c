#include "line.h"
#include "means.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINE_CHUNK_SIZE 128
#define NUMS_MAX_LEN 1024

int main(int argc, char *argv[]) {
    Line *line;

    MeanFunc means[MEANS_SIZE];
    int means_count = 0;

    float nums[NUMS_MAX_LEN];
    int nums_len;
    char *raw_num;
    float parsed_num;

    int opt;
    int i;

    while ((opt = getopt(argc, argv, "mghwa")) != -1) {
        switch (opt) {
        case 'a':
            means[means_count++] = &arithmetic_mean;
            break;
        case 'g':
            means[means_count++] = &geometric_mean;
            break;
        case 'h':
            means[means_count++] = &harmonic_mean;
            break;
        case 'w':
            means[means_count++] = &weighted_arithmetic_mean;
            break;
        case 'm':
            means[means_count++] = &median;
            break;
        default:
            fprintf(stderr, "Unknown option: %c\n", opt);
            return 1;
        }
    }

    // If there were no args passed, show all the means
    if (means_count == 0) {
        means[means_count++] = &arithmetic_mean;
        means[means_count++] = &geometric_mean;
        means[means_count++] = &harmonic_mean;
        means[means_count++] = &weighted_arithmetic_mean;
        means[means_count++] = &median;
    }

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

        for (i = 0; i < means_count; i++) {
            printf("%f ", means[i](nums, nums_len));
        }

        printf("\n");
        free(line);
    }

    return 0;
}
