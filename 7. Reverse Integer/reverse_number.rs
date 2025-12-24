fn reverse_number(mut number: isize) -> isize{
	let base: isize = 10;
	let negative: bool = number < 0;
	
	number = if (number < 0) {(number * -1)} else {(number * 1)};
	
	let mut nh: isize = number;
	let mut out: isize = 0;
	let mut i: isize = 1;
	let mut modulo;
	
	while (nh > 0){
		out *= i;
		modulo = nh % base;
		out += modulo;
		nh -= modulo;
		nh /= base;
		i = 10;
	}
	
	if (negative){
		out *= -1;
	}
	
	return (out);
}

fn main (){
	println!("{}", reverse_number(-35));
}
