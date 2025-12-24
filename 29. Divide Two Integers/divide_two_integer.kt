data class Quotient (var integer_quotient: Int = 0, var fraction: Int = 0, var out_off: Int = 0)

fun division_whole (number: Int, divisor: Int): Int{
	var out: Int = 0;
	var running_number: Int = number;
	
	while((running_number - divisor) >= 0){
		out++;
		running_number -= divisor;
	}
	
	return out;
}

fun modulo_whole (number: Int, divisor: Int): Int{
	var running_number = number;
	
	while((running_number - divisor) >= 0){
		running_number -= divisor;
	}
	
	return (running_number);
}

fun multiplication (multiplicand: Int, multiplier: Int): Int{
	var out = 0;
	
	for (i in 0 until multiplier){
		out += multiplicand;
	}
	
	return (out)
}

fun division (number: Int, divisor: Int, no_of_figures: Int = 10): Quotient{
	var base: Int = 10;
	var counter: Int = 0;
	var fraction: Int = 0;
	var integer_quotient: Int = division_whole(number, divisor);
	var remainder = modulo_whole(number, divisor);
	var running_number = remainder;
	var out_of = 1;
	
	while ((running_number != 0) && (counter < no_of_figures)){
		//running_number *= base;
		running_number = multiplication(running_number, base);
		//out_of *= base;
		out_of = multiplication(out_of, base);
		
		if (fraction == 0){
			fraction += division_whole(running_number, divisor);
		} else {
			//fraction *= base;
			fraction = multiplication(fraction, base);
			fraction += division_whole(running_number, divisor);
		}
		
		running_number = modulo_whole(running_number, divisor);
		counter++;	
	}
	
	return Quotient(integer_quotient, fraction, out_of)
}

fun main (){
	var number: Int = 6402;
	var divisor: Int = 8;
	
	println(division(number, divisor).toString());
}
