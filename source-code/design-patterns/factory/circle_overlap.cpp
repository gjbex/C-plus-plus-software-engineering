#include <iomanip>
#include <iostream>

#include "circle.h"

int main() {
    auto circles = Circle::read_circles();
    int nr_overlapping {0};
    for (unsigned i = 0; i < circles.size(); ++i) {
        for (unsigned j = i + 1; j < circles.size(); ++j) {
            if (circles[i].has_overlap(circles[j])) {
                ++nr_overlapping;
            }
        }
    }
    std::cout << circles.size() << " " << nr_overlapping << std::endl;
    return 0;
}
