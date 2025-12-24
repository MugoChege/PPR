using System;

namespace sum_of_three_closest
{
	class sum_of_three_closest
	{
		static int result_number = 0;
		static int number_of_elements = 3;
		
		public class Result{
			int [] values = new int [number_of_elements];
			int number_of_values;
			bool not_null;
			
			public void set_values (int [] list){
				number_of_values = list.Length;
				not_null = true;
				
				for (int i = 0; i < list.Length; i++){
					values[i] = list[i];
				}
			}
			
			public void empty_values (){
				not_null = false;
				int len_list = number_of_elements;
				
				for (int i = 0; i < len_list; i++){
					values[i] = 0;
				}
				
				number_of_values = 0;
			}
			
			public Result (int [] list){
				set_values (list);
			}
			
			
			public Result (){
			}
			
			
			public void print_values(){
				Console.WriteLine("This is the handy work of C#");
				int nje = 0;
				
				for (int i = 0; i < number_of_values; i++){
					Console.Write(values[i]);
					nje += values[i];
					
					if (i < (number_of_values - 1)){
						Console.Write("\t");
					}
				}
				
				Console.Write("\nThe sum of the values is:\t");
				Console.WriteLine(nje);
			}
		}
		
		static int factorial (int number){
			int nje = 1;
			
			for (int i = number; i > 0; i--){
				nje *= i;
			}
			
			return (nje);
		}
		
		static int absolute (int number){
			return (number < 0) ? (number * -1) : (number * 1);
		}
		
		static Result [] fun_sum_of_three_closest (int [] list, int target, int sample_size){
			int result_cursor = 0;
			int closest_difference = 0;
			bool first_execution = true;
			int len_list = list.Length;
			Result [] nje = new Result[sample_size];
			
			for (int a = 0; a < len_list; a++){
				for (int b = 0; b < len_list; b++){
					if (b > a){
						for (int c = 0; c < len_list; c++){
							if (c > b){
								if ((a != b) && (a != c) && (b != c)){
									int aa = list[a];
									int bb = list[b];
									int cc = list[c];
									
									//if ((aa != bb) && (aa != cc) && (bb != cc)){
									if (true){
										int difference = absolute((aa + bb + cc) - target);
										bool update_array = false;
										
										if (first_execution){
											closest_difference = difference;
											first_execution = false;
											
											update_array = true;
										} else {
											if (difference < closest_difference){
												closest_difference = difference;
												
												if (result_cursor > 0){
													for (int i = 0; i < result_cursor; i++){
														nje[result_cursor].empty_values();
													}
													result_cursor = 0;
												}
												
												update_array = true;
											} else if (difference == closest_difference){
												update_array = true;
											}
										}
										
										if (update_array){
											int [] y = {aa, bb, cc};
											nje[result_cursor] = new Result(y);
											result_cursor++;
											result_number = result_cursor;
										}
									}
								}
							}
						}
					}
				}
			}
			
			return (nje);
		}
		
	
		static void Main (string [] args){
			int [] nums = {-1,2,1,-4};
			int len_nums = nums.Length;
			int target = 1;
			
			int sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
			
			Result [] h = fun_sum_of_three_closest(nums, target, sample_space);
			
			for (int i = 0; i < result_number; i++){
				h[i].print_values();
			}
		}
	
	}
		
}
