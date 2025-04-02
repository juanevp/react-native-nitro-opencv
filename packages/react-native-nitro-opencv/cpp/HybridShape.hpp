#pragma once

#include "HybridShapeSpec.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvRectSpec.hpp"
#include "HybridCvRotatedRectSpec.hpp"
#include "HybridMatVectorSpec.hpp"
#include "HybridPointVectorSpec.hpp"
#include "HybridPointVectorOfVectorsSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridShape : public HybridShapeSpec
    {
    public:
        HybridShape() : HybridObject(TAG) {}

        void approxPolyDP(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorSpec>> &curve, const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridPointVectorSpec>> &approxCurve, double epsilon, bool closed) override;
        double arcLength(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorSpec>> &curve, bool closed) override;
        std::shared_ptr<HybridCvRectSpec> boundingRect(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorSpec>> &array) override;
        double connectedComponents(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &labels) override;
        double connectedComponentsWithStats(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &labels, const std::shared_ptr<HybridCvMatSpec> &stats, const std::shared_ptr<HybridCvMatSpec> &centroids) override;
        double contourArea(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorSpec>> &contour, std::optional<bool> oriented) override;
        void convexHull(const std::shared_ptr<HybridCvMatSpec> &points, const std::shared_ptr<HybridCvMatSpec> &hull) override;
        void convexityDefects(const std::shared_ptr<HybridCvMatSpec> &contour, const std::shared_ptr<HybridCvMatSpec> &convexHull, const std::shared_ptr<HybridCvMatSpec> &convexityDefects) override;
        void findContours(const std::shared_ptr<HybridCvMatSpec> &image, const std::variant<std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorOfVectorsSpec>> &contours, RetrievalModes mode, ContourApproximationModes method) override;
        void fitLine(const std::shared_ptr<HybridCvMatSpec> &points, const std::shared_ptr<HybridCvMatSpec> &line, DistanceTypes disType, double param, double reps, double aeps) override;
        bool isContourConvex(const std::shared_ptr<HybridCvMatSpec> &contour) override;
        double matchShapes(const std::shared_ptr<HybridCvMatSpec> &contour1, const std::shared_ptr<HybridCvMatSpec> &contour2, ShapeMatchModes method, double parameter) override;
        std::shared_ptr<HybridCvRotatedRectSpec> minAreaRect(const std::shared_ptr<HybridCvMatSpec> &points) override;
    };
}