#include <limits.h>
#include "gtest/gtest.h"
#include "../triangle.h"

TEST(TriangleType, Equivalence_Class_Test_Case){
	EXPECT_EQ("Not a Triangle", TriangleType(-1, 5, 5));
	EXPECT_EQ("Not a Triangle", TriangleType(5, -1, 5));
	EXPECT_EQ("Not a Triangle", TriangleType(5, 5, -1));
	EXPECT_EQ("Not a Triangle", TriangleType(-1, -1, 5));
	EXPECT_EQ("Not a Triangle", TriangleType(-1, 5, -1));
	EXPECT_EQ("Not a Triangle", TriangleType(-1, -1, 5));
	EXPECT_EQ("Not a Triangle", TriangleType(-1, -1, -1));
	EXPECT_EQ("out of permitted range", TriangleType(5, 5, 201));
	EXPECT_EQ("out of permitted range", TriangleType(5, 201, 5));
	EXPECT_EQ("out of permitted range", TriangleType(201, 5, 5));

}