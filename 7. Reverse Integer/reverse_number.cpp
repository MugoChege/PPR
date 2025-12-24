#include <iostream>

using namespace std;

int reverse_number (int number, int base = 10){
	bool negative = (number < 0);
	
	number = (number < 0) ? (number * -1) : (number * 1);
	
	int nh = number, out = 0, i = 1, mod;
	
	do{
		out *= i;
		mod = nh % base;
		out += mod;
		nh -= mod;
		nh /= base;
		i = 10;
	} while (nh > 0);
	
	if (negative){
		out *= -1;
	}
	
	return (out);
}

int main (){
	int number = -456789;
	
	cout << reverse_number(number) << endl << endl << endl;
	
	return 0;
}
