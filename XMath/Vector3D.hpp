#pragma once
#include <iostream>


struct Vector3D
{
	float x, y, z;

	Vector3D();

	Vector3D(float x, float y, float z);

	Vector3D(const Vector3D& vector);

	float& operator[](int index);

	const float& operator[](int index) const;

	Vector3D& operator *= (const float scalar);

	Vector3D& operator /= (float scalar);

	Vector3D& operator += (const Vector3D& vector);

	Vector3D& operator -= (const Vector3D& vector);

	Vector3D& operator = (const Vector3D& vector);

	bool operator == (const Vector3D& vector);

	friend bool operator == (const Vector3D& lhs, const Vector3D& rhs);

	friend Vector3D operator + (const Vector3D& lhs, const Vector3D& rhs);

	friend Vector3D operator * (const Vector3D& vector, float scalar);

	friend Vector3D operator * (float scalar, const Vector3D& vector);

	friend Vector3D operator / (const Vector3D& vector, float scalar);

	friend Vector3D operator - (const Vector3D& vector);

	friend Vector3D operator - (const Vector3D& lhs, const Vector3D& rhs);

	friend float Magnitude(const Vector3D& vector);

	friend Vector3D Normalize(const Vector3D& vector);

	friend float Dot(const Vector3D& lhs, const Vector3D& rhs);

	friend Vector3D Cross(const Vector3D& lhs, const Vector3D& rhs);

	friend Vector3D Project(const Vector3D& lhs, const Vector3D& rhs);

	friend Vector3D Reject(const Vector3D& lhs, const Vector3D& rhs);

	friend std::ostream& operator<<(std::ostream& stream, const Vector3D& vector);
};











