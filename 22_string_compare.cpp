#include <iostream>
#include <string>
using namespace std;

int main(){
	string str_one = "test";
	string str_two = "test";
	
	if(str_one.compare(str_two) == 0){
		cout << "String matched." << endl;
	}else{
		cout << "String Not matched!" << endl;
	}
	
	return 0;
}