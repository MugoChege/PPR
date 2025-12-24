class pow{
	public static double power (double significand, double exponent){
		double out = 1;
		
		if (exponent > 0){
			for (int i = 0; i < exponent; i++){
				out *= significand;
			}
		} else if (exponent < 0){
			exponent *= -1;
			for (int i = 0; i < exponent; i++){
				out /= significand;
			}
		} else if (exponent == 0){
			out = 1;
		}
		
		return (out);
	}
	
	public static void main (String[] args){
		double significand = 2;
		double exponent = 0;
		
		System.out.println(power(significand, exponent));
	}
}
