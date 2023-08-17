#include <stdlib.h>
#include <stdio.h>

typedef struct {
    size_t cap;
    size_t size;
    void* db;
} Ren;

void rAssert(int condition, const char* message);
void rPAssert(void *ptr, const char* message);
Ren* createRen(size_t cap);
void destroyRen(Ren* ren);
void* allocRen(Ren* ren, size_t size);
void dropDown(Ren* ren);

#ifdef MEM_IMP
void rAssert(int condition, const char* message) {
    if (!condition) {
        fprintf(stderr, "Error: %s\n", message);
        exit(EXIT_FAILURE);
    }
}

void rPAssert(void* ptr, const char* message) {
    if (!ptr) {
        fprintf(stderr, "Error: %s\n", message);
        exit(EXIT_FAILURE);
    }
}

Ren* createRen(size_t cap) {
    Ren* ren = (Ren*)malloc(sizeof(Ren));
    rPAssert(ren, "Memory allocation failed for Ren");

    ren->cap = cap;
    ren->size = 0;
    ren->db = malloc(cap);
    rPAssert(ren->db, "Memory allocation failed for Ren");

    return ren;
}

void destroyRen(Ren* ren) {
    if (ren) {
        free(ren->db);
        free(ren);
    }
}

void* allocRen(Ren* ren, size_t size) {
    rAssert(ren && size > 0, "Invalid arguments in allocRen");
    rAssert(ren->size + size <= ren->cap, "Memory allocation would exceed capacity");

    void* mem = (char*)ren->db + ren->size;
    ren->size += size;
    return mem;
}

void dropDown(Ren* ren) {
    if (ren) {
        ren->size = 0;
    }
}
#endif // MEM_IMP