# Language Specification

Instruction encodings are of type `register` or `jump`. [Encoding specification](#Encoding-Specification) below specefies:

> ### Register type
> - 8: different operations
> - 4: registers
> - Detection of immediate values 

> ### Jump type
> - 8: different operations
> - 32: instruction jumps 

#### Encoding Specification

| **Type** | **Encoding** |
|----------|--------------|
| register | `op<7:5>, rs<4:3>, rt<2:1>, imm<0>`|
| jump     | `op<7:5>, addr<4:0>` |

## Operations
Operation documentation, defines the behavior off every operation.

### Register Operations

| **Operation** | **Description** |
|---------------|-----------------|
| ADD           | `rs = rs + rt + imm` |
| SUB           | `rs = rs - rt - imm` |
| SET           | `rs = rt + imm` |
| JEQ           | Jump `imm`(0 or 1) lines if `rs == rt ` else jump `not imm` lines|

### Jump operations

| **Operation** | **Description** |
|---------------|-----------------|
| JUMP          | Jump unconditionally `adder`(0-32) lines |
| CALL          | For call documentation see [Call Section](#CALL-operation) |

#### CALL operation
| **Code** | **Function** |
|----------|--------------|
| 1        | Prints value of R1 to standard output |
| 2        | Gets value for standard input and stores it in R1 |
| 3        | Terminates program |
