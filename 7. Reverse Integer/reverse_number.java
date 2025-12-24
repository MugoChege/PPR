public class reverse_number {
	public static int reverse_number (int number){
		int base = 10;
		boolean negative = (number < 0);
		
		number = (number < 0) ? (number * -1) : (number * 1);
		
		int nh = number, out = 0, i = 1, mod;
		
		do{
			out *= i;
			mod = nh % base;
			out += mod;
			nh -= mod;
			nh /= base;
			i = 10;
		} while (nh > 0);
		
		if (negative){
			out *= -1;
		}
		
		return (out);
	}
	
	public static void main (String[] args){
		int number = -1207;
		System.out.println(reverse_number(number));
	}
}
