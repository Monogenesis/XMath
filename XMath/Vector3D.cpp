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

	Vector3D& Vector3D::operator *=(const float scalar) {
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



std::ostream& operator<<(std::ostream& stream, const Vector3D& vector) {
	stream << "x: " << vector.x << " y: " << vector.y << " z: " << vector.z;
	return stream;
}

inline bool operator == (const Vector3D& lhs, const Vector3D& rhs) {
	return Vector3D{ lhs } == rhs;
}



inline Vector3D operator + (const Vector3D& lhs, const Vector3D& rhs) {
	return Vector3D{ lhs } += rhs;
}




