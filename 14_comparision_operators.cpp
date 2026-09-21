#include <iostream>
#include <string>
using namespace std;

int main(){
	string description  =  "== Equal to\n"
							"!= Not Equal\n"
							"> greater than\n"
							"< less than\n"
							">= Greater than or equal to\n"
							"<= less than or equal to\n";
	cout << description << endl;
	int x, y;
	cout << "number x: ";
	cin >> x;
	cout << "number y: ";
	cin >> y;
	if (x > y){
		cout << "x: "<< x << " y:"<< y << " result comparision is: "<< "x greater than y";
	}
	else{
		cout << "x: "<< x << " y:"<< y << " result comparision is: "<< "x less than y";	
	}
	return 0;
}