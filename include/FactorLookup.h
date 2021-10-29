#pragma once

#include <string>
#include <gmp.h>
#include <chrono>
#include <iostream>

#include "primesUpTo2to16.h"
#include "util.h"
class FactorLookup {
public:
	FactorLookup(mpz_t n);
	std::string name = "Lookup Table";
	std::string Complexity = "O(1)";
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

#pragma once
