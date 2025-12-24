public class divide_two_integer{
	public static class Quotient{
		public int integer_quotient;
		public int fraction;
		public int out_of;
		
		public void print (){
			System.out.print(integer_quotient);
			System.out.print("\t");
			System.out.print(fraction);
			System.out.print("\t");
			System.out.println(out_of);
		}
	}
	
	public static int division_whole (int number, int divisor){
		int out = 0;
		int running_number = number;
		
		while ((running_number - divisor) >= 0){
			out++;
			running_number -= divisor;
		}
		
		return (out);
	}
	
	public static int modulo_whole (int number, int divisor){
		int running_number = number;
		
		while ((running_number - divisor) >= 0){
			running_number -= divisor;
		}
		
		return (running_number);
	}
	
	public static int multiplication (int multiplicand, int multiplier){
		int out = 0;
		
		for (int i = 0; i < multiplier; i++){
			out += multiplicand;
		}
		
		return (out);
	}
	
	public static Quotient division (int number, int divisor){
		int no_of_figures = 10;
		
		int base = 10;
		int counter = 0;
		int fraction = 0;
		int integer_quotient = division_whole (number, divisor);
		int remainder = modulo_whole (number, divisor);
		int running_number = remainder;
		int out_of = 1;
		
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
		
		Quotient o = new Quotient();
		o.integer_quotient = integer_quotient;
		o.fraction = fraction;
		o.out_of = out_of;
		
		return (o);
	}
	
	public static void main (String [] args){
		int number = 6402;
		int divisor = 8;
		
		Quotient q = division (number, divisor);
		
		q.print();
	}
}
