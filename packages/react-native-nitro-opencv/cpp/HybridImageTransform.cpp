#include <variant>
#include <opencv2/opencv.hpp>

#include "HybridImageTransform.hpp"
#include "HybridMat.hpp"
#include "utils.hpp"

namespace margelo::nitro::nitroopencv
{
    std::shared_ptr<HybridCvMatSpec> HybridImageTransform::getPerspectiveTransform(const std::shared_ptr<HybridPointVectorSpec> &src,
                                                                                   const std::shared_ptr<HybridPointVectorSpec> &dst, DecompTypes solveMethod)
    {
        auto &src_ = asPointVectorRef(src);
        auto &dst_ = asPointVectorRef(dst);
        cv::Mat result = cv::getPerspectiveTransform(src_, dst_, (int)solveMethod);
        return std::make_shared<HybridMat>(std::move(result));
    }

    void HybridImageTransform::resize(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst,
                                      const std::shared_ptr<HybridCvSizeSpec> &dsize, std::optional<double> fx, std::optional<double> fy,
                                      std::optional<InterpolationFlags> flags)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &dsize_ = asSizeRef(dsize);
        cv::resize(src_, dst_, dsize_, fx.value_or(0), fy.value_or(0), (int)flags.value_or(InterpolationFlags::INTER_LINEAR));
    }

    void HybridImageTransform::resizeTo(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double width, double height,
                                        std::optional<InterpolationFlags> flags)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::resize(src_, dst_, cv::Size(width, height), 0, 0, (int)flags.value_or(InterpolationFlags::INTER_LINEAR));
    }

    void HybridImageTransform::resizeByScale(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double fx, double fy,
                                             std::optional<InterpolationFlags> flags)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::resize(src_, dst_, cv::Size(), fx, fy, (int)flags.value_or(InterpolationFlags::INTER_LINEAR));
    }

    void HybridImageTransform::warpAffine(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst,
                                          const std::shared_ptr<HybridCvMatSpec> &M, const std::shared_ptr<HybridCvSizeSpec> &dsize)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &M_ = asMatRef(M);
        auto &dsize_ = asSizeRef(dsize);
        cv::warpAffine(src_, dst_, M_, dsize_);
    }

    void HybridImageTransform::warpPerspective(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst,
                                               const std::shared_ptr<HybridCvMatSpec> &M, const std::shared_ptr<HybridCvSizeSpec> &size, InterpolationFlags flags,
                                               BorderTypes borderMode, const std::shared_ptr<HybridCvScalarSpec> &borderValue)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &M_ = asMatRef(M);
        auto &size_ = asSizeRef(size);
        auto &borderValue_ = asScalarRef(borderValue);

        cv::warpPerspective(src_, dst_, M_, size_, (int)flags, (int)borderMode, borderValue_);
    }
}