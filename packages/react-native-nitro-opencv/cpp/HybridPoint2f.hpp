#pragma once

#include <opencv2/core/types.hpp>

#include "HybridCvPoint2fSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridPoint2f : public virtual HybridCvPoint2fSpec
    {
    private:
        cv::Point2f point;

    public:
        HybridPoint2f() : HybridObject(TAG) {}
        HybridPoint2f(cv::Point2f &&point) : HybridObject(TAG), point(point) {}

        cv::Point2f *asPoint2fPtr()
        {
            return &point;
        }

        cv::Point2f &asPoint2fRef()
        {
            return point;
        }

        double getX() override
        {
            return point.x;
        }

        double getY() override
        {
            return point.y;
        }

        Point toJsValue() override
        {
            return Point(point.x, point.y);
        }
    };

}