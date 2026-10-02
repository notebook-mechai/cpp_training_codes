#include <iostream>
#include <string>
using namespace std;

class Persons {       // The class
  public:             // Access specifier
    int ID;        // Attribute (int variable)
    string name;  // Attribute (string variable)
    string family;
};


int main() {
  Persons myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.ID = 15; 
  myObj.name = "john";
  myObj.family = "wick";

  // Print attribute values
  cout << myObj.ID << "\n"<< endl;
  cout << myObj.name  << "\n"<< endl;
  cout << myObj.family << endl;
  return 0;
}