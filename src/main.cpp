#include <iostream>
#include <gmp.h>
#include <chrono>
#include <ctype.h>
#include <cstring>

#include "util.h"
#include "benchmark.h"
#include "autofactor.h"

#include "FactorLookup.h"
#include "Fermat.h"
#include "PollarRho.h"
#include "Brent.h"
#include "Dixon.h"

uint64_t benchMarkBitLength = 70; 

void print_usage(char* argv0){
	std::cout << "Usage : " << argv0 << " algorithm N\n";
	std::cout << "Algorithm implemented :\n" ;

	std::cout << " - Fermat : fermat\n";
	std::cout << " - Pollar Rho : pollar\n";
	std::cout << " - Pollar-Brent (faster than Rho) : brent\n";
	std::cout << " - Dixon's method : dixon\n";

	std::cout << "You can also use the auto mode which will use the best algo for your number,\n";
	std::cout << "to do this, use mode \"auto\" or just : " << argv0 << " N\n";
	std::cout << "Or use benchmark with -b\n";
	exit(0);
}
void print_wrong_algo(char** argv){
	std::cout << "Sorry but the algo : " << argv[1] << " does not exist (yet...) \nHere are the existing ones :\n";
	print_usage(argv[0]);
}
static char digits[11] = "0123456789";
int main(int argc, char* argv[]) {
	if (argc == 1){
		print_usage(*argv);
	}
	mpz_randinit();
	if (argc == 2) {
		if (argv[1][0] == '-' && argv[1][1] == 'b') {
			benchmark(benchMarkBitLength);
			return 0;
		}
		else {
			bool isDigit;
			for (uint64_t i = 0; i < strlen(argv[1]); i++){
				isDigit = false;
				for (uint8_t j = 0; j < 10; j++){
					isDigit |= (argv[1][i] != j + 0x30);
				}
				if (!isdigit) {
					print_usage(*argv);
					return 0;
				}
			}
			mpz_t N;
			mpz_init(N);
			mpz_set_str(N,argv[1],10);

			std::cout << "Running auto mode on : " << N << std::endl << std::endl;
			AutoFactor(N);
			return 0;
		}
	}
	
	if (argc > 4) {
		print_usage(*argv);
		return 0;
	}

	mpz_t N;
	mpz_init(N);
	mpz_set_str(N,argv[2],10);

	if (!std::strcmp(argv[1],"fermat")){
		std::cout << "Running Fermat's algorithm on : " << N << std::endl << std::endl;
		Fermat Fn(N);
		Fn.Run();
		std::cout << std::endl << "Time used : " << ((double)Fn.timeMS) << " ms or " << ((double)Fn.timeMS) / 1000 << "seconds\n";
	}
	else if (!std::strcmp(argv[1],"pollar")){
		std::cout << "Running Pollar Rho algorithm on : " << N << std::endl << std::endl;
		PollarRho Pr(N);
		Pr.Run();
		std::cout << std::endl << "Time used : " << ((double)Pr.timeMS) << " ms or " << ((double)Pr.timeMS) / 1000 << "seconds\n";
	}
	else if (!std::strcmp(argv[1],"brent")){
		std::cout << "Running Pollar-Brent algorithm (faster than Pollar Rho) on : " << N << std::endl << std::endl;
		Brent Br(N);
		Br.Run();
		std::cout << std::endl << "Time used : " << ((double)Br.timeMS) << " ms or " << ((double)Br.timeMS) / 1000 << "seconds\n";
	}
	else if (!std::strcmp(argv[1],"dixon")){
		mpz_t BB;
		mpz_init_set_ui(BB,0);

		if (argc == 3) std::cout << "Running Dixon on an default B and N : " << N << std::endl << std::endl;
		else {
			mpz_set_str(BB,argv[3],10);
			std::cout << "Running Dixon on an custom B and N  : " << N << " and B " << BB << std::endl << std::endl;
		}


		Dixon Dr(N, BB);
		Dr.Run();
		std::cout << std::endl << "Time used : " << ((double)Dr.timeMS) << " ms or " << ((double)Dr.timeMS) / 1000 << "seconds\n";


	}
	else if (!std::strcmp(argv[1],"auto")){
		std::cout << "Running auto mode on : " << N << std::endl << std::endl;
		AutoFactor(N);
	}
	else print_wrong_algo(argv);

	return 0;
}