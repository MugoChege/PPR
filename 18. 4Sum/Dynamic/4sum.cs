using System;
using System.Collections.Generic;

namespace sum_of_4_ns
{
	class sum_of_4_c
	{
		public static int number_of_elements = 4;
		
		public class Result{
			int [] values = new int [number_of_elements];
			int number_of_values;
			bool not_null;
			
			public void print_result(){
				for (int i = 0; i < number_of_elements; i++){
					Console.Write(values[i]);
					
					if (i < (number_of_values - 1)){
						Console.Write("\t");
					}
				}
				
				Console.WriteLine();
			}
			
			public Result(){
				number_of_values = 0;
				not_null = false;
			
			}
			
			public Result(int [] list){
				number_of_values = list.Length;
				not_null = false;
				
				for (int i = 0; i < list.Length; i++){
					values[i] = list[i];
				}
			}
		}
		
		static bool not_equal_list (int [] list){
			int len_list = list.Length;
			bool nje = true;
			for (int i = 0; i < len_list; i++){
				for (int j = i; j < len_list; j++){
					if (i != j){
						if (list[i] == list[j]){
							nje = false;
						}
					}
				}
			}
			
			return (nje);
		}
		
		static List<Result> sum_of_four (int [] list, int target){
			int len_list = list.Length;
			
			List<Result> nje = new List<Result> ();
			
			for (int a = 0; a < len_list; a++){
				for (int b = 0; b < len_list; b++){
					if (b > a){
						for (int c = 0; c < len_list; c++){
							if (c > b){
								for (int d = 0; d < len_list; d++){
									if (d > c){
										int [] u = {a, b, c, d};
										if (not_equal_list(u)){
											int aa = list[a];
											int bb = list[b];
											int cc = list[c];
											int dd = list[d];
											
											//if (not_equal_list([aa, bb, cc, dd])){
											if (true){
												if ((aa + bb + cc + dd) == target){
													int [] z = {aa, bb, cc, dd};
													//Result y = Result(z);
													
													nje.Add(new Result(z));
												}
											}
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
			int [] nums = {1,0,-1,0,-2,2};
			int len_nums = nums.Length;
			int target = 0;
			
			List<Result> res = sum_of_four(nums, target);
			
			Console.WriteLine("The handy work of C#\n\n");
			
			for (int i = 0; i < res.Count; i++){
				res[i].print_result();
			}
			
			Console.WriteLine("\n\n");
		}
	}
}
