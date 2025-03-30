#include <variant>
#include <opencv2/opencv.hpp>

#include "HybridCore.hpp"
#include "HybridMat.hpp"
#include "HybridScalar.hpp"
#include "utils.hpp"

namespace margelo::nitro::nitroopencv
{

    void HybridCore::absdiff(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        cv::absdiff(src1_, src2_, dst_);
    }

    void HybridCore::add(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst,
                         const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask, std::optional<DataTypes> dtype)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        if (!mask.has_value())
            cv::add(src1_, src2_, dst_);
        else
        {
            auto &mask_ = asMatRef(mask.value());
            if (!dtype.has_value())
                cv::add(src1_, src2_, dst_, mask_);
            else
                cv::add(src1_, src2_, dst_, mask_, (int)dtype.value());
        }
    }

    void HybridCore::addWeighted(const std::shared_ptr<HybridCvMatSpec> &src1, double alpha, const std::shared_ptr<HybridCvMatSpec> &src2, double beta, double gamma,
                                 const std::shared_ptr<HybridCvMatSpec> &dst, std::optional<DataTypes> dtype)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        if (!dtype.has_value())
            cv::addWeighted(src1_, alpha, src2_, beta, gamma, dst_);
        else
            cv::addWeighted(src1_, alpha, src2_, beta, gamma, dst_, (int)dtype.value());
    }

    void HybridCore::batchDistance(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dist,
                                   double dtype, const std::shared_ptr<HybridCvMatSpec> &nidx, NormTypes normType, double K, const std::shared_ptr<HybridCvMatSpec> &mask,
                                   double update, bool crosscheck)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dist_ = asMatRef(dist);
        auto &nidx_ = asMatRef(nidx);
        auto &mask_ = asMatRef(mask);
        cv::batchDistance(src1_, src2_, dist_, dtype, nidx_, (int)normType, K, mask_, update, crosscheck);
    }

    void HybridCore::bitwise_and(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst,
                                 const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        if (!mask.has_value())
            cv::bitwise_and(src1_, src2_, dst_);
        else
        {
            auto &mask_ = asMatRef(mask.value());
            cv::bitwise_and(src1_, src2_, dst_, mask_);
        }
    }

    void HybridCore::bitwise_not(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst,
                                 const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        if (!mask.has_value())
            cv::bitwise_not(src_, dst_);
        else
        {
            auto &mask_ = asMatRef(mask.value());
            cv::bitwise_not(src_, dst_, mask_);
        }
    }

    void HybridCore::bitwise_or(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst,
                                const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        if (!mask.has_value())
            cv::bitwise_or(src1_, src2_, dst_);
        else
        {
            auto &mask_ = asMatRef(mask.value());
            cv::bitwise_or(src1_, src2_, dst_, mask_);
        }
    }

    void HybridCore::bitwise_xor(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst,
                                 const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        if (!mask.has_value())
            cv::bitwise_xor(src1_, src2_, dst_);
        else
        {
            auto &mask_ = asMatRef(mask.value());
            cv::bitwise_xor(src1_, src2_, dst_, mask_);
        }
    }

    double HybridCore::borderInterpolate(double p, double len, BorderTypes borderType)
    {
        return cv::borderInterpolate(p, len, (int)borderType);
    }

    void HybridCore::calcCovarMatrix(const std::shared_ptr<HybridMatVectorSpec> &samples, double nsamples, const std::shared_ptr<HybridCvMatSpec> &covar,
                                     const std::shared_ptr<HybridCvMatSpec> &mean, CovarFlags flags, DataTypes ctype)
    {
        auto &samples_ = asMatVectorRef(samples);
        auto &covar_ = asMatRef(covar);
        auto &mean_ = asMatRef(mean);
        cv::calcCovarMatrix(samples_.data(), nsamples, covar_, mean_, (int)flags, (int)ctype);
    }

    void HybridCore::cartToPolar(const std::shared_ptr<HybridCvMatSpec> &x, const std::shared_ptr<HybridCvMatSpec> &y, const std::shared_ptr<HybridCvMatSpec> &magnitude,
                                 const std::shared_ptr<HybridCvMatSpec> &angle, std::optional<bool> angleInDegrees)
    {
        auto &x_ = asMatRef(x);
        auto &y_ = asMatRef(y);
        auto &magnitude_ = asMatRef(magnitude);
        auto &angle_ = asMatRef(angle);
        if (!angleInDegrees.has_value())
            cv::cartToPolar(x_, y_, magnitude_, angle_);
        else
            cv::cartToPolar(x_, y_, magnitude_, angle_, angleInDegrees.value());
    }

    void HybridCore::cartToPolarN(const std::shared_ptr<HybridMatVectorSpec> &x, const std::shared_ptr<HybridMatVectorSpec> &y,
                                  const std::shared_ptr<HybridMatVectorSpec> &magnitude, const std::shared_ptr<HybridMatVectorSpec> &angle, std::optional<bool> angleInDegrees)
    {
        auto &x_ = asMatVectorRef(x);
        auto &y_ = asMatVectorRef(y);
        auto &magnitude_ = asMatVectorRef(magnitude);
        auto &angle_ = asMatVectorRef(angle);
        if (!angleInDegrees.has_value())
            cv::cartToPolar(x_, y_, magnitude_, angle_);
        else
            cv::cartToPolar(x_, y_, magnitude_, angle_, angleInDegrees.value());
    }

    void HybridCore::checkRange(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>> &a, bool quiet,
                                const std::optional<std::shared_ptr<HybridCvPointSpec>> &pos, double minVal, double maxVal)
    {
        std::visit([&pos, quiet, minVal, maxVal](auto &&arg)
                   {
            auto *pos_ = pos.has_value() ? &asPointRef(pos.value()) : nullptr;
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                cv::checkRange(asMatRef(arg), quiet, pos_, minVal, maxVal);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>)*/ {
                cv::checkRange(asMatVectorRef(arg), quiet, pos_, minVal, maxVal);
            } }, a);
    }

    void HybridCore::compare(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2,
                             const std::shared_ptr<HybridCvMatSpec> &dst, CmpTypes cmpop)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        cv::compare(src1_, src2_, dst_, (int)cmpop);
    }

    void HybridCore::completeSymm(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>> &m, bool lowerToUpper)
    {
        std::visit([lowerToUpper](auto &&arg)
                   {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                cv::completeSymm(asMatRef(arg), lowerToUpper);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>)*/ {
                cv::completeSymm(asMatVectorRef(arg), lowerToUpper);
            } }, m);
    }

    void HybridCore::convertFp16(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::convertFp16(src_, dst_);
    }

    void HybridCore::convertScaleAbs(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, std::optional<double> alpha,
                                     std::optional<double> beta)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        if (!alpha.has_value())
            cv::convertScaleAbs(src_, dst_);
        else if (!beta.has_value())
            cv::convertScaleAbs(src_, dst_, alpha.value());
        else
            cv::convertScaleAbs(src_, dst_, alpha.value(), beta.value());
    }

    void HybridCore::copyMakeBorder(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double top, double bottom,
                                    double left, double right, BorderTypes borderType, const std::shared_ptr<HybridCvScalarSpec> &value)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &value_ = asScalarRef(value);
        cv::copyMakeBorder(src_, dst_, top, bottom, left, right, (int)borderType, value_);
    }

    void HybridCore::copyTo(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &mask)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &mask_ = asMatRef(mask);
        cv::copyTo(src_, dst_, mask_);
    }

    double HybridCore::countNonZero(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>> &src)
    {
        return std::visit([](auto &&arg) -> double
                          {
            using T = std::decay_t<decltype(arg)>; // Get the underlying type of 'arg'
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                auto &mat = asMatRef(arg);
                return cv::countNonZero(mat);
            } 
            else if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                auto &vec = asMatVectorRef(arg);
                return cv::countNonZero(vec);
            } }, src);
    }

    void HybridCore::crop(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvRectSpec> &roi)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &roi_ = asRectRef(roi);
        src_(roi_).copyTo(dst_);
    }

    void HybridCore::dct(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DftFlags flags)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::dct(src_, dst_, (int)flags);
    }

    double HybridCore::determinant(const std::shared_ptr<HybridCvMatSpec> &src)
    {
        auto &src_ = asMatRef(src);
        return cv::determinant(src_);
    }

    void HybridCore::dft(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DftFlags flags, double nonzeroRows)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::dft(src_, dst_, (int)flags, nonzeroRows);
    }

    void HybridCore::divide(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst,
                            double scale, std::optional<double> dtype)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        if (!dtype.has_value())
            cv::divide(src1_, src2_, dst_, scale);
        else
            cv::divide(src1_, src2_, dst_, scale, dtype.value());
    }

    void HybridCore::eigen(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &eigenvalues, const std::shared_ptr<HybridCvMatSpec> &eigenvectors)
    {
        auto &src_ = asMatRef(src);
        auto &eigenvalues_ = asMatRef(eigenvalues);
        auto &eigenvectors_ = asMatRef(eigenvectors);
        cv::eigen(src_, eigenvalues_, eigenvectors_);
    }

    void HybridCore::eigenNonSymmetric(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &eigenvalues,
                                       const std::shared_ptr<HybridCvMatSpec> &eigenvectors)
    {
        auto &src_ = asMatRef(src);
        auto &eigenvalues_ = asMatRef(eigenvalues);
        auto &eigenvectors_ = asMatRef(eigenvectors);
        cv::eigenNonSymmetric(src_, eigenvalues_, eigenvectors_);
    }

    void HybridCore::exp(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::exp(src_, dst_);
    }

    void HybridCore::extractChannel(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double coi)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::extractChannel(src_, dst_, coi);
    }

    void HybridCore::findNonZero(const std::shared_ptr<HybridCvMatSpec> &src, const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridPointVectorSpec>> &idx)
    {
        std::visit([&src](auto &&arg)
                   {
            auto &src_ = asMatRef(src);
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) 
                cv::findNonZero(src_, asMatRef(arg));
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridPointVectorSpec>>)*/ 
                cv::findNonZero(src_, asPointVectorRef(arg)); }, idx);
    }

    void HybridCore::flip(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double flipCode)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::flip(src_, dst_, flipCode);
    }

    void HybridCore::gemm(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, double alpha,
                          const std::shared_ptr<HybridCvMatSpec> &src3, double beta, const std::shared_ptr<HybridCvMatSpec> &dst, GemmFlags flags)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &src3_ = asMatRef(src3);
        auto &dst_ = asMatRef(dst);
        cv::gemm(src1_, src2_, alpha, src3_, beta, dst_, (int)flags);
    }

    double HybridCore::getOptimalDFTSize(double vecsize)
    {
        return cv::getOptimalDFTSize((int)vecsize);
    }

    void HybridCore::getRotationMatrix2D(const std::shared_ptr<HybridCvPoint2fSpec> &center, double angle, double scale, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &center_ = asPoint2fRef(center);
        auto &dst_ = asMatRef(dst);
        dst_ = cv::getRotationMatrix2D(center_, angle, scale);
    }

    void HybridCore::hconcat(const std::shared_ptr<HybridMatVectorSpec> &srcs, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &srcs_ = asMatVectorRef(srcs);
        auto &dst_ = asMatRef(dst);
        cv::hconcat(srcs_, dst_);
    }

    void HybridCore::idft(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DftFlags flags, double nonzeroRows)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::idft(src_, dst_, (int)flags, nonzeroRows);
    }

    void HybridCore::inRange(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvScalarSpec> &lowerb,
                             const std::shared_ptr<HybridCvScalarSpec> &upperb, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &lowerb_ = asScalarRef(lowerb);
        auto &upperb_ = asScalarRef(upperb);
        cv::inRange(src_, lowerb_, upperb_, dst_);
    }

    void HybridCore::insertChannel(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double coi)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::insertChannel(src_, dst_, coi);
    }

    void HybridCore::invert(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DecompTypes flags)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::invert(src_, dst_, (int)flags);
    }

    void HybridCore::log(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::log(src_, dst_);
    }

    void HybridCore::LUT(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &lut, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src_ = asMatRef(src);
        auto &lut_ = asMatRef(lut);
        auto &dst_ = asMatRef(dst);
        cv::LUT(src_, lut_, dst_);
    }

    void HybridCore::magnitude(const std::shared_ptr<HybridCvMatSpec> &x, const std::shared_ptr<HybridCvMatSpec> &y, const std::shared_ptr<HybridCvMatSpec> &magnitude)
    {
        auto &x_ = asMatRef(x);
        auto &y_ = asMatRef(y);
        auto &magnitude_ = asMatRef(magnitude);
        cv::magnitude(x_, y_, magnitude_);
    }

    void HybridCore::magnitudeN(const std::shared_ptr<HybridMatVectorSpec> &x, const std::shared_ptr<HybridMatVectorSpec> &y, const std::shared_ptr<HybridCvMatSpec> &magnitude)
    {
        auto &x_ = asMatVectorRef(x);
        auto &y_ = asMatVectorRef(y);
        auto &magnitude_ = asMatRef(magnitude);
        cv::magnitude(x_, y_, magnitude_);
    }

    void HybridCore::Mahalanobis(const std::shared_ptr<HybridCvMatSpec> &v1, const std::shared_ptr<HybridCvMatSpec> &v2, const std::shared_ptr<HybridCvMatSpec> &icovar)
    {
        auto &v1_ = asMatRef(v1);
        auto &v2_ = asMatRef(v2);
        auto &icovar_ = asMatRef(icovar);
        cv::Mahalanobis(v1_, v2_, icovar_);
    }

    void HybridCore::MahalanobisN(const std::shared_ptr<HybridMatVectorSpec> &v1, const std::shared_ptr<HybridMatVectorSpec> &v2, const std::shared_ptr<HybridCvMatSpec> &icovar)
    {
        auto &v1_ = asMatVectorRef(v1);
        auto &v2_ = asMatVectorRef(v2);
        auto &icovar_ = asMatRef(icovar);
        cv::Mahalanobis(v1_, v2_, icovar_);
    }

    void HybridCore::max(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        cv::max(src1_, src2_, dst_);
    }

    std::shared_ptr<HybridCvScalarSpec> HybridCore::mean(const std::shared_ptr<HybridCvMatSpec> &src, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask)
    {
        auto &src_ = asMatRef(src);
        cv::Scalar result;
        if (mask.has_value())
        {
            auto &mask_ = asMatRef(mask.value());
            result = cv::mean(src_, mask_);
        }
        else
            result = cv::mean(src_);
        return std::make_shared<HybridScalar>(std::move(result));
    }

    void HybridCore::meanStdDev(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &mean,
                                const std::shared_ptr<HybridCvMatSpec> &stddev, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask)
    {
        auto &src_ = asMatRef(src);
        auto &mean_ = asMatRef(mean);
        auto &stddev_ = asMatRef(stddev);
        if (!mask.has_value())
            cv::meanStdDev(src_, mean_, stddev_);
        else
        {
            auto &mask_ = asMatRef(mask.value());
            cv::meanStdDev(src_, mean_, stddev_, mask_);
        }
    }

    void HybridCore::merge(const std::shared_ptr<HybridMatVectorSpec> &mv, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &mv_ = asMatVectorRef(mv);
        auto &dst_ = asMatRef(dst);
        cv::merge(mv_, dst_);
    }

    void HybridCore::min(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        cv::min(src1_, src2_, dst_);
    }

    std::tuple<double, double> HybridCore::minMaxLoc(const std::shared_ptr<HybridCvMatSpec> &src, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask)
    {
        auto &src_ = asMatRef(src);
        double min = 0;
        double max = 0;
        if (mask.has_value())
        {
            auto &mask_ = asMatRef(mask.value());
            cv::minMaxIdx(src_, &min, &max, nullptr, nullptr, mask_);
        }
        else
            cv::minMaxIdx(src_, &min, &max);
        return std::make_tuple(min, max);
    }

    void HybridCore::mulSpectrums(const std::shared_ptr<HybridCvMatSpec> &a, const std::shared_ptr<HybridCvMatSpec> &b, const std::shared_ptr<HybridCvMatSpec> &c,
                                  DftFlags flags, std::optional<bool> conjB)
    {
        auto &a_ = asMatRef(a);
        auto &b_ = asMatRef(b);
        auto &c_ = asMatRef(c);
        if (!conjB.has_value())
            cv::mulSpectrums(a_, b_, c_, (int)flags);
        else
            cv::mulSpectrums(a_, b_, c_, (int)flags, conjB.value());
    }

    void HybridCore::multiply(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst,
                              double scale, std::optional<DataTypes> dtype)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        if (!dtype.has_value())
            cv::multiply(src1_, src2_, dst_, scale);
        else
            cv::multiply(src1_, src2_, dst_, scale, (int)dtype.value());
    }

    void HybridCore::mulTransposed(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, bool aTa,
                                   const std::shared_ptr<HybridCvMatSpec> &delta, double scale, std::optional<DataTypes> dtype)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &delta_ = asMatRef(delta);
        if (!dtype.has_value())
            cv::mulTransposed(src_, dst_, aTa, delta_, scale);
        else
            cv::mulTransposed(src_, dst_, aTa, delta_, scale, (int)dtype.value());
    }

    double HybridCore::norm(const std::shared_ptr<HybridCvMatSpec> &src, NormTypes normType, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask)
    {
        auto &src_ = asMatRef(src);
        if (mask.has_value())
        {
            auto &mask_ = asMatRef(mask.value());
            return cv::norm(src_, (int)normType, mask_);
        }
        else
        {
            return cv::norm(src_, (int)normType);
        }
    }

    void HybridCore::normalize(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double alpha, NormTypes normType)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::normalize(src_, dst_, alpha, (int)normType);
    }

    void HybridCore::patchNaNs(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>> &a, double val)
    {
        std::visit([val](auto &&arg)
                   {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                cv::patchNaNs(asMatRef(arg), val);
            } 
            else /*if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>)*/ {
                cv::patchNaNs(asMatVectorRef(arg), val);
            } }, a);
    }

    void HybridCore::perspectiveTransform(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &m)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &m_ = asMatRef(m);
        cv::perspectiveTransform(src_, dst_, m_);
    }

    void HybridCore::phase(const std::shared_ptr<HybridCvMatSpec> &x, const std::shared_ptr<HybridCvMatSpec> &y,
                           const std::shared_ptr<HybridCvMatSpec> &angle, bool angleInDegrees)
    {
        auto &x_ = asMatRef(x);
        auto &y_ = asMatRef(y);
        auto &angle_ = asMatRef(angle);
        cv::phase(x_, y_, angle_, angleInDegrees);
    }

    void HybridCore::phaseN(const std::shared_ptr<HybridMatVectorSpec> &x, const std::shared_ptr<HybridMatVectorSpec> &y, const std::shared_ptr<HybridCvMatSpec> &angle,
                            bool angleInDegrees)
    {
        auto &x_ = asMatVectorRef(x);
        auto &y_ = asMatVectorRef(y);
        auto &angle_ = asMatRef(angle);
        cv::phase(x_, y_, angle_, angleInDegrees);
    }

    void HybridCore::pow(const std::shared_ptr<HybridCvMatSpec> &src, double power, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::pow(src_, power, dst_);
    }

    double HybridCore::PSNR(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, double R)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        return cv::PSNR(src1_, src2_, R);
    }

    void HybridCore::reduce(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double dim, ReduceTypes rtype, DataTypes dtype)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::reduce(src_, dst_, dim, (int)rtype, (int)dtype);
    }

    void HybridCore::repeat(const std::shared_ptr<HybridCvMatSpec> &src, double ny, double nx, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::repeat(src_, ny, nx, dst_);
    }

    void HybridCore::rotate(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, RotateFlags code)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::rotate(src_, dst_, (int)code);
    }

    void HybridCore::scaleAdd(const std::shared_ptr<HybridCvMatSpec> &src1, double alpha, const std::shared_ptr<HybridCvMatSpec> &src2,
                              const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        cv::scaleAdd(src1_, alpha, src2_, dst_);
    }

    bool HybridCore::solve(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst,
                           DecompTypes flags)
    {
        const auto &src1_ = asMatRef(src1);
        const auto &src2_ = asMatRef(src2);
        const auto &dst_ = asMatRef(dst);
        return cv::solve(src1_, src2_, dst_, (int)flags);
    }

    bool HybridCore::solveCubic(const std::shared_ptr<HybridCvMatSpec> &coeffs, const std::shared_ptr<HybridCvMatSpec> &roots)
    {
        const auto &coeffs_ = asMatRef(coeffs);
        const auto &roots_ = asMatRef(roots);
        return cv::solveCubic(coeffs_, roots_);
    }

    double HybridCore::solvePoly(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, std::optional<double> maxIters)
    {
        const auto &src_ = asMatRef(src);
        const auto &dst_ = asMatRef(dst);
        if (maxIters.has_value())
            return cv::solvePoly(src_, dst_, (int)maxIters.value());
        else
            return cv::solvePoly(src_, dst_);
    }

    void HybridCore::sort(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, SortFlags flags)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::sort(src_, dst_, (int)flags);
    }

    void HybridCore::sortIdx(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, SortFlags flags)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::sortIdx(src_, dst_, (int)flags);
    }

    void HybridCore::split(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridMatVectorSpec> &dst)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatVectorRef(dst);
        cv::split(src_, dst_);
    }

    void HybridCore::sqrt(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::sqrt(src_, dst_);
    }

    void HybridCore::subtract(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst,
                              const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask, std::optional<DataTypes> dtype)
    {
        auto &src1_ = asMatRef(src1);
        auto &src2_ = asMatRef(src2);
        auto &dst_ = asMatRef(dst);
        if (!mask.has_value())
            cv::subtract(src1_, src2_, dst_);
        else
        {
            auto &mask_ = asMatRef(mask.value());
            if (!dtype.has_value())
                cv::subtract(src1_, src2_, dst_, mask_);
            else
                cv::subtract(src1_, src2_, dst_, mask_, (int)dtype.value());
        }
    }

    std::shared_ptr<HybridCvScalarSpec> HybridCore::sum(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>> &src)
    {
        auto result = std::visit([](auto &&arg) -> cv::Scalar
                                 {
            using T = std::decay_t<decltype(arg)>; // Get the underlying type of 'arg'
            if constexpr (std::is_same_v<T, std::shared_ptr<HybridCvMatSpec>>) {
                auto &mat = asMatRef(arg);
                return cv::sum(mat);
            } 
            else if constexpr (std::is_same_v<T, std::shared_ptr<HybridMatVectorSpec>>) {
                auto &vec = asMatVectorRef(arg);
                return cv::sum(vec);
            } }, src);
        return std::make_shared<HybridScalar>(std::move(result));
    }

    std::shared_ptr<HybridCvScalarSpec> HybridCore::trace(const std::shared_ptr<HybridCvMatSpec> &mtx)
    {
        const auto &mtx_ = asMatRef(mtx);
        auto scalar = cv::trace(mtx_);
        return std::make_shared<HybridScalar>(std::move(scalar));
    }

    void HybridCore::transform(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &m)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        auto &m_ = asMatRef(m);
        cv::transform(src_, dst_, m_);
    }

    void HybridCore::transpose(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        cv::transpose(src_, dst_);
    }

    void HybridCore::vconcat(const std::shared_ptr<HybridMatVectorSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst)
    {
        auto &src_ = asMatVectorRef(src);
        auto &dst_ = asMatRef(dst);
        cv::vconcat(src_, dst_);
    }

    void HybridCore::convertTo(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DataTypes rtype, std::optional<double> alpha,
                               std::optional<double> beta)
    {
        auto &src_ = asMatRef(src);
        auto &dst_ = asMatRef(dst);
        if (!alpha.has_value())
            src_.convertTo(dst_, (int)rtype);
        else if (!beta.has_value())
            src_.convertTo(dst_, (int)rtype, alpha.value());
        else
            src_.convertTo(dst_, (int)rtype, alpha.value(), beta.value());
    }
}