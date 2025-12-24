function power (significand, exponent){
	let out = 1;
	
	if (exponent > 0){
		for (let i = 0; i < exponent; i++){
			out *= significand;
		}
	} else if (exponent < 0){
		exponent *= -1
		for (let i = 0; i < exponent; i++){
			out /= significand;
		}
	} else if (exponent == 0){
		out = 1;
	}
	
	return out;
}

significand = 2;
exponent = 0;

console.log (power(significand, exponent));
console.log ("\n\n\n");
