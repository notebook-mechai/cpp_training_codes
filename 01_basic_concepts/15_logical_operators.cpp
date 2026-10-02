#include <iostream>
using namespace std;

int main(){
	
	int x;
	cout << "num x:";
	cin >> x;

	if ( x > 0 && x <10){
		cout << "x is between 0-10";
	}else if ( x > 10 && x <20){
		cout << "x is between 10-20";
	}else{
		cout << "out of range :(";
	}
	
	return 0;
}