let negativeAsISquared = true;

function reverseNumber (number, base = 10){
	let nh = number;
	let out = 0;
	let i = 1;
	
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

function palindromeChecker (number){
	let out = null;
	let negative = (number < 0);
	
	number = (number < 0) ? (number * -1) : (number * 1);
	
	reversedNumber = reverseNumber (number);
	
	if (negativeAsISquared){
		out = (number == reversedNumber);
	} else {
		if (negative){
			out = ((number * -1) == reversedNumber);
		} else {
			out = (number == reversedNumber);
		}
	}
	
	return (out);
}

console.log(palindromeChecker(232321));
