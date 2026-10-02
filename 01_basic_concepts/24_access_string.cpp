#include <iostream>
#include <string>
using namespace std;

int main(){
	string text = "i      want some tea.";
	cout << text[5] << endl; // fetch character by index then show for you
	cout << text[text.length() - 1] << endl;
	
	text[0] = 'D';
	text[1] = 'o';
	text[2] = ' ';
	text.at(3) = 'y';
	text.at(4) = 'o';
	text.at(5) = 'u';
	text[text.size() - 1] =  '?';
	cout << text << endl;
	
	return 0;
}