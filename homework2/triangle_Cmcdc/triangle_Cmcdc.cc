#include <limits.h>
#include "gtest/gtest.h"
#include "../triangle.h"

TEST(TriangleType,Cmcdc_Testcase){
	//fix b, c change a
	EXPECT_EQ("Isosceles", TriangleType(1, 195, 195 ));
	EXPECT_EQ("Not a Triangle", TriangleType(400, 195, 195 ));
	EXPECT_EQ("Not a Triangle", TriangleType(-1, 195,195 ));
	EXPECT_EQ("out of permitted range", TriangleType(201, 195, 195));
	EXPECT_EQ("Equilateral", TriangleType(195, 195, 195 ));

	//fix a, b change c
	EXPECT_EQ("Not a Triangle", TriangleType(193, 190, 400));
	EXPECT_EQ("Not a Triangle", TriangleType(193, 190, -1));
	EXPECT_EQ("out of permitted range", TriangleType(193, 190, 201));
	EXPECT_EQ("Scalene", TriangleType(193, 190, 194 ));
	EXPECT_EQ("Isosceles", TriangleType(193, 190, 193 ));

	//fix a, c change b
	EXPECT_EQ("Not a Triangle", TriangleType(180, 400, 180));
	EXPECT_EQ("Not a Triangle", TriangleType(180, -1, 180));
	EXPECT_EQ("out of permitted range", TriangleType(180, 201, 180));
	EXPECT_EQ("Isosceles", TriangleType(180, 170, 180 ));
	EXPECT_EQ("Equilateral", TriangleType(180, 180, 180 ));

}