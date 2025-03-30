#pragma once

#include <opencv2/core/mat.hpp>

#include "HybridPoint2fVectorSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridPoint2fVector : public virtual HybridPoint2fVectorSpec
    {
    private:
        std::vector<cv::Point2f> vec;

    public:
        HybridPoint2fVector() = default;
        HybridPoint2fVector(std::vector<cv::Point2f> &&vec) : HybridPoint2fVectorSpec(), vec(vec) {}

        std::vector<cv::Point2f>& asPoint2fVectorRef() {
            return vec;
        }

        std::vector<Point> toJsValue() override;
        std::shared_ptr<HybridCvPoint2fSpec> copyAt(double index) override;
    };
}