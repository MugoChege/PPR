static negative_as_i_squared: bool = true;

fn reverse_number (number: isize) -> isize{
	let base: isize = 10;
	let mut nh: isize = number;
	let mut i: isize = 1;
	let mut out: isize = 0;
	let mut modulus: isize;
	
	while nh > 0{
		out *= i;
		modulus = nh % base;
		out += modulus;
		nh -= modulus;
		nh /= base;
		i = 10;
	}
	
	return out;
}

fn palindrome_checker (mut number: isize) -> bool{
	let mut out: bool = false;
	let negative: bool = number < 0;
	
	number = if number < 0 {number * -1} else {number * 1};
	
	let reversed_number: isize = reverse_number (number);
	let nais: bool;
	
	unsafe{
		nais = negative_as_i_squared;
	}
	
	if nais {
		out = number == reversed_number
	} else {
		if negative{
			out = (number * -1) == reversed_number;
		} else {
			out = number == reversed_number;
		}
	}
	
	return out;
}

fn main (){
	println!("This is the handy work of Rust");
	
	println!("{}\n\n", palindrome_checker(232321));
}
