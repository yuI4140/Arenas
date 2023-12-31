#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
#define LINUX_ALIGNMENT 8
#endif

#ifdef _WIN32
#define WINDOWS_ALIGNMENT 16
#endif

typedef struct {
  size_t cap;
  size_t size;
  void *db;
} Ren;

static void rAssert(int condition, const char *message);
static void rPAssert(void *ptr, const char *message);
Ren *createRen(size_t cap);
void destroyRen(Ren *ren);
void *allocRen(Ren *ren, size_t size, size_t alignment);
void freeMemInRen(Ren *ren, void *mem);
void dropDown(Ren *ren);

#ifdef MEM_IMP
static void rAssert(int condition, const char *message) {
  if (!condition) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
  }
}
static void rPAssert(void *ptr, const char *message) {
  if (!ptr) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
  }
}
Ren *createRen(size_t cap) {
  Ren *ren = (Ren *)malloc(sizeof(Ren));
  rPAssert(ren, "Memory allocation failed for Ren");

  ren->cap = cap;
  ren->size = 0;
  ren->db = malloc(cap);
  rPAssert(ren->db, "Memory allocation failed for Ren");

  return ren;
}

void destroyRen(Ren *ren) {
  if (ren) {
    free(ren->db);
    free(ren);
  }
}
void *allocRen(Ren *ren, size_t size, size_t alignment) {
  rAssert(ren && size > 0 && alignment > 0, "Invalid arguments in allocRen");
  size_t totalSize = size + alignment - 1;
  void *mem = (char *)ren->db + ren->size;
  char *charMem = (char *)mem; // Cast to char* for pointer arithmetic

  uintptr_t uintptrMem =
      (uintptr_t)(charMem + alignment - 1) & ~(alignment - 1);
  void *alignedMem = (void *)uintptrMem;

  ptrdiff_t offset = (char *)alignedMem - charMem;

  size_t allocatedSize = offset + totalSize;

  rAssert(ren->size + allocatedSize <= ren->cap,
          "Memory allocation would exceed capacity");

  ren->size += allocatedSize;
  return alignedMem;
}
void dropDown(Ren *ren) {
  if (ren) {
    ren->size = 0;
  }
}
#endif // MEM_IMP
