#pragma once

#include "HybridImageTransformSpec.hpp"
#include "HybridPointVectorSpec.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvSizeSpec.hpp"
#include "DecompTypes.hpp"
#include "InterpolationFlags.hpp"
#include "BorderTypes.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridImageTransform : public HybridImageTransformSpec
    {
    public:
        HybridImageTransform() : HybridObject(TAG) {}

        std::shared_ptr<HybridCvMatSpec> getPerspectiveTransform(const std::shared_ptr<HybridPointVectorSpec> &src, const std::shared_ptr<HybridPointVectorSpec> &dst, DecompTypes solveMethod) override;
        void warpAffine(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &M, const std::shared_ptr<HybridCvSizeSpec> &dsize) override;
        void warpPerspective(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &M, const std::shared_ptr<HybridCvSizeSpec> &size, InterpolationFlags flags, BorderTypes borderMode, const std::shared_ptr<HybridCvScalarSpec> &borderValue) override;
    };
}