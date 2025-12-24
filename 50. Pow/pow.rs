fn power (significand:f64, exponent: f64) -> f64{
	let mut out: f64 = 1.0;
	
	if exponent > 0.0{
		let exp: i32 = exponent as i32; 
		for i in 0..exp{
			out *= significand;
		}
	} else if exponent < 0.0{
		let exp: i32 = (exponent * -1.0) as i32;
		for i in 0..exp{
			out /= significand;
		}
	} else if exponent == 0.0{
		out = 1.0;
	}
	
	return out;
}

fn main () {
	let significand: f64 = 2.0;
	let exponent: f64 = 0.0;
	
	println!("{}\n\n\n", power(significand, exponent));
}
