#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stdbool.h>
#include <sys/types.h>

#define RELATIVE_POINTERS true

#ifndef ARENA_SIZE
#define ARENA_SIZE 4096
#endif

#ifndef N_LISTS
#define N_LISTS 59
#endif

#define ALLOC_HEADER_SIZE (sizeof(header) - (2 * sizeof(header *)))
#define MIN_ALLOCATION 8
enum state {
    UNALLOCATED = 0,
    ALLOCATED = 1,
    FENCEPOST = 2
};
typedef struct header {
    size_t size_state;
    size_t left_size;
    union {
        struct{
            struct header * next;
            struct header * prev;
        };
        char data[0];
    };
} header;

static inline size_t get_size(header * h){
    return h -> size_state & ~0x3;
}
static inline void set_state(header * h, size_t size){
    h-> size_state = size | (h->size_state & 0x3);
}
static inline enum state get_state(header * h){
    return (enum state) (h-> size_state & 0x3);
}
static inline void set_size_and_state(header * h, size_t size, enum state s){
    h->size_state = (size & ~0x3) | (s & 0x3);
}
#define MAX_OS_CHUNKS 1024
// Malloc interface
void * my_malloc(size_t size);
void * my_calloc(size_t nmemb, size_t size);
void * my_realloc(void * ptr, size_t size);
void my_free(void * p);

// Debug list verifitcation
bool verify();

extern void * base;
extern header freelistSentinels[];
extern char freelist_bitmap[];
extern header * osChunkList[];
extern size_t numOsChunks;

#endif