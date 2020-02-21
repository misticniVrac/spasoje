#include "vector.h"

#include <iostream>

namespace spasoje{



Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(const float x,const float y)
{
	this->x = x;
	this->y = y;
}
Vector2&
Vector2::add(Vector2 val)
{
	this->x += val.x;
	this->y += val.y;

	return *this;
}

Vector2&
Vector2::subtract(const Vector2 &val)
{
	this->x -= val.x;
	this->y -= val.y;

	return *this;
}

Vector2&
Vector2::multiply(Vector2 val)
{
	this->x *= val.x;
	this->y *= val.y;

	return *this;
}

Vector2&
Vector2::divide(Vector2 val)
{
	this->x /= val.x;
	this->y /= val.y;

	return *this;
}

bool 
Vector2::compare(const Vector2& val)
{
	return this->x==val.x && this->y == val.y;
}


Vector2 operator+(const Vector2& left,const Vector2& right) 
{
	return Vector2(left.x+left.y,right.x+right.y);
}

Vector2 operator-(const Vector2& left,const Vector2& right) 
{
	return Vector2(left.x-left.y,right.x-right.y);
}


Vector2 operator*(const Vector2& left,const Vector2& right) 
{
	return Vector2(left.x*left.y,right.x*right.y);
}


Vector2 operator/(const Vector2& left,const Vector2& right) 
{
	return Vector2(left.x*left.y,right.x*right.y);
}

Vector2& Vector2::operator+=(const Vector2& val)
{
	return this->add(val);
}

Vector2& Vector2::operator-=(const Vector2& val)
{
	return this->subtract(val);
}
Vector2& Vector2::operator*=(const Vector2& val)
{
	return this->multiply(val);
}
Vector2& Vector2::operator/=(const Vector2& val)
{
	return this->divide(val);
}

bool operator==(const Vector2& left,const Vector2& right)
{
	return left.x==right.x && left.y==right.y;
}

bool operator!=(const Vector2& left,const Vector2& right)
{
	return !(left.x==right.x && left.y==right.y);
}

std::ostream& operator <<(std::ostream& stream,const Vector2& val)
{
	stream << "Vector2("<<val.x<<", "<<val.y << ")";
	return stream;
}


}

