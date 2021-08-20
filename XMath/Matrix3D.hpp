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

	//friend bool operator == (const Matrix3D& lhs, const Matrix3D& rhs);

	bool operator != (const Matrix3D& other);

	friend Matrix3D operator + (const Matrix3D& lhs, const Matrix3D& rhs);

	friend Matrix3D operator - (const Matrix3D& lhs, const Matrix3D& rhs);

	friend Matrix3D operator * (const Matrix3D& lhs, const Matrix3D& rhs);

	friend Matrix3D operator * (const Matrix3D& lhs, float scalar);

	friend Matrix3D operator * (float scalar, Matrix3D& rhs);

	friend Matrix3D Transpose(const Matrix3D& matrix);

	friend float Determinant(const Matrix3D& matrix);

	friend Matrix3D Inverse(const Matrix3D& matrix);

	friend Matrix3D MakeRoationX(float t);

	friend Matrix3D MakeRoationY(float t);

	friend Matrix3D MakeRoationZ(float t);

	friend Matrix3D MakeRoation(float t, const Vector3D& vec);

	friend Matrix3D MakeReflection(const Vector3D& vec);

	friend Matrix3D MakeInvolution(const Vector3D& vec);

	friend Matrix3D MakeScale(float sx, float sy, float sz);

	friend Matrix3D MakeScale(float s, const Vector3D& vec);

	friend Matrix3D MakeSkew(float t, const Vector3D& dir, const Vector3D& projectedDir);


	friend std::ostream& operator<<(std::ostream& stream, const Matrix3D& vector);

	
};

