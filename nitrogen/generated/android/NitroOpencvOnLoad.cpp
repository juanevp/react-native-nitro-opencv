///
/// NitroOpencvOnLoad.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#ifndef BUILDING_NITROOPENCV_WITH_GENERATED_CMAKE_PROJECT
#error NitroOpencvOnLoad.cpp is not being built with the autogenerated CMakeLists.txt project. Is a different CMakeLists.txt building this?
#endif

#include "NitroOpencvOnLoad.hpp"

#include <jni.h>
#include <fbjni/fbjni.h>
#include <NitroModules/HybridObjectRegistry.hpp>

#include "HybridMat.hpp"
#include "HybridMatVector.hpp"
#include "HybridPoint.hpp"
#include "HybridPointVector.hpp"
#include "HybridPointVectorOfVectors.hpp"
#include "HybridPoint2f.hpp"
#include "HybridPoint2fVector.hpp"
#include "HybridRect.hpp"
#include "HybridRotatedRect.hpp"
#include "HybridRectVector.hpp"
#include "HybridScalar.hpp"
#include "HybridSize.hpp"
#include "HybridObjects.hpp"
#include "HybridCore.hpp"
#include "HybridColorConversion.hpp"
#include "HybridShape.hpp"
#include "HybridObjectDetection.hpp"
#include "HybridMisc.hpp"
#include "HybridImageTransform.hpp"
#include "HybridImageFiltering.hpp"
#include "HybridFeature.hpp"
#include "HybridDrawing.hpp"

namespace margelo::nitro::nitroopencv {

int initialize(JavaVM* vm) {
  using namespace margelo::nitro;
  using namespace margelo::nitro::nitroopencv;
  using namespace facebook;

  return facebook::jni::initialize(vm, [] {
    // Register native JNI methods
    

    // Register Nitro Hybrid Objects
    HybridObjectRegistry::registerHybridObjectConstructor(
      "CvMat",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridMat>,
                      "The HybridObject \"HybridMat\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridMat>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "MatVector",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridMatVector>,
                      "The HybridObject \"HybridMatVector\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridMatVector>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "CvPoint",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridPoint>,
                      "The HybridObject \"HybridPoint\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridPoint>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "PointVector",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridPointVector>,
                      "The HybridObject \"HybridPointVector\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridPointVector>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "PointVectorOfVectors",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridPointVectorOfVectors>,
                      "The HybridObject \"HybridPointVectorOfVectors\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridPointVectorOfVectors>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "CvPoint2f",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridPoint2f>,
                      "The HybridObject \"HybridPoint2f\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridPoint2f>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "Point2fVector",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridPoint2fVector>,
                      "The HybridObject \"HybridPoint2fVector\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridPoint2fVector>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "CvRect",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridRect>,
                      "The HybridObject \"HybridRect\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridRect>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "CvRotatedRect",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridRotatedRect>,
                      "The HybridObject \"HybridRotatedRect\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridRotatedRect>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "RectVector",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridRectVector>,
                      "The HybridObject \"HybridRectVector\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridRectVector>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "CvScalar",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridScalar>,
                      "The HybridObject \"HybridScalar\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridScalar>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "CvSize",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridSize>,
                      "The HybridObject \"HybridSize\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridSize>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "Objects",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridObjects>,
                      "The HybridObject \"HybridObjects\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridObjects>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "Core",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridCore>,
                      "The HybridObject \"HybridCore\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridCore>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "ColorConversion",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridColorConversion>,
                      "The HybridObject \"HybridColorConversion\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridColorConversion>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "Shape",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridShape>,
                      "The HybridObject \"HybridShape\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridShape>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "ObjectDetection",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridObjectDetection>,
                      "The HybridObject \"HybridObjectDetection\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridObjectDetection>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "Misc",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridMisc>,
                      "The HybridObject \"HybridMisc\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridMisc>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "ImageTransform",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridImageTransform>,
                      "The HybridObject \"HybridImageTransform\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridImageTransform>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "ImageFiltering",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridImageFiltering>,
                      "The HybridObject \"HybridImageFiltering\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridImageFiltering>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "Feature",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridFeature>,
                      "The HybridObject \"HybridFeature\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridFeature>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "Drawing",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridDrawing>,
                      "The HybridObject \"HybridDrawing\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridDrawing>();
      }
    );
  });
}

} // namespace margelo::nitro::nitroopencv
