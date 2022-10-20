#pragma once

#include <stddef.h>

typedef struct vector{
    size_t size;
    size_t used;
    char** lines;
}str_vector;

str_vector *new_StrVec (size_t size);

void push_StrVec(str_vector* vec, char* line);

void free_StrVec(str_vector* vec);
