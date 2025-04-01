#include <boost/program_options.hpp>
#include <iostream>

#include "utils.h"

/*@
 * @brief This function is used to parse the command line arguments
 *
 * The application takes two mandatory integer values as the input. The first
 * integer is the minimum value to count, the second the maximum values.  It
 * also takes a flag `--relative` that indicates that the resulting histogram
 * should be normalized to the total number of values in the output.
 *
 * @param argc The number of command line arguments
 * @param argv The command line arguments
 *
 * @return A tuple containing the minimum value, the maximum value, and a flag
 * indicating whether the histogram should be normalized.
 */
std::tuple<int, int, bool> parse_command_line(int argc, char* argv[]) {
    namespace po = boost::program_options;

    int min_value;
    int max_value;
    bool relative;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("min", po::value<int>(&min_value)->required(), "the minimum value to count")
        ("max", po::value<int>(&max_value)->required(), "the maximum value to count")
        ("relative", po::bool_switch(&relative), "normalize the histogram to the total number of values");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        exit(0);
    }

    po::notify(vm);

    if (min_value > max_value) {
        std::cerr << "The minimum value must be less than or equal to the maximum value" << std::endl;
        exit(1);
    }

    return std::make_tuple(min_value, max_value, relative);
}
