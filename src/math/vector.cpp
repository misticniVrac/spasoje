#include "vector.h"

#include <iostream>
#include <math.h>
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
Vector2::Vector2(const float val)
{
	this->x = val;
	this->y = val;
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

Vector2
Vector2::normalize(const Vector2 &val)
{
	float length_of_v = sqrt((val.x * val.x) + (val.y * val.y));
	      return Vector2(val.x / length_of_v, val.y / length_of_v);
}

Vector2 operator+(const Vector2& left,const Vector2& right) 
{
	return Vector2(left.x+right.x,left.y+right.y);
}

Vector2 operator-(const Vector2& left,const Vector2& right) 
{
	return Vector2(left.x-right.x,left.y-right.y);
}


Vector2 operator*(const Vector2& left,const Vector2& right) 
{
	return Vector2(left.x*right.x,left.y*right.y);
}


Vector2 operator/(const Vector2& left,const Vector2& right) 
{
	return Vector2(left.x/right.x,left.y/right.y);
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

//Vector 3


Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}


Vector3::Vector3(const float x,const float y,const float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

}
Vector3::Vector3(const float val)
{
	this->x = val;
	this->y = val;
	this->z = val;
}
Vector3::Vector3(const Vector2 val,float z)
{
	this->x = val.x;
	this->y = val.y;
	this->z = z;
}
Vector3&
Vector3::add(Vector3 val)
{
	this->x += val.x;
	this->y += val.y;
	this->z += val.z;

	return *this;
}

Vector3&
Vector3::subtract(const Vector3 &val)
{
	this->x -= val.x;
	this->y -= val.y;
	this->z -= val.z;

	return *this;
}

Vector3&
Vector3::multiply(Vector3 val)
{
	this->x *= val.x;
	this->y *= val.y;
	this->z *= val.z;

	return *this;
}

Vector3&
Vector3::divide(Vector3 val)
{
	this->x /= val.x;
	this->y /= val.y;
	this->z /= val.z;

	return *this;
}

bool 
Vector3::compare(const Vector3& val)
{
	return this->x==val.x && this->y == val.y && this->z == val.z;
}

Vector3
Vector3::normalize(const Vector3 &val)
{
	float length_of_v = sqrt((val.x * val.x) + (val.y * val.y) + (val.z * val.z));
	      return Vector3(val.x / length_of_v, val.y / length_of_v,val.z / length_of_v);
}



Vector3 operator+(const Vector3& left,const Vector3& right) 
{
	return Vector3(left.x+right.x,left.y+right.y,left.z+right.z);
}

Vector3 operator-(const Vector3& left,const Vector3& right) 
{
	return Vector3(left.x-right.x,left.y-right.y,left.z-right.z);
}


Vector3 operator*(const Vector3& left,const Vector3& right) 
{
	return Vector3(left.x*right.x,left.y*right.y,left.z*right.z);
}


Vector3 operator/(const Vector3& left,const Vector3& right) 
{
	return Vector3(left.x/right.x,left.y/right.y,left.z/right.z);
}

Vector3& Vector3::operator+=(const Vector3& val)
{
	return this->add(val);
}

Vector3& Vector3::operator-=(const Vector3& val)
{
	return this->subtract(val);
}
Vector3& Vector3::operator*=(const Vector3& val)
{
	return this->multiply(val);
}
Vector3& Vector3::operator/=(const Vector3& val)
{
	return this->divide(val);
}

bool operator==(const Vector3& left,const Vector3& right)
{
	return left.x==right.x && left.y==right.y && left.z == right.z;
}

bool operator!=(const Vector3& left,const Vector3& right)
{
	return !(left.x==right.x && left.y==right.y && left.z==right.z);
}

std::ostream& operator <<(std::ostream& stream,const Vector3& val)
{
	stream << "Vector3("<<val.x<<", "<<val.y << ", "<< val.z <<")";
	return stream;
}



}

