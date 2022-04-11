//
// Created by lijing14 on 2022/4/11.
//

#ifndef MY_APPLICATION_NATIVE_LIB_H
#define MY_APPLICATION_NATIVE_LIB_H

#include <jni.h>

extern "C" {
jstring stringFromJNI(JNIEnv *env, jobject _jobject);
jlong createPlayer(JNIEnv *env, jobject _jobject);
void start(JNIEnv *env, jobject _jobject, jlong player);
jstring getName(JNIEnv *env, jobject _jobject, jlong player);
void pause(JNIEnv *env, jobject _jobject, jlong player);
void release(JNIEnv *env, jobject _jobject, jlong player);
}


#endif //MY_APPLICATION_NATIVE_LIB_H
