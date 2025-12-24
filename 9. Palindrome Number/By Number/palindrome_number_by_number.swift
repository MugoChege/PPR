let negative_as_i_squared: Bool = true;

func reverse_number (number: Int) -> Int {
	let base: Int = 10;
	var nh: Int = number;
	var i: Int = 1;
	var out: Int = 0;
	var mod: Int;
	
	while nh > 0{
		out *= i;
		mod = nh % base;
		out += mod;
		nh -= mod;
		nh /= base;
		i = 10;
	}
	
	return out;
}

func palindrome_checker (number: Int) -> Bool{
	var out: Bool = false;
	let negative: Bool = (number < 0);
	var nh: Int = (number < 0) ? (number * -1) : (number * 1);
	
	let reversed_number: Int = reverse_number (number: nh);
	
	if (negative_as_i_squared){
		out = (nh == reversed_number);
	} else {
		if (negative){
			out = ((nh * -1) == reversed_number);
		} else {
			out  = (nh == reversed_number);
		}
	}
	
	return (out);
}

print ("This is the handy work of Swift");

print (palindrome_checker (number: 232312));
