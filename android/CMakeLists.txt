project(NitroOpencv)
cmake_minimum_required(VERSION 3.9.0)

message("BUILDING NitroOpenCV C++")

set (PACKAGE_NAME NitroOpenCV)
set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 20)

file(TO_CMAKE_PATH "${NODE_MODULES_DIR}" NODE_MODULES_DIR)

find_package(ReactAndroid REQUIRED CONFIG)
find_package(fbjni REQUIRED CONFIG)
find_package(OpenCV REQUIRED COMPONENTS OpenCV::opencv_java4)

file(GLOB CppSourceFiles "../cpp/*.cpp")

# Define C++ library and add all sources
add_library(${PACKAGE_NAME} SHARED
        src/main/cpp/cpp-adapter.cpp
        ${CppSourceFiles}
)

# Add Nitrogen specs :)
include(${CMAKE_SOURCE_DIR}/../nitrogen/generated/android/NitroOpencv+autolinking.cmake)

# Set up local includes
include_directories(
        "src/main/cpp"
        "../cpp"
        "${NODE_MODULES_DIR}/react-native/React"
        "${NODE_MODULES_DIR}/react-native/React/Base"
        "${NODE_MODULES_DIR}/react-native/ReactCommon"
        "${NODE_MODULES_DIR}/react-native/ReactCommon/jsi"
        "${NODE_MODULES_DIR}/react-native/ReactCommon/callinvoker"
        "${NODE_MODULES_DIR}/react-native/ReactAndroid/src/main/jni/react/turbomodule"
)

find_library(LOG_LIB log)

# Link all libraries together
if(ReactAndroid_VERSION_MINOR GREATER_EQUAL 76)
  target_link_libraries(
    ${PACKAGE_NAME}
    ${LOG_LIB}
    android
    ReactAndroid::reactnative
    fbjni::fbjni
    OpenCV::opencv_java4
  )
else()
  target_link_libraries(
    ${PACKAGE_NAME}
    ${LOG_LIB}
    android
    ReactAndroid::folly_runtime
    ReactAndroid::glog
    ReactAndroid::jsi
    ReactAndroid::reactnativejni
    fbjni::fbjni
    OpenCV::opencv_java4
  )
endif()