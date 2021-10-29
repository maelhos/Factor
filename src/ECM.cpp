#include "ECM.h"


void ECM::Run()
{
	begin = std::chrono::high_resolution_clock::now();
	ECM::main();
	end = std::chrono::high_resolution_clock::now();
	timeMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}


ECM::ECM(mpz_t n)
{
	mpz_init(N); mpz_init(p); mpz_init(q);
	mpz_set(N, n);

}


void ECM::main() {
	std::cout << "Not implemented yet ... \n";

}

