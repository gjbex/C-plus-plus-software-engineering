#include <stdexcept>

int fib(int n) {
    if (n < 0) {
        throw std::invalid_argument("fib: n must be non-negative");
    }
    if (n <= 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
