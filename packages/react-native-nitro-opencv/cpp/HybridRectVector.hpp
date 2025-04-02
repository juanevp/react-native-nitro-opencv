#pragma once

#include <opencv2/core/mat.hpp>

#include "HybridRectVectorSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridRectVector : public virtual HybridRectVectorSpec
    {
    private:
        std::vector<cv::Rect> vec;

    public:
        HybridRectVector() : HybridObject(TAG) {}
        HybridRectVector(std::vector<cv::Rect> &&vec) : HybridObject(TAG), vec(vec) {}

        std::vector<cv::Rect> &asRectVectorRef()
        {
            return vec;
        }

        std::vector<Rect> toJsValue() override;
        std::shared_ptr<HybridCvRectSpec> copyAt(double index) override;
    };
}