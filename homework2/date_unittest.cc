#include <limits.h>
#include "gtest/gtest.h"
#include "date.h"


TEST(dataTest,  Worst_Case){
	EXPECT_EQ("1812/1/2",  nextdate(1812, 1, 1));
	EXPECT_EQ("1813/1/3",  nextdate(1813, 1, 2));
	EXPECT_EQ("1912/1/2",  nextdate(1912, 1, 1));
	EXPECT_EQ("2011/1/2",  nextdate(2011, 1, 1));
	EXPECT_EQ("2012/1/2",  nextdate(2012, 1, 1));
	EXPECT_EQ("1812/1/3",  nextdate(1812, 1, 2));
	EXPECT_EQ("1813/1/3",  nextdate(1813, 1, 2));
	EXPECT_EQ("1912/1/3",  nextdate(1912, 1, 2));
	EXPECT_EQ("2011/1/3",  nextdate(2011, 1, 2));
	EXPECT_EQ("2012/1/3",  nextdate(2012, 1, 2));
	EXPECT_EQ("1812/1/16",  nextdate(1812, 1, 15));
	EXPECT_EQ("1912/1/16",  nextdate(1912, 1, 15));
	EXPECT_EQ("2011/1/16",  nextdate(2011, 1, 15));
	EXPECT_EQ("2012/1/16",  nextdate(2012, 1, 15));
	EXPECT_EQ("1812/1/31",  nextdate(1812, 1, 30));
	EXPECT_EQ("1813/1/31",  nextdate(1813, 1, 30));
	EXPECT_EQ("1912/1/31",  nextdate(1912, 1, 30));
	EXPECT_EQ("2011/1/31",  nextdate(2011, 1, 30));
	EXPECT_EQ("2012/1/31",  nextdate(2012, 1, 30));

}

TEST(dateTest,  YearCase){
	EXPECT_EQ("2013/1/1",  nextdate(2012, 12, 31));
}

TEST(dateTest,  MonthCase){
	EXPECT_EQ("2011/2/1",  nextdate(2011, 1, 31));
	EXPECT_EQ("2012/2/1",  nextdate(2012, 1, 31));
	EXPECT_EQ("2012/4/1",  nextdate(2012, 3, 31));
	EXPECT_EQ("2012/5/1",  nextdate(2012, 4, 30));
	EXPECT_EQ("2012/6/1",  nextdate(2012, 5, 31));
	EXPECT_EQ("2012/7/1",  nextdate(2012, 6, 30));
	EXPECT_EQ("2012/8/1",  nextdate(2012, 7, 31));
	EXPECT_EQ("2012/9/1",  nextdate(2012, 8, 31));
	EXPECT_EQ("2012/10/1",  nextdate(2012, 9, 30));
	EXPECT_EQ("2012/11/1",  nextdate(2012, 10, 31));
	EXPECT_EQ("2012/12/1",  nextdate(2012, 11, 30));
	EXPECT_EQ("2013/1/1",  nextdate(2012, 12, 31));
}

TEST(dateTest,  leapYearCase){
	EXPECT_EQ("2000/2/29",  nextdate(2000, 2, 28));
	EXPECT_EQ("2000/3/1",  nextdate(2000, 2, 29));
	EXPECT_EQ("2011/3/1",  nextdate(2011, 2, 28));	
	EXPECT_EQ("1996/3/1",  nextdate(1996, 2, 29));	
	EXPECT_EQ("1996/2/29",  nextdate(1996, 2, 28));	
	EXPECT_EQ("Out of year range 1812-2012",  nextdate(2100, 2, 28));	
	EXPECT_EQ("Cannot have Feb 29",  nextdate(2001, 2, 29));	
}
TEST(dateTest,  Decision_Table_Case){
	EXPECT_EQ("2001/4/16",  nextdate(2001, 4, 15));
	EXPECT_EQ("2001/5/2",  nextdate(2001, 5, 1));	
	EXPECT_EQ("Error day 31",  nextdate(2001, 4, 31));
	EXPECT_EQ("2001/1/16",  nextdate(2001, 1, 15));
	EXPECT_EQ("2001/2/1",  nextdate(2001, 1, 31));
	EXPECT_EQ("2001/12/16",  nextdate(2001, 12, 15));
	EXPECT_EQ("2002/1/1",  nextdate(2001, 12, 31));
	EXPECT_EQ("2001/2/16",  nextdate(2001, 2, 15));
	EXPECT_EQ("2004/2/29",  nextdate(2004, 2, 28));
	EXPECT_EQ("2001/3/1",  nextdate(2001, 2, 28));	
	EXPECT_EQ("2004/3/1",  nextdate(2004, 2, 29));	
	EXPECT_EQ("Cannot have Feb 29",  nextdate(2001, 2, 29));	
	EXPECT_EQ("Error day 30",  nextdate(2001, 2, 30));	
}

TEST(dataTest, Equivalence_Class_Case){
	EXPECT_EQ("Error month -1",  nextdate(1912, -1, 15));
	EXPECT_EQ("Error day -1",  nextdate(1912, 6, -1));
	EXPECT_EQ("Error month -1",  nextdate(1912, -1, -1));
	EXPECT_EQ("Error month 13",  nextdate(1912, 13, 1));
	EXPECT_EQ("Error day 32",  nextdate(1912, 1, 32));
	EXPECT_EQ("Out of year range 1812-2012",  nextdate(1811, 1, 1));
	EXPECT_EQ("Out of year range 1812-2012",  nextdate(2013, 1, 1));

}

