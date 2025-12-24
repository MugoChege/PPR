using System;

namespace palindrome_number_by_number_ns
{
	class palindrome_number_by_number_c
	{
	static bool negative_as_i_squared = true;
	
	static int reverse_number (int number){
		int base_radix = 10;
		int nh = number;
		int i = 1;
		int nje = 0;
		int mod;
		
		while (nh > 0){
			nje *= i;
			mod = nh % base_radix;
			nje += mod;
			nh -= mod;
			nh /= base_radix;
			i = 10;
		}
		
		return (nje);
	}
	
	static bool palindrome_checker (int number){
		bool nje = false;
		bool negative = (number < 0);
		
		number = (number < 0) ? (number * -1) : (number * 1);
		
		int reversed_number = reverse_number(number);
		
		if (negative_as_i_squared){
			nje = (number == reversed_number);
		} else {
			if (negative){
				nje = ((number * -1) == reversed_number);
			} else {
				nje = (number == reversed_number);
			}
		}
		
		return (nje);
	}
	
	static void Main (string [] args){
		Console.WriteLine("This is the handy work of C#");
		
		Console.WriteLine(palindrome_checker(232321));
	}
	}
}
