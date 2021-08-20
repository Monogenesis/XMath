#pragma once
#include "Matrix4D.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

struct Transform4D : Matrix4D
{
	private:

		float n[4][4]; // Column major order

	public:

		Transform4D() = default;

		Transform4D(float n00, float n01, float n02, float n03,
					float n10, float n11, float n12, float n13,
					float n20, float n21, float n22, float n23);

		Transform4D(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& p);

		Vector3D& operator [] (int j);

		const Vector3D& operator [] (int j) const;

		const Point3D& GetTranslation(void) const;

		void SetTranslation(const Point3D& p);

		Transform4D Inverse(const Transform4D& H);

		friend Transform4D operator * (const Transform4D& lhs, const Transform4D& rhs);

		friend Vector3D operator * (const Transform4D& H, const Vector3D& v);

		friend Point3D operator * (const Transform4D& H, const Point3D& p);

};