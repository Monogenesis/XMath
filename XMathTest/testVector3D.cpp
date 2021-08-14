#include "pch.h"
#include "Vector3D.cpp"

	

	TEST(TestVectorF, addition) {
		Vector3D a = { 1,2,3 };
		Vector3D b = { -1,-1,-1 };
		Vector3D c = { 0, 1, 2 };

		ASSERT_EQ( c, a + b);
	}

	TEST(TestVectorF, subtraction) {
		Vector3D a = { 1,2,3 };
		Vector3D b = { -1,-1,-1 };
		Vector3D c = { 2, 3, 4 };

		ASSERT_EQ(c, a - b);
	}

	TEST(TestVectorF, proptertiesAddition) {
		Vector3D a = { 1,2,3 };
		Vector3D b = { -1,0,100 };
		Vector3D c = { 0, 0, 0 };

		// Associative
		ASSERT_EQ((a + b) + c, a + (b + c));

		// Commutative
		ASSERT_EQ(a + b, b + a);
	}

	TEST(TestVectorF, proptertiesSubtraction) {
		Vector3D a = { 1,2,3 };
		Vector3D b = { -1,0,100 };
		Vector3D c = { 0, 0, 0 };

		// Associative
		ASSERT_EQ((a - b) - c, a - (b - c));
	}

	TEST(TestVectorF, proptertiesMultiplication) {
		Vector3D a = { 1,2,3 };
		Vector3D b = { -1,0,1 };
		int scalarT = -2;
		int scalarS = 5;

		// Associative
		ASSERT_EQ((scalarT * scalarS) * a, scalarS * (scalarT * a));

		// Commutative
		ASSERT_EQ(scalarT * (a + b), scalarT * a + scalarT * b);

		// Distributive
		ASSERT_EQ((scalarT + scalarS) * a, scalarS * a + scalarT * a);
		ASSERT_EQ(a * (scalarT + scalarS), a  * scalarS + a * scalarT);
	}
	
	TEST(TestVectorF, dotproductProperties) {
		Vector3D a = { 1,2,3 };
		Vector3D b = { -1,0,1 };
		Vector3D c = { 7,-1,0 };
		int scalarT = -2;

		// Commutative
		ASSERT_EQ(Dot(a, b), Dot(b, a));

		// Distributive
		ASSERT_EQ(Dot(a, (b + c)), Dot(a, b) + Dot(a , c));

		// Scalar factorization
		ASSERT_EQ(Dot(scalarT * a, b), Dot(a, scalarT * b));
		ASSERT_EQ(Dot(scalarT * a, b), scalarT * Dot(a,b));
		ASSERT_EQ(Dot(a, scalarT * b), scalarT * Dot(a, b));
	}

	TEST(TestVectorF, crossproductProperties) {
		Vector3D a = { 1,2,3 };
		Vector3D b = { -1,0,1 };
		Vector3D c = { 7,-1,0 };
		int scalarT = -2;

		// Anticommutativity
		ASSERT_EQ(Cross(a,b), Cross(-b, a));

		// Distributive
		ASSERT_EQ(Cross(a, b + c), Cross(a, b) + Cross(a, c));

		// Scalar factorization
		ASSERT_EQ(Cross(scalarT * a, b), Cross(a, scalarT * b));
		ASSERT_EQ(Cross(scalarT * a, b), scalarT * Cross(a,b));

		// Vector tripple product
		ASSERT_EQ(Cross(a, Cross(b, c)), b * Dot(a, c) - (c * Dot(a, b)));
		
		// Lagrange's identity
		ASSERT_EQ(Dot(Cross(a, b) , Cross(a, b)), Dot(a, a) * Dot(b, b) - Dot(a, b) * Dot(a, b));

	}
