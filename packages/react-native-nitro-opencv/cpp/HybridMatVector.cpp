#include "HybridMatVector.hpp"
#include "HybridMat.hpp"

namespace margelo::nitro::nitroopencv {
    std::vector<MatInfo> HybridMatVector::toJsValue() {
        std::vector<MatInfo> res;
        res.reserve(vec.size());
        for (auto &item: vec) {
            res.emplace_back(item.cols, item.rows, Size(item.size().width, item.size().height));
        }
        return res;
    }

    std::shared_ptr<HybridCvMatSpec> HybridMatVector::copyAt(double index) {
        auto mat = vec.at(index);
        return std::make_shared<HybridMat>(std::move(mat));
    }
}