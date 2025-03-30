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
        HybridPoint() = default;
        HybridPoint(cv::Point &&point) : HybridCvPointSpec(), point(point) {}

        cv::Point* asPointPtr() {
            return &point;
        }

        cv::Point& asPointRef() {
            return point;
        }

        double getX() override {
            return point.x;
        }
        
        double getY() override {
            return point.y;
        }
  

        Point toJsValue() override {
            return Point(point.x, point.y);
        }
    };
}