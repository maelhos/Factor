#include "Brent.h"

void Brent::Run()
{
	begin = std::chrono::high_resolution_clock::now();
	Brent::main();
	end = std::chrono::high_resolution_clock::now();
	timeMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}


Brent::Brent(mpz_t n)
{
	mpz_init(N); mpz_init(p); mpz_init(q);
	mpz_set(N, n);
}

void Brent::submain(mpz_t* rop){
	mpz_t g;
	mpz_init_set(g,N); // g ← N

	mpz_t y, c, m; // those are just GMP inits ...
	mpz_inits(y, c, m, nullptr);

	mpz_t r, q, x;
	mpz_inits(r, q, x, nullptr);

	mpz_t i, k, ys, t, t2;
	mpz_inits(i, k, ys, t, t2, nullptr);


	mpz_rand(&y, &N); // y ← random number beetwen 1 and N - 1
	mpz_rand(&c, &N); // c ← random number beetwen 1 and N - 1
	//mpz_set_ui(c, 1);
	mpz_rand(&m, &N); // m ← random number beetwen 1 and N - 1

	mpz_set_ui(g, 1); // g ← 1
	mpz_set_ui(r, 1); // r ← 1
	mpz_set_ui(q, 1); // q ← 1

	while (!mpz_cmp_ui(g, 1)){ // while g = 1
		mpz_set(x, y); // x ← y
		mpz_set_ui(i, 0); // i ← 0

		while (mpz_cmp(i, r) <= 0){ // while i <= r
			mpz_powm_ui(y, y, 2, N); // y ← y^2 + c (mod N)
			mpz_add(y, y, c);
			mpz_mod(y, y, N);

			mpz_inc(&i); // i ← i + 1
		}
		mpz_set_ui(k, 0); // k ← 0
		while (mpz_cmp(k, r) < 0 && !mpz_cmp_ui(g, 1)){ // k < r and g = 1
			mpz_set(ys, y); // ys ← y
			mpz_set_ui(i, 0); // i ← 0

			mpz_sub(t, r, k); // t ← min(m, r - k)
			mpz_min(&t, &m, &t);

			while (mpz_cmp(i, t) <= 0){ // while i <= min(m, r - k)
				mpz_powm_ui(y, y, 2, N); // y ← y^2 + c (mod N)
				mpz_add(y, y, c);
				mpz_mod(y, y, N);

				mpz_sub(t2, x, y); // q ← q * |x - y| (mod N)
				mpz_abs(t2, t2);
				mpz_mul(q, q, t2);
				mpz_mod(q, q, N);

				mpz_inc(&i); // i ← i + 1
			}
			mpz_gcd(g, q, N); // g ← gcd(q, N)
			mpz_add(k, k, m); // k ← k + m
		}
		mpz_mul_ui(r, r, 2);
	}
	if (!mpz_cmp(g, N)){ // if g = N
		while (true) {
			mpz_powm_ui(ys, ys, 2, N); // ys ← ys^2 + c (mod N)
			mpz_add(ys, ys, c);
			mpz_mod(ys, ys, N);

			mpz_sub(g, x, ys); // g ← gcd(|x - ys|, N)
			mpz_abs(g, g);
			mpz_gcd(g, g, N);

			if ( mpz_cmp_ui(g, 1) > 0)   // if  N > g > 1 : return g
				break;
		}
	}
	mpz_set(*rop,g);
	return;
}

void Brent::main() {
	if (base_case(&N)) return;

	mpz_t p,q;
	mpz_inits(p, q, nullptr);
	Brent::submain(&p);
	mpz_div(q, N, p);
	std::cout << "P = " << p << "\nQ = " << q << "\n";
}

