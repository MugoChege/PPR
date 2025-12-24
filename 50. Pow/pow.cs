using System;

namespace Power
{
	class Power_class
	{
		static double power (double significand, double exponent)
		{
			double nje = 1;
			
			if (exponent > 0)
			{
				for (int i = 0; i < exponent; i++)
				{
					nje *= significand;
				}
			}
			else if (exponent < 0)
			{
				exponent *= -1;
				for (int i = 0; i < exponent; i++)
				{
					nje /= significand;
				}
			}
			else if (exponent == 0)
			{
				nje = 1;
			}
			
			return (nje);
		}
		
		static void Main ()
		{
			double significand = 2;
			double exponent = -5;
			
			Console.WriteLine(power(significand, exponent));
		}
	}
}
