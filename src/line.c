#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *content;
    size_t len;
    size_t cap;
} Line;

Line *read_line(FILE *stream, size_t chunk_size) {
    char c;
    size_t i = 0;
    char *realloc_line = NULL;
    Line *line = malloc(sizeof(Line));
    if (line == NULL) {
        fprintf(stderr, "Couldn't allocate memory to read a line");
        return NULL;
    }

    line->content = malloc(sizeof(char) * chunk_size);
    if (line->content == NULL) {
        fprintf(stderr, "Couldn't allocate memory for line's contents");
        return NULL;
    }

    line->len = 0;
    line->cap = chunk_size;

    while ((c = fgetc(stream)) != EOF) {
        if (c == '\n') {
            break;
        }

        if (i == line->cap - 1) {
            realloc_line =
                (char *)realloc(line->content, line->cap + chunk_size);

            if (realloc_line == NULL) {
                fprintf(stderr,
                        "Couldn't realocate line buffer, returning now");
                break;
            }

            /* Checking the case where the realocated poiter is moved elsewhere
             */
            if (realloc_line != line->content) {
                line->content = realloc_line;
            }

            line->cap += chunk_size;
        }

        line->content[i] = c;
        i++;
    }

    line->len = i;
    line->content[i] = '\0';
    return line;
}

char *read_all(FILE *stream, size_t chunk_size) {
    char *buffer = malloc(chunk_size * sizeof(char));
    size_t len = 0;
    size_t cap = chunk_size;

    if (buffer == NULL) {
        fprintf(stderr, "Couldn't allocate buffer to parse stream input");
    }

    char c;
    while ((c = fgetc(stream)) != EOF) {
        if (len >= cap) {
            cap *= 1.5;
            void *realloc_buffer = realloc(buffer, cap * sizeof(char));

            if (realloc_buffer == NULL) {
                fprintf(stderr, "Couldn't realocate buffer to parse stream "
                                "input, returning now");
                break;
            }

            /* Checking the case where the realocated poiter is moved elsewhere
             */
            if (realloc_buffer != buffer) {
                buffer = realloc_buffer;
            }
        }

        buffer[len++] = c;
    }

    return buffer;
}

typedef struct Splits Splits;
struct Splits {
    int len;
    int cap;
    char **splits;
};

Splits *split_buffer_by_tokens(char *buffer, char *token) {
    Splits *splits = malloc(sizeof(Splits));
    splits->len = 0;
    splits->cap = 16;

    splits->splits = calloc(splits->cap, sizeof(char *));

    for (char *split = strtok(buffer, token); split != NULL;
         split = strtok(NULL, token)) {
        if (splits->len >= splits->cap) {
            // splits->cap *= 1.5;
        }

        splits->splits[splits->len++] = split;
    }

    return splits;
}
