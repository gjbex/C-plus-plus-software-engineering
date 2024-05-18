#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <cblas.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cerr<<"Usage: "<<argv[0]<<" <matrix-size>\n";
        std::exit(1);
    }
	int N {std::stoi(argv[1])}; //dimension of the random square matrices used
	
	
	std::mt19937_64 rng;
	std::uniform_real_distribution<float> rngdist{-1.0f, 1.0f};
    std::vector<float> A;
    A.resize(N*N);
    std::generate(A.begin(), A.end(), [&rng, &rngdist](){ return rngdist(rng); });
    std::vector<float> B;
    B.resize(N*N);
    std::generate(B.begin(), B.end(), [&rng, &rngdist](){ return rngdist(rng); });
    std::vector<float> C;
    C.resize(N*N);
    std::fill(C.begin(), C.end(), 0.0f);

    const float alpha = 1.0f;
    const float beta = 1.0f;
	cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, N, N, N, alpha, A.data(), N, B.data(), N, beta, C.data(), N);
	return 0;
}
