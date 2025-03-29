///
/// HybridCvSizeSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridCvSizeSpec.hpp"

namespace margelo::nitro::nitroopencv {

  void HybridCvSizeSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("width", &HybridCvSizeSpec::getWidth);
      prototype.registerHybridGetter("height", &HybridCvSizeSpec::getHeight);
      prototype.registerHybridMethod("toJsValue", &HybridCvSizeSpec::toJsValue);
    });
  }

} // namespace margelo::nitro::nitroopencv
