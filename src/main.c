#include "line.h"
#include "means.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_CHUNK_SIZE 128
#define NUMS_MAX_LEN 1024
#define SPLITS_BASE_CAP 16

#define HELP_VALUE 0
#define ARITHMETIC_VALUE 1
#define GEOMETRIC_VALUE 2
#define HARMONIC_VALUE 3
#define WEIGHTED_ARITHMETIC_VALUE 4
#define MEDIAN_VALUE 5
#define VARIANCE_VALUE 6
#define STANDARD_DEVIATION_VALUE 7
#define INPUT_SEP_VALUE 8
#define OUTPUT_SEP_VALUE 9
#define INPUT_LINE_SEP_VALUE 10
#define OUTPUT_LINE_SEP_VALUE 11

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
    printf("  -v, --variance             Compute variance\n");
    printf("  -s, --standard-deviation   Compute standard deviation\n");
    printf("      --sep                  Input value separator\n");
    printf("      --input-sep            Input value separator\n");
    printf("      --output-sep           Output value separator\n");
    printf("      --input-line-sep       Input line separator\n");
    printf("      --output-line-sep      Output line separator\n");
    printf("      --help                 Display this help message\n\n");
    printf("Input format: Numbers (or value-weight pairs for weighted mean) "
           "separated by spaces.\n");
    printf("Example:\n");
    printf("  echo '1 2 3' | ./meanie -a\n");
    printf("  echo '2 1 4 2' | ./meanie -w\n");
}

int main(int argc, char *argv[]) {
    Line *line;
    char *input_sep = " ";
    char *input_line_sep = "\n";
    char *output_sep = " ";
    char *output_line_sep = "\n";

    MeanFunc means[MEANS_SIZE];
    int means_count = 0;

    double nums[NUMS_MAX_LEN];
    int nums_len;
    char *raw_num;
    double parsed_num;

    int opt;

    const struct option long_options[] = {
        {"help", no_argument, NULL, HELP_VALUE},
        {"arithmetic", no_argument, NULL, ARITHMETIC_VALUE},
        {"geometric", no_argument, NULL, GEOMETRIC_VALUE},
        {"harmonic", no_argument, NULL, HARMONIC_VALUE},
        {"weighted-arithmetic", no_argument, NULL, WEIGHTED_ARITHMETIC_VALUE},
        {"median", no_argument, NULL, MEDIAN_VALUE},
        {"variance", no_argument, NULL, VARIANCE_VALUE},
        {"standard-deviation", no_argument, NULL, STANDARD_DEVIATION_VALUE},
        {"sep", required_argument, NULL, INPUT_SEP_VALUE},
        {"input-sep", required_argument, NULL, INPUT_SEP_VALUE},
        {"output-sep", required_argument, NULL, OUTPUT_SEP_VALUE},
        {"input-line-sep", required_argument, NULL, INPUT_LINE_SEP_VALUE},
        {"output-line-sep", required_argument, NULL, OUTPUT_LINE_SEP_VALUE},
    };

    while ((opt = getopt_long(argc, argv, "mghwavs", long_options, NULL)) !=
           -1) {
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
        case VARIANCE_VALUE:
        case 'v':
            means[means_count++] = &variance;
            break;
        case STANDARD_DEVIATION_VALUE:
        case 's':
            means[means_count++] = &standard_deviation;
            break;
        case INPUT_SEP_VALUE:
            input_sep = optarg;
            break;
        case OUTPUT_SEP_VALUE:
            output_sep = optarg;
            break;
        case INPUT_LINE_SEP_VALUE:
            input_line_sep = optarg;
            break;
        case OUTPUT_LINE_SEP_VALUE:
            output_line_sep = optarg;
            break;
        case '?':
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
        means[means_count++] = &variance;
        means[means_count++] = &standard_deviation;
    }

    char *buffer = read_all(stdin, LINE_CHUNK_SIZE);
    buffer = strtok(buffer, "\n"); // Removing possible last \n token

    Splits *splits =
        split_buffer_by_tokens(buffer, input_line_sep, SPLITS_BASE_CAP);
    int i, j;
    for (i = 0; i < splits->len - 1; i++) {

        nums_len = 0;
        for (raw_num = strtok(splits->splits[i], input_sep); raw_num != NULL;
             raw_num = strtok(NULL, input_sep)) {
            nums[nums_len++] = strtod(raw_num, NULL);
        }

        for (j = 0; j < means_count - 1; j++) {
            printf("%f%s", means[j](nums, nums_len), output_sep);
        }

        printf("%f%s", means[j](nums, nums_len), output_line_sep);
    }

    nums_len = 0;
    for (raw_num = strtok(splits->splits[i], input_sep); raw_num != NULL;
         raw_num = strtok(NULL, input_sep)) {
        nums[nums_len++] = strtod(raw_num, NULL);
    }

    for (j = 0; j < means_count - 1; j++) {
        printf("%f%s", means[j](nums, nums_len), output_sep);
    }

    printf("%f\n", means[j](nums, nums_len));
    return 0;
}
