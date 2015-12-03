
#include "../triangle.h"

TEST(isTriangleTest,  Positive){
	EXPECT_TRUE(isATriangle(1, 2, 2));
	EXPECT_FALSE(isATriangle(3, 5, 9));
}

TEST(isTriangleTest,  Trivial){
	EXPECT_TRUE(isATriangle(1, 2, 2));
	EXPECT_TRUE(isATriangle(1, 2, 2));
	EXPECT_TRUE(isATriangle(3, 4, 5));
}

TEST(isTriangleTest,  Negative){
	EXPECT_FALSE(isATriangle(1, 1, -1));
	EXPECT_FALSE(isATriangle(1, -1, 1));
	EXPECT_FALSE(isATriangle(-1, 1, 1));
	EXPECT_FALSE(isATriangle(INT_MIN, 1, 1));
}

TEST(isTriangleTest, Zero){
	EXPECT_FALSE(isATriangle(0, 0, 0));
	EXPECT_FALSE(isATriangle(1, 2, 0));
	EXPECT_FALSE(isATriangle(0, 1, 2));
	EXPECT_FALSE(isATriangle(1, 0, 2));
}

TEST(TriangleTypeTest, IsoscelesMin_1){
	EXPECT_EQ("Isosceles", TriangleType(100, 100, 1));
	EXPECT_EQ("Isosceles", TriangleType(100, 100, 2));
	EXPECT_EQ("Isosceles", TriangleType(100, 1, 100));
	EXPECT_EQ("Isosceles", TriangleType(100, 2, 100));
	EXPECT_EQ("Isosceles", TriangleType(1, 100, 100));
	EXPECT_EQ("Isosceles", TriangleType(2, 100, 100));
}

TEST(TriangleTypeTest, Equilateral){
	EXPECT_EQ("Equilateral", TriangleType(100, 100, 100));
}

TEST(TriangleTypeTest, IsoscelesMax_1){
	EXPECT_EQ("Isosceles", TriangleType(100, 100, 199));
	EXPECT_EQ("Isosceles", TriangleType(100, 199, 100));
	EXPECT_EQ("Isosceles", TriangleType(199, 100, 100));
	EXPECT_EQ("Isosceles", TriangleType(3, 2, 2));
	EXPECT_EQ("Isosceles", TriangleType(2, 3, 2));
	EXPECT_EQ("Isosceles", TriangleType(2, 2, 3));
}

TEST(TriangleTypeTest, NotTriangle){
	EXPECT_EQ("Not a Triangle", TriangleType(100, 100, 200));
	EXPECT_EQ("Not a Triangle", TriangleType(100, 200, 100));
	EXPECT_EQ("Not a Triangle", TriangleType(200, 100, 100));
	EXPECT_EQ("Not a Triangle", TriangleType(4, 1, 2));
	EXPECT_EQ("Not a Triangle", TriangleType(1, 4, 2));
	EXPECT_EQ("Not a Triangle", TriangleType(1, 2, 4));
}
TEST(TriangleTypeTest, Scalene){
	EXPECT_EQ("Scalene", TriangleType(3, 4, 5));
	EXPECT_EQ("Scalene", TriangleType(198, 199, 200));
}
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