project(NitroOpencv)
cmake_minimum_required(VERSION 3.9.0)

message("BUILDING NitroOpenCV C++")

set (PACKAGE_NAME NitroOpencv)
set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 20)

file(TO_CMAKE_PATH "${NODE_MODULES_DIR}" NODE_MODULES_DIR)

find_package(ReactAndroid REQUIRED CONFIG)
find_package(fbjni REQUIRED CONFIG)

file(REAL_PATH .. PACKAGE_ROOT_DIR)
CMAKE_PATH(APPEND INSTALLOPENCVLOG ${PACKAGE_ROOT_DIR} "install-opencv.log")
message(STATUS "INSTALLOPENCVLOG: ${INSTALLOPENCVLOG}")
if(CMAKE_HOST_WIN32)
  execute_process(
    COMMAND cmd /C "pnpm run install-opencv >${INSTALLOPENCVLOG}" 
    WORKING_DIRECTORY ${PACKAGE_ROOT_DIR}
    RESULT_VARIABLE OpencvInstallResult
    OUTPUT_VARIABLE OpencvInstallOutput
    ERROR_VARIABLE OpencvInstallError  
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_STRIP_TRAILING_WHITESPACE
  )
elseif(CMAKE_HOST_UNIX)
  execute_process(
    COMMAND sh -c "pnpm run install-opencv >${INSTALLOPENCVLOG}" 
    WORKING_DIRECTORY ${PACKAGE_ROOT_DIR}
    RESULT_VARIABLE OpencvInstallResult
    OUTPUT_VARIABLE OpencvInstallOutput
    ERROR_VARIABLE OpencvInstallError  
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_STRIP_TRAILING_WHITESPACE
  )
else()
    message(FATAL_ERROR "Unsupported operating system")
endif()

if(OpencvInstallOutput)
    message(STATUS "pnpm output:\n${OpencvInstallOutput}")
endif()

if(OpencvInstallError)
    message(STATUS "pnpm errors:\n${OpencvInstallError}")
endif()

if (NOT OpencvInstallResult EQUAL 0)
  message(FATAL_ERROR "OpenCV setup failed")
endif()

file(REAL_PATH ../opencv/OpenCV-android-sdk/sdk/native/jni OpenCV_DIR)
message("OpenCV_DIR ${OpenCV_DIR}")
set(OpenCV_STATIC ON)
find_package(OpenCV REQUIRED)
# find_package(OpenCV REQUIRED COMPONENTS OpenCV::opencv_java4)

file(GLOB_RECURSE CppSourceFiles RELATIVE ${CMAKE_SOURCE_DIR}
  "../cpp/*.c"
  "../cpp/*.cpp"
  "src/main/cpp/cpp-adapter.cpp"
)

# Define C++ library and add all sources
add_library(${PACKAGE_NAME} SHARED
        ${CppSourceFiles}
)

# Add Nitrogen specs
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

target_link_libraries(
  ${PACKAGE_NAME}
  ${LOG_LIB}
  android
  fbjni::fbjni
  #OpenCV::opencv_java4
  ${OpenCV_LIBS}
)

# Link all libraries together
if(ReactAndroid_VERSION_MINOR GREATER_EQUAL 76)
  target_link_libraries(
    ${PACKAGE_NAME}
    ReactAndroid::reactnative
  )
else()
  target_link_libraries(
    ${PACKAGE_NAME}
    ReactAndroid::folly_runtime
    ReactAndroid::glog
    ReactAndroid::jsi
    ReactAndroid::reactnativejni
  )
endif()

target_compile_options(
  ${PACKAGE_NAME}
  PRIVATE
  -DLOG_TAG=\"ReactNative\"
  -fexceptions
  -frtti
  -fstack-protector-all
  -Wall
  -Wextra
  -DONANDROID
)