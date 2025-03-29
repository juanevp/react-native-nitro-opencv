///
/// HybridMatVectorSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridMatVectorSpec.hpp"

namespace margelo::nitro::nitroopencv {

  void HybridMatVectorSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("toJsValue", &HybridMatVectorSpec::toJsValue);
      prototype.registerHybridMethod("copyAt", &HybridMatVectorSpec::copyAt);
    });
  }

} // namespace margelo::nitro::nitroopencv
