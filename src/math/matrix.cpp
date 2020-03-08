#include "matrix.h"
#include "vector.h"
#include "math.h"

#include <iostream>
#include <math.h>

namespace spasoje{

Matrix4
Matrix4::diagonally(float val)
{
	Matrix4 res;
	for(int x=0;x<4;x++)
		for(int y=0;y<4;y++)
			res.elements[x][y] = x==y?val:0.0;
	return res;
}

Matrix4
Matrix4::identity()
{
	return diagonally(1.0);
}

void
Matrix4::multiply(const Matrix4& val)
{
	float res[4][4]{0};
	for(int r=0;r<4;r++)
	{
		for(int c=0;c<4;c++)
		{
			for(int x=0;x<4;x++)
				res[r][c] += this->elements[r][x]  * val.elements[x][c];
		}
	}

	for(int x=0;x<4;x++)
		for(int y=0;y<4;y++)
			this->elements[x][y] = res[x][y];
}

Matrix4
Matrix4::translate(const Matrix4& matrix,const Vector3& val)
{
	Matrix4 res = Matrix4::diagonally(1.0);

	res.elements[0][3] = matrix.elements[0][3] + val.x;
	res.elements[1][3] = matrix.elements[1][3] + val.y;
	res.elements[2][3] = matrix.elements[2][3] + val.z;

	return res;
}

Matrix4
Matrix4::scale(const Matrix4& matrix,const Vector3& val)
{
	
	Matrix4 res;

	res.elements[0][0] = matrix.elements[0][0] * val.x;
	res.elements[1][1] = matrix.elements[1][1] * val.y;
	res.elements[2][2] = matrix.elements[3][3] * val.z;
	
	res.elements[3][3] = 1.0;

	return res;
}


Matrix4 
Matrix4::rotate(const Matrix4& matrix, float angle, const Vector3& val)
{
	Matrix4 res = Matrix4::diagonally(1.0);
	
	float rad = toRadians(angle);
	

	float s = sin(rad);
	float c = cos(rad);
	float omc = 1.0f - c;

	Vector3 axis = Vector3::normalize(val);
	
	
	res.elements[0][0] = c + omc * axis.x * axis.x;
	res.elements[0][1] = omc * axis.x * axis.y + s * axis.z;
	res.elements[0][2] = omc * axis.x * axis.z - s * axis.y;

	res.elements[1][0] = omc * axis.y *  axis.x - s * axis.z;
	res.elements[1][1] = c + omc * axis.y * axis.y;
	res.elements[1][2] = omc * axis.y * axis.z + s * axis.x;  

	res.elements[2][0] = omc * axis.z * axis.x + s * axis.y;
	res.elements[2][1] = omc * axis.z * axis.y - s * axis.x;
	res.elements[2][2] = c + omc * axis.z * axis.z;

	res.multiply(matrix);
	return res;

}

std::ostream& operator <<(std::ostream& stream,const Matrix4& val)
{
	stream << "Matrix4"<<"\n[ ";
	for(int x=0;x<4;x++)
	{
		for(int y=0;y<4;y++)
			stream << val.elements[x][y] << (y==3?" ]\n":", ");
		
		if(x!=3)stream << "[ ";
	}

	return stream;

}


}
