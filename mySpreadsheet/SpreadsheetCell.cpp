#include "SpreadsheetCell.h"

using namespace std;

SpreadsheetCell::SpreadsheetCell()
{
	mValue = 0;
}

SpreadsheetCell::SpreadsheetCell(double initialValue)
{
	setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(std::string_view initialValue)
{
	setString(initialValue);
}

void SpreadsheetCell::setValue(double inValue)
{
	mValue = inValue;
}

double SpreadsheetCell::getValue() const
{
	return mValue;
}

void SpreadsheetCell::setString(string_view inString)
{
	mValue = stringToDouble(inString);
}

string SpreadsheetCell::getString() const
{
	return doubleToString(mValue);
}

SpreadsheetCell & SpreadsheetCell::operator=(const SpreadsheetCell & rhs)
{
	if (this == &rhs) {
		return *this;
	}

	mValue = rhs.mValue;
	return *this;
}

SpreadsheetCell & SpreadsheetCell::operator+=(const SpreadsheetCell & rhs)
{
	setValue(getValue() + rhs.getValue());
	return *this;
}

SpreadsheetCell & SpreadsheetCell::operator-=(const SpreadsheetCell & rhs)
{
	setValue(getValue() - rhs.getValue());
	return *this;
}

SpreadsheetCell & SpreadsheetCell::operator*=(const SpreadsheetCell & rhs)
{
	setValue(getValue() + rhs.getValue());
	return *this;
}

SpreadsheetCell & SpreadsheetCell::operator/=(const SpreadsheetCell & rhs)
{
	setValue(getValue() / rhs.getValue());
	return *this;
}

/*SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& cell) const
{
	return SpreadsheetCell(getValue() + cell.getValue());
}*/

void SpreadsheetCell::setColor(Color color)
{
	mColor = color;
}

SpreadsheetCell::Color SpreadsheetCell::getColor() const
{
	return Color();
}

string SpreadsheetCell::doubleToString(double inValue)
{
	return to_string(inValue);
}

double SpreadsheetCell::stringToDouble(string_view inString)
{
	return strtod(inString.data(), nullptr);
}

SpreadsheetCell operator+(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return SpreadsheetCell(lhs.getValue + rhs.getValue);
}

SpreadsheetCell operator-(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return SpreadsheetCell(lhs.getValue() - rhs.getValue());
}

SpreadsheetCell operator*(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return SpreadsheetCell(lhs.getValue() * rhs.getValue());
}

SpreadsheetCell operator/(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	if (rhs.getValue() == 0) {
		throw invalid_argument("Divide by zero.");
	}
	return SpreadsheetCell(lhs.getValue() / rhs.getValue());
}
