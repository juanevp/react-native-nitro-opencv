#include <variant>
#include <opencv2/opencv.hpp>

#include "HybridShape.hpp"
#include "HybridRect.hpp"
#include "HybridRotatedRect.hpp"
#include "utils.hpp"

namespace margelo::nitro::nitroopencv
{
    void HybridShape::approxPolyDP(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorSpec>> &curve,
                                   const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridPointVectorSpec>> &approxCurve, double epsilon, bool closed)
    {
        auto &input = std::visit([](auto&& arg) -> cv::InputArray {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                return asMatRef(arg);
            } 
            else if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                return asMatVectorRef(arg);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ {
                return asPointVectorRef(arg);
            } 
        }, curve);

        auto &output = std::visit([](auto&& arg) -> cv::OutputArray {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                return asMatRef(arg);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ {
                return asPointVectorRef(arg);
            } 
        }, approxCurve);

        cv::approxPolyDP(input, output, epsilon, closed);
    }

    double HybridShape::arcLength(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorSpec>> &curve,
                                  bool closed)
    {
        auto &input = std::visit([](auto&& arg) -> cv::InputArray {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                return asMatRef(arg);
            } 
            else if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                return asMatVectorRef(arg);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ {
                return asPointVectorRef(arg);
            } 
        }, curve);

        return cv::arcLength(input, closed);
    }

    std::shared_ptr<HybridCvRectSpec> HybridShape::boundingRect(
        const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorSpec>> &array)
    {
        auto &input = std::visit([](auto&& arg) -> cv::InputArray {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                return asMatRef(arg);
            } 
            else if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                return asMatVectorRef(arg);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ {
                return asPointVectorRef(arg);
            } 
        }, array);

        return std::make_shared<HybridRect>(cv::boundingRect(input));
    }

    double HybridShape::connectedComponents(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &labels)
    {
        auto &image_ = asMatRef(image);
        auto &labels_ = asMatRef(labels);
        return cv::connectedComponents(image_, labels_);
    }

    double HybridShape::connectedComponentsWithStats(const std::shared_ptr<HybridCvMatSpec> &image, const std::shared_ptr<HybridCvMatSpec> &labels,
                                                     const std::shared_ptr<HybridCvMatSpec> &stats, const std::shared_ptr<HybridCvMatSpec> &centroids)
    {
        auto &image_ = asMatRef(image);
        auto &labels_ = asMatRef(labels);
        auto &stats_ = asMatRef(stats);
        auto &centroids_ = asMatRef(centroids);
        return cv::connectedComponentsWithStats(image_, labels_, stats_, centroids_);

    }

    double HybridShape::contourArea(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorSpec>> &contour,
                                    std::optional<bool> oriented)
    {
        auto &input = std::visit([](auto&& arg) -> cv::InputArray {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                return asMatRef(arg);
            } 
            else if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                return asMatVectorRef(arg);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ {
                return asPointVectorRef(arg);
            } 
        }, contour);

        return cv::contourArea(input, oriented.value_or(false));
    }

    void HybridShape::convexHull(const std::shared_ptr<HybridCvMatSpec> &points, const std::shared_ptr<HybridCvMatSpec> &hull)
    {
        auto &points_ = asMatRef(points);
        auto &hull_ = asMatRef(hull);

        cv::convexHull(points_, hull_);
    }

    void HybridShape::convexityDefects(const std::shared_ptr<HybridCvMatSpec> &contour, const std::shared_ptr<HybridCvMatSpec> &convexHull,
                                       const std::shared_ptr<HybridCvMatSpec> &convexityDefects)
    {
        auto &contour_ = asMatRef(contour);
        auto &convexHull_ = asMatRef(convexHull);
        auto &convexityDefects_ = asMatRef(convexityDefects);

        cv::convexityDefects(contour_, convexHull_, convexityDefects_);
    }

    void HybridShape::findContours(const std::shared_ptr<HybridCvMatSpec> &image,
                                   const std::variant<std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorOfVectorsSpec>> &contours,
                                   RetrievalModes mode, ContourApproximationModes method)
    {
        auto &image_ = asMatRef(image);
        auto &contours_ = std::visit([](auto&& arg) -> cv::OutputArray {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                return asMatVectorRef(arg);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorOfVectorsSpec>>)*/ {
                return asPointVectorOfVectorsRef(arg);
            } 
        }, contours);
        cv::findContours(image_, contours_, (int)mode, (int)method);
    }

    void HybridShape::fitLine(const std::shared_ptr<HybridCvMatSpec> &points, const std::shared_ptr<HybridCvMatSpec> &line, DistanceTypes disType,
                              double param, double reps, double aeps)
    {
        auto &points_ = asMatRef(points);
        auto &line_ = asMatRef(line);
        cv::fitLine(points_, line_, (int)disType, param, reps, aeps);
    }

    bool HybridShape::isContourConvex(const std::shared_ptr<HybridCvMatSpec> &contour)
    {
        auto &contour_ = asMatRef(contour);
        return cv::isContourConvex(contour_);
    }

    double HybridShape::matchShapes(const std::shared_ptr<HybridCvMatSpec> &contour1, const std::shared_ptr<HybridCvMatSpec> &contour2, ShapeMatchModes method, double parameter)
    {
        auto &contour1_ = asMatRef(contour1);
        auto &contour2_ = asMatRef(contour2);
        auto result = cv::matchShapes(contour1_, contour2_, (int)method, parameter);
    }

    std::shared_ptr<HybridCvRotatedRectSpec> HybridShape::minAreaRect(const std::shared_ptr<HybridCvMatSpec> &points)
    {
        auto &points_ = asMatRef(points);
        auto rect = cv::minAreaRect(points_);
        return std::make_shared<HybridRotatedRect>(rect);
    }
}