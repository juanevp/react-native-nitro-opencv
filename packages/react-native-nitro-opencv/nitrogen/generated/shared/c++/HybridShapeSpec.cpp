///
/// HybridShapeSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridShapeSpec.hpp"

namespace margelo::nitro::nitroopencv {

  void HybridShapeSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("approxPolyDP", &HybridShapeSpec::approxPolyDP);
      prototype.registerHybridMethod("arcLength", &HybridShapeSpec::arcLength);
      prototype.registerHybridMethod("boundingRect", &HybridShapeSpec::boundingRect);
      prototype.registerHybridMethod("connectedComponents", &HybridShapeSpec::connectedComponents);
      prototype.registerHybridMethod("connectedComponentsWithStats", &HybridShapeSpec::connectedComponentsWithStats);
      prototype.registerHybridMethod("contourArea", &HybridShapeSpec::contourArea);
      prototype.registerHybridMethod("convexHull", &HybridShapeSpec::convexHull);
      prototype.registerHybridMethod("convexityDefects", &HybridShapeSpec::convexityDefects);
      prototype.registerHybridMethod("findContours", &HybridShapeSpec::findContours);
      prototype.registerHybridMethod("fitLine", &HybridShapeSpec::fitLine);
      prototype.registerHybridMethod("isContourConvex", &HybridShapeSpec::isContourConvex);
      prototype.registerHybridMethod("matchShapes", &HybridShapeSpec::matchShapes);
      prototype.registerHybridMethod("minAreaRect", &HybridShapeSpec::minAreaRect);
    });
  }

} // namespace margelo::nitro::nitroopencv
