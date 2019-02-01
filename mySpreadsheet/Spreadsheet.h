#pragma once

#include <cstddef>
#include "SpreadsheetCell.h"

class Spreadsheet
{
public:
	
	Spreadsheet(size_t width = 100, size_t height = 100);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&& src) noexcept; // Move constructor
	~Spreadsheet();
	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	Spreadsheet& operator=(const Spreadsheet& rhs);
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept; // Move assign
	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;


private:
	void verifyCoordinate(size_t x, size_t y) const;
	//bool inRange(size_t value, size_t upper) const;
	//void cleanup() noexcept;
	//void moveFrom(Spreadsheet& src) noexcept;

	size_t mWidth;
	size_t mHeight;
	SpreadsheetCell** mCells = nullptr;
};