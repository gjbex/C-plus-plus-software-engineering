#include "relative_counter.h"

std::ostream& operator<<(std::ostream& out, const RelativeCounter& counter) {
    for (int i = counter.min(); i <= counter.max(); ++i) {
        out << i << " " << counter.get_count(i) << '\n';
    }
    return out;
}

