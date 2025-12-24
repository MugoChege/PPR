using System;

namespace divide_two_integer_ns
{
	class divide_two_integer_c
	{
		public struct Quotient{
			public int integer_quotient;
			public int fraction;
			public int out_of;
			
			public Quotient (int iq, int f, int oo){
				integer_quotient = iq;
				fraction = f;
				out_of = oo;
			}
			
			public void print (){
				Console.Write(integer_quotient);
				Console.Write("\t");
				Console.Write(fraction);
				Console.Write("\t");
				Console.WriteLine(out_of);
			}
		}
		
		public static int division_whole(int number, int divisor){
			int nje = 0;
			int running_number = number;
			
			while ((running_number - divisor) >= 0){
				nje++;
				running_number -= divisor;
			}
			
			return (nje);
		}
		
		public static int modulo_whole (int number, int divisor){
			int running_number = number;
			
			while ((running_number - divisor) >= 0){
				running_number -= divisor;
			}
			
			return (running_number);
		}
		
		public static int multiplication (int multiplicand, int multiplier){
			int nje = 0;
			
			for (int i = 0; i < multiplier; i++){
				nje += multiplicand;
			}
			
			return (nje);
		}
		
		public static Quotient division (int number, int divisor){
			int no_of_figures = 10;
			int base_radix = 10;
			int counter = 0;
			int fraction = 0;
			int integer_quotient = division_whole(number, divisor);
			int remainder = modulo_whole (number, divisor);
			int running_number = remainder;
			int out_of = 1;
			
			while ((running_number != 0) && (counter < no_of_figures)){
				//running_number *= base_radix;
				running_number = multiplication(running_number, base_radix);
				//out_of *= base_radix;
				out_of = multiplication (out_of, base_radix);
				
				if (fraction == 0){
					fraction += division_whole(running_number, base_radix);
				} else {
					//fraction *= base_radix;
					fraction = multiplication(fraction, base_radix);
					fraction += division_whole (running_number, divisor);
				}
				
				running_number = modulo_whole(running_number, divisor);
				counter++;
			}
			
			return new Quotient(integer_quotient, fraction, out_of);
		}
		
		public static void Main (string [] args) {
			int number = 6402;
			int divisor = 8;
			
			Quotient q = division(number, divisor);
			
			//Console.WriteLine(multiplication(number, divisor));
			q.print();
		}
	}
}
