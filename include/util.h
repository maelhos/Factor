#pragma once

#include "gmp.h"
#include <ctime>
#include <iostream>





static gmp_randstate_t rstate;

void mpz_min(mpz_t* x, mpz_t* y, mpz_t* z);
void mpz_max(mpz_t* x, mpz_t* y, mpz_t* z);

void mpz_inc(mpz_t* rop);
void mpz_dec(mpz_t* rop);

void mpz_randinit();

void mpz_randpow2(mpz_t* rop,uint64_t p);
void mpz_rand(mpz_t* rop,mpz_t* bound);


bool base_case(mpz_t* N);
void factor_power(mpz_t* rop);