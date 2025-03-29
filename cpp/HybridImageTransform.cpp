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