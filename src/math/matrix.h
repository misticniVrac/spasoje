#pragma once

#include <iostream>

#include "vector.h"

namespace spasoje{

struct Matrix4
{

		float elements[4][4]={0};	

	
		void multiply(const Matrix4& val);

	
		static Matrix4 translate(const Matrix4& matrix, const Vector3& val);
		static Matrix4 scale(const Matrix4& matrix, const Vector3& val);
		static Matrix4 rotate(const Matrix4& matrix, float angle, const Vector3& val);

		static Matrix4 identity();
		static Matrix4 diagonally(float val);	

		

};

std::ostream& operator<<(std::ostream& stream,const Matrix4& val);



;}
