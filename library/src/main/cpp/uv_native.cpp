//
// Created by 李樟取 on 2017/6/4.
//

#include "uv_native.h"
#include "uv.h"

uv_loop_t *loop;

void on_resolved(uv_getaddrinfo_t *resolver, int status, struct addrinfo *res) {
    if (status < 0) {
        ALOGE("getaddrinfo callback error %s\n", uv_err_name(status));
        return;
    }
    char addr[17] = {'\0'};
    uv_ip4_name((struct sockaddr_in *) res->ai_addr, addr, 16);
    ALOGE("ipv4 :%s\n", addr);
    uv_freeaddrinfo(res);
}

void test(JNIEnv *env, jobject thiz) {
    loop = uv_default_loop();
    ALOGE("www.baidu.com is... ");
    uv_getaddrinfo_t resolver;
    int r = uv_getaddrinfo(loop, &resolver, on_resolved, "www.baidu.com", "80", NULL);

    if (r) {
        ALOGE("getaddrinfo call error %s\n", uv_err_name(r));
    } else {
        uv_run(loop, UV_RUN_DEFAULT);
    }
}

static const JNINativeMethod sMethods[] = {
        {
                const_cast<char *>("test"),
                const_cast<char *>("()V"),
                reinterpret_cast<void *>(test)
        },

};

int registerNativeMethods(JNIEnv *env, const char *className, const JNINativeMethod *methods,
                          const int numMethods) {
    jclass clazz = env->FindClass(className);
    if (!clazz) {
        ALOGE("Native registration unable to find class '%s'\n", className);
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, methods, numMethods) != 0) {
        ALOGE("RegisterNatives failed for '%s'\n", className);
        env->DeleteLocalRef(clazz);
        return JNI_FALSE;
    }
    env->DeleteLocalRef(clazz);
    return JNI_TRUE;
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    registerNativeMethods(env, CLASSNAME, sMethods, NELEM(sMethods));
    return JNI_VERSION_1_6;
}
