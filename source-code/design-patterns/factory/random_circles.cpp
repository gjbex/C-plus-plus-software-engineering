#include <iostream>

#include "CLI/CLI.hpp"

#include "circle_factory.h"

struct Options {
    int nr_circles {10};
    double radius {0.1};
    Seed_t seed {1234};
};

Options get_options(int argc, char *argv[]) {
    Options options;
    CLI::App app {"Generate random circles"};
    app.add_option("--nr_circles", options.nr_circles,
                   "Number of circles to generate");
    app.add_option("--radius", options.radius,
                   "Radius of each generated circle");
    app.add_option("--seed", options.seed,
                   "Random seed used for generation");

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError& e) {
        std::exit(app.exit(e));
    }

    return options;
}

int main(int argc, char *argv[]) {
    Options options {get_options(argc, argv)};
    CircleFactory factory(options.radius, options.seed);
    for (int i = 0; i < options.nr_circles; ++i) {
        Circle circle {factory.create()};
        std::cout << circle << std::endl;
    }
    return 0;
}
