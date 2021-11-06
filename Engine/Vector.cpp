#include "Vector.h"

Vector::Vector(double x_in, double y_in)
	:
	x(x_in),
	y(y_in)
{
}

Vector Vector::operator+(const Vector& rhs) const
{
	return Vector(x+rhs.x,y+rhs.y);
}

Vector& Vector::operator+=(const Vector& rhs)
{
	return *this = *this + rhs;
}

Vector Vector::operator*(const Vector& rhs) const
{
	return Vector(x*rhs.x,y*rhs.y);
}

Vector& Vector::operator*=(const Vector& rhs)
{
	return *this = *this * rhs;
}

Vector Vector::operator*(double rhs) const
{
	return Vector(x*rhs,y*rhs);
}

Vector& Vector::operator*=(double rhs)
{
	return *this = *this * rhs;
}

Vector Vector::operator-(const Vector& rhs) const
{
	return Vector(x-rhs.x,y-rhs.y);
}

Vector& Vector::operator-=(const Vector& rhs)
{
	return *this = *this - rhs;
}

double Vector::GetLength() const
{
	return sqrt(GetLengthsq());
}

double Vector::GetLengthsq() const
{
	return x*x + y*y;
}

Vector& Vector::Normalize()
{
	return *this = GetNormalized();
}

Vector Vector::GetNormalized() const
{
	const double len = GetLength();
	if (len != 0.0)
	{
		return *this * (1.0 / len);
	}
	return *this;
}