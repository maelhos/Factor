#pragma once

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include <gmp.h>
#include <mpfr.h>
#include "util.h"

class Dixon {
public:
	Dixon(mpz_t n);
	std::string name = "Dixon's method";
	std::string Complexity = "O(sqrt(N))";
	uint64_t timeMS = 0;
	mpz_t N;
	mpz_t p;
	mpz_t q;
	void Run();
	void main();
private:
	uint64_t FindBoundB(mpz_t n);;
	std::chrono::time_point<std::chrono::high_resolution_clock> begin;
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
};

