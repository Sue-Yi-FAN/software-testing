#include <limits.h>
#include <string.h>
#include "gtest/gtest.h"

using namespace std;
bool isATriangle(int a,  int b,  int c){
	if ((a < b + c) && (b < a + c) && (c < a +b) && (a > 0) && (b>0) && (c >0))
		return true;
	return false;
}

string TriangleType(int a,  int b,  int c){
if(isATriangle(a,  b,  c)){	
	if ((a == b) && (b == c))
		return "Equilateral";
    else if ((a != b) && (a != c) && (b != c))
		return "Scalene";
    else 
    	return "Isosceles";
 }
 else
 	return "Not a Triangle";

}

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
}
int main(int argc,  char **argv) {
  ::testing::InitGoogleTest(&argc,  argv);
  return RUN_ALL_TESTS();
}
