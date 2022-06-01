#include <errno.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myMalloc.h"
static pthread_mutex_t mutex;
header freelistSentinels[N_LISTS];
header * lastFencePost;
void * base;
header * osChunkList[MAX_OS_CHUNKS];
size_t numOsChunks = 0;

static void init(void) __attribute__((constructor));

static inline header * get_header_from_offset(void * ptr, ptrdiff_t off);
static inline header * get_left_header(header * h);
static inline header * ptr_to_header(void *p);

static inline void initialize_fencepost(header * fp, size_t left_size);
static inline void insert_os_chunk(header *hdr);
static inline void insert_fencepost(void *raw_mem, size_t size);
static header *allocate_chunk(size_t size);

static inline void deallocate_object(void *p);

static inline header *allocate_object(size_t raw_size);

static inline header *detect_cycles();
static inline header *verify_pointers();
static inline bool verify_freelist();
static inline header *verify_chunk(header * chunk);
static inline bool verify_tags();
static void init();

static bool isMallocInitialized;

static inline header *get_header_from_offset(void * ptr, ptrdiff_t off){
    return (header *)((char *) ptr + off);
}
header * get_right_header(header * h){

}
inline static header * get_left_header(header * h){

}
inline static void initialize_fencepost(header *fp, size_t left_size){

}
inline static void insert_os_chunk(header *hdr){

}
inline static void insert_fenceposts(void *raw_mem, size_t size){

}
inline static void initialize_fencepost(header * fp, size_t left_size){

}
inline static void insert_os_chunk(header *hdr){

}
inline static void insert_fenceposts(void *raw_mem, size_t size){

}
static header * allocate_chunk(size_t size){

}
static inline size_t round(size_t size){

}
static inline void free_block(header * h){

}
static inline size_t find_index(size_t s){

}
static inline size_t alloc_size(size_t s){

}
static void insert_block_to_free_list(header * b){

}
inline header * allocate_object(size_t raw_size){

}
static inline header *ptr_to_header(void * p){

}
static inline void deallocate_object(void * p){

}
static inline header *detect_cycles(){

}
static inline header * verify_pointers(){

}
static inline bool verify_freelist(){

}
static inline header * verify_chunk(header * chunk){

}
static inline bool verify_tags(){

}
static void init(){

}
void * my_malloc(size_t size){

} 
void * my_calloc(size_t nmemb, size_t size){

}
void * my_realloc(void * ptr, size_t size){

}
void my_free(void * p){
    
}
bool verify() {
    
}