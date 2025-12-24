#include <stdio.h>

double power (double significand, double exponent){
	double out = 1;
	
	if (exponent > 0){ 
		for (int i = 0; i < exponent; i++){
			out *= significand;
		}
	} else if (exponent < 0){
		exponent *= -1;
		for (int i = 0; i < exponent; i++){
			out /= significand;
		}
	} else if (exponent == 0){
		out = 1;
	}
	
	return (out);
}

int main () {
	double significand = 2;
	double exponent = -5;
	
	printf("%lf\n\n\n", power(significand, exponent));
	
	return (0);
}
