#pragma once

#include <opencv2/core/mat.hpp>

#include "HybridCvMatSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    // using namespace facebook;

    class HybridMat : public virtual HybridCvMatSpec
    {
    private:
        cv::Mat mat;

    public:
        HybridMat(cv::Mat &&mat) : HybridCvMatSpec(), mat(mat) {}

    public:
        cv::Mat* asMatPtr() {
            return &mat;
        }

        cv::Mat& asMatRef() {
            return mat;
        }

        double getCols() override
        {
            return mat.cols;
        }
        double getRows() override
        {
            return mat.rows;
        }
        double getDepth() override
        {
            return mat.depth();
        }
        double getChannels() override
        {
            return mat.channels();
        }
        bool getEmpty() override
        {
            return mat.empty();
        }
        std::shared_ptr<HybridCvSizeSpec> getSize() override;
        std::string getBase64() override {
            return this->toBase64(MatImageFormat::JPEG);
        }
        std::string toBase64(std::optional<MatImageFormat> format) override;
        Mat toJsValue(std::optional<MatImageFormat> format) override {
            auto size = mat.size();
            return Mat(getCols(), getRows(), Size(size.width, size.height), toBase64(format));
        }
    };
}