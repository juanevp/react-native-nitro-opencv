#pragma once

#include <opencv2/core/types.hpp>

#include "HybridCvRangeSpec.hpp"

namespace margelo::nitro::nitroopencv
{
    class HybridRange : public virtual HybridCvRangeSpec
    {
    private:
        cv::Range range;

    public:
        HybridRange() : HybridObject(TAG) {}
        HybridRange(cv::Range &&range) : HybridObject(TAG), range(range) {}

        cv::Range *asRangePtr()
        {
            return &range;
        }

        cv::Range &asRangeRef()
        {
            return range;
        }

        double getStart() override
        {
            return range.start;
        }

        double getEnd() override
        {
            return range.end;
        }

        bool empty() override
        {
            return range.empty();
        }

        double size() override
        {
            return range.size();
        }

        Range toJsValue() override
        {
            return Range(range.start, range.end);
        }
    };
}