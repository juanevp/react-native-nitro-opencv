///
/// HybridObjectsSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridObjectsSpec.hpp"

namespace margelo::nitro::nitroopencv {

  void HybridObjectsSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("createMat", &HybridObjectsSpec::createMat);
      prototype.registerHybridMethod("createMatVector", &HybridObjectsSpec::createMatVector);
      prototype.registerHybridMethod("createPoint", &HybridObjectsSpec::createPoint);
      prototype.registerHybridMethod("createPointVector", &HybridObjectsSpec::createPointVector);
      prototype.registerHybridMethod("createPointVectorOfVectors", &HybridObjectsSpec::createPointVectorOfVectors);
      prototype.registerHybridMethod("createPoint2f", &HybridObjectsSpec::createPoint2f);
      prototype.registerHybridMethod("createPoint2fVector", &HybridObjectsSpec::createPoint2fVector);
      prototype.registerHybridMethod("createRange", &HybridObjectsSpec::createRange);
      prototype.registerHybridMethod("createRangeAll", &HybridObjectsSpec::createRangeAll);
      prototype.registerHybridMethod("createRect", &HybridObjectsSpec::createRect);
      prototype.registerHybridMethod("createRectVector", &HybridObjectsSpec::createRectVector);
      prototype.registerHybridMethod("createRotatedRect", &HybridObjectsSpec::createRotatedRect);
      prototype.registerHybridMethod("createSize", &HybridObjectsSpec::createSize);
      prototype.registerHybridMethod("createScalar", &HybridObjectsSpec::createScalar);
      prototype.registerHybridMethod("arrayBufferToMat", &HybridObjectsSpec::arrayBufferToMat);
      prototype.registerHybridMethod("base64ToMat", &HybridObjectsSpec::base64ToMat);
      prototype.registerHybridMethod("matToArrayBuffer", &HybridObjectsSpec::matToArrayBuffer);
    });
  }

} // namespace margelo::nitro::nitroopencv
