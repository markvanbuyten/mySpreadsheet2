#pragma once

#include "SpreadsheetCell.h"
#include <string>
#include <string_view>
#include <optional>

class StringSpreadsheetCell : public SpreadsheetCell
{
public:
	virtual void set(std::string_view inString) override;
	virtual std::string getString() const override;

private:
	std::optional<std::string> mValue;
};