#include "HybridPoint2fVector.hpp"
#include "HybridPoint2f.hpp"

namespace margelo::nitro::nitroopencv {
    std::vector<Point> HybridPoint2fVector::toJsValue() {
        std::vector<Point> res;
        res.reserve(vec.size());
        for (auto &item: vec) {
            res.emplace_back(item.x, item.y);
        }
        return res;
    }

    std::shared_ptr<HybridCvPoint2fSpec> HybridPoint2fVector::copyAt(double index) {
        auto point = vec.at(index);
        return std::make_shared<HybridPoint2f>(std::move(point));
    }
}