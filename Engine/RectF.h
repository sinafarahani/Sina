#pragma once

#include "Vector.h"

class RectF
{
public:
	RectF() = default;
	RectF( double left_in,double right_in,double top_in,double bottom_in );
	RectF( const Vector& topLeft,const Vector& bottomRight );
	RectF( const Vector& topLeft,double width,double height );
	bool IsOverlappingWith( const RectF& other ) const;
	bool IsContainedBy( const RectF& other ) const;
	bool Contains(const Vector& point) const;
	static RectF FromCenter( const Vector& center,double halfWidth,double halfHeight );
	RectF GetExpanded( double offset ) const;
	Vector GetCenter() const;
public:
	double left;
	double right;
	double top;
	double bottom;
};