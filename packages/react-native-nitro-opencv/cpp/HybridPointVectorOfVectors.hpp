#pragma once

#include <opencv2/core/mat.hpp>

#include "HybridPointVectorOfVectorsSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridPointVectorOfVectors : public virtual HybridPointVectorOfVectorsSpec
    {
    private:
        std::vector<std::vector<cv::Point>> vec;

    public:
        HybridPointVectorOfVectors(std::vector<std::vector<cv::Point>> &&vec) : HybridPointVectorOfVectorsSpec(), vec(vec) {}

        std::vector<std::vector<cv::Point>>& asPointVectorOfVectorsRef() {
            return vec;
        }

        std::vector<std::vector<Point>> toJsValue() override;
        std::shared_ptr<HybridPointVectorSpec> copyAt(double index) override;
    };
}