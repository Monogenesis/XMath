#pragma once
#include "Vector3D.hpp"

struct Matrix4D
{
	private:

		float n[4][4]; // Column major order

	public:

		Matrix4D() = default;

		Matrix4D(
			float n00, float n01, float n02, float n03,
			float n10, float n11, float n12, float n13,
			float n20, float n21, float n22, float n23,
			float n30, float n31, float n32, float n33);

		Matrix4D(const Matrix4D& matrix);

		float& operator () (int i, int j);

		const float& operator () (int i, int j) const;

		Vector3D& operator [] (int j);

		const Vector3D& operator [] (int j) const;

		friend Matrix4D Inverse(const Matrix4D& matrix);

		friend std::ostream& operator<<(std::ostream& stream, const Matrix4D& vector);


};

