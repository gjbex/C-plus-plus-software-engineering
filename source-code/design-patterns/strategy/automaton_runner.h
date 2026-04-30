#ifndef AUTOMATON_RUNNER_HDR
#define AUTOMATON_RUNNER_HDR

#include <array>
#include <cstdint>
#include <valarray>
#include <functional>

using Rules = std::array<uint8_t, 8>;
using Automaton = std::valarray<uint8_t>;

class GenerationHandler {
    public:
        [[nodiscard]] virtual bool handle([[maybe_unused]] const Automaton& automaton) { return true; }
        virtual ~GenerationHandler() = default;
};

class AutomatonRunner {
    private:
        Rules rules;
        Automaton next_generation(const Automaton& automaton);
    public:
        AutomatonRunner(uint8_t rule_nr);
        void evolve(Automaton& automaton, const size_t nr_generations,
                    GenerationHandler* handler);
};

#endif
