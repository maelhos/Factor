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
	FactBase = (uint64_t*)malloc((1+bb) * sizeof(uint64_t));
	FactbBase = (bool*)malloc((1+bb) * sizeof(bool));

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

bool Dixon::isSmooth(mpz_t* p, uint64_t* facts, uint16_t* powers, uint64_t* numFact, uint8_t* BitVec){
	static uint32_t tempPr, tempPow, tempIndex;
	mpz_t bck;
	mpz_init_set(bck,*p);
	tempIndex = 0;
	for (uint32_t i = 0; i < FactSize; i++)
	{
		tempPr = FactBase[i];
		tempPow = 0;
		while (mpz_divisible_ui_p(bck,tempPr)){
			mpz_div_ui(bck, bck, tempPr);
			tempPow++;
		}
		if (tempPow != 0){
			facts[tempIndex] = tempPr;
			powers[tempIndex] = tempPow;
			tempIndex++;
		}
		
		BitVec[i] = tempPow & 1;
			
		
		if (mpz_cmp_ui(bck,1) == 0){
			*numFact = tempIndex;
			mpz_clear(bck);
			return true;
		}
	}
	*numFact = 0;
	mpz_clear(bck);
	return false;
}

void Dixon::Findrels(){
	mpz_t sqrt; mpz_init(sqrt);
	mpz_t k; mpz_init_set_ui(k,1);

	mpz_t a; mpz_init(a);
	mpz_t b; mpz_init(b);


	uint64_t numRels = 0;

	uint64_t* tempFacts = (uint64_t*)malloc(FactSize * sizeof(uint64_t));
	uint16_t* tempPows = (uint16_t*)malloc(FactSize * sizeof(uint16_t));
	uint8_t* tempBitVec  = (uint8_t*)malloc((FactSize+1) * sizeof(uint8_t));
	uint64_t tempnumFact;

	memset(tempBitVec,0,(FactSize+1)/8);
	std::cout << "\r" << numRels << " / " << FactSize << " ; " << (100 * numRels) / FactSize << " %";
	while (1){
		mpz_mul(sqrt,N,k);   // sqrt = sqrt(N*k)
		mpz_sqrt(sqrt,sqrt);
		for (uint8_t i = 0; i < 100; i++)
		{
			mpz_add_ui(a,sqrt,i); // a = sqrt + i;
			mpz_powm_ui(b,a,2,N);
			if (isSmooth(&b,tempFacts,tempPows,&tempnumFact,tempBitVec)){
				Rels[numRels].Facts = (uint64_t*)malloc((tempnumFact+1) * sizeof(uint64_t));
				Rels[numRels].Pows = (uint16_t*)malloc((tempnumFact+1) * sizeof(uint16_t));
				Rels[numRels].BitVec = (uint8_t*)malloc(FactSize + 1);
			
				memcpy(Rels[numRels].Facts,tempFacts,tempnumFact*8);
				memcpy(Rels[numRels].Pows,tempPows,tempnumFact*2);
				memcpy(Rels[numRels].BitVec,tempBitVec,FactSize);

				Rels[numRels].numFact = tempnumFact;
				mpz_init(Rels[numRels].k);
				mpz_set(Rels[numRels].k, a);
				numRels++;
				
				std::cout << "\r" << numRels << " / " << FactSize << " ; " << (100 * numRels) / FactSize << " %";
				if (numRels >= FactSize)
				{
					std::cout << std::endl;
					free(tempFacts);
					free(tempPows);
					free(tempBitVec);
					mpz_clear(a);
					mpz_clear(b);
					mpz_clear(sqrt);
					mpz_clear(k);
					return;
				}
			}
		}
		mpz_inc(&k);
	}

}

void Dixon::PrintRel(Rel rel){
	std::cout <<  rel.k << "^2 = ";
	if (rel.numFact == 0)
		std::cout << "1";
	for (uint64_t i = 0; i < rel.numFact; i++)
	{
		if (rel.Pows[i] == 1) std::cout << rel.Facts[i];
		else std::cout << rel.Facts[i] << "^" << rel.Pows[i];
		if (i+1 < rel.numFact) std::cout << " * ";
	}
	std::cout << " -> ";
	for (uint32_t i = 0; i < FactSize ; i++)
	{
		if (rel.BitVec[i])
		{
			std::cout << "1";
		}
		else
		{
			std::cout << "0";
		}
		
		
	}
	std::cout << std::endl;
}

void Dixon::SolveMatrix(){
	

}


void Dixon::main() {

	if (!mpz_cmp_ui(B,0)){
		FindBoundB(N);
		std::cout << "Optimal bound B : " << B << std::endl;
	}
	else std::cout << "Bound B already set by user : " << B << std::endl;
	bb = mpz_get_ui(B);
	Rels = (Rel*)malloc(bb * sizeof(Rel));

	std::cout << "Allocating and calculating Factor base mod N ..." << std::endl;
	getFactorBase();
	std::cout << "Found Factor Base ..." << std::endl;

	std::cout << "Sieving for relation mod N ..." << std::endl;
	Findrels();
	std::cout << "Sieving Done" << std::endl;

	for (uint64_t i = 0; i < FactSize; i++)
	{
		PrintRel(Rels[i]);
	}
	std::cout << std::endl;

	
}


