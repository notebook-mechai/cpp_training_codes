#include <iostream>
#include <string>
using namespace std;

int main(){
	string text = "suggestion for me and you";
	cout << "Returns an indexed character from a string: " << text.at(4) << endl;
	cout << "Returns the length of a string: " << text.length() << endl;
	cout << "Alias of length(). Returns the length of a string: " << text.size() << endl;
	cout << "Returns the maximum length of a string: " << text.max_size() << endl;
	
	cout << "Checks wheter a string is empty or not: " << text.empty() << endl; // 0 - if the string is not empty ; 1 - if the string is empty
	cout << "Appends a string (or a part of a string) to another string: " << text.append(".") << endl;
	cout << "Returs a part of a string from a start index(position) and length: " << text.substr(11,4) << endl;
	
	cout << "Returns the index (position) of the first occurrence of a string or character: " << text.find("for") << endl;
	cout << "Returns the index (position) of the first occurrence of a string or character: " << text.find("f") << endl;
	cout << "Returns the index (position) of the last occurrence of a string or character: " << text.rfind("e") << endl;
	
	cout << "Replaces a part of a string with another string: " << text.replace(0, 0, "the ") << endl;
//	str1.replace(pos, n, m, c)                             // Replace with character
//	str1.replace(pos, n, str2)                            // Replace with string
//	str1.replace(pos1, n, str2, pos2,m)                  // Replace with substring
//	str1.replace(first, last, n, c);                    // Replace Character
//	str1.replace(first, last, str2)                    // Replace String
//	str1.replace (first, last, str2_first, str2_last);// Replace Substring


	cout << "Inserts a string at a specified index (position): " << text.insert(0, "> ") << endl;
	cout << "\nAlias of length(). Returns the length of a string: " << text.size() << endl;
	
	string msg = "The smile";
	cout << "After Removes String: " << msg << endl;
	msg.clear();
	if (msg.empty()){
		cout << "result Clear function: msg string is empty." << endl;
	} else {
		cout << "result clear function: msg string is Full." << endl;
	}
	
	return 0;
}