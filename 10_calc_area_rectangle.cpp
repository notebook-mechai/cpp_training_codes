#include <iostream>
#include <math.h>
using namespace std;

int main(){
	double w, l , result;
	cout << "--- welcome to online calc area rectangle" << endl;
	
	cout << "size of width: ";
	cin >> w;
	
	cout << "size of lenght: ";
	cin>> l;
	
	result = w * l;
	
	cout << "Area of rectangle: " << result;
	return 0;

}