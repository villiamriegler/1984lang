#include "datastructures.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv){
    FILE* file; 

    
    if (argc != 2){ // Checking for correct number of arguments to compiler
        printf("Error: Too many or too few arguments supplied\n");
        exit(EXIT_FAILURE);
    }
    
    file = fopen(argv[1],"r");
    if (file == NULL){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    
    str_vector* yes;

    yes = parseFile(file);

    for(int i = 0; i < yes->used; i++){
        printf("%s, %i, %lu\n", yes->lines[i],i,sizeof(yes->lines[i]));
    }

    free_StrVec(yes);

    return 0;
}
