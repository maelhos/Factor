#include "util.h"


void mpz_min(mpz_t* x, mpz_t* y, mpz_t* z) {
	if (mpz_cmp(*z, *y) >= 0) {
		mpz_set(*x, *y);
	}
	else {
		mpz_set(*x, *z);
	}
}

void mpz_max(mpz_t* x, mpz_t* y, mpz_t* z) {
	if (mpz_cmp(*z, *y) >= 0) {
		mpz_set(*x, *z);
	}
	else {
		mpz_set(*x, *y);
	}
}

void mpz_inc(mpz_t* rop) {mpz_add_ui(*rop,*rop,1);};

void mpz_dec(mpz_t* rop) {mpz_sub_ui(*rop,*rop,1);};

void mpz_randinit(){
    gmp_randinit_mt(rstate);
    gmp_randseed_ui(rstate, std::time(nullptr));
}

void mpz_randpow2(mpz_t* rop,uint64_t p){
	mpz_urandomb(*rop, rstate, p);
}

void mpz_rand(mpz_t* rop,mpz_t* bound){
    mpz_t temp;
    mpz_init_set(temp,*bound);
    mpz_dec(&temp);
	mpz_urandomm(*rop, rstate, temp);
}

void factor_power(mpz_t* rop){
	uint64_t i = 1;
    while (!mpz_root(nullptr,*rop,i)) i++;
    mpz_root(*rop,*rop,i);
}

bool base_case(mpz_t* N){
    if (mpz_probab_prime_p (*N,35)){
        std::cout << "(Base case : N is prime ...)" << std::endl;
        std::cout << "P = " << *N << "\nQ = " << 1 << "\n";
        return true;
    }
    else if (mpz_perfect_power_p(*N)){
        mpz_t p;
        mpz_init_set(p,*N);
        factor_power(N);
        std::cout << "(Base case : N a perfect power ...)" << std::endl;
        std::cout << "P = " << p << "\nQ = " << *N << "\n";
        return true;

    }
    else if (!mpz_odd_p(*N)){
        mpz_div_ui(*N,*N,2);
        std::cout << "(Base case : N is even ...)" << std::endl;
        std::cout << "P = " << *N << "\nQ = " << 2 << "\n";
        return true;
    } 
    return false;
}