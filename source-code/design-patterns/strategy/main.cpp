#include <iostream>
#include <memory>
#include <random>
#include <string>

#include "CLI/CLI.hpp"

#include "automaton_runner.h"
#include "cycle_finder.h"

Automaton init_automaton(const size_t nr_cells, const size_t seed) {
    Automaton automaton(nr_cells);
    std::mt19937_64 engine(seed);
    std::uniform_int_distribution<uint8_t> distr(0, 1);
    for (size_t cell_nr = 0; cell_nr < automaton.size(); ++cell_nr) {
        automaton[cell_nr] = distr(engine);
    }
    return automaton;
}

class PrintHandler: public GenerationHandler {
    public:
        bool handle(const Automaton& automaton) override {
            for (const auto& value: automaton) {
                if (value == 0) {
                    std::cout << ' ';
                } else {
                    std::cout << 'X';
                }
            }
            std::cout << '\n';
            return true;
        }
};

class DoNothingHandler: public GenerationHandler {
    public:
        bool handle([[maybe_unused]] const Automaton& automaton) override {
            return true;
        }
};

struct Options {
    size_t nr_cells;
    unsigned int rule_nr;
    size_t nr_generations;
    size_t seed;
    std::string handler_name;
};

Options get_options(int argc, char *argv[]) {
    Options options {10, 47, 20, 1234, "visualize"};

    CLI::App app {"Run a one-dimensional cellular automaton"};
    app.add_option("--nr_cells", options.nr_cells,
                   "Number of cells in the automaton");
    app.add_option("--rule_nr", options.rule_nr,
                   "Elementary cellular automaton rule number")
        ->check(CLI::Range(0U, 255U));
    app.add_option("--nr_generations", options.nr_generations,
                   "Number of generations to evolve");
    app.add_option("--seed", options.seed,
                   "Seed used to initialize the automaton");
    app.add_option("--handler", options.handler_name,
                   "Generation handler")
        ->check(CLI::IsMember({"visualize", "nothing", "cycles"}));

    try {
        app.parse(argc, argv);
        if (options.nr_cells < 2) {
            throw CLI::ValidationError("--nr_cells", "must be at least 2");
        }
    } catch (const CLI::ParseError& e) {
        std::exit(app.exit(e));
    }

    return options;
}

std::unique_ptr<GenerationHandler> make_handler(const std::string& handler_name) {
    if (handler_name == "nothing") {
        return std::make_unique<DoNothingHandler>();
    }
    if (handler_name == "cycles") {
        return std::make_unique<CycleFinder>();
    }
    return std::make_unique<PrintHandler>();
}

int main(int argc, char *argv[]) {
    Options options {get_options(argc, argv)};
    auto handler = make_handler(options.handler_name);
    Automaton automaton = init_automaton(options.nr_cells, options.seed);
    AutomatonRunner runner(static_cast<uint8_t>(options.rule_nr));
    runner.evolve(automaton, options.nr_generations, handler.get());
    if (CycleFinder* gen_handler = dynamic_cast<CycleFinder*>(handler.get());
            gen_handler != nullptr) {
        std::cout << gen_handler->cycle_length() << "\n";
    }
    return 0;
}
