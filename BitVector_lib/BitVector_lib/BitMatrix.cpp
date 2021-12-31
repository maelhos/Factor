#include "BitMatrix.h"

BitMatrix::BitMatrix(uint16_t _NumberOfRows, uint16_t _NumberOfColumns) {
	NumberOfRows = _NumberOfRows;
	NumberOfColumns = _NumberOfColumns;

	BufferString = (char*)malloc(1); // necessary for further free and malloc cycles...


	UsedRowForElimination = (bool*)malloc(NumberOfRows);
	UseFullRows = (bool*)malloc(NumberOfRows);

	assert(UsedRowForElimination != 0);
	assert(UseFullRows != 0);

	memset(UsedRowForElimination, 1, NumberOfRows);
	memset(UseFullRows, 1, NumberOfRows);


	buffer = new BitVector *[NumberOfRows];
	for (uint16_t i = 0; i < NumberOfRows; i++)
		buffer[i] = new BitVector(NumberOfColumns);


}

char* BitMatrix::ToString() {
	free(BufferString);
	BufferString = (char*)malloc((NumberOfRows+1)*NumberOfColumns + 1);
	assert(BufferString != 0);
	char* tempStr = (char*)malloc(NumberOfColumns);
	for (uint16_t i = 0; i < NumberOfRows; i++)
	{
		tempStr = (*(buffer[i])).ToString();
		memcpy(BufferString + i * NumberOfColumns, tempStr, NumberOfColumns);
		BufferString[i * (NumberOfColumns + 1) - 1] = '\n';
	}
	BufferString[(NumberOfRows + 1) * NumberOfColumns] = 0;
	return BufferString;
}







BitMatrix::~BitMatrix(){}