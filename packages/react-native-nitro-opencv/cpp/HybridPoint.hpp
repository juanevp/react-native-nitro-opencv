#pragma once

#include <opencv2/core/types.hpp>

#include "HybridCvPointSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridPoint : public virtual HybridCvPointSpec
    {
    private:
        cv::Point point;

    public:
        HybridPoint(cv::Point &&point) : HybridCvPointSpec(), point(point) {}

        cv::Point* asPointPtr() {
            return &point;
        }

        cv::Point& asPointRef() {
            return point;
        }

        Point toJsValue() override {
            return Point(point.x, point.y);
        }
    };
}