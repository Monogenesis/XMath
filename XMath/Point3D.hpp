#pragma once

#include "Vector3D.hpp"

struct Point3D : Vector3D
{
	Point3D() = default;

	Point3D(float a, float b, float c);

	friend Point3D operator+(const Point3D &lhs, const Vector3D &rhs);

	friend Point3D operator+(const Vector3D &lhs, const Point3D &rhs);

	friend Vector3D operator-(const Point3D &lhs, const Point3D &rhs);
};
