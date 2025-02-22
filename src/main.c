#include "line.h"
#include "means.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_CHUNK_SIZE 128
#define NUMS_MAX_LEN 1024

#define HELP_VALUE 0
#define ARITHMETIC_VALUE 1
#define GEOMETRIC_VALUE 2
#define HARMONIC_VALUE 3
#define WEIGHTED_ARITHMETIC_VALUE 4
#define MEDIAN_VALUE 5

void show_help() {
    printf("Usage: meanie [OPTIONS]\n");
    printf("Calculate statistical means from input data. By default, all means "
           "are computed.\n\n");
    printf("Options:\n");
    printf("  -a, --arithmetic           Compute arithmetic mean\n");
    printf("  -g, --geometric            Compute geometric mean\n");
    printf("  -h, --harmonic             Compute harmonic mean\n");
    printf("  -w, --weighted-arithmetic  Compute weighted arithmetic mean\n");
    printf("  -m, --median               Compute median\n");
    printf("      --help                 Display this help message\n\n");
    printf("Input format: Numbers (or value-weight pairs for weighted mean) "
           "separated by spaces.\n");
    printf("Example:\n");
    printf("  echo '1 2 3' | ./meanie -a\n");
    printf("  echo '2 1 4 2' | ./meanie -w\n");
}

int main(int argc, char *argv[]) {
    Line *line;

    MeanFunc means[MEANS_SIZE];
    int means_count = 0;

    double nums[NUMS_MAX_LEN];
    int nums_len;
    char *raw_num;
    double parsed_num;

    int opt;
    int i;

    const struct option long_options[] = {
        {"help", 0, NULL, HELP_VALUE},
        {"arithmetic", 0, NULL, ARITHMETIC_VALUE},
        {"geometric", 0, NULL, GEOMETRIC_VALUE},
        {"harmonic", 0, NULL, HARMONIC_VALUE},
        {"weighted-arithmetic", 0, NULL, WEIGHTED_ARITHMETIC_VALUE},
        {"median", 0, NULL, MEDIAN_VALUE},
    };

    while ((opt = getopt_long(argc, argv, "mghwa", long_options, NULL)) != -1) {
        switch (opt) {
        case HELP_VALUE:
            show_help();
            exit(0);
            break;
        case ARITHMETIC_VALUE:
        case 'a':
            means[means_count++] = &arithmetic_mean;
            break;
        case GEOMETRIC_VALUE:
        case 'g':
            means[means_count++] = &geometric_mean;
            break;
        case HARMONIC_VALUE:
        case 'h':
            means[means_count++] = &harmonic_mean;
            break;
        case WEIGHTED_ARITHMETIC_VALUE:
        case 'w':
            means[means_count++] = &weighted_arithmetic_mean;
            break;
        case MEDIAN_VALUE:
        case 'm':
            means[means_count++] = &median;
            break;
        default:
            fprintf(stderr, "Unknown option: %c\n", opt);
            return 1;
        }
    }

    /* If there were no args passed, show all the means */
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
            parsed_num = strtod(raw_num, NULL);

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
