#include <iostream>
#include <math.h>
using namespace std;

int main(){
	const double pi = 3.14;
	double r, result_area, result_circumference_circle ; //radius
	
	cout << "please enter  radius of the circle: ";
	cin >> r;
		
	result_area = pi * r * r;
	cout << "result area of the circle:" << result_area << endl;
	
	result_circumference_circle = pi * r * 2;
	cout << "result circumference of the circle:" << result_circumference_circle << endl;
	
	return 0;
}