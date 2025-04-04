#include <variant>
#include <opencv2/opencv.hpp>

#include "HybridImageIo.hpp"
#include "HybridMat.hpp"
#include "utils.hpp"

namespace margelo::nitro::nitroopencv
{
    std::vector<int> decodeWriteFlags(const std::vector<std::tuple<ImwriteFlags, double>> &params)
    {
        std::vector<int> result{};
        result.reserve(params.size() * 2);
        for (auto &item : params)
        {
            result.push_back((int)std::get<0>(item));
            result.push_back(std::get<1>(item));
        }
        return result;
    }

    bool HybridImageIo::haveImageReader(const std::string &filename)
    {
        return cv::haveImageReader(filename);
    }

    bool HybridImageIo::haveImageWriter(const std::string &filename)
    {
        return cv::haveImageWriter(filename);
    }

    double HybridImageIo::imcount(const std::string &filename, std::optional<ImreadModes> flags)
    {
        return cv::imcount(filename, (int)flags.value_or(ImreadModes::IMREAD_ANYCOLOR));
    }

    std::shared_ptr<HybridCvMatSpec> HybridImageIo::imdecode(const std::shared_ptr<HybridCvMatSpec> &buf, ImreadModes flags, const std::optional<std::shared_ptr<HybridCvMatSpec>> &dst)
    {
        auto &buf_ = asMatRef(buf);
        if (dst.has_value())
        {
            auto &dst_ = asMatRef(dst.value());
            cv::Mat result = cv::imdecode(buf_, (int)flags, &dst_);
            return std::make_shared<HybridMat>(std::move(result));
        }
        else
        {
            cv::Mat result = cv::imdecode(buf_, (int)flags);
            return std::make_shared<HybridMat>(std::move(result));
        }
    }

    bool HybridImageIo::imdecodemulti(const std::shared_ptr<HybridCvMatSpec> &buf, ImreadModes flags, const std::shared_ptr<HybridMatVectorSpec> &mats, const std::optional<std::shared_ptr<HybridCvRangeSpec>> &range)
    {
        auto &buf_ = asMatRef(buf);
        auto &mats_ = asMatVectorRef(mats);
        if (range.has_value())
        {
            auto &range_ = asRangeRef(range.value());
            return cv::imdecodemulti(buf_, (int)flags, mats_, range_);
        }
        else
            return cv::imdecodemulti(buf_, (int)flags, mats_);
    }

    std::optional<std::shared_ptr<ArrayBuffer>> HybridImageIo::imencode(const std::string &ext, const std::shared_ptr<HybridCvMatSpec> &img, const std::optional<std::vector<std::tuple<ImwriteFlags, double>>> &params)
    {
        auto &img_ = asMatRef(img);
        auto buf_ = new std::vector<uint8_t>{};
        auto result = false;
        if (params.has_value())
        {
            auto flags = decodeWriteFlags(params.value());
            result = cv::imencode(ext, img_, *buf_, flags);
        }
        else
            result = cv::imencode(ext, img_, *buf_);
        if (result)
        {
            return ArrayBuffer::wrap(buf_->data(), buf_->size(), [=]()
                                     { delete buf_; });
        }
        delete buf_;
        return std::nullopt;
    }

    std::optional<std::shared_ptr<ArrayBuffer>> HybridImageIo::imencodemulti(const std::string &ext, const std::shared_ptr<HybridMatVectorSpec> &imgs, const std::optional<std::vector<std::tuple<ImwriteFlags, double>>> &params)
    {
        auto &imgs_ = asMatVectorRef(imgs);
        auto buf_ = new std::vector<uint8_t>{};
        auto result = false;
        if (params.has_value())
        {
            auto flags = decodeWriteFlags(params.value());
            result = cv::imencodemulti(ext, imgs_, *buf_, flags);
        }
        else
            result = cv::imencodemulti(ext, imgs_, *buf_);
        if (result)
        {
            return ArrayBuffer::wrap(buf_->data(), buf_->size(), [=]()
                                     { delete buf_; });
        }
        delete buf_;
        return std::nullopt;
    }

    std::shared_ptr<HybridCvMatSpec> HybridImageIo::imread(const std::string &filename, std::optional<ImreadModes> flags, const std::optional<std::shared_ptr<HybridCvMatSpec>> &dst)
    {
        auto resolvedFlags = (int)flags.value_or(ImreadModes::IMREAD_COLOR_BGR);
        if (dst.has_value())
        {
            auto &dst_ = asMatRef(dst.value());
            cv::imread(filename, dst_, resolvedFlags);
            return dst.value();
        }
        else
        {
            cv::Mat result = cv::imread(filename, resolvedFlags);
            return std::make_shared<HybridMat>(std::move(result));
        }
    }

    bool HybridImageIo::imreadmulti(const std::string &filename, const std::shared_ptr<HybridMatVectorSpec> &mats, std::optional<ImreadModes> flags)
    {
        auto resolvedFlags = (int)flags.value_or(ImreadModes::IMREAD_ANYCOLOR);
        auto &mats_ = asMatVectorRef(mats);
        return cv::imreadmulti(filename, mats_, resolvedFlags);
    }

    bool HybridImageIo::imwrite(const std::string &filename, const std::shared_ptr<HybridCvMatSpec> &img, const std::optional<std::vector<std::tuple<ImwriteFlags, double>>> &params)
    {
        auto &img_ = asMatRef(img);
        if (params.has_value())
        {
            auto flags = decodeWriteFlags(params.value());
            return cv::imwrite(filename, img_, flags);
        }
        else
            return cv::imwrite(filename, img_);
    }

    bool HybridImageIo::imwritemulti(const std::string &filename, const std::shared_ptr<HybridMatVectorSpec> &img, const std::optional<std::vector<std::tuple<ImwriteFlags, double>>> &params)
    {
        auto &img_ = asMatVectorRef(img);
        if (params.has_value())
        {
            auto flags = decodeWriteFlags(params.value());
            return cv::imwritemulti(filename, img_, flags);
        }
        else
            return cv::imwritemulti(filename, img_);
    }

}