///
/// HybridDrawingSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridDrawingSpec.hpp"

namespace margelo::nitro::nitroopencv {

  void HybridDrawingSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("arrowedLine", &HybridDrawingSpec::arrowedLine);
      prototype.registerHybridMethod("circle", &HybridDrawingSpec::circle);
      prototype.registerHybridMethod("clipLine", &HybridDrawingSpec::clipLine);
      prototype.registerHybridMethod("drawContours", &HybridDrawingSpec::drawContours);
      prototype.registerHybridMethod("drawMarker", &HybridDrawingSpec::drawMarker);
      prototype.registerHybridMethod("ellipse", &HybridDrawingSpec::ellipse);
      prototype.registerHybridMethod("fillConvexPoly", &HybridDrawingSpec::fillConvexPoly);
      prototype.registerHybridMethod("fillPoly", &HybridDrawingSpec::fillPoly);
      prototype.registerHybridMethod("line", &HybridDrawingSpec::line);
      prototype.registerHybridMethod("polylines", &HybridDrawingSpec::polylines);
      prototype.registerHybridMethod("rectangle", &HybridDrawingSpec::rectangle);
    });
  }

} // namespace margelo::nitro::nitroopencv
