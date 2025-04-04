///
/// HybridCvPoint2fSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridCvPoint2fSpec.hpp"

namespace margelo::nitro::nitroopencv {

  void HybridCvPoint2fSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("x", &HybridCvPoint2fSpec::getX);
      prototype.registerHybridGetter("y", &HybridCvPoint2fSpec::getY);
      prototype.registerHybridMethod("toJsValue", &HybridCvPoint2fSpec::toJsValue);
    });
  }

} // namespace margelo::nitro::nitroopencv
