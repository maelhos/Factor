#include "PollarRho.h"

void PollarRho::Run()
{
	begin = std::chrono::high_resolution_clock::now();
	PollarRho::main();
	end = std::chrono::high_resolution_clock::now();
	timeMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}


PollarRho::PollarRho(mpz_t n)
{
	mpz_init(N); mpz_init(p); mpz_init(q);
	mpz_set(N, n);

}

void PollarRho::f(mpz_t* y) {
	mpz_mul(*y, *y, *y);
	mpz_add_ui(*y, *y, 1);
	mpz_mod(*y, *y, N);
}


void PollarRho::main() {
	mpz_t x, y, d;
	if (base_case(&N)) return;

	mpz_init_set_ui(x,2); // x ← 2
	mpz_init_set_ui(y,2); // y ← 2
	mpz_init_set_ui(d,1); // d ← 1

	while (!mpz_cmp_ui(d,1)){ // while d = 1:
		f(&x); // x ← f(x)

		f(&y); // y ← f(f(y))
		f(&y); 

		mpz_sub(d,x,y); // d ← gcd(|x - y|, N)
		mpz_abs(d,d);
		mpz_gcd(d,d,N);
	}
	mpz_set(p,d); // return d
	mpz_div(q,N,p);

	std::cout << "P = " << p << "\nQ = " << q << "\n";

}

