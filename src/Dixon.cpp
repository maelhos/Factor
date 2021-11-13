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

void Dixon::getFactorBase(mpz_t* N, uint64_t b){
	mpz_t temp;
	mpz_init(temp);
	uint16_t j = 0;
	assert (b <= Plength); 
	for (uint16_t i = 0; i < b; i++)
	{
		mpz_set_ui(temp,primes[i]);
		if (mpz_jacobi(*N,temp)){
			FactBase[j] = primes[i];
			j++;
		}
	}
	FactMax = FactBase[j-1];
	FactSize = j;
}	

bool Dixon::isSmooth(mpz_t* p, uint64_t* facts, uint16_t* powers){
	uint32_t tempPr, tempPow, tempIndex;
	tempIndex = 0;
	for (uint32_t i = 0; i < FactSize; i++)
	{
		tempPr = FactBase[i];
		tempPow = 0;
		while (mpz_divisible_ui_p(*p,tempPr)){
			mpz_div_ui(*p, *p, tempPr);
			tempPow++;
		}
		if (tempPow){
			facts[tempIndex] = tempPr;
			powers[tempIndex] = tempPow;
			tempIndex++;
		}
		if (!mpz_cmp_ui(*p,1)) return true;
	}
	return false;
}

void Dixon::main() {
	std::cout << "Optimal bound B : " << FindBoundB(N) << std::endl;

	std::cout << "Calculating Factor base mod N ..." << std::endl;
	getFactorBase(&N,Plength);
	std::cout << "Found Factor Base ..." << std::endl;



	
	std::cout << "Not implemented yet ... \n";

}

