func reverse_number(num: Int, base: Int = 10) -> Int {
	var negative: Bool = num < 0;
	
	var number: Int = (num < 0) ? (num * -1) : (num * 1);
	
	var out: Int = 0;
	var i: Int = 1;
	var mod: Int;
	
	while number > 0{
		out *= i;
		mod = number % base;
		out += mod;
		number -= mod;
		number /= base;
		i = 10;
	}
	
	if (negative){
		out *= -1;
	}
	
	return (out);
}

print (reverse_number(num:-234567));
