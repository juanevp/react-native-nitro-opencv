#pragma once

#include <opencv2/core/mat.hpp>
#include <NitroModules/ArrayBuffer.hpp>

#include "HybridObjectsSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridObjects : public virtual HybridObjectsSpec
    {
    private:
    public:
        HybridObjects() : HybridObjectsSpec() {}

        std::shared_ptr<HybridCvMatSpec> createMat(double rows, double cols, DataTypes dataType, const std::optional<std::vector<double>> &data) override;
        std::shared_ptr<HybridMatVectorSpec> createMatVector() override;
        std::shared_ptr<HybridCvPointSpec> createPoint(double x, double y) override;
        std::shared_ptr<HybridPointVectorSpec> createPointVector() override;
        std::shared_ptr<HybridPointVectorOfVectorsSpec> createPointVectorOfVectors() override;
        std::shared_ptr<HybridCvPoint2fSpec> createPoint2f(double x, double y) override;
        std::shared_ptr<HybridPoint2fVectorSpec> createPoint2fVector() override;
        std::shared_ptr<HybridCvRectSpec> createRect(double x, double y, double width, double height) override;
        std::shared_ptr<HybridRectVectorSpec> createRectVector() override;
        std::shared_ptr<HybridCvRotatedRectSpec> createRotatedRect(double centerX, double centerY, double width, double height, double angle) override;
        std::shared_ptr<HybridCvSizeSpec> createSize(double width, double height) override;
        std::shared_ptr<HybridCvScalarSpec> createScalar(std::optional<double> a, std::optional<double> b, std::optional<double> c, std::optional<double> d) override;
        std::shared_ptr<HybridCvMatSpec> arrayBufferToMat(ImportBufferItemType itemType, double rows, double cols, double channels, const std::shared_ptr<ArrayBuffer> &input) override;
        std::shared_ptr<HybridCvMatSpec> base64ToMat(const std::string &data) override;
        std::shared_ptr<ArrayBuffer> matToArrayBuffer(const std::shared_ptr<HybridCvMatSpec> &mat) override;
    };
}