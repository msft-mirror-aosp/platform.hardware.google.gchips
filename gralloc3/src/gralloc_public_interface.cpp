#include <gralloc3/gralloc_public_interface.h>

#include "mali_gralloc_buffer.h"

native_handle_t *createNativeHandle() {
    return nullptr;
}

void setOffset(native_handle_t *handle, int offset) {
    (void) handle;
    (void) offset;
}
