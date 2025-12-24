#include <iostream>

using namespace std;

bool negative_as_i_squared = true;

int reverse_number (int number){
	int base = 10;
	int nh = number;
	int i = 1;
	int out = 0;
	int mod;
	
	while (nh > 0){
		out *= i;
		mod = nh % base;
		out += mod;
		nh -= mod;
		nh /= base;
		i = 10;
	}
	
	return (out);
}

bool palindrome_checker (int number){
	bool out = false;
	int negative = (number < 0);
	
	number = (number < 0) ? (number * -1) : (number * 1);
	
	int reversed_number = reverse_number(number);
	
	if (negative_as_i_squared){
		out = (number == reversed_number);
	} else {
		if (negative){
			out = ((number * -1) == reversed_number);
		} else {
			out = (number == reversed_number);
		}
	}
	
	return (out);
}

int main (){
	cout << "This is the handy work of C++" << endl;
	cout << (palindrome_checker(232321) ? ("True") : ("False")) << endl << endl;
	
	return (0);
}
