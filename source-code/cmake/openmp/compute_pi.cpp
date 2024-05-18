#include <iostream>
#ifdef _OPENMP
#include <omp.h>
#endif
#include <random>

int main(int argc, char* argv[]) {
    const long nr_tries {argc > 1 ? std::stol(argv[1]) : 10'000};
    long count {0};
#pragma omp parallel default(none) shared(nr_tries, count)
    {
        long nr_threads {1};
#ifdef _OPENMP
        nr_threads = omp_get_num_threads();
#endif
        long nr_thread_tries {nr_tries/nr_threads};
#ifdef _OPENMP
        if (omp_get_thread_num() == 0) {
            nr_thread_tries += nr_tries % nr_threads;
        }
#endif
        std::random_device random_device;
        auto seed {random_device()};
#ifdef _OPENMP
        seed %= 1 + omp_get_thread_num();
#endif
        std::mt19937_64 engine(seed);
        std::uniform_real_distribution<double> distr(-1.0, 1.0);
#pragma omp for reduction(+:count)
        for (long try_nr = 0; try_nr < nr_thread_tries; ++try_nr) {
            double x {distr(engine)};
            double y {distr(engine)};
            if (x*x + y*y < 1.0) {
                count++;
            }
        }
#pragma omp single
        count *= nr_threads;
    }
    std::cout << "pi = " << 4.0*static_cast<double>(count)/nr_tries << "\n";
    return 0;
}
