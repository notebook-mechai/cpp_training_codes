#include <iostream>
#include <string>
using namespace std;

int main(){
	int a , b;
	a = b = 1;
	double sum, sub, mul, div;
	cout << "The number one:";
	cin >> a;
	
	cout << "The number two:";
	cin >> b;
	
	sum = a + b;
	sub = a - b;
	
	mul  = a * b;
	div = a / b;
	
	cout << "The sum result:" << sum << endl;
	cout << "The sub result:" << sub << endl;
	cout << "The mul result:" << mul << endl; 
	cout << "The div result:" << div << endl;
//	cout << a << endl;
//	cout << b << endl;
	return 0;
}