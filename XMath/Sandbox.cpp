
#include <vector>
#include "Sandbox.hpp"
#include "Vector3D.hpp"
#include "Matrix3D.hpp"


int main() {

	Matrix3D m1{1,2,3,4,5,6,7,8,9};
	Vector3D v1{1,2,3};
	Vector3D v2{3,3,3};
	Vector3D v3{7,8,9};
	Matrix3D m2{v1,v2,v3 };
	std::cout << Dot(v2,v2) << std::endl;
	std::cout << Dot(v1,v2) << std::endl;
	std::cout << v2 * Dot(v1,v2) << std::endl;
	std::cout << Project(v1,v2) << std::endl;
	std::cout << Reject(v1,v2) << std::endl;

}