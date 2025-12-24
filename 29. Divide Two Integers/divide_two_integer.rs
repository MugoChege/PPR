struct Quotient{
	integer_quotient: isize,
	fraction: isize,
	out_of: isize
}

impl Quotient{
	fn print(&self) -> (){
		println!("The quotient is:\t{}\nand {} parts of {} divisions of the divisor\n\n", self.integer_quotient, self.fraction, self.out_of);
	}
}

fn division_whole (number: isize, divisor: isize) -> isize{
	let mut out: isize = 0;
	let mut running_number: isize = number;
	
	while (running_number - divisor) >= 0{
		out += 1;
		running_number -= divisor;
	}
	
	return out;
}

fn modulo_whole (number: isize, divisor: isize) -> isize {
	let mut running_number: isize = number;
	
	while (running_number - divisor) >= 0{
		running_number -= divisor;
	}
	
	return running_number;
}

fn multiplication (multiplicand: isize, multiplier: isize) -> isize{
	let mut out = 0;
	
	for i in 0..multiplier{
		out += multiplicand;
	}
	
	return out;
}

fn division (number: isize, divisor: isize) -> Quotient{
	let no_of_figures: isize = 10;
	let base: isize = 10;
	let mut counter: isize = 0;
	let mut fraction: isize = 0;
	let integer_quotient: isize = division_whole(number, divisor);
	let remainder: isize = modulo_whole(number, divisor);
	let mut running_number: isize = remainder;
	let mut out_of: isize = 1;
	
	while ((running_number != 0) && (counter < no_of_figures)){
		//running_number *= base;
		running_number = multiplication(running_number, base);
		//out_of *= base;
		out_of = multiplication(out_of, base);
		
		if fraction == 0{
			fraction += division_whole(running_number, divisor);
		} else {
			//fraction *= base;
			fraction = multiplication(fraction, base);
			
			fraction += division_whole(running_number, divisor);
		}
		
		running_number = modulo_whole(running_number, divisor);
		counter += 1;
	}
	
	let q: Quotient = Quotient {integer_quotient: integer_quotient, fraction: fraction, out_of: out_of};
	//q.integer_quotient = integer_quotient;
	//q.fraction = fraction;
	//q.out_of = out_of;
	
	return q;
}

fn main (){
	let number: isize = 6402;
	let divisor: isize = 8;
	
	let d: Quotient = division(number, divisor);
	
	d.print();
}
