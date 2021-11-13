#pragma once

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include <gmp.h>
#include <mpfr.h>

#include <primesUpTo2to16.h>
#include "util.h"
#include "assert.h"

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
	uint64_t FactBase[6543] = {0};
	uint32_t FactSize;
	uint32_t FactMax;
	uint64_t FindBoundB(mpz_t n);;
	void getFactorBase(mpz_t* N, uint64_t b);
	bool isSmooth(mpz_t* p, uint64_t* facts, uint16_t* powers);

	std::chrono::time_point<std::chrono::high_resolution_clock> begin;
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
};

