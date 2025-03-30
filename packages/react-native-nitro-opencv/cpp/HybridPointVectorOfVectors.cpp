#include "HybridPointVectorOfVectors.hpp"
#include "HybridPointVector.hpp"

namespace margelo::nitro::nitroopencv {
    std::vector<std::vector<Point>> HybridPointVectorOfVectors::toJsValue() {
        std::vector<std::vector<Point>> res;
        res.reserve(vec.size());
        for (auto &subvec: vec) {
            auto &subres = res.emplace_back();
            subres.reserve(subvec.size());
            for (auto &item: subvec) {
                subres.emplace_back(item.x, item.y);
            }
        }
        return res;
    }

    std::shared_ptr<HybridPointVectorSpec> HybridPointVectorOfVectors::copyAt(double index) {
        auto subvec = vec.at(index);
        return std::make_shared<HybridPointVector>(std::move(subvec));
    }
}