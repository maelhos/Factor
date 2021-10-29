#pragma once

#include <string>
#include <gmp.h>
#include <chrono>
#include <iostream>

#include "util.h"

class Fermat {
public:
	Fermat(mpz_t n);
	std::string name = "Fermat";
	std::string Complexity = "O(N^(1/2))";
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

