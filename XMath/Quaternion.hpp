#pragma once

#include "Vector3D.hpp"
#include "Matrix3D.hpp"

struct Quaternion
{
	float x, y, z, w;

	Quaternion() = default;

	Quaternion(float a, float b, float c, float s);

	Quaternion(const Vector3D &v, float s);

	const Vector3D &GetVectorPart(void) const;

	Vector3D Transform(const Vector3D &v, const Quaternion &q);

	Matrix3D GetRotationMatrix(void);

	void SetRotationMatrix(const Matrix3D &m);

	friend Quaternion operator*(const Quaternion &lhs, const Quaternion &rhs);

	friend std::ostream &operator<<(std::ostream &stream, const Quaternion &vector);
};
