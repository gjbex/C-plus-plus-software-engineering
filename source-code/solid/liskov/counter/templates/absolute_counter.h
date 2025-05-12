#ifndef ABSOLUTE_COUNTER_HDR
#define ABSOLUTE_COUNTER_HDR

#include <numeric>
#include "counter.h"

struct AbsoluteCounter : public Counter<size_t> {
    public:
        AbsoluteCounter(int min, int max) {
            min_ = min;
            max_ = max;
            for (int i = 0; i < max_ - min_ + 1; ++i) {
                counts_.push_back(0);
            }
        }
        void add(const int value) { counts_[value - min_]++; }
        size_t size() const {
            return std::accumulate(counts_.cbegin(), counts_.cend(), 0);
        }
};

#endif
