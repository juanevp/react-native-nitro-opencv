#include <opencv2/core/cvdef.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <NitroModules/ArrayBuffer.hpp>

#include "ConvertImage.hpp"
#include "HybridMat.hpp"
#include "HybridPoint.hpp"
#include "HybridRange.hpp"
#include "HybridRect.hpp"
#include "HybridRotatedRect.hpp"
#include "HybridScalar.hpp"
#include "HybridSize.hpp"
#include "HybridObjects.hpp"
#include "HybridPoint2fVector.hpp"
#include "HybridRectVector.hpp"
#include "utils.hpp"

namespace margelo::nitro::nitroopencv
{
    std::shared_ptr<HybridCvMatSpec> HybridObjects::createMat(double rows, double cols, DataTypes dataType, const std::optional<std::vector<double>> &data)
    {
        std::vector<int> size{(int)rows, (int)cols};
        if (data.has_value())
        {
            auto channels = CV_MAT_CN((int)dataType);
            auto depth = CV_MAT_DEPTH((int)dataType);
            cv::Mat mat(std::move(data.value()), true);
            mat = mat.reshape(channels, size);
            mat.convertTo(mat, depth);
            return std::make_shared<HybridMat>(std::move(mat));
        }
        else
        {
            return std::make_shared<HybridMat>(cv::Mat(size, (int)dataType));
        }
    }

    std::shared_ptr<HybridMatVectorSpec> HybridObjects::createMatVector()
    {
        return std::make_shared<HybridMatVector>();
    }

    std::shared_ptr<HybridCvPointSpec> HybridObjects::createPoint(double x, double y)
    {
        return std::make_shared<HybridPoint>(cv::Point(x, y));
    }

    std::shared_ptr<HybridPointVectorSpec> HybridObjects::createPointVector()
    {
        return std::make_shared<HybridPointVector>();
    }

    std::shared_ptr<HybridPointVectorOfVectorsSpec> HybridObjects::createPointVectorOfVectors()
    {
        return std::make_shared<HybridPointVectorOfVectors>();
    }

    std::shared_ptr<HybridCvPoint2fSpec> HybridObjects::createPoint2f(double x, double y)
    {
        return std::make_shared<HybridPoint2f>(cv::Point2f(x, y));
    }

    std::shared_ptr<HybridPoint2fVectorSpec> HybridObjects::createPoint2fVector()
    {
        return std::make_shared<HybridPoint2fVector>();
    }

    std::shared_ptr<HybridCvRangeSpec> HybridObjects::createRange(double start, double end)
    {
        return std::make_shared<HybridRange>(cv::Range(start, end));
    }

    std::shared_ptr<HybridCvRangeSpec> HybridObjects::createRangeAll()
    {
        return std::make_shared<HybridRange>(cv::Range::all());
    }

    std::shared_ptr<HybridCvRectSpec> HybridObjects::createRect(double x, double y, double width, double height)
    {
        return std::make_shared<HybridRect>(cv::Rect(x, y, width, height));
    }

    std::shared_ptr<HybridRectVectorSpec> HybridObjects::createRectVector()
    {
        return std::make_shared<HybridRectVector>();
    }

    std::shared_ptr<HybridCvRotatedRectSpec> HybridObjects::createRotatedRect(double centerX, double centerY, double width, double height, double angle)
    {
        return std::make_shared<HybridRotatedRect>(cv::RotatedRect(cv::Point2f(centerX, centerY), cv::Size2f(width, height), angle));
    }

    std::shared_ptr<HybridCvSizeSpec> HybridObjects::createSize(double width, double height)
    {
        return std::make_shared<HybridSize>(cv::Size(width, height));
    }

    std::shared_ptr<HybridCvScalarSpec> HybridObjects::createScalar(std::optional<double> a, std::optional<double> b, std::optional<double> c, std::optional<double> d)
    {
        return std::make_shared<HybridScalar>(cv::Scalar(a.value_or(0), b.value_or(0), c.value_or(0), d.value_or(0)));
    }

    std::shared_ptr<HybridCvMatSpec> HybridObjects::arrayBufferToMat(ImportBufferItemType itemType, double rows, double cols, double channels, const std::shared_ptr<ArrayBuffer> &input)
    {
        auto modeType = -1;
        auto typeSize = 1;
        if (itemType == ImportBufferItemType::UINT8)
        {
            typeSize = 1;
            if (channels == 1)
                modeType = CV_8U;
            if (channels == 3)
                modeType = CV_8UC3;
            if (channels == 4)
                modeType = CV_8UC4;
        }
        else if (itemType == ImportBufferItemType::UINT16)
        {
            typeSize = 2;
            if (channels == 1)
                modeType = CV_16U;
            if (channels == 3)
                modeType = CV_16UC3;
            if (channels == 4)
                modeType = CV_16UC4;
        }
        else if (itemType == ImportBufferItemType::INT8)
        {
            typeSize = 1;
            if (channels == 1)
                modeType = CV_8S;
            if (channels == 3)
                modeType = CV_8SC3;
            if (channels == 4)
                modeType = CV_8SC4;
        }
        else if (itemType == ImportBufferItemType::INT16)
        {
            typeSize = 2;
            if (channels == 1)
                modeType = CV_16S;
            if (channels == 3)
                modeType = CV_16SC3;
            if (channels == 4)
                modeType = CV_16SC4;
        }
        else if (itemType == ImportBufferItemType::INT32)
        {
            typeSize = 4;
            if (channels == 1)
                modeType = CV_32S;
            if (channels == 3)
                modeType = CV_32SC3;
            if (channels == 4)
                modeType = CV_32SC4;
        }
        else if (itemType == ImportBufferItemType::FLOAT32)
        {
            typeSize = 4;
            if (channels == 1)
                modeType = CV_32F;
            if (channels == 3)
                modeType = CV_32FC3;
            if (channels == 4)
                modeType = CV_32FC4;
        }
        else if (itemType == ImportBufferItemType::FLOAT64)
        {
            typeSize = 8;
            if (channels == 1)
                modeType = CV_64F;
            if (channels == 3)
                modeType = CV_64FC3;
            if (channels == 4)
                modeType = CV_64FC4;
        }

        if (channels == -1)
        {
            throw std::runtime_error("Fast OpenCV Error: Invalid channel count passed to bufferToMat!");
        }

        cv::Mat mat(rows, cols, modeType);
        memcpy(mat.data, input->data(), (int)rows * (int)cols * (int)channels * typeSize);
        return std::make_shared<HybridMat>(std::move(mat));
    }

    std::shared_ptr<HybridCvMatSpec> HybridObjects::base64ToMat(const std::string &data)
    {
        auto mat = ImageConverter::str2mat(data);
        return std::make_shared<HybridMat>(std::move(mat));
    }

    std::shared_ptr<ArrayBuffer> HybridObjects::matToArrayBuffer(const std::shared_ptr<HybridCvMatSpec> &mat)
    {
        auto &mat_ = asMatRef(mat);
        auto size = mat_.cols * mat_.rows * mat_.channels() * mat_.elemSize1();
        return ArrayBuffer::copy((uint8_t *)mat_.data, size);
    }
}