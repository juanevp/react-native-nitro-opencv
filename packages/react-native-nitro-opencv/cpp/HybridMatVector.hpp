#pragma once

#include <opencv2/core/mat.hpp>

#include "HybridMatVectorSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridMatVector : public virtual HybridMatVectorSpec
    {
    private:
        std::vector<cv::Mat> vec;

    public:
        HybridMatVector() : HybridObject(TAG) {}
        HybridMatVector(std::vector<cv::Mat> &&vec) : HybridObject(TAG), vec(vec) {}

        std::vector<cv::Mat> &asMatVectorRef()
        {
            return vec;
        }

        std::vector<MatInfo> toJsValue() override;
        std::shared_ptr<HybridCvMatSpec> copyAt(double index) override;
    };
}