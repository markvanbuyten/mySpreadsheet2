#pragma once

#include <cstddef>
#include <memory>
#include "SpreadsheetCell.h"

class SpreadsheetApp; //forward declaration

class Spreadsheet
{
public:
	
	Spreadsheet(SpreadsheetApp& theApp, size_t width = kMaxWidth, size_t height = kMaxHeight);
	Spreadsheet(const Spreadsheet& src);
	
	~Spreadsheet();


	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getID() const;

	Spreadsheet& operator=(const Spreadsheet& rhs);
	
	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

	static const size_t kMaxHeight = 100;
	static const size_t kMaxWidth = 100;


private:
	class Impl;
	std::unique_ptr<Impl> mImpl;
};

