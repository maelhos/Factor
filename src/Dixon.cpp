#include "Dixon.h"


void Dixon::Run()
{
	begin = std::chrono::high_resolution_clock::now();
	Dixon::main();
	end = std::chrono::high_resolution_clock::now();
	timeMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}


Dixon::Dixon(mpz_t n)
{
	mpz_init(N); mpz_init(p); mpz_init(q);
	mpz_set(N, n);

}

uint64_t Dixon::FindBoundB(mpz_t n) {
	mpfr_t n2, k, k2;
	mpfr_init2(n2, 4096); 
	mpfr_init2(k, 4096); 
	mpfr_init2(k2, 4096); 
	mpfr_set_z(n2, n, MPFR_RNDN);
	
	mpfr_log(k, n2, MPFR_RNDN);
	mpfr_log(k2, k, MPFR_RNDN);

	mpfr_mul(k, k, k2, MPFR_RNDN);
	mpfr_sqrt(k, k, MPFR_RNDN);
	mpfr_exp(k, k, MPFR_RNDN);

	return mpfr_get_ui(k, MPFR_RNDN) + 1;
}

void Dixon::main() {
	std::cout << "Bound B : " << FindBoundB(N) << std::endl;
	std::cout << "Not implemented yet ... \n";

}

