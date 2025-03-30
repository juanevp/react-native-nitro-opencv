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
        HybridSize(cv::Size &&size) : HybridCvSizeSpec(), size(size) {}

        cv::Size* asSizePtr() {
            return &size;
        }

        cv::Size& asSizeRef() {
            return size;
        }

        Size toJsValue() override {
            return Size(size.width, size.height);
        }
    };
}