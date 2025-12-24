using System;

namespace sum_of_three_ns
{
	class sum_of_three_class
	{
		public static int result_number = 0;
		public static int number_of_elements = 3;
		
		public class result {
			int [] values = new int [number_of_elements];
			public bool isNull = false;
			
			public result (){
				isNull = true;
				/*for (int i = 0; i < a.Length; i++){
					values[i] = a[i];
				}*/
			}
			
			public void set_result (int [] a){
				for (int i = 0; i < a.Length; i++){
					values[i] = a[i];
				}
			}
			
			public void print(){
				for (int i = 0; i < values.Length; i++){
					Console.Write(values[i]);
					Console.Write("\t");
				}
				Console.WriteLine();
			}
		}
		
		static int factorial(int number){
			int nje = 1;
			
			for (int i = number; i > 0; i--){
				nje *= i;
			}
			
			return (nje);
		}
		
		static result [] sum_of_three (int [] list, int combination, int target = 0)
		{
			int len_list = list.Length;
			result [] nje = new result [combination];
			int result_pointer = 0;
			
			for (int a = 0; a < len_list; a++){
				for (int b = 0; b < len_list; b++){
					if (b > a){
						for (int c = 0; c < len_list; c++){
							if (c > b){
								if ((a != b) && (a != c) && (b != c)){
									int aa = list[a];
									int bb = list[b];
									int cc = list[c];
									
									if ((aa != bb) && (aa != cc) && (bb != cc)){
										if ((aa + bb + cc) == target){
											//int [] z = {a, b, c};
											//int [] z = {aa, bb, cc};
											
											int [] y = {aa, bb, cc};
											result z = new result();
											z.set_result(y);
											nje [result_pointer] = z;
											result_pointer++;
											result_number = result_pointer;
											
											/*
											for (int i = 0; i < z.Length; i++){
												nje[i] = z[i];
												Console.Write(nje[i]);
												Console.Write("\t");
											}
											Console.Write("\n\n");
											*/
										}
									}
								}
							}
						}
					}
				}
			}
			return nje;
		}
		
		static void Main (string [] args)
		{
			int [] nums = {-1,0,1,2,-1,-4};
			
			int len_nums = nums.Length;
			
			int sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
			
			result [] h = sum_of_three(nums, sample_space);
			
			for (int i = 0; i < result_number; i++){
				//Console.WriteLine(h[i]);
				h[i].print();
			}
		}
		
	}
}
