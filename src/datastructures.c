#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "datastructures.h"

str_vector *new_StrVec(size_t size){
    str_vector * vec;
    vec -> size = size * sizeof(char*);
    vec -> used = 0;
    vec -> lines = (char**)malloc(vec->size);
    if (vec -> lines == NULL){
        printf("ERROR: Memmory could not be allocate\n");
        exit(EXIT_FAILURE);
    }

    return vec;
}

void push_StrVec(str_vector *vec, char *line){
    if (vec -> used == vec -> size){
        vec -> size += vec -> size; // TODO: The size grows exponentially
        vec -> lines = realloc(vec -> lines, vec -> size);
        if (vec -> lines == NULL){
            printf("ERROR: Could not reallocate memmory");
            exit(EXIT_FAILURE);
        }
    }
    *(vec -> lines + vec -> used) = line;
    vec->used++;
}

void free_StrVec(str_vector *vec){
    free(vec);
}
