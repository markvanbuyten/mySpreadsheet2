#pragma once

#include <cstddef>
#include "SpreadsheetCell.h"

class SpreadsheetApp; //forward declaration

class Spreadsheet
{
public:
	
	Spreadsheet(size_t width /*= kMaxWidth*/, size_t height /*= kMaxHeight*/, SpreadsheetApp& theApp);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&& src) noexcept; // Move constructor
	~Spreadsheet();
	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);
	size_t getID() const;

	Spreadsheet& operator=(const Spreadsheet& rhs);
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept; // Move assign
	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

	static const size_t kMaxHeight = 100;
	static const size_t kMaxWidth = 100;


private:
	void verifyCoordinate(size_t x, size_t y) const;
	//bool inRange(size_t value, size_t upper) const;
	//void cleanup() noexcept;
	//void moveFrom(Spreadsheet& src) noexcept;

	size_t mWidth;
	size_t mHeight;
	SpreadsheetCell** mCells = nullptr;
	size_t mID = 0;
	SpreadsheetApp& mTheApp;

	static inline size_t sCounter;
};