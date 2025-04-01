#ifndef RELATIVE_COUNTER_HDR
#define RELATIVE_COUNTER_HDR

#include <iostream>
#include <vector>
#include "absolute_counter.h"

struct RelativeCounter {
    private:
        int min_;
        int max_;
        std::vector<double> counts_;

    public:
        explicit RelativeCounter(const AbsoluteCounter& counter) {
            min_ = counter.min();
            max_ = counter.max();
            double n {static_cast<double>(counter.size())};
            for (int i = counter.min(); i <= counter.max(); ++i) {
                counts_.push_back(counter.get_count(i)/n);
            }
        }
        int min() const { return min_; }
        int max() const { return max_; }
        double get_count(int value) const { return counts_[value - min_]; }
};

std::ostream& operator<<(std::ostream& out, const RelativeCounter& counter);

#endif
