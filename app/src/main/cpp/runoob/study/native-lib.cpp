#include "../../../../../../../../Library/Android/sdk/ndk-bundle/platforms/android-9/arch-arm/usr/include/jni.h"
#include <string>

extern "C"
jstring
Java_itcode_com_cdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
