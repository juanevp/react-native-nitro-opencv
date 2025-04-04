///
/// HybridCvRangeSpec.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/HybridObject.hpp>)
#include <NitroModules/HybridObject.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

// Forward declaration of `Range` to properly resolve imports.
namespace margelo::nitro::nitroopencv { struct Range; }

#include "Range.hpp"

namespace margelo::nitro::nitroopencv {

  using namespace margelo::nitro;

  /**
   * An abstract base class for `CvRange`
   * Inherit this class to create instances of `HybridCvRangeSpec` in C++.
   * You must explicitly call `HybridObject`'s constructor yourself, because it is virtual.
   * @example
   * ```cpp
   * class HybridCvRange: public HybridCvRangeSpec {
   * public:
   *   HybridCvRange(...): HybridObject(TAG) { ... }
   *   // ...
   * };
   * ```
   */
  class HybridCvRangeSpec: public virtual HybridObject {
    public:
      // Constructor
      explicit HybridCvRangeSpec(): HybridObject(TAG) { }

      // Destructor
      ~HybridCvRangeSpec() override = default;

    public:
      // Properties
      virtual double getStart() = 0;
      virtual double getEnd() = 0;

    public:
      // Methods
      virtual bool empty() = 0;
      virtual double size() = 0;
      virtual Range toJsValue() = 0;

    protected:
      // Hybrid Setup
      void loadHybridMethods() override;

    protected:
      // Tag for logging
      static constexpr auto TAG = "CvRange";
  };

} // namespace margelo::nitro::nitroopencv
