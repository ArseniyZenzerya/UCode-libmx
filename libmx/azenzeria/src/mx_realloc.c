#include "../inc/libmx.h"


void *mx_realloc(void *ptr, size_t size){


    size_t len = malloc_size(ptr);
    void *new_ptr;

   
    if (!ptr) {
	    return malloc(size);
    }
    if (size <= 0 && ptr) {
        free(ptr);

        return NULL;
    }

    if (len > size) {
        new_ptr = (void *)malloc(len);
        size = len;
    }
    else {
        new_ptr = (void *)malloc(size);
    }
    
    if (!new_ptr) {
        return NULL;
    }

    new_ptr = mx_memmove(new_ptr, ptr, size);
    free(ptr);

return new_ptr;

}




