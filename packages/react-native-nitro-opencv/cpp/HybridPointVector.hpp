#pragma once

#include <opencv2/core/mat.hpp>

#include "HybridPointVectorSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridPointVector : public virtual HybridPointVectorSpec
    {
    private:
        std::vector<cv::Point> vec;

    public:
        HybridPointVector(std::vector<cv::Point> &&vec) : HybridPointVectorSpec(), vec(vec) {}

        std::vector<cv::Point>& asPointVectorRef() {
            return vec;
        }

        std::vector<Point> toJsValue() override;
        std::shared_ptr<HybridCvPointSpec> copyAt(double index) override;
    };
}