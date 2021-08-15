#include "Matrix3D.hpp"
#include "Vector3D.hpp";



	Matrix3D::Matrix3D(	float n00, float n01, float n02,
						float n10, float n11, float n12,
						float n20, float n21, float n22
						) 
	{
		n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
		n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
		n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
	}

	Matrix3D::Matrix3D(const Matrix3D& matrix)
	{
		n[0][0] = matrix(0, 0); n[0][1] = matrix(1, 0); n[0][2] = matrix(2, 0);
		n[1][0] = matrix(0, 1); n[1][1] = matrix(1, 1); n[1][2] = matrix(2, 1);
		n[2][0] = matrix(0, 2); n[2][1] = matrix(1, 2); n[2][2] = matrix(2, 2);
	}

	Matrix3D::Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)
	{
		n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
		n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
		n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
	}

	float& Matrix3D::operator () (int i, int j)
	{
		return n[j][i];
	}

	const float& Matrix3D::operator () (int i, int j) const
	{
		return n[j][i];
	}

	Vector3D& Matrix3D::operator [] (int j)
	{
		return (*reinterpret_cast<Vector3D*>(n[j]));
	}

	const Vector3D& Matrix3D::operator [] (int j) const
	{
		return (*reinterpret_cast<const Vector3D*>(n[j]));
	}

	Matrix3D& Matrix3D::operator *= (const Matrix3D& other)
	{
		float n00 = (*this)(0, 0) * other(0, 0) + (*this)(0, 1) * other(1, 0) + (*this)(0, 2) * other(2, 0);
		float n01 = (*this)(0, 0) * other(0, 1) + (*this)(0, 1) * other(1, 1) + (*this)(0, 2) * other(2, 1);
		float n02 = (*this)(0, 0) * other(0, 2) + (*this)(0, 1) * other(1, 2) + (*this)(0, 2) * other(2, 2);
		float n10 = (*this)(1, 0) * other(0, 0) + (*this)(1, 1) * other(1, 0) + (*this)(1, 2) * other(2, 0);
		float n11 = (*this)(1, 0) * other(0, 1) + (*this)(1, 1) * other(1, 1) + (*this)(1, 2) * other(2, 1);
		float n12 = (*this)(1, 0) * other(0, 2) + (*this)(1, 1) * other(1, 2) + (*this)(1, 2) * other(2, 2);
		float n20 = (*this)(2, 0) * other(0, 0) + (*this)(2, 1) * other(1, 0) + (*this)(2, 2) * other(2, 0);
		float n21 = (*this)(2, 0) * other(0, 1) + (*this)(2, 1) * other(1, 1) + (*this)(2, 2) * other(2, 1);
		float n22 = (*this)(2, 0) * other(0, 2) + (*this)(2, 1) * other(1, 2) + (*this)(2, 2) * other(2, 2);
		
		this->n[0][0] = n00;
		this->n[0][1] = n01;
		this->n[0][2] = n02;	
		this->n[1][0] = n10;
		this->n[1][1] = n11;
		this->n[1][2] = n12;
		this->n[2][0] = n20;
		this->n[2][1] = n21;
		this->n[2][2] = n22;

		return *this;
	}

	Matrix3D& Matrix3D::operator *= (float scalar)
	{
		this->n[0][0] *= scalar;
		this->n[0][1] *= scalar;
		this->n[0][2] *= scalar;
		this->n[1][0] *= scalar;
		this->n[1][1] *= scalar;
		this->n[1][2] *= scalar;
		this->n[2][0] *= scalar;
		this->n[2][1] *= scalar;
		this->n[2][2] *= scalar;
		return *this;
	}

	Matrix3D& Matrix3D::operator += (const Matrix3D& other)
	{
		this->n[0][0] += other(0, 0);
		this->n[0][1] += other(1, 0);
		this->n[0][2] += other(2, 0);
		this->n[1][0] += other(0, 1);
		this->n[1][1] += other(1, 1);
		this->n[1][2] += other(2, 1);
		this->n[2][0] += other(0, 2);
		this->n[2][1] += other(1, 2);
		this->n[2][2] += other(2, 2);
		return *this;
	}

	Matrix3D& Matrix3D::operator-=(const Matrix3D& other)
	{
		this->n[0][0] -= other(0, 0);
		this->n[0][1] -= other(1, 0);
		this->n[0][2] -= other(2, 0);
		this->n[1][0] -= other(0, 1);
		this->n[1][1] -= other(1, 1);
		this->n[1][2] -= other(2, 1);
		this->n[2][0] -= other(0, 2);
		this->n[2][1] -= other(1, 2);
		this->n[2][2] -= other(2, 2);
		return *this;
	}

	Vector3D Matrix3D::operator * (const Vector3D& v)
	{
		return Vector3D( 
			(0, 0) * v.x + (0, 1) * v.y + (0, 2) * v.z,
			(1, 0) * v.x + (1, 1) * v.y + (1, 2) * v.z, 
			(2, 0) * v.x + (2, 1) * v.y + (2, 2) * v.z
		);
	}

	bool Matrix3D::operator!=(const Matrix3D& other)
	{
		return !(*this == other);
	}


	bool Matrix3D::operator == (const Matrix3D& other)
	{	
		bool result = (
			((*this)(0, 0) == other(0, 0)) && ((*this)(1, 0) == other(1, 0)) && ((*this)(2, 0) == other(2, 0)) &&
			((*this)(0, 1) == other(0, 1)) && ((*this)(1, 1) == other(1, 1)) && ((*this)(2, 1) == other(2, 1)) &&
			((*this)(0, 2) == other(0, 2)) && ((*this)(1, 2) == other(1, 2)) && ((*this)(2, 2) == other(2, 2))
			);
	return result;

	}


	Matrix3D operator + (const Matrix3D& lhs, const Matrix3D& rhs)
	{
		return Matrix3D{lhs} += rhs;
	}

	Matrix3D operator-(const Matrix3D& lhs, const Matrix3D& rhs)
	{
		return Matrix3D{ lhs } -= rhs;
	}

	Matrix3D operator * (const Matrix3D& lhs, const Matrix3D& rhs) 
	{
		return Matrix3D{ lhs } *= rhs;
	}

	Matrix3D operator * (const Matrix3D& lhs, float scalar)
	{
		return Matrix3D{lhs} *= scalar;
	}

	Matrix3D operator * (float scalar, Matrix3D& rhs)
	{
		return Matrix3D{ rhs } *= scalar;
	}

	 Matrix3D Transpose(const Matrix3D& matrix)
	{
		Matrix3D result{ matrix(0, 0), matrix(1, 0), matrix(2,0),
						matrix(0, 1), matrix(1, 1), matrix(2, 1),
						matrix(0, 2), matrix(1, 2), matrix(2, 2),
		};

		return result;
	}

	 float Determinant(const Matrix3D& matrix) {
		 return (	matrix(0, 0) * (matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1))
				+	matrix(0, 1) * (matrix(1, 2) * matrix(2, 0) - matrix(1, 0) * matrix(2, 2))
				+	matrix(0, 2) * (matrix(1, 0) * matrix(2, 1) - matrix(1, 1) * matrix(2, 0)));
	 }

	 Matrix3D Inverse(const Matrix3D& matrix) {
		 const Vector3D& a = matrix[0];
		 const Vector3D& b = matrix[1];
		 const Vector3D& c = matrix[2];

		 Vector3D r0 = Cross(b, c);
		 Vector3D r1 = Cross(c, a);
		 Vector3D r2 = Cross(a, b);

		 float invDet = 1.0f / Dot(r2, c);

		 return (Matrix3D(	r0.x * invDet, r0.y * invDet, r0.z * invDet,
							r1.x * invDet, r1.y * invDet, r1.z * invDet,
							r2.x * invDet, r2.y * invDet, r2.z * invDet
						));
	 }

	 Matrix3D MakeRoationX(float t) {

		 float c = cos(t);
		 float s = sin(t);

		 return Matrix3D{ 1.0f, 0.0f, 0.0f,
							0.0f, c, -s,
							0.0f, s, c
				};
	 }

	 Matrix3D MakeRoationY(float t) {

		 float c = cos(t);
		 float s = sin(t);

		 return Matrix3D{	c, 0.0f, s,
							0.0f, 1.0f, 0.0f,
							-s, 0.0f, c
				};
	 }

	 Matrix3D MakeRoationZ(float t) {

		 float c = cos(t);
		 float s = sin(t);

		 return Matrix3D{	c, -s, 0.0f,
							s, c, 0.0f,
							0.0f, 0.0f, 1.0f
				};
	 }

	 Matrix3D MakeRoation(float t, const Vector3D& vec) {

		 float c = cos(t);
		 float s = sin(t);
		 float d = 1.0f - c;

		 float x = vec.x * d;
		 float y = vec.y * d;
		 float z = vec.z * d;

		 float vecXvecY = x * vec.y;
		 float vecXvecZ = x * vec.z;
		 float vecYvecZ = y * vec.z;

		 return Matrix3D{ c + x * vec.x, vecXvecY - s * vec.z, vecXvecZ + s * vec.y,
							vecXvecY + s * vec.z, c + y * vec.y, vecYvecZ - s * vec.x,
							vecXvecZ - s * vec.y, vecYvecZ + s * vec.x, c + z * vec.z
				};

	 }

	std::ostream& operator<<(std::ostream& stream, const Matrix3D& matrix)
	{
		stream	<< matrix(0, 0) << " " << matrix(0, 1) << " " << matrix(0, 2) << " \n"
				<< matrix(1, 0) << " " << matrix(1, 1) << " " << matrix(1, 2) << " \n"
				<< matrix(2, 0) << " " << matrix(2, 1) << " " << matrix(2, 2);
		return stream;
	}
