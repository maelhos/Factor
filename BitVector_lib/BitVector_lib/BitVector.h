#pragma once

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <cassert>

class BitVector
{
public:
	uint16_t NumberOfBits;
	uint8_t NumberOfVals;
	uint8_t NumberOfBytes;

	uint64_t* buffer;
	BitVector();
	BitVector(uint16_t _NumberOfBits);
	char* ToString();
	bool GetNthBit(uint16_t n);
	bool SetNthBit(uint16_t n, bool v);
	void XOR(BitVector* bv);
	void AND(BitVector* bv);
	void OR(BitVector* bv);
	void Clear();
	~BitVector();


private:
	char* BufferString;
	const uint8_t BitsPerVar = 64; // should be <= 64

};

