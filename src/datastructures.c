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
            printf("ERROR: Could not reallocate memmory\n");
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

instr_vec* new_instrVec(size_t size){
    instr_vec* vec = (instr_vec*)malloc(sizeof(instr_vec));
    vec -> size = size;
    vec -> used = 0;
    vec -> instructions = (INSTRUCTION*)malloc(sizeof(INSTRUCTION) * size);
    if (vec -> instructions == NULL){
        printf("ERROR: Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    return vec;
}

void push_instrVec (instr_vec* instructions, INSTRUCTION instr){
    if (instructions -> used == instructions -> size - 1){
        instructions -> size += instructions -> size;
        instructions -> instructions = realloc(instructions -> instructions, sizeof(INSTRUCTION) * instructions -> size);
        if (instructions -> instructions == NULL){
            printf("ERROR: Failed to reallocate memmory\n");
            exit(EXIT_FAILURE);
        }
    }
    instructions -> instructions[instructions -> used] = instr;
    instructions -> used++;
}

void free_instrVec(instr_vec* vec){
    free(vec);
}
