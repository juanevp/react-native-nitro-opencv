#pragma once

#include <opencv2/core/types.hpp>

#include "HybridCvSizeSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridSize : public virtual HybridCvSizeSpec
    {
    private:
        cv::Size size;

    public:
        HybridSize() = default;
        HybridSize(cv::Size &&size) : HybridCvSizeSpec(), size(size) {}

        cv::Size* asSizePtr() {
            return &size;
        }

        cv::Size& asSizeRef() {
            return size;
        }

        double getWidth() override {
            return size.width;
        }

        double getHeight() override {
            return size.height;
        }
  
        Size toJsValue() override {
            return Size(size.width, size.height);
        }
    };
}