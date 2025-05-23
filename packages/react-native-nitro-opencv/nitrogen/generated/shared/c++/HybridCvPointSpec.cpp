///
/// HybridCvPointSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridCvPointSpec.hpp"

namespace margelo::nitro::nitroopencv {

  void HybridCvPointSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("x", &HybridCvPointSpec::getX);
      prototype.registerHybridGetter("y", &HybridCvPointSpec::getY);
      prototype.registerHybridMethod("toJsValue", &HybridCvPointSpec::toJsValue);
    });
  }

} // namespace margelo::nitro::nitroopencv
