#pragma once

#include <opencv2/core/mat.hpp>

#include "HybridMatVectorSpec.hpp"
#include "HybridPointVectorSpec.hpp"
#include "HybridPointVectorOfVectorsSpec.hpp"
#include "HybridPoint2fVectorSpec.hpp"
#include "HybridRectVectorSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridMatVector : public virtual HybridMatVectorSpec
    {
    private:
        std::vector<cv::Mat> vec;

    public:
        HybridMatVector(std::vector<cv::Mat> &&vec) : HybridMatVectorSpec(), vec(vec) {}

        std::vector<cv::Mat>& asMatVectorRef() {
            return vec;
        }

        std::vector<MatInfo> toJsValue() override;
        std::shared_ptr<HybridCvMatSpec> copyAt(double index) override;
    };

    class HybridPointVector : public virtual HybridPointVectorSpec
    {
    private:
        std::vector<cv::Point> vec;

    public:
        HybridPointVector(std::vector<cv::Point> &&vec) : HybridPointVectorSpec(), vec(vec) {}

        std::vector<cv::Point>& asPointVectorRef() {
            return vec;
        }

        std::vector<Point> toJsValue() override;
        std::shared_ptr<HybridCvPointSpec> copyAt(double index) override;
    };

    class HybridPointVectorOfVectors : public virtual HybridPointVectorOfVectorsSpec
    {
    private:
        std::vector<std::vector<cv::Point>> vec;

    public:
        HybridPointVectorOfVectors(std::vector<std::vector<cv::Point>> &&vec) : HybridPointVectorOfVectorsSpec(), vec(vec) {}

        std::vector<std::vector<cv::Point>>& asPointVectorOfVectorsRef() {
            return vec;
        }

        std::vector<std::vector<Point>> toJsValue() override;
        std::shared_ptr<HybridPointVectorSpec> copyAt(double index) override;
    };

    class HybridPoint2fVector : public virtual HybridPoint2fVectorSpec
    {
    private:
        std::vector<cv::Point2f> vec;

    public:
        HybridPoint2fVector(std::vector<cv::Point2f> &&vec) : HybridPoint2fVectorSpec(), vec(vec) {}

        std::vector<cv::Point2f>& asPoint2fVectorRef() {
            return vec;
        }

        std::vector<Point> toJsValue() override;
        std::shared_ptr<HybridCvPoint2fSpec> copyAt(double index) override;
    };
    
    class HybridRectVector : public virtual HybridRectVectorSpec
    {
    private:
        std::vector<cv::Rect> vec;

    public:
        HybridRectVector(std::vector<cv::Rect> &&vec) : HybridRectVectorSpec(), vec(vec) {}

        std::vector<cv::Rect>& asRectVectorRef() {
            return vec;
        }

        std::vector<Rect> toJsValue() override;
        std::shared_ptr<HybridCvRectSpec> copyAt(double index) override;
    };
}