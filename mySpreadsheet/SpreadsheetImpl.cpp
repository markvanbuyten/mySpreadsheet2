#include "SpreadsheetImpl.h"
#include "Spreadsheet.h"
#include <stdexcept>
#include <utility>
#include <algorithm>

Spreadsheet::Impl::Impl(const SpreadsheetApp& theApp, size_t width, size_t height)
	:mID(sCounter++)
	, mWidth(std::min(width, Spreadsheet::kMaxWidth))
	, mHeight(std::min(height, Spreadsheet::kMaxHeight))
	, mTheApp(theApp)
{
	mCells = new SpreadsheetCell*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

Spreadsheet::Impl::Impl(const Impl & src)
	:Impl(src.mTheApp, src.mWidth, src.mHeight)
{
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

Spreadsheet::Impl::~Impl()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

Impl & Spreadsheet::Impl::operator=(const Impl & rhs)
{

	// Check for self-assignment
	if (this == &rhs) {
		return *this;
	}

	Spreadsheet temp(rhs); //Do all the work in a temporary instance
	swap(*this, temp);
	return *this;
}

void Spreadsheet::Impl::setCellAt(size_t x, size_t y, const SpreadsheetCell & cell)
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}

SpreadsheetCell & Spreadsheet::Impl::getCellAt(size_t x, size_t y)
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

size_t Spreadsheet::Impl::getID() const
{
	return mID;
}

void Spreadsheet::Impl::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

void Spreadsheet::Impl::swap(Impl & other) noexcept
{
	using std::swap;

	swap(mWidth, other.mWidth);
	swap(mHeight, other.mHeight);
	swap(mCells, other.mCells);
}
