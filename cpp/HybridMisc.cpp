#include <variant>
#include <opencv2/opencv.hpp>

#include "HybridMisc.hpp"
#include "HybridMat.hpp"
#include "utils.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvPoint2fSpec.hpp"
#include "HybridPoint.hpp"

namespace margelo::nitro::nitroopencv
{
    void HybridMisc::adaptiveThreshold(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double maxValue,
                                       AdaptiveThresholdTypes adaptiveMethod, ThresholdTypes thresholdType, double blockSize, double C)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::adaptiveThreshold(src_, dst_, maxValue, (int)adaptiveMethod, (int)thresholdType, blockSize, C);
    }

    void HybridMisc::distanceTransform(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DistanceTypes distanceType,
                                       DistanceTransformMasks maskSize)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::distanceTransform(src_, dst_, (int)distanceType, (int)maskSize);
    }

    double HybridMisc::floodFill(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &mask, const std::shared_ptr<HybridCvPointSpec> &seedPoint,
                                 const std::shared_ptr<HybridCvScalarSpec> &newVal, const std::optional<std::shared_ptr<HybridCvRectSpec>> &rect, 
                                 const std::shared_ptr<HybridCvScalarSpec> &loDiff, const std::shared_ptr<HybridCvScalarSpec> &upDiff, double flags)
    {
        auto &image_ = asMatRef(image);
        auto &mask_ = asMatRef(mask);
        auto &seedPoint_ = asPointRef(seedPoint);
        auto &newVal_ = asScalarRef(newVal);
        auto *rect_ = rect.has_value() ? &asRectRef(rect.value()) : nullptr;
        auto &loDiff_ = asScalarRef(loDiff);
        auto &upDiff_ = asScalarRef(upDiff);
        return cv::floodFill(image_, mask_, seedPoint_, newVal_, rect_, loDiff_, upDiff_, flags);
    }

    void HybridMisc::integral(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &sum)
    {
        auto &src_ = asMatRef(src);
        auto &sum_ = asMatRef(sum);
        cv::integral(src_, sum_);
    }

    void HybridMisc::threshold(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double thresh, double maxval, double type)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::threshold(src_, dst_, thresh, maxval, type);
    }
}