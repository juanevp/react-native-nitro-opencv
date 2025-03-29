#include <variant>
#include <opencv2/opencv.hpp>

#include "HybridImageFiltering.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvPointSpec.hpp"
#include "HybridCvScalarSpec.hpp"
#include "HybridCvSizeSpec.hpp"
#include "HybridMat.hpp"
#include "HybridScalar.hpp"
#include "utils.hpp"
#include "BorderTypes.hpp"
#include "DataTypes.hpp"

namespace margelo::nitro::nitroopencv
{
    void HybridImageFiltering::bilateralFilter(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double d, double sigmaColor,
                                               double sigmaSpace, BorderTypes borderType)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::bilateralFilter(src_, dst_, d, sigmaColor, sigmaSpace, (int)borderType);
    }

    void HybridImageFiltering::blur(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvSizeSpec> &ksize,
                                    const std::shared_ptr<HybridCvPointSpec> &anchor, BorderTypes borderType)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &ksize_ = asSizeRef(ksize);
        auto &anchor_ = asPointRef(anchor);
        cv::blur(src_, dst_, ksize_, anchor_, (int)borderType);
    }

    void HybridImageFiltering::boxFilter(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DataTypes ddepth,
                                         const std::shared_ptr<HybridCvSizeSpec> &ksize, const std::shared_ptr<HybridCvPointSpec> &anchor, bool normalize, BorderTypes borderType)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &ksize_ = asSizeRef(ksize);
        auto &anchor_ = asPointRef(anchor);
        cv::boxFilter(src_, dst_, (int)ddepth, ksize_, anchor_, normalize, (int)borderType);
    }

    void HybridImageFiltering::buildPyramid(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double maxlevel, BorderTypes borderType)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::buildPyramid(src_, dst_, maxlevel, (int)borderType);
    }

    void HybridImageFiltering::dilate(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &kernel,
                                      const std::shared_ptr<HybridCvPointSpec> &anchor, double iterations, BorderTypes borderType,
                                      const std::shared_ptr<HybridCvScalarSpec> &borderValue)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &kernel_ = asMatRef(kernel);
        auto &anchor_ = asPointRef(anchor);
        auto &borderValue_ = asScalarRef(borderValue);
        cv::dilate(src_, dst_, kernel_, anchor_, iterations, (int)borderType, borderValue_);
    }

    void HybridImageFiltering::erode(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &kernel,
                                     const std::shared_ptr<HybridCvPointSpec> &anchor, double iterations, BorderTypes borderType,
                                     const std::shared_ptr<HybridCvScalarSpec> &borderValue)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &kernel_ = asMatRef(kernel);
        auto &anchor_ = asPointRef(anchor);
        auto &borderValue_ = asScalarRef(borderValue);
        cv::erode(src_, dst_, kernel_, anchor_, iterations, (int)borderType, borderValue_);
    }

    void HybridImageFiltering::filter2D(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double ddepth,
                                        const std::shared_ptr<HybridCvMatSpec> &kernel, const std::shared_ptr<HybridCvPointSpec> &anchor, double delat, BorderTypes borderType)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &kernel_ = asMatRef(kernel);
        auto &anchor_ = asPointRef(anchor);
        cv::filter2D(src_, dst_, ddepth, kernel_, anchor_, delat, (int)borderType);
    }

    void HybridImageFiltering::GaussianBlur(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst,
                                            const std::shared_ptr<HybridCvSizeSpec> &ksize, double sigmaX, std::optional<double> sigmaY, std::optional<BorderTypes> borderType)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &ksize_ = asSizeRef(ksize);
        if (!sigmaY.has_value())
        {
            cv::GaussianBlur(src_, dst_, ksize_, sigmaX);
        }
        else if (!borderType.has_value())
        {
            cv::GaussianBlur(src_, dst_, ksize_, sigmaX, sigmaY.value());
        }
        else
        {
            cv::GaussianBlur(src_, dst_, ksize_, sigmaX, sigmaY.value(), (int)borderType.value());
        }
    }

    std::shared_ptr<HybridCvMatSpec> HybridImageFiltering::getGaborKernel(const std::shared_ptr<HybridCvSizeSpec> &ksize, double sigma, double theta, double lambd,
                                                                          double gamma, double psi, DataTypes ktype)
    {
        auto &ksize_ = asSizeRef(ksize);
        cv::Mat result = cv::getGaborKernel(ksize_, sigma, theta, lambd, gamma, psi, (int)ktype);
        return std::make_shared<HybridMat>(std::move(result));
    }

    std::shared_ptr<HybridCvMatSpec> HybridImageFiltering::getGaussianKernel(double ksize, double sigma, DataTypes ktype)
    {
        cv::Mat result = cv::getGaussianKernel(ksize, sigma, (int)ktype);
        return std::make_shared<HybridMat>(std::move(result));
    }

    std::shared_ptr<HybridCvMatSpec> HybridImageFiltering::getStructuringElement(MorphShapes shape, const std::shared_ptr<HybridCvSizeSpec> &ksize,
                                                                                 const std::optional<std::shared_ptr<HybridCvPointSpec>> &anchor)
    {
        auto &ksize_ = asSizeRef(ksize);
        if (anchor.has_value())
        {
            auto &anchor_ = asPointRef(anchor.value());
            cv::Mat result = cv::getStructuringElement((int)shape, ksize_, anchor_);
            return std::make_shared<HybridMat>(std::move(result));
        }
        else
        {
            cv::Mat result = cv::getStructuringElement((int)shape, ksize_);
            return std::make_shared<HybridMat>(std::move(result));
        }
    }

    void HybridImageFiltering::Laplacian(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DataTypes ddepth, double ksize,
                                         double scale, double delta, BorderTypes borderType)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::Laplacian(src_, dst_, (int)ddepth, ksize, scale, delta, (int)borderType);
    }

    void HybridImageFiltering::medianBlur(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double ksize)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::medianBlur(src_, dst_, ksize);
    }

    std::shared_ptr<HybridCvScalarSpec> HybridImageFiltering::morphologyDefaultBorderValue()
    {
        return std::make_shared<HybridScalar>(cv::morphologyDefaultBorderValue());
    }

    void HybridImageFiltering::morphologyEx(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, MorphTypes op,
                                            const std::shared_ptr<HybridCvMatSpec> &kernel, const std::optional<std::shared_ptr<HybridCvPointSpec>> &anchor,
                                            std::optional<double> iterations, std::optional<BorderTypes> borderType,
                                            const std::optional<std::shared_ptr<HybridCvScalarSpec>> &borderValue)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &kernel_ = asMatRef(kernel);
        if (!anchor.has_value())
            cv::morphologyEx(src_, dst_, (int)op, kernel_);
        else {
            auto &anchor_ = asPointRef(anchor.value());
            if (!iterations.has_value())
                cv::morphologyEx(src_, dst_, (int)op, kernel_, anchor_);
            else if (!borderType.has_value())
                cv::morphologyEx(src_, dst_, (int)op, kernel_, anchor_, (int)iterations.value());
            else if (!borderValue.has_value())
                cv::morphologyEx(src_, dst_, (int)op, kernel_, anchor_, (int)iterations.value(), (int)borderType.value());
            else
            {
                auto &borderValue_ = asScalarRef(borderValue.value());
                cv::morphologyEx(src_, dst_, (int)op, kernel_, anchor_, (int)iterations.value(), (int)borderType.value(), borderValue_);
            }
        }
    }

    void HybridImageFiltering::Sobel(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double ddepth, double dx, double dy,
                                     double ksize, double scale, double delta, BorderTypes borderType)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::Sobel(src_, dst_, ddepth, dx, dy, ksize, scale, delta, (int)borderType);
    }
}