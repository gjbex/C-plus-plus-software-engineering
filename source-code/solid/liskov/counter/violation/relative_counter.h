#ifndef RELATIVE_COUNTER_HDR
#define RELATIVE_COUNTER_HDR

#include <iostream>
#include <vector>
#include "absolute_counter.h"

struct RelativeCounter : public AbsoluteCounter {
    private:
        std::vector<double> counts_;

    public:
        explicit RelativeCounter(const AbsoluteCounter& counter) :
            AbsoluteCounter(counter.min(), counter.max()) {
            double n {static_cast<double>(counter.size())};
            for (int i = counter.min(); i <= counter.max(); ++i) {
                counts_.push_back(counter.get_count(i)/n);
            }
        }
        double get_count(int value) const { return counts_[value - min_]; }
};

std::ostream& operator<<(std::ostream& out, const RelativeCounter& counter);

#endif
