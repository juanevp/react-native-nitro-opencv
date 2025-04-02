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
        HybridRect() : HybridObject(TAG) {}
        HybridRect(cv::Rect &&rect) : HybridObject(TAG), rect(rect) {}

        cv::Rect *asRectPtr()
        {
            return &rect;
        }

        cv::Rect &asRectRef()
        {
            return rect;
        }

        double getX() override
        {
            return rect.x;
        }

        double getY() override
        {
            return rect.y;
        }

        double getWidth() override
        {
            return rect.width;
        }

        double getHeight() override
        {
            return rect.height;
        }

        Rect toJsValue() override
        {
            return Rect(rect.x, rect.y, rect.width, rect.height);
        }
    };
}