#include <iostream>
using namespace std;

int main(){
	cout << "--- c++ Assignment Operators " << endl;
	string text = "= , x = 5\n"
	"= , x = 5\n"
	"+= , x += 3\n"
	"-= , x -= 3n"
	"*= , x *= 3\n"
	"/= , x /= 3\n"
	"%= , x %= 3\n"
	"&= , x &= 3\n"
	"|= , x |= 3\n"
	"^= , x ^= 3\n"
	">>= , x >>= 3\n"
	"<<= , x <<= 3\n";
	
	int x;
	x = 5;
//	cout << "= , x = 5 => "  << x << endl;
//	
//	x += 3;
//	cout << "+= , x += 3 => "  <<  x << endl;
//	
//	x -= 3;
//	cout << "-= , x -= 3 => " << x << endl;
//	
//	x *= 3;
//	cout << "*= , x *= 3 => " << x << endl;
//	
//	x /= 3;
//	cout << "/= , x /= 3 => " << x << endl;
//	
//	x %= 3;
//	cout << "%= , x %= 3 => " << x << endl;
	
	x &= 3; // and
	cout << "&= , x &= 3 => " << x << endl;
	
	x |= 3; // or
	cout << "|= , x |= 3 => " << x << endl;
	
	x ^= 3; // xor
	cout << "^= , x ^= 3 => " << x << endl;
	
	x >>= 3; // Right Shift
	cout << ">>= , x >>= 3 => " << x << endl;
	
	x <<= 3; // Left Shift
	cout <<  "<<= , x <<= 3 => "<< x << endl;
	
			
	
	
 
 
  return 0;
}