#pragma once

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
	double x;
	double y;
};