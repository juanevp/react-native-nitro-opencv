#include "HybridRectVector.hpp"
#include "HybridRect.hpp"

namespace margelo::nitro::nitroopencv {
    std::vector<Rect> HybridRectVector::toJsValue() {
        std::vector<Rect> res;
        res.reserve(vec.size());
        for (size_t i = 0; i < vec.size(); i++) {
            res.emplace_back(vec.at(i).x, vec.at(i).y, vec.at(i).width, vec.at(i).height);
        }
        return res;   
    }
    
    std::shared_ptr<HybridCvRectSpec> HybridRectVector::copyAt(double index) {
        auto rect = vec.at(index);
        return std::make_shared<HybridRect>(rect);
    }
}