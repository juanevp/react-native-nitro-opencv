#include <variant>
#include <opencv2/opencv.hpp>

#include "HybridObjectDetection.hpp"
#include "HybridMat.hpp"
#include "utils.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvPoint2fSpec.hpp"
#include "HybridPoint.hpp"
#include "TemplateMatchModes.hpp"
#include "PhaseCorrelationResult.hpp"

namespace margelo::nitro::nitroopencv
{
    void HybridObjectDetection::matchTemplate(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &templ,
                                              const std::shared_ptr<HybridCvMatSpec> &result, TemplateMatchModes method, const std::shared_ptr<HybridCvMatSpec> &mask)
    {
        auto &image_ = asMatRef(image);
        auto &templ_ = asMatRef(templ);
        auto &result_ = asMatRef(result);
        auto &mask_ = asMatRef(mask);
        cv::matchTemplate(image_, templ_, result_, (int)method, mask_);
    }

    PhaseCorrelationResult HybridObjectDetection::phaseCorrelate(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2,
                                                                               const std::optional<std::shared_ptr<HybridCvMatSpec>> &window)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &window_ = window.has_value() ? asMatRef(window.value()) : cv::noArray();
        double response = 0;
        cv::Point2f result = cv::phaseCorrelate(src1_, src2_, window_, &response);
        return PhaseCorrelationResult(std::make_shared<HybridPoint2f>(std::move(result)), response);
    }
}