#pragma once

#include <cstdint>
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
const operationCode ADD     = 0x00;
const operationCode SUB     = 0x01;
const operationCode SET     = 0x02;
const operationCode JUMP    = 0x4;
const operationCode JEQ     = 0x5;
const operationCode CALL    = 0x6;

#define is_j_type(x) (x & 0x4)      // Macro to check if operation is jump type
#define is_r_type(x) (!(x & 0x4))   // Macro to check if operation is r type

typedef uint8_t registerCode;
const registerCode R0 = 0x0;
const registerCode R1 = 0x1;
const registerCode R2 = 0x2;
const registerCode R3 = 0x3;


