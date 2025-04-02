#pragma once

#include "HybridFeatureSpec.hpp"
#include "HybridPointVectorSpec.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvSizeSpec.hpp"
#include "DecompTypes.hpp"
#include "InterpolationFlags.hpp"
#include "BorderTypes.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridFeature : public HybridFeatureSpec
    {
    public:
        HybridFeature() : HybridObject(TAG) {}

        void Canny(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &edges, double threshold1, double threshold2) override;
        void cornerHarris(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double blockSize, double ksize, double k) override;
        void cornerMinEigenVal(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double blockSize) override;
        void goodFeaturesToTrack(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &corners, double maxCorners, double qualityLevel, double minDistance) override;
        void HoughCircles(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &circles, HoughModes method, double dp, double minDist, std::optional<double> param1, std::optional<double> param2) override;
        void HoughLines(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &lines, double rho, double theta, double threshold) override;
        void HoughLinesP(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &lines, double rho, double theta, double threshold) override;
    };
}