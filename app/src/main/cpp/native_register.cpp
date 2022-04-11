//
// Created by lijing14 on 2022/4/11.
//
#include <jni.h>
#include <cstdlib>
#include "native-lib.h"

static const JNINativeMethod methods[] = {
        {"stringFromJNI", "()Ljava/lang/String;", (void *)stringFromJNI},
        {"createPlayer", "()J", (void *)createPlayer},
        {"start", "(J)V", (void *)start},
        {"getName", "(J)Ljava/lang/String;", (void *)getName},
        {"pause", "(J)V", (void *)pause},
        {"release", "(J)V", (void *)release},
};

static int registNativeMethod(JNIEnv *vm){
    jclass clazz  = vm->FindClass("com/lijing/media/player/LeeNativePlayer");
    return vm->RegisterNatives(clazz, methods, sizeof(methods)/sizeof(methods[0]));
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    int result = -1;

    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) == JNI_OK) {
        if (registNativeMethod(env) == JNI_OK) {
            result = JNI_VERSION_1_6;
        }
        return result;
    }
    return result;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved)
{


}