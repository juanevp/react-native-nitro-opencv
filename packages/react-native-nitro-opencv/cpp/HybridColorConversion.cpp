#include <variant>
#include <opencv2/opencv.hpp>

#include "HybridColorConversion.hpp"
#include "HybridMat.hpp"
#include "utils.hpp"

namespace margelo::nitro::nitroopencv
{
    void HybridColorConversion::cvtColor(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, ColorConversionCodes code, std::optional<double> dstCn)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        if (dstCn.has_value())
            cv::cvtColor(src_, dst_, (int)code, dstCn.value());
        else
            cv::cvtColor(src_, dst_, (int)code);
    }

    void HybridColorConversion::cvtColorTwoPlane(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst, ColorConversionCodes code)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        cv::cvtColorTwoPlane(src1_, src2_, dst_, (int)code);
    }

    void HybridColorConversion::demosaicing(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, ColorConversionCodes code, std::optional<double> dstCn)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        if (dstCn.has_value())
            cv::demosaicing(src_, dst_, (int)code, dstCn.value());
        else
            cv::demosaicing(src_, dst_, (int)code);
    }
}