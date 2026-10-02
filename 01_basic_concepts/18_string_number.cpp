#include <iostream>
#include <string>
#include <stdlib.h> // convert function such as stoi OR atoi
#include <sstream>
#include <typeinfo>
using namespace std;

int main(){
	string x = "2";
	string y = "4";
	cout << "result is: " << x+y << endl;
	int result = stoi(x) + stoi(y); //stoi => string to integer
	cout << "another resutl is: " << result << endl;
	// --- way one ----------------------------------------------------------
	char str3[] = "31337 tester";
	cout << "another resutl is: " << stoi(str3) << endl; // actually remove string or characters part
	// --- way two ----------------------------------------------------------
	char* str1 = "141";
    char* str2 = "3.14";
    int res1 = atoi(str1); // atoi => arhument to integer
    int res2 = atoi(str2);
    cout << "atoi(" << str1 << ") is " << res1 << endl;
    cout << "atoi(" << str2 << ") is " << res2 << endl;
    // --- way three -----------------------------------------------------------
    string num = "145836";
    cout << "\nnum is string type:" << num << endl;
    stringstream newValue; // object from the class stringstream
    newValue << num; // inserting string num in newValue stream
    
    // The object has the value 12345
    // and stream it to the integer x
    int z = 0;
    newValue >> z;
    cout << "num is string type:" << z << endl;
    // --- way four --------------------------------------------------------------
    const char* str_num = "12395.0000046";
    float a;
    sscanf(str_num, "%f", &a);
    cout << "The value of a: " << a << endl;
    // --- way five --------------------------------------------------------------
    
    string str_number = "54";
    int number = 0;
    // Traversing string
    for (char c : str_number) {
//    	cout << typeid(c).name() << endl;
        // Checking if the element is number
        if (c >= '0' && c <= '9') {
//            number = number * 10 + (c);
            number = number * 10 + (c - '0');
        }
    }
    cout << number << endl;
    
    // ------------------------------------------------------------------------------
    cout << '5' - '0' << endl;
    cout << '4' - '0' << endl;
//    cout << '9' + '1' << endl;
//    cout << "5" - "4" << endl;
    
	return 0;
}