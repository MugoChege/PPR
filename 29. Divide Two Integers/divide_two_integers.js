function division_whole (number, divisor){
	let out = 0;
	let running_number = number
	
	while ((running_number - divisor) >= 0){
		out++;
		running_number -= divisor;
	}
	
	return (out);
}

function modulo_whole (number, divisor){
	let running_number = number;
	
	while ((running_number - divisor) >= 0){
		running_number -= divisor;
	}
	
	return (running_number);
}

function multiplication (multiplicand, multiplier){
	let out = 0;
	
	for (let i = 0; i < multiplier; i++){
		out += multiplicand;
	}
	
	return out;
}

function division (number, divisor, no_of_figures = 10){
	let base = 10;
	let counter = 0;
	let fraction = 0;
	let integer_quotient = division_whole(number, divisor);
	let remainder = modulo_whole(number, divisor);
	let running_number = remainder;
	let out_of = 1;
	
	while ((running_number != 0) && (counter < no_of_figures)){
		//running_number *= base;
		running_number = multiplication(running_number, base);
		//out_of *= base
		out_of = multiplication(out_of, base);
		
		if (fraction == 0){
			fraction += division_whole(running_number, divisor);
		} else {
			//fraction *= base
			fraction = multiplication(fraction, base);
			fraction += division_whole(running_number, divisor);
		}
		
		running_number = modulo_whole(running_number, divisor)
		counter += 1;
	}
	
	return [integer_quotient, fraction, out_of];
}


number = 6402
divisor = 8

console.log(division(number, divisor));
//console.log(modulo(number, divisor));
//console.log(division_fractiontion(7, divisor));
