// A DMMul reference implementation using MKL

#include <algorithm>
#include <iostream>
#include <random>

#include "mkl.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <N>\n";
        std::exit(1);
    }
    // Number Dimensions of our matrix
    std::size_t N = std::stoul(argv[1]);

    // Create our random number generators
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<float> dist(-10.0f, 10.0f);

    // Create input matrices
    float *A = (float *)mkl_malloc(N * N * sizeof(float), 64);
    float *B = (float *)mkl_malloc(N * N * sizeof(float), 64);
    float *C = (float *)mkl_malloc(N * N * sizeof(float), 64);

    // Initialize them with random values (and C to 0)
    std::generate(A, A + N * N, [&] { return dist(rng); });
    std::generate(B, B + N * N, [&] { return dist(rng); });
    std::generate(C, C + N * N, [&] { return 0; });

    // MMul scaling constants
    float alpha = 1.0f;
    float beta = 0.0f;

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, alpha, A, N,
            B, N, beta, C, N);

    // Free memory
    mkl_free(A);
    mkl_free(B);
    mkl_free(C);
    return 0;
}
