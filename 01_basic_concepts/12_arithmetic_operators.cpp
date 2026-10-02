#include <iostream>
using namespace std;

int main(){
	cout << "--- arithmetic operators: " << endl;
	string text = "+ Addition\n"
					"- Subtraction\n"
					"* Multiplication\n"
					"/ Division\n"
					"% Modulus\n"
					"++ Increment\n"
					"-- Decrement\n";
	cout << text << endl;
	
	double a, b;
	cout << "number a: ";
	cin >> a;
	cout << "number b: ";
	cin >> b;
	cout << "Addition a,b: " << a + b << endl;
	cout << "Subtraction a,b: " << a - b << endl;
	cout << "Division a,b: " << a / b << endl;
	
//	cout << "Modulus a,b:" << a%b << endl;

	int x = 8;
	int y = 3;
	cout << "Increment x++(8): " << x++ << endl;
	cout << "Increment ++x(8): " << ++x << endl;	
	cout << "Decrement y--(3): " << y-- << endl;
	cout << "Decrement --y(3): " << --y << endl;
			
	return 0;
}