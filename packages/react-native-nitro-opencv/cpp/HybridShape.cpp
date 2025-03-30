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
        auto visitOutput = [&approxCurve, epsilon, closed](cv::InputArray input) 
        {
            std::visit([&input, epsilon, closed](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                    cv::approxPolyDP(input, asMatRef(arg), epsilon, closed);
                } 
                else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ {
                    cv::approxPolyDP(input, asPointVectorRef(arg), epsilon, closed);
                } 
            }, approxCurve);
        };

        std::visit([&visitOutput](auto&& arg) {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                visitOutput(asMatRef(arg));
            } 
            else if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                visitOutput(asMatVectorRef(arg));
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ {
                visitOutput(asPointVectorRef(arg));
            } 
        }, curve);
    }

    double HybridShape::arcLength(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorSpec>> &curve,
                                  bool closed)
    {
        return std::visit([closed](auto&& arg) -> double {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                return cv::arcLength(asMatRef(arg), closed);
            } 
            else if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                return cv::arcLength(asMatVectorRef(arg), closed);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ {
                return cv::arcLength(asPointVectorRef(arg), closed);
            } 
        }, curve);
    }

    std::shared_ptr<HybridCvRectSpec> HybridShape::boundingRect(
        const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>, std::shared_ptr<HybridPointVectorSpec>> &array)
    {
        auto rect = std::visit([](auto&& arg) -> cv::Rect {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                return cv::boundingRect(asMatRef(arg));
            } 
            else if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                return cv::boundingRect(asMatVectorRef(arg));
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ {
                return cv::boundingRect(asPointVectorRef(arg));
            } 
        }, array);

        return std::make_shared<HybridRect>(std::move(rect));
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
        auto oriented_resolved = oriented.value_or(false);
        return std::visit([oriented_resolved](auto&& arg) -> double {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                return cv::contourArea(asMatRef(arg), oriented_resolved);
            } 
            else if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                return cv::contourArea(asMatVectorRef(arg), oriented_resolved);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ {
                return cv::contourArea(asPointVectorRef(arg), oriented_resolved);
            } 
        }, contour);
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
        std::visit([&image, mode, method](auto&& arg) {
            auto &image_ = asMatRef(image);
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                cv::findContours(image_, asMatVectorRef(arg), (int)mode, (int)method);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorOfVectorsSpec>>)*/ {
                cv::findContours(image_, asPointVectorOfVectorsRef(arg), (int)mode, (int)method);
            } 
        }, contours);
        
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
        return cv::matchShapes(contour1_, contour2_, (int)method, parameter);
    }

    std::shared_ptr<HybridCvRotatedRectSpec> HybridShape::minAreaRect(const std::shared_ptr<HybridCvMatSpec> &points)
    {
        auto &points_ = asMatRef(points);
        auto rect = cv::minAreaRect(points_);
        return std::make_shared<HybridRotatedRect>(std::move(rect));
    }
}