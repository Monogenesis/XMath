#pragma once

#include "Vector3D.hpp";
#include <iostream>

struct Matrix3D
{
private:

	float n[3][3]; // Column major order

public:

	Matrix3D() = default;

	Matrix3D(float n00, float n01, float n02,
		float n10, float n11, float n12,
		float n20, float n21, float n22);

	Matrix3D(const Matrix3D& matrix);

	Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);

	float& operator () (int i, int j);

	const float& operator () (int i, int j) const;

	Vector3D& operator [] (int j);

	const Vector3D& operator [] (int j) const;

	bool operator == (const Matrix3D& other);
	
	Matrix3D& operator *= (const Matrix3D& other);

	Matrix3D& operator *= (float scalar);

	Matrix3D& operator += (const Matrix3D& other);

	Matrix3D& operator -= (const Matrix3D& other);

	Vector3D operator * (const Vector3D& v);



	
};

inline bool operator == (const Matrix3D& lhs, const Matrix3D& rhs);

inline Matrix3D operator + (const Matrix3D& lhs, const Matrix3D& rhs);

inline Matrix3D operator - (const Matrix3D& lhs, const Matrix3D& rhs);

inline Matrix3D operator * (const Matrix3D& lhs, const Matrix3D& rhs);

inline Matrix3D operator * (const Matrix3D& lhs, float scalar);

inline Matrix3D operator * (float scalar, Matrix3D& rhs);

//inline Matrix3D Transpose(const Matrix3D& matrix);
inline Matrix3D Transpose(const Matrix3D& matrix)
{
	Matrix3D result{ matrix(0, 0), matrix(1, 0), matrix(2,0),
					matrix(0, 1), matrix(1, 1), matrix(2, 1),
					matrix(0, 2), matrix(1, 2), matrix(2, 2),
	};

	return result;
}


std::ostream& operator<<(std::ostream& stream, const Matrix3D& vector);