val negative_as_i_squared: Boolean = true;

fun reverse_number (number: Int) : Int {
	val base: Int = 10;
	var nh: Int = number;
	var i: Int = 1;
	var out: Int = 0;
	var mod: Int;
	
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

fun palindrome_checker (number: Int) : Boolean{
	var out: Boolean = false;
	val negative: Boolean = (number < 0);
	var nh: Int = number;
	
	nh = if (nh < 0) (number * -1) else (number * 1);
	
	val reversed_number = reverse_number(nh);
	
	if (negative_as_i_squared){
		out = (nh == reversed_number);
	} else {
		if (negative){
			out = ((nh * -1) == reversed_number);
		} else {
			out = (nh == reversed_number);
		}
	}
	
	return (out);
}

fun main (): Unit {
	println("This is the handy work of Kotlin");
	
	println(palindrome_checker(232312));
}
