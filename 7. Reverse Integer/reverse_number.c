#include <stdio.h>

int reverse_number(int number){
	int base = 10;
	int negative = (number < 0);
	
	number = (number < 0) ? (number * -1) : (number * 1);
	
	int nh = number;
	int out = 0;
	int i = 1;
	int mod;
	
	do {
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

void main () {
	int number = -120;
	
	printf("%d\n\n\n", reverse_number(number));
}
