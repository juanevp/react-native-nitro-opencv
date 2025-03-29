///
/// HybridCvScalarSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridCvScalarSpec.hpp"

namespace margelo::nitro::nitroopencv {

  void HybridCvScalarSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("a", &HybridCvScalarSpec::getA);
      prototype.registerHybridGetter("b", &HybridCvScalarSpec::getB);
      prototype.registerHybridGetter("c", &HybridCvScalarSpec::getC);
      prototype.registerHybridGetter("d", &HybridCvScalarSpec::getD);
      prototype.registerHybridMethod("toJsValue", &HybridCvScalarSpec::toJsValue);
    });
  }

} // namespace margelo::nitro::nitroopencv
