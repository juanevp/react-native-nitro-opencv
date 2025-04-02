#pragma once

#include "HybridImageFilteringSpec.hpp"
#include "HybridPointVectorSpec.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvSizeSpec.hpp"
#include "DecompTypes.hpp"
#include "InterpolationFlags.hpp"
#include "BorderTypes.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridImageFiltering : public HybridImageFilteringSpec
    {
    public:
        HybridImageFiltering() : HybridObject(TAG) {}

        void bilateralFilter(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double d, double sigmaColor, double sigmaSpace, BorderTypes borderType) override;
        void blur(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvSizeSpec> &ksize, const std::shared_ptr<HybridCvPointSpec> &anchor, BorderTypes borderType) override;
        void boxFilter(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DataTypes ddepth, const std::shared_ptr<HybridCvSizeSpec> &ksize, const std::shared_ptr<HybridCvPointSpec> &anchor, bool normalize, BorderTypes borderType) override;
        void buildPyramid(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double maxlevel, BorderTypes borderType) override;
        void dilate(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &kernel, const std::shared_ptr<HybridCvPointSpec> &anchor, double iterations, BorderTypes borderType, const std::shared_ptr<HybridCvScalarSpec> &borderValue) override;
        void erode(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &kernel, const std::shared_ptr<HybridCvPointSpec> &anchor, double iterations, BorderTypes borderType, const std::shared_ptr<HybridCvScalarSpec> &borderValue) override;
        void filter2D(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double ddepth, const std::shared_ptr<HybridCvMatSpec> &kernel, const std::shared_ptr<HybridCvPointSpec> &anchor, double delat, BorderTypes borderType) override;
        void GaussianBlur(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvSizeSpec> &ksize, double sigmaX, std::optional<double> sigmaY, std::optional<BorderTypes> borderType) override;
        std::shared_ptr<HybridCvMatSpec> getGaborKernel(const std::shared_ptr<HybridCvSizeSpec> &ksize, double sigma, double theta, double lambd, double gamma, double psi, DataTypes ktype) override;
        std::shared_ptr<HybridCvMatSpec> getGaussianKernel(double ksize, double sigma, DataTypes ktype) override;
        std::shared_ptr<HybridCvMatSpec> getStructuringElement(MorphShapes shape, const std::shared_ptr<HybridCvSizeSpec> &ksize, const std::optional<std::shared_ptr<HybridCvPointSpec>> &anchor) override;
        void Laplacian(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DataTypes ddepth, double ksize, double scale, double delta, BorderTypes borderType) override;
        void medianBlur(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double ksize) override;
        std::shared_ptr<HybridCvScalarSpec> morphologyDefaultBorderValue() override;
        void morphologyEx(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, MorphTypes op, const std::shared_ptr<HybridCvMatSpec> &kernel, const std::optional<std::shared_ptr<HybridCvPointSpec>> &anchor, std::optional<double> iterations, std::optional<BorderTypes> borderType, const std::optional<std::shared_ptr<HybridCvScalarSpec>> &borderValue) override;
        void Sobel(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double ddepth, double dx, double dy, double ksize, double scale, double delta, BorderTypes borderType) override;
    };
}