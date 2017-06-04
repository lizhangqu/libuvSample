//
// Created by 李樟取 on 2017/6/4.
//

#ifndef UV_NATIVE_H
#define UV_NATIVE_H

#include "jni.h"

#ifndef NELEM
# define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))
#endif


#ifndef CLASSNAME
#define CLASSNAME "io/github/lizhangqu/uv/UV"
#endif



#ifdef ANDROID

#include <android/log.h>

#define TAG "UV"

#define ALOGE(fmt, ...) __android_log_print(ANDROID_LOG_ERROR, TAG, fmt, ##__VA_ARGS__)
#define ALOGI(fmt, ...) __android_log_print(ANDROID_LOG_INFO, TAG, fmt, ##__VA_ARGS__)
#define ALOGD(fmt, ...) __android_log_print(ANDROID_LOG_DEBUG, TAG, fmt, ##__VA_ARGS__)
#define ALOGW(fmt, ...) __android_log_print(ANDROID_LOG_WARN, TAG, fmt, ##__VA_ARGS__)
#else
#define ALOGE printf
#define ALOGI printf
#define ALOGD printf
#define ALOGW printf
#endif

#endif //UV_NATIVE_H
