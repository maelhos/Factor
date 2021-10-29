#include "FactorLookup.h"

int gcd(int a, int b) {
	int temp;
	while (b > 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void FactorLookup::Run()
{
	begin = std::chrono::high_resolution_clock::now();
	FactorLookup::main();
	end = std::chrono::high_resolution_clock::now();
	timeMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}


FactorLookup::FactorLookup(mpz_t n)
{
	mpz_init(N); mpz_init(p); mpz_init(q);
	mpz_set(N, n);

}

void FactorLookup::main() {
	if (base_case(&N)) return;
	uint64_t nn = mpz_get_ui(N);
	for (uint64_t i = 0; i < 65537; i++) {
		if ((gcd(nn, primes[i]) != 1) && (gcd(nn, primes[i]) != nn) ){
			mpz_set_ui(p, primes[i]);
			mpz_div(q, N, p);
			

			std::cout << "P = " << p << "\nQ = " << q << "\n";
			return;	

		}
	}
}