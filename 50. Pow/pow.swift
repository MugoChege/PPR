func power (significand: Double, exponent: Double) -> Double {
	var out: Double = 1.0;
	
	if (exponent > 0.0){
		var exp: Int = Int(exponent);
		for i in 0..<exp{
			out *= significand;
		}
	} else if (exponent < 0.0){
		var exp: Int = Int(exponent * -1);
		for i in 0..<exp{
			out /= significand;
		}
	} else if (exponent == 0.0){
		out = 1.0;
	}
	
	return out;
}

var significand: Double = 2.0;
var exponent: Double = 0.0;

print (power(significand: significand, exponent: exponent));
