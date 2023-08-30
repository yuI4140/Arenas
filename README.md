# Ren Memory Allocator

The Ren Memory Allocator is a s
stb-style library implemented in C. It provides functions to allocate and manage memory chunks with alignment support.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [API](#api)
- [Building](#building)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Ren Memory Allocator is designed to manage memory efficiently, especially in situations where memory alignment is crucial, such as in certain optimization scenarios. The allocator aims to provide a way to allocate memory blocks aligned to specified boundaries.

## Usage

To use the Ren Memory Allocator in your C project, follow these steps:

1. Include the `ren.h` header file in your source code.
2. Implement the memory allocation functions by defining `MEM_IMP` before including `ren.h`. Refer to the provided code example for reference.
3. Use the allocator's functions like `createRen`, `allocRen`, and `destroyRen` to allocate, manage, and deallocate memory.

Example usage:
- C :

```c
#define MEM_IMP
#include "mem.h"

int main() {
    Ren* ren = createRen(4096); // Create a Ren allocator with a capacity of 4096 bytes

    void* mem = allocRen(ren, 128, 8); // Allocate 128 bytes of memory aligned to 8 bytes
    // Use the allocated memory...

    dropDown(ren); // Reset the allocator's memory usage

    destroyRen(ren); // Deallocate the Ren allocator

    return 0;
}
```
- C++ :
```cpp
#define MEM_IMP
#include "mem.hpp"
int main() {
    Ren ren(1024);

    // Usage example
    void *mem = ren.alloc(100,8);
    // Use mem as needed

    ren.dropDown();
    ren.destroy(mem);

    return 0;
}
```
## Doc
*see* [Doc](https://github.com/yuI4140/Arenas/Doc.md)
## Contributing
*See* [Contributing](https://github.com/yuI4140/Arenas/Contributing.md)
## License
The Ren Memory Allocator is released under the [MIT License](LICENSE).
