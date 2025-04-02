#pragma once

#include "HybridObjectDetectionSpec.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvPoint2fSpec.hpp"
#include "TemplateMatchModes.hpp"
#include "PhaseCorrelationResult.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridObjectDetection : public HybridObjectDetectionSpec
    {
    public:
        HybridObjectDetection() : HybridObject(TAG) {}

        void matchTemplate(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &templ, const std::shared_ptr<HybridCvMatSpec> &result, TemplateMatchModes method, const std::shared_ptr<HybridCvMatSpec> &mask) override;
        PhaseCorrelationResult phaseCorrelate(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::optional<std::shared_ptr<HybridCvMatSpec>> &window) override;
    };
}