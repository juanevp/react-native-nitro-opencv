#pragma once

#include "HybridColorConversionSpec.hpp"
#include "HybridCvMatSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridColorConversion : public HybridColorConversionSpec
    {
    public:
        HybridColorConversion() : HybridColorConversionSpec() {}

        void cvtColor(const std::shared_ptr<HybridCvMatSpec>& src, const std::shared_ptr<HybridCvMatSpec>& dst, ColorConversionCodes code, std::optional<double> dstCn) override;
        void cvtColorTwoPlane(const std::shared_ptr<HybridCvMatSpec>& src1, const std::shared_ptr<HybridCvMatSpec>& src2, const std::shared_ptr<HybridCvMatSpec>& dst, ColorConversionCodes code) override;
        void demosaicing(const std::shared_ptr<HybridCvMatSpec>& src, const std::shared_ptr<HybridCvMatSpec>& dst, ColorConversionCodes code, std::optional<double> dstCn) override;
   };
}