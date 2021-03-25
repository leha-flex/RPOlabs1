#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_INFO(...) __android_log_print(ANDROID_LOG_INFO, "chel_ndk", __VA_ARGS__)

#include <C:\Users\DEDLXCK\AndroidStudioProjects\libs\spdlog\include\spdlog\spdlog.h>
#include "C:\Users\DEDLXCK\AndroidStudioProjects\libs\spdlog\include\spdlog\sinks\android_sink.h"

#define SLOG_INFO(...) android_logger->info( __VA_ARGS__ )
auto android_logger = spdlog::android_logger_mt( "android", "rpo_ndk");

extern "C" JNIEXPORT jstring JNICALL
Java_com_pro_rpolabs_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from Me";
    LOG_INFO("Hello from system log %d", 2021);
    SLOG_INFO("Hello from spdlog {}", 2021);
    return env->NewStringUTF(hello.c_str());
}