#pragma once

#include <stdio.h>

typedef struct {
    char *content;
    size_t len;
    size_t cap;
} Line;

Line *read_line(FILE *stream, size_t chunk_size);
