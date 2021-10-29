#include "benchmark.h"

void benchmark(uint64_t bitlen){
    mpz_t p, q, N, b;
	mpz_init(p); mpz_init(q); mpz_init(N); mpz_init(b);

	mpz_randpow2(&p,bitlen/2);
	mpz_randpow2(&q,bitlen/2);

	mpz_nextprime(p, p);
	mpz_nextprime(q, q);

	mpz_mul(N, p, q);
	std::cout << "Benchmark mode in 2^" << bitlen << " bit mode \n";
	std::cout << "P = " << p << "\nQ = " << q << "\nN = p*q = " << N << "\n\n";
	AutoFactor(N);
}