#include <limits.h>
#include "gtest/gtest.h"
#include "../triangle.h"

TEST(TriangleType, Equivalence_Class_Test_Case){
	EXPECT_EQ("Not a Triangle", TriangleType(0, 0, 0));
	EXPECT_EQ("Equilateral", TriangleType(3, 3, 3 ));
	EXPECT_EQ("Scalene", TriangleType(3, 4, 5));
	EXPECT_EQ("out of permitted range", TriangleType(201, 200, 200));
	EXPECT_EQ("Isosceles", TriangleType(3, 5, 5));
}