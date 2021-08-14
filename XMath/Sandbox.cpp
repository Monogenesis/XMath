
#include <vector>
#include "Sandbox.hpp"
#include "Vector3D.hpp"
#include "Matrix3D.hpp"


int main() {

	Matrix3D m1{1,2,3,4,5,6,7,8,9};
	Vector3D i{1, 0, 0};
	Vector3D j{0, 1, 0};
	Vector3D k{0, 0, 1};

	Matrix3D A = { 1,1,1,
		1,2,1,
		0,2,1 };
	Matrix3D I = { 1,0,0,
				0,1,0,
				0,0,1
	};
	std::cout << (i != j) << std::endl;
	std::cout << !(i == j) << std::endl;
	std::cout << !(A == I) << std::endl;
	std::cout << (A != I) << std::endl;


}