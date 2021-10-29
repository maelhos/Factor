#pragma once

#include <string>
#include <gmp.h>
#include <chrono>
#include <iostream>
#include <ctime>

#include "util.h"

class PollarRho {
public:
	PollarRho(mpz_t n);
	std::string name = "Pollar Rho";
	std::string Complexity = "O(sqrt(N))";
	uint64_t timeMS = 0;
	mpz_t N;
	mpz_t p;
	mpz_t q;
	void Run();
	void main();
private:
	void f(mpz_t* y);
	std::chrono::time_point<std::chrono::high_resolution_clock> begin;
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
};
