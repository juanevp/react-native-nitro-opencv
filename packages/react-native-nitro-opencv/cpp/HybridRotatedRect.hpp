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
        HybridRotatedRect() : HybridObject(TAG) {}
        HybridRotatedRect(cv::RotatedRect &&rect) : HybridObject(TAG), rect(rect) {}

        cv::RotatedRect *asRotatedRectPtr()
        {
            return &rect;
        }

        cv::RotatedRect &asRotatedRectRef()
        {
            return rect;
        }

        virtual double getCenterX() override
        {
            return rect.center.x;
        }

        virtual double getCenterY() override
        {
            return rect.center.y;
        }

        double getWidth() override
        {
            return rect.size.width;
        }

        double getHeight() override
        {
            return rect.size.height;
        }

        double getAngle() override
        {
            return rect.angle;
        }

        RotatedRect toJsValue() override
        {
            return RotatedRect(rect.center.x, rect.center.y, rect.size.width, rect.size.height, rect.angle);
        }
    };
}