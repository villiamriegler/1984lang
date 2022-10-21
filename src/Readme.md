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

## Example program
```
The Dayorder on day 2 was to always listen to big brother. 
This made Equal feelings between JULIA and Winston even stronger and 0 people could stand in their way. 
Dayorder on day 2 was however trubelsome for others.  


For example this wasn't exactly Plusgood to O'Brian as he no longer cared for big brother all he whanted was to catch Winston with absolutly 0 regard for his own safety.
Which was Plusungood for Julia whom missed SYME that had died 1 days ago.
She needed to Crimestop her thinking JULIA and SYME were not i love and 1 day is too short to proccess.
Also avoiding Joycamp for -4 days was really important 


As approached Equal between Winston and O'Brian with soon 0 meters to go.
The Dayorder on day 1 was announced to have been a test and many had failed.

##################
# NON FUZZY CODE #
##################

Dayorder 2 # Takes input into Winston
Equal Julia Winston 0 # Moves input into Julia, julia is our counter

Dayorder 2 # Takes input into Winston

Plusgood O'Brian Winston 0 # O'Brian + Winston
Plusungood JULIA SYME 1    # Julia - 1 
Crimestop JULIA SYME 1     # If Julia == 0 jump one line 
Joycamp -3                 # If Julia != 0 jump -3 lines

Equal Winston O'Brian 0 # Moves O'Brian output into Winston
Dayorder 1              # Prints Winston
```