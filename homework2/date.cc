#include "date.h"

string nextdate(int year,  int month,  int day){
	int tomorrowDay = 0;
	int tomorrowMonth = month;
	int tomorrowYear = year;
	string ans = "2";
	if(year < 1812 || year > 2012)
		return "Out of year range 1812-2012";
	else{
		switch(month)
		{
			case 1: case 3: case 5: case 7: case 8: case 10:
				if(day < 31 && day > 0){
					tomorrowDay = day + 1;
				}
				else if(day <= 0 || day > 31){
					return "Error day " + to_string(day);
				}
				else{
					tomorrowDay = 1;
					tomorrowMonth = month + 1;
				}
				break;
			case 4: case 6: case 9: case 11:
				if(day < 30 && day > 0){
					tomorrowDay = day + 1;
				}
				else if(day <= 0 || day > 30){
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
				if(day < 31 && day > 0){
					tomorrowDay = day + 1;
				}
				else if(day <= 0 || day > 31){
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
	}
	ans =to_string(tomorrowYear)+'/'+
	to_string(tomorrowMonth)+'/'+
	to_string(tomorrowDay);
	return ans;
}