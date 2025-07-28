#pragma once

#include <stdio.h>

typedef struct {
    char *content;
    size_t len;
    size_t cap;
} Line;

typedef struct Splits Splits;
struct Splits {
    int len;
    int cap;
    char **splits;
};

Line *read_line(FILE *stream, size_t chunk_size);
char *read_all(FILE *stream, size_t chunk_size);
Splits *split_buffer_by_tokens(char *buffer, char *token, size_t base_cap);
