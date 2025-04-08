#include <iostream>
#include "utils.h"
#include "absolute_counter.h"
#include "relative_counter.h"

int main(int argc, char* argv[]) {
    const auto [min, max, is_output_relative] = parse_command_line(argc, argv);
    AbsoluteCounter counter(min, max);
    int value {0};
    while (std::cin >> value) {
        counter.add(value);
    }
    if (is_output_relative) {
        RelativeCounter relative_counter(counter);
        std::cout << relative_counter << std::endl;
    } else {
        std::cout << counter << std::endl;
    }
    return 0;
}
