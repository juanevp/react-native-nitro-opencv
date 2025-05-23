///
/// HybridCoreSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridCoreSpec.hpp"

namespace margelo::nitro::nitroopencv {

  void HybridCoreSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("absdiff", &HybridCoreSpec::absdiff);
      prototype.registerHybridMethod("add", &HybridCoreSpec::add);
      prototype.registerHybridMethod("addWeighted", &HybridCoreSpec::addWeighted);
      prototype.registerHybridMethod("batchDistance", &HybridCoreSpec::batchDistance);
      prototype.registerHybridMethod("bitwise_and", &HybridCoreSpec::bitwise_and);
      prototype.registerHybridMethod("bitwise_not", &HybridCoreSpec::bitwise_not);
      prototype.registerHybridMethod("bitwise_or", &HybridCoreSpec::bitwise_or);
      prototype.registerHybridMethod("bitwise_xor", &HybridCoreSpec::bitwise_xor);
      prototype.registerHybridMethod("borderInterpolate", &HybridCoreSpec::borderInterpolate);
      prototype.registerHybridMethod("calcCovarMatrix", &HybridCoreSpec::calcCovarMatrix);
      prototype.registerHybridMethod("cartToPolar", &HybridCoreSpec::cartToPolar);
      prototype.registerHybridMethod("cartToPolarN", &HybridCoreSpec::cartToPolarN);
      prototype.registerHybridMethod("checkRange", &HybridCoreSpec::checkRange);
      prototype.registerHybridMethod("compare", &HybridCoreSpec::compare);
      prototype.registerHybridMethod("completeSymm", &HybridCoreSpec::completeSymm);
      prototype.registerHybridMethod("convertFp16", &HybridCoreSpec::convertFp16);
      prototype.registerHybridMethod("convertScaleAbs", &HybridCoreSpec::convertScaleAbs);
      prototype.registerHybridMethod("copyMakeBorder", &HybridCoreSpec::copyMakeBorder);
      prototype.registerHybridMethod("copyTo", &HybridCoreSpec::copyTo);
      prototype.registerHybridMethod("countNonZero", &HybridCoreSpec::countNonZero);
      prototype.registerHybridMethod("crop", &HybridCoreSpec::crop);
      prototype.registerHybridMethod("dct", &HybridCoreSpec::dct);
      prototype.registerHybridMethod("determinant", &HybridCoreSpec::determinant);
      prototype.registerHybridMethod("dft", &HybridCoreSpec::dft);
      prototype.registerHybridMethod("divide", &HybridCoreSpec::divide);
      prototype.registerHybridMethod("eigen", &HybridCoreSpec::eigen);
      prototype.registerHybridMethod("eigenNonSymmetric", &HybridCoreSpec::eigenNonSymmetric);
      prototype.registerHybridMethod("exp", &HybridCoreSpec::exp);
      prototype.registerHybridMethod("extractChannel", &HybridCoreSpec::extractChannel);
      prototype.registerHybridMethod("findNonZero", &HybridCoreSpec::findNonZero);
      prototype.registerHybridMethod("flip", &HybridCoreSpec::flip);
      prototype.registerHybridMethod("gemm", &HybridCoreSpec::gemm);
      prototype.registerHybridMethod("getOptimalDFTSize", &HybridCoreSpec::getOptimalDFTSize);
      prototype.registerHybridMethod("getRotationMatrix2D", &HybridCoreSpec::getRotationMatrix2D);
      prototype.registerHybridMethod("hconcat", &HybridCoreSpec::hconcat);
      prototype.registerHybridMethod("idft", &HybridCoreSpec::idft);
      prototype.registerHybridMethod("inRange", &HybridCoreSpec::inRange);
      prototype.registerHybridMethod("insertChannel", &HybridCoreSpec::insertChannel);
      prototype.registerHybridMethod("invert", &HybridCoreSpec::invert);
      prototype.registerHybridMethod("log", &HybridCoreSpec::log);
      prototype.registerHybridMethod("LUT", &HybridCoreSpec::LUT);
      prototype.registerHybridMethod("magnitude", &HybridCoreSpec::magnitude);
      prototype.registerHybridMethod("magnitudeN", &HybridCoreSpec::magnitudeN);
      prototype.registerHybridMethod("Mahalanobis", &HybridCoreSpec::Mahalanobis);
      prototype.registerHybridMethod("MahalanobisN", &HybridCoreSpec::MahalanobisN);
      prototype.registerHybridMethod("max", &HybridCoreSpec::max);
      prototype.registerHybridMethod("mean", &HybridCoreSpec::mean);
      prototype.registerHybridMethod("meanStdDev", &HybridCoreSpec::meanStdDev);
      prototype.registerHybridMethod("merge", &HybridCoreSpec::merge);
      prototype.registerHybridMethod("min", &HybridCoreSpec::min);
      prototype.registerHybridMethod("minMaxLoc", &HybridCoreSpec::minMaxLoc);
      prototype.registerHybridMethod("mulSpectrums", &HybridCoreSpec::mulSpectrums);
      prototype.registerHybridMethod("multiply", &HybridCoreSpec::multiply);
      prototype.registerHybridMethod("mulTransposed", &HybridCoreSpec::mulTransposed);
      prototype.registerHybridMethod("norm", &HybridCoreSpec::norm);
      prototype.registerHybridMethod("normalize", &HybridCoreSpec::normalize);
      prototype.registerHybridMethod("patchNaNs", &HybridCoreSpec::patchNaNs);
      prototype.registerHybridMethod("perspectiveTransform", &HybridCoreSpec::perspectiveTransform);
      prototype.registerHybridMethod("phase", &HybridCoreSpec::phase);
      prototype.registerHybridMethod("phaseN", &HybridCoreSpec::phaseN);
      prototype.registerHybridMethod("pow", &HybridCoreSpec::pow);
      prototype.registerHybridMethod("PSNR", &HybridCoreSpec::PSNR);
      prototype.registerHybridMethod("reduce", &HybridCoreSpec::reduce);
      prototype.registerHybridMethod("repeat", &HybridCoreSpec::repeat);
      prototype.registerHybridMethod("rotate", &HybridCoreSpec::rotate);
      prototype.registerHybridMethod("scaleAdd", &HybridCoreSpec::scaleAdd);
      prototype.registerHybridMethod("solve", &HybridCoreSpec::solve);
      prototype.registerHybridMethod("solveCubic", &HybridCoreSpec::solveCubic);
      prototype.registerHybridMethod("solvePoly", &HybridCoreSpec::solvePoly);
      prototype.registerHybridMethod("sort", &HybridCoreSpec::sort);
      prototype.registerHybridMethod("sortIdx", &HybridCoreSpec::sortIdx);
      prototype.registerHybridMethod("split", &HybridCoreSpec::split);
      prototype.registerHybridMethod("sqrt", &HybridCoreSpec::sqrt);
      prototype.registerHybridMethod("subtract", &HybridCoreSpec::subtract);
      prototype.registerHybridMethod("sum", &HybridCoreSpec::sum);
      prototype.registerHybridMethod("trace", &HybridCoreSpec::trace);
      prototype.registerHybridMethod("transform", &HybridCoreSpec::transform);
      prototype.registerHybridMethod("transpose", &HybridCoreSpec::transpose);
      prototype.registerHybridMethod("vconcat", &HybridCoreSpec::vconcat);
      prototype.registerHybridMethod("convertTo", &HybridCoreSpec::convertTo);
    });
  }

} // namespace margelo::nitro::nitroopencv
