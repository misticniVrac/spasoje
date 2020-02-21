#pragma once

#include <iostream>

namespace spasoje
{
	
struct Vector2
{
	float x;
	float y;

	Vector2();
	Vector2(const float x,const float y);

	Vector2 &add(Vector2 val);
	Vector2 &subtract(const Vector2 &val);
	Vector2 &multiply(Vector2 val);
	Vector2 &divide(Vector2 val);

	bool compare(const Vector2 &val);

	Vector2& operator+=(const Vector2& val);
	Vector2& operator-=(const Vector2& val);
	Vector2& operator*=(const Vector2& val);
	Vector2& operator/=(const Vector2& val);

};	


	Vector2 operator+(const Vector2& left,const Vector2& right);
	Vector2 operator-(const Vector2& left,const Vector2& right);
	Vector2 operator*(const Vector2& left,const Vector2& right);
	Vector2 operator/(const Vector2& left,const Vector2& right); 
	
	bool operator==(const Vector2& left,const Vector2& right);
	bool operator!=(const Vector2& left,const Vector2& right);
	
	std::ostream& operator<<(std::ostream& stream,const Vector2& val);


}
