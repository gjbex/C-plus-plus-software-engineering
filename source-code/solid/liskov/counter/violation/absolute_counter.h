#ifndef COUNTER_HDR
#define COUNTER_HDR

#include <iostream>
#include <numeric>
#include <vector>

struct AbsoluteCounter {
    protected:
        int min_;
        int max_;
        std::vector<int> counts_;

    public:
        AbsoluteCounter() : min_{0}, max_{0} {}
        AbsoluteCounter(int min, int max) {
            min_ = min;
            max_ = max;
            for (int i = 0; i < max_ - min_ + 1; ++i) {
                counts_.push_back(0);
            }
        }
        int min() const { return min_;}
        int max() const { return max_;}
        int get_count(int value) const { return counts_[value - min_]; }
        void add(int value) { counts_[value - min_]++; }
        int size() const {
             return std::accumulate(counts_.begin(), counts_.end(), 0);
        }
};

std::ostream& operator<<(std::ostream& out, const AbsoluteCounter& counter);

#endif
