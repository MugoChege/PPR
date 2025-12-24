fun power (significand: Double, exponent: Double) : Double {
	var out: Double = 1.0;
	
	if (exponent > 0){
		for (i in 0 until exponent.toInt()){
			out *= significand;
		}
	} else if (exponent < 0){
		var exp: Int = (exponent * -1).toInt();
		for (i in 0 until exp){
			out /= significand;
		}
	} else if (exponent == 0.0){
		out = 1.0;
	}
	
	return out;
}

fun main () {
	var significand: Double = 2.0;
	var exponent: Double = 0.0;
	
	println(power(significand, exponent));
	
}
