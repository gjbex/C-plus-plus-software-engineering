#ifndef RELATIVE_COUNTER_HDR
#define RELATIVE_COUNTER_HDR

#include "absolute_counter.h"
#include "counter.h"

struct RelativeCounter : public Counter<double> {
    public:
        explicit RelativeCounter(const AbsoluteCounter& counter) {
            min_ = counter.min();
            max_ = counter.max();
            double n {static_cast<double>(counter.size())};
            for (int i = counter.min(); i <= counter.max(); ++i) {
                counts_.push_back(counter.get_count(i)/n);
            }
        }
};

#endif
