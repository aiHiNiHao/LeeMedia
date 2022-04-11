#include <string>
#include "native-lib.h"
#include <jni.h>
#include "LeePlayer.cpp"

extern "C" {
jstring
stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

jlong createPlayer(JNIEnv *env, jobject _jobject) {
    auto *player = new LeePlayer("river lee");
    return reinterpret_cast<jlong>(player);
}

void start(JNIEnv *env, jobject _jobject, jlong player) {
    auto *_player = reinterpret_cast<LeePlayer *>(player);
    _player->start();
}

jstring getName(JNIEnv *env, jobject _jobject, jlong player) {
    auto *_player = reinterpret_cast<LeePlayer *>(player);
    return env->NewStringUTF(_player->getName().c_str());
}

void pause(JNIEnv *env, jobject _jobject, jlong player) {
    auto *_player = reinterpret_cast<LeePlayer *>(player);
    _player->pause();
}

void release(JNIEnv *env, jobject _jobject, jlong player) {
    auto *_player = reinterpret_cast<LeePlayer *>(player);
    delete _player;
}


}