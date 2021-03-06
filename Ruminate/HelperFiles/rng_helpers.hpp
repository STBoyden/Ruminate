#pragma once
#include "../../../pcg32-master/pcg32.h"
#include "../../../OptimizedHeaders-main/mat.hpp"

namespace rum
{
    static pcg32 gen(time(NULL) << 8, time(NULL) >> 8);

    class RngInit
    {
    protected:
        float lowest = 0, highest = 1;

    public:
        RngInit() = default;
        RngInit(float lowest, float highest) : lowest(lowest), highest(highest) {}
        virtual void Generator(MLMat &mat) const
        {
            for (uint32_t i = 0; i < mat.Area(); ++i)
            {
                mat.FastAt(i) = (gen.nextFloat() * this->highest) + this->lowest;
            }
        }
    };

}; // namespace rum
