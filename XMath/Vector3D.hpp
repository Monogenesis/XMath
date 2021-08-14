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


};

std::ostream& operator<<(std::ostream& stream, const Vector3D& vector);

inline bool operator == (const Vector3D& lhs, const Vector3D& rhs);



inline Vector3D operator + (const Vector3D& lhs, const Vector3D& rhs);

inline Vector3D operator * (const Vector3D& vector, float scalar);

inline Vector3D operator * (float scalar, const Vector3D& vector);

//inline Vector3D operator / (const Vector3D& vector, float scalar);
inline Vector3D operator / (const Vector3D& vector, float scalar) {
	scalar = 1.0f / scalar;
	return (Vector3D{ vector.x * scalar, vector.y * scalar, vector.z * scalar });
}


//inline Vector3D operator - (const Vector3D& vector);

inline Vector3D operator - (const Vector3D& vector) {
	return (Vector3D(-vector.x, -vector.y, -vector.z));
}


// inline Vector3D operator - (const Vector3D& lhs, const Vector3D& rhs);
inline Vector3D operator - (const Vector3D& lhs, const Vector3D& rhs) {
	return Vector3D{ lhs } -= rhs;
}

inline float Magnitude(const Vector3D& vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
}


inline Vector3D Normalize(const Vector3D& vector) {
	return (vector / Magnitude(vector));
}

inline float Dot(const Vector3D& lhs, const Vector3D& rhs) {
	return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
}

inline Vector3D Cross(const Vector3D& lhs, const Vector3D& rhs) {
	return Vector3D{ lhs.y * rhs.z - lhs.z * rhs.y,
					lhs.z * rhs.x - lhs.x * rhs.z,
					lhs.x * rhs.y - lhs.y * rhs.x
	};
}
//inline Vector3D Project(const Vector3D& lhs, const Vector3D& rhs);

//inline Vector3D Reject(const Vector3D& lhs, const Vector3D& rhs);
inline Vector3D operator * (const Vector3D& vector, float scalar) {
	return (Vector3D{ vector } *= scalar);
}

inline Vector3D operator * (float scalar, const Vector3D& vector) {
	return (vector * scalar);
}


inline Vector3D Project(const Vector3D& lhs, const Vector3D& rhs) {
	return (rhs * (Dot(lhs, rhs)) / Dot(rhs, rhs));
}

inline Vector3D Reject(const Vector3D& lhs, const Vector3D& rhs) {
	return (lhs - (rhs * Dot(lhs, rhs)) / Dot(rhs, rhs));
}
