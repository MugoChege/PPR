using System;
using System.Collections.Generic;

namespace sum_of_three_ns
{
	class sum_of_three_class
	{
		public static int number_of_elements = 3;
		
		public class Result {
			int [] values = new int [number_of_elements];
			public bool isNull = false;
			
			public Result (){
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
		
		static List<Result> sum_of_three (int [] list, int target = 0)
		{
			int len_list = list.Length;
			List<Result> nje = new List<Result> ();
			
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
											Result z = new Result();
											z.set_result(y);
											nje.Add(z);
											
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
			
			List<Result> res = sum_of_three(nums);
			
			Console.WriteLine("This is the handy work of C#");
			
			for (int i = 0; i < res.Count; i++){
				//Console.WriteLine(h[i]);
				res[i].print();
			}
		}
		
	}
}
