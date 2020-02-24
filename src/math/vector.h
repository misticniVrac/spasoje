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
	Vector2(const float val);

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



struct Vector3
{
	float x;
	float y;
	float z;

	Vector3();
	Vector3(const float x,const float y,const float z);
	Vector3(const float val);

	Vector3 &add(Vector3 val);
	Vector3 &subtract(const Vector3 &val);
	Vector3 &multiply(Vector3 val);
	Vector3 &divide(Vector3 val);

	bool compare(const Vector3 &val);

	Vector3& operator+=(const Vector3& val);
	Vector3& operator-=(const Vector3& val);
	Vector3& operator*=(const Vector3& val);
	Vector3& operator/=(const Vector3& val);

};	


	Vector3 operator+(const Vector3& left,const Vector3& right);
	Vector3 operator-(const Vector3& left,const Vector3& right);
	Vector3 operator*(const Vector3& left,const Vector3& right);
	Vector3 operator/(const Vector3& left,const Vector3& right); 
	
	bool operator==(const Vector3& left,const Vector3& right);
	bool operator!=(const Vector3& left,const Vector3& right);
	
	std::ostream& operator<<(std::ostream& stream,const Vector3& val);




}
