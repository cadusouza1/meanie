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

    float nums[NUMS_MAX_LEN];
    int nums_len;
    char *raw_num;
    float parsed_num;

    int opt;
    int show_all = 0;
    int show_arithmetic = 0;
    int show_geometric = 0;
    int show_harmonic = 0;
    int show_weighted_average = 0;

    if (argc < 2) {
        show_all = 1;
    } else {
        while ((opt = getopt(argc, argv, "aghw")) != -1) {
            switch (opt) {
            case 'a':
                show_arithmetic = 1;
                break;
            case 'g':
                show_geometric = 1;
                break;
            case 'h':
                show_harmonic = 1;
                break;
            case 'w':
                show_weighted_average = 1;
                break;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                return 1;
            }
        }
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

        if (show_arithmetic || show_all) {
            printf("%f ", arithmetic_mean(nums, nums_len));
        }

        if (show_geometric || show_all) {
            printf("%f ", geometric_mean(nums, nums_len));
        }

        if (show_harmonic || show_all) {
            printf("%f ", harmonic_mean(nums, nums_len));
        }

        if (show_weighted_average || show_all) {
            printf("%f", weighted_arithmetic_mean(nums, nums_len));
        }

        printf("\n");

        free(line);
    }

    return 0;
}
