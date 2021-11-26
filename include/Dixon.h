#pragma once

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include <gmp.h>
#include <mpfr.h>
#include <bits/stdc++.h>

#include <primesUpTo2to16.h>
#include "util.h"
#include "assert.h"

class Dixon {
public:
	Dixon(mpz_t n, mpz_t b);

	std::string name = "Dixon's method";
	std::string Complexity = "O(sqrt(N))";

	uint64_t timeMS = 0;

	mpz_t N;
	mpz_t B;
	mpz_t p;
	mpz_t q;
	void Run();
	void main();
private:
	struct Rel
	{
		mpz_t* k;
		uint64_t* Facts;
		uint16_t* Pows;
		uint64_t numFact;
	};
	Rel* Rels;
	uint64_t* FactBase;
	uint64_t FactSize;
	uint64_t FactMax;
	uint64_t bb;
	void FindBoundB(mpz_t n);;
	void getFactorBase();
	bool isSmooth(mpz_t* p, uint64_t* facts, uint16_t* powers, uint64_t* numFact);
	void Findrels();

	std::chrono::time_point<std::chrono::high_resolution_clock> begin;
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
};

