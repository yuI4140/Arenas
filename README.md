# Ren Memory Allocator

The Ren Memory Allocator is a simple memory allocation library implemented in C. It provides functions to allocate and manage memory chunks with alignment support.

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

```c
#include "ren.h"

int main() {
    Ren* ren = createRen(4096); // Create a Ren allocator with a capacity of 4096 bytes

    void* mem = allocRen(ren, 128, 8); // Allocate 128 bytes of memory aligned to 8 bytes
    // Use the allocated memory...

    dropDown(ren); // Reset the allocator's memory usage

    destroyRen(ren); // Deallocate the Ren allocator

    return 0;
}
```
## API

### `Ren* createRen(size_t cap)`

Creates a new Ren allocator with the specified capacity.

- `cap`: The capacity of the allocator in bytes.
- Returns a pointer to the created Ren allocator.

### `void* allocRen(Ren* ren, size_t size, size_t alignment)`

Allocates memory from the Ren allocator with the specified size and alignment.

- `ren`: Pointer to the Ren allocator.
- `size`: The size of memory to allocate in bytes.
- `alignment`: The desired memory alignment in bytes.
- Returns a pointer to the allocated memory.

### `void dropDown(Ren* ren)`

Resets the memory usage of the Ren allocator.

- `ren`: Pointer to the Ren allocator.

### `void destroyRen(Ren* ren)`

Deallocates the Ren allocator and its associated memory.

- `ren`: Pointer to the Ren allocator.

## Contributing

Contributions to the Ren Memory Allocator are welcome! If you'd like to contribute, follow these steps:

1. Fork the repository on GitHub.
2. Clone your forked repository to your local machine.
3. Create a new branch for your feature or bug fix.
4. Make your changes and commit them.
5. Push the changes to your fork on GitHub.
6. Create a pull request from your branch to the main repository.

Feel free to open an issue if you encounter any problems or have questions.

## License

The Ren Memory Allocator is released under the [MIT License](LICENSE).
