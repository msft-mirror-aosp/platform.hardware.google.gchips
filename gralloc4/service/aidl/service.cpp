#undef LOG_TAG
#define LOG_TAG "gralloc-allocator"

#include <android/binder_ibinder_platform.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <android/binder_status.h>
#include <log/log.h>

#if defined(GRALLOC_MAPPER_4)
#include "aidl/GrallocAllocator.h"
#elif defined (GRALLOC_MAPPER_5)
#include "aidl/GrallocAllocator2.h"
#endif

using namespace android;

using pixel::allocator::GrallocAllocator;

int main() {
    auto service = ndk::SharedRefBase::make<GrallocAllocator>();
    auto binder = service->asBinder();

    AIBinder_setMinSchedulerPolicy(binder.get(), SCHED_NORMAL, -20);

    const auto instance = std::string() + GrallocAllocator::descriptor + "/default";
    auto status = AServiceManager_addServiceWithFlags(binder.get(), instance.c_str(),
                                        AServiceManager_AddServiceFlag::ADD_SERVICE_ALLOW_ISOLATED);
    if (status != STATUS_OK) {
        ALOGE("Failed to start AIDL gralloc allocator service");
        return -EINVAL;
    }

    ABinderProcess_setThreadPoolMaxThreadCount(4);
    ABinderProcess_startThreadPool();
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE; // Unreachable
}
