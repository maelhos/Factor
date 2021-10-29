#include "Fermat.h"

void Fermat::Run()
{
	begin = std::chrono::high_resolution_clock::now();
	Fermat::main();
	end = std::chrono::high_resolution_clock::now();
	timeMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}


Fermat::Fermat(mpz_t n)
{
	mpz_init(N); mpz_init(p); mpz_init(q);
	mpz_set(N, n);

}

void Fermat::main() {
	if (base_case(&N)) return;
	
	mpz_t a, b2;
	mpz_init(a); mpz_init(b2);

	mpz_sqrt(a,N); // a ← ceiling(sqrt(N))
	mpz_mul(b2, a, a); // b2 ← a*a - N
	mpz_sub(b2, b2, N);
	
	while (!((bool)mpz_perfect_square_p(b2))) { // repeat until b2 is a square:
		mpz_inc(&a); // a ← a + 1
		mpz_mul(b2, a, a); // b2 ← a*a - N 
		mpz_sub(b2, b2, N);
	}

	mpz_sqrt(b2, b2); // p ← a - sqrt(b2)
	mpz_sub(p, a, b2);

	mpz_div(q, N, p);
	std::cout << "P = " << p << "\nQ = " << q << "\n";

}

