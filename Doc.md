## C-Api
### `createRen(size_t cap)`

Creates a new Ren allocator with the specified capacity.

- `cap`: The capacity of the allocator in bytes.
- Returns a pointer to the created Ren allocator.

### `allocRen(Ren* ren, size_t size, size_t alignment)`

Allocates memory from the Ren allocator with the specified size and alignment.

- `ren`: Pointer to the Ren allocator.
- `size`: The size of memory to allocate in bytes.
- `alignment`: The desired memory alignment in bytes.
- Returns a pointer to the allocated memory.

### `dropDown(Ren* ren)`

Resets the memory usage of the Ren allocator.

- `ren`: Pointer to the Ren allocator.

### `destroyRen(Ren* ren)`

Deallocates the Ren allocator and its associated memory.

- `ren`: Pointer to the Ren allocator.
## C++-Api
### Constructors

- `Ren(size_t cap)`: Constructs a `Ren` allocator with the specified capacity.

### Member Functions

- `void *alloc(size_t size, size_t alignment)`: Allocates memory with the specified `size` and `alignment`. Returns a pointer to the allocated memory block.

- `void destroy(void *mem)`: Deallocates the memory block pointed to by `mem`, if it falls within the allocated buffer range.

- `void dropDown()`: Resets the memory usage of the `Ren` allocator, effectively releasing all allocated memory.

## Memory Alignment

- Linux Platform: The default memory alignment used is 8 bytes.

- Windows Platform: The default memory alignment used is 16 bytes.

## Important Notes

- Memory allocations are made from the preallocated buffer specified during construction.
- Allocated memory is aligned according to the specified `alignment` parameter.
- Memory deallocation through the `destroy` function is limited to memory blocks within the allocated buffer range.
