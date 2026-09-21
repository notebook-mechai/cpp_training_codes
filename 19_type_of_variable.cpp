#define _USE_MATH_DEFINES

#include <iostream>
#include <typeinfo>
#include <cmath>
#include <string>
using namespace std;

int main(){
	
	int x = 5;
	string text = "hello";
	char c = 'p';
	bool isNum = true;
	float  avg = 17.83;
	double pi = 3.141592653589793238462643383279502884197;
	
	cout << typeid(x).name() << endl;
	cout << typeid(text).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(isNum).name() << endl;
	cout << typeid(avg).name() << endl;
	cout << typeid(pi).name() << endl;
	
	cout << pi << endl;
	cout << M_PI << " " << M_E << " " << M_SQRT2 << endl;
}