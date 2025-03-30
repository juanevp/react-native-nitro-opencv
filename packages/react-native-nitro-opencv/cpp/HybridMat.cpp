#include "HybridMat.hpp"
#include "HybridSize.hpp"
#include "ConvertImage.hpp"

namespace margelo::nitro::nitroopencv {
    std::shared_ptr<HybridCvSizeSpec> HybridMat::getSize() {
        // Cache value?
        return std::make_shared<HybridSize>(mat.size());
    }

    std::string HybridMat::toBase64(std::optional<MatImageFormat> format) {
        std::string fmt;
        switch (format.value_or(MatImageFormat::JPEG)) {
            case MatImageFormat::PNG:
                fmt = "png";
                break;
            default:
                fmt = "jpeg";
                break;
        }
        mat.convertTo(mat, CV_8U);
        return ImageConverter::mat2str(mat, fmt);
    }
}