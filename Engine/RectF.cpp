#include "RectF.h"

RectF::RectF( double left_in,double right_in,double top_in,double bottom_in )
	:
	left( left_in ),
	right( right_in ),
	top( top_in ),
	bottom( bottom_in )
{
}

RectF::RectF( const Vector& topLeft,const Vector & bottomRight )
	:
	RectF( topLeft.x,bottomRight.x,topLeft.y,bottomRight.y )
{
}

RectF::RectF( const Vector& topLeft,double width,double height )
	:
	RectF( topLeft,topLeft + Vector( width,height ) )
{
}

bool RectF::IsOverlappingWith( const RectF& other ) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

bool RectF::IsContainedBy( const RectF & other ) const
{
	return left >= other.left && right <= other.right &&
		top >= other.top && bottom <= other.bottom;
}

bool RectF::Contains(const Vector& point) const
{
	return point.x >= left && point.x < right&& point.y >= top && point.y < bottom;
}

RectF RectF::FromCenter( const Vector & center,double halfWidth,double halfHeight )
{
	const Vector half( halfWidth,halfHeight );
	return RectF( center - half,center + half );
}

RectF RectF::GetExpanded( double offset ) const
{
	return RectF( left - offset,right + offset,top - offset,bottom + offset );
}

Vector RectF::GetCenter() const
{
	return Vector( (left + right) / 2.0f,(top + bottom) / 2.0f );
}
