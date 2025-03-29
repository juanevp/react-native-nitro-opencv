///
/// HybridObjectDetectionSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridObjectDetectionSpec.hpp"

namespace margelo::nitro::nitroopencv {

  void HybridObjectDetectionSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("matchTemplate", &HybridObjectDetectionSpec::matchTemplate);
      prototype.registerHybridMethod("phaseCorrelate", &HybridObjectDetectionSpec::phaseCorrelate);
    });
  }

} // namespace margelo::nitro::nitroopencv
