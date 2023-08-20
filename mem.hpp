#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <memory>

#ifdef __linux__
constexpr size_t LINUX_ALIGNMENT = 8;
#endif

#ifdef _WIN32
constexpr size_t WINDOWS_ALIGNMENT = 16;
#endif

class Ren {
public:
  Ren(size_t cap);
  ~Ren();
  void *alloc(size_t size, size_t alignment);
  void destroy(void *mem);
  void dropDown();

private:
  size_t cap;
  size_t size;
  void *db;
  void rAssert(bool condition, const char *message);
  void rPAssert(void *ptr, const char *message);
};
#ifdef MEM_IMP

Ren::Ren(size_t cap) : cap(cap), size(0), db(nullptr) {
  db = std::malloc(cap);
  rPAssert(db, "Memory allocation failed for Ren");
}

Ren::~Ren() {
  if (db) {
    std::free(db);
  }
}

void *Ren::alloc(size_t size, size_t alignment) {
  rAssert(size > 0 && alignment > 0, "Invalid arguments in allocRen");
  size_t totalSize = size + alignment - 1;
  void *mem = reinterpret_cast<char *>(db) + size;
  char *charMem = static_cast<char *>(mem);

  uintptr_t uintptrMem =
      reinterpret_cast<uintptr_t>(charMem + alignment - 1) & ~(alignment - 1);
  void *alignedMem = reinterpret_cast<void *>(uintptrMem);

  ptrdiff_t offset = static_cast<char *>(alignedMem) - charMem;

  size_t allocatedSize = offset + totalSize;

  rAssert(size + allocatedSize <= cap,
          "Memory allocation would exceed capacity");

  this->size += allocatedSize;
  return alignedMem;
}

void Ren::destroy(void *mem) {
  if (mem) {
    if (mem >= db && mem < reinterpret_cast<char *>(db) + size) {
      std::free(mem);
    }
  }
}

void Ren::dropDown() { size = 0; }

void Ren::rAssert(bool condition, const char *message) {
  if (!condition) {
    std::fprintf(stderr, "Error: %s\n", message);
    std::exit(EXIT_FAILURE);
  }
}

void Ren::rPAssert(void *ptr, const char *message) {
  if (!ptr) {
    std::fprintf(stderr, "Error: %s\n", message);
    std::exit(EXIT_FAILURE);
  }
}
#endif /* MEM_IMP */
