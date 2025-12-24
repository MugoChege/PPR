using System;

namespace remove_element_ns
{
	class remove_element_c
	{
		public static int remove_by_shifting (int element, int [] list){
			int count = 0;
			int len_list = list.Length;
			
			for (int i = (len_list - 1); i >= 0; i--){
				if (list[i] == element){
					count ++;
					int holder = list[i];
					
					for (int j = i; j < (len_list - 1); j++){
						list[j] = list[j + 1];
					}
					
					list[len_list - 1] = holder;
				}
			}
			
			return (count);
		}
		
		public static void Main (String [] args){
			int [] nums = {0,1,2,2,3,0,4,2};
			int len_nums = nums.Length;
			int vals = 2;
			
			int rem = remove_by_shifting(vals, nums);
			
			Console.WriteLine("This is the handy work of C#\n\n");
			Console.WriteLine(rem);
			Console.WriteLine("\n\n\n");
			
			Console.Write("[");
			for (int i = 0; i < len_nums; i++){
				Console.Write(nums[i]);
				
				if (i == (len_nums - 1)){
					Console.WriteLine("]");
				} else {
					Console.Write(", ");
				}
			}
			
			Console.Write("\n\n\n[");
			for (int i = 0; i < (len_nums - rem); i++){
				Console.Write(nums[i]);
				
				if (i == ((len_nums - rem) - 1)){
					Console.WriteLine("]");
				} else {
					Console.Write(", ");
				}
			}
		}
	}
}
