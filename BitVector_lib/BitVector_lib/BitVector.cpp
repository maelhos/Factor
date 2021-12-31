#include "BitVector.h"

BitVector::BitVector(uint16_t _NumberOfBits)
{
	NumberOfBits = _NumberOfBits;

	NumberOfVals = NumberOfBits / BitsPerVar;
	if (NumberOfBits % BitsPerVar != 0) NumberOfVals++;

	NumberOfBytes = NumberOfBits / 8;
	if (NumberOfBits % 8 != 0) NumberOfBytes++;

	buffer = (uint64_t*)malloc(NumberOfBytes);
	assert(buffer != 0);
	memset(buffer, 0, NumberOfBytes);

	BufferString = (char*)malloc(1); // necessary for further free and malloc cycles...

}
char* BitVector::ToString() {
	free(BufferString);
	BufferString = (char*)malloc(NumberOfBits + 1);
	assert(BufferString != 0);
	uint8_t index = 0;
	uint64_t temp;
	for (uint8_t i = 0; i < NumberOfVals - 1; i++)
	{
		temp = buffer[i];
		for (uint8_t j = 0; j < BitsPerVar; j++)
		{
			BufferString[index] = (temp & 1) + 0x30;
			index++;
			temp >>= 1;
		}
	}
	temp = buffer[NumberOfVals - 1];
	uint8_t _t = NumberOfBits % BitsPerVar;
	if (_t == 0) _t += BitsPerVar;
	for (uint8_t i = 0; i < _t; i++)
	{
		BufferString[index] = (temp & 1) + 0x30;
		index++;
		temp >>= 1;
	}

	BufferString[NumberOfBits] = 0;
	return BufferString;
}

bool BitVector::SetNthBit(uint16_t n, bool v) {
	if (n > NumberOfBits - 1)
		return false;
	if (v)
		buffer[n / BitsPerVar] |= (uint64_t)v << ((uint64_t)(n % BitsPerVar));
	else
		buffer[n / BitsPerVar] &= (uint64_t)v << ((uint64_t)(n % BitsPerVar));
	return true;
}

bool BitVector::GetNthBit(uint16_t n) {
	if (n > NumberOfBits - 1)
		return false;
	uint64_t _t = buffer[n / BitsPerVar];
	return (_t >> (n % BitsPerVar)) & 1;
}

void BitVector::XOR(BitVector* bv) {
	assert(NumberOfBits == (*bv).NumberOfBits);
	for (uint8_t i = 0; i < NumberOfVals; i++)
		buffer[i] ^= (*bv).buffer[i];
}
void BitVector::OR(BitVector* bv) {
	assert(NumberOfBits == (*bv).NumberOfBits);
	for (uint8_t i = 0; i < NumberOfVals; i++)
		buffer[i] |= (*bv).buffer[i];
}
void BitVector::AND(BitVector* bv) {
	assert(NumberOfBits == (*bv).NumberOfBits);
	for (uint8_t i = 0; i < NumberOfVals; i++)
		buffer[i] &= (*bv).buffer[i];
}
void BitVector::Clear() {
	for (uint8_t i = 0; i < NumberOfVals; i++)
		buffer[i] = 0;
}

BitVector::~BitVector(){}
