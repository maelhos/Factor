#pragma once

#include "BitVector.h"

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <cassert>


class BitMatrix
{
public:
	BitMatrix(uint16_t _NumberOfRow, uint16_t _NumberOfColumns);
	char* ToString();
	void Solve();
	~BitMatrix();
private:
	BitMatrix* SolutionMatrix;
	BitVector** buffer;

	uint16_t NumberOfRows;
	uint16_t NumberOfColumns;
	bool* UsedRowForElimination;
	bool* UseFullRows;

	char* BufferString;

	void RemoveUselessRows();
	void XorNecessaryRows(uint16_t PivotIndex);

};
