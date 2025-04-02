#pragma once

#include "HybridDrawingSpec.hpp"
#include "HybridPointVectorSpec.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvSizeSpec.hpp"
#include "DecompTypes.hpp"
#include "InterpolationFlags.hpp"
#include "LineTypes.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridDrawing : public HybridDrawingSpec
    {
    public:
        HybridDrawing() : HybridObject(TAG) {}

        void arrowedLine(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &pt1, const std::shared_ptr<HybridCvPointSpec> &pt2, const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes line_type) override;
        void circle(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &center, double radius, const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes line_type) override;
        bool clipLine(const std::shared_ptr<HybridCvSizeSpec> &imgSize, const std::shared_ptr<HybridCvPointSpec> &pt1, const std::shared_ptr<HybridCvPointSpec> &pt2) override;
        void drawContours(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridMatVectorSpec> &contours, double contourIdx, const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes lineType) override;
        void drawMarker(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &position, const std::shared_ptr<HybridCvScalarSpec> &color, MarkerTypes markerType, double markerSize, double thickness, LineTypes line_type) override;
        void ellipse(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &center, const std::shared_ptr<HybridCvSizeSpec> &axes, double angle, double startAngle, double endAngle, const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes lineType) override;
        void fillConvexPoly(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridMatVectorSpec> &pts, const std::shared_ptr<HybridCvScalarSpec> &color, LineTypes lineType) override;
        void fillPoly(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridMatVectorSpec> &pts, const std::shared_ptr<HybridCvScalarSpec> &color, LineTypes lineType) override;
        void line(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &pt1, const std::shared_ptr<HybridCvPointSpec> &pt2, const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes lineType) override;
        void polylines(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridMatVectorSpec> &pts, bool isClosed, const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes lineType) override;
        void rectangle(const std::shared_ptr<HybridCvMatSpec> &img, const std::shared_ptr<HybridCvPointSpec> &pt1, const std::shared_ptr<HybridCvPointSpec> &pt2, const std::shared_ptr<HybridCvScalarSpec> &color, double thickness, LineTypes lineType) override;
    };
}