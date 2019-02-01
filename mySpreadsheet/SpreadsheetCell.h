#pragma once

#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
	SpreadsheetCell();
	SpreadsheetCell(double initialValue);
	SpreadsheetCell(std::string_view initialValue);

	void setValue(double inValue);
	double getValue() const;

	void setString(std::string_view inString);
	std::string getString() const;

	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

private:
	static std::string doubleToString(double inValue);
	static double stringToDouble(std::string_view inString);
	double mValue;
};