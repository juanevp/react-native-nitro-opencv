///
/// ReduceTypes.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#include <cmath>
#if __has_include(<NitroModules/JSIConverter.hpp>)
#include <NitroModules/JSIConverter.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/NitroDefines.hpp>)
#include <NitroModules/NitroDefines.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

namespace margelo::nitro::nitroopencv {

  /**
   * An enum which can be represented as a JavaScript enum (ReduceTypes).
   */
  enum class ReduceTypes {
    REDUCE_SUM      SWIFT_NAME(reduceSum) = 0,
    REDUCE_AVG      SWIFT_NAME(reduceAvg) = 1,
    REDUCE_MAX      SWIFT_NAME(reduceMax) = 2,
    REDUCE_MIN      SWIFT_NAME(reduceMin) = 3,
  } CLOSED_ENUM;

} // namespace margelo::nitro::nitroopencv

namespace margelo::nitro {

  using namespace margelo::nitro::nitroopencv;

  // C++ ReduceTypes <> JS ReduceTypes (enum)
  template <>
  struct JSIConverter<ReduceTypes> final {
    static inline ReduceTypes fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      int enumValue = JSIConverter<int>::fromJSI(runtime, arg);
      return static_cast<ReduceTypes>(enumValue);
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, ReduceTypes arg) {
      int enumValue = static_cast<int>(arg);
      return JSIConverter<int>::toJSI(runtime, enumValue);
    }
    static inline bool canConvert(jsi::Runtime&, const jsi::Value& value) {
      if (!value.isNumber()) {
        return false;
      }
      double integer;
      double fraction = modf(value.getNumber(), &integer);
      if (fraction != 0.0) {
        // It is some kind of floating point number - our enums are ints.
        return false;
      }
      // Check if we are within the bounds of the enum.
      return integer >= 0 && integer <= 3;
    }
  };

} // namespace margelo::nitro
