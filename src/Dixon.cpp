#include "Dixon.h"


void Dixon::Run()
{
	begin = std::chrono::high_resolution_clock::now();
	Dixon::main();
	end = std::chrono::high_resolution_clock::now();
	timeMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}


Dixon::Dixon(mpz_t n,mpz_t b)
{
	mpz_init(N); mpz_init(p);mpz_init(q);mpz_init(B);
	mpz_set(N, n);
	mpz_set(B, b);
	bb = mpz_get_ui(B) + 1;
	Rels = (Rel*)malloc(bb * sizeof(Rel));
}

void Dixon::FindBoundB(mpz_t n) {
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

	mpz_set_fr(B,k,MPFR_RNDN);
}

void Dixon::getFactorBase(){
	static uint64_t num = 0;
	
	bool* FactbBase;
	FactBase = (uint64_t*)malloc(bb * sizeof(uint64_t));
	FactbBase = (bool*)malloc(bb * sizeof(bool));

	std::memset(FactbBase, true, bb * sizeof(bool));
	std::memset(FactBase, 0, bb * sizeof(uint64_t));

	for (uint64_t p = 2; p * p <= bb; p++)
    {
        if (FactbBase[p])
        {
            for (uint64_t i = p * p; i <= bb; i += p)
                FactbBase[i] = 0;
        }
    }
	for (uint64_t i = 2; i < bb; i++)
	{
		if (FactbBase[i]){
			FactBase[num] = i;
			num++;
		}
	}
	FactSize = num;
	FactMax = FactBase[FactSize-1];
	free(FactbBase); // dont need anymore
	FactBase = (uint64_t*)realloc(FactBase,(FactSize + 1) * sizeof(uint64_t)); // crop the size to save space
}	

bool Dixon::isSmooth(mpz_t* p, uint64_t* facts, uint16_t* powers, uint64_t* numFact){
	static uint32_t tempPr, tempPow, tempIndex;
	mpz_t bck;
	mpz_init_set(bck,*p);
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
		if (!mpz_cmp_ui(*p,1)){
			*numFact = tempIndex;
			mpz_set(*p,bck);
			return true;
		}
	}
	return false;
}

void Dixon::Findrels(){
	mpz_t r; mpz_init(r);
	mpz_sqrt(r,N);
	uint64_t numRels = 0;

	mpz_t fs; mpz_init(fs);
	uint64_t* tempFacts = (uint64_t*)malloc(FactSize * sizeof(uint64_t));
	uint16_t* tempPows = (uint16_t*)malloc(FactSize * sizeof(uint16_t));
	uint64_t* numFact = (uint64_t*)malloc(sizeof(uint64_t));
	while (numRels < bb){
		mpz_mul(fs,r,r); // fs = (r^2) mod N
		mpz_mod(fs,fs,N);
		if (isSmooth(&fs,tempFacts,tempPows,numFact)){
			memcpy(Rels[numRels].Facts,tempFacts,*numFact);
			memcpy(Rels[numRels].Pows,tempPows,*numFact);
			Rels[numRels].numFact = *numFact;
			numRels++;
		}
		mpz_inc(&r);
	}
	free(tempFacts);
	free(tempPows);
	free(numFact);
}
void Dixon::main() {

	if (!mpz_cmp_ui(B,0)){
		FindBoundB(N);
		std::cout << "Optimal bound B : " << B << std::endl;
	}
	else std::cout << "Bound B already set by user : " << B << std::endl;


	std::cout << "Allocating and calculating Factor base mod N ..." << std::endl;
	getFactorBase();
	std::cout << "Found Factor Base ..." << std::endl;


	std::cout << "Not implemented yet ... \n";

}

