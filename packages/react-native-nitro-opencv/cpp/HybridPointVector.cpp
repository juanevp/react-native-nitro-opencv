#include "HybridPointVector.hpp"
#include "HybridPoint.hpp"

namespace margelo::nitro::nitroopencv {
    std::vector<Point> HybridPointVector::toJsValue() {
        std::vector<Point> res;
        res.reserve(vec.size());
        for (size_t i = 0; i < vec.size(); i++) {
            res.emplace_back(vec.at(i).x, vec.at(i).y);
        }
        return res;
    }

    std::shared_ptr<HybridCvPointSpec> HybridPointVector::copyAt(double index) {
        auto point = vec.at(index);
        return std::make_shared<HybridPoint>(point);
    }
}