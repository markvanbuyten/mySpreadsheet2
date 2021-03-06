#include "Spreadsheet.h"
#include "SpreadsheetImpl.h"
#include <utility>
#include <algorithm>

//size_t Spreadsheet::sCounter;

Spreadsheet::Spreadsheet(SpreadsheetApp& theApp, size_t width, size_t height)
{
	mImpl = std::make_unique<Impl>(theApp, width, height);
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
{
	mImpl = std::make_unique<Impl>(*src.mImpl);
}

Spreadsheet::~Spreadsheet() = default;


void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell & cell)
{
	mImpl->setCellAt(x, y, cell);
}

SpreadsheetCell & Spreadsheet::getCellAt(size_t x, size_t y)
{
	
	return mImpl->getCellAt(x, y);
}

size_t Spreadsheet::getID() const
{
	return mImpl->getID();
}

Spreadsheet & Spreadsheet::operator=(const Spreadsheet & rhs)
{
	*mImpl = *rhs.mImpl;
	return *this;
}


void swap(Spreadsheet & first, Spreadsheet & second) noexcept
{
	using std::swap;

	swap(first.mImpl, second.mImpl);
}
