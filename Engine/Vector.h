#pragma once
#include <math.h>
#include <cmath>

using namespace std;
class Vector {
public:
	Vector() = default;
	Vector(double x_in, double y_in);
	Vector operator+(const Vector& rhs) const;
	Vector& operator+=(const Vector& rhs);
	Vector operator*(const Vector& rhs) const;
	Vector& operator*=(const Vector& rhs);
	Vector operator*(double rhs) const;
	Vector& operator*=(double rhs);
	Vector operator-(const Vector& rhs) const;
	Vector& operator-=(const Vector& rhs);
	double GetLength() const;
	double GetLengthsq() const;
	Vector& Normalize();
	Vector GetNormalized() const;

	double x;
	double y;
};