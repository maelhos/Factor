#include "autofactor.h"

void AutoFactor(mpz_t N) {
    mpz_t b2p16, b2p70, b10p50, b10p100;
    mpz_init(b2p16); 	          mpz_init(b2p70);	             mpz_init(b10p50); 		         mpz_init(b10p100);
	mpz_set_ui(b2p16, 2);         mpz_set_ui(b2p70, 2);          mpz_set_ui(b10p50, 10);         mpz_set_ui(b10p100, 10);
	mpz_pow_ui(b2p16, b2p16, 16); mpz_pow_ui(b2p70, b2p70, 100); mpz_pow_ui(b10p50, b10p50, 50); mpz_pow_ui(b10p50, b10p50, 100); 

	if (mpz_cmp(N, b2p16) < 0) {
		std::cout << "N less than 2^16 ... going for lookup table\n";

		FactorLookup FL(N);
		FL.Run();
		std::cout << "Time used : " << ((double)FL.timeMS) << " ms or " << ((double)FL.timeMS) / 1000 << "seconds\n";
		return;
	}
	else if (mpz_cmp(N, b2p70) < 0) {
		std::cout << "N less than 2^100 ... going for Pollar-Brent Variation of Pollar Rho (faster)\n";

		Brent Br(N);
		Br.Run();
		std::cout << "Time used : " << ((double)Br.timeMS) << " ms or " << ((double)Br.timeMS) / 1000 << "seconds\n";
		return;
	}
	else if (mpz_cmp(N, b10p50) < 0) {
		std::cout << "N less than 10^50 ... going for Dixon\n";

		mpz_t BB;
		mpz_init_set_ui(BB, 0);
		Dixon Dx(N,BB);
		Dx.Run();
		std::cout << "Time used : " << ((double)Dx.timeMS) << " ms or " << ((double)Dx.timeMS) / 1000 << "seconds\n";
		return;
	}
	std::cout << "No technique for that number yet...";
}