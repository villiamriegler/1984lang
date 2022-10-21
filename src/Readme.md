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
| Plusgood           | `rs = rs + rt + imm` |
| Plusungood           | `rs = rs - rt - imm` |
| Equal           | `rs = rt + imm` |
| Crimestop           | Jump `imm`(0 or 1) lines if `rs == rt ` else jump `not imm` lines|

### Jump operations

| **Operation** | **Description** |
|---------------|-----------------|
| Joycamp          | Jump unconditionally `adder`(0-32) lines |
| Dayorder      | A call instruction, documentation see [Call Section](#CALL-operation) |

#### CALL operation
| **Code** | **Function** |
|----------|--------------|
| 1        | Prints value of R1 to standard output |
| 2        | Gets value for standard input and stores it in R1 |
| 3        | Terminates program |

## Registers 

1984lang supports 4 registers:

| **Number** | **NAME** | **FUNCTION** |
|------------|----------|--------------|
| 0          | SYME     | Should alwyas be zero |
| 1          | WINSTON  | Handles i/o |
| 2          | JULIA    | Good place to store information |
| 3          | O'BRIAN  |  |