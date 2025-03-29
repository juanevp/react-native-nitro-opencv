#include <variant>
#include <opencv2/opencv.hpp>

#include "HybridDrawing.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvPointSpec.hpp"
#include "HybridCvScalarSpec.hpp"
#include "HybridCvSizeSpec.hpp"
#include "HybridMat.hpp"
#include "LineTypes.hpp"
#include "utils.hpp"

namespace margelo::nitro::nitroopencv
{
    void HybridDrawing::arrowedLine(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &pt1, const std::shared_ptr<HybridCvPointSpec> &pt2,
                                    const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes line_type)
    {
        auto &img_ = asMatRef(img);
        auto &pt1_ = asPointRef(pt1);
        auto &pt2_ = asPointRef(pt2);
        auto &color_ = asScalarRef(color);
        cv::arrowedLine(img_, pt1_, pt2_, color_, thickness, (int)line_type);
    }

    void HybridDrawing::circle(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &center, double radius,
                               const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes line_type)
    {
        auto &img_ = asMatRef(img);
        auto &center_ = asPointRef(center);
        auto &color_ = asScalarRef(color);
        cv::circle(img_, center_, radius, color_, thickness, (int)line_type);
    }

    bool HybridDrawing::clipLine(const std::shared_ptr<HybridCvSizeSpec> &imgSize, const std::shared_ptr<HybridCvPointSpec> &pt1, const std::shared_ptr<HybridCvPointSpec> &pt2)
    {
        auto &imgSize_ = asSizeRef(imgSize);
        auto &pt1_ = asPointRef(pt1);
        auto &pt2_ = asPointRef(pt2);
        return cv::clipLine(imgSize_, pt1_, pt2_);
    }

    void HybridDrawing::drawContours(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridMatVectorSpec> &contours, double contourIdx,
                                     const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes line_type)
    {
        auto &image_ = asMatRef(image);
        auto &contours_ = asMatVectorRef(contours);
        auto &color_ = asScalarRef(color);
        cv::drawContours(image_, contours_, contourIdx, color_, thickness, (int)line_type);
    }

    void HybridDrawing::drawMarker(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &position,
                                   const std::shared_ptr<HybridCvScalarSpec> &color, MarkerTypes markerType, double markerSize, double thickness, LineTypes line_type)
    {
        auto &img_ = asMatRef(img);
        auto &position_ = asPointRef(position);
        auto &color_ = asScalarRef(color);
        cv::drawMarker(img_, position_, color_, (int)markerType, markerSize, thickness, (int)line_type);
    }

    void HybridDrawing::ellipse(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &center, const std::shared_ptr<HybridCvSizeSpec> &axes,
                                double angle, double startAngle, double endAngle, const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes line_type)
    {
        auto &img_ = asMatRef(img);
        auto &center_ = asPointRef(center);
        auto &axes_ = asSizeRef(axes);
        auto &color_ = asScalarRef(color);
        cv::ellipse(img_, center_, axes_, angle, startAngle, endAngle, color_, thickness, (int)line_type);
    }

    void HybridDrawing::fillConvexPoly(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridMatVectorSpec> &pts,
                                       const std::shared_ptr<HybridCvScalarSpec> &color, LineTypes line_type)
    {
        auto &img_ = asMatRef(img);
        auto &pts_ = asMatVectorRef(pts);
        auto &color_ = asScalarRef(color);
        cv::fillConvexPoly(img_, pts_, color_, (int)line_type);
    }

    void HybridDrawing::fillPoly(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridMatVectorSpec> &pts,
                                 const std::shared_ptr<HybridCvScalarSpec> &color, LineTypes line_type)
    {
        auto &img_ = asMatRef(img);
        auto &pts_ = asMatVectorRef(pts);
        auto &color_ = asScalarRef(color);
        cv::fillPoly(img_, pts_, color_, (int)line_type);
    }

    void HybridDrawing::line(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &pt1, const std::shared_ptr<HybridCvPointSpec> &pt2,
                             const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes line_type)
    {
        auto &img_ = asMatRef(img);
        auto &pt1_ = asPointRef(pt1);
        auto &pt2_ = asPointRef(pt2);
        auto &color_ = asScalarRef(color);
        cv::line(img_, pt1_, pt2_, color_, thickness, (int)line_type);
    }

    void HybridDrawing::polylines(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridMatVectorSpec> &pts, bool isClosed,
                                  const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes line_type)
    {
        auto &img_ = asMatRef(img);
        auto &pts_ = asMatVectorRef(pts);
        auto &color_ = asScalarRef(color);
        cv::polylines(img_, pts_, isClosed, color_, thickness, (int)line_type);
    }

    void HybridDrawing::rectangle(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &pt1, const std::shared_ptr<HybridCvPointSpec> &pt2,
                                  const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes line_type)
    {
        auto &img_ = asMatRef(img);
        auto &pt1_ = asPointRef(pt1);
        auto &pt2_ = asPointRef(pt2);
        auto &color_ = asScalarRef(color);
        cv::rectangle(img_, pt1_, pt2_, color_, thickness, (int)line_type);
    }
}