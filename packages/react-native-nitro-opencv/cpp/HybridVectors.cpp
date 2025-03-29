#include "HybridVectors.hpp"

namespace margelo::nitro::nitroopencv {
    std::vector<MatInfo> HybridMatVector::toJsValue() {
        std::vector<MatInfo> res;
        res.reserve(vec.size());
        for (size_t i = 0; i < vec.size(); i++) {
            res.emplace_back(vec.at(i).cols, vec.at(i).rows, vec.at(i).size);
        }
        return res;
    }

    std::shared_ptr<HybridCvMatSpec> HybridMatVector::copyAt(double index) {
        auto mat = vec.at(index);
        return std::make_shared<HybridCvMatSpec>(mat);
    }

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
        return std::make_shared<HybridCvPointSpec>(point);
    }

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
        return std::make_shared<HybridPointVectorSpec>(subvec);
    }
    
    std::vector<Point> HybridPoint2fVector::toJsValue() {
        std::vector<Point> res;
        res.reserve(vec.size());
        for (size_t i = 0; i < vec.size(); i++) {
            res.emplace_back(vec.at(i).x, vec.at(i).y);
        }
        return res;
    }

    std::shared_ptr<HybridCvPoint2fSpec> HybridPoint2fVector::copyAt(double index) {
        auto point = vec.at(index);
        return std::make_shared<HybridCvPoint2fSpec>(point);
    }

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
        return std::make_shared<HybridCvRectSpec>(rect);
    }
}