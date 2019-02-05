#pragma once

#include <cstddef>
#include "Spreadsheet.h"
#include "SpreadsheetCell.h"

class Spreadsheet::Impl
{
public:
	Impl(const SpreadsheetApp& theApp, size_t width, size_t height);
	Impl(const Impl& src);
	~Impl();

	Impl& operator=(const Impl& rhs);

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getID() const;

private:
	void verifyCoordinate(size_t x, size_t y) const;
	void swap(Impl& other) noexcept;

	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadsheetCell** mCells = nullptr;
	size_t mID = 0;
	const SpreadsheetApp& mTheApp;

	static inline size_t sCounter;
};