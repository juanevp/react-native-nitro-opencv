#include "HybridPointVector.hpp"
#include "HybridPoint.hpp"

namespace margelo::nitro::nitroopencv {
    std::vector<Point> HybridPointVector::toJsValue() {
        std::vector<Point> res;
        res.reserve(vec.size());
        for (auto &item: vec) {
            res.emplace_back(item.x, item.y);
        }
        return res;
    }

    std::shared_ptr<HybridCvPointSpec> HybridPointVector::copyAt(double index) {
        auto point = vec.at(index);
        return std::make_shared<HybridPoint>(std::move(point));
    }
}