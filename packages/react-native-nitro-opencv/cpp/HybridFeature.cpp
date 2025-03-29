#include <variant>
#include <opencv2/opencv.hpp>

#include "HybridFeature.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvPointSpec.hpp"
#include "HybridCvScalarSpec.hpp"
#include "HybridCvSizeSpec.hpp"
#include "HybridMat.hpp"
#include "HybridScalar.hpp"
#include "utils.hpp"

namespace margelo::nitro::nitroopencv
{
    void HybridFeature::Canny(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &edges, double threshold1, double threshold2)
    {
        auto &image_ = asMatRef(image);
        auto &edges_ = asMatRef(edges);
        cv::Canny(image_, edges_, threshold1, threshold2);
    }

    void HybridFeature::cornerHarris(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double blockSize, double ksize, double k)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::cornerHarris(src_, dst_, blockSize, ksize, k);
    }

    void HybridFeature::cornerMinEigenVal(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double blockSize)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::cornerMinEigenVal(src_, dst_, blockSize);
    }

    void HybridFeature::goodFeaturesToTrack(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &corners, double maxCorners,
                                            double qualityLevel, double minDistance)
    {
        auto &image_ = asMatRef(image);
        auto &corners_ = asMatRef(corners);
        cv::goodFeaturesToTrack(image_, corners_, maxCorners, qualityLevel, minDistance);
    }

    void HybridFeature::HoughCircles(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &circles, HoughModes method,
                                     double dp, double minDist, std::optional<double> param1, std::optional<double> param2)
    {
        auto &image_ = asMatRef(image);
        auto &circles_ = asMatRef(circles);
        if (!param1.has_value())
            cv::HoughCircles(image_, circles_, (int)method, dp, minDist);
        else if (!param2.has_value())
            cv::HoughCircles(image_, circles_, (int)method, dp, minDist, param1.value());
        else
            cv::HoughCircles(image_, circles_, (int)method, dp, minDist, param1.value(), param2.value());
    }

    void HybridFeature::HoughLines(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &lines, double rho, double theta, double threshold)
    {
        auto &image_ = asMatRef(image);
        auto &lines_ = asMatRef(lines);
        cv::HoughLines(image_, lines_, rho, theta, threshold);
    }

    void HybridFeature::HoughLinesP(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &lines, double rho, double theta, double threshold)
    {
        auto &image_ = asMatRef(image);
        auto &lines_ = asMatRef(lines);
        cv::HoughLinesP(image_, lines_, rho, theta, threshold);
    }
}