#include "Vector3D.hpp"
#include <iostream>



	Vector3D::Vector3D() : x(0), y(0), z(0) 
	{}

	Vector3D::Vector3D(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

	Vector3D::Vector3D(const Vector3D& vector) : x(vector.x), y(vector.y), z(vector.z) 
	{}

	float& Vector3D::operator [] (int index) {
		return ((&x)[index]);
	}

	const float& Vector3D::operator [] (int index) const {
		return ((&x)[index]);
	}

	Vector3D& Vector3D::operator *= (const float scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return(*this);
	}

	Vector3D& Vector3D::operator /= (float scalar) {
		scalar = 1.0f / scalar;
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return(*this);
	}

	Vector3D& Vector3D::operator += (const Vector3D& vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return (*this);
	}

	Vector3D& Vector3D::operator -= (const Vector3D& vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return (*this);
	}


	Vector3D& Vector3D::operator = (const Vector3D& vector) {
		x = vector.x;
		y = vector.y;
		z = vector.z;
		return (*this);
	}

	bool Vector3D::operator == (const Vector3D& vector) {
		bool result = (x == vector.x && y == vector.y && z == vector.z);
		return result;
	}

	bool Vector3D::operator!=(const Vector3D& vector)
	{
		return !(*this == vector);
	}

	inline Vector3D operator + (const Vector3D& lhs, const Vector3D& rhs) {
		return Vector3D{ lhs } += rhs;
	}

	Vector3D operator * (const Vector3D& vector, float scalar) {
		return (Vector3D{ vector } *= scalar);
	}

	Vector3D operator * (float scalar, const Vector3D& vector) {
		return (vector * scalar);
	}

	Vector3D operator / (const Vector3D& vector, float scalar) {
		scalar = 1.0f / scalar;
		return (Vector3D{ vector.x * scalar, vector.y * scalar, vector.z * scalar });
	}

	Vector3D operator - (const Vector3D& lhs, const Vector3D& rhs) {
		return Vector3D{ lhs } -= rhs;
	}

	Vector3D operator - (const Vector3D& vector) {
		return (Vector3D(-vector.x, -vector.y, -vector.z));
	}

	std::ostream& operator<<(std::ostream& stream, const Vector3D& vector) {
		stream << "x: " << vector.x << " y: " << vector.y << " z: " << vector.z;
		return stream;
	}

	inline bool operator == (const Vector3D& lhs, const Vector3D& rhs) {
		return Vector3D{ lhs } == rhs;
	}

	float Magnitude(const Vector3D& vector)
	{
		return (sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
	}

	Vector3D Normalize(const Vector3D& vector) {
		return (vector / Magnitude(vector));
	}

	float Dot(const Vector3D& lhs, const Vector3D& rhs) {
		return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
	}

	Vector3D Cross(const Vector3D& lhs, const Vector3D& rhs) {
		return Vector3D{ lhs.y * rhs.z - lhs.z * rhs.y,
						lhs.z * rhs.x - lhs.x * rhs.z,
						lhs.x * rhs.y - lhs.y * rhs.x
		};
	}

	Vector3D Project(const Vector3D& lhs, const Vector3D& rhs) {
		return (rhs * (Dot(lhs, rhs)) / Dot(rhs, rhs));
	}

	Vector3D Reject(const Vector3D& lhs, const Vector3D& rhs) {
		return (lhs - (rhs * Dot(lhs, rhs)) / Dot(rhs, rhs));
	}

