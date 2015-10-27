#include <limits.h>
#include <string.h>
#include "gtest/gtest.h"

using namespace std;

string nextdate(int year,  int month,  int day){
	int tomorrowDay = 0;
	int tomorrowMonth = month;
	int tomorrowYear = year;
	string ans = "2";
	switch(month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10:
			if(day < 31 && day > 0){
				tomorrowDay = day + 1;
			}
			else if(day < 0 || day > 31){
				return "Error day " + to_string(day);
			}
			else{
				tomorrowDay = 1;
				tomorrowMonth = month + 1;
			}
			break;
		case 4: case 6: case 9: case 11:
			if(day < 30){
				tomorrowDay = day + 1;
			}
			else if(day < 0 || day > 30){
				return "Error day " + to_string(day);
			}
			else{
				tomorrowDay = 1 ;
				tomorrowMonth = month + 1;
			}
			break; 
		case 2:
			if(day < 28 && day > 0){
				tomorrowDay = day + 1;
			}
			else if(day == 28){
				if(year%400==0||(year%4==0&&year%100!=0)){
					tomorrowDay =day + 1;
				}
				else{
					tomorrowDay = 1;
					tomorrowMonth += 1;
				}
			}
			else if(day == 29){
				if(year%400==0||(year%4==0&&year%100!=0)){
					tomorrowDay = 1;
					tomorrowMonth = 3;
				}
				else{
				return "Cannot have Feb " + to_string(day);
				}
			}
			else{
				return "Error day " + to_string(day);
			}
			break;
		case 12:
			if(day < 31){
				tomorrowDay = day + 1;
			}
			else if(day < 0 || day > 31){
				return "Error day " + to_string(day);
			}
			else{
				tomorrowDay = 1;
				tomorrowMonth = 1;
				tomorrowYear += 1;
			}
			break;
		default:
			return "Error month " + to_string(month);
	}
	ans =to_string(tomorrowYear)+'/'+
	to_string(tomorrowMonth)+'/'+
	to_string(tomorrowDay);
	return ans;
}

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
	EXPECT_EQ("2100/3/1",  nextdate(2100, 2, 28));	
	EXPECT_EQ("Cannot have Feb 29",  nextdate(2100, 2, 29));	
}

TEST(dateTest,  ErrorCase){
	EXPECT_EQ("Cannot have Feb 29",  nextdate(1, 2, 29));
	EXPECT_EQ("Error month 13",  nextdate(1, 13, 1));
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

int main(int argc,  char **argv) {
  ::testing::InitGoogleTest(&argc,  argv);
  return RUN_ALL_TESTS();
}
