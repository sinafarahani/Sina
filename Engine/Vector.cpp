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
