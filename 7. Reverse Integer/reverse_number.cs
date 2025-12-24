using System;

namespace rn
{
	class rn
	{
		static int reverse_number(int number, int radix = 10)
		{
			bool negative = (number < 0);
			
			number = (number < 0) ? (number * -1) : (number * 1);
			
			int nh = number, nje = 0, i = 1, mod;
			
			do{
				nje *= i;
				mod = nh % radix;
				nje += mod;
				nh -= mod;
				nh /= radix;
				i = 10;
			} while (nh > 0);
			
			if (negative){
				nje *= -1;
			}
			
			return (nje);
		}
		
		static void Main ()
		{
			int number = -1204;
			
			Console.WriteLine(reverse_number(number));
		}
	}
}
