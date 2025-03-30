#include <opencv2/core/mat.hpp>

#include "HybridCvMatSpec.hpp"
#include "HybridCvRectSpec.hpp"
#include "HybridCvPointSpec.hpp"
#include "HybridCvScalarSpec.hpp"
#include "HybridCvSizeSpec.hpp"
#include "HybridMat.hpp"
#include "HybridRect.hpp"
#include "HybridPoint.hpp"
#include "HybridScalar.hpp"
#include "HybridSize.hpp"
#include "HybridMatVectorSpec.hpp"
#include "HybridPointVectorSpec.hpp"
#include "HybridMatVector.hpp"
#include "HybridPoint2f.hpp"
#include "HybridPointVector.hpp"
#include "HybridPointVectorOfVectors.hpp"

namespace margelo::nitro::nitroopencv {
    // IMPORTANT: these reinterpret casts assume that there only exist one concrete subclass of each spec.

    inline cv::Mat& asMatRef(std::shared_ptr<HybridCvMatSpec> ptr) {
        return std::reinterpret_pointer_cast<HybridMat>(ptr)->asMatRef();
    }

    inline std::vector<cv::Mat>& asMatVectorRef(std::shared_ptr<HybridMatVectorSpec> ptr) {
        return std::reinterpret_pointer_cast<HybridMatVector>(ptr)->asMatVectorRef();
    }

    inline cv::Rect& asRectRef(std::shared_ptr<HybridCvRectSpec> ptr) {
        return std::reinterpret_pointer_cast<HybridRect>(ptr)->asRectRef();
    }

    inline cv::Point& asPointRef(std::shared_ptr<HybridCvPointSpec> ptr) {
        return std::reinterpret_pointer_cast<HybridPoint>(ptr)->asPointRef();
    }

    inline cv::Point2f& asPoint2fRef(std::shared_ptr<HybridCvPoint2fSpec> ptr) {
        return std::reinterpret_pointer_cast<HybridPoint2f>(ptr)->asPoint2fRef();
    }

    inline std::vector<cv::Point>& asPointVectorRef(std::shared_ptr<HybridPointVectorSpec> ptr) {
        return std::reinterpret_pointer_cast<HybridPointVector>(ptr)->asPointVectorRef();
    }
    
    inline std::vector<std::vector<cv::Point>>& asPointVectorOfVectorsRef(std::shared_ptr<HybridPointVectorOfVectorsSpec> ptr) {
        return std::reinterpret_pointer_cast<HybridPointVectorOfVectors>(ptr)->asPointVectorOfVectorsRef();
    }

    inline cv::Scalar& asScalarRef(std::shared_ptr<HybridCvScalarSpec> ptr) {
        return std::reinterpret_pointer_cast<HybridScalar>(ptr)->asScalarRef();
    }

    inline cv::Size& asSizeRef(std::shared_ptr<HybridCvSizeSpec> ptr) {
        return std::reinterpret_pointer_cast<HybridSize>(ptr)->asSizeRef();
    }
}