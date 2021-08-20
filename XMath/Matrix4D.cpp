#include "Matrix4D.hpp"
#include "Matrix3D.hpp"


Matrix4D::Matrix4D(	float n00, float n01, float n02, float n03, 
					float n10, float n11, float n12, float n13, 
					float n20, float n21, float n22, float n23, 
					float n30, float n31, float n32, float n33)
{
	n[0][0] = n00; n[0][1] = n10; n[0][2] = n20; n[0][3] = n30;
	n[1][0] = n01; n[1][1] = n11; n[1][2] = n21; n[0][3] = n31;
	n[2][0] = n02; n[2][1] = n12; n[2][2] = n22; n[0][3] = n32;
	n[3][0] = n03; n[3][1] = n13; n[3][2] = n23; n[3][3] = n33;
}

Matrix4D::Matrix4D(const Matrix4D& matrix)
{	n[0][0] = matrix(0, 0); n[0][1] = matrix(1, 0); n[0][2] = matrix(2, 0); n[0][3] = matrix(3, 0);
	n[1][0] = matrix(0, 1); n[1][1] = matrix(1, 1); n[1][2] = matrix(2, 1); n[0][3] = matrix(3, 1);
	n[2][0] = matrix(0, 2); n[2][1] = matrix(1, 2); n[2][2] = matrix(2, 2); n[0][3] = matrix(3, 2);
	n[3][0] = matrix(0, 3); n[3][1] = matrix(1, 3); n[3][2] = matrix(2, 3); n[3][3] = matrix(3, 3);
}

float& Matrix4D::operator () (int i, int j)
{
	return n[j][i];
}

const float& Matrix4D::operator () (int i, int j) const
{
	return n[j][i];
}

Vector3D& Matrix4D::operator [] (int j)
{
	return (*reinterpret_cast<Vector3D*>(n[j]));
}

const Vector3D& Matrix4D::operator [] (int j) const
{
	return (*reinterpret_cast<const Vector3D*>(n[j]));
}

Matrix4D Inverse(const Matrix4D& matrix)
{
	const Vector3D& a = reinterpret_cast<const Vector3D&>(matrix[0]);
	const Vector3D& b = reinterpret_cast<const Vector3D&>(matrix[1]);
	const Vector3D& c = reinterpret_cast<const Vector3D&>(matrix[2]);
	const Vector3D& d = reinterpret_cast<const Vector3D&>(matrix[3]);

	const float& x = matrix(3, 0);
	const float& y = matrix(3, 1);
	const float& z = matrix(3, 2);
	const float& w = matrix(3, 3);

	Vector3D s = Cross(a, b);
	Vector3D t = Cross(c, d);
	Vector3D u = a * y - b * x;
	Vector3D v = c * w - d * z;

	float invDet = 1.0f / (Dot(s, v) + Dot(t, u));
	s *= invDet;
	t *= invDet;
	u *= invDet;
	v *= invDet;

	Vector3D r0 = Cross(b, v) + t * y;
	Vector3D r1 = Cross(v, a) - t * x;
	Vector3D r2 = Cross(d, u) + s * w;
	Vector3D r3 = Cross(u, c) - s * z;

	return Matrix4D{	r0.x, r0.y, r0.z, -Dot(b, t),
						r1.x, r1.y, r1.z, Dot(a, t),
						r2.x, r2.y, r2.z, -Dot(d, s),
						r3.x, r3.y, r3.z, Dot(c, s)
					};
}


std::ostream& operator<<(std::ostream& stream, const Matrix4D& matrix)
{
	stream << matrix(0, 0) << " " << matrix(0, 1) << " " << matrix(0, 2) << matrix(0, 3) << " \n"
		<< matrix(1, 0) << " " << matrix(1, 1) << " " << matrix(1, 2) << matrix(1, 3) << " \n"
		<< matrix(2, 0) << " " << matrix(2, 1) << " " << matrix(2, 2) << matrix(2, 3) << " \n"
		<< matrix(3, 0) << " " << matrix(3, 1) << " " << matrix(3, 2) << matrix(3, 3);
	return stream;
}