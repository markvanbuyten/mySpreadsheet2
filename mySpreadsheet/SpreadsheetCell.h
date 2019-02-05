#pragma once

#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
	SpreadsheetCell();
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(std::string_view initialValue);

	void setValue(double inValue);
	double getValue() const;

	void setString(std::string_view inString);
	std::string getString() const;

	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
	//SpreadsheetCell operator+(const SpreadsheetCell& cell) const;
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);


	enum class Color {Red = 1, Green, Blue, Yellow};
	void setColor(Color color);
	Color getColor() const;

private:
	static std::string doubleToString(double inValue);
	static double stringToDouble(std::string_view inString);
	double mValue;
	Color mColor = Color::Red;
};

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);