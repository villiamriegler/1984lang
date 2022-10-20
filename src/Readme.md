# Language Specification

Instruction encodings are of type `register` or `jump`. [Encoding specification](#-encoding-specification) below specefies:

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
