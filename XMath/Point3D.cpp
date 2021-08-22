#include "Point3D.hpp"

Point3D::Point3D(float a, float b, float c) : Vector3D(a, b, c){};

Point3D operator+(const Point3D &a, const Vector3D &b)
{
	return Point3D{a.x + b.x, a.y + b.y, a.z + b.z};
}

Point3D operator+(const Vector3D &lhs, const Point3D &rhs)
{
	return Point3D{rhs} + lhs;
}

Vector3D operator-(const Point3D &a, const Point3D &b)
{
	return Vector3D{a.x - b.x, a.y - b.y, a.z - b.z};
}
