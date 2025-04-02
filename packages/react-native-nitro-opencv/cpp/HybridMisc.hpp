#pragma once

#include "HybridMiscSpec.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvPoint2fSpec.hpp"
#include "TemplateMatchModes.hpp"
#include "PhaseCorrelationResult.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridMisc : public HybridMiscSpec
    {
    public:
        HybridMisc() : HybridObject(TAG) {}

        void adaptiveThreshold(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double maxValue, AdaptiveThresholdTypes adaptiveMethod, ThresholdTypes thresholdType, double blockSize, double C) override;
        void distanceTransform(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DistanceTypes distanceType, DistanceTransformMasks maskSize) override;
        double floodFill(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &mask, const std::shared_ptr<HybridCvPointSpec> &seedPoint, const std::shared_ptr<HybridCvScalarSpec> &newVal, const std::optional<std::shared_ptr<HybridCvRectSpec>> &rect, const std::shared_ptr<HybridCvScalarSpec> &loDiff, const std::shared_ptr<HybridCvScalarSpec> &upDiff, double flags) override;
        void integral(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &sum) override;
        void threshold(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double thresh, double maxval, double type) override;
    };
}