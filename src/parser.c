#include "parser.h"
#include "datastructures.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 100

str_vector parseFile(FILE* file){
    str_vector* lines = new_StrVec(10);
    char* buffer = malloc(sizeof(char) * BUFFSIZE);

    while (fgets(buffer, BUFFSIZE, file) != NULL) { // Reads one line 
        push_StrVec(lines, buffer);
    }

    return *lines;
}
