#include <jni.h>
#include "NitroOpencvOnLoad.hpp"
//#include <android/log.h>

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  //__android_log_print(ANDROID_LOG_INFO, "react-native-nitro-opencv", "Entering JNI_OnLoad");
  return margelo::nitro::nitroopencv::initialize(vm);
  //__android_log_print(ANDROID_LOG_INFO, "react-native-nitro-opencv", "Exiting JNI_OnLoad");
}
