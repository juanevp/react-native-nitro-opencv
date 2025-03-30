#pragma once

#include <opencv2/core/types.hpp>

#include "HybridCvScalarSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    // using namespace facebook;

    class HybridScalar : public virtual HybridCvScalarSpec
    {
    private:
        cv::Scalar scalar;

    public:
        HybridScalar() = default;
        HybridScalar(cv::Scalar &&scalar) : HybridCvScalarSpec(), scalar(scalar) {}

        cv::Scalar* asScalarPtr() {
            return &scalar;
        }

        cv::Scalar& asScalarRef() {
            return scalar;
        }

        double getA() override {
            return scalar.val[0];
        }
        double getB() override {
            return scalar.val[1];
        }
        double getC() override {
            return scalar.val[2];
        }
        double getD() override {
            return scalar.val[3];
        }
  
        Scalar toJsValue() override {
            return Scalar(getA(), getB(), getC(), getD());
        }
    };
}