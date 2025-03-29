#pragma once

#include <opencv2/core/types.hpp>

#include "HybridCvPointSpec.hpp"
#include "HybridCvPoint2fSpec.hpp"

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

    class HybridPoint2f : public virtual HybridCvPoint2fSpec
    {
    private:
        cv::Point2f point;

    public:
        HybridPoint2f(cv::Point2f &&point) : HybridCvPoint2fSpec(), point(point) {}

        cv::Point2f* asPoint2fPtr() {
            return &point;
        }

        cv::Point2f& asPoint2fRef() {
            return point;
        }

        Point toJsValue() override {
            return Point(point.x, point.y);
        }
    };

}