#ifndef COUNTER_HDR
#define COUNTER_HDR

#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
struct Counter {
    protected:
        int min_ {0};
        int max_ {0};
        std::vector<T> counts_;

    public:
        int min() const { return min_;}
        int max() const { return max_;}
        T get_count(int value) const { return counts_[value - min_]; }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Counter<T>& counter) {
    for (int i = counter.min(); i <= counter.max(); ++i) {
        out << i << " " << counter.get_count(i) << '\n';
    }
    return out;
}

#endif
