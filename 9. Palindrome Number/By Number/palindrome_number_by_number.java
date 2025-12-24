public class palindrome_number_by_number{
	public static boolean negative_as_i_squared = true;
	
	public static int reverse_number (int number){
		int nh = number;
		int out = 0;
		int i = 1;
		int mod;
		int base = 10;
		
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
	
	public static boolean palindrome_checker (int number){
		boolean out = false;
		boolean negative = (number < 0);
		
		number = (number < 0) ? (number * -1) : (number * 1);
		
		int reversed_number = reverse_number(number);
		
		if (negative_as_i_squared){
			out = (number == reversed_number);
		} else {
			if (negative){
				out = ((number * -1) == reversed_number);
			} else {
				out = (number == reversed_number);
			}
		}
		
		return (out);
	}
	
	public static void main (String [] args){
		System.out.println ("This is the handy work of Java");
		
		System.out.println (palindrome_checker(23232));
	}
}
