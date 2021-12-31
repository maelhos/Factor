#include "BitVector.h"
#include "BitMatrix.h"
int main(int argc, int** argv) {
	BitVector test(67);
	BitVector test2(67);
	assert(test.SetNthBit(0, 1));
	assert(test.SetNthBit(1, 1));
	assert(test.SetNthBit(11, 1));
	assert(test.SetNthBit(64, 1));
	assert(test.SetNthBit(66, 1));

	assert(test2.SetNthBit(4, 1));
	assert(test2.SetNthBit(11, 1));
	assert(test2.SetNthBit(64, 1));

	std::cout << test.ToString() << std::endl;
	std::cout << test2.ToString() << std::endl;
	test2.XOR(&test);
	std::cout << test2.ToString() << std::endl;

	std::cout << "|||||||||||||||||" << "\n\n";
	BitMatrix BT(10,14);
	(BT.
	std::cout << BT.ToString() << std::endl;
	return 0;
}