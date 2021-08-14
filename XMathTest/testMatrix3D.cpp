#include "pch.h"
#include "Matrix3D.cpp"





TEST(TestMatrixF, additionProperties) {
	Matrix3D A = {1,1,1,
		1,1,1,
		1,1,1	};
	Matrix3D B = { 2,2,2,
		2,2,2,
		2,2,2
	};
	Matrix3D C = {	6,6,6,
					6,6,6,
					6,6,6
	};
	// Associative
	 ASSERT_EQ((A + B) + C, A + (B + C));

	 //Commutative
	 ASSERT_EQ(A + B, A + B);
}

TEST(TestMatrixF, transposePropterties) {
	Matrix3D A = {	1,2,3,
					4,5,6,
					7,8,9};	
	Matrix3D B = {	1,4,7,
					2,5,8,
					3,6,9};

	// Product rule
	ASSERT_EQ(Transpose(A * B), Transpose(B) * Transpose(A));

}

TEST(TestMatrixF, matrixMultiplicationProperties) {
	Matrix3D A = { 1,1,1,
		1,1,1,
		1,1,1 };
	Matrix3D B = { 2,2,2,
		2,2,2,
		2,2,2
	};
	Matrix3D C = { 6,6,6,
					6,6,6,
					6,6,6
	};
	// Associative
	ASSERT_EQ((A * B) *  C, A * (B * C));

	//Distributive
	ASSERT_EQ(A * (B + C), A * B + A * C);
	ASSERT_EQ((A + B) * C, A * C + B * C);
}

TEST(TestMatrixF, scalarMultiplicationPropterties) {
	Matrix3D A = { 1,1,1,
		1,1,1,
		1,1,1 };
	Matrix3D B = { 2,2,2,
		2,2,2,
		2,2,2
	};
	Matrix3D C = { 6,6,6,
					6,6,6,
					6,6,6
	};
	float scalarS = -5;
	float scalarT = 12;

	// Associative
	ASSERT_EQ((scalarS * scalarT) * A, scalarS * (scalarT * A));

	//Commutative
	ASSERT_EQ(scalarT * A, A * scalarT);

	// Distributive
	ASSERT_EQ(scalarT * (A + B), scalarT * A + scalarT * B);
	ASSERT_EQ((scalarS + scalarT) * A , scalarS * A + scalarT * A);
}

TEST(TestMatrixF, determinantPropterties) {
	Matrix3D A = { 1,1,1,
		1,2,1,
		0,2,1 };
	Matrix3D B = { 2,2,2,
		2,2,2,
		2,2,2
	};
	Matrix3D I = {	1,0,0,
					0,1,0,
					0,0,1
	};

	float scalarT = 12;

	// Identity
	ASSERT_EQ(Determinant(I), 1);

	// Transposed matrix
	ASSERT_EQ(Determinant(Transpose(A)), Determinant(A));

	// Inverse matrix
	ASSERT_EQ(Determinant(Inverse(A)), 1 / Determinant(A));

	// Product rule
	ASSERT_EQ(Determinant(A * B), Determinant(A) * Determinant(B));

	// Scalar factorization
	ASSERT_EQ(Determinant(scalarT * A), (scalarT * scalarT * scalarT) * Determinant(A));
}