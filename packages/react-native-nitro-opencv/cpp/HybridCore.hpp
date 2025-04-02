#pragma once

#include <opencv2/core/mat.hpp>

#include "HybridCoreSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    // using namespace facebook;

    class HybridCore : public HybridCoreSpec
    {
    public:
        HybridCore() : HybridObject(TAG) {}

        void absdiff(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void add(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask, std::optional<DataTypes> dtype) override;
        void addWeighted(const std::shared_ptr<HybridCvMatSpec> &src1, double alpha, const std::shared_ptr<HybridCvMatSpec> &src2, double beta, double gamma, const std::shared_ptr<HybridCvMatSpec> &dst, std::optional<DataTypes> dtype) override;
        void batchDistance(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dist, double dtype, const std::shared_ptr<HybridCvMatSpec> &nidx, NormTypes normType, double K, const std::shared_ptr<HybridCvMatSpec> &mask, double update, bool crosscheck) override;
        void bitwise_and(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask) override;
        void bitwise_not(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask) override;
        void bitwise_or(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask) override;
        void bitwise_xor(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask) override;
        double borderInterpolate(double p, double len, BorderTypes borderType) override;
        void calcCovarMatrix(const std::shared_ptr<HybridMatVectorSpec> &samples, double nsamples, const std::shared_ptr<HybridCvMatSpec> &covar, const std::shared_ptr<HybridCvMatSpec> &mean, CovarFlags flags, DataTypes ctype) override;
        void cartToPolar(const std::shared_ptr<HybridCvMatSpec> &x, const std::shared_ptr<HybridCvMatSpec> &y, const std::shared_ptr<HybridCvMatSpec> &magnitude, const std::shared_ptr<HybridCvMatSpec> &angle, std::optional<bool> angleInDegrees) override;
        void cartToPolarN(const std::shared_ptr<HybridMatVectorSpec> &x, const std::shared_ptr<HybridMatVectorSpec> &y, const std::shared_ptr<HybridMatVectorSpec> &magnitude, const std::shared_ptr<HybridMatVectorSpec> &angle, std::optional<bool> angleInDegrees) override;
        void checkRange(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>> &a, bool quiet, const std::optional<std::shared_ptr<HybridCvPointSpec>> &pos, double minVal, double maxVal) override;
        void compare(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst, CmpTypes cmpop) override;
        void completeSymm(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>> &m, bool lowerToUpper) override;
        void convertFp16(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void convertScaleAbs(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, std::optional<double> alpha, std::optional<double> beta) override;
        void copyMakeBorder(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double top, double bottom, double left, double right, BorderTypes borderType, const std::shared_ptr<HybridCvScalarSpec> &value) override;
        void copyTo(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &mask) override;
        double countNonZero(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>> &src) override;
        void crop(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvRectSpec> &roi) override;
        void dct(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DftFlags flags) override;
        double determinant(const std::shared_ptr<HybridCvMatSpec> &src) override;
        void dft(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DftFlags flags, double nonzeroRows) override;
        void divide(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst, double scale, std::optional<double> dtype) override;
        void eigen(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &eigenvalues, const std::shared_ptr<HybridCvMatSpec> &eigenvectors) override;
        void eigenNonSymmetric(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &eigenvalues, const std::shared_ptr<HybridCvMatSpec> &eigenvectors) override;
        void exp(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void extractChannel(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double coi) override;
        void findNonZero(const std::shared_ptr<HybridCvMatSpec> &src, const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridPointVectorSpec>> &idx) override;
        void flip(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double flipCode) override;
        void gemm(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, double alpha, const std::shared_ptr<HybridCvMatSpec> &src3, double beta, const std::shared_ptr<HybridCvMatSpec> &dst, GemmFlags flags) override;
        double getOptimalDFTSize(double vecsize) override;
        void getRotationMatrix2D(const std::shared_ptr<HybridCvPoint2fSpec> &center, double angle, double scale, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void hconcat(const std::shared_ptr<HybridMatVectorSpec> &srcs, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void idft(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DftFlags flags, double nonzeroRows) override;
        void inRange(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvScalarSpec> &lowerb, const std::shared_ptr<HybridCvScalarSpec> &upperb, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void insertChannel(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double coi) override;
        void invert(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DecompTypes flags) override;
        void log(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void LUT(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &lut, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void magnitude(const std::shared_ptr<HybridCvMatSpec> &x, const std::shared_ptr<HybridCvMatSpec> &y, const std::shared_ptr<HybridCvMatSpec> &magnitude) override;
        void magnitudeN(const std::shared_ptr<HybridMatVectorSpec> &x, const std::shared_ptr<HybridMatVectorSpec> &y, const std::shared_ptr<HybridCvMatSpec> &magnitude) override;
        void Mahalanobis(const std::shared_ptr<HybridCvMatSpec> &v1, const std::shared_ptr<HybridCvMatSpec> &v2, const std::shared_ptr<HybridCvMatSpec> &icovar) override;
        void MahalanobisN(const std::shared_ptr<HybridMatVectorSpec> &v1, const std::shared_ptr<HybridMatVectorSpec> &v2, const std::shared_ptr<HybridCvMatSpec> &icovar) override;
        void max(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        std::shared_ptr<HybridCvScalarSpec> mean(const std::shared_ptr<HybridCvMatSpec> &src, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask) override;
        void meanStdDev(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &mean, const std::shared_ptr<HybridCvMatSpec> &stddev, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask) override;
        void merge(const std::shared_ptr<HybridMatVectorSpec> &mv, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void min(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        std::tuple<double, double> minMaxLoc(const std::shared_ptr<HybridCvMatSpec> &src, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask) override;
        void mulSpectrums(const std::shared_ptr<HybridCvMatSpec> &a, const std::shared_ptr<HybridCvMatSpec> &b, const std::shared_ptr<HybridCvMatSpec> &c, DftFlags flags, std::optional<bool> conjB) override;
        void multiply(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst, double scale, std::optional<DataTypes> dtype) override;
        void mulTransposed(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, bool aTa, const std::shared_ptr<HybridCvMatSpec> &delta, double scale, std::optional<DataTypes> dtype) override;
        double norm(const std::shared_ptr<HybridCvMatSpec> &src, NormTypes normType, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask) override;
        void normalize(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double alpha, NormTypes normType) override;
        void patchNaNs(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>> &a, double val) override;
        void perspectiveTransform(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &m) override;
        void phase(const std::shared_ptr<HybridCvMatSpec> &x, const std::shared_ptr<HybridCvMatSpec> &y, const std::shared_ptr<HybridCvMatSpec> &angle, bool angleInDegrees) override;
        void phaseN(const std::shared_ptr<HybridMatVectorSpec> &x, const std::shared_ptr<HybridMatVectorSpec> &y, const std::shared_ptr<HybridCvMatSpec> &angle, bool angleInDegrees) override;
        void pow(const std::shared_ptr<HybridCvMatSpec> &src, double power, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        double PSNR(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, double R) override;
        void reduce(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, double dim, ReduceTypes rtype, DataTypes dtype) override;
        void repeat(const std::shared_ptr<HybridCvMatSpec> &src, double ny, double nx, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void rotate(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, RotateFlags code) override;
        void scaleAdd(const std::shared_ptr<HybridCvMatSpec> &src1, double alpha, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        bool solve(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst, DecompTypes flags) override;
        bool solveCubic(const std::shared_ptr<HybridCvMatSpec> &coeffs, const std::shared_ptr<HybridCvMatSpec> &roots) override;
        double solvePoly(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, std::optional<double> maxIters) override;
        void sort(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, SortFlags flags) override;
        void sortIdx(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, SortFlags flags) override;
        void split(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridMatVectorSpec> &dst) override;
        void sqrt(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void subtract(const std::shared_ptr<HybridCvMatSpec> &src1, const std::shared_ptr<HybridCvMatSpec> &src2, const std::shared_ptr<HybridCvMatSpec> &dst, const std::optional<std::shared_ptr<HybridCvMatSpec>> &mask, std::optional<DataTypes> dtype) override;
        std::shared_ptr<HybridCvScalarSpec> sum(const std::variant<std::shared_ptr<HybridCvMatSpec>, std::shared_ptr<HybridMatVectorSpec>> &src) override;
        std::shared_ptr<HybridCvScalarSpec> trace(const std::shared_ptr<HybridCvMatSpec> &mtx) override;
        void transform(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, const std::shared_ptr<HybridCvMatSpec> &m) override;
        void transpose(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void vconcat(const std::shared_ptr<HybridMatVectorSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst) override;
        void convertTo(const std::shared_ptr<HybridCvMatSpec> &src, const std::shared_ptr<HybridCvMatSpec> &dst, DataTypes rtype, std::optional<double> alpha, std::optional<double> beta) override;
    };
}