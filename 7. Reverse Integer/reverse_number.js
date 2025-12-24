function reverse_number(number, base = 10){
	let negative = (number < 0);
	
	let number = (number < 0) ? (number * -1) : (number * 1);
	
	let nh = number;
	let out = 0;
	let i = 1;
	let mod;
	
	while (nh > 0){
		out *= i;
		mod = nh % base;
		out += mod;
		nh -= mod;
		nh /= base;
		i = 10;
	}
	
	if (negative){
		out *= -1;
	}
	
	return (out);
}

console.log(reverse_number(9753));
