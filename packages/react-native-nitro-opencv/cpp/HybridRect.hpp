#pragma once

#include <opencv2/core/types.hpp>

#include "HybridCvRectSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    // using namespace facebook;

    class HybridRect : public virtual HybridCvRectSpec
    {
    private:
        cv::Rect rect;

    public:
    HybridRect(cv::Rect &&rect) : HybridCvRectSpec(), rect(rect) {}

        cv::Rect* asRectPtr() {
            return &rect;
        }

        cv::Rect& asRectRef() {
            return rect;
        }

        Rect toJsValue() override {
            return Rect(rect.x, rect.y, rect.width, rect.height);
        }
    };
}