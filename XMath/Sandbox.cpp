
#include <vector>
#include "Sandbox.hpp"
#include "Vector3D.hpp"
#include "Matrix3D.hpp"
#include "Quaternion.hpp"

int main()
{

	Matrix3D m1{1, 2, 3, 4, 5, 6, 7, 8, 9};
	Vector3D i{1, 0, 0};
	Quaternion q1{0.2f, 0.1f, 0.5f, 0.0f};
	Quaternion q2{0.2f, 0.1f, 0.1f, 0.0f};
	std::cout << q1 * q2 << std::endl;
}