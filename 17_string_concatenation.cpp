#include <iostream>
#include <string>
using namespace std;

int main(){
	string name, family, fullname;
	
	cout << "you'r name:";
	cin >> name;
	
	cout << "you'r family:";
	cin >> family;
	
//	fullname = name + " "+ family;
	fullname = name.append(family);
	cout << "you'r fullname is: " << fullname;

	return 0;
	
	
}