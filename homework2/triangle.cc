#include "triangle.h"
bool isATriangle(int a,  int b,  int c){
	if ((a < b + c) && (b < a + c) && (c < a +b) 
		&& (a > 0) && (b>0) && (c >0)) 
		return true;
	return false;
}

string TriangleType(int a,  int b,  int c){
if(isATriangle(a,  b,  c)){	
	if ((a == b) && (b == c))
		return "Equilateral";
    else if ((a != b) && (a != c) && (b != c))
		return "Scalene";
    else if (a > 200 || b > 200 || c > 200)
		return "out of permitted range";
    else 
    	return "Isosceles";
 
 }else 
 	return "Not a Triangle";
	
}
