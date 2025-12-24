#include <stdio.h>

int negative_as_i_squared = 1;

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

int palindrome_checker (int number){
	int out = 0;
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
	printf("This is the handy work of C.\n%s\n\n", (palindrome_checker(23232) ? ("True") : ("False")));
	
	return 0;
}
