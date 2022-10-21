#pragma once

#include <stdint.h>
#include <stdint.h>


typedef union INSTRUNCTION{
    // 8 bit instruction of r_type is encoded as
    // 7 6 5 4 3 2 1 0 (bits) 
    // 0: Detects imm value
    // 1-2: rt register identifier
    // 3-4: rs register identifier 
    // 5-7: operation identifier
    uint8_t r_type;
    
    // 8 bit instruction of j_type is encoded as
    //  7 6 5 4 3 2 1 0 (bits)
    //  0-4: instruction lines to jump
    //  5-7: operation identifier
    uint8_t j_type;

}INSTRUCTION;

// operation codes 111 and 011 are unused 
typedef uint8_t operationCode;
static const operationCode ADD     = 0x00;
static const operationCode SUB     = 0x01;
static const operationCode SET     = 0x02;
static const operationCode JUMP    = 0x4;
static const operationCode JEQ     = 0x5;
static const operationCode CALL    = 0x6;

#define is_j_type(x) (x & 0x4)      // Macro to check if operation is jump type
#define is_r_type(x) (!(x & 0x4))   // Macro to check if operation is r type

typedef uint8_t registerCode;
static const registerCode R0 = 0x0;
static const registerCode R1 = 0x1;
static const registerCode R2 = 0x2;
static const registerCode R3 = 0x3;

// Encodes an instruction form a parsed line of code 
// Assumes (line) to be a parsed correct instruction 
INSTRUCTION encode_instr(char* line); // TODO: when you have decided keywords s

