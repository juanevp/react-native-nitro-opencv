#pragma once

#include <opencv2/core/types.hpp>

#include "HybridCvRotatedRectSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    // using namespace facebook;

    class HybridRotatedRect : public virtual HybridCvRotatedRectSpec
    {
    private:
        cv::RotatedRect rect;

    public:
        HybridRotatedRect(cv::RotatedRect &&rect) : HybridCvRotatedRectSpec(), rect(rect) {}

        cv::RotatedRect* asRotatedRectPtr() {
            return &rect;
        }

        cv::RotatedRect& asRotatedRectRef() {
            return rect;
        }

        RotatedRect toJsValue() override {
            return RotatedRect(rect.center.x, rect.center.y, rect.size.width, rect.size.height, rect.angle);
        }
    };
}