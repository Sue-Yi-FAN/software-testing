#include <limits.h>
#include "gtest/gtest.h"
#include "../date.h"

TEST(dataTest, C1_Testcase){
	EXPECT_EQ("Out of year range 1812-2012",  nextdate(1811, 1, 15));
	EXPECT_EQ("Error day -1",  nextdate(1912, 1, -1));
	EXPECT_EQ("Error day -1",  nextdate(1912, 4, -1));
	EXPECT_EQ("Error day -1",  nextdate(1912, 2, -1));
	EXPECT_EQ("Error day -1",  nextdate(1912, 12, -1));
	
	EXPECT_EQ("1912/2/1",  nextdate(1912, 1, 31));
	EXPECT_EQ("1912/1/16",  nextdate(1912, 1, 15));
	EXPECT_EQ("Error day 32",  nextdate(1912, 1, 32));

	EXPECT_EQ("1912/5/1",  nextdate(1912, 4, 30));
	EXPECT_EQ("1912/4/16",  nextdate(1912, 4, 15));
	EXPECT_EQ("Error day 32",  nextdate(1912, 4, 32));

	EXPECT_EQ("2000/2/28",  nextdate(2000, 2, 27));
	EXPECT_EQ("2000/2/29",  nextdate(2000, 2, 28));
	EXPECT_EQ("2001/3/1",  nextdate(2001, 2, 28));
	EXPECT_EQ("2000/3/1",  nextdate(2000, 2, 29));
	EXPECT_EQ("Cannot have Feb 29",  nextdate(2001, 2, 29));
	EXPECT_EQ("Error day 32", nextdate(1912, 2, 32));

	EXPECT_EQ("1913/1/1",  nextdate(1912, 12, 31));
	EXPECT_EQ("1912/12/16",  nextdate(1912, 12, 15));
	EXPECT_EQ("Error day 32",  nextdate(1912, 12, 32));

	EXPECT_EQ("Error month 13",  nextdate(1912, 13, 1));
	EXPECT_EQ("Out of year range 1812-2012",  nextdate(2013, 1, 1));
}

