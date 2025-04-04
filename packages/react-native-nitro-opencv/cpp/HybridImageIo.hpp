#pragma once

#include "HybridImageIoSpec.hpp"
#include "HybridPointVectorSpec.hpp"
#include "HybridCvMatSpec.hpp"
#include "HybridCvSizeSpec.hpp"
#include "DecompTypes.hpp"
#include "InterpolationFlags.hpp"
#include "BorderTypes.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridImageIo : public HybridImageIoSpec
    {
    public:
        HybridImageIo() : HybridObject(TAG) {}

        bool haveImageReader(const std::string& filename) override;
        bool haveImageWriter(const std::string& filename) override;
        double imcount(const std::string& filename, std::optional<ImreadModes> flags) override;
        std::shared_ptr<HybridCvMatSpec> imdecode(const std::shared_ptr<HybridCvMatSpec>& buf, ImreadModes flags, const std::optional<std::shared_ptr<HybridCvMatSpec>>& dst) override;
        bool imdecodemulti(const std::shared_ptr<HybridCvMatSpec>& buf, ImreadModes flags, const std::shared_ptr<HybridMatVectorSpec>& mats, const std::optional<std::shared_ptr<HybridCvRangeSpec>>& range) override;
        std::optional<std::shared_ptr<ArrayBuffer>> imencode(const std::string& ext, const std::shared_ptr<HybridCvMatSpec>& img, const std::optional<std::vector<std::tuple<ImwriteFlags, double>>>& params) override;
        std::optional<std::shared_ptr<ArrayBuffer>> imencodemulti(const std::string& ext, const std::shared_ptr<HybridMatVectorSpec>& imgs, const std::optional<std::vector<std::tuple<ImwriteFlags, double>>>& params) override;
        std::shared_ptr<HybridCvMatSpec> imread(const std::string& filename, std::optional<ImreadModes> flags, const std::optional<std::shared_ptr<HybridCvMatSpec>>& dst) override;
        bool imreadmulti(const std::string& filename, const std::shared_ptr<HybridMatVectorSpec>& mats, std::optional<ImreadModes> flags) override;
        bool imwrite(const std::string& filename, const std::shared_ptr<HybridCvMatSpec>& img, const std::optional<std::vector<std::tuple<ImwriteFlags, double>>>& params) override;
        bool imwritemulti(const std::string& filename, const std::shared_ptr<HybridMatVectorSpec>& img, const std::optional<std::vector<std::tuple<ImwriteFlags, double>>>& params) override;
    };
}