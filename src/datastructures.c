#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "datastructures.h"

str_vector *new_StrVec(size_t size){
    str_vector *vec = (str_vector*)malloc(sizeof(str_vector));
    vec->size = size;
    vec->used = 0;
    vec->lines = (char**)malloc(vec->size* sizeof(char*));
    if (vec->lines == NULL){
        printf("ERROR: Memmory could not be allocated\n");
        exit(EXIT_FAILURE);
    }

    return vec;
}

void push_StrVec(str_vector *vec, char *line){
    if (vec->used == vec->size - 1){ // Check if we need to extend vector
        vec -> size += vec -> size; // TODO: The size grows exponentially
        vec -> lines = realloc(vec -> lines, vec -> size * sizeof(char*));
        if (vec -> lines == NULL){
            printf("ERROR: Could not reallocate memmory");
            exit(EXIT_FAILURE);
        }
    }
    vec -> lines[vec->used] = (char*)malloc(sizeof(char)*strlen(line));
    strcpy(vec->lines[vec->used], line); // strcpy is safer than just assingnig
    vec -> used++;
}

void free_StrVec(str_vector *vec){
    free(vec);
}
