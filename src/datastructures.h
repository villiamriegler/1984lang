#pragma once

#include <stddef.h>
#include"compiler.h"

typedef struct vector{
    size_t size;
    size_t used;
    char** lines;
}str_vector;


str_vector *new_StrVec (size_t size);

void push_StrVec(str_vector* vec, char* line);

void free_StrVec(str_vector* vec);

typedef struct vec{
    size_t size;
    size_t used;
    INSTRUCTION* instructions;
}instr_vec;

instr_vec* new_instrVec (size_t size);

void push_instrVec (instr_vec * instructions, INSTRUCTION instr);

void free_instrVec(instr_vec* vec);