#include "HybridRectVector.hpp"
#include "HybridRect.hpp"

namespace margelo::nitro::nitroopencv {
    std::vector<Rect> HybridRectVector::toJsValue() {
        std::vector<Rect> res;
        res.reserve(vec.size());
        for(auto &item: vec) {
            res.emplace_back(item.x, item.y, item.width, item.height);
        }
        return res;   
    }
    
    std::shared_ptr<HybridCvRectSpec> HybridRectVector::copyAt(double index) {
        auto rect = vec.at(index);
        return std::make_shared<HybridRect>(std::move(rect));
    }
}