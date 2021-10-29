#pragma once

#include <string>
#include <gmp.h>
#include <chrono>
#include <iostream>
#include <ctime>

#include "util.h"

class ECM {
public:
	ECM(mpz_t n);
	std::string name = "Polar Rho";
	std::string Complexity = "O(sqrt(N))";
	uint64_t timeMS = 0;
	mpz_t N;
	mpz_t p;
	mpz_t q;
	void Run();
	void main();
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> begin;
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
};

