#include "HybridPointVectorOfVectors.hpp"
#include "HybridPointVector.hpp"

namespace margelo::nitro::nitroopencv {
    std::vector<std::vector<Point>> HybridPointVectorOfVectors::toJsValue() {
        std::vector<std::vector<Point>> res;
        res.reserve(vec.size());
        for (size_t i = 0; i < vec.size(); i++) {
            auto &subvec = vec.at(i);
            auto &subres = res.emplace_back();
            subres.reserve(subvec.size());
            for (size_t j = 0; j < subvec.size(); j++) {
                subres.emplace_back(subvec.at(i).x, subvec.at(i).y);
            }
        }
        return res;
    }

    std::shared_ptr<HybridPointVectorSpec> HybridPointVectorOfVectors::copyAt(double index) {
        auto subvec = vec.at(index);
        return std::make_shared<HybridPointVector>(subvec);
    }
}