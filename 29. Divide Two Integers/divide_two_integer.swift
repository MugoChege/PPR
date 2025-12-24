struct Quotient {
	var integer_quotient: Int
	var fraction: Int
	var out_of: Int
	
	func print_values () -> Void {
		print("This is the version from Swift");
		print(integer_quotient);
		print(fraction);
		print(out_of);
	}
}

func division_whole (number: Int, divisor: Int) -> Int {
	var out: Int = 0;
	var running_number: Int = number;
	
	while (running_number - divisor) >= 0{
		out += 1;
		running_number -= divisor;
	}
	
	return out;
}

func modulo_whole (number: Int, divisor: Int) -> Int {
	var running_number: Int = number;
	
	while (running_number - divisor) >= 0{
		running_number -= divisor;
	}
	
	return running_number;
}

func multiplication (multiplicand: Int, multiplier: Int) -> Int{
	var out = 0;
	
	for i in 0..<multiplier{
		out += multiplicand;
	}
	
	return out;
}

func division (number: Int, divisor: Int) -> Quotient{
	let no_of_figures: Int = 10;
	let base: Int = 10;
	var counter: Int = 0;
	var fraction: Int = 0;
	let integer_quotient = division_whole(number: number,divisor: divisor);
	let remainder = modulo_whole(number: number,divisor: divisor);
	var running_number = remainder;
	var out_of = 1;
	
	while ((running_number != 0) && (counter < no_of_figures)){
		//running_number *= base;
		running_number = multiplication(multiplicand: running_number, multiplier: base);
		//out_of *= base;
		out_of = multiplication(multiplicand: out_of, multiplier: base);
		
		if (fraction == 0){
			fraction += division_whole(number: running_number, divisor: divisor);
		} else {
			//fractioin *= base;
			fraction = multiplication(multiplicand: fraction, multiplier: base);
			
			fraction += division_whole(number: running_number,divisor: divisor);
		}
		
		running_number = modulo_whole(number: running_number,divisor: divisor);
		counter += 1;
	}
	
	return Quotient(integer_quotient: integer_quotient, fraction: fraction, out_of: out_of);
}

let number: Int = 6402;
let divisor: Int = 8;

let q: Quotient = division(number: number, divisor: divisor);

q.print_values();
