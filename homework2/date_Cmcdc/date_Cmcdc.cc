#include <limits.h>
#include "gtest/gtest.h"
#include "../date.h"

TEST(dataTest, Cmcdc_Testcase){
	//fixed month and day, change year.
	EXPECT_EQ("Out of year range 1812-2012",  nextdate(1811, 2, 28));
	EXPECT_EQ("2000/2/29",  nextdate(2000, 2, 28));
	EXPECT_EQ("1912/2/29",  nextdate(1912, 2, 28));
	EXPECT_EQ("1913/3/1",  nextdate(1913, 2, 28));

	EXPECT_EQ("2000/3/1", nextdate(2000, 2, 29));
	EXPECT_EQ("Cannot have Feb 29", nextdate(1993, 2, 29));

	//fixed years and day, change month.
	EXPECT_EQ("2000/2/1",  nextdate(2000, 1, 31));
	EXPECT_EQ("Error day 31",  nextdate(2000, 2, 31));
	EXPECT_EQ("Error day 31",  nextdate(2000, 9, 31));
	EXPECT_EQ("2001/1/1",  nextdate(2000, 12, 31));
	EXPECT_EQ("Error month 13",  nextdate(2000, 13, 31));

	//fixed years and month, change day.
	EXPECT_EQ("1933/5/1",  nextdate(1933, 4, 30));
	EXPECT_EQ("Error day 31",  nextdate(1933, 4, 31));
	EXPECT_EQ("1933/4/30",  nextdate(1933, 4, 29));
	EXPECT_EQ("1933/4/2",  nextdate(1933, 4, 1));
	EXPECT_EQ("Error day 0",  nextdate(1933, 4, 0));

	EXPECT_EQ("1933/1/2",  nextdate(1933, 1, 1));
	EXPECT_EQ("Error day 0",  nextdate(1933, 1, 0));
	EXPECT_EQ("Error day 32",  nextdate(1933, 1, 32));

	EXPECT_EQ("1992/2/2", nextdate(1992, 2, 1));
	EXPECT_EQ("Error day 31", nextdate(1992, 2, 31));
	EXPECT_EQ("1992/3/1", nextdate(1992, 2, 29));

	EXPECT_EQ("1910/12/2", nextdate(1910, 12, 1));
	EXPECT_EQ("Error day 32", nextdate(1910, 12, 32));
	EXPECT_EQ("Error day -1", nextdate(1910, 12, -1));
}

