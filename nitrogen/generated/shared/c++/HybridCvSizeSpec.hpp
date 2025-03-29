///
/// HybridCvSizeSpec.hpp
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

// Forward declaration of `Size` to properly resolve imports.
namespace margelo::nitro::nitroopencv { struct Size; }

#include "Size.hpp"

namespace margelo::nitro::nitroopencv {

  using namespace margelo::nitro;

  /**
   * An abstract base class for `CvSize`
   * Inherit this class to create instances of `HybridCvSizeSpec` in C++.
   * You must explicitly call `HybridObject`'s constructor yourself, because it is virtual.
   * @example
   * ```cpp
   * class HybridCvSize: public HybridCvSizeSpec {
   * public:
   *   HybridCvSize(...): HybridObject(TAG) { ... }
   *   // ...
   * };
   * ```
   */
  class HybridCvSizeSpec: public virtual HybridObject {
    public:
      // Constructor
      explicit HybridCvSizeSpec(): HybridObject(TAG) { }

      // Destructor
      ~HybridCvSizeSpec() override = default;

    public:
      // Properties
      virtual double getWidth() = 0;
      virtual double getHeight() = 0;

    public:
      // Methods
      virtual Size toJsValue() = 0;

    protected:
      // Hybrid Setup
      void loadHybridMethods() override;

    protected:
      // Tag for logging
      static constexpr auto TAG = "CvSize";
  };

} // namespace margelo::nitro::nitroopencv
