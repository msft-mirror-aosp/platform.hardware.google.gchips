#include "gralloc3/gralloc_vendor_interface.h"
#include <vector>

namespace android::hardware::graphics::allocator::priv {

struct Descriptor {
    unsigned int size = 0;
    uint64_t producer_usage = 0;
    uint64_t consumer_usage = 0;

    struct PlaneDescriptor {
        int fd = -1;
        size_t size = 0;
        off_t offset = 0;
        int stride_byte = 0;
    };
    std::vector<PlaneDescriptor> planes;

    int width = 0;
    int height = 0;
    int stride_pixel = 0;
    int format = 0;
};

Descriptor *createDescriptor() { return new Descriptor(); }
void deleteDescriptor(Descriptor *descriptor) { delete descriptor; }

void setProducerUsage(Descriptor &descriptor, uint64_t usage) {
    descriptor.producer_usage = usage;
}

void setConsumerUsage(Descriptor &descriptor, uint64_t usage) {
    descriptor.consumer_usage = usage;
}

void setPlaneCount(Descriptor &descriptor, int count) {
    descriptor.planes.resize(count);
}

void setPlane(Descriptor &descriptor, int index, int fd, size_t size, off_t offset, int stride_byte) {
    descriptor.planes[index].fd = fd;
    descriptor.planes[index].size = size;
    descriptor.planes[index].offset = offset;
    descriptor.planes[index].stride_byte = stride_byte;
}

void setWidth(Descriptor &descriptor, int width) {
    descriptor.width = width;
}

void setHeight(Descriptor &descriptor, int height) {
    descriptor.height = height;
}

void setStridePixel(Descriptor &descriptor, int stride_pixel) {
    descriptor.stride_pixel = stride_pixel;
}

void setFormat(Descriptor &descriptor, int format) {
    descriptor.format = format;
}

uint8_t getFormatBitsPerPixel(uint64_t format) {
  return 0;
}

buffer_handle_t createNativeHandle(const Descriptor &descriptor) {
  return nullptr;
}

}  // namespace android::hardware::graphics::allocator::priv
